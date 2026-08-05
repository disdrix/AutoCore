# Review B (skeptical / adversarial): `aa_0080cac0` Client_RecvGiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080cac0_Client_RecvGiveCredits.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on register contract + suppress flag |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Absolute currency set | **Falsified — AddCredits delta path** |
| 2 | Always plays sound | **Falsified — only amount > 0** |
| 3 | Always enqueues floater | **Falsified — needs vehicle + d6c==0** |
| 4 | Body proves opcode 0x205E | **Falsified as body claim** |
| 5 | Finished exact | **Overstated — register contract + floater blob** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Additive int64 @+8 | High | Wrong money / double-count |
| Positive sound polarity | High | Spam or silence |
| Floater gate +0xd6c | Tentative | Wrong combat feedback |
| ESI/EDI framing | Tentative | Wrong game/packet |

---

## 3. Cross-check against raw

```
if !char@ESI+0xe98: DEBUG_STOP;
AddCredits(char, *(i64*)(EDI+8));
if amount>0: play "credits";
if vehicle@char+0x250:
  optional floater type 4 if char+0xd6c==0;
  refresh money HUD +0x1040.
Clean preserves CF.
```

---

## 4. Surviving contract for AutoCore

```
On S2C GiveCredits (0x205E):
  require local character; ADD signed int64 delta @ packet+8
  positive → credits UI sound
  with vehicle: optional type-4 floater unless char+0xd6c suppress; refresh money HUD
Do NOT also GiveCredits after CompleteObjective if that path already added credits.
Contrast CharacterLevel absolute snapshot.
```

---

## 5. Open questions

1. Seal ESI/EDI vs PacketDispatch arg order.
2. Meaning of char+0xd6c suppress flag.
3. Whether negative amounts suppress sound only or also floater (floater uses lo dword).
4. Runtime mission-reward capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on register contract + suppress flag
