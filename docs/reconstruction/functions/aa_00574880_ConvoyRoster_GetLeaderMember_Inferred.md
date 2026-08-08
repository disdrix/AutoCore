# Function record: ConvoyRoster_GetLeaderMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574880` |
| **Canonical name** | `ConvoyRoster_GetLeaderMember_Inferred` |
| **Ghidra name** | `FUN_00574880` |
| **Address** | `0x00574880`–`0x0057489b` (**28 B** / `0x1c`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | convoy / crew roster |
| **Completion status** | **Dual A/B complete** (2026-08-04 OWN-ONLY WQ9F-I) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Alias

- `FUN_00574880`
- Prior auto plate `Named_CalleeOf_Mission_Client_BuildMissionDetailPanel_00574880` (**reject** as product — single-caller plate)

## Purpose

**Leader member getter.** If roster member-count at `+0x1d8` is zero, return null; else return the object* at leader slot index stored at `+0x194` using the shared 4-slot table base `+0x1a0` / stride `0x10`.

UI convoy invite/kick duals compare the result to `DAT_00d1b6d8` (local player) and disable buttons when not equal — sealed non-leader gate.

## Signature (image-sealed)

```c
// ECX = roster/crew host; no stack args; plain RET; EAX = member* or null
void *ConvoyRoster_GetLeaderMember_Inferred(void *roster);
```

## Layout

| Offset | Role | Conf |
|---|---|---|
| `+0x194` | leader slot index (int; packet-packed as byte) | **High** |
| `+0x1d8` | member count / validity (byte; zero → null) | **High** |
| `+0x1a0 + i*0x10` | slot `i` object* (i∈0..3 at writers) | **High** (shared with GetMemberBySlot) |

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00574760` | `ConvoyRoster_GetMemberBySlot_Inferred` | same load formula + bounds |
| `0x005749d0` | `VehicleCrew_ContainsMember_Inferred` | same host slot table COID scan |
| `0x00574a90` | `VehicleCrew_ClearMemberObject_Inferred` | clears matching slot object* |
| `0x0082fb30` | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` | leader-disable consumer |

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00574880_FUN_00574880.md` |
| Annotated | `docs/reconstruction/raw/aa_00574880_FUN_00574880.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ConvoyRoster_GetLeaderMember_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00574880.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00574880_ConvoyRoster_GetLeaderMember_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00574880_FUN_00574880.md` |
| Dual report | `docs/agents/task-dual-ab-0051f880-00574880-wq9fi-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes | **High** |
| ABI ECX-this + plain ret + EAX ptr | **High** |
| Leader-slot load role | **High** |
| Product C++ name | **Inferred** |
| Index always 0..3 | **Open** (no body clamp) |
