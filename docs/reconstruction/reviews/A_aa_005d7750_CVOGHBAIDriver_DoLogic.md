# Review A (reconstruction fidelity): `aa_005d7750` CVOGHBAIDriver_DoLogic

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7750` |
| **VA** | `0x005d7750` |
| **Canonical name** | `CVOGHBAIDriver_DoLogic` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d7750_CVOGHBAIDriver_DoLogic.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Main NPC **vehicle-driver** AI tick. State machine on **owner+0x26c** (0 idle/patrol, 1 engage, 2 combat): skill cast sets, slot timer, leash via `ReturnToNormalLocation` or `DoVehiclePursue`, **always** `CVOGHBAIFollowVehicle_FireWeapons` at end (weapons decoupled from drive). Bail if path/context `this[0x2f]` missing. Scoped string `CVOGHBAIDriver::DoLogic`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d7750_CVOGHBAIDriver_DoLogic.md` |
| Annotated | `docs/reconstruction/raw/aa_005d7750_CVOGHBAIDriver_DoLogic.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_DoLogic.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d7750_CVOGHBAIDriver_DoLogic.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Scoped string DoLogic` | **High** | Present |
| `Bail if this[0x2f] null or +8 null` | **High** | Early return |
| `State byte owner+0x26c: 0/1/2` | **High** | Matches NPC.md + OnHeartBeat |
| `Idle: clear counter; TryCast set0; slot timer; target→state2 else leash` | **High** | Plate summary |
| `Engage: timer this[0x2d] vs profile; cast set1; promote/drop` | **High** | Body |
| `Combat: pursue + skills tail` | **High** | DoVehiclePursue path |
| `Always FireWeapons at end` | **High** | Independent of drive state |
| `Profile params attack/engage thresholds` | **Probable** | FUN_00540890 chain |
| `AI_CheckSlotTimerReady on idle/combat pulses` | **High** | Call preserved |
| `Client-side simulation only` | **High** | Not server authoritative |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Exception frame + scoped string | **Yes** |
| Path null bail | **Yes** |
| State machine branches | **Yes** |
| FireWeapons epilogue | **Yes** |
| No modernization of state enum | **Yes** |

---

## 5. Gaps / open

1. Full combat-tail skill set IDs and vtbl action slots.
2. Exact this[index] → byte offset table (decomp index vs raw).
3. Engage timer profile source field names.
4. Runtime idle→engage→combat log with +0x26c.

**Verdict:** **accept-with-gaps**
