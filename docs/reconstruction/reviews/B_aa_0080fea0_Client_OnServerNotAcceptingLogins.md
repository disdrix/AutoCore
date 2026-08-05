# Review B (skeptical / adversarial): `Client_OnServerNotAcceptingLogins` @ `0x0080fea0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080fea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080fea0_Client_OnServerNotAcceptingLogins.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Queues login for later automatically | Falsified — notify UX |
| 2 | Auth success path | Falsified — rejection notify |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client must surface closed server | High | Player confusion |

---

## 3. Cross-check against raw

```
OnServerNotAcceptingLogins: S2C toast server closed to logins.
```

---

## 4. Surviving contract for AutoCore

```
OnServerNotAcceptingLogins: client UX for login closed.
```

---

## 5. Open questions

1. Seal S2C opcode.

**Verdict:** **accept**
