# Function record: Math_ComposeOptionalTRSMatrix_Inferred (`FUN_0076f970`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f970` |
| **Canonical name** | `Math_ComposeOptionalTRSMatrix_Inferred` |
| **Ghidra name** | `FUN_0076f970` |
| **Address** | `0x0076f970` |
| **Body** | `0x0076f970`–`0x0076fc93` (0x323 bytes; cdecl `ret`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | math / graphics transforms (GfxNode + skeleton) |
| **Completion status** | **Dual A/B sealed** (W18-P, 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunker_SubmitForRende_0076f970`
- Ghidra: `FUN_0076f970`

## Purpose

**Compose a 4×4 matrix** from optional translation / rotation / scale components, left-multiplying stages onto a dest buffer. Primary client entry is GfxNode dirty rebuild (`GfxNode_ComposeWorldMatrix_ClearDirty` @ `0x00972e50`), which reduces to **S · R · T** into the node base matrix.

## Signature (machine)

```c
// EAX = float3* tA optional
// ECX = float3* tB optional
// cdecl stack (caller ADD ESP,0x14):
//   float4x4* dest
//   float4*   rOuter   // quat; also builds inverse
//   float3*   scale
//   float4*   rInner   // quat
//   float3*   translation
// return dest*
float4x4 *Math_ComposeOptionalTRSMatrix_Inferred(...);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076f970_FUN_0076f970.md`
- Annotated: `docs/reconstruction/raw/aa_0076f970_FUN_0076f970.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Math_ComposeOptionalTRSMatrix_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0076f970.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0076f970_Math_ComposeOptionalTRSMatrix_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0076f970_FUN_0076f970.md`

## Callers / callees

**Callees:** `FUN_00412d80`, `FUN_0076eb00`, `FUN_0076e6b0`

**Callers:**

| VA | Role |
|---|---|
| `0x00972e50` | GfxNode compose + clear dirty bit0 @+0xBC |
| `0x00965290` | radius query; inline dirty compose |
| `0x0096b470` | skeleton / bone matrix path (via `00972e50` and direct) |
| `0x00765170` | static geometry / GPCE clone path |

## Confidence

| Claim | Level |
|---|---|
| Compose stage order + null skips | **Confirmed** (decompile + mul call sequence) |
| GfxNode arg map + S·R·T reduction | **Confirmed** (caller bytes + zero global) |
| Identity base `DAT_00afdf70` | **Confirmed** (`read_memory`) |
| cdecl 5 stack args | **Confirmed** (`ADD ESP,0x14`) |
| Product English name | **Probable** / `_Inferred` |
| Runtime matrix samples | **Open** |
