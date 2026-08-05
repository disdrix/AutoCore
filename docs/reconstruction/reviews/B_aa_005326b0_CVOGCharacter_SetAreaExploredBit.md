# Review B (skeptical / adversarial): `aa_005326b0` CVOGCharacter_SetAreaExploredBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_005326b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005326b0_CVOGCharacter_SetAreaExploredBit.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unlock insert timing |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always writes bit even if entry missing | **Falsified — unlock then return** |
| 2 | Awards explore XP | **Falsified — no AddExperience** |
| 3 | setBit false deletes continent entry | **Falsified — only clears bit** |
| 4 | Finished exact | **Overstated — list helpers + unlock async** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Missing-entry no-write | High | Lost first discover bit |
| set/clear polarity | High | Stuck fog |
| LogicUI 0x20 | High | Map chrome desync |
| Secondary list match | Tentative | Missed notify |

---

## 3. Cross-check against raw

```
if areaId∉1..32: return;
entry=hash(+0x534,continent);
if !entry: if local: UnlockContinent; return;
setBit? OR : AND~ bit @+0x08;
LogicUI 0x20(areaId);
if local: walk secondary list match continent+area.
Clean ≡ raw; no XP.
```

---

## 4. Surviving contract for AutoCore

```
SetAreaExploredBit(char, continentId, areaId, setBit):
  reject areaId outside 1..32
  if unlock entry missing: local-only UnlockContinentObject; do NOT write bit this call
  else OR/clear ExploredBits; LogicUI type 0x20
  no XP from explore bits (server-driven discovery XP if any is separate)
Pairs with IsAreaExplored / RecvUnlockRegion.
```

---

## 5. Open questions

1. Sync vs async continent unlock insert.
2. FUN_00540060 list semantics.
3. RecvUnlockRegion bit-diff caller contract.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unlock insert timing
