# Review A (reconstruction fidelity): `aa_0040d260` CVOGPhysics_ApplyImpulseVector

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d260` |
| **VA** | `0x0040d260` |
| **Canonical name** | `CVOGPhysics_ApplyImpulseVector` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040d260_CVOGPhysics_ApplyImpulseVector.md` |
| **System tag** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_ApplyImpulseVector.cpp` |
| Raw | `docs/reconstruction/raw/aa_0040d260_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Apply linear velocity/impulse vector to bound rigid body via body vtable +0x50. Optional readiness: FUN_005070b0 probe; if not ready && this+0x44≠0 → FUN_005070d0 first. body=*(this+0x3c). Used by network soft-apply and air-stab/boost reaction paths.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| body = *(this+0x3c) | High | Plate + CF |
| body vtbl +0x50 apply/set linear vel | High | Call |
| Readiness FUN_005070b0; maybe FUN_005070d0 | High | Plate |
| Gate uses this+0x44 | High | Plate |
| Soft network + airStab consumers | Medium | Related notes |
| Vec3 vs vec4 layout Tentative | Medium | Plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Ready probe → optional prepare → vtbl+0x50(vec) | Yes |

---

## 4. Gaps

1. Exact vec layout float3 vs float4.
2. Whether +0x50 is impulse or setLinearVel.
3. FUN_005070b0/d0 names.

**Verdict:** **accept-with-gaps**
