# Review B (skeptical / adversarial): `aa_00650f90` CVOGHBMissionPatrol_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00650f90_CVOGHBMissionPatrol_Tick.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on +0xc54 semantics |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always completes patrol | **Falsified — TFID match gate** |
| 2 | No party path | **Falsified — loop <4** |
| 3 | Finished distance formula | **Overstated — may be siblings** |
| 4 | Definitely pure XP grant | **Overstated — +0xc54 family ambiguous here** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID match | High | Never progress / wrong char |
| +0xc54 write | Tentative | Corrupt scalar |
| Party size 4 | Tentative | Miss 5th |

---

## 3. Cross-check against raw

```
cast owner Character; mission=+0xcb0;
if local or party TFID match: vtbl+0x50; optional +0xc54 blend
else vtbl+0x18(1,1);
FUN_00578b30.
Clean ≡ raw CF; semantics partial.
```

---

## 4. Surviving contract for AutoCore

```
MissionPatrol_Tick:
  HB for patrol objective progress on matching character/party
  do not treat as generic combat regen
  pair with ObjectiveRequirementPatrol + Client_LocalDiscoveryTick
  Fn3/Fn6 siblings may own distance gates — review together
```

---

## 5. Open questions

1. Dual A/B Fn3/Fn6 if missing.
2. Seal +0xc54 meaning in this path vs AddExperience personal scalar.
3. Live patrol complete packet order.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on +0xc54 semantics
