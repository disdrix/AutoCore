# Function record: BitStream_writeQuantizedFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b910` |
| **Canonical name** | `BitStream_writeQuantizedFloat` |
| **Address** | `0x0042b910` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Trampoline to FUN_0042b980 quantize+write.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
void BitStream_writeQuantizedFloat(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b910_BitStream_writeQuantizedFloat.md`
- Annotated: `docs/reconstruction/raw/aa_0042b910_BitStream_writeQuantizedFloat.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_writeQuantizedFloat.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
