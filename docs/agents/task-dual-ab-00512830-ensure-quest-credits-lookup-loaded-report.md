# Dual A/B report — `aa_00512830` EnsureQuestCreditsLookupLoaded

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00512830`. Dual A/B + artifacts. Seal ensure-load wrapper for `tQuestCreditsLookup`.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees/xrefs/globals; no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00512830` EnsureQuestCreditsLookupLoaded | **accept-with-gaps** — wrapper control flow + globals sealed; plate early-out/flag-set **rejected** |

---

## Sealed facts

1. **Identity:** VA `0x00512830`, body through `ret` at `0x0051286d` (62 bytes). Canonical name `EnsureQuestCreditsLookupLoaded`. System: missions-progression.

2. **ABI:** No stack parameters; **void** return (`ret` only). Preserves `ESI` across body.

3. **Control flow (linear — no ready-flag test):**
   1. `ECX = *[0x00b0469c]` → `FUN_007e1d80` (DB/RM enter, refcount++)
   2. `ECX = *[0x00b0469c]`; push **`0x00b04258`** → `LoadQuestCreditsLookupFromWad` (`0x007cc470`)
   3. `ESI = EAX` (load status); `ECX = *[0x00b0469c]` → `FUN_007b7df0` (leave, refcount--)
   4. If `ESI < 0`: `FUN_007a4480(0, "VOG_DEBUG_STOP")` (`"VOG_DEBUG_STOP\0"` @ `0x00a15844`)

4. **Plate corrections:**
   - “if already loaded: return” — **false** for this body (gate is **caller-side**).
   - “sets `g_nQuestCreditsLookupLoaded_Inferred`” — **not in this body**.

5. **Global block (contiguous):**

   | VA | Symbol | Role |
   |----|--------|------|
   | `0x00b04258` | `g_pQuestCreditsLookupMap_Inferred` | map root (pushed to Load; used by `Map_LowerBoundFindByIntKey`) |
   | `0x00b0425c` | `g_pQuestCreditsLookupEndSentinel_Inferred` | end sentinel (consumer) |
   | `0x00b04260` | `g_nQuestCreditsLookupLoaded_Inferred` | loaded dword; **READ** only from `Mission_ComputeObjectiveCredits` (no static write xref) |

6. **DB context singleton:** `DAT_00b0469c` (`g_pDbReaderCtx*` inferred) — ECX source for enter/load/leave. Shared with sibling ensure-loaders (`0x005127f0`..`0x005128f0` family).

7. **Sibling:** `EnsureQuestBaseCreditsLoaded` `0x00512870` — identical skeleton; map imm `0x00b04264` (`g_pQuestBaseCreditsMap_Inferred`).

8. **Callers (exactly 2 functions / 3 call sites):**
   - `Mission_ComputeObjectiveCredits` `0x0059df20` — lazy path; checks `[0x00b04260]` before call (sites `0x0059df91`, `0x0059dfb5`)
   - `FUN_0094a6a0` — clonebase/table init (`0x0094afb8`); batches with XP/BaseCredits ensures when `param+0x31f5 == 0`

9. **Not** credit math / award — consumer formula remains in `Mission_ComputeObjectiveCredits` (CreditsIndex `obj+0x13e` → frac @ row `+0x10`). Loader xpath `//tQuestCreditsLookup/row` sealed on `aa_007cc470`, not re-proven here beyond callee identity.

10. **Decompiler gap sealed:** displayed `LoadQuestCreditsLookupFromWad(&map)` drops **ECX = ctx**; binary uses **ctx + map address**.

---

## Gaps

1. Write site for `g_nQuestCreditsLookupLoaded_Inferred` (`0x00b04260`) — likely inside Load via pointer; not sealed in this unit.  
2. Product names for `FUN_007e1d80` / `FUN_007b7df0` / `DAT_00b0469c` type.  
3. Load status code domain and whether re-entry is idempotent.  
4. Severity of `FUN_007a4480(0,"VOG_DEBUG_STOP")` (debug log vs hard stop).  
5. Runtime bring-up capture / bit-exact image diff.  
6. Full MSXML/COM path of `LoadQuestCreditsLookupFromWad` (owned by loader dual).

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00512830_EnsureQuestCreditsLookupLoaded.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00512830_EnsureQuestCreditsLookupLoaded.md` | accept-with-gaps |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Function record | `docs/reconstruction/functions/aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnsureQuestCreditsLookupLoaded.cpp` |
| Raw | `docs/reconstruction/raw/aa_00512830_EnsureQuestCreditsLookupLoaded.md` |
| Annotated | `docs/reconstruction/raw/aa_00512830_EnsureQuestCreditsLookupLoaded.annotated.md` |
| This report | `docs/agents/task-dual-ab-00512830-ensure-quest-credits-lookup-loaded-report.md` |
| Related loader dual | `docs/reconstruction/reviews/A_aa_007cc470_LoadQuestCreditsLookupFromWad.md` |
| Related consumer | `docs/reconstruction/functions/aa_0059df20_Mission_ComputeObjectiveCredits.md` |

---

## AutoCore impact

- Server mission credit grants need the **same lookup table semantics** (CreditsIndex → level-credit fraction) as client preview math in `Mission_ComputeObjectiveCredits`; this unit only forces **client** table materialization.  
- Do **not** port an in-body ready early-out that is absent from retail.  
- Port of ensure may no-op if tables are loaded at server boot; flag write location remains a residual on the loader.
