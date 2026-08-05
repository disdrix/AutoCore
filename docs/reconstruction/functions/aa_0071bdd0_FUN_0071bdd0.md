# Function record: FUN_0071bdd0 (alias)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bdd0` |
| **Canonical name** | `DES_BuildSBoxLookupTables` |
| **Scaffold name** | `FUN_0071bdd0` |
| **Address** | `0x0071bdd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth / DES |
| **Completion status** | **Dual A/B sealed** 2026-07-29 (W19-P) — see canonical record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

See `aa_0071bdd0_DES_BuildSBoxLookupTables.md`. Builds DES S-box lookup banks for `DES_CalculateSBoxSubstitution`.

## Signature (decompiler-derived)

```c
void FUN_0071bdd0(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.md`
- Annotated: `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/DES_BuildSBoxLookupTables.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0071bdd0.cpp`

## Callers / callees

Sole caller `DES_InitializeCipher`. Leaf vs code; writes BSS LUT banks.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Parameter semantic names | N/A (void) |
| Types | **High** for tables; pedagogical S-box pair map open |
