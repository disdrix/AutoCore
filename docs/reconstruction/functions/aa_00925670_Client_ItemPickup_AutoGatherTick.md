# Function record: Client_ItemPickup_AutoGatherTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925670` |
| **Canonical name** | `Client_ItemPickup_AutoGatherTick` |
| **Ghidra name** | `FUN_00925670` |
| **Address** | `0x00925670`–`0x00925712` |
| **Module** | `autoassault.exe` (base `0x400000`) |
| **System** | inventory-transfer / client input |
| **Completion status** | **Dual A/B sealed** (W24-T) |
| **Twin record** | `aa_00925670_FUN_00925670.md` |

## Purpose

Always-on auto item pickup tick from `Client_Input_PollBoundActions`: 100 ms throttle, radius-20 gather, C2S ItemPickup on hit.

## Artifacts

See `aa_00925670_FUN_00925670.md` for full plate list.
