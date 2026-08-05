# Review B (skeptical / adversarial): `aa_00509680` CVOGLootGenerator_GetTypeFromIDPrefix_00509680

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509680` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00509680_CVOGLootGenerator_GetTypeFromIDPrefix_00509680.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns char* name | Falsified — byte load |
| 2 | Default empty string | Falsified — returns 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte field semantics | High | Wrong flag |
| Map miss → 0 | High | False zero type |

---

## 3. Cross-check against raw

```
Sibling: map type → *(entry+0x10) byte; default 0.
```

---

## 4. Surviving contract for AutoCore

```
Loot prefix byte field; keep separate from name/type APIs.
```

---

## 5. Open questions

1. Caller use of returned byte.

**Verdict:** **accept-with-gaps**
