# Review B (skeptical / adversarial): `aa_007bfa70` Named_dcDamage_Insert_MoveFirst

| Field | Value |
|---|---|
| **Stable ID** | `aa_007bfa70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007bfa70_Named_dcDamage_Insert_MoveFirst.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is tDamage full load | Falsified — insert helper |
| 2 | Runtime damage apply | Falsified — DB cursor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cursor semantics | High | Missed damage rows |

---

## 3. Cross-check against raw

```
dcDamage_Insert_MoveFirst: child damage rows under open parent.
```

---

## 4. Surviving contract for AutoCore

```
DB import helper for combat gear damage links.
```

---

## 5. Open questions

1. Trace one weapon open through this helper.

**Verdict:** **accept-with-gaps**
