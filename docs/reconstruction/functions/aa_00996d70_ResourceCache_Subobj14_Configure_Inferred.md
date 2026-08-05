# Function record: ResourceCache_Subobj14_Configure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996d70` |
| **Canonical name** | `ResourceCache_Subobj14_Configure_Inferred` |
| **Ghidra name** | `FUN_00996d70` |
| **Address** | `0x00996d70`–`0x00996dbb` (**76 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | ResourceCache / embedded configure subobject |
| **Completion status** | **Dual-reviewed (W37-V)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Classification** | worker |

## Purpose

Reconfigure the embedded ResourceCache configure-subobject at host `+0x14`. Closes nested residual from W31-F `ResourceCache_SetField10AndConfigure_Inferred` (which sets `+0x10` then calls this with `EAX=host+0x14`).

## Signature

```c
// EAX=subobj, EBX=size, stack flag, RET 4
void ResourceCache_Subobj14_Configure_Inferred(
    void *subobj /*EAX*/,
    uint32_t size /*EBX*/,
    uint8_t flag /*stack*/);
```

## Family

- Parent: `ResourceCache_SetField10AndConfigure_Inferred` (`0x00989ef0`)
- Sibling lock/layout: `ResourceCache_LookupByName` (`0x00989e00`)
- Buffer helpers: `FUN_009899a0`, `FUN_00989b00`

## Artifacts

- Twin Ghidra record: `docs/reconstruction/functions/aa_00996d70_FUN_00996d70.md`
- Clean: `docs/reconstruction/reconstructed-exact/ResourceCache_Subobj14_Configure_Inferred.cpp`
- Dual A/B: `reviews/A_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md`, `reviews/B_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md`
