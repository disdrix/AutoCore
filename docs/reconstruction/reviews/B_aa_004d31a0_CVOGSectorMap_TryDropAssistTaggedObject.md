# Review B (skeptical / adversarial): `aa_004d31a0` CVOGSectorMap_TryDropAssistTaggedObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d31a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d31a0_CVOGSectorMap_TryDropAssistTaggedObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Awards XP directly | No CalculateAndAward; only create/place | **Falsified** as XP award |
| 2 | Always drops | Unit RNG vs `this+0x30` | **Falsified** as always |
| 3 | Uses GiveItemByCbid loot | Uses `FUN_004cf120(0x21a3,…)` | **Falsified** as item CBID loot |
| 4 | Name “assist tag” plate-proven | No plate string in body | **Contested** — parent dual only |
| 5 | Single participant | Requires both A and B pass vtbl+0x210 | **Survives** dual gate |

---

## 2. Live ≡ raw

```
if A.ok && B && B.ok:
  if rand_unit < this[+0x30]:
    o = create(0x21a3)
    copy pose; PlaceWorldObject(o, pos, 1.0, 1)
```

Matches decompile; name remains **inferred**.

---

## 3. Surviving contract

```
// kill side-effect: chance spawn type-0x21a3 world object near participants
TryDropAssistTaggedObject(host, A, B)
```

**Open:** true product identity of 0x21a3.

**Verdict:** **accept-with-gaps**.
