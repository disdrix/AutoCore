# Function record: GfxBody_UnserializeGBOD_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00765740` |
| **Canonical name** | `GfxBody_UnserializeGBOD_Inferred` |
| **Ghidra name** | `FUN_00765740` |
| **Address** | `0x00765740`–`0x00766045` (**2310 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | palantir / graphics / gfxBody |
| **Wave** | W37-S |
| **Verdict** | **accept-with-gaps** |
| **Classification** | worker |

## Signature

```c
uint32_t __stdcall GfxBody_UnserializeGBOD_Inferred(void* body, void* reader);
// RET 8; SEH LAB_009b31c4; bad tag/version → 0xFFFFFFFF
```

## Evidence anchors

| Fact | Source |
|---|---|
| Tag `0x47424F44` GBOD | `read_memory` `81 7c 24 3c 44 4f 42 47` |
| Path `gfxBody.cpp` | decompile + string |
| Invalid TAG / version plates | `0x00a9dc40`, `0x00a9dc0c` |
| Sole caller | `FUN_0073eb40` |
| MapA factory | `FUN_00437b00` (W36-A) |
| MapB optional | `FUN_00437c90` (W36-C) |

## Port note

Port as **GBOD root unserialize** for gfxBody with versioned arms and OR-status. Do not invent method English beyond plates. Pair factory loops with W36-A/C. Respect stdcall 2-arg cleanup.

## Artifacts

See `aa_00765740_FUN_00765740.md`.
