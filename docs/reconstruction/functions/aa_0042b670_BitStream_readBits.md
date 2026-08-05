# Function record: BitStream_readBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b670` |
| **Canonical name** | `BitStream_readBits` |
| **Address** | `0x0042b670` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-bitstream` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Core BitStream bit reader; OOB sets error@+0x1c.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ __thiscall BitStream_readBits(int param_1,uint param_2,byte *param_3)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0042b670_BitStream_readBits.md`
- Annotated: `docs/reconstruction/raw/aa_0042b670_BitStream_readBits.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BitStream_readBits.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
