# Review A (reconstruction fidelity): `aa_005cfb60` CVOGHBAICreatureBase_DoVehiclePursue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cfb60` |
| **VA** | `0x005cfb60` |
| **Canonical name** | `CVOGHBAICreatureBase_DoVehiclePursue` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005cfb60_CVOGHBAICreatureBase_DoVehiclePursue.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Steer owned vehicle toward active attack/pursue target: vehicle @ owner+0x250, target @ this[6]+0xa0; alive vtbl+0x198; aim pos vtbl+0x1c8; ground/air offset +0x84/+0xb0; normalize + clamp `DAT_009da864`; speed-threshold heading `FUN_005cc460` + rot matrix else direct vector; apply dest vtbl+0x4c. Caller: Driver combat; idle when no map path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cfb60_CVOGHBAICreatureBase_DoVehiclePursue.md` |
| Annotated | `docs/reconstruction/raw/aa_005cfb60_CVOGHBAICreatureBase_DoVehiclePursue.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAICreatureBase_DoVehiclePursue.cpp` |
| Function record | `docs/reconstruction/functions/aa_005cfb60_CVOGHBAICreatureBase_DoVehiclePursue.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vehicle from owner+0x250 family` | **High** | this[0x19]+0x250 |
| `Target this[6]+0xa0` | **High** | Shared target slot |
| `Alive check vtbl+0x198` | **High** | Gate |
| `Target pos vtbl+0x1c8 / +0x1a0 family` | **High** | Body |
| `Ground +0x84 vs air +0xb0 offset` | **High** | Vehicle type branch |
| `Direction normalize + DAT_009da864 clamp` | **High** | Max turn/dir |
| `Speed threshold → heading helper vs direct` | **High** | FUN_005cc460 / direct |
| `Apply destination vtbl+0x4c` | **High** | Steer write |
| `FPU-heavy residual` | **High** | Large clean body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Target/vehicle resolve + alive | **Yes** |
| Offset + normalize + clamp | **Yes** |
| Speed branch + apply | **Yes** |
| No invented clamps beyond DAT | **Yes** |

---

## 5. Gaps / open

1. FUN_005cc460 / FUN_00567ce0 true names.
2. DAT_009da864 exact units (rad/s vs unit vector).
3. Flag +0xb8 bit 6 scaled pursuit meaning.
4. Runtime pursue capture with steering axes.

**Verdict:** **accept-with-gaps**
