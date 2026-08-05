# Review B (skeptical / adversarial): `aa_00826720` Client_SendQuickBarUpdateFromUi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00826720_Client_SendQuickBarUpdateFromUi.md` |
| **Verdict** | **accept-with-gaps** on CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses absolute slot formal arg | **Falsified — derives from UI page/column** |
| 2 | isItem true for skills | **Falsified — skill kind==1 → isItem 0** |
| 3 | Standard __fastcall only | **Weak — ESI UI** |
| 4 | Awaits ack before UI update | **Falsified as body claim — send only** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x2062 size 0x10 | High | Wrong wire |
| page*10+col | High | Wrong bar slot |
| isItem polarity | High | Skill/item swap |
| ESI binding | Tentative | Wrong UI object |

---

## 3. Cross-check against raw

```
if payload:
  slot = page*10+col; isItem=(kind!=1); pack 0x2062; send 0x10 via DAT sector net
Clean matches plate RE.
```

---

## 4. Surviving contract for AutoCore

```
On QuickBar UI assign:
  C2S 0x2062 with slot=page*10+column, isItem=(kind!=skill), int64 value
  optimistic; login restore via CreateCharacterExtended
Keep wire layout identical to WithSlot sibling.
```

---

## 5. Open questions

1. Pad field hygiene on wire.
2. Server apply path.
3. Runtime QB drag capture.

**Verdict:** **accept-with-gaps** on CF
