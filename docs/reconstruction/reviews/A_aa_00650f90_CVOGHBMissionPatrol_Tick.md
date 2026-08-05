# Review A (reconstruction fidelity): `aa_00650f90` CVOGHBMissionPatrol_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f90` |
| **VA** | `0x00650f90` |
| **Canonical name** | `CVOGHBMissionPatrol_Tick` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00650f90_CVOGHBMissionPatrol_Tick.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission **patrol** heartbeat tick: RTDynamicCast owner to Character; resolve mission block +0xcb0; match local/player TFID (or party loop <4); on match apply scalar blend into char **+0xc54** (personal XP scalar family) via vtbl+0x50 path; else vtbl+0x18(1,1) fail path. Ties to ObjectiveRequirementPatrol / discovery.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00650f90_CVOGHBMissionPatrol_Tick.md` |
| Annotated | `docs/reconstruction/raw/aa_00650f90_CVOGHBMissionPatrol_Tick.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionPatrol_Tick.cpp` |
| Function record | `docs/reconstruction/functions/aa_00650f90_CVOGHBMissionPatrol_Tick.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `RTDynamicCast owner → CVOGCharacter` | **High** | Entry |
| `Mission block char+0xcb0` | **High** | iVar3 |
| `Local player match FUN_00578270` | **High** | Compare param_1[6] |
| `Party loop iVar5 < 4 TFID match +0x196..` | **High** | Alternate |
| `Match → vtbl+0x50 + scalar into +0xc54` | **High** | Progress path |
| `Miss → vtbl+0x18(1,1)` | **High** | Fail/cleanup |
| `FUN_00578b30 epilogue both paths` | **High** | Tail |
| `Links patrol objective / auto-patrol docs` | **Probable** | System notes |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Cast + mission resolve | **Yes** |
| Local/party match branches | **Yes** |
| Scalar / fail paths | **Yes** |

---

## 5. Gaps / open

1. Whether +0xc54 write is XP scalar or patrol progress residual mis-name.
2. vtbl+0x50 / +0x18 identities.
3. Distance check may live in Fn3/Fn6 siblings not this body.
4. Runtime patrol objective complete capture.

**Verdict:** **accept-with-gaps**
