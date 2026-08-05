# Review B (skeptical / adversarial): `aa_0057c4a0` CVOGReaction_ShowScreenText

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057c4a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0057c4a0_CVOGReaction_ShowScreenText.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes mission state | **Falsified** |
| 2 | Opcode not 0x26 | **Falsified** |
| 3 | Same as ShowDialog | **Falsified** |
| 4 | Server broadcast | **Overstated** |
| 5 | Clean drops SendLogicUiPacket | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Packet CF | High | Missing screen text |
| Opcode | High | Wrong UI handler |
| Payload fields | Probable | Wrong text/params |

---

## 3. Cross-check against raw

```
packet.fields from reaction/source +0x160 family
packet.opcode = 0x26
Client_SendLogicUiPacket(packet)
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
ShowScreenText(reaction, source)
  emit Logic UI opcode 0x26 for floating/banner text
  no mission state mutation
```

---

## 5. Open questions

1. Document 0x26 payload in UI system map.
2. Difference vs chat toast helpers.
3. Dispatch case binding.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
