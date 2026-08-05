# Function record: stoChunkReader_TestAndPopSoftSkipBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767570` |
| **Canonical name** | `stoChunkReader_TestAndPopSoftSkipBit` |
| **Name confidence** | **Inferred** — soft-skip bitset peer of sealed `stoChunkReader_SoftSkipIfBitSet`; pop via resize |
| **Ghidra** | `FUN_00767570` |
| **Address** | `0x00767570`–`0x007675BD` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | storage / arda2 `stoChunk` |
| **Completion status** | **Dual A/B sealed** (W38-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_00767570`
- Prior scaffold: `Named_CalleeOf_Named_gfxBody_00767570` (**reject**)
- Test-only peer: `stoChunkReader_SoftSkipIfBitSet` @ `0x00767120`

## Purpose

Test the soft-skip bitset top bit `(size-1)` and shrink the bitset size by one (pop). Returns whether the bit was set prior to the pop.

## Signature (retail)

```c
// EDI = StoSoftSkipView*, plain RET, AL = bool
bool stoChunkReader_TestAndPopSoftSkipBit(StoSoftSkipView* view /*EDI*/);
```

## Key offsets

| Off | Field |
|---|---|
| `+0` | size / id (bit count) |
| `+8` | bitset word base |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767570_FUN_00767570.md` |
| Annotated | `docs/reconstruction/raw/aa_00767570_FUN_00767570.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/stoChunkReader_TestAndPopSoftSkipBit.cpp` |
| Clean (Ghidra alias) | `docs/reconstruction/reconstructed-exact/FUN_00767570.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00767570_stoChunkReader_TestAndPopSoftSkipBit.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00767570_stoChunkReader_TestAndPopSoftSkipBit.md` |

## Callers / callees

| Kind | Target |
|---|---|
| Callee | `FUN_004362c0` |
| Caller | `FUN_00765740` (gfxBody unserialize) ×1 |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + pop side-effect | **High** |
| Soft-skip English / product name | **Inferred** |
| Why sole caller ignores return | **Open** |
| Runtime | **Open** |
