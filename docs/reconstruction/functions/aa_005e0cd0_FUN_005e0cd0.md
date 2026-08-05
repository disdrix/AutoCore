# Function record: LootCatalog_FillCandidateIds_QualityTypeBand_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0cd0` |
| **Canonical name** | `LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` |
| **Address** | `0x005e0cd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory / loot catalog (filtered-roll fill) |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 (accept-with-gaps) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_005e0cd0`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_005e0cd0`

## Purpose

Alternate catalog fill for filtered roll (`005e1150`): quality/type banded tables at catalog `+0x10e00c` / `+0x10e13c`, random band bias `005e0590`, range copy `005e1860`. Returns 1 if out-vector non-empty.

## Signature

```c
// __thiscall; ret 0x18
int __thiscall LootCatalog_FillCandidateIds_QualityTypeBand_Inferred(
    void *catalog, int typeCode, void *outVector,
    int qualityOrA, int typeOrB, int outVectorOrSentinel);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005e0cd0_FUN_005e0cd0.md`
- Annotated: `docs/reconstruction/raw/aa_005e0cd0_FUN_005e0cd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005e0cd0.cpp`
- Dual: `reviews/A_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred.md`
- Dual: `reviews/B_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred.md`

## Callers / callees

- Callers: `FUN_005e1150` only (live)
- Callees: `FUN_005e0480`, `FUN_005e0590`, `FUN_0040f5b0`, `FUN_00410420`, `FUN_005e1860`

## Confidence

| Claim | Level |
|---|---|
| Fill-not-pick; emptiness return | Confirmed |
| Distinct tables from `005e07d0` | Confirmed |
| Extra stack formal / ESI bias residual | Tentative / Probable |
