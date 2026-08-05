# Review B (skeptical / adversarial): `aa_004d0cf0` Inv_GenerateLootItem_type

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0cf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d0cf0_Inv_GenerateLootItem_type.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Identical to id path | Falsified — distinct VA + plate |
| 2 | UI filter only | Falsified — generate path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type identity | High | Wrong category drops |
| Shared helper contracts | Medium | Dup logic bugs |

---

## 3. Cross-check against raw

```
GenerateLootItem_type:
  type-keyed entry → GenerateLootItem helpers
Sibling of id path. Residual FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
Type-based loot generation for AutoCore.
```

---

## 5. Open questions

1. List call sites preferring type vs id.

**Verdict:** **accept-with-gaps**
