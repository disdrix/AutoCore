# Function record: stoChunk_ConvertToInteger

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767600` |
| **Canonical name** | `stoChunk_ConvertToInteger` |
| **Name confidence** | **High** — plate `"Invalid integer length in ConvertToInteger()"` + `stoChunk.cpp` |
| **Ghidra** | `FUN_00767600` |
| **Address** | `0x00767600`–`0x007677f6` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 stoChunk |
| **Completion status** | **Dual A/B sealed** (W25-R 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept** |

## Alias

- Ghidra: `FUN_00767600`
- Prior: `Named_stoChunk_00767600`

## Purpose

Parse a decimal integer token from an MSVC `std::string` into a little-endian integer buffer of 1/2/4/8 bytes, with optional signed mode (leading `-`, abs range, then negate). Shared by all text-mode stoChunk integer readers.

## Signature (retail)

```c
// EAX = const std::string* text, stack (out, byteLen, signedMode), RET 12
int32_t stoChunk_ConvertToInteger(
    const std::string* text /*EAX*/,
    void* out,
    uint32_t byteLen,    // 1, 2, 4, or 8
    int32_t signedMode); // 0=unsigned, 1=signed
// returns 0 success, -1 failure
```

## Key facts

| Item | Value |
|---|---|
| Empty / non-digit | −1 |
| Unsigned max | 0xFF / 0xFFFF / 0xFFFFFFFF / u64 |
| Signed abs max | 0x7F / 0x7FFF / 0x7FFFFFFF / 0x7FFFFFFFFFFFFFFF |
| Bad length log lines | 0x3ab (unsigned), 0x3c3 (signed) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767600_FUN_00767600.md` |
| Annotated | `docs/reconstruction/raw/aa_00767600_FUN_00767600.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunk_ConvertToInteger.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_00767600.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_00767600_FUN_00767600.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00767600_stoChunk_ConvertToInteger.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00767600_stoChunk_ConvertToInteger.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `__allmul`, `isdigit`, `vog_LogMessage` |
| Callers | `FUN_00768260`…`FUN_00769660` incl. `stoChunkReader_TextReadU32` `0x007689e0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / decimal parse / range tables | **High** |
| ABI EAX + 3 stack + RET 12 | **High** |
| Product name ConvertToInteger | **High** |
| signedMode ∉ {0,1} path | **High** (no range check) |
| Runtime | **Open** |
