# Function record: CNDHash_TraversalLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e10` |
| **Canonical name** | `CNDHash_TraversalLock` |
| **Ghidra name** | `FUN_00411e10` |
| **Address** | `0x00411e10`–`0x00411e35` (**38 B** / `0x26`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / shared CNDHash |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_00411e10_CNDHash_TraversalLock.md`, `B_aa_00411e10_CNDHash_TraversalLock.md` |
| **Last reviewed** | `2026-08-05` (MEGA-113 OWN-ONLY) |

## Alias

- `FUN_00411e10`
- **Rejected scaffold:** `Named_VOG_DEBUG_STOP_00411e10`
- **Rejected:** any `Named_CalleeOf_*`

## Purpose

String-sealed **CNDHash TraversalLock** entry: acquire traversal ownership by setting `hash+0x1d = 1`. Double-lock is soft (log + continue + re-assert flag). Shared leaf used by interact-icon refresh (`Client_UpdateNpcInteractIcons`), UI reload, and object/character-embedded hash walkers.

## Signature (sealed)

```c
// custom: ESI = CNDHash* hash; no stack args; void; bare ret (C3)
// NOT MSVC thiscall
void CNDHash_TraversalLock(void /*ESI=hash*/);
```

## Algorithm

1. If `*(hash+0x1d) != 0`: log `"HashError:TraversalLock, already locked for traversal"` then `"VOG_DEBUG_STOP"` via `FUN_007a4480`.
2. Always: `*(hash+0x1d) = 1`.
3. Return (caller walks with TraverseToNext / inline chain; unlocks by clearing `+0x1d`).

## Related

- Peer: TraverseToNext family checks same flag (string `HashError:TraverseToNext, not locked for traversal` @ `0x00a27c9c`; raw `FUN_00411e40` residual).
- List parallel: `List_TraversalLock` (`0x004294f0`) / `List_TraversalUnlock` (`0x0040c700`) — CS-based, different layout.
- CNDHash host family: ctor `CNDHash_Ctor_00a2c2b0`, alloc/destroy bucket table duals (WQ9G-J / WQ9H-D).
- Partition parent: `Client_UpdateNpcInteractIcons` @ `0x0091b8d0`.

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
- Clean: `docs/reconstruction/reconstructed-exact/CNDHash_TraversalLock.cpp`
- Report: `docs/agents/task-dual-ab-00411e10-mega-113-report.md`

## Confidence

| Claim | Level |
|---|---|
| Role = CNDHash TraversalLock set | **High** |
| ESI ABI / bare ret / +0x1d flag | **High** |
| Soft double-lock (log then set) | **High** |
| Product C++ class / RTTI | **Open** |
| Runtime / bit-exact | **Open** |
