# Review A (reconstruction fidelity): `aa_005d2e40` GhostCreature_UnpackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2e40` |
| **VA** | `0x005d2e40` |
| **Canonical name** | `GhostCreature_UnpackUpdate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d2e40_GhostCreature_UnpackUpdate.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

GhostCreature TNL unpackUpdate (~869-line clean). Applies **PositionMask** XYZ from server **as-is** (no terrain/foot correction). Initial update also packs enhancement/triggers/level/skills. Sibling contrast to `VehicleNet_UnpackGhostVehicle` (vehicle pose/combat/hardpoints). Useful when comparing owner/creature ghost paths that interact with vehicle owner blocks.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d2e40_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005d2e40_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GhostCreature_UnpackUpdate.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d2e40_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Position as-is no foot correct` | High | Plate |
| `Initial extra blocks (enhancement/skills)` | High | Plate |
| `Creature not vehicle hardpoints` | High | Body scope |
| `Full mask table sealed` | Medium | Large residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| flag-gated field reads; position raw | Yes |
| No invent vehicle wheel equip | Yes |

---

## 5. Gaps / open

1. Seal mask bits vs GhostCreature server pack.

**Verdict:** accept-with-gaps
