# Review B (skeptical / adversarial): `Client_OnBadCharacterLoginId` @ `0x009494c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009494c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_009494c0_Client_OnBadCharacterLoginId.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Auto-picks first character | Falsified — reject |
| 2 | Server account create | Falsified — client error UX |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hard reject bad char id | High | Silent fail if missing |

---

## 3. Cross-check against raw

```
OnBadCharacterLoginId: toast bad character ID; abort play.
```

---

## 4. Surviving contract for AutoCore

```
OnBadCharacterLoginId: client login UX error.
```

---

## 5. Open questions

1. Where ID validated before call.

**Verdict:** **accept**
