# Review B (skeptical / adversarial): `aa_0043f210` Math_Matrix4x4_Set16

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043f210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-E) |
| **Counterpart** | `reviews/A_aa_0043f210_Math_Matrix4x4_Set16.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This **is** `D3DXMatrixPerspectiveFovLH` / builds perspective from FOV | **Falsified** — no tan/FOV/aspect; pure 16-float store |
| 2 | Identical to ortho sibling `FUN_0043f2e0` | **Falsified** — sibling has div/mul formulas + globals 1.0/2.0; this body has none |
| 3 | cdecl / bare `ret` | **Falsified** — `ret 0x40`; ECX dest |
| 4 | Dest on stack / first stack arg | **Falsified** — `mov edi, ecx` then stores via EDI |
| 5 | Copies more/fewer than 16 floats | **Falsified** — `mov ecx, 16; rep movsd` |
| 6 | Non-leaf / writes globals | **Falsified** — leaf load/store only |
| 7 | Integer `undefined4` means non-float matrix | **Falsified as semantics** — bytes are `movss` / DWORD moves of float bits |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store-only leaf | **High** | Over-porting as projection math |
| ECX + ret 0x40 | **High** | Stack imbalance / wrong dest |
| 16 elements | **High** | Truncated/overrun matrix |
| Name not “Perspective*” | **High** | Mis-indexing gfx math |
| Row-major labeling of args | **Medium–High** | Transpose if a rare caller is column-major (no evidence) |

---

## 3. Cross-check against raw + bytes

```
out[0..15] = stack_floats[0..15]
return (ret 0x40)
```

Clean must **not** invent:

- cot(FOV), aspect ratios, near/far Z formulas
- Ortho left/right/top/bottom math (owned by sibling)
- Extra W or 4×4 multiply

Prior review notes that called this “perspective sibling” mean **call-site role** (gfxView mode 0 uses this after computing scales), not body semantics.

---

## 4. Surviving contract for AutoCore

```c
// Port of Math_Matrix4x4_Set16
void Matrix4x4_Set16(float out[16],
    float m00, float m01, float m02, float m03,
    float m10, float m11, float m12, float m13,
    float m20, float m21, float m22, float m23,
    float m30, float m31, float m32, float m33)
{
  out[0]=m00; out[1]=m01; out[2]=m02; out[3]=m03;
  out[4]=m10; out[5]=m11; out[6]=m12; out[7]=m13;
  out[8]=m20; out[9]=m21; out[10]=m22; out[11]=m23;
  out[12]=m30; out[13]=m31; out[14]=m32; out[15]=m33;
}
// Prefer memcpy of float[16] when source is already contiguous.
```

---

## 5. Open questions

1. Product symbol name.
2. Whether any caller relies on the aligned local spill (observable only under concurrent dest aliasing — none expected).

**Verdict:** **accept**
