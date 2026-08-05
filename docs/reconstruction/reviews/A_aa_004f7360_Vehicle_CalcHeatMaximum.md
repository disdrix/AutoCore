# Review A (reconstruction fidelity): `aa_004f7360` Vehicle_CalcHeatMaximum

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7360` |
| **VA** | `0x004f7360` |
| **Canonical name** | `Vehicle_CalcHeatMaximum` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f7360_Vehicle_CalcHeatMaximum.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Compute MaxHeat capacity: power plant heat capacity (**plant→nHeatMaximum**, plant via vehicle power path / **+0xb0** family); creature race/level heat tables chassis **+0x531/+0x532**; vehicle heat adjust **+0x1e0**; ceil to int. Table bases `DAT_009cd0dc` / `DAT_009cd0ec` INFERRED. Used when equipping power plant and pool init.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f7360_Vehicle_CalcHeatMaximum.md` (or `aa_004f7360_FUN_004f7360.md`) |
| Annotated | `docs/reconstruction/raw/aa_004f7360_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_CalcHeatMaximum.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f7360_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Power plant heat maximum term` | High | Body |
| `Race/class chassis +0x531/+0x532` | High | Plate |
| `Vehicle heat adjust +0x1e0` | High | Plate |
| `Returns int capacity` | High | Signature |
| `Table DAT addresses` | Medium | INFERRED |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Owner path combine plant+tables+adjust → ceil | Yes |
| No invent current heat write | Yes |

---

## 5. Gaps / open

1. Seal DAT_009cd0dc/ec table contents.
2. Zero plant → 0 heat capacity path.

**Verdict:** **accept-with-gaps**
