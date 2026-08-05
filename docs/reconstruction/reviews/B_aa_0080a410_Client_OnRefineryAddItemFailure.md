# Review B (skeptical / adversarial): `Client_OnRefineryAddItemFailure` @ `0x0080a410`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080a410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080a410_Client_OnRefineryAddItemFailure.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Adds item anyway | Falsified — failure path |
| 2 | Server refinery logic | Falsified — client toast |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client toast only | High | Silent fail UX |

---

## 3. Cross-check against raw

```
OnRefineryAddItemFailure: toast refinery add missing object.
```

---

## 4. Surviving contract for AutoCore

```
OnRefineryAddItemFailure: client UX; server already failed.
```

---

## 5. Open questions

1. Opcode for refinery add response.

**Verdict:** **accept**
