# Review A (reconstruction fidelity): `aa_0040d6d0` StdTree_Tidy_FreeHead_Bare_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d6d0` |
| **VA** | `0x0040d6d0`–`0x0040d6fe` exclusive (**46 B**) |
| **Canonical name** | `StdTree_Tidy_FreeHead_Bare_Val12` |
| **Ghidra name** | `FUN_0040d6d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-A) |
| **Counterpart** | `reviews/B_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` |
| **System** | MSVC `_Tree` tidy / free header (Val12, bare) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bare Val12 tree tidy (no SEH): full-range erase via `StdTree_EraseRange_Val12`, free header node, null `head` and `size`. SEH-unwind twin of `StdTree_Tidy_FreeHead_Val12` @ `0x0040d7c0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-A append) | `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Bare_Val12.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d6d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` |
| Peer SEH tidy | `aa_0040d7c0` StdTree_Tidy_FreeHead_Val12 (W32-B) |
| Erase range | `aa_0040d700` StdTree_EraseRange_Val12 (W32-C) |
| Live | decompile truncated after delete; **46 B hex seals null + RET** |

---

## 3. Signature (sealed)

```c
// ECX = tree*; bare RET (C3); void
void __fastcall StdTree_Tidy_FreeHead_Bare_Val12(StdTree_Val12* tree);
```

| Formal | Source | Conf |
|---|---|---|
| tree | ECX (`56 8B F1`) | **High** |
| head@+4 / size@+8 | post-delete stores | **High** |
| free this? | no (frees head only) | **High** |
| SEH | none in body | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this (tree)
out slot = push ECX
head = [ESI+4]
CALL FUN_0040d700(tree, &out, *head, head)   // full-range erase
operator_delete(head); ADD ESP,4
[ESI+4] = 0; [ESI+8] = 0
POP ESI; POP ECX; RET
```

| Stage | Match | Conf |
|---|---|---|
| Full-range erase args | Yes (`*head`, `head`) | **High** |
| Free header only | Yes | **High** |
| Null head+size after delete | Yes (bytes; decompiler missed) | **High** |
| Bare RET / no SEH | Yes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (46 B):

```
51568bf18b46048b0850518d44240c508bcee8190000008b4e0451e832c1070083c40433c08946048946085e59c3
```

Pad `CC` then next function.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | Unwind `@009bda70` (JMP) |
| Callees | `FUN_0040d700`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for map T.  
2. Why bare vs SEH twin (`0040d7c0`) — path selection open beyond unwind xref.  
3. Nested erase-range value-dtor policy (owned W32-C).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, full-erase → free-head → null order, and bare epilogue sealed by bytes over false-noreturn decompile. Residual product plate + twin rationale → **accept-with-gaps**.
