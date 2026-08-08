# Dual A/B report — R12-035 OWN-ONLY (`0x005ae6d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-035**  
**Scope:** VA `0x005ae6d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent Rrotate `005a27f0` re-dual, sibling insert `005ae2f0`, range parent `005af2e0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-035**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ae6d0` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/isnil21/size--/throw plate sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): insert-as-role / isnil29-merge / Val12-merge / RetC-merge / noreturn-on-delete / skill-only / range-as-body / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005ae6d0` — sealed facts

1. **Body:** `0x005ae6d0`–`0x005ae986` exclusive (**694 B** / `0x2B6`); `CC` pad to `0x005ae98f`; next `FUN_005ae990` @ `0x005ae990`. Ghidra truncates on false noreturn from `operator_delete`.
2. **ABI:** **`__thiscall`** ECX=map; stack `Node** outIt`, `Node* node`; **`ret 8`** (`C2 08 00` @ `0x005ae983`).
3. **Semantics:** MSVC-style **`_Tree` erase + RB rebalance** for **isnil@+0x21**:
   - SEH frame (`LAB_009a65a2` / FS:[0]).
   - Nil → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `_CxxThrowException(..., DAT_00acc34c)`.
   - Successor via `FUN_004e12c0` (isnil21 iterator++).
   - Unlink + head extremity fix (min `FUN_004cb2c0`, max `FUN_00421a60`); two-child path bytes @ `0x005ae7f0+` (decomp may mark unreachable).
   - If erased black → recolor + Lrot `FUN_0050e9f0` / Rrot `FUN_005a27f0` (parent dual).
   - Bare `operator_delete`; if size>0 then size--; `*outIt = succ`.
4. **Layout:** left@+0, parent@+4, right@+8, value@+0xC (**Val16**), color@**+0x20**, isnil@**+0x21**; node **0x28**; map+4=head, map+8=size.
5. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `basic_string`/`exception`/`_CxxThrowException`, `operator_delete`.
6. **Callers (1):** `FUN_005af2e0` @ `0x005af37f` (`MOV ECX,EDI` seals thiscall). **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_005ae6d0`). Product demangle open → `_Inferred`.
8. **Twins (CF):** peer erase isnil29 thiscall `004cb740` / RetC `00402850` / isnil31 `00408ed0`; insert twin isnil21 `00407200`; rotates isnil21 `0050e9f0`/`005a27f0`.
9. **Decompile ≡ raw CF** for throw/unlink/rebalance; ABI/epilogue sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value_type / host shell English.  
- Residual duals of successor/min/max helpers + range parent `005af2e0`.  
- Two-child splice plate full fidelity (decomp unreachable).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ae6d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005ae6d0_FUN_005ae6d0.md` |
| Function named | `docs/reconstruction/functions/aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005af2e0  StdTree range erase isnil21  [residual]
  └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x005ae6d0)  [OWN R12-035]
        ├─ FUN_004e12c0  successor / ++ isnil21  [residual]
        ├─ FUN_004cb2c0  min isnil21  [residual]
        ├─ FUN_00421a60  max isnil21  [residual]
        ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)  [R10-030 dualed]
        └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)  [R11-007 parent dualed]

Family peers (dualed elsewhere):
  00407200  StdTree_InsertAndRebalance_Isnil21_Inferred
  00408990  StdTree_Buynode_Val16_Isnil21_Inferred
  004088f0  StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred

Do not merge:
  004cb740  StdTree_EraseAndRebalance_Isnil29_Inferred  (thiscall RET8, isnil29)
  00402850  StdTree_EraseAndRebalance_Isnil29_RetC_Inferred  (stack RET0xC)
  00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred
  005ae990  StdTree_EraseNode_Val12  (adjacent; isnil@+0x19)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005ae6d0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ae6d0` | Port as **shared StdTree single-node erase + RB rebalance** for **isnil@+0x21 / color@+0x20 / node 0x28 / Val16**. **thiscall** ECX=map; stack `outIt**`, `node*`; **ret 8**. Pair with Lrotate `0050e9f0`, Rrotate `005a27f0`, InsertAndRebalance `00407200`, buynode `00408990`. Throw plate shared `"invalid map/set<T> iterator"`. Do **not** merge with isnil29/31/Val12 erases. No value dtor in body. |
| Pair with | dualed rotates isnil21; dualed insert/buynode isnil21; residual range parent `005af2e0` + succ/min/max helpers. |
| Naming caution | **Not** skill/mission-specific. **Not** range erase (`005af2e0`). **Not** adjacent Val12 erase (`005ae990`). **Not** Runtime Confirmed. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 and R12 partition listed this erase as residual gap — now dualed R12-035. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
