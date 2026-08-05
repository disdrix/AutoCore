# Function record: CVOGSectorMap_RemoveCharacter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9b50` |
| **Canonical name** | `CVOGSectorMap_RemoveCharacter_Inferred` |
| **Address** | `0x004d9b50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | sector-map |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004d9b50`
- Prior: `Named_CalleeOf_Named_VOGClient_004d9b50`

## Purpose

Erase character* from sector map vector `+0xe75c/+0xe760` (inverse of `CVOGSectorMap_AddCharacter`). Optional `+0xf6` secondary set rebuild; sole-remaining notify when set size==1.

## Signature

```c
void /*fastcall/thiscall*/ CVOGSectorMap_RemoveCharacter_Inferred(void *sectorMap /*, Object *who */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d9b50_FUN_004d9b50.md`
- Annotated: `docs/reconstruction/raw/aa_004d9b50_FUN_004d9b50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004d9b50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md`

## Callers / callees

- Callers: `FUN_009440e0`, `FUN_00943db0`, `FUN_0052f260`
- Callees: `FUN_0049c5f0`, `memmove`, set helpers `0040f400`/`0040ed60`/`0040f2a0`, `FUN_004bb1c0`

## Confidence

| Claim | Level |
|---|---|
| Vector erase role | **Confirmed** |
| Flag-gated reindex | **Confirmed** |
| Product name | **Open** |
