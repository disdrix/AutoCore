# Function record: BitStream_writeFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b770` |
| **Canonical name** | `BitStream_writeFlag` |
| **Address** | `0x0042b770` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write single flag bit; grow or silent fail.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
void __thiscall BitStream_writeFlag(int param_1,char param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b770_BitStream_writeFlag.md`
- Annotated: `docs/reconstruction/raw/aa_0042b770_BitStream_writeFlag.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_writeFlag.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
