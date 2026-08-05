# Function record: BitStream_GrowForBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b450` |
| **Canonical name** | `BitStream_GrowForBits` |
| **Address** | `0x0042b450` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Ensure the BitStream buffer can accept `extraBits` additional write bits past `+0x30` capacity. Computes `NewSize = ((extraBits + bitCap + 7) >> 3) + 0x5DC` bytes; if allocated size at `+0x10` is smaller and owns-buffer flag `+0x14` is set, `realloc`s buffer at `+0x0c`, sets `+0x10 = NewSize` and both bit caps `+0x2c/+0x30 = NewSize*8`, returns 1. Otherwise sets error `+0x1c=1` and returns 0.

See clean plate for CF summary and key offsets.

## Signature (behavior)

```c
// EDI = BitStream* this; ECX = extraBits; AL = success
uint8_t BitStream_GrowForBits(int extraBits, BitStream* self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.md`
- Annotated: `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_GrowForBits.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0042b450.cpp`
- Dual reviews:
  - `docs/reconstruction/reviews/A_aa_0042b450_BitStream_GrowForBits.md`
  - `docs/reconstruction/reviews/B_aa_0042b450_BitStream_GrowForBits.md`

## Callers / callees

- Callee: `realloc`
- Callers: `BitStream_writeBits` (overflow bits), `BitStream_writeFlag` (ECX=1), string/int pack helpers

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes | High |
| Role = write-side grow | High |
| ABI EDI/ECX/AL | High |
| No realloc NULL check | High |
| Product symbol string | Tentative |
