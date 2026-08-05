# Function record: CVOGPhysics_ApplyImpulseVector

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d260` |
| **Canonical name** | `CVOGPhysics_ApplyImpulseVector` |
| **Address** | `0x0040d260` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics / CVOGPhysics` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Apply linear impulse/vel via body vtbl+0x50.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
void __thiscall CVOGPhysics_ApplyImpulseVector(int param_1,uint32_t /* width from decompiler */ param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d260_CVOGPhysics_ApplyImpulseVector.md`
- Annotated: `docs/reconstruction/raw/aa_0040d260_CVOGPhysics_ApplyImpulseVector.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysics_ApplyImpulseVector.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
