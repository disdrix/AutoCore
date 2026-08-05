# Function record: stoChunkReader_TextReadBool

| Field | Value |
|---|---|
| **Stable ID** | `aa_00769660` |
| **Canonical name** | `stoChunkReader_TextReadBool` |
| **Name confidence** | **Inferred** — error string `"Expected bool…"`; text peer via `FUN_00439a50`; parse `ConvertToInteger(out,1,0)` |
| **Ghidra** | `FUN_00769660` |
| **Address** | `0x00769660`–`0x007698d0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Completion status** | **Dual A/B sealed** (W38-J 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept** |

## Alias

- Ghidra: `FUN_00769660`
- Prior scaffold: `Named_stoChunk_00769660`
- Binary peer: `FUN_00437000` (via dispatcher `FUN_00439a50`)
- Family twin: `stoChunkReader_TextReadU32` @ `0x007689e0` (byteLen 4 vs 1)

## Purpose

Text-mode read of one **bool** (1-byte integer 0/1 via ConvertToInteger) from a stoChunk reader: scan or pushback token, parse, return 0/−1; log on type mismatch or past-end `}`.

## Signature (retail)

```c
// EDI = reader, stack = uint8_t* out, RET 4
int32_t stoChunkReader_TextReadBool(StoChunkReader* reader /*EDI*/, uint8_t* out);
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
| Raw | `docs/reconstruction/raw/aa_00769660_FUN_00769660.md` |
| Annotated | `docs/reconstruction/raw/aa_00769660_FUN_00769660.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadBool.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_00769660.cpp` |
| Prior scaffold | `docs/reconstruction/reconstructed-exact/Named_stoChunk_00769660.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_00769660_FUN_00769660.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00769660_stoChunkReader_TextReadBool.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00769660_stoChunkReader_TextReadBool.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `FUN_00435df0`, `FUN_00767600` (`stoChunk_ConvertToInteger`), `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `isspace`, `std::string` |
| Callers (8 funcs) | `FUN_00439a50` (mode dispatcher), `FUN_0072c860`, `FUN_00739c80`, `FUN_0074ce60`, `FUN_0075a980`, `FUN_00765740`, `FUN_00963fb0`, `FUN_00964690` |

## Confidence

| Claim | Level |
|---|---|
| Text bool peer + ABI EDI/stack/ret4 | **High** |
| Token scan / pushback / `}` / error format | **High** |
| `FUN_00767600(out,1,0)` call shape | **High** |
| Product English name | **Inferred** |
| Runtime | **Open** |
