# Review B (skeptical / adversarial): `aa_0040d450` Math_FloatNearlyEqual_AbsRel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W25-T) |
| **Counterpart** | `reviews/A_aa_0040d450_Math_FloatNearlyEqual_AbsRel.md` |
| **Scratch** | `tmp/a_0040d450.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only an absolute epsilon test | **Falsified** — relative path multiplies maxAbs by param_3 after abs fail |
| 2 | param_3 is absolute and param_4 is relative | **Falsified** — param_4 gates first as absTol; param_3 scales maxAbs |
| 3 | thiscall / ECX object | **Falsified** — leaf float formals only; `PUSH/POP ECX` is scratch, not this |
| 4 | Returns float / void | **Falsified** — `XOR EAX,EAX` / `MOV EAX,1` then RET |
| 5 | max is min or sum | **Falsified** — pointer selects larger of \|a\|,\|b\| |
| 6 | Product name is retail string | **Overstated** — no string xref; name inferred from role |
| 7 | SSE mul means non-IEEE edge cases differ from pure x87 | **Open residual** — CF still sealed; runtime CW not proven |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual abs+rel CF | **High** | Wrong equality gates in quat/vec |
| Formal order (a,b,rel,abs) | **High** | Swapped tolerances (caller eps same both mitigates) |
| cdecl EAX bool | **High** | ABI break |
| Leaf | **High** | Missed side effects |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX
diff = a - b
if absTol < |diff|:
  maxAbs = max(|a|,|b|)
  if maxAbs * relTol < |diff|: EAX=0; POP ECX; RET
EAX=1; POP ECX; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Callers pass matching (rel,abs) pairs (often identical eps ~1e-6).

---

## 4. Surviving contract for AutoCore

```
// Prefer this dual-gate over pure |a-b|<eps when porting client math parity:
near = Math_FloatNearlyEqual_AbsRel(a, b, relTol, absTol)
// true if |a-b|<=absTol OR |a-b|<=max(|a|,|b|)*relTol
// quat normalize skip uses ~1e-6 for both tols against lenSq vs 1.0f
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/semantics sealed; product name residual only → **accept**.
