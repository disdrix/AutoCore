# Review A (reconstruction fidelity): `aa_004c6100` CVOGCreature_FindTerrainHeight

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c6100` |
| **VA** | `0x004c6100` |
| **Canonical name** | `CVOGCreature_FindTerrainHeight` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c6100_CVOGCreature_FindTerrainHeight.md` |
| **System** | `world-terrain` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Creature ground-snap under world XZ (+ bias): profile scopes; detect **bLocal** via sectorMap focused object vfunc **+0x1d8** == this; `FUN_004cd220(x,z)+bias` first sample; if elevated above terrain by >~0.5 beyond foot, refine — null physics body `this+0x254` → `CVOGMap_CastTerrainHeight(..., bLocal)` else prep + vertical `FUN_00580ed0` castRay filter 5/(5|0xd). Return **terrainY + foot offset this+0x120**. Combat NPCs re-snap; static IsNPC path may skip (server Y).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c6100_CVOGCreature_FindTerrainHeight.md` |
| Annotated | `docs/reconstruction/raw/aa_004c6100_CVOGCreature_FindTerrainHeight.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_FindTerrainHeight.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c6100_CVOGCreature_FindTerrainHeight.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `bLocal via sector+0xe8a0 vfunc+0x1d8` | **High** | Plate |
| `FUN_004cd220 initial HF sample + bias` | **High** | Call |
| `Elevation gate vs DAT_00a0f298 ~0.5 + foot` | **High** | Branch |
| `Null body+0x254 → CastTerrainHeight` | **High** | Path A |
| `Body present → castRay FUN_00580ed0` | **High** | Path B |
| `Filter 5 or 5|0xd when local` | **High** | Matches map cast |
| `Return + foot this+0x120` | **High** | Final |
| `castRay out packing SEH-coupled residual` | **Tentative** | Plate note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Local detect + sample + refine paths + foot | **Yes** |
| No invented wheel collide | **Yes** |

---

## 5. Gaps / open

1. Seal castRay hit-out stack layout.
2. FUN_004cd220 vs FUN_005a58c0 relationship.
3. When AI skips this for static IsNPC.

**Verdict:** **accept-with-gaps**
