# Dual A/B report — W31-S OWN `aa_0051bc90` + `aa_00530670`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-S  
**Scope:** VAs `0x0051bc90`, `0x00530670` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` / `get_function_by_address` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` → **W31-S**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051bc90` ObjectCsList_ClearDestroyNoNode4_Inferred | **accept-with-gaps** — CS drain CF/ABI/flag/throw/next/no-node+4/dtor callers sealed; product English open |
| `aa_00530670` CVOGCharacter_TryClearMissionCounterIfPositive | **accept-with-gaps** — map try-clear CF/ABI/`ret 4`/dual-field/+0x40 dirty/sole caller sealed; key English open |

---

## VA `0x0051bc90` — sealed facts

1. **Body:** `0x0051bc90`–`0x0051bd8b` exclusive (**251 B** / `0xFB`); final **`C3`**; pad `CC`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX = **list\***; no stack formals; void; bare RET.
3. **Semantics:** CS-protected list clear/destroy (Object CS-list family, `sizeof` 0x2C-class helpers):
   - `EnterCriticalSection(list+4)`.
   - If flag `list+0x28 ≠ 0`: Leave + throw **`0x80070005`** (`E_ACCESSDENIED`).
   - Drain head `list+0x1C`: next @ `node+8`, scalar-delete `vtbl[0](1)` — **no** `node+4=0`.
   - Zero `+0x24/+0x20/+0x1C`; LeaveCS.
   - Does **not** free list / DeleteCS (callers do).
4. **Classification:** worker (list clear-destroy).
5. **Callers (2 / 3 xrefs):** `FUN_0051bf10` @ `0051bf19` (scalar dtor, vtbl `009ce07c`); `FUN_0051d0e0` @ `0051d0e9` + `0051d0f6` (complete dtor, both vtbls then DeleteCS).
6. **Twin:** `ObjectCsList_ClearDestroy_Inferred` `0x0051b8a0` (W30-F) **clears `node+4`**; used from SharedBase dtor path — do not merge.
7. **Name:** `ObjectCsList_ClearDestroyNoNode4_Inferred` (Ghidra `FUN_0051bc90`).
8. **Decompile residual:** SEH/chkstk frame expanded in bytes — **machine sealed** in clean/annotated.
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); full body hex sealed.

### Gaps

- Product English / MSVC demangle for CS-list class (`009ce154` / `009ce07c`).  
- Field English for `+0x20/+0x24`.  
- Rationale for twin `node+4` difference.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051bc90_FUN_0051bc90.md` |
| Annotated | `docs/reconstruction/raw/aa_0051bc90_FUN_0051bc90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectCsList_ClearDestroyNoNode4_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051bc90.cpp` |
| Function | `docs/reconstruction/functions/aa_0051bc90_FUN_0051bc90.md` |
| Function named | `docs/reconstruction/functions/aa_0051bc90_ObjectCsList_ClearDestroyNoNode4_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0051bc90.md` |

---

## VA `0x00530670` — sealed facts

1. **Body:** `0x00530670`–`0x00530708` exclusive (**152 B** / `0x98`); dual **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = **character**; stack `(key)`; returns **bool** (AL 0/1); **`ret 4`**.
3. **Map:** object `char+0x584`; end/head `char+0x588` (Val12 family with `FUN_00418b80` find + Set/Add/Get siblings).
4. **CF fail:** miss **or** `*(node+0x14) <= 0` → return **0** (no Set).
5. **CF success:** re-find; if hit: `*(node+0x10)=0` (+ defensive negative copy); `char+0x634 |= 0x40`; then `CVOGCharacter_SetMissionCounter(key, 0)`; `|= 0x40` again; return **1**.
6. **Callees:** `FUN_00418b80` ×2; `FUN_005305b0` (W30-I sealed Set).
7. **Callers (1 / 1 xref):** `FUN_00809dd0` @ `00809e0a` (packet success vs `"FAILED: Server reports failure."`).
8. **Name:** `CVOGCharacter_TryClearMissionCounterIfPositive` (Ghidra `FUN_00530670`).
9. **Decompile residual:** map ECX omitted on nested finds — **machine sealed** (`LEA EDI,[ESI+0x584]`).
10. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); full body hex sealed.
11. Partially addresses W30-I dual-field gap for the **clear** path: this unit writes **+0x10** then zeros **+0x14** via Set.

### Gaps

- Product English for counter key domain.  
- Dirty bit `0x40` consumers vs `0x10` mission dirty family.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00530670_FUN_00530670.md` |
| Annotated | `docs/reconstruction/raw/aa_00530670_FUN_00530670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryClearMissionCounterIfPositive.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00530670.cpp` |
| Function | `docs/reconstruction/functions/aa_00530670_FUN_00530670.md` |
| Function named | `docs/reconstruction/functions/aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` |
| Scratch | `docs/reconstruction/tmp/a_00530670.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051bc90` | Port as **list dtor drain** twin of `ObjectCsList_ClearDestroy_Inferred`. Same CS/flag/head/next/zero; **omit** `node+4=0`. Call from list complete/scalar dtors before DeleteCS. Do not use for SharedBase pre-clear (that is `0051b8a0`). |
| `00530670` | Port as character map **try-clear**: only when `+0x14 > 0`; zero **+0x10**, then Set(key,0), dirty **`\|=0x40`**, return bool, **ret 4**. Do not Set on miss/non-positive. Preserve map this=`+0x584`, head=`+0x588`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0051b8a0` | `ObjectCsList_ClearDestroy_Inferred` (W30-F) — **with** `node+4=0` |
| `0x0051bf10` | CS-list scalar-deleting dtor (calls this clear) — W31-R partition |
| `0x0051d0e0` | CS-list complete dtor (calls this clear ×2) — W31-R partition |
| `0x005305b0` | `CVOGCharacter_SetMissionCounter` (W30-I) |
| `0x00530610` | `CVOGCharacter_AddMissionCounter` — hit `+=` at +0x14; ret 0xC |
| `0x0052ada0` | `CVOGCharacter_GetResourceBalanceByType` — read +0x10 |
| `0x00418b80` | ordered-map find |
| `0x00809dd0` | packet path sole caller of `00530670` |
| `0x0094e530` | other SetMissionCounter caller (W31-T partition) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names from sibling family / structural `_Inferred`.  
- Avoid bare `undefined4` in clean (`uint32_t` / `int32_t`).

---

## This report

`docs/agents/task-dual-ab-0051bc90-00530670-w31s-report.md`
