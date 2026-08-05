# Function record: stoChunkReader_TextReadU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007689e0` |
| **Canonical name** | `stoChunkReader_TextReadU32` |
| **Name confidence** | **Inferred** — text peer of sealed `stoChunkReader_ReadU32`; error string `"Expected uint32…"`; path `stoChunk.cpp` |
| **Ghidra** | `FUN_007689e0` |
| **Address** | `0x007689e0`–`0x00768c50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Completion status** | **Dual A/B sealed** (W22-Q 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_007689e0`
- Prior scaffold: `Named_stoChunk_007689e0`
- Binary peer: `stoChunkReader_ReadU32` @ `0x00437050`

## Purpose

Text-mode read of one **uint32** from a stoChunk reader: scan or pushback token, parse via `FUN_00767600(out,4,0)`, return 0/−1; log on type mismatch or past-end `}`.

## Signature (retail)

```c
// EDI = reader, stack = uint32_t* out, RET 4
int32_t stoChunkReader_TextReadU32(StoChunkReader* reader /*EDI*/, uint32_t* out);
// returns 0 success, 0xffffffff fail
```

## Key offsets

| Off | Field |
|---|---|
| `+0x18` | cursor |
| `+0x1c` | base |
| `+0x20` | available |
| `+0x2c` | buffer |
| `+0x402c` | sticky status |
| `+0x404c` | pushback string |
| `+0x4060` | pushback-active flag |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007689e0_FUN_007689e0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadU32.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_007689e0.cpp` |
| Prior scaffold | `docs/reconstruction/reconstructed-exact/Named_stoChunk_007689e0.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_007689e0_FUN_007689e0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_007689e0_stoChunkReader_TextReadU32.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007689e0_stoChunkReader_TextReadU32.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `FUN_00435df0`, `FUN_00767600`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `isspace`, `std::string` |
| Callers | `FUN_00436900` (mode dispatcher); `stoChunkReader_OpenChunk`; many unserializers |

## Confidence

| Claim | Level |
|---|---|
| Text uint32 peer + ABI EDI/stack/ret4 | **High** |
| Token scan / pushback / `}` / error format | **High** |
| `FUN_00767600` exact parse rules | **Probable** |
| Product English name | **Inferred** |
| Runtime | **Open** |
