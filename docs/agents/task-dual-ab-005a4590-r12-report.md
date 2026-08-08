# Dual A/B report — R12-032 OWN-ONLY (`0x005a4590`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-032**  
**Scope:** VA `0x005a4590` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including sibling insert `005a4950`, range shell `005a4c30`, buynode `005a4870`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_function_callees` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-032**.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005a4590` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/isnil21/value-free/size-- sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): insert-merge / isnil29-merge / range-clear / skill-only / wrong RET / missing size-- all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a4590` — sealed facts

1. **Body:** `0x005a4590`–`0x005a4862` inclusive (**723 B** / `0x2D3`); pad `CC`; next `0x005a4870`. Ghidra truncated body end `0x005a482f` (false noreturn on delete).
2. **ABI:** **`__thiscall`** ECX=map shell; stack `Node** outIt`, `Node* node`; **`ret 8`** (`C2 08 00`).
3. **Semantics:** MSVC-style **`_Tree` erase(const_iterator)** for **isnil@+0x21**:
   - Throw `"invalid map/set<T> iterator"` if `node->isnil`.
   - Successor prep `FUN_004e12c0`; splice replacement child; fix root + head leftmost/rightmost (min `004cb2c0` / max `00421a60`).
   - If erased black: RB recolor + Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - Free value heap @+0x14; zero +0x14/+0x18/+0x1c; `operator_delete(node)`; size-- if size>0; `*outIt = succ`.
4. **Layout:** left@+0, parent@+4, right@+8, key@+0x0C, heap begin/end/cap@+0x14/+0x18/+0x1c, color@**+0x20**, isnil@**+0x21**; node **0x24**; tree+4=head, head+4=root, size@tree+8.
5. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, throw path.
6. **Callers (1):** `FUN_005a4c30` (erase-range shell) @ `0x005a4ccf`.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_005a4590`). Product demangle open → `_Inferred`.
9. **Twins / peers:** L/R rotates isnil21 dualed; peer erases isnil29 `004cb740` / isnil31 `00408ed0` (do not merge). Parent dual supplies Rrotate used in black fixup.
10. **Decompile ≡ raw CF** for throw/unlink/rebalance/value free; RET + size-- sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value_type (key + vector-like).  
- Unreachable-block region may hide fuller both-children successor path.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a4590.cpp` |
| Function | `docs/reconstruction/functions/aa_005a4590_FUN_005a4590.md` |
| Function named | `docs/reconstruction/functions/aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005a4c30  erase-range shell (caller)                    [residual]
  └─ StdTree_EraseAndRebalance_Isnil21_Inferred (0x005a4590) [OWN R12-032]
       ├─ FUN_004e12c0  iterator++ / succ isnil21           [residual]
       ├─ FUN_004cb2c0  min isnil21                         [residual]
       ├─ FUN_00421a60  max isnil21                         [residual]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)     [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)     [R11-007 parent dualed]

Sibling near unit (not dualled):
  005a4870  buynode 0x24 isnil21
  005a4950  InsertAndRebalance-like isnil21 (R12-033)

Peer erases other families (dualed elsewhere):
  004cb740 StdTree_EraseAndRebalance_Isnil29_Inferred
  00408ed0 StdTree_EraseAndRebalance_Isnil31_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005a4590-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a4590` | Port as **shared StdTree erase + rebalance** for **isnil@+0x21 / color@+0x20 / node 0x24**. **thiscall** ECX=map; stack `outIt` + `node`; **ret 8**. Free heap @+0x14 before node; size--. Pair with L/R rotates `0050e9f0` / `005a27f0`. Do not merge with isnil29/31 erases. |
| Pair with | Rrotate isnil21 parent; Lrotate isnil21; range shell `005a4c30`; sibling buynode `005a4870`. |
| Naming caution | **Not** insert (`005a4950` / `00407200`). **Not** isnil29 erase (`004cb740`). **Not** skill-product exclusive — structural STL helper. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed this erase among Rrotate callers — now dualed R12-032. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
