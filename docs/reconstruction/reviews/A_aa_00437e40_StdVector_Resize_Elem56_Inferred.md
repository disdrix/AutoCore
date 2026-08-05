# Review A (reconstruction fidelity): `aa_00437e40` StdVector_Resize_Elem56_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437e40` |
| **VA** | `0x00437e40`–`0x00437f1e` exclusive (**222 B**) |
| **Canonical name** | `StdVector_Resize_Elem56_Inferred` |
| **Ghidra name** | `FUN_00437e40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-F) |
| **Counterpart** | `reviews/B_aa_00437e40_StdVector_Resize_Elem56_Inferred.md` |
| **System** | MSVC `vector` resize, elem **0x38** (dual `basic_string`) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + callers/xrefs + `get_function_by_address` + context decompile of stack dtor `FUN_00437da0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`vector<T>::resize(new_size, value)` for non-trivial T size **0x38**: grow by InsertN-class at end; shrink by erase `[new_end, end)`; destroy by-value fill on exit.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-F append) | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00437e40_FUN_00437e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem56_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00437e40.cpp` |
| Function records | `functions/aa_00437e40_FUN_00437e40.md`, `functions/aa_00437e40_StdVector_Resize_Elem56_Inferred.md` |
| Stack dtor context | `FUN_00437da0` decompile (two `~basic_string`) |
| Live | full hex 222 B; epilogue `C2 38 00`; magic `0x92492493` |

---

## 3. Signature (sealed)

```c
// EDI=vec*, ECX=new_size, stack Elem56 by value; RET 0x38
void StdVector_Resize_Elem56_Inferred(
    StdVectorElem56* vec,
    uint32_t new_size,
    Elem56 value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | **EDI** (`8B 77 04` begin) | **High** |
| new_size | **ECX** (`8B D9`; cmp vs size) | **High** |
| value blob 0x38 | stack; epilogue dtor + **`RET 0x38`** | **High** |
| begin/end @ +4/+8 | triad | **High** |
| stride 0x38 | magic + `*0x38` lea form | **High** |
| T = two basic_string | `FUN_00437da0` destroys +0 and +0x1c | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size via ÷0x38 magic | bytes | **High** |
| Grow → `FUN_00438520`(vec, end, count, &value) | call pushes | **High** |
| Shrink → `FUN_00438430`(vec, it*, new_end, end) | call pushes + lea ×56 | **High** |
| Equal / empty no-op | CF | **High** |
| Destroy stack value + RET 0x38 | `FUN_00437da0` + `C2 38 00` | **High** |
| SEH frame | push −1 / handler `LAB_009bcc88` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (222 B) — raw W38-F append.

Entry: `6A FF 68 88 CC 9B 00` (SEH) … `8B D9` (new_size→EBX) … `8B 77 04` (begin from EDI).  
Epilogue: `C7 44 24 14 FF FF FF FF` / `E8 … FUN_00437da0` / `C2 38 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | `FUN_00437ad0` (1), `FUN_00765740` (2), `FUN_0095e3e0` (3), `FUN_009895c0` (1) |
| Callees | `FUN_00438520`, `FUN_00438430`, `FUN_00437da0` |

---

## 7. Gaps

1. Product/MSVC demangle + exact T English (gfxBody residual only).  
2. Grow `FUN_00438520` / shrink `FUN_00438430` not dual-owned.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Resize ABI, size math, grow/shrink wiring, RET 0x38, and dual-string T layout sealed by full-body bytes + dtor context. Gaps are product English and unowned neighbors → **accept-with-gaps**.
