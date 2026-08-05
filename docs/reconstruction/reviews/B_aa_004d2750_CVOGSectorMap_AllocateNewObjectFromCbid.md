# Review B (skeptical / adversarial): `aa_004d2750` CVOGSectorMap_AllocateNewObjectFromCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d2750_CVOGSectorMap_AllocateNewObjectFromCbid.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Takes raw CBID as first arg | First map is amount→CBID via `005123e0` | **Falsified** as direct CBID arg |
| 2 | Inserts into player bag | Ends in `DropObjectOnGround` | **Falsified** as bag grant |
| 3 | Silent fail on null factory | Logs plate string with cbid | **Falsified** silent |
| 4 | Always writes amount fields | Only when vtbl+8 returns 0 | **Survives** gated write |
| 5 | Unique COID without map counter | Uses `map+0xe6e0` 64-bit post-inc | **Falsified** |

---

## 2. Live ≡ raw

```
cbid = AmountToCurrencyCbid(lo,hi)
item = GiveItemByCbid(cbid)
if !item: log fail; return
init vtbl+8; maybe stamp amount/extras
alloc COID; SetCoidIdentity; vtbl+0x2a4; DropObjectOnGround
```

Matches scaffold + parent “credits floaters” note.

---

## 3. Surviving contract

```
// map-local: amount → currency object in world
AllocateNewObjectFromCbid(map, amountLo, amountHi, extraA, extraB)
```

**Not** a bag grant; **not** a direct-CBID factory (amount-tiered).

**Verdict:** **accept-with-gaps**.
