# Review B (skeptical / adversarial): `Client_ShowLoginFailureDialog` @ `0x0080c3c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080c3c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080c3c0_Client_ShowLoginFailureDialog.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Succeeds login | Falsified — failure dialog |
| 2 | Specific reason always | Weak — generic message |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Generic login fail UX | High | Silent fail |

---

## 3. Cross-check against raw

```
ShowLoginFailureDialog: generic failed-to-login dialog.
```

---

## 4. Surviving contract for AutoCore

```
ShowLoginFailureDialog: client auth UX; pairs OnAuthDisconnected.
```

---

## 5. Open questions

1. Whether always generic vs reason-coded elsewhere.

**Verdict:** **accept**
