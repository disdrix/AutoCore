# Review B (skeptical / adversarial): `aa_0092ce00` Client_SendInstantRepairRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0092ce00_Client_SendInstantRepairRequest.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on server payload expectations |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sends rich repair struct | **Falsified — 4-byte opcode only** |
| 2 | Always sends | **Falsified — dual gates global + connection** |
| 3 | Connection is DAT sector net | **Weak — uses in_EAX+0xc78 not DAT_00d1b4b8** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Opcode + size 4 | High | Wrong C2S |
| Dual gates | High | Spurious sends |
| Tick stamp side effect | Probable | Cooldown UI wrong |

---

## 3. Cross-check against raw

```
if DAT_00d1b6d8:
  local=0x20b6; if conn@+0xc78: send 4 bytes; stamp tick at global+0x620
Clean matches.
```

---

## 4. Surviving contract for AutoCore

```
On Instant Repair request:
  emit 0x20B6 size 4 when INC/global gate + connection live
  stamp client tick for UI cooldown
Implement AutoCore handler as opcode-only unless server RE shows more fields.
```

---

## 5. Open questions

1. Server InstantRepair handler body.
2. Identity of DAT_00d1b6d8.
3. Runtime click capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on server payload expectations
