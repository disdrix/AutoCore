# Review B (skeptical / adversarial): `Client_OnAuthDisconnected` @ `0x008221e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008221e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_008221e0_Client_OnAuthDisconnected.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Retries auth automatically here | Falsified — surfaces failure |
| 2 | Sector packet handler | Falsified — auth disconnect |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client auth disconnect UX | High | Silent disconnect |

---

## 3. Cross-check against raw

```
OnAuthDisconnected: show login-failure UX; client only.
```

---

## 4. Surviving contract for AutoCore

```
OnAuthDisconnected: auth client path; not AutoCore server.
```

---

## 5. Open questions

1. Call graph vs ShowLoginFailureDialog.

**Verdict:** **accept**
