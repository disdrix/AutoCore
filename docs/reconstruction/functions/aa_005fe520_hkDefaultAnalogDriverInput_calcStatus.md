# Function record: hkDefaultAnalogDriverInput_calcStatus

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe520` |
| **Canonical name** | `hkDefaultAnalogDriverInput_calcStatus` |
| **Address** | `0x005fe520` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* WI-MOV-005: maps ctrl+0x20 raw pedal into status. Accel(-1)→+0xc |pedal|; positive→+0x10
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005fe520_hkDefaultAnalogDriverInput_calcStatus.md`
- Annotated: `docs/reconstruction/raw/aa_005fe520_hkDefaultAnalogDriverInput_calcStatus.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_calcStatus.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
