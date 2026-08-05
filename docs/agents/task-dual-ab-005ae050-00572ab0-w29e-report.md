# Dual A/B report — W29-E OWN-ONLY (`0x005ae050`, `0x00572ab0`)

**Date:** 2026-07-29  
**Agent:** W29-E OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005ae050`, `0x00572ab0`. Dual A/B + artifacts.  
**Partition:** wave29 (OWN-ONLY dual W29-E).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005ae050` StdTree_Dec_Val12 | **accept** — Val12 iterator-- / `_Tree::_Dec`; leaf; 7 insert consumers |
| `aa_00572ab0` InventoryGrid_AutoMergePartialStacks_Inferred | **accept-with-gaps** — full-grid underfilled stack merge; true epilogue past false noreturn; AL dirty |

---

## `aa_005ae050` — StdTree_Dec_Val12

### Sealed facts

1. **Body:** `0x005ae050`–`0x005ae0a0` exclusive (**80** B / `0x50`). Final **`C3`**; pad `CC`.

2. **ABI:** ECX = `node**` (iterator); bare **`RET`**; void. Leaf (no callees).

3. **Algorithm:**
   ```
   if (*it)->isnil: *it = node.right; return   // end → rightmost
   if left not nil: *it = rightmost(left)
   else: walk parents while coming from left; if parent not nil: *it = parent
   ```

4. **Layout:** Val12 — left@0, parent@+4, right@+8, isnil@+0x19 (family with Inc/Buynode/Erase/Insert Val12).

5. **Callers (7):** `FUN_0053a8e0`, `Skill_CategoryCooldownMap_Insert` (`0x0051d2f0`), `FUN_00573810`, `FUN_0053a1a0`, `FUN_005e18d0`, `FUN_005aed20`, `FUN_005accf0`.

6. **Name:** structural `StdTree_Dec_Val12`. Prior residual mis-role as “tree insert” is **rejected**.

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005ae050_StdTree_Dec_Val12.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005ae050_StdTree_Dec_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ae050_StdTree_Dec_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ae050_StdTree_Dec_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005ae050_StdTree_Dec_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005ae050_FUN_005ae050.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Dec_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005ae050.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.annotated.md` |

---

## `aa_00572ab0` — InventoryGrid_AutoMergePartialStacks_Inferred

### Sealed facts

1. **Body (true):** `0x00572ab0`–`0x00572ec7` exclusive (**1047** B / `0x417`). Ghidra lists end `0x00572e7f` (**false** — `operator_delete` noreturn). Final **`C3`** after `mov al, dirty`.

2. **ABI:** `__thiscall` ECX = `InventoryGrid*`; bare **`RET`**; return **bool in AL** (any merge).

3. **Algorithm:**
   ```
   consumeList = empty; partialMap = empty Val12
   TraversalLock(this+0x2c); for each item via List_IterateNext:
     if !Item_IsStackEligible || qty >= max: continue
     max = type4 ? 0x423F : (def+0x4BA || 200)
     scan partialMap for peer with same clonebase+0x34:
       residual: transfer room; Erase peer; InsertOrFind current
       full absorb: peer.qty += item.qty; item.qty=0; enqueue consume
     else InsertOrFind current
     on change: dirty items/owner; this+0x21=1
   leave CS; RemoveItem(1e6,1)+QueueDelete consume; destroy map/list; return dirty
   ```

4. **Callees:** `0040fb90`, `005ae2b0`, `004294f0`, `004022a0`, `00513e70`, vtbl `+0x250/+0x254/+0x25c/+0x260`, `005ae0b0`, `00573250`, `00573810`, `00418700`, `00404840`, `00512670`, `00571b80`, `004d4790`, `00573700`, `LeaveCriticalSection`, `operator_delete`.

5. **Callers (1):** `FUN_008c2f50` only (xref `008c2f72`) — may send sector packet **`0x204a`** if AL≠0.

6. **Name:** `InventoryGrid_AutoMergePartialStacks_Inferred`. Distinct from COID merge `00571830` and capacity predicate `0040abf0`.

### Gaps

1. Product English / demangle.  
2. Sector `0x204a` product meaning (caller-owned).  
3. Clean plate short-circuits full residual branch detail (raw authority).  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00572ab0_InventoryGrid_AutoMergePartialStacks_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00572ab0_FUN_00572ab0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_AutoMergePartialStacks_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00572ab0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00572ab0_FUN_00572ab0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_Dec_Val12 (`0x005ae050`)

- Port as **generic Val12 tree iterator--**, not product-map-specific and **not** an insert helper.
- Preserve isnil@+0x19; end-nil path sets `*it = header.right` (rightmost).
- Pair with `StdTree_Inc_Val12` (`0x005ae0b0`); insert-or-find must call Dec (or equivalent) for predecessor.
- Do not substitute isnil@+0x15 / +0x29 peer families.

### InventoryGrid_AutoMergePartialStacks_Inferred (`0x00572ab0`)

- Port as **full-grid underfilled stack consolidate**, not COID delta merge and not capacity-only check.
- Max stack: type-4 effective **16959** (`0x423F`); else def `+0x4BA` or **200** — same as `Item_CanAcceptStackQty`.
- Peer key: **clonebase+0x34** (not instance COID).
- Fully absorbed stacks: `RemoveItem(qty=1000000, flag=1)` then `Object_QueueDelete`.
- Return dirty bool; grid flag **`+0x21`** on change.
- Ghidra plate end is **not** authority — continue past `operator_delete` to AL return.

---

## Notes

- Tools used: `decompile_function`, `batch_decompile`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_bulk_xrefs`, `get_function_callees`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W29-E only for these two VAs.
- Did not write artifacts for non-owned helpers (`00573810` dualed W28-T; `005ae0b0` W28-N; `00573250` W27-S; `0040abf0` stack capacity; caller `008c2f50` out of ownership).
