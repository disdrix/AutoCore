# Review A (reconstruction fidelity): `aa_00466ea0` StdVector_InsertN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466ea0` |
| **VA** | `0x00466ea0`–`0x00467174` (**725 B** / `0x2D5`) |
| **Canonical name** | `StdVector_InsertN_Elem28_CountEcx_Inferred` |
| **Ghidra name** | `FUN_00466ea0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-Q) |
| **Counterpart** | `reviews/B_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| **System** | util / container (generic POD vector insert-n) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry/magic/epilogue + body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style `vector<T>::insert` for **POD T size 0x1c**: insert `count` copies of `*value` at iterator `where`, growing capacity 1.5× when needed or shifting in-place when capacity allows. Count-in-ECX / vec-in-EDX ABI flavor (peer of dword `StdVector_InsertN_Dword_CountEcx_Inferred` @ `0x00419880`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-Q append) | `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00466ea0_FUN_00466ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28_CountEcx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00466ea0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| Size helper | sealed `StdVector_Elem28_Size` @ `0x00469c50` (W33-J) |
| Sole caller | `FUN_00466df0` @ `0x00466e46` |
| Live | decompile CF ≡ insert-n; **bytes** seal `RET 8` + value formal |

---

## 3. Signature (sealed)

```c
// ECX = count; EDX = vec*; stack where*, value*; RET 8; void
void StdVector_InsertN_Elem28_CountEcx_Inferred(
    /*ECX*/ uint32_t count,
    /*EDX*/ VectorElem28* vec,   // +4 begin, +8 end, +0xC capEnd
    /*stack*/ Elem28* where,
    /*stack*/ const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| count | ECX (`8B D9`) | **High** |
| vec | EDX (`8B F2`) | **High** |
| where | `[ebp+8]` | **High** |
| value | `[ebp+0xC]` SSE/dword snapshot | **High** (bytes win; decompiler under-counted) |
| begin/end/cap @ +4/+8/+0xC | triad math | **High** |
| stride 0x1c | `/0x1c` magic `0x92492493` | **High** |
| max 0x9249249 | `BA 49 92 24 09` | **High** |
| RET 8 | `C2 08 00` (two sites) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Value snapshot 0x1c to stack | entry SSE + dwords | **High** |
| count==0 early-out | decompile + `0F 84` | **High** |
| overflow → `FUN_004540b0` | rel32 → `004540b0` | **High** |
| Grow 1.5× + new + relocate + fill + delete | decompile + helpers | **High** |
| In-place hole/mid arms | decompile | **High** |
| Dual RET 8 (realloc early + fallthrough) | `read_memory` | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: `55 8B EC 6A FF 68 90 DC 9B 00 … 8B D9 8B F2 … BA 49 92 24 09 … E8 … → FUN_004540b0`.  
Epilogue (both paths): `… 5B 8B E5 5D C2 08 00`.  
Pad `CC`. Full body hex — raw W34-Q append.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00466df0` only (direct) |
| Callees | throw; size; uninit-copy/fill; reverse-copy; assign; new/delete |

---

## 7. Gaps

1. Product/MSVC demangle / concrete T.  
2. Nested helper duals + parent resize.  
3. Per-call helper register map residual.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — insert-n ABI/CF/stride/max/growth sealed; product plate + nested helpers residual.
