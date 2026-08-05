# Review B (skeptical / adversarial): `aa_005214b0` Character_SetDword_plusCf8_Dirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005214b0` |
| **VA** | `0x005214b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005214b0_Character_SetDword_plusCf8_Dirty_Inferred.md` |
| **Evidence** | Live decompile; twin comparison |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same destination as `0x00521480` | **Falsified** | `+0xcf8` vs `+0xcf4` |
| 2 | Change-detect early out | **Falsified** | always writes |
| 3 | Different net mask than twin | **Falsified** | same `0x20000000` |
| 4 | No local `+0x634` dirty | **Falsified** | `|= 1` present |
| 5 | Product field identified | **Open** | residual |
| 6 | Clean invents behavior | **Falsified** | ≡ raw |

---

## 2. Surviving contract

```
Character_SetDword_plusCf8(self, v):
  *(u32*)(self+0x634) |= 1
  *(u32*)(self+0xcf8) = v
  if charNet: NetObject_SetMaskBits(charNet, 0x20000000, 0)
```

**Verdict:** **accept-with-gaps**
