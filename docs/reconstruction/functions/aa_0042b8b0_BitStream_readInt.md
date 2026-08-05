# Function record: BitStream_readInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8b0` |
| **Canonical name** | `BitStream_readInt` |
| **Address** | `0x0042b8b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

readBits + mask (except 32-bit full word).

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
uint BitStream_readInt(byte param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b8b0_BitStream_readInt.md`
- Annotated: `docs/reconstruction/raw/aa_0042b8b0_BitStream_readInt.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_readInt.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
