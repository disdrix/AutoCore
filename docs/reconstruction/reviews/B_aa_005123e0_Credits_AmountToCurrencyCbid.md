# Review B (skeptical / adversarial): `aa_005123e0` Credits_AmountToCurrencyCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005123e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005123e0_Credits_AmountToCurrencyCbid.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | General item rarity mapper | Sole xref from credits spawn `004d2750` | **Falsified** as general rarity |
| 2 | Returns amount itself | Returns DAT_* or −1 only | **Falsified** |
| 3 | Thresholds are powers of 2 | 999 / 999999 / 999999999 exact | **Falsified** as 2^n |
| 4 | Static CBIDs in EXE | Image shows −1; writers at 005127xx | **Survives** as runtime-filled |
| 5 | hi treated as unsigned always | Outer checks `hi < 0` / `hi > 0` | **Survives** signed hi |

---

## 2. Cross-check ladder

```
amount == 0            → -1
1 .. 999               → DAT_00af1b50
1000 .. 999999         → DAT_00af1b54
1e6 .. 999999999       → DAT_00af1b58
≥1e9 or hi>0 (large)   → DAT_00af1b5c
hi < 0                 → -1
```

Decompiler nesting is ugly but equivalent to this cascade (largest threshold first).

---

## 3. Surviving contract

```
cbid = Credits_AmountToCurrencyCbid(lo, hi)
// used only to GiveItemByCbid for world credit drops
```

**Open:** exact CBID constants after init.

**Verdict:** **accept-with-gaps**.
