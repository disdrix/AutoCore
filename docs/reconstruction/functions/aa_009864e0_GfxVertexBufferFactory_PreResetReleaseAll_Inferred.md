# Function record: GfxVertexBufferFactory_PreResetReleaseAll_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009864e0` |
| **Canonical name** | `GfxVertexBufferFactory_PreResetReleaseAll_Inferred` |
| **Ghidra name** | `FUN_009864e0` |
| **Address** | `0x009864e0`–`0x00986560` inclusive (**129 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / gfxVertexBufferFactory + gfxDeviceVB |
| **Completion status** | **Dual A/B complete** (W38-AD) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

See twin record `aa_009864e0_FUN_009864e0.md`. Name from Device Reset call site + `FUN_007465c0`/`gfxDeviceVB.cpp` + PostRestore sibling `gfxVertexBufferFactory.cpp` strings.

## Signature

```c
void GfxVertexBufferFactory_PreResetReleaseAll_Inferred(/* EAX factory */);
```

## Artifacts

Same trio + dual A/B as `functions/aa_009864e0_FUN_009864e0.md`.
