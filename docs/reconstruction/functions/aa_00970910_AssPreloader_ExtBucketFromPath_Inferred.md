# Function record: AssPreloader_ExtBucketFromPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970910` |
| **Canonical name** | `AssPreloader_ExtBucketFromPath_Inferred` |
| **Ghidra name** | `FUN_00970910` |
| **Address** | `0x00970910` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | AssPreloader |
| **Completion status** | **Sealed W38-C** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Classify asset path/name into 5 extension buckets used by AssPreloader size/count tallies.

## Signature

```c
int AssPreloader_ExtBucketFromPath_Inferred(const char** name_holder); // ret 4
```

## Bucket map

| Index | Extension |
|------:|-----------|
| 0 | `.geo` |
| 1 | `.dds` |
| 2 | `.ogg` |
| 3 | `.xml` |
| 4 | OTHER (default; table string built but not searched) |

## Artifacts

See `aa_00970910_FUN_00970910.md` for full links.
