# Review B (skeptical / adversarial): `aa_009729d0` Math_Mat4TransformDirection3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009729d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009729d0_Math_Mat4TransformDirection3_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as TransformPoint3 | Seeds **w=0** not 1; no perspective divide | **Falsified** merge |
| 2 | Includes translation always | Affine callee path for w≈0 is linear-only | **Falsified** |
| 3 | Normalizes result | No call to `0076f5f0`; callers normalize before | **Falsified** |
| 4 | Matrix is stack formal | Decomp only shows vec*; ESI convention from family | **Survives** as reg matrix |
| 5 | Writes out.w | Only xyz stored back | **Falsified** |

---

## 2. Live ≡ raw

Live ≡ raw: load 3 floats, `local_14 = 0`, `FUN_0076f240`, store 3 floats. Unproject dual independently labels this TransformDirection after Normalize. Point sibling `0076f6e0` is the w=1 counterpart.

---

## 3. Surviving contract

```
// ESI = m[16], dir = float[3] in/out
// tmp = {dir.x, dir.y, dir.z, 0}
// tmp = Mat4MulVec4_AffineFast(m, tmp)  // no translation when affine
// dir.xyz = tmp.xyz
```

**Gaps kept:** product name; full clobber list; runtime.

**Verdict:** **accept-with-gaps**.
