# Review B (skeptical / adversarial): `aa_006a3db0` Math_X87_RoundToInt64_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006a3db0_Math_X87_RoundToInt64_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Plain C `float` formal | Decomp `in_ST0`; no stack load of arg | **Falsified** (FPU in) |
| 2 | Truncate toward zero only | ROUND + residual ±1 adjust | **Falsified** pure trunc |
| 3 | Same as CRT `ftol` VA | Separate game helper; many direct xrefs | **Survives** as distinct |
| 4 | Always returns short | Return is 64-bit; callers cast | **Survives** as int64 leaf |
| 5 | Domain/XP formula lives here | Pure numeric; formulas in callers | **Falsified** domain claim |

---

## 2. Live ≡ raw

Live ≡ raw ROUND/zero-gate/sign arms/`0x80000000` residual test. Entry prologue aligns stack and uses FPU store of ST0. Callers span LevelUp, tac-arc, outpost XP, mesh — all “float on ST0 → integer”.

---

## 3. Surviving contract

```
// ST0 = x
// u = round_to_int64(x)   // FRNDINT family
// if u != 0: maybe ±1 from residual half-bit test
// return u as int64 (EDX:EAX)
```

**Gaps kept:** exact half-case IEEE table; CRT twin proof; product name.

**Verdict:** **accept-with-gaps**.
