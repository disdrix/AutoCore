# Review A (reconstruction fidelity): `aa_005d6e80` CVOGHBAIDriver_ReturnToNormalLocation

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6e80` |
| **VA** | `0x005d6e80` |
| **Canonical name** | `CVOGHBAIDriver_ReturnToNormalLocation` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d6e80_CVOGHBAIDriver_ReturnToNormalLocation.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leash / return-home for drivers: prefer **map path** (`CVOGMapPath` / waypoint) when path COID resolves; else pursue spawn/home or clear. Notes combat target at `this[6]+0xa0`. Returns **char** handled/success for idle branch in DoLogic. Scoped string `CVOGHBAIDriver::ReturnToNormalLocation()`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6e80_CVOGHBAIDriver_ReturnToNormalLocation.md` |
| Annotated | `docs/reconstruction/raw/aa_005d6e80_CVOGHBAIDriver_ReturnToNormalLocation.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_ReturnToNormalLocation.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d6e80_CVOGHBAIDriver_ReturnToNormalLocation.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Scoped string ReturnToNormalLocation` | **High** | Present |
| `Notes target this[6]+0xa0 present` | **High** | bVar7 |
| `Path COID / waypoint gate on owner dual-base +0x228..+0x234` | **High** | All-FF / zero checks |
| `CVOGWaypoint_UpdateState on path` | **High** | Call |
| `MapPath_AdvanceAndSteer when path valid` | **High** | Plate + related |
| `Distance vs waypoint+0x4c threshold` | **High** | SQRT delta pos |
| `Returns char success/handled` | **High** | cVar4 |
| `Null path → clear / fall through home` | **High** | Body branches |
| `param_1[0x2f] path context` | **High** | Shared with DoLogic |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Exception + scoped string | **Yes** |
| Target note + COID gate | **Yes** |
| Waypoint / distance / steer paths | **Yes** |
| Char return | **Yes** |

---

## 5. Gaps / open

1. Full MapPath index/curvature field map.
2. Exact return polarity when target present vs home-only.
3. this+0x95 flag meaning.
4. Runtime leash with and without path COID.

**Verdict:** **accept-with-gaps**
