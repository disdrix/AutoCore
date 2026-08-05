# Review B (skeptical / adversarial): `aa_004c97b0` Experience_GetCreatureXpForLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c97b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c97b0_Experience_GetCreatureXpForLevel.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns 0x7FFFFFFF on miss | Falsified — that is GetCumulativeThreshold |
| 2 | Applies grey kill slope | Falsified — pure table lookup |
| 3 | Writes experience onto character | Falsified — read-only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x10 field = base XP | High | Wrong kill base |
| Missing → 0 | High | False zero awards |
| Map root / loader pairing | Medium | Table never loads |

---

## 3. Cross-check against raw

```
GetCreatureXpForLevel(level):
  if !ready: EnsureCreatureXpTableLoaded
  it = lower_bound(map DAT_00b04270, level)
  if !ready: Ensure again
  return (it!=end) ? *(it+0x10) : 0
Clean ≡ raw CF; residual unaff/extraout.
```

---

## 4. Surviving contract for AutoCore

```
Creature-level base XP for kill grey/hard path.
  AutoCore must load tCreatureExperienceLevel and expose same +0x10 lookup.
```

---

## 5. Open questions

1. Dump retail table samples vs docs/XP.md rows.
2. Wire Ensure loader to set g_nCreatureXpTableReady.

**Verdict:** **accept-with-gaps**
