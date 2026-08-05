# Function record: BitStream_writeBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b4a0` |
| **Canonical name** | `BitStream_writeBits` |
| **Address** | `0x0042b4a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Core BitStream bit writer (LSB-first); grow via `FUN_0042b450`; dual-reviewed.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __thiscall BitStream_writeBits(int param_1,byte *param_2,byte *param_3)
```

Note: decompiler types `param_2` as `byte*` but body uses it as integer bit count.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b4a0_BitStream_writeBits.md`
- Annotated: `docs/reconstruction/raw/aa_0042b4a0_BitStream_writeBits.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_writeBits.cpp`
- Dual reviews:
  - `docs/reconstruction/reviews/A_aa_0042b4a0_BitStream_writeBits.md`
  - `docs/reconstruction/reviews/B_aa_0042b4a0_BitStream_writeBits.md`

## Callers / callees

- Callee: `FUN_0042b450` (grow)
- Callers: `BitStream_writeInt`, packers via bit helpers

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| param_2 is bit count (not pointer) | Medium (body evidence; decomp type wrong) |
| Types | Tentative |
