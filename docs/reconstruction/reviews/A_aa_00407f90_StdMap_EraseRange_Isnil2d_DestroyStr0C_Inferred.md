# Review A (reconstruction fidelity): `aa_00407f90` StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407f90` |
| **VA** | `0x00407f90`–`0x00408042` exclusive (**178 B** / `0xB2`) |
| **Canonical name** | `StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00407f90` |
| **Review date** | `2026-08-05` (WQ9K-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00407f90_StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred.md` |
| **System** | MSVC `std::_Tree` range erase (isnil@+0x2d string-key family) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map/set range erase** for the compact string-key family (`isnil@+0x2d`). Full-range fast path frees the tree via dualed `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` (`0x00409970`); partial path inlines successor (isnil@+0x2d) and calls dualed `StdMap_StringKey_EraseAndRebalance_Inferred` (`0x004094c0`). Used by map tidy/dtor full-clear paths (`FUN_00404ec0`, `FUN_004061f0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05); unaff_EDI = map; successor inlined |
| Bytes | `read_memory` 220 B; tails `C2 0C 00`; isnil `+0x2d` immediates; free → `00409970`; erase → `004094c0` |
| Free subtree | dualed `aa_00409970` WQ9J-I |
| Single erase | dualed `StdMap_StringKey_EraseAndRebalance_Inferred` / `aa_004094c0` WQ9J-F |
| Peer | OWN isnil131 erase-range `00407b70`; isnil29 `Map_EraseRange_C` `00407d70` |
| Callers | `FUN_00404ec0`, `FUN_004061f0` |

---

## 3. Signature (sealed)

```c
// Register-this EDI; RET 0x0c
Node** StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred(
    /*EDI*/ Map* map, Node** outIt, Node* first, Node* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | **EDI** (callers pre-load; entry uses `[EDI+4]`) | **High** |
| outIt / first / last | stack | **High** |
| cleanup | both exits `RET 0x0c` | **High** |
| return | EAX = outIt | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Full clear: first==*head && last==head | decomp ≡ bytes | **High** |
| FreeSubtree(head->parent) ECX=map then head reset + size 0 | rel call → `0x00409970` | **High** |
| Partial: successor isnil@+0x2d | immediates `0x2d` | **High** |
| StringKey erase `004094c0` | rel call | **High** |
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
| Free-subtree dual isnil2d DestroyStr0C | **Yes** |
| Partial dualed StringKey erase | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdMap_EraseRange_Isnil2d_DestroyStr0C_Inferred`**.

---

## 7. Gaps

- Product map English / demangle for compact string-key map.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/isnil2d/full-clear free-subtree + partial StringKey erase sealed → **accept-with-gaps**.
