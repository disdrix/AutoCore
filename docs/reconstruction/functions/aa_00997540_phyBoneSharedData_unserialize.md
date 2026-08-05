# Function record: phyBoneSharedData_unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00997540` |
| **Canonical name** | `phyBoneSharedData_unserialize` |
| **Address** | `0x00997540` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics / phy` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

BDAT (TADB) hkQsTransform nested in PBON.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
/* phyBoneSharedData::unserialize  (BDAT / file tag TADB = 0x42444154)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00997540_phyBoneSharedData_unserialize.md`
- Annotated: `docs/reconstruction/raw/aa_00997540_phyBoneSharedData_unserialize.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/phyBoneSharedData_unserialize.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Parameter semantic names | Probable / Tentative until caller pass |
| Types | Tentative |
