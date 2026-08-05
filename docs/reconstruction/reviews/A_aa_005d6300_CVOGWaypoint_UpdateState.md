# Review A (reconstruction fidelity): `aa_005d6300` CVOGWaypoint_UpdateState

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6300` |
| **VA** | `0x005d6300` |
| **Canonical name** | `CVOGWaypoint_UpdateState` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d6300_CVOGWaypoint_UpdateState.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Waypoint FSM dispatcher. Scoped string CVOGWaypoint::UpdateState. Switches on state byte **`+0x50`**: **0** → `FUN_005d5750`; **1** → `FUN_005d5960`; **2** → `FUN_005d5cc0`; **3** → `FUN_005d5680`; default fall-through (no handler). Called from path-follow / `CVOGHBAIDriver_ReturnToNormalLocation` when path COID valid. Pose written at `+0x20..+0x2c`, patrol radius `+0x4c` consumed by handlers (not this shell). This function is **dispatch only** — handler bodies still FUN_* residual.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6300_CVOGWaypoint_UpdateState.md` |
| Annotated | `docs/reconstruction/raw/aa_005d6300_CVOGWaypoint_UpdateState.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGWaypoint_UpdateState.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d6300_CVOGWaypoint_UpdateState.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Scoped string CVOGWaypoint::UpdateState` | **High** | FUN_0076cf00 |
| `Switch on *(byte*)(this+0x50)` | **High** | switch |
| `case 0 → FUN_005d5750` | **High** | Call |
| `case 1 → FUN_005d5960` | **High** | Call |
| `case 2 → FUN_005d5cc0` | **High** | Call |
| `case 3 → FUN_005d5680` | **High** | Call |
| `No default case body` | **High** | switch end |
| `Called from ReturnToNormalLocation / path follow` | **High** | Callers |
| `Does not itself AdvanceAndSteer` | **High** | No call here |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + scope + switch 0..3 handlers + unscope | **Yes** |
| No invented state math in shell | **Yes** |

---

## 5. Gaps / open

1. Semantic names for FUN_005d5750/5960/5cc0/5680 (idle / path / patrol / hold?).
2. Which handlers write pose +0x20 and transition +0x50.
3. Role of flag +0x52 noted in NPC.md vs this switch.
4. Whether state 2 is path-active (InitFromSpawn can start at 2).

**Verdict:** **accept-with-gaps**
