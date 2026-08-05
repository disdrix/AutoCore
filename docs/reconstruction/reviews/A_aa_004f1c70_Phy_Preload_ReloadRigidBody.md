# Review A (reconstruction fidelity): `aa_004f1c70` Phy_Preload_ReloadRigidBody

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1c70` |
| **VA** | `0x004f1c70` |
| **Canonical name** | `Phy_Preload_ReloadRigidBody` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f1c70_Phy_Preload_ReloadRigidBody.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Preload path **`Preload::ReloadRigidBody`** (plate). Reloads / rebuilds rigid body assets via `FUN_004f1180`, `FUN_004a1620`, `FUN_004a6390`, `FUN_005de8f0`, `FUN_0043d650`/`0043d670`, `FUN_00402d50`, path helper `FUN_00989e00`. Used when physics assets must refresh without full world reinit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f1c70_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004f1c70_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_Preload_ReloadRigidBody.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f1c70_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Reload rigid body preload pipeline | High | Plate + callees |
| Shares open helpers with CollectAllPhysicsPreloads | High | FUN_00989e00/43d670 |
| Not world Step | High | Distinct role |
| Full per-mesh algorithm sealed | Medium | FUN residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| path/open → rebuild helpers → return | Yes |

---

## 5. Gaps / open

1. Name FUN_004f1180 primary reload.
2. When called vs CollectAllPhysicsPreloads.

**Verdict:** **accept-with-gaps**
