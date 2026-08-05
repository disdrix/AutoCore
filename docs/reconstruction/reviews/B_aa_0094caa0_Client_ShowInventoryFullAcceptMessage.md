# Review B (skeptical / adversarial): `Client_ShowInventoryFullAcceptMessage` @ `0x0094caa0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094caa0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0094caa0_Client_ShowInventoryFullAcceptMessage.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Toast only never sends | Falsified — 0x208f path |
| 2 | Always sends even when full | Falsified — toast return when unfit |
| 3 | Opcode 0x2072 UseObject | Falsified — 0x208f |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x208f accept path | High | Broken loot/offer accept |
| Full → toast no send | High | Server spam if wrong |
| Vehicle required gate | High | Silent no-op on foot? |

---

## 3. Cross-check against raw

```
ShowInventoryFullAcceptMessage:
  if char && ui visible && vehicle:
    if BL && !fit: toast full; return
    else send 0x208f (0x18) with char TFID fields.
```

---

## 4. Surviving contract for AutoCore

```
ShowInventoryFullAcceptMessage:
  dual toast/send for accept-when-full UX;
  verify 0x208f server handler before port.
```

---

## 5. Open questions

1. Name 0x208f in opcode table.
2. Confirm on-foot behavior (vehicle gate).

**Verdict:** **accept-with-gaps**
