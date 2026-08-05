# Review A (reconstruction fidelity): `aa_0068a620` StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a620` |
| **VA** | `0x0068a620`–`0x0068a68a` (**106 B**) |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28` |
| **Ghidra name** | `FUN_0068a620` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AC) |
| **Counterpart** | `reviews/B_aa_0068a620_StdVector_InsertOne_RebindIt_Elem28.md` |
| **System** | MSVC `vector` insert-one + rebind, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + callers/callees/xrefs + parent `FUN_0068ae50` context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **one** POD-`0x1c` element at pointer iterator `where`, then rebind an out-iterator so it remains valid if `StdVector_InsertN_Elem28` reallocates `begin`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AC append) | `docs/reconstruction/raw/aa_0068a620_FUN_0068a620.md` |
| Annotated | `docs/reconstruction/raw/aa_0068a620_FUN_0068a620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0068a620.cpp` |
| Function records | `functions/aa_0068a620_FUN_0068a620.md`, `…_StdVector_InsertOne_RebindIt_Elem28.md` |
| Callee dual | W34-S `StdVector_InsertN_Elem28` (`0x0068a1d0`) |
| Live | decompile ≡ CF; full 106 B hex; `C2 0C 00`; `6A 01` count |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack outIt*, where*, value*; RET 0x0C; void
void __thiscall StdVector_InsertOne_RebindIt_Elem28(
    VectorElem28* vec,
    Elem28** outIt,
    Elem28* where,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F9`) | **High** |
| outIt / where / value | stack; `RET 0x0C` | **High** |
| begin/end @ +4/+8 | triad math | **High** |
| stride 0x1c | magic `0x92492493` + `6B F6 1C` | **High** |
| count literal 1 | `6A 01` before call | **High** |
| value is pointer | InsertN copies 7 dwords from arg | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| begin null → index 0 | decompile ≡ `74 1E` → `33 F6` | **High** |
| size==0 → index 0 | `75 04` / `33 F6` | **High** |
| else index = (where−begin)/0x1c | decompile ≡ magic path | **High** |
| insert-N count=1 | `6A 01` + `E8 … → 0068a1d0` | **High** |
| rebind `*outIt = begin'+index*0x1c` | `6B F6 1C; 03 77 04; 89 30` | **High** |
| `RET 0x0C` | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (106 B) — see raw W37-AC append.

Entry: `53 8B 5C 24 0C 56 57 8B F9 8B 77 04 …`  
Call: `51 6A 01 53 8B CF E8 58 FB FF FF` → `FUN_0068a1d0`  
Epilogue: `5F 89 30 5E 5B C2 0C 00`  
Pad `CC` after body.

---

## 6. Gaps

- Product English for POD `T` (0x1c).
- Caller `FUN_0068ae50` full dual not OWN.
- Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/CF/stride/count=1/rebind against live decompile + full hex. Residual product T → **accept-with-gaps**.
