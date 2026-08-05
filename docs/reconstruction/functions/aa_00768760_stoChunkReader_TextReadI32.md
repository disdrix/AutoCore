# Function record: stoChunkReader_TextReadI32

| Field | Value |
|---|---|
| **Stable ID** | `aa_00768760` |
| **Canonical name** | `stoChunkReader_TextReadI32` |
| **Name confidence** | **Inferred** — plate `"Expected int32…"`; `FUN_00767600(out,4,1)`; peer of `TextReadU32` |
| **Ghidra** | `FUN_00768760` |
| **Address** | `0x00768760`–`0x007689D0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Completion status** | **Dual A/B sealed** (W38-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_00768760`
- Unsigned peer: `stoChunkReader_TextReadU32` @ `0x007689e0`
- Parse helper: `stoChunk_ConvertToInteger` @ `0x00767600`
- Binary dual (common): `stoChunkReader_ReadU32` @ `0x00437050`

## Purpose

Text-mode read of one **signed int32** from a stoChunk reader: scan or pushback token, parse signed 4-byte integer, return 0/−1; log on type mismatch or past-end `}`.

## Signature (retail)

```c
// EDI = reader, stack = int32_t* out, RET 4
int32_t stoChunkReader_TextReadI32(StoChunkReader* reader /*EDI*/, int32_t* out);
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
| Raw | `docs/reconstruction/raw/aa_00768760_FUN_00768760.md` |
| Annotated | `docs/reconstruction/raw/aa_00768760_FUN_00768760.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadI32.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_00768760.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00768760_stoChunkReader_TextReadI32.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00768760_stoChunkReader_TextReadI32.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `FUN_00435df0`, `FUN_00767600`, `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `isspace`, `std::string` |
| Callers | 98 xrefs across text-mode dual I/O |

## Confidence

| Claim | Level |
|---|---|
| Text int32 peer + ABI EDI/stack/ret4 | **High** |
| Token scan / pushback / `}` / error format | **High** |
| `FUN_00767600` exact parse rules | **Probable** |
| Product English name | **Inferred** |
| Runtime | **Open** |
