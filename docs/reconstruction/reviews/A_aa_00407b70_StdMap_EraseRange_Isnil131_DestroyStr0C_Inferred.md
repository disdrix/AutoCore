# Review A (reconstruction fidelity): `aa_00407b70` StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407b70` |
| **VA** | `0x00407b70`–`0x00407bea` exclusive (**122 B** / `0x7A`) |
| **Canonical name** | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00407b70` |
| **Review date** | `2026-08-05` (WQ9K-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407b70_StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred.md` |
| **System** | MSVC `std::_Tree` range erase (isnil@+0x131 string family) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the large-node string family (`isnil@+0x131`). Full-range fast path frees the tree via dualed `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` (`0x00409920`); partial path walks successors (`FUN_00404000`) and erases via residual `FUN_00408ad0` (~string @+0x0c + rebalance). Used by map tidy/dtor full-clear paths (`FUN_00405110`, `FUN_00405df0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05); unaff_ESI = map |
| Bytes | `read_memory` 200 B; tails `C2 0C 00`; free call rel → `00409920` |
| Free subtree | dualed `aa_00409920` WQ9J-I |
| Successor / erase | residual `00404000` / `00408ad0` (isnil131 + string dtor) |
| Peer | OWN isnil2d erase-range `00407f90`; isnil29 `Map_EraseRange_C` `00407d70` |
| Callers | `FUN_00405110`, `FUN_00405df0` |

---

## 3. Signature (sealed)

```c
// Register-this ESI; RET 0x0c
Node** StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred(
    /*ESI*/ Map* map, Node** outIt, Node* first, Node* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | **ESI** (callers pre-load; entry uses `[ESI+4]`) | **High** |
| outIt / first / last | stack | **High** |
| cleanup | `POP EBP; POP EBX; RET 0x0c` both exits | **High** |
| return | EAX = outIt | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full clear: first==*head && last==head | decomp ≡ bytes | **High** |
| FreeSubtree(head->parent) ECX=map then head reset + size 0 | rel call → `0x00409920` | **High** |
| Partial: successor `00404000` then erase `00408ad0` | rel calls | **High** |
| `*out = first` / ret 0x0c | bytes | **High** |
| Decompile ≡ raw CF | yes (ABI register-this via bytes) | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | 2 (tidy/dtor full-range erase → delete head) |
| Xrefs | 2 UNCONDITIONAL_CALL |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL range-erase structure | **Yes** |
| Free-subtree dual isnil131 DestroyStr0C | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred`**.

---

## 7. Gaps

- Product map value_type / demangle (large node through +0x131).
- Residual undualed: successor `00404000`, erase `00408ad0`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/full-clear free-subtree + partial erase sealed; product open → **accept-with-gaps**.
