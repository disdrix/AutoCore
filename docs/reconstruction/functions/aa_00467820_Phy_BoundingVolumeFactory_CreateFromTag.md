# Function record: Phy_BoundingVolumeFactory_CreateFromTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467820` |
| **Canonical name** | `Phy_BoundingVolumeFactory_CreateFromTag` |
| **Address** | `0x00467820` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `physics / phy` |
| **Completion status** | **Human-refined plate** — Purpose/CF/offsets; dual reviews where present; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_00467820`
- Prior auto-slug names (if any): leave on disk; canonical is `Phy_BoundingVolumeFactory_CreateFromTag`

## Purpose

Bounding-volume factory create-by-tag.

See clean plate for CF summary and key offsets.

## Signature (decompiler-derived)

```c
uint32_t /* width from decompiler */ * __fastcall Phy_BoundingVolumeFactory_CreateFromTag(void *param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00467820_FUN_00467820.md`
- Annotated: `docs/reconstruction/raw/aa_00467820_FUN_00467820.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Phy_BoundingVolumeFactory_CreateFromTag.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_00467820.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
