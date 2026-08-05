# Review B (skeptical / adversarial): `aa_004d5aa0` CVOGObject_EvalOfferableMissionInteractState

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5aa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d5aa0_CVOGObject_EvalOfferableMissionInteractState.md` |
| **Verdict** | **accept-with-gaps** on CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns bool | **Falsified — interact state 0/6/7** |
| 2 | Ignores active missions | **Falsified — branches to active objective eval** |
| 3 | Core always 6 | **Falsified — +0x169 selects 6 vs 7** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| States 6/7 polarity | High | Wrong offer icon |
| CBID/continent match | High | Miss/wrong NPC |
| Completed skip | High | Re-offer completed |

---

## 3. Cross-check against raw

```
lock traverse missions:
  if not completed and CBID+continent match:
    if active: eval active objective state (continue)
    else if requirements==0: return 6/7; unlock
unlock; return cVar4
Clean matches plate.
```

---

## 4. Surviving contract for AutoCore

```
On offerable mission icon:
  match NPC CBID+map; skip completed; active→objective eval; eligible→6/7
Keep lock discipline on mission hash traversal.
Align with HasCompletedMission / CheckMissionRequirements dual reviews.
```

---

## 5. Open questions

1. unaff_EDI meaning.
2. Runtime icon eval capture.

**Verdict:** **accept-with-gaps** on CF
