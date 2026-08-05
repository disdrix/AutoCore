# Review B (skeptical / adversarial): `aa_004d2820` CVOGSectorMap_PlaceWorldObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d2820_CVOGSectorMap_PlaceWorldObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Creates item from CBID | No GiveItemByCbid; takes existing `obj*` | **Falsified** as factory |
| 2 | Always assigns new COID | Only when both COID dwords are −1 | **Falsified** as always |
| 3 | Bag insert | DropObjectOnGround only | **Falsified** |
| 4 | `(a&b)==−1` means either is −1 | Requires **both** all-ones | **Survives** both-unset |
| 5 | Identical to `004d2750` | No amount→CBID; no factory | **Falsified** as same |

---

## 2. Live ≡ raw

```
vtbl+0x218(map)
if COID unset: counter++, SetCoidIdentity, vtbl+0x2a4
DropObjectOnGround(...)
related = vtbl+0x1d4(); if related: related[+0x2ac]=1
```

Matches clean + multiple place call sites (loot radius 5 / special radius 1).

---

## 3. Surviving contract

```
PlaceWorldObject(map, obj, pos/radius/flag...):
  register with map; ensure COID; drop; tag related+0x2ac
```

**Verdict:** **accept-with-gaps**.
