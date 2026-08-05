# Review A (reconstruction fidelity): `aa_00437f70` StdVector_Resize_Elem20_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437f70` |
| **VA** | `0x00437f70`–`0x00438040` exclusive (**208 B**) |
| **Canonical name** | `StdVector_Resize_Elem20_Inferred` |
| **Ghidra name** | `FUN_00437f70` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-F) |
| **Counterpart** | `reviews/B_aa_00437f70_StdVector_Resize_Elem20_Inferred.md` |
| **System** | MSVC `vector` resize, elem **0x14** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`vector<T>::resize(new_size, value)` for T size **0x14**: grow by InsertN-class at end; shrink by erase `[new_end, end)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-F append) | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00437f70_FUN_00437f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem20_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00437f70.cpp` |
| Function records | `functions/aa_00437f70_FUN_00437f70.md`, `functions/aa_00437f70_StdVector_Resize_Elem20_Inferred.md` |
| Live | full hex 208 B; epilogue `C2 14 00`; magic `0x66666667` |

---

## 3. Signature (sealed)

```c
// ESI=vec*, ECX=new_size, stack Elem20 by value; RET 0x14
void StdVector_Resize_Elem20_Inferred(
    StdVectorElem20* vec,
    uint32_t new_size,
    Elem20 value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | **ESI** (`8B 4E 04` begin) | **High** |
| new_size | **ECX** (`8B F9`; cmp vs size) | **High** |
| value blob 0x14 | stack; **`RET 0x14`** | **High** |
| begin/end @ +4/+8 | triad | **High** |
| stride 0x14 | magic `0x66666667` + `*0x14` lea | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size via ÷0x14 magic | bytes | **High** |
| Grow → `FUN_004388b0`(vec, end, count, &value) | call pushes | **High** |
| Shrink → `FUN_00438850`(vec, it*, new_end, end) | call pushes | **High** |
| Equal / empty no-op | CF | **High** |
| RET 0x14 | `C2 14 00` | **High** |
| Epilogue `FUN_00437f20` | call present; **role residual** | Medium |

---

## 5. Machine bytes (`read_memory`)

Full body hex (208 B) — raw W38-F append.

Entry: `6A FF 68 58 EA 9B 00` (SEH) … `8B F9` (new_size→EDI) … `8B 4E 04` (begin from ESI).  
Epilogue: state −1 / `E8 … FUN_00437f20` / `C2 14 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | `FUN_00765740` @ `0x00765914`, `0x00765d6c` only |
| Callees | `FUN_004388b0`, `FUN_00438850`, `FUN_00437f20` |

---

## 7. Gaps

1. Product/MSVC demangle + exact T English (0x14 lanes).  
2. Grow `FUN_004388b0` / shrink `FUN_00438850` not dual-owned.  
3. Epilogue `FUN_00437f20` semantics residual (Ghidra shows vector-of-0x38 destroy — do not over-claim).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Resize ABI, size math, grow/shrink wiring, and RET 0x14 sealed by full-body bytes. Gaps are product English, unowned neighbors, and epilogue helper → **accept-with-gaps**.
