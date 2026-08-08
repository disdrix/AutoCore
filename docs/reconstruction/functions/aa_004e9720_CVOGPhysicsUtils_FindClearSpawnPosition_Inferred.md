# Function record: CVOGPhysicsUtils_FindClearSpawnPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9720` |
| **Canonical name** | `FUN_004e9720` |
| **Proposed name** | `CVOGPhysicsUtils_FindClearSpawnPosition_Inferred` |
| **Address** | `0x004e9720`–`0x004e9a9b` (892 B / `0x37C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Parent dual** | `0x005eb790` `VOGPhysics_QueryCollect_Ctor_Inferred` |
| **Partition** | R13-027 |
| **Completion status** | **Dual sealed (accept-with-gaps)** — first dual A/B 2026-08-05 |
| **Bit-for-bit / runtime / diff** | Open (never Runtime Confirmed) |
| **Prior scaffold** | `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720` (**retired**) |

## Purpose

cdecl helper: sphere-query probe for a **collision-clear spawn/placement float4**. Builds temporary sphere shape + parent query-collect, registers on `host+0xE4A4`, retries with random XZ scatter + height resample until zero hits or attempts exhausted. Returns bool found-clear.

## Signature (assembly-sealed)

```c
bool __cdecl CVOGPhysicsUtils_FindClearSpawnPosition_Inferred(
    void *host,
    float *in_pos /* float4 */,
    float scatter_radius,
    float sphere_radius,
    float *out_pos /* float4 */,
    uint32_t query_cookie,
    unsigned char max_attempts,
    unsigned char keep_last_on_fail);
// bare RET; AL = found clear
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e9720_FUN_004e9720.md`
- Annotated: `docs/reconstruction/raw/aa_004e9720_FUN_004e9720.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004e9720.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md`
- Report: `docs/agents/task-dual-ab-004e9720-r13-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (4) | `CVOGSpawnPoint_CreateCreature`, `CVOGSpawnPoint_CreateTemplateVehicle`, `FUN_00522f70`, `FUN_005cc7f0` |
| Callees | `006c7fa0`, `005eb8d0`, **`005eb790`**, `0055ff20`, `005eb130`, `007a4330`, `004cd220`, `00560020`, `004eacc0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI + bool return | **High** |
| Clear-spawn probe role | **High** |
| Product method English | **Med / Inferred** |
| Runtime Confirmed | **Open — not claimed** |
