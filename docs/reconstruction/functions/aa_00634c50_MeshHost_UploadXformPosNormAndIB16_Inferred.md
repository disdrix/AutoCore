# Function record: MeshHost_UploadXformPosNormAndIB16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634c50` |
| **Canonical name** | `MeshHost_UploadXformPosNormAndIB16_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00634c50` |
| **Address** | `0x00634c50` |
| **Body** | `0x00634c50`–`0x00634df8` exclusive (**424 B** / `0x1A8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | mesh / gfx upload (CVOGObject optional mesh-host tick) |
| **Completion status** | **Dual-reviewed** WQ9J-D — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Thiscall-style **fastcall** worker on a mesh-upload host: dirty owner flags at `+0xBC`, lock VB, copy owner xform into a stack FieldBlock via `FUN_00416240`, transform host source pos/nrm into FVF channels (usage 0 and 3), unlock VB (`gfxDeviceVB.cpp`), lock IB with flags `0x800`, pack source u32 indices to u16, unlock IB (`gfxDeviceIB.cpp`).

Host fields: `+0x0C` owner*, `+0x10` pos*, `+0x14` nrm*, `+0x18` vertCount, `+0x1C` idx_u32*, `+0x20` idxCount.

## Signature

```c
// ECX = MeshUploadHost*
void __fastcall MeshHost_UploadXformPosNormAndIB16_Inferred(void* host);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00595230` (`CVOGObject_Tick`) @ `0x005952a9` — table at object `+0x1c4`, gated by `+0x90d` bit1 |
| Callees | `FUN_00414ae0`, `FUN_0044bcc0`, `FUN_00437960`, `FUN_00416240` (WQ9I-H), `FUN_007468e0`×2, `FUN_009732d0`, `FUN_00973240`, `FUN_007464e0`, `FUN_0044ba40`, `FUN_00743ba0` |

## Artifacts

- Raw (+ WQ9J-D append): `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.md`
- Annotated: `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/MeshHost_UploadXformPosNormAndIB16_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00634c50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00634c50_FUN_00634c50.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ECX host + gate offsets | **High** |
| VB then IB upload | **High** |
| FieldBlock temp use | **High** |
| Device-wrapper exact types | **Med** |
| Product class English | **Open** |
