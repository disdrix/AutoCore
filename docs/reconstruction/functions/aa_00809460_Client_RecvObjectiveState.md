# Function record: Client_RecvObjectiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809460` |
| **Canonical name** | `Client_RecvObjectiveState` |
| **Address** | `0x00809460` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Opcode** | **0x2071** ObjectiveState (progress only) |
| **Calling convention** | Packet arg + client context in EAX |
| **Completion status** | **Human-refined clean** — dual residual 2026-07-29 sealed **slot floats** + **shared Action vtbl+0x20** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Progress-only S2C handler. Lookup pending objective by id (`packet+0x14`), write 4 **IEEE float** slots (`+0x18..+0x24` → state[1..4]), fire bitmask-selected requirement **`vtable+0x20`** — which is the **shared** progress-toast Action `FUN_00637de0` (not event Action / Eval / SlotAction). **Does not** complete objectives (distinct from `0x2070` / `Client_RecvCompleteDynamicObjective`). **Does not** call `EvaluatePendingObjectives`.

## Signature

```c
void Client_RecvObjectiveState(int pPacket); // client context in EAX
```

## Packet map

| Offset | Field |
|---|---|
| `+0x10` | bitmask (u32) — bit *i* → requirement *i* `vtbl+0x20` toast |
| `+0x14` | objective id |
| `+0x18..+0x24` | 4× slot values (**float** bits; absolute count or 0..1 ratio by type) |

## Behavioral summary

1. Require local character at `client+0xe98` and pending-hash hit at `char+0x55c` by id.
2. Store four progress dwords into runtime node `[1..4]` (node`[0]` remains def pointer).
3. Optional mission UI root at `client+0x107c` (vtable `+0x3d8` gate, then `+0x448` / `+0x34c`).
4. For each requirement index with mask bit set: call `vtbl+0x20(char, node)` = **`FUN_00637de0`** (shared progress toast; fills text via `vtbl+0x1c` → usually SlotAction `+0x18`; skips req types 7/8).
5. `FUN_0092ce90` / `Client_RefreshMissionRelatedUi` + dirty byte `*(client+0x4d0)+4 = 1`.

## Action `vtbl+0x20` (sealed residual)

| Fact | Detail | Confidence |
|---|---|---|
| Target | `FUN_00637de0` @ `0x00637de0` | **High** |
| Scope | Shared by Collect / UseItem / Patrol / Kill + 10 further DATA vtable slots | **High** |
| Role | Progress string + UI toast enqueue (`FUN_0040c5c0`); **not** complete | **High** |
| Not | Collect event Action `+0x04`, Eval `+0x08`/`+0x10`, SlotAction `+0x18` | **High** |
| Text path | often `+0x1c` trampoline `0x00637dd0` → `jmp [vtbl+0x18]` | **High** |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Opcode / role | High | plate + missionState.md |
| Packet offsets | High | direct stores |
| Pending hash via client+0xe98 → char+0x55c | High | consistent with character layout |
| No CompleteObjective | High | body has none |
| Slot IEEE float bits | **High** | dual residual; Eval family |
| No EvaluatePending from this path | **High** | residual decompile + xrefs |
| `vtable+0x20` shared toast | **High** | multi-vtbl `read_memory` + xrefs + body |
| `FUN_0092ce90` UI refresh role | **High** | residual; original name open |
| UI object at +0x107c class name | Tentative | mission UI root sealed; class open |
| Overall | **High (static)** | |

## Open questions

- Product names for `FUN_00637de0` / `FUN_0040c5c0` / `client+0x107c` / dirty `+0x4d0` tracker.
- Confirm client type codes 7/8 ≡ Km / TimePlayed.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00809460_Client_RecvObjectiveState.md` |
| Annotated | `raw/aa_00809460_Client_RecvObjectiveState.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvObjectiveState.cpp` |
| Shared Action | `functions/aa_00637de0_FUN_00637de0.md` |
| Force-complete sibling | `functions/aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| UI refresh callee | `functions/aa_0092ce90_FUN_0092ce90.md` |
| System map | `systems/missions-progression.md` |
| Dual A | `reviews/A_aa_00809460_Client_RecvObjectiveState.md` |
| Dual B | `reviews/B_aa_00809460_Client_RecvObjectiveState.md` |
| Dual residual | `reviews/a_00809460.md` |
