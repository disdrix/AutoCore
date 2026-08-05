# Review B (skeptical / adversarial): `Client_OnGlobalForceQuitDialog` @ `0x008096c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008096c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008096c0_Client_OnGlobalForceQuitDialog.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Silent process exit only | Falsified — dialog + login return |
| 2 | Allows continue in sector | Falsified — force quit path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Force-quit UX mandatory | High | Stuck client |
| Return to login on Accept | High | Wrong screen |

---

## 3. Cross-check against raw

```
OnGlobalForceQuitDialog:
  show multi-login/GM force-quit dialog;
  Accept → login screen.
```

---

## 4. Surviving contract for AutoCore

```
OnGlobalForceQuitDialog: client global disconnect UX.
```

---

## 5. Open questions

1. Enumerate all force-quit reason strings.

**Verdict:** **accept-with-gaps**
