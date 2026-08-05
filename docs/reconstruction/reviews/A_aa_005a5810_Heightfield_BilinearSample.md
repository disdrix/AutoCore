# Review A (reconstruction fidelity): `aa_005a5810` Heightfield_BilinearSample

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5810` |
| **VA** | `0x005a5810` |
| **Canonical name** | `Heightfield_BilinearSample` (inferred; parent dual already names this role) |
| **Ghidra symbol** | `FUN_005a5810` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005a5810_Heightfield_BilinearSample.md` |
| **System** | `world-terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Cell-local heightfield bilinear (diagonal-split) sample**:

* `this` = heightfield* in **ECX**
* Stack: **`int cellX`**, **`int cellZ`**, **`float fx`**, **`float fz`**
* Cleans with **`RET 0x10`**
* Returns **ST0 / float10** = raw height (caller `Heightfield_SampleY` divides by `hf+0x34`)

Fetches corner heights via heightfield vtbl **+0x30** (get height at integer grid coords). Uses a **diagonal split** on `fx + fz` vs `g_flOne` (1.0f @ `0x00a0f2a0`): lower triangle when `fx+fz ≤ 1`, upper when `fx+fz > 1`.

**Sole caller:** `FUN_005a58c0` / `Heightfield_SampleY` (already dualed), which scales world XZ, clamps cells to `[0, dim−2]`, and passes fractional remainders.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005a5810_FUN_005a5810.md` | Decomp (broken unaff_*) |
| Annotated | `docs/reconstruction/raw/aa_005a5810_FUN_005a5810.annotated.md` | Scaffold |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_005a5810.cpp` | Mirrors broken decomp (not formula-authoritative) |
| Function record | `docs/reconstruction/functions/aa_005a5810_FUN_005a5810.md` | Scaffold |
| Live decompile | Ghidra MCP `0x005a5810` | **Under-arity**; unaff_ESI/EDI/retaddr |
| Live `read_memory` | full body ~0x9E | **ABI + diagonal gate + vtbl+0x30 sealed** |
| Parent dual | `reviews/A_aa_005a58c0_Heightfield_SampleY.md` | Call contract |
| Terrain plate | `physics/verified/fn_004cfe60_castTerrain.md` | HF sample chain |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=hf; 4 stack args (ix, iz, fx, fz); **RET 0x10** | **High** | Epilogue `C2 10 00`; caller passes 4 values |
| Decompiler 2-arg + `unaff_*` is **wrong ABI display** | **High** | Asm loads `[esp+…]` for all four; `unaff_*` = missing stack floats |
| Corner fetch via `(**hf->vtbl)[+0x30](ix, iz)` | **High** | `FF 50 30` / `FF 52 30` |
| Samples include (ix+1,iz), (ix,iz+1), and either (ix,iz) or (ix+1,iz+1) | **High** | Path-dependent third sample |
| Diagonal gate: `comiss xmm0, [g_flOne]` on `fx+fz` | **High** | `F3 0F 10/58` then `0F 2F 05 a0 f2 a0 00`; `jbe` lower |
| Lower path when `fx+fz ≤ 1.0`; upper when `>` | **High** | `jbe` → lower block |
| Return ST0 float10 | **High** | FPU leave value; parent uses as raw Y |
| Exact closed-form lerp coefficients | **Probable** | FPU sequence present; not fully algebraically reduced this pass |
| vtbl+0x30 English “getHeight(i,j)” | **Probable** | Role from use |
| Product / PDB name | **Probable / open** | Parent already uses `Heightfield_BilinearSample` |

---

## 4. Control flow: decomp vs body

| Stage | Decompiler | Body truth |
|---|---|---|
| Arity | 2 stack ints | **4 stack args; RET 0x10** |
| fx/fz | `unaff_ESI` / `unaff_EDI` / `unaff_retaddr` | Stack floats after ix/iz |
| Sample calls | vtbl+0x30 | **Yes** |
| Gate vs `g_flOne` | Present but args wrong | **fx+fz vs 1.0** |
| Clean scaffold | Copies decomp | **Not formula-authoritative** — dual seals ABI/structure |

### Instruction seal (`read_memory` 2026-07-29)

```text
; prologue: push ecx, ebx, ebp; load iz→ebp, push esi/edi; load ix→edi; esi=this
; sample(ix+1, iz):  push iz; lea ebx,[edi+1]; push ebx; call [vtbl+0x30]; fstp local
; sample(ix, iz+1):  push iz+1; push ix; call [vtbl+0x30]; fstp local
; movss xmm0, fx; addss xmm0, fz; comiss xmm0, [g_flOne=0x00a0f2a0]
; jbe LOWER
; UPPER: sample(ix+1, iz+1) [ebx=ix+1, and companion]; FPU blend; ret 0x10
; LOWER: sample(ix, iz); FPU blend with prior corners; ret 0x10
```

Epilogue both paths: **`C2 10 00`**.

### Authoritative contract (structure)

```c
// Heightfield_BilinearSample (Probable)
// thiscall ECX = Heightfield*
// stack: int cellX, int cellZ, float fx, float fz
// RET 0x10; ST0 = raw height
float10 __thiscall Heightfield_BilinearSample(
    Heightfield* hf, int ix, int iz, float fx, float fz)
{
  // h10 = GetH(ix+1, iz);  h01 = GetH(ix, iz+1);   via vtbl+0x30
  if (fx + fz > 1.0f) {
    // upper triangle — uses h11 = GetH(ix+1, iz+1) (+ h10/h01)
    // return diagonal-upper blend (FPU; Probable closed form)
  } else {
    // lower triangle — uses h00 = GetH(ix, iz) (+ h10/h01)
    // return diagonal-lower blend (FPU; Probable closed form)
  }
}

// Parent Heightfield_SampleY:
//   scale/clamp → BilinearSample(hf, cellX, cellZ, fx, fz) / hf->heightScale(+0x34)
```

Classic diagonal-split bilinear (Probable closed forms):

```
// lower (fx+fz ≤ 1):  h00 + fx*(h10-h00) + fz*(h01-h00)
// upper (fx+fz > 1):  h11 + (1-fx)*(h01-h11) + (1-fz)*(h10-h11)
```

(Exact match to FPU micro-ops: **Probable** — structure sealed; algebraic reduction residual.)

---

## 5. Callers

| Function | Role |
|---|---|
| `FUN_005a58c0` Heightfield_SampleY | Sole caller; world→cell + scale divide |

---

## 6. Gaps / open

1. Fully reduced closed-form proof of both FPU paths (step-by-step ST stack).
2. Exact English/RTTI for vtbl+0x30 getter.
3. Clean cpp still mirrors broken decomp — should be rewritten when formula sealed.
4. Whether getter args are int or float (body pushes int regs / converted values).
5. Runtime golden vs known heightfield asset samples.
6. Product / PDB mangled name.

**Verdict:** **accept-with-gaps** — **ABI RET 0x10 + diagonal gate + vtbl+0x30 corner sampling + sole-caller contract** sealed; exact algebraic lerp + clean rewrite residual.
