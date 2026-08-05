# Function record: WorldObj_UnbindOrDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005614f0` |
| **Canonical name** | `WorldObj_UnbindOrDefer_Inferred` |
| **Ghidra name** | `FUN_005614f0` |
| **Address** | `0x005614f0`–`0x00561571` (**129 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object unbind / defer (no destroy) |
| **Completion status** | **Dual-sealed** (W30-J 2026-07-29) — A **accept**, B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Manager **thiscall** unbind of a world object — **or defer** if reentrancy flag `manager+0x12c == 1` (same flag/queue family as enroll and `WorldObj_RemoveOrDefer`).

### Defer branch

Grow/push onto pointer vector at `manager+0xf0`, `obj.ref6++`, `*outDone = 0`.

### Immediate branch

1. If `manager+0x24 > 0`: `FUN_00561320` (flush pending body pairs).
2. `FUN_0055fbf0(manager, obj)` — unbind links.
3. `FUN_0055f0b0(obj)` — compact `obj+0x88` pointer list.
4. `FUN_0055fd80(manager, obj)` — clear `obj+8`, host detach/cleanup.
5. `*outDone = 1`.

**Not** remove/destroy: unlike `00561450`, no `0062a490` / `005ffff0`, no ref--, no vtbl destroy.

Used by mode-7 leave path (`WorldObj_SnapshotHostRefsAndUnbind`) after snapshotting host-list entries so the object can be rebound later.

## Signature

```c
// RET 8
void __thiscall WorldObj_UnbindOrDefer_Inferred(int manager, uint8_t *outDone, int obj);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindOrDefer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005614f0.cpp` |
| Scaffold record | `docs/reconstruction/functions/aa_005614f0_FUN_005614f0.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `WorldObj_SnapshotHostRefsAndUnbind_Inferred` (`005617c0`) | leave mode 7 |
| Caller | `FUN_00561580` | related host detach |
| Callee | `005b3370` / `00561320` / `0055fbf0` / `0055f0b0` / `0055fd80` | queue / flush / unbind family |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI sealed | **Confirmed** |
| Distinct from RemoveOrDefer | **Confirmed** |
| Product names | Open / `_Inferred` |
