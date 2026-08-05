# Review A (reconstruction fidelity): `aa_0040d700` StdTree_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d700` |
| **VA** | `0x0040d700`–`0x0040d7b3` (**180 B**) |
| **Canonical name** | `StdTree_EraseRange_Val12` |
| **Ghidra name** | `FUN_0040d700` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-C) |
| **Counterpart** | `reviews/B_aa_0040d700_StdTree_EraseRange_Val12.md` |
| **System** | MSVC `_Tree` range erase Val12 |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style red-black **range erase** `[first, last)` on a Val12 facade (`head@+4`, `size@+8`, isnil@`+0x19`). Full-tree path frees via `StdTree_FreeSubtree_Val12` and resets the sentinel; partial path uses in-order successor + `FUN_004188e0` single erase.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-C append) | `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Val12.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d700.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d700_StdTree_EraseRange_Val12.md` |
| Free dual | `aa_0040d630` StdTree_FreeSubtree_Val12 (W31-A) |
| Single erase | `aa_004188e0` (map erase util) |
| Peer | `aa_004e5120` StdMap_EraseRange_Val12 (W28-P) |
| Live | decompile ≡ scaffold; body hex 180 B; RET `C2 0C 00` ×2 |

---

## 3. Signature (sealed)

```c
// ECX = map; stack out_it*, first*, last*; RET 0x0C; void
void __thiscall StdTree_EraseRange_Val12(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`8B F9`) | **High** |
| out / first / last | stack after EBX/ESI/EDI push | **High** |
| epilogue | `C2 0C 00` | **High** |

---

## 4. Control flow (bytes authority)

```
if (first == *head && last == head):
  FreeSubtree(head->parent)
  head links = head; size = 0; *out = *head; RET 0xC
while first != last:
  next = successor_Val12(first)   // isnil@+0x19
  FUN_004188e0(this, &slot, first)
  first = next
*out = first; RET 0xC
```

| Stage | Match | Conf |
|---|---|---|
| Full-range gate | Yes | **High** |
| Free + head reset + size 0 | Yes | **High** |
| Successor + single erase loop | Yes | **High** |
| `*out_it` both exits | Yes | **High** |
| Body size 180 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0040d6d0`, `FUN_0040d7c0` (full clear then delete head) |
| Callees | `FUN_0040d630`, `FUN_004188e0` |

---

## 6. Gaps

1. Product/MSVC demangle for map T.  
2. Full free path skips value vtbl destroy (clear path owns that).  
3. Nested `FUN_004188e0` product English residual (owned elsewhere).  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI, full/partial CF, Val12 successor, free+reset, and RET 0xC sealed against live decompile + bytes + peer. Residual product T + value-dtor policy → **accept-with-gaps**.
