# Function record: ParticleFluidLiquidChild_HostLink_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c17b0` |
| **Canonical name** | `ParticleFluidLiquidChild_HostLink_Ctor_Inferred` |
| **Ghidra** | `FUN_004c17b0` |
| **Address** | `0x004c17b0` |
| **Body** | `0x004c17b0`–`0x004c17fe` inclusive (**79 B**) |
| **Wave** | W38-L OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

## Layout (HostLink, 8 B)

| Off | Field |
|---|---|
| +0 | `void** vtbl` → `PTR_LAB_009cb7a4` (slot0 `0x004c09c0`) |
| +4 | `void* host` (liquid-child parent; may be null) |

## Host list coupling

| Off on host | Field |
|---|---|
| +8 | list sentinel `ListNode0C*` |
| +0xC | list size |
| IncSize ECX | `host+4` (size at ECX+8) |

## See also

- Parent ctor: `ParticleFluidLiquidChild_Ctor_Inferred` (`0x004c1800`, W37-G)
- CreateLiquidChild: `0x004c1960` (W34-O)
- Twin Ghidra record: `aa_004c17b0_FUN_004c17b0.md`
