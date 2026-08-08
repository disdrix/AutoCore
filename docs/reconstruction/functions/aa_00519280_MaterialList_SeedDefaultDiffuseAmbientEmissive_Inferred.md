# Function record: MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519280` |
| **Canonical name** | `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` |
| **Ghidra name** | `FUN_00519280` |
| **Address** | `0x00519280` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / material param bank |
| **Completion status** | **Dual sealed** (WQ9R-E 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Seed destination float4 bank with default MatDiffuse/Ambient/Emissive colors per source material slot, then apply caller tint.

## Signature

```c
void MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred(
    void *srcMaterialOwner, void *dstVecHost,
    float r, float g, float b, float a);
```

## Dual A/B

| Review | Verdict |
|---|---|
| A | accept-with-gaps |
| B | accept-with-gaps |

## Artifacts

- Raw / annotated / clean / twin as listed on `aa_00519280_FUN_00519280.md`
- Agent report: `docs/agents/task-dual-ab-005190c0-00519280-wq9re-report.md`
