# Review B (skeptical / adversarial): `Client_LoadGraphicsIniKeys` @ `0x0095ae10`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0095ae10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0095ae10_Client_LoadGraphicsIniKeys.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Forces mission active always | Falsified — loads option key |
| 2 | Server config | Falsified — client graphics/UI INI |
| 3 | Only camera keys | Falsified — mission/QB keys too |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| SET_NEW_MISSION_ACTIVE exists | High | Missing auto-active option |
| FULL_QUICKBAR_RED visual flag | Medium | UI tint wrong |
| Huge key table complete | Tentative | Missing prefs |

---

## 3. Cross-check against raw

```
LoadGraphicsIniKeys(ctx):
  register graphics/UI INI keys incl. SET_NEW_MISSION_ACTIVE, FULL_QUICKBAR_RED, CINCAM_*;
  client config only.
```

---

## 4. Surviving contract for AutoCore

```
LoadGraphicsIniKeys:
  client option key table; pairs BuildInterfaceOptionsDialog toggles.
```

---

## 5. Open questions

1. Extract full key list for options port.

**Verdict:** **accept-with-gaps**
