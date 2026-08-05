# Review B (skeptical / adversarial): `aa_007e1630` Named_vCloneBase_NameList

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e1630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e1630_Named_vCloneBase_NameList.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is GetTypeFromIDPrefix | Falsified — bulk name list load |
| 2 | Mutates live loot rolls | Falsified — table load |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name entry layout | Medium | Bad labels |

---

## 3. Cross-check against raw

```
vCloneBase_NameList: load name catalog for templates.
```

---

## 4. Surviving contract for AutoCore

```
Supports loot/UI naming; load after/with tCloneBase.
```

---

## 5. Open questions

1. Who consumes the name list at runtime.

**Verdict:** **accept-with-gaps**
