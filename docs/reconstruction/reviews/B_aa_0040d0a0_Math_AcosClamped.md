# Review B (skeptical / adversarial): `aa_0040d0a0` Math_AcosClamped

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d0a0_Math_AcosClamped.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always calls `_CIacos` (clamp-then-acos) | Port as `acos(clamp(x,-1,1))` | **Partial falsify** — exterior **never** calls `_CIacos`; endpoints are **hardcoded 0/π**. Equivalent on `[-1,1]` for finite inputs; differs only if CRT acos domain handling mattered for `|x|>1` |
| 2 | Returns degrees | UI/tooltip association | **Falsified** — π constant + `_CIacos` = **radians** |
| 3 | Is `asin` / `atan2` | Angle-family confusion | **Falsified** — sole callee `_CIacos`; no y-component |
| 4 | Saturates both sides to 0 | Symmetric clamp mistake | **Falsified** — positive → **0**, non-positive → **π** |
| 5 | Threshold is soft epsilon (e.g. 1−ε) | Numerical overfit | **Falsified** — exact `g_flOne` (1.0) compare via `FCOMIP` |
| 6 | `DAT_00a27c3c` is 180.0 or τ | Constant misread | **Falsified** — bytes `db 0f 49 40` = **π** |
| 7 | `__stdcall` / thiscall / XMM return | ABI overfit | **Falsified** — stack float in, **ST0** out, plain `ret` |
| 8 | Sole caller is turret aiming | Scaffold name | **Falsified** — **10** caller functions / **17** sites |
| 9 | Mutates caller memory beyond arg | Side-effect fear | **Mostly falsified** — rewrites only own `[esp+4]` arg slot on saturate path before reload (caller stack slot may be clobbered if it alias-shared; typical leaf pattern) |
| 10 | Name `Math_AcosClamped` is PDB-proven | Symbol inflation | **Not sealed** — **inferred** from CF; Ghidra still `FUN_0040d0a0` |
| 11 | Identical DAT site as upright π (`DAT_009d54a4`) | Constant aliasing | **Falsified as same address** — same **value class** (π), different VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Domain gate `\|x\| ≥ 1` vs interior | **High** | NaN / domain error if always-acos port |
| Endpoint polarity (pos→0, else→π) | **High** | Anti-aligned angles flip (π vs 0) |
| Radians not degrees | **High** | 57× scale bug in consumers |
| `g_flOne` / π byte values | **Confirmed** | Wrong table constants |
| `_CIacos` @ `0x006a3e26` | **High** | Wrong CRT entry |
| Caller list completeness (17) | **High** (addrs) | Miss multi-site UI/camera uses |
| Product function name | **Low–Med** | Doc only |
| NaN / −0 behavior | **Low** | Rare edge divergence |
| Equivalence to `acos(clamp(x,-1,1))` | **High** for finite `x` | Port style only |

---

## 3. Cross-check against raw

```text
// raw aa_0040d0a0 ≡ live decompile 2026-07-29
if (g_flOne <= ABS(x)) {          // |x| >= 1
    r = 0.0f;
    if (x <= 0.0f)
        r = DAT_00a27c3c;         // π
    return r;
}
return _CIacos(x);
```

Assembly polarity of the `|x| < 1` jump:

* After `FABS` / load 1.0 / `FXCH`: `FCOMIP` compares **`|x|` to `1.0`**.
* `JC 0040d0d5` when CF set ⇒ **`|x| < 1`** ⇒ interior `_CIacos`.
* Fall-through ⇒ **`|x| ≥ 1`** ⇒ 0/π.

Matches decompiler `if (g_flOne <= ABS(param_1))` saturate block.

---

## 4. Surviving contract for AutoCore

```
Math_AcosClamped(x) -> radians in ST0:
  if |x| < 1.0:
      return _CIacos(x)            // CRT acos
  else:
      return (x > 0.0) ? 0.0 : PI  // PI = *(float*)0x00a27c3c
                                   // 1.0 threshold = g_flOne @ 0x00a0f2a0

// NOT: asin, atan2, degrees
// NOT: always call acos(clamp(...))  — retail early-outs exterior
// Callers: turret aim, orientation helpers, UI tooltip, camera residual, …
```

**Port tests that matter:**

* `+1` → `0`; `-1` → `π`; `0` → `π/2` (via `_CIacos`).
* `+2` → `0` (not NaN); `-2` → `π` (not NaN).
* Must **not** scale by `180/π`.
* Must use **π** not `180` for the negative saturated endpoint.
* Optional micro-opt: skip CRT call when `|x| ≥ 1` (matches retail).

---

## 5. Open questions

1. Product symbol / compiler intrinsic name if any PDB ever surfaces.
2. Whether `_CIacos` itself clamps (irrelevant when this helper early-outs).
3. Per-caller: is `x` a unit-dot product (expected) or sometimes unnormalized (would hit saturate often)?
4. Runtime CE probe of NaN input path (policy-open).

**Verdict:** **accept-with-gaps** — adversarial attacks on degrees/asin/symmetric-zero/sole-caller **fail**; remaining gaps are product name, NaN edges, and caller-side formula duals (out of this VA).
