# Function record: stoChunkReader_TextReadString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076a200` |
| **Canonical name** | `stoChunkReader_TextReadString` |
| **Name confidence** | **Inferred** — error string `"Expected string…"`; wraps sealed `ReadQuotedTag`; text peer via `FUN_00439a20` |
| **Ghidra** | `FUN_0076a200` |
| **Address** | `0x0076a200`–`0x0076a2b5` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Completion status** | **Dual A/B sealed** (W38-J 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept** |

## Alias

- Ghidra: `FUN_0076a200`
- Prior scaffold: `Named_stoChunk_0076a200`
- Binary peer: `FUN_00436f10` (via dispatcher `FUN_00439a20`)
- Inner helper: `stoChunkReader_ReadQuotedTag` @ `0x00769b70` (W25-S)

## Purpose

Text-mode read of one **quoted string** into a caller `std::string`: delegate to ReadQuotedTag (strict double-quote strip); on failure log type mismatch with token + chunk name.

## Signature (retail leaf)

```c
// ECX = std::string* out, EBX = StoChunkReader* reader, plain RET
int32_t stoChunkReader_TextReadString(std::string* out /*ECX*/,
                                      StoChunkReader* reader /*EBX*/);
// returns 0 success, 0xffffffff fail
```

Mode dispatcher `FUN_00439a20` additionally uses **stack reader** + **`ret 4`** for the public dual-mode entry.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.md` |
| Annotated | `docs/reconstruction/raw/aa_0076a200_FUN_0076a200.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_TextReadString.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_0076a200.cpp` |
| Prior scaffold | `docs/reconstruction/reconstructed-exact/Named_stoChunk_0076a200.cpp` |
| Function (Ghidra) | `docs/reconstruction/functions/aa_0076a200_FUN_0076a200.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0076a200_stoChunkReader_TextReadString.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076a200_stoChunkReader_TextReadString.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callees | `FUN_00769b70` (ReadQuotedTag), `FUN_00436250`, `FUN_0076cec0`, `vog_LogMessage`, `std::string` dtor |
| Callers (sample) | `FUN_00439a20` (dispatcher), `effEffect_Unserialize`, `phyBoneSharedData_unserialize`, `FUN_00458a30`, `FUN_004590a0`, `FUN_00459750`, many gfx/anim/string field readers (53 CODE xrefs) |

## Confidence

| Claim | Level |
|---|---|
| ECX out + EBX reader + C3 + 0/−1 | **High** |
| ReadQuotedTag-only success path | **High** |
| Expected-string fail log | **High** |
| Product English name | **Inferred** |
| Runtime | **Open** |
