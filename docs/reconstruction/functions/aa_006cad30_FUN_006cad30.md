# Function record: FUN_006cad30

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad30` |
| **Canonical name** | `LinkPair_CanonAndSort_Inferred` (preferred) / `FUN_006cad30` |
| **Address** | `0x006cad30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / bind link-pair list prep |
| **Completion status** | **partial** — dual A/B **accept** (W28-Q) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `LinkPair_CanonAndSort_Inferred`
- Legacy: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006cad30` (**narrow**)

## Purpose

Canon within-pair keys then sort pair array. See named function record.

## Signature (decompiler-derived)

```c
void FUN_006cad30(int param_1, uint param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.md`
- Annotated: `docs/reconstruction/raw/aa_006cad30_FUN_006cad30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LinkPair_CanonAndSort_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006cad30.cpp`
- Named: `docs/reconstruction/functions/aa_006cad30_LinkPair_CanonAndSort_Inferred.md`
- A/B: `docs/reconstruction/reviews/A_aa_006cad30_LinkPair_CanonAndSort_Inferred.md`, `B_aa_006cad30_LinkPair_CanonAndSort_Inferred.md`
- Report: `docs/agents/task-dual-ab-0053a8e0-006cad30-w28q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_006cac60` |
| **Callers** | `FUN_006297e0` ×2, `FUN_00634450` ×2, `FUN_0055ff20`, `FUN_00560020` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Parameter semantic names | Probable (array, count) |
| Types | Tentative (void* pair objects) |
