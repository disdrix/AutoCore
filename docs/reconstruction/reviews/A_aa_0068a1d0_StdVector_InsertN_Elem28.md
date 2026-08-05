# Review A (reconstruction fidelity): `aa_0068a1d0` StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a1d0` |
| **VA** | `0x0068a1d0`–`0x0068a49a` (**714 B**) |
| **Canonical name** | `StdVector_InsertN_Elem28` |
| **Ghidra name** | `FUN_0068a1d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-S) |
| **Counterpart** | `reviews/B_aa_0068a1d0_StdVector_InsertN_Elem28.md` |
| **System** | MSVC `vector` insert-n, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (entry/full hex/epilogue) + callers/callees. Nested helper decompiles for POD proof. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a **0x1c POD** at pointer `where`, growing 1.5× or shifting in-place. Insert-one wrapper `FUN_0068a620` always passes count=`1` and rebinds an out iterator.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-S append) | `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0068a1d0_FUN_0068a1d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0068a1d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0068a1d0_StdVector_InsertN_Elem28.md` |
| Caller | `FUN_0068a620` decompile (count=1 rebind) |
| Helpers | `FUN_00687d10` / `FUN_00688550` / `FUN_006860f0` (7-dword memcpy) |
| Live | decompile ≡ CF; `C2 0C 00` ×3 sealed; full 714 B hex |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,
    Elem28* where,
    uint32_t count,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B D9`) | **High** |
| where / count / value | stack; `RET 0x0C` | **High** |
| begin/end/cap @ +4/+8/+0xC | triad math | **High** |
| stride 0x1c | magic + `6B ?? 1C` | **High** |
| max 0x9249249 | `BA 49 92 24 09` | **High** |
| POD local | `B9 07; F3 A5` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| POD value local (7 dwords) | entry bytes | **High** |
| count==0 early return | decompile | **High** |
| overflow → `FUN_00686070` | size+count vs max | **High** |
| Grow 1.5× + new + relocate + fill + delete old | decompile + helpers | **High** |
| delete is cdecl continue (not noreturn) | `E8… 83 C4 04` then triad writes | **High** |
| In-place hole / mid | decompile | **High** |
| RET 0x0C | three epilogues | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (714 B) — see raw W34-S append.

Entry: `55 8B EC 6A FF 68 70 A1 9A 00` … `8B D9 B9 07 00 00 00 8D 7D D4 F3 A5`.  
Epilogue: `5B 8B E5 5D C2 0C 00`.  
Pad `CC` @ `0x0068a49a`.

---

## 6. Gaps

- Product English for POD `T`.
- Nested helper plates free.
- Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/CF/POD-stride/max/1.5× against live decompile + full hex. Residual product T + nested English → **accept-with-gaps**.
