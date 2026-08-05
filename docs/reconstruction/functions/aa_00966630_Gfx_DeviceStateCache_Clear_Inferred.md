# Function record: Gfx_DeviceStateCache_Clear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966630` |
| **Canonical name** | `Gfx_DeviceStateCache_Clear_Inferred` |
| **Ghidra name** | `FUN_00966630` |
| **Address** | `0x00966630` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | gfx / device state cache |
| **Name class** | **Inferred** (structural from caches + sole Reset caller) |
| **Completion status** | Dual A/B **accept** (W38-Y) |
| **Classification** | leaf |

## Signature

```c
void Gfx_DeviceStateCache_Clear_Inferred(uint32_t *host /* EDX */);
```

## Behavior

1. Zero `DAT_00d0e128[16]` and `DAT_00d0e0e8[16]` (`REP STOSD`).
2. Zero `DAT_00d1a568`, `DAT_00d1a564`, `DAT_00d1a558`, `DAT_00d1a55c`.
3. Zero `host[0]`, `host[1]`, `host[2]`, `host[0xf]` (`+0x00..+0x08`, `+0x3C`).

## Evidence

Live Ghidra decompile + full-body `read_memory` (68 B) + sole caller call-site + sibling `FUN_00966690` init + consumer `FUN_0043f4b0`. **No** `disassemble_bytes`.

## Related

- Parent: `aa_0075eff0` `GfxDevice_Reset` (W37-N).
- Twin init: `FUN_00966690` (full host setup + same zero block).
- Nuller: `FUN_00966680` (`DAT_00d1f048 = 0`).
