# Review B (skeptical / adversarial): `aa_00508a00` Item_RollScaledRandomFloat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508a00` |
| **VA** | `0x00508a00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00508a00_Item_RollScaledRandomFloat_Inferred.md` |
| **Evidence** | Live decompile + sealed floats + sole caller `00509c70` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always multiplies by fresh unit random | When `param_4 != 0`, multiplies by `param_4` only (no unit draw in magnitude path) | **Falsified always-random** |
| 2 | Always sign-flips | Requires `param_3 != 0` **and** u&lt;0.5 | **Falsified** |
| 3 | Threshold is 0.5 using wrong constant | `DAT_00a0f298 = 0.5f` sealed | **Sealed** |
| 4 | Floor uses 0 / epsilon invent | `DAT_00a0f718 ≈ 0.01f` sealed | **Sealed** |
| 5 | This selects quality tier (−1/0/+1) | That logic lives in `00509c70` head; this is float writer helper | **Falsified conflation** |
| 6 | Multiple independent callers | Live: only `00509c70` | **Confirmed sole** |
| 7 | Clean modernizes RNG | Scaffold ≡ live | **Falsified** |
| 8 | `ret 0x10` is wrong (cdecl no clean) | Epilogue `c2 10 00` | **Falsified** |
| 9 | Sign flip uses second independent stream incorrectly | Body re-gets unit scalar after magnitude; advances cursor | **Survives** as written |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual magnitude path (random vs fixed) | **Confirmed** | Affix ranges wrong |
| Sign-flip polarity / 50% | **Confirmed** | Symmetric bonus/malus bias |
| Dead-zone 0.01 | **Confirmed** | Noise stats survive as tiny floats |
| `param_2` seed English | **Low–Med** | Determinism story |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
f = (unitOrZero == 0.f) ? scale * UnitRandom01(streamHint)
                        : scale * unitOrZero;
if (allowSignFlip && UnitRandom01() < 0.5f) f = -f;
if (fabsf(f) < 0.01f) f = 0.f;
return f;
// NOT quality-tier logic; NOT broken-roll
```

Port rule: keep the **param_4==0** branch distinct from fixed multiply; keep sign flip behind the char flag.

---

## 4. Cross-check vs `00509c70`

Caller dual already lists this as “scale×random float helper” for type cases (armor floats, etc.). Do not invent extra quality math here. `param_3`/`param_5` seed residual on the **caller** still applies to how `param_2`/`param_4` are filled before the call.

---

## 5. Open questions

1. Whether `FUN_007a4170` is pure [0,1) from the same table as the sign-flip u16 path.
2. Call-site mapping of `allow_sign_flip` per type-case (which stats are bipolar).
3. Runtime.

**Verdict:** **accept-with-gaps** — adversarial pass keeps scaled-float CF; seed formal residual only.
