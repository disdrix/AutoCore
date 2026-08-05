# Review B (skeptical / adversarial): `aa_00509550` CVOGLootGenerator_GetTypeFromIDPrefix_00509550

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00509550_CVOGLootGenerator_GetTypeFromIDPrefix_00509550.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same return as 00509410 +0x11 | Falsified — +0x44 |
| 2 | Returns byte type | Falsified — pointer field |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x44 meaning | High | Wrong loot field |
| Default empty | Medium | Silent miss |

---

## 3. Cross-check against raw

```
Sibling: map type → entry+0x44. Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Loot prefix field accessor; do not collapse into primary GetType.
```

---

## 5. Open questions

1. Xref callers for +0x44 consumers.

**Verdict:** **accept-with-gaps**
