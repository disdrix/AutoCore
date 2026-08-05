# Review A (reconstruction fidelity): `aa_0076f240` Math_Mat4MulVec4_AffineFast

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f240` |
| **VA** | `0x0076f240` |
| **Canonical name** | `Math_Mat4MulVec4_AffineFast` (structural; product/PDB open) |
| **Ghidra name** | `FUN_0076f240` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0076f240_Math_Mat4MulVec4_AffineFast.md` |
| **System** | graphics / math (matrix × vec4) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**4×4 matrix × vec4** with **affine / projective fast paths**.

Register convention (MSVC custom, recovered from body + call sites):

| Reg / slot | Role |
|---|---|
| **ESI** | `const float* m` — 16 floats, D3D row-major layout |
| **EDI** | `const float* v` — input vec4 |
| **stack arg** | `float* out` — writes `out[0..3]`; also returned in EAX |

Control flow:

1. **Projective / non-affine matrix** — if any of `m[3]`, `m[7]`, `m[11]` is outside ≈0 (`eps=1e-6` / `-eps`) **or** `m[15]` is outside ≈1:
   - Full `out = v * M` (row-vector · row-major):
     - `out.x = v.x*m[0] + v.y*m[4] + v.z*m[8]  + v.w*m[12]`
     - `out.y = v.x*m[1] + v.y*m[5] + v.z*m[9]  + v.w*m[13]`
     - `out.z = v.x*m[2] + v.y*m[6] + v.z*m[10] + v.w*m[14]`
     - `out.w = v.x*m[3] + v.y*m[7] + v.z*m[11] + v.w*m[15]`

2. **Else if input `v.w` is not ~0 and not ~1** (`FUN_0040d450(v.w, 1.0, 1e-6, 1e-6)` returns 0 when not near 1.0 under that test path):
   - Same xyz full mix with `v.w`; **`out.w = v.w`** (preserve w, skip `m[15]` row).

3. **Else if `v.w ≈ 1`** (near-equal helper returns non-zero):
   - Affine point: `out.xyz = v.xyz * R + T` (uses `m[12..14]` as translation; no `* v.w`); **`out.w = 1.0`**.

4. **Else (`v.w ≈ 0`)** — direction:
   - Linear only (no translation); **`out.w = 0.0`**.

Returns `out`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076f240_FUN_0076f240.md` |
| Annotated | `docs/reconstruction/raw/aa_0076f240_FUN_0076f240.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0076f240.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076f240_FUN_0076f240.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0076f240` |
| Callee | `FUN_0040d450` @ `0x0040d450` (float near-equal) |
| Bytes | `read_memory` entry — `push ebp; mov ebp,esp; and esp,~0xf; sub esp,0x1c`; loads `_DAT_00a240ec` |
| Constants | `read_memory` @ `0x00a240ec` → `1e-6`; `0x00aaa640` → `-1e-6`; imm `0x358637bd` = `1e-6`; `g_flOne` @ `0x00a0f2a0` |
| Callers | 17 named + sites including `FUN_0076f6e0`, `FUN_0076f670`, terrain/gfx paths |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = Mat4×Vec4 with affine fast paths | **Confirmed** | decompile ≡ multiply structure |
| ESI=matrix, EDI=vector, stack=out | **Confirmed** | unaff_ESI/EDI + `param_1`; call site `MOV EDI,EAX` / `LEA` out |
| D3D row-vector × row-major layout | **High** | `m[0,4,8,12]` contributes to x |
| Epsilon `1e-6` / `-1e-6` gates last column | **Confirmed** | `read_memory` `0x00a240ec` / `0x00aaa640` |
| `FUN_0040d450` = relative near-equal for w≈1 | **Confirmed** | callee body |
| Affine path skips translation when w=0 | **Confirmed** | else branch |
| Product / PDB name | **Open** | structural only |
| Exact `m[15]` compare constants `DAT_00a11078` / `_DAT_00a110e0` product meaning | **High** as band around 1.0 | values ~1.000001 / companion |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Non-affine last-column → full 4×4 | Yes |
| w not 0/1 → full xyz, preserve w | Yes |
| w≈1 → affine + T, w=1 | Yes |
| w≈0 → linear, w=0 | Yes |
| Write 4 floats to out; return out | Yes |

### Recovered CF

```c
// float* Math_Mat4MulVec4_AffineFast(float out[4])  // ESI=m[16], EDI=v[4]
bool nonAffine =
  !near0(m[3]) || !near0(m[7]) || !near0(m[11]) || !near1(m[15]);
if (nonAffine) {
  full_mul(out, m, v);                 // includes m[15]*v.w
} else if (!near0(v[3]) && !float_near(v[3], 1.f, 1e-6, 1e-6)) {
  full_mul_xyz(out, m, v); out[3] = v[3];
} else if (float_near(v[3], 1.f, 1e-6, 1e-6)) {
  affine_point(out, m, v); out[3] = 1.f;   // + m[12..14]
} else {
  linear_dir(out, m, v); out[3] = 0.f;     // no translation
}
return out;
```

---

## 5. Callers (inventory)

| Caller | Role (caller-owned) |
|---|---|
| `FUN_0076f6e0` | TransformPoint3 + optional perspective divide |
| `FUN_0076f670` | Sibling transform helper |
| `FUN_00435b40` / `FUN_00435d60` | Asset / mesh path |
| `FUN_009728e0` / `FUN_009729d0` / `FUN_00997b90` / `FUN_009813a0` | Gfx object / skin paths |
| `FUN_0099d780` family | Batch transform sites |
| ~20 xrefs total | Shared math primitive |

---

## 6. Gaps

1. Product/PDB name.
2. Exact numeric band for `m[15]` (`DAT_00a11078` / `_DAT_00a110e0`) beyond “near 1”.
3. Runtime bit-exact vs EXE; clean rename polish.

**Verdict:** CF + register ABI + multiply layout sealed. **accept-with-gaps.**
