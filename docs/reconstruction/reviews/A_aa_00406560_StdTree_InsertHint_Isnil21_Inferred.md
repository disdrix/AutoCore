# Review A (reconstruction fidelity): `aa_00406560` StdTree_InsertHint_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406560` |
| **VA** | `0x00406560`–`0x00406705` exclusive (**421 B** / `0x1A5`) |
| **Canonical name** | `StdTree_InsertHint_Isnil21_Inferred` |
| **Ghidra name** | `FUN_00406560` |
| **Review date** | `2026-08-04` (WQ9H-F OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00406560_StdTree_InsertHint_Isnil21_Inferred.md` |
| **System** | MSVC `std::_Tree` unique insert-with-hint (isnil@+0x21; 2-dword key) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set insert(const_iterator hint, const value_type&)** for the **isnil@+0x21** node family. Attempts local always-insert via residual `FUN_00407200` on empty / begin / end / neighbor-valid hints; otherwise falls back to insert-or-find `FUN_00407060` and returns the node only.

Pair-key less is dualed `StdPairKey_Less_HiSignedLoUnsigned_Inferred` (`0x00401480`) — shared leaf with dualed isnil29 InsertHint `0x004cc220`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-04) |
| Bytes | entry empty-path + pred/succ insert where + epilogue `RET 0x0c` |
| Pair-key less dual | `aa_00401480` WQ9G-B |
| InsertHint isnil29 peer | `aa_004cc220` WQ9F-E |
| Sole caller | `FUN_004055c0` @ `0x00405609` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 0x0c
Node** __thiscall StdTree_InsertHint_Isnil21_Inferred(
    Map* map, Node** outIt, Node* hint, const void* value);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`MOV ESI,ECX`) | **High** |
| outIt / hint / value | stack after frame | **High** |
| cleanup | `ADD ESP,8; C2 0C 00` | **High** |
| return | outIt in EAX | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Empty → Insert(1, head) | size@+8 == 0 | **High** |
| Hint == leftmost | inlined signed-hi/unsigned-lo less | **High** |
| Hint == head (end) | rightmost key < value → Insert(0, rightmost) | **High** |
| value < hint → Prevnode | `FUN_005adff0` on local | **High** |
| pred < value < hint | open-side Insert via isnil@+0x21 on pred.right | **High** (bytes: where=pred/addLeft=0 or where=hint/addLeft=1) |
| hint < value → Nextnode | `FUN_004e12c0` | **High** |
| Open-side Insert | bytes: where=hint/addLeft=0 or where=succ/addLeft=1 | **High** |
| Fallback InsertOrFind | `FUN_00407060`; `*outIt = pair.node` | **High** |
| Key less helper | `FUN_00401480` (2-dword hi/lo) | **High** |
| Decomp where-alias after prev/next | **slightly wrong** — bytes override | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_004055c0` only (`xref_count=1`) |
| Return to product | caller returns **node+0x18** (mapped) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Insert-hint CF peer of isnil29 dual | **Yes** |
| isnil@+0x21 attachment immediates | **Yes** |
| Shared pair-key less `00401480` | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertHint_Isnil21_Inferred`**.

---

## 7. Gaps

- Product pair/value demangle.
- Residual duals: always-insert `00407200`, insert-or-find `00407060`, pred/succ isnil21.
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/isnil21/pair-key sealed; product residual → **accept-with-gaps**.