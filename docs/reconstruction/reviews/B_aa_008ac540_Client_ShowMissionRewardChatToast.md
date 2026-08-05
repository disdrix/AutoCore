# Review B (skeptical / adversarial): `Client_ShowMissionRewardChatToast` @ `0x008ac540`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008ac540_Client_ShowMissionRewardChatToast.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grants XP to character here | Falsified — toast display; grant elsewhere |
| 2 | Uses completed hash +0x540 only | Falsified — +0x538 already-received check |
| 3 | Ignores mission id -1 | Partial — plate says must not be -1 for completed path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x538 already-received | High | Duplicate toast |
| ComputeObjectiveXp numbers | High | Wrong reward text |
| Scaler FUN_0051f510 | Medium | Mismatched UI XP |
| Grant vs toast split | High | Double-count if confused |

---

## 3. Cross-check against raw

```
lookup mission; if already received: alt toast; else compute XP/credits; show chat toast.
```

---

## 4. Surviving contract for AutoCore

```
ShowMissionRewardChatToast(obj/mission context):
  display-only reward numbers
  already-received via char+0x538
  do not use as server grant path
```

---

## 5. Open questions

1. Seal toast format strings.
2. Link to CompleteObjective / RecvCompleteDynamicObjective.

**Verdict:** **accept-with-gaps**
