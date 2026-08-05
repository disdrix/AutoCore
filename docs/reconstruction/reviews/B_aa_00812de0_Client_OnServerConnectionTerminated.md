# Review B (skeptical / adversarial): `Client_OnServerConnectionTerminated` @ `0x00812de0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00812de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00812de0_Client_OnServerConnectionTerminated.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Auto-reconnect here | Falsified — login return |
| 2 | Silent crash | Falsified — dialog |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Terminated → login UX | High | Stuck world UI |

---

## 3. Cross-check against raw

```
OnServerConnectionTerminated: dialog; Accept→login.
```

---

## 4. Surviving contract for AutoCore

```
OnServerConnectionTerminated: client disconnect UX.
```

---

## 5. Open questions

1. Dispatch conditions vs force-quit.

**Verdict:** **accept**
