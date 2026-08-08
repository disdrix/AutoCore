# Function record: Client_SortTargetListByViewAngle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930360` |
| **Canonical name** | `Client_SortTargetListByViewAngle_Inferred` |
| **Ghidra name** | `FUN_00930360` |
| **Address** | `0x00930360`–`0x00930691` (**0x332** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / client target selection |
| **Classification** | worker |
| **Dual verdict** | **accept-with-gaps** (A≡B MEGA-023 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Sort/reorder a gathered TFID target list by view-angle score relative to the local player's facing (forward + right basis). Drives hostile tab-cycle order for `Client_CycleHostileTarget_Inferred`.

## Signature

```c
// stdcall RET 0xC
void Client_SortTargetListByViewAngle_Inferred(
    void *client,
    TFID_16 *tfidList,
    unsigned *countInOut);
```

## Sealed facts

1. Sole caller: `Client_CycleHostileTarget_Inferred` after `Skill_GatherTargetsInArea`.
2. Score: left half `fDot+1`, right half `-fDot-1`, zero-dist `2.0f`.
3. Sort ascending by score float @ vector elem +4 (`LAB_0092cdd0`).
4. Writes back `obj+0x160` TFID blobs; may shrink count when resolve fails.
5. `_Inferred` — no product string/RTTI at VA.

## Gaps

- Product C++ / keybind plate.
- Virtual `+0x144` / `client+0xd34` English.
- Runtime confirmation.

## Artifacts

See `aa_00930360_FUN_00930360.md` for full artifact list.
