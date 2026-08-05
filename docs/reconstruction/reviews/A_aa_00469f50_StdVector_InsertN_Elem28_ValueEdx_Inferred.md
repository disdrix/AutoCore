# Review A (reconstruction fidelity): `aa_00469f50` StdVector_InsertN_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f50` |
| **VA** | `0x00469f50`–`0x0046a203` (**692 B** / `0x2B4`) |
| **Canonical name** | `StdVector_InsertN_Elem28_ValueEdx_Inferred` |
| **Ghidra name** | `FUN_00469f50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-Q) |
| **Counterpart** | `reviews/B_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| **System** | util / container (generic POD vector insert-n) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style `vector<T>::insert` for **POD T size 0x1c**: insert `count` copies of `*value` at `where`. **Value-in-EDX** ABI flavor (stack carries vec/where/count). Algorithm twin of `00466ea0` with different calling convention.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-Q append) | `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00469f50_FUN_00469f50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_ValueEdx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00469f50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| Size helper | sealed `StdVector_Elem28_Size` @ `0x00469c50` |
| Sole caller | `FUN_00469e20` @ `0x00469e73` (insert-one) |
| Live | decompile CF ≡ insert-n; **bytes** seal `RET 0x0C` + value snapshot |

---

## 3. Signature (sealed)

```c
// EDX = value*; stack vec*, where*, count; RET 0x0C; void
// ECX clobbered (rep movsd count=7) — not a formal
void StdVector_InsertN_Elem28_ValueEdx_Inferred(
    /*EDX*/ const Elem28* value,
    /*stack*/ VectorElem28* vec,
    /*stack*/ Elem28* where,
    /*stack*/ uint32_t count);
```

| Formal | Source | Conf |
|---|---|---|
| value | EDX (`8B F2` + `F3 A5` ×7) | **High** |
| vec | `[ebp+8]` | **High** |
| where | `[ebp+0xC]` | **High** |
| count | `[ebp+0x10]` | **High** |
| triad +4/+8/+0xC | decompile | **High** |
| stride 0x1c / max 0x9249249 | magic + imm | **High** |
| RET 0x0C | `C2 0C 00` (two sites) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Value snapshot `mov ecx,7; rep movsd` | entry bytes | **High** |
| count==0 early-out | decompile | **High** |
| overflow → `FUN_004540b0` | rel32 | **High** |
| Grow 1.5× + new + copy/fill/copy + delete | decompile | **High** |
| In-place hole/mid | decompile | **High** |
| Dual RET 0x0C | `read_memory` | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: `55 8B EC 6A FF 68 B0 C8 9B 00 … B9 07 00 00 00 8B F2 8D 7D D0 F3 A5 …`.  
Epilogue: `… 5B 8B E5 5D C2 0C 00`.  
Pad `CC`. Full body hex — raw W34-Q append.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00469e20` only (direct) |
| Callees | throw; size; copy/fill/reverse/assign; new/delete |

---

## 7. Gaps

1. Product demangle / concrete T.  
2. Nested helper duals + insert-one parent.  
3. Helper register formal residual.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — insert-n ABI/CF/stride/max/growth sealed; product plate + nested helpers residual.
