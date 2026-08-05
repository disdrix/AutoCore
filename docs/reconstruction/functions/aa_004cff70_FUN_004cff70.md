# Function record: CVOGMap_MarchDirToTerrain_Inferred (`FUN_004cff70`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cff70` |
| **Canonical name** | `CVOGMap_MarchDirToTerrain_Inferred` (Ghidra: `FUN_004cff70`) |
| **Address** | `0x004cff70` |
| **Body** | `004cff70` – `004d01bf` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `world-terrain` (consumers: input-drive-control, interaction-activation) |
| **Completion status** | **Partial** — three-rep present; **dual A/B 2026-07-29** accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_004cff70`
- Scaffold alias: `Named_CalleeOf_Client_Input_DriveControlTick_004cff70` (incomplete — also pick + `FUN_005995a0`)
- Dual: `CVOGMap_MarchDirToTerrain_Inferred`

## Purpose

March a `float4` start along a `float4` per-step direction against the map **heightfield** (`map+0xe4e0` → `FUN_005a58c0` sample). Returns **1** when a stepped probe first sits at/below HF Y (with optional X/Z abs-ratio blend); **0** on null HF / exhausted steps. Supports buried-start emerge-then-hit. **Not** `CVOGMap_CastTerrainHeight` (no collision cast, not float Y).

## Signature (recovered)

```c
// __thiscall; RET 0x10
int CVOGMap_MarchDirToTerrain_Inferred(
    CVOGMap* this,   // ECX
    float* start,    // float4
    float* dir,      // float4 step delta
    float* outHit,   // float4
    int maxSteps     // callers: 400
);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cff70_FUN_004cff70.md`
- Annotated: `docs/reconstruction/raw/aa_004cff70_FUN_004cff70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004cff70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004cff70_CVOGMap_MarchDirToTerrain_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004cff70_CVOGMap_MarchDirToTerrain_Inferred.md`
- Sibling: `docs/reconstruction/physics/verified/fn_004cfe60_castTerrain.md`

## Callers / callees

**Callers (5 xrefs):**

| Address | Function |
|---|---|
| `0x00922848`, `0x00923328` | `Client_Input_DriveControlTick` |
| `0x0092496b`, `0x00924c26` | `Client_InteractClickPickTarget` |
| `0x0059964d` | `FUN_005995a0` |

**Callees:** `FUN_005a58c0` only (HF bilinear sample).

## Confidence

| Claim | Level |
|---|---|
| Control flow (gate, bury/emerge, surface hit, bool) | **High** |
| `map+0xe4e0` HF gate; sample (x,z) | **High** |
| ABI thiscall + RET 0x10 + maxSteps | **High** |
| Caller maxSteps=400 | **High** |
| Distinct from CastTerrainHeight | **High** |
| Product English name | **Open** (`_Inferred`) |
| Hit X/Z blend non-identity | **Probable residual** |
