# Function record: BitStream_readFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ad50` |
| **Canonical name** | `BitStream_readFlag` |
| **Address** | `0x0042ad50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Read single flag bit; OOB returns false.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
bool __thiscall BitStream_readFlag(int param_1,uint8_t *param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042ad50_BitStream_readFlag.md`
- Annotated: `docs/reconstruction/raw/aa_0042ad50_BitStream_readFlag.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_readFlag.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
