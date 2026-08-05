# Review B (skeptical / adversarial): `aa_005097b0` CVOGLootGenerator_GetTypeFromIDPrefix_005097b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005097b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005097b0_CVOGLootGenerator_GetTypeFromIDPrefix_005097b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same as GenerateLootItem | Falsified — prefix field getter |
| 2 | Always +0x11 name | Falsified — +0x70 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x70 field | High | Wrong loot struct |
| Fallthrough CF | Medium | Wrong type branch |

---

## 3. Cross-check against raw

```
Sibling: type → non-null lookup → entry+0x70. Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Loot prefix struct accessor; family residual of 005092b0.
```

---

## 5. Open questions

1. Document full VA family offsets table.

**Verdict:** **accept-with-gaps**
