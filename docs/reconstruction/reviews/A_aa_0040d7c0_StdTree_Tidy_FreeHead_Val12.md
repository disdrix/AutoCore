# Review A (reconstruction fidelity): `aa_0040d7c0` StdTree_Tidy_FreeHead_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d7c0` |
| **VA** | `0x0040d7c0`–`0x0040d81c` (**92 B**) |
| **Canonical name** | `StdTree_Tidy_FreeHead_Val12` |
| **Ghidra name** | `FUN_0040d7c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-B) |
| **Counterpart** | `reviews/B_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` |
| **System** | MSVC `_Tree` tidy / free head (Val12) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex past Ghidra end) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tidy tree subobject: full-range erase via `FUN_0040d700`, free header with `operator_delete`, null head@+4 and size@+8.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-B append) | `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d7c0_FUN_0040d7c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Val12.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d7c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` |
| Parent complete dtor | `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor (W31-A **accept-with-gaps**) |
| Free-subtree | `aa_0040d630` StdTree_FreeSubtree_Val12 (W31-A) |
| Live | decompile truncated; 92 B hex seals epilogue |

---

## 3. Signature (sealed)

```c
// ECX = tree*; bare RET; void
void __fastcall StdTree_Tidy_FreeHead_Val12(StdTree_Val12* tree);
```

| Formal | Source | Conf |
|---|---|---|
| tree | ECX (`8B F1`) | **High** |
| head load/store @+4 | `8B 46 04` / `89 46 04` | **High** |
| size null @+8 | `89 46 08` | **High** |
| cleanup | `C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH setup (LAB_009bda78)
ESI = this
head = *(this+4)
FUN_0040d700(this, &out, *head /*left begin*/, head /*end*/)
operator_delete(head)          // cdecl + ADD ESP,4
*(this+4) = 0
*(this+8) = 0
restore SEH; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Full-range erase call | `PUSH head; PUSH *head; LEA out; MOV ECX,ESI; CALL 0040d700` | **High** |
| Delete head | `PUSH [ESI+4]; CALL operator_delete; ADD ESP,4` | **High** |
| Null head+size | `XOR EAX,EAX; MOV [ESI+4],EAX; MOV [ESI+8],EAX` | **High** |
| Bare RET | `C3` | **High** |
| Ghidra end @ 0040d800 | **Truncated** (false noreturn) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (92 B) — see raw W32-B append.

Entry: `6A FF 68 78 DA 9B 00` (SEH).  
Epilogue: `33 C0 89 46 04 89 46 08 5E 64 89 0D … 83 C4 10 C3`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0040d820` complete dtor (`LEA ECX,[ESI+4]`); Unwind |
| Callees | `FUN_0040d700`, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for map T / host class.  
2. Nested `FUN_0040d700` dual ownership (erase / full free path).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — tidy stage order/ABI/offsets sealed by bytes; product names residual.
