# Review B (skeptical / adversarial): `aa_00524680` Character_SetEquippedRaceItemCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524680` |
| **VA** | `0x00524680` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00524680_Character_SetEquippedRaceItemCbid_Inferred.md` |
| **Evidence** | Live decompile + body bytes; callee `0x00522f70` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always calls sync even when equal | **Falsified** | early cmp return |
| 2 | Always dirties net | **Falsified** | `map+0x7e==0` store-only path; vehicle-null path may skip dirty |
| 3 | Always uses mask `0x40000000` | **Falsified** | vehicle path uses `0x1000000` |
| 4 | Sets TFID itself | **Falsified** | only `+0x514`; TFID via sync |
| 5 | Second store is a different field | **Falsified** | same `+0x514` (fallthrough LAB) |
| 6 | Product name sealed | **Open** | Probable only |
| 7 | Clean diverges on mask selection | **Falsified** | ≡ raw ≡ live |

---

## 2. Surviving contract

```
Character_SetEquippedRaceItemCbid(self, cbid):
  if *(self+0x514) == cbid: return
  if map.flag_7e == 0:
    *(self+0x514) = cbid; return
  // else optional dirty (char 0x40000000 or vehicle 0x1000000)
  *(self+0x514) = cbid
  SyncEquippedRaceItemFromCbid(self)
  *(self+0x514) = cbid   // redundant
```

**Verdict:** **accept-with-gaps**
