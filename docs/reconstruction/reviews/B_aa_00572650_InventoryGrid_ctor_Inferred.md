# Review B (skeptical / adversarial): `aa_00572650` InventoryGrid_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00572650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00572650_InventoryGrid_ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Places items | Falsified — ctor |
| 2 | Name PDB-official | Overstated — INFERRED |
| 3 | No sync primitive | Falsified — CS |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Layout 0x68 | High | Corrupt grid |
| CS init | High | Race crash |
| Name certainty | Tentative | Docs only |

---

## 3. Cross-check against raw

```
install vtbls; set w/h/pages; alloc cells; InitCS; empty tree.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
InventoryGrid_ctor(grid, w, h, pages):
  0x68 layout; pair AllocateCellArray / Place / FindFree
  AutoCore cargo grid type
```

---

## 5. Open questions

1. Confirm name vs symbols if any.
2. Document tree key type.

**Verdict:** **accept-with-gaps**
