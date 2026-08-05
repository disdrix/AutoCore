# Review B (skeptical / adversarial): `Client_WriteJoyCustomIni` @ `0x0081e700`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0081e700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0081e700_Client_WriteJoyCustomIni.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reads player input | Falsified — writes INI template |
| 2 | Server keybinds | Falsified — client joy_custom.ini |
| 3 | Only stick axes no QB | Falsified — QB keys included |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Template includes Drive+QB | High | Missing binds for joy users |
| Write-only helper | High | None if unused |

---

## 3. Cross-check against raw

```
WriteJoyCustomIni:
  fopen joy_custom.ini; fputs Drive/QB template; fclose.
  error if open fails.
```

---

## 4. Surviving contract for AutoCore

```
WriteJoyCustomIni:
  client joystick config template;
  pairs ActionMap_Init / InitDefaultKeybinds.
```

---

## 5. Open questions

1. Confirm overwrite policy.

**Verdict:** **accept**
