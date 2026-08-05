# Review B (skeptical / adversarial): `aa_005d6e80` CVOGHBAIDriver_ReturnToNormalLocation

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6e80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d6e80_CVOGHBAIDriver_ReturnToNormalLocation.md` |
| **Verdict** | **accept-with-gaps** on CF; contract High for path-vs-pursue gate |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always pursues target | **Falsified — path preferred; pursue is sibling** |
| 2 | Bool only; no distance | **Falsified — SQRT distance checks** |
| 3 | Ignores combat target flag | **Falsified — bVar7 gates some sets** |
| 4 | Finished exact MapPath ABI | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Path-preferred leash | High | Combat when should patrol |
| Char return for DoLogic gate | High | Wrong pursue vs path |
| Waypoint threshold +0x4c | Tentative | Leash radius wrong |
| COID all-FF sentinel | High | No path ever |

---

## 3. Cross-check against raw

```
scoped entry; bTarget=this[6]+0xa0;
if path COID valid: UpdateState + AdvanceAndSteer / distance gates
else home/clear branches
return char handled.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
ReturnToNormalLocation(driver):
  if map path COID resolves: advance/steer along path (leash)
  else home toward spawn/waypoint; may clear
  return handled → DoLogic skips pure pursue when true
Critical for NPC_DRIVING path combat: pursue only when this returns false.
```

---

## 5. Open questions

1. Seal return polarity in DoLogic idle+combat call sites.
2. Name +0x228/+0x22c COID pair fields.
3. MapPath_AdvanceAndSteer dual A/B if missing.

**Verdict:** **accept-with-gaps** on CF; contract High for path-vs-pursue gate
