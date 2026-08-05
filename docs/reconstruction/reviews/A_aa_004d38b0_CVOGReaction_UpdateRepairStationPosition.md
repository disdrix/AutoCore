# Review A (reconstruction fidelity): `aa_004d38b0` CVOGReaction_UpdateRepairStationPosition

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d38b0` |
| **VA** | `0x004d38b0` |
| **Canonical name** | `CVOGReaction_UpdateRepairStationPosition` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d38b0_CVOGReaction_UpdateRepairStationPosition.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-map **player TFID → station key** map update (set/map at `this+0xe740`):

1. `this` = large map/world object owning repair-station entries.
2. `param_2` = player TFID (2 dwords).
3. `param_3` = station key (GenericVar1).
4. Tree/map lower_bound style via `FUN_004e2320(param_2)`; compare against sentinel at `this+0xe740`.
5. If end/miss: `FUN_004e48b0` insert `{tfid_lo, tfid_hi, stationKey}` → return **1**.
6. If found and `entry+0x18 != stationKey`: update key → return **1**.
7. If found and key unchanged → return **0**.

Called from MarkRepairStation after character field writes.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d38b0_CVOGReaction_UpdateRepairStationPosition.md` |
| Annotated | `docs/reconstruction/raw/aa_004d38b0_CVOGReaction_UpdateRepairStationPosition.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_UpdateRepairStationPosition.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d38b0_CVOGReaction_UpdateRepairStationPosition.md` |
| Caller | MarkRepairStation `aa_00521e00` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(map*, tfid[2]*, stationKey) → 0/1` | **High** | Raw plate |
| Map root at `+0xe740` | **High** | Explicit |
| Return 1 on insert or key change | **High** | Two success arms |
| Return 0 if unchanged | **High** | Final |
| TFID ordered compare uses hi/lo dwords | **High** | Nested compare |
| FUN_004e2320 = lower_bound / find | **Probable** | Pattern |
| FUN_004e48b0 = insert | **Probable** | Pattern |
| Full tree node layout | **Tentative** | +0x10/+0x14/+0x18 only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Find vs end | **Yes** |
| Insert path | **Yes** |
| Update-if-different | **Yes** |
| Unchanged 0 | **Yes** |

---

## 5. Gaps

1. Red-black / tree implementation of helpers.
2. Who reads the map (respawn? UI?).
3. Multi-map lifetime of entries.
4. Runtime mark → update return value observation.
5. Exact `this` type (continent map vs sector world).

**Verdict:** Insert/update map CF faithful. **accept-with-gaps.**
