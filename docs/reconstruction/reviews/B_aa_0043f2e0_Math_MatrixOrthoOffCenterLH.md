# Review B (skeptical / adversarial): `aa_0043f2e0` Math_MatrixOrthoOffCenterLH

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043f2e0` |
| **VA** | `0x0043f2e0` |
| **Canonical name** | `Math_MatrixOrthoOffCenterLH` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0043f2e0_Math_MatrixOrthoOffCenterLH.md` |
| **System** | graphics (gfxView) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is perspective projection | No FOV/tan; ortho formulas; caller only in ortho branch | **Falsified** |
| 2 | OpenGL `2/(zf-zn)` style z | Uses **`1/(zf-zn)`** | **Falsified** GL z |
| 3 | `g_flLevelUpUiBase_Inferred` is UI level-up scale | Shared **2.0f** pool; used as TWO in matrix | **Falsified** UI role here |
| 4 | Six stack float formals | left/right/top in **XMM**; only bottom/zn/zf on stack | **Falsified** all-stack model |
| 5 | Writes only diagonal | Also m30/m31/m32 (indices 12/13/14) | **Falsified** diagonal-only |
| 6 | Multiple call sites | **1** xref (`FUN_0075b7f0`) | **Attack fails** — rare leaf |
| 7 | Identical to `FUN_0043f210` | Sibling is perspective path in same caller | **Falsified** collapse |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ortho off-center LH formulas | **Confirmed** | Broken camera ortho |
| z row D3D 1/(zf-zn) | **Confirmed** | Depth wrong vs D3D |
| TWO=2.0 @ `0xa10e74` | **Confirmed** | 1.0 mistake halves scale |
| Register/stack ABI | **Confirmed** | Silent wrong frustum |
| Product name | **Open** | Naming |

---

## 3. Cross-check against raw / live / bytes

```
leaf decompile ≡ raw.
Caller FUN_0075b7f0:
  if near≈far → log gfxView.cpp:0xA9 "Couldn't create projection matrix..."
  if *(view+0xEC)==0 → perspective FUN_0043f210
  if ==1 → scale L/R/B/T by 1/zoom; CALL 0x0043f2e0
read_memory 0x00a10e74 = 2.0f
```

### Trap: UI symbol name

Ports must treat `g_flLevelUpUiBase_Inferred` as **2.0f literal**, not a level-up UI constant, in this matrix.

### Trap: RH vs LH / OpenGL

`m[14] = zn/(zn-zf)` and `m[10]=1/(zf-zn)` match **D3D LH ortho off-center**, not GL `glOrtho`.

### Trap: zero division

No runtime guard inside this leaf — caller ensures near≠far before either projection builder.

---

## 4. Surviving contract for AutoCore

```
Math_MatrixOrthoOffCenterLH(out, left, right, bottom, top, zn, zf)
  // ABI: EAX=out; XMM1=left; XMM4=right; XMM5=top; stack bottom,zn,zf
  // D3D LH off-center ortho into float[16] row-major
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| Formulas / ABI / leaf | **Sealed Confirmed** |
| gfxView field map dual | Partial via caller |
| Product name | Open |
| Runtime matrix capture | Open |

**Verdict:** accept-with-gaps.
