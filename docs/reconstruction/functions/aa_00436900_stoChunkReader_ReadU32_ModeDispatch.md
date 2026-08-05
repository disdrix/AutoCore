# Function record: stoChunkReader_ReadU32_ModeDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436900` |
| **Canonical name** | `stoChunkReader_ReadU32_ModeDispatch` |
| **Prior / Ghidra name** | `FUN_00436900` |
| **Address** | `0x00436900`–`0x0043691a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `storage` / arda2 `stoChunk` |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W22-R OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00436900`
- Scaffold: `Named_CalleeOf_Named_anmAnimMaster_00436900`
- Mode dispatcher for binary `stoChunkReader_ReadU32` (`0x00437050`) vs text `FUN_007689e0`

## Purpose

Single-uint32 read dispatcher on `stoChunkReader`:

1. If `*(reader+0x4044) == 0` → binary LE dword via `stoChunkReader_ReadU32`.
2. Else → text token/parse path `FUN_007689e0` (reader in EDI; plate `stoChunk.cpp` / `"Expected uint32 but got \"%s\"..."`).
3. Return callee status in EAX (`0` / `0xffffffff`).

Body is a **27-byte** branch + two call sites; no local stream math.

## Signature (sealed)

```c
// EAX = StoChunkReader*, ECX = uint32_t* out, plain RET
// Returns 0 success, 0xffffffff fail.
int32_t stoChunkReader_ReadU32_ModeDispatch(/* EAX reader */, /* ECX */ uint32_t* out);
```

## Mode field

| Reader off | Role |
|---:|---|
| `+0x4044` | 0 = binary; ≠0 = text (integer compare only in this unit) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00436900_FUN_00436900.md` |
| Annotated | `docs/reconstruction/raw/aa_00436900_FUN_00436900.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_ReadU32_ModeDispatch.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00436900.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00436900_stoChunkReader_ReadU32_ModeDispatch.md` |
| Function alias | `docs/reconstruction/functions/aa_00436900_FUN_00436900.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `stoChunkReader_ReadU32` / `FUN_00437050` | `0x00437050` binary |
| Callee | `FUN_007689e0` | `0x007689e0` text uint32 |
| Caller | `gfxGeometryPiece_Unserialize` | 4 call sites |
| Caller | `gfxVertexBufferImpl_Unserialize` | 1+ |
| Caller | `FUN_0095ef50` | 7 call sites |
| Caller | `FUN_00964690` | 1 |
| Caller | site `0x0095ffc2` | xref |

## Confidence

| Claim | Level |
|---|---|
| CF: mode gate → binary or text call | **High** |
| EAX=reader, ECX=out, plain ret | **High** |
| Callee identities (rel32) | **High** |
| Return status in EAX (not void) | **High** |
| Product English plate name | **Inferred** |
| Runtime / bit-exact | **Open** |
