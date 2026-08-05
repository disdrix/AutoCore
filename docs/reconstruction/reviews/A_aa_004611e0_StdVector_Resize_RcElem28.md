# Review A (reconstruction fidelity): `aa_004611e0` StdVector_Resize_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004611e0` |
| **VA** | `0x004611e0`–`0x004612c5` exclusive (**229 B**) |
| **Canonical name** | `StdVector_Resize_RcElem28` |
| **Ghidra name** | `FUN_004611e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-Q) |
| **Counterpart** | `reviews/B_aa_004611e0_StdVector_Resize_RcElem28.md` |
| **System** | MSVC `vector` resize, refcounted elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Resize an RC-elem28 vector to `n` elements using by-value fill `value`: grow via sealed insert-n at end; shrink via erase-range; Release stack value.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-Q append) | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004611e0_FUN_004611e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004611e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004611e0_StdVector_Resize_RcElem28.md` |
| Insert-n dual | W34-P `aa_004617a0` `StdVector_InsertN_RcElem28` |
| Callers | `FUN_00965ab0` @ `0x00965f47` |

---

## 3. Signature (sealed)

```c
// EDI=vec*, ECX=new_size, stack T[0x1c] by-value; RET 0x1C
void StdVector_Resize_RcElem28(
    StdVectorRc28* vec,
    uint32_t new_size,
    RcElem28 value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | EDI (`mov esi,[edi+4]`) | **High** |
| new_size | ECX → EBX (`8B D9`) | **High** |
| value by-value 0x1c | stack; `RET 0x1C`; resource @ T+0x10 released | **High** |
| stride 0x1c | magic `0x92492493` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| SEH + size from triad | decompile + bytes | **High** |
| Grow: InsertN at end, count=n−size | call `0x004617a0` | **High** |
| Shrink: erase [begin+n*0x1c, end) | call `0x00461720` | **High** |
| Equal: no-op | CF | **High** |
| Release stack resource + RET 0x1C | `C2 1C 00` + vtbl+8 | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (229 B) — raw W35-Q append.

Entry: `6A FF 68 18 E6 9B 00` (SEH).  
Epilogue: `83 C4 10 C2 1C 00`.  
Pad `CC` then `FUN_004612d0`.

---

## 6. Gaps

- Product/PDB T English (gfx residual only).  
- Erase helper `FUN_00461720` + destroy chain unowned.  
- Sole parent not dual-owned.  
- Runtime / bit-exact.

---

## Verdict

**accept-with-gaps** — resize ABI/CF/stride/Release sealed against insert-n family.
