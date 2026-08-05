# Function record: Client_RecvBroadcast

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810a80` |
| **Canonical name** | `Client_RecvBroadcast` |
| **Address** | `0x00810a80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network-sector` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C chat/broadcast handler; type@+4; dual-reviewed.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
void __thiscall Client_RecvBroadcast(int param_1,int param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00810a80_Client_RecvBroadcast.md`
- Annotated: `docs/reconstruction/raw/aa_00810a80_Client_RecvBroadcast.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvBroadcast.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
