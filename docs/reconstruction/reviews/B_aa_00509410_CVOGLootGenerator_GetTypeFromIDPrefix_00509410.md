# Review B (skeptical / adversarial): `aa_00509410` CVOGLootGenerator_GetTypeFromIDPrefix_00509410

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509410` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00509410_CVOGLootGenerator_GetTypeFromIDPrefix_00509410.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same as GetTypeFromIDPrefix primary | Falsified — +0x11 name sibling |
| 2 | Returns type int | Falsified — char* name |
| 3 | No miss log | Falsified — invalid prefix log |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x11 field | High | Wrong tooltip name |
| Shared map root | High | Empty loot names |
| Type set completeness | Medium | Default empty |

---

## 3. Cross-check against raw

```
GetTypeFromIDPrefix_name(id):
  type=map[+0x10]; switch→lookup+0x11; miss empty/log.
Sibling of 005092b0/550/680/7b0.
```

---

## 4. Surviving contract for AutoCore

```
Loot modifier name by ID prefix. Keep VA family split by return field.
```

---

## 5. Open questions

1. Rename to GetModifierName once sealed.

**Verdict:** **accept-with-gaps**
