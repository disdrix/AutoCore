# Review B (skeptical / adversarial): `aa_007bfd10` Named_dcCloneBase_Insert_MoveFirst

| Field | Value |
|---|---|
| **Stable ID** | `aa_007bfd10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007bfd10_Named_dcCloneBase_Insert_MoveFirst.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | tCloneBase full table | Falsified — cursor helper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cursor state | High | Failed child opens |

---

## 3. Cross-check against raw

```
dcCloneBase_Insert_MoveFirst: parent cursor for template children.
```

---

## 4. Surviving contract for AutoCore

```
DB import ordering primitive for clonebase hierarchy.
```

---

## 5. Open questions

1. Call graph from Drive_dcVehicle_Insert_Open.

**Verdict:** **accept-with-gaps**
