# Review A (reconstruction fidelity): `aa_00809460` Client_RecvObjectiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809460` |
| **VA** | `0x00809460` |
| **Canonical name** | `Client_RecvObjectiveState` |
| **Review date** | `2026-07-23` (residual refresh `2026-07-29`; Action map strengthen same day) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00809460_Client_RecvObjectiveState.md` |
| **Residual scratch** | `reviews/a_00809460.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00809460_Client_RecvObjectiveState.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvObjectiveState.cpp` |
| Function record | `docs/reconstruction/functions/aa_00809460_Client_RecvObjectiveState.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Sibling force-complete | `Client_RecvCompleteDynamicObjective` `0x0080ff00` (opcode `0x2070`) |
| Dispatch | `Client_PacketDispatch` case `0x2071` |
| Residual Ghidra | Live re-decomp `0x00809460`, `FUN_0092ce90`, `FUN_00637de0`; `read_memory` of Collect/UseItem/Patrol/Kill vtables; `get_xrefs_to(0x00637de0)` |
| Slot consumers | UseItem/Kill/Patrol Eval + UseItem/Collect SlotAction |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode **0x2071** progress-only (not complete) | **High** | Body has no `CompleteObjective`; dispatch maps 0x2071 here |
| Pending hash via `client+0xe98` → `char+0x55c` | **High** | Matches character layout in system map |
| Objective id at packet `+0x14` | **High** | Lookup key |
| Four slot dwords `+0x18..+0x24` → `state[1..4]` | **High** | Direct stores; state[0] remains def* |
| Slots are **IEEE float bits** (absolute or 0..1 by type) | **High** | Eval family reinterprets as `float`; sealed residual |
| Bitmask at `+0x10` selects requirement index *i* | **High** | `1 << (uEval & 0x1f)` over def `+0x158` vector |
| **`vtable+0x20` = shared `FUN_00637de0` progress toast** | **High** | 14 DATA vtable slots; body string+`FUN_0040c5c0`; not event Action/Eval |
| Toast uses SlotAction text via `+0x1c` (often trampoline `0x00637dd0` → `+0x18`) | **High** | bytes + multi-class sample |
| UI refresh at `client+0x107c` (mission UI root) | **High** | Same as HideMissionDialogIfOpen |
| `FUN_0092ce90` mission UI panel refresh | **High** | Residual decompile; proposed `Client_RefreshMissionRelatedUi` |
| Dirty `*(client+0x4d0)+4 = 1` | **High** (UI dirty) | Does **not** schedule EvaluatePending |
| Register `in_EAX` = client context | **High** | Packet-handler convention |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Guard character + pending lookup | **Yes** |
| Write 4 slots | **Yes** |
| Optional UI vcalls | **Yes** |
| Bitmask evaluator Action loop | **Yes** |
| Dirty helpers; no CompleteObjective | **Yes** |

Re-decompile 2026-07-29: **no CF change** vs frozen raw.

---

## 4. Gaps (remaining after residual)

1. Product names: `FUN_00637de0`, `FUN_0040c5c0`, `client+0x107c` / `+0x10b8` widgets, dirty `+0x4d0` tracker.
2. Confirm client req type codes **7/8** ≡ `RequirementType.Km` / `TimePlayed` (toast skip).
3. Runtime / bit-exact / image diff (matrix policy).
4. Full toast payload layout (`0x98` element) field map.

**Prior gaps closed by residual:** slot float semantics; `FUN_0092ce90` role; EvaluatePending-not-scheduled; **`vtable+0x20` shared toast identity** (was “per-type Action map open”).

**Verdict:** Progress-only S2C hub faithful. **accept-with-gaps** — dual residual sealed static open Qs for slots + Action; verification dims remain.
