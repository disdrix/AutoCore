# Review A (reconstruction fidelity): `aa_00407d70` Map_EraseRange_C

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407d70` |
| **VA** | `0x00407d70`–`0x00407e24` exclusive (**180 B** / `0xB4`) |
| **Canonical name** | `Map_EraseRange_C` |
| **Ghidra name** | `FUN_00407d70` |
| **Review date** | `2026-08-04` (WQ9H-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407d70_Map_EraseRange_C.md` |
| **System** | MSVC `std::_Tree` range erase (isnil@+0x29) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the large-node family (`isnil@+0x29`). Full-range fast path frees the tree via dualed `StdTree_FreeSubtree_Isnil29_Inferred` (`0x00406c00`); partial path walks successors and calls dualed `Map_EraseNode_B` (`0x00409220`). Used by map tidy/dtor full-clear paths (`FUN_00405350`, `FUN_00406010`, `FUN_004d98f0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-04) |
| Bytes | `read_memory` 180 B; tails `C2 0C 00`; isnil `+0x29` immediates |
| Free subtree | dualed `aa_00406c00` WQ9G |
| Single erase | dualed `Map_EraseNode_B` / `aa_00409220` WQ9E-G |
| Peer twins | `Map_EraseRange` `0x0051c7c0`; `Map_EraseRange_B` `0x0051d880` |
| Callers | `FUN_00405350`, `FUN_00406010`, `FUN_004d98f0` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 0x0c
Node** __thiscall Map_EraseRange_C(
    Map* map, Node** outIt, Node* first, Node* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`MOV EDI,ECX`) | **High** |
| outIt / first / last | stack (`[ESP+…]` after pushes) | **High** |
| cleanup | `POP EBX; RET 0x0c` both exits | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full clear: first==*head && last==head | decomp ≡ bytes | **High** |
| FreeSubtree(head->parent) then head reset + size 0 | rel call → `0x00406c00` | **High** |
| Partial: successor isnil@+0x29 | immediates `0x29` | **High** |
| Map_EraseNode_B(ECX=map, &first, node) | rel call → `0x00409220` | **High** |
| `*out = first` / ret 0x0c | bytes | **High** |
| Decompile ≡ raw CF | yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | 3 (tidy/dtor full-range erase) |
| Xrefs | 3 UNCONDITIONAL_CALL |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure | **Yes** |
| Shared free-subtree + erase-node duals | **Yes** |
| Twin of Map_EraseRange / Map_EraseRange_B | **Yes** (180 B class, same CF) |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseRange_C`** (structural third isnil29 instantiation).

---

## 7. Gaps

- Product map value_type / demangle.
- Per-caller payload English beyond tidy/dtor full clear.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/isnil29/full-clear free-subtree + partial erase sealed → **accept-with-gaps**.