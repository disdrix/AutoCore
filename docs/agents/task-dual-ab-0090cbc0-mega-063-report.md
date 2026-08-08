# Dual A/B report — MEGA-063 OWN-ONLY (`0x0090cbc0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-063**  
**Scope:** VA `0x0090cbc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-063 residual dual seal — **Post-force-complete medal UI refresh** (`aa_0090cbc0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090cbc0` MedalUI_RefreshPagedAchievementSlots_Inferred | **accept-with-gaps** — CF/ABI/EAX-host/RET/paging/fill sealed; product class English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / RET4 / grant-medals / VOG_DEBUG_STOP-misname / stride-24 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090cbc0` — sealed facts

1. **Body:** `0x0090cbc0`–`0x0090cdfe` inclusive (**575 B** / `0x23F`); pad `CC` then next @ `0x0090ce00`.
2. **ABI:** **EAX** = MedalUI host; no stack formals; void; bare **`RET`** (`C3`) ×2 exits.
3. **Semantics:** paged medal/achievement grid refresh:
   - Gate: `DAT_00d1b6d8 != 0` and host `vtbl[+0x3d8]()`.
   - Prep clear 24 slots via dualed `MedalUI_PrepClearButtonSlots_Inferred` (`FUN_0090c700`, EDI=host).
   - Count via `FUN_0090c810` (vector `[+0x574,+0x578)` + hash `+0x540`).
   - Page: `maxPage=(count-25)/3+1` when count>24 else 0; fields host `+0x5a4` / `+0x50c`; scrollbar `+0x5a0`.
   - Fill ≤**24** slots from index `pageIndex*3`: vector apply flag=**1**, hash apply flag=**0** via `FUN_0090c9a0` (XML `i_d_a_2d_btn_achievement.xml` in apply dual).
4. **Callers (6 xrefs):** `Client_RecvCompleteDynamicObjective` @ `0081015f` (S2C **0x2070**); `FUN_0080ce50` **JMP** @ `0080ce87`; `FUN_0090d0d0` @ `0090d364`; `FUN_00946c00` @ `009473a5`; `0090ce73`; `00952bb1`.
5. **Callees:** `FUN_0090c700`, `FUN_0090c810`, `FUN_0051a0e0`, `FUN_0090c9a0`, `FUN_007a4480`.
6. **Name:** `MedalUI_RefreshPagedAchievementSlots_Inferred` (Ghidra `FUN_0090cbc0`). Product class open → `_Inferred`.
7. **Retired scaffold:** `Named_VOG_DEBUG_STOP_0090cbc0` (string misname).
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for host / manager / scrollbar classes and vtbl slots.  
- Apply flag 0 vs 1 product meaning beyond source path.  
- Residual caller duals outside OWN.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090cbc0_FUN_0090cbc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_RefreshPagedAchievementSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090cbc0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0090cbc0.cpp` |
| Function | `docs/reconstruction/functions/aa_0090cbc0_FUN_0090cbc0.md` |
| Function named | `docs/reconstruction/functions/aa_0090cbc0_MedalUI_RefreshPagedAchievementSlots_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RecvCompleteDynamicObjective  (S2C 0x2070 force complete)  [named handler]
  └─ FUN_0090cbc0  MedalUI_RefreshPagedAchievementSlots_Inferred  [OWN MEGA-063]
        ├─ FUN_0090c700  MedalUI_PrepClearButtonSlots_Inferred     [dualed MEGA-102]
        ├─ FUN_0090c810  MedalUI_CountDisplayableEntries_Inferred  [sibling]
        ├─ FUN_0051a0e0  medal-def resolve                         [shared]
        ├─ FUN_0090c9a0  MedalUi_ApplyAchievementSlotButton_*      [sibling dual]
        └─ FUN_007a4480  debug log (HashError / VOG_DEBUG_STOP)

FUN_0090d0d0  achievements window init (i_d_a_2d_wnd_bg_achievements.xml)
  └─ FUN_0090cbc0  [OWN MEGA-063]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090cbc0-mega-063-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090cbc0` | Port as **MedalUI paged achievement slot refresh**. **EAX=host**, no stack args, **bare RET**. Gate on manager `DAT_00d1b6d8` + host visible vtbl`+0x3d8`. Sequence: prep-clear 24 → count → page/scrollbar → fill ≤24 from `pageIndex*3` (vector flag1 then hash flag0). |
| Do not | Treat as ECX-thiscall, RET 4, medal grant, objective complete, or VOG_DEBUG_STOP helper. |
| Pair with | dualed prep `0090c700`; count `0090c810`; apply `0090c9a0`; caller `Client_RecvCompleteDynamicObjective` (0x2070). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming registry entries when batching MEGA residuals
- inventory status if still `none` on page snapshots
