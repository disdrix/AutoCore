# Function record: CVOGCharacter_SetAreaExploredBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_005326b0` |
| **Canonical name** | `CVOGCharacter_SetAreaExploredBit` |
| **Address** | `0x005326b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Partial scaffold** — raw/annotated/clean present; refine + dual review for important units |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reconstructed from Ghidra decompile. See clean source and annotated notes for body.

## Signature (decompiler-derived)

```c
/* Set/clear one explored-area bit on local character, LogicUI notify type 0x20.
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005326b0_CVOGCharacter_SetAreaExploredBit.md`
- Annotated: `docs/reconstruction/raw/aa_005326b0_CVOGCharacter_SetAreaExploredBit.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetAreaExploredBit.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
