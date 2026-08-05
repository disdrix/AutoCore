# Review B (skeptical / adversarial): `aa_004d0df0` Inv_GenerateLootItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d0df0_Inv_GenerateLootItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is the type-keyed generator | Falsified — (id) plate |
| 2 | DB table loader | Falsified — runtime generate |
| 3 | Only grants credits | Falsified — item generate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Id resolve path | High | Wrong item CBID |
| Sibling split id/type | High | Wrong generator |

---

## 3. Cross-check against raw

```
GenerateLootItem(id path):
  orchestrate id → item instance via helpers
≠ type path. Residual FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
Runtime loot item creation for AutoCore drop awards.
```

---

## 5. Open questions

1. Capture one kill-loot generate call stack.

**Verdict:** **accept-with-gaps**
