# Review B (skeptical / adversarial): `aa_0086d020` Mission_Client_ClaimSelectedReward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086d020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0086d020_Mission_Client_ClaimSelectedReward.md` |
| **Verdict** | **accept-with-gaps** on CF; wire residual |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Claims without selection | Falsified — select-first toast |
| 2 | No network send | Falsified — SendSectorPacket |
| 3 | Sealed 0x20c6 schema | Overstated — seed only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Select gate + toast | High | Claim empty reward |
| 0x20c6 claim opcode | High | Wrong C2S |
| +0x510 selection state | High | Stale claim |
| GiveItem timing | Tentative | Desync loot |

---

## 3. Cross-check against raw

```
switch UI msg; if accept without selection toast; else pack 0x20c6 + send; optional GiveItem.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
ClaimSelectedReward(panel, msg, id):
  client must select reward; sends sector claim
  AutoCore: implement C2S claim + server grant authority
  pair CompleteObjective reward UI
```

---

## 5. Open questions

1. Seal 0x20c6 payload fields.
2. Confirm local GiveItem vs ack-only.

**Verdict:** **accept-with-gaps** on CF; wire residual
