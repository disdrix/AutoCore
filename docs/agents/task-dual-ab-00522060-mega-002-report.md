# Dual A/B report — MEGA-002 OWN-ONLY (`0x00522060`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-002**  
**Scope:** VA `0x00522060` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `analyze_control_flow` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — type-0x1a craftable batch counter (callee of dualed **CVOGCharacter_TryType1aCraft_Inferred** `0x005316c0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522060` Character_CountType1aCraftableBatches | **accept-with-gaps** — CF/ABI/RET10/type-1a/mode matrix/dual-grid sealed; product field English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ValidateCraftAffordability-misname / single-grid / min-not-add / mode polarity invert / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00522060` — sealed facts

1. **Body:** `0x00522060`–`0x00522203` inclusive (**420 B** / `0x1A4`); pad `CC` after.
2. **ABI:** **ECX** = character; stack `item*`, `int* outBatches`, `char mode`, `char simpleFlag`; **AL** bool; **`RET 0x10`**.
3. **Semantics:** count affordable **type-0x1a** craft batches from **cargo + locker**:
   - Guards: `this+0x250`, `*(+0x250)+0x2b0`, `this+0xcbc`, `item+0x38==0x1a`, blob `item+0x3c`.
   - `simpleFlag≠0`: sum counts of `blob+0x4c0` only; return `*out!=0`.
   - `mode≠1` and cost `@+0x4d4>0`: `*out += floor(have(+0x4d0)/cost)` across both grids.
   - `mode≠2`: `*out +=` min secondary slot counts (`+0x498…`, via `FUN_00599dd0`).
   - Return `*out > 0`.
4. **Odd sealed:** primary batches and secondary min are **ADDed** (not `min`'d together).
5. **Callees:** `InventoryGrid_CountItemsByCbid` `0x005711c0`; `ItemDef_CountConfiguredModSlots_Inferred` `0x00599dd0`.
6. **Callers / xrefs:** 5 UNCONDITIONAL_CALL — craft `0x005316c0` @ `0x00531750`; UI `0089bc30` / `0089bf50` / `0089c330`; site `0089cc96`.
7. **Name:** `Character_CountType1aCraftableBatches` (Ghidra `FUN_00522060`). Scaffold Named_CalleeOf ValidateCraftAffordability **retired**.
8. **Decompile ≡ raw CF**; dual-grid this restored via assembly (decompiler collapses `FUN_005711c0` this).

### Gaps

- Product English for blob fields (`+0x4c0` / `+0x4d0` / secondary list).  
- Whether retail UI always uses exclusive mode 1 or 2.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522060_Character_CountType1aCraftableBatches.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00522060_Character_CountType1aCraftableBatches.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00522060_FUN_00522060.md` |
| Annotated | `docs/reconstruction/raw/aa_00522060_FUN_00522060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_CountType1aCraftableBatches.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522060.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060.cpp` |
| Function | `docs/reconstruction/functions/aa_00522060_FUN_00522060.md` |
| Function named | `docs/reconstruction/functions/aa_00522060_Character_CountType1aCraftableBatches.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGCharacter_TryType1aCraft_Inferred  0x005316c0  [dualed WQ8R-B]
  ├─ FUN_004f1e20                 ensure blob
  ├─ FUN_00522060  Character_CountType1aCraftableBatches  [OWN MEGA-002]
  │     ├─ InventoryGrid_CountItemsByCbid  0x005711c0  [dualed]
  │     └─ ItemDef_CountConfiguredModSlots_Inferred  0x00599dd0  [dualed partial]
  ├─ InventoryGrid_FindFreeSlot   0x005713a0
  ├─ CVOGReaction_RemoveInventoryItem  0x005721c0
  └─ FUN_005310a0                 grant product

UI type-1a list / affordability:
  FUN_0089bc30 / FUN_0089bf50 / FUN_0089c330
    └─ FUN_00522060  (mode from +0x528, flag from +0x538)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00522060-mega-002-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522060` | Port as **character type-0x1a craft batch counter**. **thiscall RET 0x10**. Always sum **cargo + locker**. Mode: **1 skips primary**, **2 skips secondary**. Primary and secondary contributions **ADD**. Simple flag uses **`+0x4c0`**, not primary `+0x4d0`. |
| Pair with | dualed craft `005316c0`; dualed `InventoryGrid_CountItemsByCbid` `005711c0`; dualed slot-count `00599dd0`. |
| Do not | Merge with ValidateCraftAffordability client helper; count a single grid; invert mode polarity; replace ADD with min(primary, secondary). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00522060`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + control flow. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin `FUN_00522060.cpp`; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: primary+secondary **ADD**; secondary loop bound = count-of-non-(-1); simple path CBID `+0x4c0`.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
