# Review A (reconstruction fidelity): `aa_005d9290` Drive_CollisionListener_DoVehicleCollision

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d9290` |
| **VA** | `0x005d9290` |
| **Canonical name** | `Drive_CollisionListener_DoVehicleCollision` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d9290_Drive_CollisionListener_DoVehicleCollision.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Havok/collision listener path for vehicle-vehicle (or vehicle-world) impact (`CollisionListener::DoVehicleCollision`). Takes collider pair + contact normal/impulse-ish floats; computes response magnitudes (SQRT/ABS heavy); may dispatch damage/FX/impulse side effects via FUN_* (physics impulse, combat hooks). Critical for crash damage and bounce — not player input tick.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d9290_Drive_CollisionListener_DoVehicleCollision.md` (or `aa_005d9290_FUN_005d9290.md`) |
| Annotated | `docs/reconstruction/raw/aa_005d9290_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_DoVehicleCollision.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d9290_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String CollisionListener::DoVehicleCollision` | High | Rename |
| `Pair + normal/impulse params` | High | Signature |
| `Heavy float response math` | High | SQRT/ABS |
| `Side-effect FUN callees` | High | Body |
| `Not Input_DriveControlTick` | High | Scope |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Read contact → magnitude → side effects | Yes |
| No invented keyboard axes | Yes |

---

## 5. Gaps / open

1. Exact damage formula vs impulse.
2. Which FUN apply world impulse vs cosmetic.
3. Filter self-collision / invuln.

**Verdict:** **accept-with-gaps**
