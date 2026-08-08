# Dual A/B report — MEGA-023 OWN-ONLY (`0x00930360`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-023**  
**Scope:** VA `0x00930360` (`aa_00930360`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` row MEGA-023.  
**Hint:** `Client_SortTargetListByViewAngle` → sealed as **`Client_SortTargetListByViewAngle_Inferred`**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00930360` Client_SortTargetListByViewAngle_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/score/sort-key/sole-caller sealed; product plate + nested leaf English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / distance-only / descending-best / multi-caller / selection-apply / gather / noreturn-delete / scaffold-as-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00930360` — sealed facts

1. **Body:** `0x00930360`–`0x00930691` inclusive (**0x332** B / 818 B); pad `CC` after.
2. **ABI:** stack `client*`, `TFID_16*`, `uint* count`; void; **stdcall `RET 0xC`** (`C2 0C 00`). **Not** ECX thiscall.
3. **Semantics:** view-angle reorder of TFID list:
   - Player origin via `*(client+0xe98)` interior vtbl **`+0x1a0`**; quat vtbl **`+0x1a4`**.
   - Forward `FUN_004e8a40`; right `FUN_004e8ad0` (`Quat_ExtractRight_Inferred`).
   - Per TFID: resolve `Object_ResolveFromTFID` (`0x004bb950`); virtual `+0x144`; delta from `obj+0x80/84/88`.
   - **Score:** dist≤0 → **2.0f**; else unitize; if `right·u ≤ 0` → `fDot+1`; else `−fDot−1` (`DAT_00aaa668=−1.0f`).
   - Build `vector` of **0x10**-byte elems (`InsertN` `00408640` / construct `00409e20`).
   - Sort `FUN_00409bd0` + comparator `LAB_0092cdd0` — **ascending** by **float@+4**.
   - Rewrite `*(TFID_16*)(obj+0x160)` into list; `*count = n`; `operator_delete` buffer (returns).
4. **Constants (`read_memory`):** `g_flOne=1.0f`, `g_flZero=0.0f`, `g_flLevelUpUiBase_Inferred=2.0f`, `DAT_00aaa668=−1.0f`.
5. **Callees:** vtbl+0x1a0/1a4, `004e8a40`, `004e8ad0`, `004bb950`, virt+0x144, `00408640`, `00409e20`, `00409bd0`, `LAB_0092cdd0`, `operator_delete`.
6. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — `Client_CycleHostileTarget_Inferred` (`FUN_00943340`) @ `0x00943440`.
7. **Name:** `Client_SortTargetListByViewAngle_Inferred` (Ghidra `FUN_00930360`). Scaffold `Named_CalleeOf_…` **retired**. Product plate open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/score/sort sealed via `disassemble_function` + `read_memory`. Decompiler noreturn-on-delete is **false**.

### Gaps

- Product C++ / PDB method English.  
- Virtual `+0x144` and `client+0xd34` ECX preload English.  
- UX intent of ascending order (right-forward first) vs product “best” language — bytes only.  
- Nested dual residual on sort/construct helpers as standalone units.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00930360_Client_SortTargetListByViewAngle_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00930360_Client_SortTargetListByViewAngle_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00930360_FUN_00930360.md` |
| Annotated | `docs/reconstruction/raw/aa_00930360_FUN_00930360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SortTargetListByViewAngle_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00930360.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00930360.cpp` |
| Function | `docs/reconstruction/functions/aa_00930360_FUN_00930360.md` |
| Function named | `docs/reconstruction/functions/aa_00930360_Client_SortTargetListByViewAngle_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_Input_PollBoundActions  [caller of cycle; not OWN]
  └─ Client_CycleHostileTarget_Inferred  FUN_00943340  [dualed WQ9R-C]
        ├─ Skill_GatherTargetsInArea  mode=2 hostile max=50
        ├─ FUN_00930360  Client_SortTargetListByViewAngle_Inferred  [OWN MEGA-023]
        │     ├─ FUN_004e8a40  forward extract
        │     ├─ FUN_004e8ad0  Quat_ExtractRight_Inferred  [dualed]
        │     ├─ Object_ResolveFromTFID  004bb950
        │     ├─ FUN_00408640  StdVector_InsertN_Elem0x10_Inferred  [dualed]
        │     ├─ FUN_00409e20 / FUN_00409bd0 / LAB_0092cdd0
        │     └─ operator_delete
        ├─ Object_ResolveFromTFID
        └─ FUN_0093e120  apply selection
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00930360-mega-023-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00930360` | Port as **view-angle TFID list reorder**. **stdcall RET 0xC**; three stack args (`client`, list, count*). Preserve score half-plane formula and **ascending** sort by score@+4. Do **not** fold gather or selection-apply into this unit. Pair with dualed cycle parent `00943340` and right extract `004e8ad0`. |
| Pair with | `Client_CycleHostileTarget_Inferred` `00943340`; `Skill_GatherTargetsInArea` `0058d330`; `Quat_ExtractRight_Inferred` `004e8ad0`; forward sibling `004e8a40`; `StdVector_InsertN_Elem0x10_Inferred` `00408640`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md` / coverage / naming registry entries for `aa_00930360`
- Progress / WORK_QUEUE residual clear for MEGA-023 row

This agent did **not** edit parent ledgers.
