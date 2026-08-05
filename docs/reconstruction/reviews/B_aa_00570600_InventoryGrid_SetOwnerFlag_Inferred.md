# Review B (skeptical / adversarial): `aa_00570600` InventoryGrid_SetOwnerFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00570600_InventoryGrid_SetOwnerFlag_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Allocates cells | Falsified — flag only |
| 2 | No-op forever | Falsified — raw writes +0x4 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x4 owner flag | High | Wrong owner semantics |
| Clean/raw drift | Medium | False no-op port |

---

## 3. Cross-check against raw

```
SetOwnerFlag(grid, flag): grid+0x4 = flag. Prefer annotated raw.
```

---

## 4. Surviving contract for AutoCore

```
Cargo grid ownership mark after ctor; pair with AllocateCellArray.
```

---

## 5. Open questions

1. Who reads +0x4.

**Verdict:** **accept-with-gaps**
