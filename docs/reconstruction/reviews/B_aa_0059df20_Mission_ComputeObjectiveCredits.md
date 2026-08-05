# Review B (skeptical / adversarial): `aa_0059df20` Mission_ComputeObjectiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059df20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23`; residual refresh `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0059df20_Mission_ComputeObjectiveCredits.md` |
| **Verdict** | **accept-with-gaps** on CF formula; runtime/table dump open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Writes char+0x720 itself | Body has no store | **Falsified** — returns delta only |
| 2 | Null-checks mission like XP | Body loads `*(obj+0x14c)+0x11c` unchecked | **Falsified** — no check |
| 3 | Called on every objective advance | Advance branch never calls | **Falsified** — FINAL grant only |
| 4 | Ensure* names are invents | Ghidra callees + dedicated units at 0x00512870/0x00512830 | **Sealed High** |
| 5 | ROUND is nearest-int library | Image: FNSTCW; OR AH,0x0C; FISTP after ceil | **Falsified as nearest**; sealed as chop FISTP |
| 6 | Map payload type mixup | Base `(float)*(int*)+0x10`; frac `*(float*)+0x10` | **High** both |
| 7 | Null mission unreachable | CompleteObjective guards; toast can call with null mission | **Partial** — body fault; primary path safe |
| 8 | Negative scaler undefined | ceil+FISTP can yield negative; caller ADDs with sign-extend carry | **Documented High** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula ceil(scaler*frac*base) | High | Wrong credit payout |
| Keys 0x11c / 0x13e / 0x148 | High | Wrong tables |
| Miss → 0 | High | NaN/crash path |
| Map row+0x10 types | **High** | residual: int base vs float frac sealed by loaders |
| Ensure* VAs | **High** | residual sealed |
| ROUND/FISTP | **High** | residual sealed |

---

## 3. Cross-check against raw

```
load base map[TargetLevel]; load frac[CreditsIndex]; return FISTP_chop(ceil(scaler*frac*base)) or 0.
Clean ≡ raw CF. Image ROUND = RC=chop convert, not FRNDINT nearest.
```

---

## 4. Surviving contract for AutoCore

```
ComputeObjectiveCredits(obj) → int delta:
  caller adds to char+0x720 on FINAL complete only
  pair ComputeObjectiveXp + CompleteObjective
  AutoCore must match tables + ceil for positive products
  Negative scaler: client can go negative; server port may clamp 0
```

---

## 5. Residual disposition

| Prior gap | Disposition |
|-----------|-------------|
| Ensure* loader names | **Sealed High** @ `0x00512870` / `0x00512830` |
| Map node beyond +0x10 | **Sealed High** key+0x0C / value+0x10 / flag+0x15 |
| ROUND exactness | **Sealed High** FISTP RC=chop after ceil |
| Null mission | **Sealed** body fault; CompleteObjective safe; toast theoretical |
| Negative scaler | **Documented** client vs AutoCore clamp |
| Table full-row bit-exact | Still open |
| Runtime / live compare | Still open |

**Verdict:** **accept-with-gaps** — CF formula dual residual closed; verification/runtime remain.
