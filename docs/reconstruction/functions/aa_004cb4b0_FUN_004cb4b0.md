# Function record: FUN_004cb4b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4b0` |
| **Canonical name** | `FUN_004cb4b0` (scaffold; prefer `StdMap_LowerBound_Tfid_Isnil29`) |
| **Address** | `0x004cb4b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC map lower_bound |
| **Completion status** | **Dual-reviewed** W31-N — **accept-with-gaps** (see named record) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

Canonical: `StdMap_LowerBound_Tfid_Isnil29`.  
**Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb4b0`.

## Purpose

See `aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md`.

## Signature

```c
Node_Isnil29* __fastcall FUN_004cb4b0(MapHost_Head4* self, const KeyU32I32* pKey);
```

## Artifacts

- Named: `docs/reconstruction/functions/aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md`
- Raw: `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.md`
- Annotated: `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_LowerBound_Tfid_Isnil29.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004cb4b0.cpp`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004c8970`, `FUN_004ca760`, `FUN_004cba00`, `FUN_004cc400`, `FUN_005a0470` |
| Callees | none |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Product map type | **Low** |
