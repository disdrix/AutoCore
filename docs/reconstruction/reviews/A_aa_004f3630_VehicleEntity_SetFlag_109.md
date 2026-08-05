# Review A (reconstruction fidelity): `aa_004f3630` VehicleEntity_SetFlag_109

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3630` |
| **VA** | `0x004f3630` |
| **Canonical name** | `VehicleEntity_SetFlag_109` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f3630_VehicleEntity_SetFlag_109.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny ungated store: `*(u8*)(this+0x109) = param_2`. Neighbor of `SetHandbrake` in .text; **not** a drive-axis field (axes live at +0x614/+0x618/+0x61c). Flag meaning residual — name is offset-based. No gates, no mask dirty. Thin entity flag setter for inventory completeness.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3630_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3630_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetFlag_109.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f3630_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Single store at +0x109` | High | Body 1-liner |
| `Not drive-axis (≠ +0x61c)` | High | Offset contrast |
| `No gate / no mask` | High | Body |
| `Semantic name of flag` | Low | Offset-only name |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| store u8 @ +0x109 | Yes |
| No invent semantics | Yes |

---

## 5. Gaps / open

1. Name flag from xrefs / create-packet / ghost pack.
2. Confirm consumers of entity+0x109.

**Verdict:** **accept-with-gaps**
