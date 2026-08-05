# Function record: BitStream_writeInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8f0` |
| **Canonical name** | `BitStream_writeInt` |
| **Address** | `0x0042b8f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

writeBits wrapper for integer bitCount.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
void BitStream_writeInt(uint32_t /* width from decompiler */ param_1,uint8_t param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b8f0_BitStream_writeInt.md`
- Annotated: `docs/reconstruction/raw/aa_0042b8f0_BitStream_writeInt.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_writeInt.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
