# Dual A/B report — R13-018 OWN-ONLY (`0x0040b440`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-018**  
**Scope:** VA `0x0040b440` (`aa_0040b440`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent MissionTracker `0092b2a0` re-dual, range parent `0040bc10`, sibling R13-017/019/020).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-018**.  
**System:** inventory-transfer (partition assignment; unit role is generic MSVC `_Tree` erase Val12 RetC).  
**Parent dual:** `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred.  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040b440` StdTree_EraseAndRebalance_Val12_RetC_Inferred | **accept-with-gaps** — erase CF/ABI/RET0xC/isnil19/epilogue sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): noreturn-as-full-body / thiscall-RET8-merge / isnil21-merge / isnil29-merge / range-erase / freelist / value-dtor / MissionTracker-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040b440` — sealed facts

1. **Body:** `0x0040b440`–`0x0040b6d0` exclusive (**656 B** / `0x290`); next fn `FUN_0040b6d0` abuts. Ghidra lists end `0x0040b6a0` (false noreturn on `operator_delete`).
2. **ABI:** **3 stack args** `map*`, `outIt**`, `node*`; **`ret 0xC`** (`C2 0C 00` @ `0x0040b6cd`). **Not** thiscall RET 8.
3. **Semantics:** MSVC-style **`_Tree` erase + RB rebalance** for **Val12 isnil@+0x19**:
   - SEH frame (`LAB_009bc919` / FS:[0]).
   - Nil iterator → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `FUN_00401bc0` → `_CxxThrowException` / `DAT_00acc34c`.
   - Successor via `FUN_00457cc0` (iterator++ isnil19 — dualed W38-B).
   - Unlink + head extremity fix (min `0043bf90` / max `0040b8f0`); two-child swap path @ `0x0040b539`.
   - If erased black → recolor + Lrotate `00446b10` / Rrotate `0040b910`.
   - `operator_delete(node)` (no value dtor); size--; `*outIt = succ`.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x18**, isnil@**+0x19**; node **0x1C** (Val12); shell head@+4, size@+8.
5. **Callees:** `FUN_00457cc0`, `FUN_0043bf90`, `FUN_0040b8f0`, `FUN_00446b10`, `FUN_0040b910`, `FUN_00401bc0`, basic_string ctor (IAT), `_CxxThrowException`, `operator_delete`.
6. **Callers (2):** `FUN_0040bc10` @ `0x0040bcae` (erase-range); `FUN_0092b2a0` @ `0x0092b741` (MissionTracker parent).
7. **Xrefs:** 2 UNCONDITIONAL_CALL (same); both 3× PUSH.
8. **Name:** `StdTree_EraseAndRebalance_Val12_RetC_Inferred` (Ghidra `FUN_0040b440`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** thiscall Val12 erase `004e4130`; Map_EraseNode_Val12 `005399f0`; StdTree_EraseNode_Val12 `005ae990`; Val12 twin `005e15a0`; isnil21 `00405650`; isnil29 RetC `00402850`; isnil31 `00408ed0`.
10. **Decompile ≡ raw CF** for throw/unlink/rebalance; epilogue sealed via `read_memory` + `disassemble_function` past false noreturn.

### Gaps

- Product / MSVC demangle for map value_type / host English (`FUN_0092b2a0` / range `FUN_0040bc10`).  
- Dual of range parent `FUN_0040bc10`, min `0043bf90`, max `0040b8f0`, L/R rotates.  
- Two-child splice plate bit-level fidelity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b440_FUN_0040b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_RetC_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b440.cpp` |
| Function | `docs/reconstruction/functions/aa_0040b440_FUN_0040b440.md` |
| Function named | `docs/reconstruction/functions/aa_0040b440_StdTree_EraseAndRebalance_Val12_RetC_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0092b2a0  MissionTracker_FillTrackedTargetSlots_Inferred  [parent dual — residual re-merge]
  └─ StdTree_EraseAndRebalance_Val12_RetC_Inferred (0x0040b440)  [OWN R13-018]
       ├─ FUN_00457cc0  StdTree_IteratorIncrement_Isnil19  [W38-B dualed]
       ├─ FUN_0043bf90  min  [residual]
       ├─ FUN_0040b8f0  max  [residual]
       ├─ FUN_00446b10  Lrotate Val12 family  [residual]
       └─ FUN_0040b910  Rrotate Val12 family  [residual]

FUN_0040bc10  erase-range parent (isnil19 / Val12)  [R13-020 residual]
  └─ StdTree_EraseAndRebalance_Val12_RetC_Inferred (0x0040b440)

// Do not merge with thiscall Val12 erase:
FUN_004e4130  StdTree_EraseAndRebalance_Val12  [W27-Q dualed — ret 8 thiscall]
  └─ different min/iter/rotate pair (005ae0b0 / 005adfa0 / 00418bf0 / 00573170 / 00418c10)
```

Partition system **inventory-transfer** explains why this VA was queued under that residual set (parent MissionTracker proximity + sibling R13-017..020 cluster), not an inventory-product English name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040b440-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040b440` | Port as **shared StdTree erase+rebalance** for **Val12 isnil@+0x19 / color@+0x18 / node 0x1C**. **3 stack args**; **ret 0xC**. No value dtor. Pair with Isnil19 ++ `00457cc0`, Lrotate `00446b10`, Rrotate `0040b910`. Do **not** merge with thiscall Val12 erase `004e4130` (ret 8) or isnil21/29/31 erase. |
| Pair with | dualed Isnil19 ++ `00457cc0`; residual range parent `0040bc10`; residual min/max/rotates; parent MissionTracker `0092b2a0`. |
| Naming caution | **Not** MissionTracker-product-specific. **Not** inventory grid English. **Not** thiscall Val12 erase. **Not** isnil21/29/31 erase despite shared MSVC plate shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (generic STL erase — not inventory UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0040b440`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (stack RET 0xC; epilogue past false noreturn).  
- Odd behavior preserved: decompiler unreachable mid-blocks for two-child path; assembly has them.  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
