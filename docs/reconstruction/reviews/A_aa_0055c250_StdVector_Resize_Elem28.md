# Review A (reconstruction fidelity): `aa_0055c250` StdVector_Resize_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c250` |
| **VA** | `0x0055c250`–`0x0055c306` exclusive (**182 B** / `0xB6`) |
| **Canonical name** | `StdVector_Resize_Elem28` |
| **Ghidra name** | `FUN_0055c250` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AA) |
| **Counterpart** | `reviews/B_aa_0055c250_StdVector_Resize_Elem28.md` |
| **System** | MSVC `vector<T>::resize(n, value)` POD stride **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resize a POD `vector` of **0x1c** elements to `new_size`, fill-growing with a by-value element and shrink-publishing a new `end` without nontrivial destruction.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AA append) | `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.md` |
| Annotated | `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0055c250.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055c250_StdVector_Resize_Elem28.md` |
| Grow callee dual | W34-R `StdVector_InsertN_Elem28` @ `0x0055be00` |
| Live | decompile ≡ CF skeleton; **`C2 20 00`** sealed both exits |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack new_size + Elem28 by value (0x1c); RET 0x20; void
void __thiscall StdVector_Resize_Elem28(
    VectorElem28* vec,
    uint32_t new_size,
    Elem28 value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F9`) | **High** |
| new_size | stack (`MOV EBP,[ESP+0x10]` after 3 pushes) | **High** |
| value 0x1c | stack; grow passes `&stack`; **RET 0x20** | **High** |
| begin/end @ +4/+8 | decompile + triad | **High** |
| stride 0x1c | magic `0x92492493` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| size = 0 if begin==0 else (end-begin)/0x1c | decompile + magic | **High** |
| Grow → `InsertN(end, new-size, &value)` | call @ `0x0055c2ae` | **High** |
| Shrink → `new_end=begin+n*0x1c`; `FUN_0055b470(end,end,new_end)` → `end=EAX` | bytes; helper entry `MOV EAX,[esp+0xC]` | **High** |
| Equal size no-op | CF | **High** |
| Dual `RET 0x20` | `C2 20 00` ×2 | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (182 B) — raw W37-AA append.

Entry: `55 56 57 8B F9`.  
Magic: `B8 93 24 49 92`.  
Grow epilogue: `5F 5E 5D C2 20 00`.  
Shrink epilogue: `5B 5F 5E 5D C2 20 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| Callers | `FUN_0055a5f0` @ `0x0055a684` (sole) |
| Callees | `FUN_0055be00` (InsertN), `FUN_0055b470` (shrink helper) |
| Family | InsertN W34-R; peer resize `0045c4b0` (different ABI regs/RET) |

---

## 7. Gaps

1. Product English for this host's `Elem28`.  
2. Full dual of shrink helper `FUN_0055b470` / parent `FUN_0055a5f0`.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — resize ABI/CF/stride/grow-InsertN/shrink-end sealed by full-body bytes + callee context; product type residual.
