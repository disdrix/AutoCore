# Review B (skeptical / adversarial): `Client_ShowEquipFailureMessage` @ `0x00931db0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00931db0_Client_ShowEquipFailureMessage.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Single generic equip fail | Falsified — large switch |
| 2 | Equips on case 0 only | Weak — cases 0/3 shared empty path |
| 3 | Server validates here | Falsified — client messages |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reason→string map | High | Wrong equip feedback |
| Client UX only | High | Does not fix equip |

---

## 3. Cross-check against raw

```
ShowEquipFailureMessage(reason):
  switch reason → town/unidentified/weight/tech/space/... toasts.
```

---

## 4. Surviving contract for AutoCore

```
ShowEquipFailureMessage:
  client equip error UX; pairs ConfirmEquipOrCustomizeItem.
```

---

## 5. Open questions

1. Full enum table for AutoCore fail codes parity.

**Verdict:** **accept-with-gaps**
