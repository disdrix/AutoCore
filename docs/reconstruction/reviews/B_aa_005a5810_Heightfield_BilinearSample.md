# Review B (skeptical / adversarial): `aa_005a5810` Heightfield_BilinearSample

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a5810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005a5810_Heightfield_BilinearSample.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler signature `(hf, ix, iz)` is complete ABI | Trust Ghidra | **Falsified** — body `RET 0x10`; parent passes **fx, fz** too |
| 2 | `unaff_ESI` / `unaff_EDI` are live register inputs from caller | Decomp unaff_ | **Falsified as ABI** — caller does not leave heights in ESI/EDI; they stand in for **stack floats** |
| 3 | Full 4-corner always-sampled bilinear | Textbook model | **Falsified as always-4** — third corner is path-dependent; diagonal split |
| 4 | Gate is on height magnitude vs 1.0 | Misread comiss | **Falsified** — comiss is on **fx+fz** vs `g_flOne` |
| 5 | This unit scales world XZ / divides height scale | Confuse with parent | **Falsified** — pure cell-local; parent does scale/clamp/÷`+0x34` |
| 6 | Map-level cast / Havok ray | Confuse CastTerrainHeight | **Falsified** — only HF vtbl getter; no world cast |
| 7 | Multiple callers | Inflated surface | **Falsified** — sole caller `0x005a58c0` |
| 8 | Clean scaffold is formula-authoritative | Auto plate | **Falsified** — scaffold copies broken decomp; dual prefers body |
| 9 | Name string-proven | Symbol inflation | **Not sealed** — Probable; parent dual already uses name |
| 10 | Exact lerp algebra is High without ST walk | Overclaim | **Accepted residual** — structure High; closed form **Probable** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-arg thiscall RET 0x10 | **High** | Stack corruption / wrong fracs |
| Diagonal `fx+fz` vs 1.0 | **High** | Wrong triangle / seams |
| vtbl+0x30 corner get | **High** | Wrong height source |
| Sole parent SampleY | **High** | Miss dual surface |
| Closed-form coefficients | **Probable** | Off-by-frac terrain Y |
| Product name | **Low–Med** | Naming only |

---

## 3. Cross-check against raw

```text
// raw decompile shows unaff_* — NOT authoritative for ABI
// body:
GetH = hf->vtbl[+0x30]
h10 = GetH(ix+1, iz)
h01 = GetH(ix, iz+1)
if (fx + fz > 1.0f) { /* upper: sample h11; blend; ret 0x10 */ }
else                { /* lower: sample h00; blend; ret 0x10 */ }
```

Parent raw `aa_005a58c0`:

```text
FUN_005a5810(cellX, cellZ, gx-cellX, gz-cellZ)  // thiscall ECX=hf
return st0 / *(hf+0x34)
```

---

## 4. Surviving contract for AutoCore

```
Heightfield_BilinearSample(hf, ix, iz, fx, fz) -> rawY:
  // diagonal-split bilinear on HF grid via vtbl+0x30
  // RET 0x10

// NOT responsible for:
//   world scale (+0x30/+0x38)
//   cell clamp to dim-2
//   height scale divide (+0x34)
// Those live in Heightfield_SampleY (0x005a58c0).
```

**Port tests:**

* Stack must pop 16 bytes of args.
* Seam along `fx+fz=1` must match diagonal split (not full 4-corner grid bilinear unless proven equivalent).
* Do not trust scaffold clean FPU until algebra sealed.
* Must not call map cast / Havok.

---

## 5. Open questions

1. Algebraic reduction of both FPU paths to textbook formulas.
2. vtbl+0x30 signature (int,int) vs float promotion.
3. Rewrite clean cpp to body-authoritative form.
4. Runtime golden samples.

**Verdict:** **accept-with-gaps** — attacks that trust decomp arity or merge parent scale logic **fail**; exact lerp algebra remains the main residual.
