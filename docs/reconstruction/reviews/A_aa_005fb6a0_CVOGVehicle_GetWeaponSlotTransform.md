# Review A (reconstruction fidelity): `aa_005fb6a0` CVOGVehicle_GetWeaponSlotTransform

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fb6a0` |
| **VA** | `0x005fb6a0` |
| **Canonical name** | `CVOGVehicle_GetWeaponSlotTransform` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fb6a0_CVOGVehicle_GetWeaponSlotTransform.md` |
| **System tag** | `vehicle-combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGVehicle_GetWeaponSlotTransform.cpp` |
| Raw | `docs/reconstruction/raw/aa_005fb6a0_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Compute weapon slot transform for slot index param_4. Slot base = param_4*0xc0 + *(this+0x80). Special parity when this+0xc > 2 and slot even (mod-2 check with 0x80000001). Loads local basis floats from slot+0x40..+0x48 and composes into out param_5/param_6. Used for muzzle/TacArc placement.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Slot stride 0xc0 from table this+0x80 | High | Body |
| Even-slot special when type/count this+0xc>2 | High | mod-2 branch |
| Loads slot+0x40/+0x44/+0x48 basis | High | Body |
| Outputs via param_5 / param_6 float buffers | High | Sig |
| Not damage application | High | Transform only |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Index slot → optional even branch → load/compose matrix | Yes |

---

## 4. Gaps

1. Full matrix composition and parent bone chain.
2. param_2/param_3 roles.
3. Exact even-slot visual vs hardpoint meaning.

**Verdict:** **accept-with-gaps**
