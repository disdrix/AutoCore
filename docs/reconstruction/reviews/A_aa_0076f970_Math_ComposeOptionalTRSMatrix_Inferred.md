# Review A (reconstruction fidelity): `aa_0076f970` Math_ComposeOptionalTRSMatrix_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f970` |
| **VA** | `0x0076f970` |
| **Body** | `0x0076f970`–`0x0076fc93` (**0x323** bytes; cdecl `ret`) |
| **Canonical name** | `Math_ComposeOptionalTRSMatrix_Inferred` |
| **Ghidra name** | `FUN_0076f970` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_0076f970` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W18-P) |
| **Counterpart** | `reviews/B_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` |
| **System** | math / graphics transforms |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, caller `0x00972e50` bytes (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Build a 4×4 affine matrix** from optional TRS pieces and left-multiply them into `dest`:

- Optional base translation (`param_6`) or identity (`DAT_00afdf70`).
- Optional outer translation pair (ECX / EAX as ±T sandwich stages).
- Optional inner quat → R, outer quat → R and R⁻¹, scale → diagonal S.
- Core mul helper `FUN_00412d80(dest, A, dest)`.

**Primary product path:** `GfxNode_ComposeWorldMatrix_ClearDirty` (`0x00972e50`) rebuilds node matrix then clears dirty **bit 0** at `node+0xBC`.

### GfxNode reduction (sealed)

```
// EAX=ECX=0x00D1A6C0 (static zeros), rOuter=(0,0,0,1)
dest(node+0) = S(node+0x9C) * R(node+0x80) * T(node+0x90)
```

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_0076f970_FUN_0076f970.md` | v2026-07-29 append |
| Annotated | `raw/aa_0076f970_FUN_0076f970.annotated.md` | machine CF sealed |
| Clean | `reconstructed-exact/Math_ComposeOptionalTRSMatrix_Inferred.cpp` | stage order ≡ decompile |
| Scaffold | `reconstructed-exact/FUN_0076f970.cpp` | Ghidra name |
| Function record | `functions/aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md` | dual sealed |
| Live decompile | Ghidra `0x0076f970` | ≡ raw |
| Identity | `read_memory` `DAT_00afdf70` | diag 1.0f |
| Zero global | `read_memory` `0x00D1A6C0` | zeros |
| Caller dual | `A/B_aa_00972e50_GfxNode_ComposeWorldMatrix_ClearDirty` | call shape sealed |
| Mul / quat helpers | decompile `00412d80`, `0076eb00`, `0076e6b0` | roles sealed |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range + cdecl return | **Confirmed** | epilogue `c3`; callers `add esp,14` |
| Five stack formals order | **Confirmed** | push order @ `00972e50` |
| EAX/ECX optional float3* | **Confirmed** | prologue tests + T builders |
| Stage null-skips + mul order | **Confirmed** | eight conditional `FUN_00412d80` |
| Identity / scale / T builders | **Confirmed** | copy-from-`DAT_00afdf70` + stores |
| Quat path uses eb00 / e6b0 | **Confirmed** | callees list + decompile |
| GfxNode S·R·T reduction | **Confirmed** | zeros global + identity outer quat |
| Node field English (+0x80 quat, +0x90 T, +0x9C S) | **High** | formal consumption (not PDB) |
| Product composer name | **Probable** | `_Inferred` |
| Dest always node+0 for all callers | **Probable** | sealed for GfxNode; other callers similar |
| Runtime float samples | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Build optional ±T from EAX | **Yes** |
| Build R + Rinv from param_3 | **Yes** |
| Build S from param_4 | **Yes** |
| Build ±T from ECX/param_1 | **Yes** |
| Build R from param_5 | **Yes** |
| Base I or T(param_6) → dest | **Yes** |
| Left-mul order tB,R5,-tB,tA,R3,S,Rinv3,-tA | **Yes** |
| Return dest | **Yes** |

---

## 5. Gaps

1. Product/PDB name.
2. Exhaustive non-GfxNode call sites (skeleton direct `FUN_0076f970` with non-zero T_A/T_B).
3. Row- vs column-vector documentation for ports (mul helper layout sealed in `00412d80` dual territory).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/GfxNode map High; product name open.
