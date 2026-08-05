# Review A (reconstruction fidelity): `aa_005f7720` VehicleNet_UnpackGhostVehicle

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f7720` |
| **VA** | `0x005f7720` |
| **Canonical name** | `VehicleNet_UnpackGhostVehicle` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005f7720_VehicleNet_UnpackGhostVehicle.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

TNL GhostVehicle unpack for **initial + delta** updates (~3k-line clean). Wire order: flags → pose (pos/rot/vel/angVel) → quantized throttle/steer → owner block (creature-owner form @0x005F7DCA **no** SpawnOwner wheels path) → optional path block → hardpoints (initial may equip; delta → `FUN_005b2800` + `PostCorrectionEvent`) → combat tail (Heat 32b → **+0x150** HeatMask **0x20000000**; ShieldMax **+0x148** **0x2000000**; Shield clamp **+0x144** **0x4000000**; Power via owner vtbl; Health 18b cur/max). Handbrake runtime flag is **wire** `VehicleFlags` bit0 → entity **+0x61c** (≠ sinVehicleFlags setup). GM 4 bits → owner+0x12A; AI state bits. AutoCore `GhostVehicle.cs` mirrors masks.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f7720_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005f7720_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleNet_UnpackGhostVehicle.cpp` |
| Function record | `docs/reconstruction/functions/aa_005f7720_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Initial vs delta hardpoint split (equip vs PostCorrection)` | High | RE docs + clean |
| `Combat tail Heat/Shield/Power/Health masks` | High | Plate + GhostVehicle tests |
| `Pose + throttle/steer quantized fields` | High | server_ghost_pack_notes |
| `Creature-owner form omits wheels path` | High | 0x005F7DCA note |
| `Wire handbrake bit0 → +0x61c` | High | server_handbrake_wire |
| `Full bit-exact field widths every branch` | Medium | Large residual |
| `Path-block current path id reader` | Medium | NPC path RE |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| flag-gated sections; combat tail after attributes | Yes |
| No invent server-only pack order divergence as client read | Yes |

---

## 5. Gaps / open

1. Seal every mask bit vs GhostVehicle.cs pack path.
2. Runtime capture of one initial + one delta unpack.
3. Bit-exact deferred.

**Verdict:** accept-with-gaps
