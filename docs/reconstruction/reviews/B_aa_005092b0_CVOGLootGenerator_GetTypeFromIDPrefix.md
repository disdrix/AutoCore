# Review B (skeptical / adversarial): `aa_005092b0` CVOGLootGenerator_GetTypeFromIDPrefix

| Field | Value |
|---|---|
| **Stable ID** | `aa_005092b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005092b0_CVOGLootGenerator_GetTypeFromIDPrefix.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Generates final item instance | Falsified — type-from-prefix only |
| 2 | Is tLootTable loader | Falsified — runtime map lookup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Prefix map correctness | High | Wrong affix type |
| Sibling VA confusion | Medium | Wrong port |

---

## 3. Cross-check against raw

```
GetTypeFromIDPrefix(prefix):
  lower_bound DAT_00b041dc; miss → log error
Clean ≡ raw; siblings exist.
```

---

## 4. Surviving contract for AutoCore

```
Loot affix type resolve for AutoCore generator.
```

---

## 5. Open questions

1. Diff siblings 00509410/550/680/7b0 roles.

**Verdict:** **accept-with-gaps**
