# Review B (skeptical / adversarial): `aa_008a3510` Mission_Client_BuildMissionDetailPanel

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a3510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008a3510_Mission_Client_BuildMissionDetailPanel.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server mission state machine | Falsified — detail panel UI |
| 2 | No convoy option | Falsified — convoy string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Status string mapping | High | Wrong journal |
| Set Active wiring | Tentative | Miss active mission |

---

## 3. Cross-check against raw

```
build detail panel strings/actions from mission row.
Clean ≡ raw CF; large UI residual.
```

---

## 4. Surviving contract for AutoCore

```
BuildMissionDetailPanel(panel, missionRow):
  client journal detail
  pair UpdateMissionJournal + NotifyActiveMissionChanged
```

---

## 5. Open questions

1. Trace Set Active click handler opcode.
2. Reward list bind offsets.

**Verdict:** **accept-with-gaps**
