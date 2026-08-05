# Function record: D3dFormat_GetBitsPerPixel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ead0` |
| **Canonical name** | `D3dFormat_GetBitsPerPixel_Inferred` |
| **Ghidra name** | `FUN_0040ead0` |
| **Address** | `0x0040ead0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Graphics / D3D format utility |
| **Wave** | W38-T |
| **Verdict** | **accept** |
| **Naming** | **Inferred** from D3DFMT constants + bpp/8 callers |

## Role

Leaf **format → bits-per-pixel** table for texture/surface memory math.

## Signature

```c
uint32_t D3dFormat_GetBitsPerPixel_Inferred(uint32_t d3d_format);
```

## Cross-links

- Ghidra record: `docs/reconstruction/functions/aa_0040ead0_FUN_0040ead0.md`
- Dual A/B: `reviews/A_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md`, `reviews/B_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md`
- Report: `docs/agents/task-dual-ab-0074e310-0040ead0-w38t-report.md`
