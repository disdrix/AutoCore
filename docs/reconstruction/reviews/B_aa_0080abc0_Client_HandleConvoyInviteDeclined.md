# Review B (skeptical / adversarial): `Client_HandleConvoyInviteDeclined` @ `0x0080abc0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080abc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080abc0_Client_HandleConvoyInviteDeclined.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Accepts invite on this path | Falsified — declined path |
| 2 | Server convoy authority | Falsified — client toast |
| 3 | No reason discrimination | Falsified — multi-string map |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client toast only | High | None if wrong string |
| Reason enum coverage | High | Generic/wrong decline text |
| packet+0x14 reason | Tentative | Wrong field |

---

## 3. Cross-check against raw

```
HandleConvoyInviteDeclined:
  reason code → localized decline toast;
  no roster change.
```

---

## 4. Surviving contract for AutoCore

```
HandleConvoyInviteDeclined(reason):
  UX only; server already rejected invite.
```

---

## 5. Open questions

1. Seal opcode + reason enum table.

**Verdict:** **accept-with-gaps**
