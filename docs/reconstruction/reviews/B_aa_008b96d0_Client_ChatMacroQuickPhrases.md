# Review B (skeptical / adversarial): `Client_ChatMacroQuickPhrases` @ `0x008b96d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b96d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008b96d0_Client_ChatMacroQuickPhrases.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Executes skills on phrase select | Falsified — chat/UI phrases |
| 2 | Server-side macro defs only | Falsified — client string table |
| 3 | No combat relevance | Weak — cooldown/power/repair callouts |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Phrase strings | High | Wrong UX copy |
| Chat send path | Tentative | Macros silent |
| Slot count | Medium | Truncated list |

---

## 3. Cross-check against raw

```
ChatMacroQuickPhrases:
  fill/register quick-phrase UI including combat callouts + convoy phrases;
  client social UI.
```

---

## 4. Surviving contract for AutoCore

```
ChatMacroQuickPhrases:
  client chat macros; not skill train / not cast.
  Useful only for UX parity / string fidelity.
```

---

## 5. Open questions

1. Wire selected phrase → chat C2S opcode.
2. Count of macro slots vs retail UI.

**Verdict:** **accept-with-gaps**
