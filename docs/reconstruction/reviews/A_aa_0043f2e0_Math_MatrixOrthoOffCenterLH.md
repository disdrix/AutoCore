# Review A (reconstruction fidelity): `aa_0043f2e0` Math_MatrixOrthoOffCenterLH

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043f2e0` |
| **VA** | `0x0043f2e0` |
| **Canonical name** | `Math_MatrixOrthoOffCenterLH` (structural; matches D3DX ortho-off-center LH) |
| **Ghidra name** | `FUN_0043f2e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0043f2e0_Math_MatrixOrthoOffCenterLH.md` |
| **System** | graphics (`gfxView.cpp` orthographic projection) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build a **left-handed orthographic off-center projection matrix** into `float out[16]` (D3D row-major).

| Input | Source |
|---|---|
| `out` | **EAX** |
| `left` | **XMM1** |
| `right` | **XMM4** |
| `top` | **XMM5** |
| `bottom` | stack `param_1` |
| `zn` (near) | stack `param_2` |
| `zf` (far) | stack `param_3` |

Formulas (leaf; no callees):

```
TWO = g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f   // shared literal; UI name is misnomer
ONE = g_flOne @ 0x00a0f2a0 = 1.0f

m[0]  = TWO / (right - left)
m[5]  = TWO / (top - bottom)
m[10] = ONE / (zf - zn)          // D3D-style 1/(zf-zn), not 2/(zf-zn)
m[12] = (left + right) / (left - right)
m[13] = (bottom + top) / (bottom - top)
m[14] = zn / (zn - zf)
m[15] = ONE

// zeros: m[1,2,3, 4,6,7, 8,9,11]
```

Single caller: `FUN_0075b7f0` (gfxView projection rebuild) when `*(view+0xEC) == 1` (ortho mode). Perspective mode uses sibling `FUN_0043f210`. Source string in caller:  
`"C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp"`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_0043f2e0_*` |
| Fresh decompile | Ghidra leaf @ `0x0043f2e0` |
| Caller | `FUN_0075b7f0` @ `0x0075b7f0` — ortho branch loads frustum from view+`0x118..0x124`, near/far @ `+0xF0/+0xF4`, scale `1/zoom` @ `+0x58` |
| Assembly context | `0x0075b8cb` CALL — preloads XMM1/4/5, `MOV EAX,[ESI+0x50]` (matrix dest) |
| Constants | `read_memory` `0x00a10e74` → `00 00 00 40` (**2.0**); `0x00a0f2a0` → **1.0** |
| Body range | `0x0043f2e0` – `0x0043f3aa` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Ortho off-center LH projection builder | **Confirmed** | formulas ≡ D3DXMatrixOrthoOffCenterLH-class |
| `m22 = 1/(zf-zn)` not `2/(zf-zn)` | **Confirmed** | decompile `g_flOne / (param_3 - param_2)` |
| TWO from `0x00a10e74` = 2.0 | **Confirmed** | `read_memory` |
| `g_flLevelUpUiBase_Inferred` is misnomer here | **High** | shared 2.0 pool (same as quat duals) |
| EAX=out; XMM1/4/5 + 3 stack floats | **Confirmed** | decompile + call site |
| Leaf (no calls) | **Confirmed** | analyze complete |
| Ortho mode selected by view+`0xEC==1` | **High** | caller branch |
| Product/PDB export name | **Open** | structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero off-diagonal slots | Yes |
| Scale diagonals m00/m11/m22 | Yes |
| Translation-like m30/m31/m32 | Yes |
| m33=1 | Yes |

### Recovered CF

```c
// void Math_MatrixOrthoOffCenterLH(float* out /*EAX*/,
//   float left /*XMM1*/, float right /*XMM4*/, float top /*XMM5*/,
//   float bottom, float zn, float zf /*stack*/)
const float TWO = 2.f, ONE = 1.f;
memset selective zeros on out;
out[0]  = TWO / (right - left);
out[5]  = TWO / (top - bottom);
out[10] = ONE / (zf - zn);
out[12] = (left + right) / (left - right);
out[13] = (bottom + top) / (bottom - top);
out[14] = zn / (zn - zf);
out[15] = ONE;
```

---

## 5. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_0075b7f0` | `0x0075b8cb` | gfxView rebuild projection when ortho (`+0xEC==1`) |

**1 xref only.**

---

## 6. Gaps

1. Product/PDB name (D3DX-like structural is sufficient for ports).
2. Full gfxView dual for perspective sibling `FUN_0043f210` and field map (partially known from caller).
3. Runtime matrix dump vs D3D reference.

**Verdict:** CF + formulas + ABI sealed. **accept-with-gaps.**
