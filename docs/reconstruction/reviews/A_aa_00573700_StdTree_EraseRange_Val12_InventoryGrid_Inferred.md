# Review A (reconstruction fidelity): `aa_00573700` StdTree_EraseRange_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573700` |
| **VA** | `0x00573700`–`0x005737b3` inclusive (**180 B** / `0xB4`) |
| **Canonical name** | `StdTree_EraseRange_Val12_InventoryGrid_Inferred` |
| **Ghidra name** | `FUN_00573700` |
| **Prior scaffold** | `FUN_00573700` |
| **Rejected misname** | sole product plate `InventoryGrid_DestroyItemList` (full-clear only; misses partial + temp maps) |
| **Review date** | `2026-08-05` (MEGA-120 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00573700_StdTree_EraseRange_Val12_InventoryGrid_Inferred.md` |
| **System** | inventory-transfer / MSVC `_Tree` range erase Val12 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_function_signature`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **range erase** `[first, last)` on Val12 nodes (isnil@`+0x19`). Full-range path free-subtrees the root and resets the sentinel; partial path walks successors and calls dualed single-node erase `StdTree_Erase_Val12` (`0x00573250`).

```text
StdTree_EraseRange_Val12_InventoryGrid_Inferred(map, out, first, last)
  if first==begin && last==end:
    FreeSubtree(root); reset head; size=0; *out=begin; RET 0xC
  while first != last:
    next = successor_Val12(first)
    Erase_Val12(map, first)
    first = next
  *out = first; RET 0xC
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (full free + successor erase loop) |
| Full body | `disassemble_function` + `read_memory` **180 B** |
| Peer | dualed `StdTree_EraseRange_Val12` @ `0x0040d700` (W32-C) — hex clone except CALL sites |
| Single erase | dualed `StdTree_Erase_Val12` @ `0x00573250` (W27-S) |
| Free | residual `FUN_005731c0` (bytes: right-recurse + left-advance free, RET 4) |
| Callers | `005725a0` complete dtor; `00572ab0` AutoMerge; `005738d0` map-shell dtor |
| Layout | InventoryGrid shell @ `+0x5c` / head `+0x60` / size `+0x64` (ctor dual) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Signature (sealed)

```c
// ECX=map; stack outIt*, first*, last*; RET 0x0C
void __thiscall StdTree_EraseRange_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX → EDI (`MOV EDI,ECX`) | **Confirmed** |
| last | EBX from `[ESP+0x10]` after entry | **Confirmed** |
| first | ESI from stack | **Confirmed** |
| outIt | stack after 3 pushes; both exits store `*outIt` | **Confirmed** |
| cleanup | `RET 0x0C` (`C2 0C 00`) @ `0x00573747` and `0x005737b1` | **Confirmed** |
| isnil | `CMP byte ptr [ESI+0x19],0` | **Confirmed** (Val12) |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full-range gate `first==*head && last==head` | bytes + decomp | **Confirmed** |
| Free root `FUN_005731c0(head->parent)` | CALL site | **Confirmed** |
| Head self-link reset + `size=0` | dword stores | **Confirmed** |
| Successor isnil@+0x19 | disasm loop | **Confirmed** |
| Single erase `FUN_00573250` thiscall | `MOV ECX,EDI; CALL` | **Confirmed** |
| `*outIt` both exits | MOV [EAX],… | **Confirmed** |
| Body 180 B / peer clone | hex compare | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers (3) | `FUN_005725a0` @ `0x005725fe` (`LEA ESI,[EDI+0x5c]`); `FUN_00572ab0` @ `0x00572e71`; `FUN_005738d0` @ `0x005738e2` |
| Callees | `FUN_005731c0`, `FUN_00573250` |
| Xrefs | 3 UNCONDITIONAL_CALL |

---

## 6. Gaps (non-blocking)

1. Product/MSVC demangle for map `T` / key English.  
2. Nested free-subtree `005731c0` residual dual.  
3. Runtime / bit-exact / differential open.

---

## 7. Verdict rationale

**accept-with-gaps** — ABI (`RET 0x0C` / thiscall ECX=map), Val12 layout, full vs partial CF, dualed single-erase callee, and InventoryGrid shell ownership are sealed from live decompile + bytes + callers. Gaps are product naming and free-subtree residual ownership, not ABI risk. Terminal **false** (no runtime Confirmed).
