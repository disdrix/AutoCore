# Review B (skeptical / adversarial): `aa_0076f240` Math_Mat4MulVec4_AffineFast

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f240` |
| **VA** | `0x0076f240` |
| **Canonical name** | `Math_Mat4MulVec4_AffineFast` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076f240_Math_Mat4MulVec4_AffineFast.md` |
| **System** | graphics / math |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is only a full 4×4 multiply (no fast path) | Three distinct branches after last-column test | **Falsified** |
| 2 | Column-vector × column-major OpenGL layout | Uses `m[0,4,8,12]` for x — D3D row-vector / row-major | **Falsified** GL model |
| 3 | ESI/EDI are stack formals | Body uses `unaff_ESI`/`unaff_EDI`; callers preload registers | **Falsified** stack-only ABI |
| 4 | Always writes w from full row | Affine and direction paths force w=1 / w=0 | **Falsified** |
| 5 | Epsilon is 0 or FLT_EPSILON only | `read_memory` `0x00a240ec` = **1e-6**, `0x00aaa640` = **-1e-6** | **Attack fails** |
| 6 | `FUN_0040d450` is a hash or RNG | Callee is abs-diff / scaled near-equal of two floats | **Falsified** |
| 7 | Product name required to seal | No string/RTTI in this VA | **Agree leave structural** |
| 8 | Decompiler `float * FUN_0076f240(float *param_1)` is full truth | Hides ESI/EDI formals | **Overstated** signature plate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multiply indices / layout | **Confirmed** | Wrong port flips axes |
| Affine vs projective branch | **Confirmed** | Wrong w / missed translation |
| ESI/EDI/out ABI | **Confirmed** | Register smash if reimplemented as cdecl |
| Eps constants | **Confirmed** | Precision branch flip |
| Product English name | **Open** | Naming only |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x0076f240:
  prologue stack-align; COMISS vs [ESI+0xC] with DAT_00a240ec (1e-6)
  EBX = [EBP+8] out pointer
callees: FUN_0040d450 only
xrefs: 20 (gfx transform cluster + 76f6e0)
```

### Layout trap

Do **not** port as `out = M * v` column-major without transposing indices. Observed:

```
out.x = m[0]*vx + m[4]*vy + m[8]*vz + m[12]*vw
```

### ABI trap

Callers must set **ESI=matrix**, **EDI=vec4**, push **out***. Treating as pure `__cdecl(m,v,out)` will mis-bind.

### Fast-path trap

Porting only the full multiply loses affine speed path and changes `out.w` for points/directions — observable in any chain that reads w (e.g. `aa_0076f6e0` perspective divide).

---

## 4. Surviving contract for AutoCore

```
Math_Mat4MulVec4_AffineFast(out, m /*ESI*/, v /*EDI*/) -> out
  m: float[16] D3D row-major
  v: float[4]
  if last column non-affine (m03,m13,m23 ≉ 0 or m33 ≉ 1):
    full v*M including w row
  elif v.w ≉ 0 and v.w ≉ 1:
    full xyz; out.w = v.w
  elif v.w ≈ 1:
    R*v.xyz + T; out.w = 1
  else:
    R*v.xyz; out.w = 0
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| CF / multiply / branches | **Sealed Confirmed** |
| Register ABI | **Sealed Confirmed** |
| Product name | Open |
| Runtime capture | Open |

**Verdict:** accept-with-gaps. Safe shared math primitive for transform ports.
