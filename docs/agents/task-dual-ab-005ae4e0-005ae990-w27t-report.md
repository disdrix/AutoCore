# Dual A/B report — W27-T OWN-ONLY (`0x005ae4e0`, `0x005ae990`)

**Date:** 2026-07-29  
**Agent:** W27-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005ae4e0`, `0x005ae990`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005ae4e0` StdTree_InsertAndRebalance_Val12 | **accept-with-gaps** — Val12 always-insert + RB rebalance; `ret 0x10`; throw `"map/set<T> too long"` @ size>`0x15555553` |
| `aa_005ae990` StdTree_EraseNode_Val12 | **accept-with-gaps** — Val12 single erase + RB; `ret 8`; throw `"invalid map/set<T> iterator"`; size-- sealed past false noreturn |

---

## `aa_005ae4e0` — StdTree_InsertAndRebalance_Val12

### Sealed facts

1. **Body:** `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B / `0x1EA`). Final **`c2 10 00`** (`ret 0x10`); following `cc` pad.

2. **ABI:** `__thiscall` ECX=map; four stack args `(outIt*, addLeft, where, value*)`; clean **16** B.

3. **Algorithm:**
   ```
   if size > 0x15555553: throw "map/set<T> too long"
   n = StdTree_Buynode_Val12(head, where, head, value, color=0)
   size++
   link first | left | right (+ leftmost/rightmost)
   while parent red: recolor uncle OR rotate; root black; *outIt = n
   ```

4. **Callees:** `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170` (Lrotate), `FUN_00418c10` (Rrotate), string/exception, `_CxxThrowException`.

5. **Callers (1):** `FUN_005aed20` only (xrefs `005aed79`, `005aedb0`) — insert-or-find with int key @ value dword0.

6. **Peer clone:** `Map_TreeInsertAndRebalance_Val12` @ `0x0051c1c0` — same size/max/algorithm; **different** SEH (`LAB_009a65a2` vs `LAB_009a3502`) and sole caller. **Do not merge.**

7. **Name:** structural `StdTree_InsertAndRebalance_Val12`. Legacy MissionStopLimit chain alias is **narrow**.

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Buynode null OOM path (no check in decomp).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005ae4e0_FUN_005ae4e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005ae4e0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.annotated.md` |

---

## `aa_005ae990` — StdTree_EraseNode_Val12

### Sealed facts

1. **Body:** true exclusive end **`0x005aec44`** (**692** B / `0x2B4`). Ghidra lists end `0x005aec16` (false noreturn on `operator_delete`). Final **`c2 08 00`** (`ret 8`).

2. **ABI:** `__thiscall` ECX=map; stack `(outIt*, node*)`; clean **8** B.

3. **Algorithm:**
   ```
   if node.isnil@+0x19: throw "invalid map/set<T> iterator"
   succ = successor(node) via FUN_005ae0b0
   unlink + fix root/begin/end (FUN_005adfa0 / FUN_00418bf0)
   if erased black: RB fixup (FUN_00573170 / FUN_00418c10)
   operator_delete(node)  // falls through
   if size > 0: size--
   *outIt = succ
   ```

4. **Callees:** `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, L/R rotate Val12, `operator_delete`, exception path.

5. **Callers (1):** `FUN_005af3a0` only (xref `005af43f`) — range erase loop.

6. **Family:** Val12 isnil@+0x19 / color@+0x18 / node 0x1c. **Distinct** from `Map_EraseNode` (isnil@+0x29) and `StdMap_EraseIterator` (isnil@+0x15).

7. **Name:** structural `StdTree_EraseNode_Val12`.

### Gaps

1. Product/MSVC demangle.  
2. Full two-child splice expansion in clean (raw remains authority).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005ae990_StdTree_EraseNode_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005ae990_StdTree_EraseNode_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ae990_StdTree_EraseNode_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ae990_StdTree_EraseNode_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005ae990_StdTree_EraseNode_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005ae990_FUN_005ae990.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseNode_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005ae990.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae990_FUN_005ae990.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_InsertAndRebalance_Val12 (`0x005ae4e0`)

- Port as **generic Val12 always-insert + rebalance**, not MissionStopLimit-specific logic.
- Node size **0x1c**; color @ +0x18; isnil @ +0x19; max size **`0x15555553`**.
- Preserve **`ret 0x10`** ABI; parent owns uniqueness (`FUN_005aed20`).
- Do not substitute peer `0x0051c1c0` without matching caller/SEH expectations (both are valid clones).

### StdTree_EraseNode_Val12 (`0x005ae990`)

- Port as **generic Val12 single erase**; preserve successor return + **size--** after delete.
- Decompiler **omits** size-- / *outIt — bytes are authority for epilogue.
- Range erase is **parent** `FUN_005af3a0`, not this unit.
- Do not use larger-node `Map_EraseNode` offsets (isnil@+0x29) on this family.

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.
- Did not write artifacts for non-owned helpers (`005ae220` dualed W24-I; `00573170`/`00418c10` dualed W26-Q; `005aed20`/`005af3a0` callers out of ownership).
