# Review B (skeptical / adversarial): `aa_0093d110` Inv_Client_ReverseEngineerItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0093d110_Inv_Client_ReverseEngineerItem.md` |
| **Verdict** | **accept-with-gaps**; wire open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server destroys item alone | Falsified — client path |
| 2 | No item type gates | Falsified — type/flag checks |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Item flag/type gates | High | RE illegal items |
| C2S residual | Tentative | Wrong opcode |

---

## 3. Cross-check against raw

```
on selected item: flag/type gates; UI helpers; request RE.
Clean ≡ raw CF; opcode residual.
```

---

## 4. Surviving contract for AutoCore

```
ReverseEngineerItem(selected):
  client RE initiate
  pair OnReverseEngineerFailure toasts
  AutoCore: server must re-validate
```

---

## 5. Open questions

1. Seal RE C2S opcode/payload.
2. Flag catalog.

**Verdict:** **accept-with-gaps**; wire open
