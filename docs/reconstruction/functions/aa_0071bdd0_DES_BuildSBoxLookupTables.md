# Function record: DES_BuildSBoxLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bdd0` |
| **Canonical name** | `DES_BuildSBoxLookupTables` |
| **Address** | `0x0071bdd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth / DES |
| **Completion status** | **Dual A/B sealed** 2026-07-29 (W19-P) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run); filled-table golden vectors open |

## Alias

| Name | Role |
|------|------|
| `FUN_0071bdd0` | Ghidra / scaffold |

## Purpose

One-shot **DES S-box LUT builder**. Expands FIPS S-box nibble tables (`DAT_00afcb48` / `DAT_00afcb88`) into four **0x1000-byte** runtime banks at `DAT_00d12e90`..`DAT_00d15e90` consumed by `DES_CalculateSBoxSubstitution`.

## Signature (sealed)

```c
void DES_BuildSBoxLookupTables(void);
// no args; ret
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.md` (+ 2026-07-29 live)
- Annotated: `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/DES_BuildSBoxLookupTables.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0071bdd0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0071bdd0_DES_BuildSBoxLookupTables.md`
- Review B: `docs/reconstruction/reviews/B_aa_0071bdd0_DES_BuildSBoxLookupTables.md`

## Callers / callees

| Direction | Target | Notes |
|-----------|--------|-------|
| Caller | `DES_InitializeCipher` @ `0x0071c06b` | sole UNCONDITIONAL_CALL |
| Callees | none | leaf; only DAT_* reads/writes |
| Sibling (not owned) | `FUN_0071b5a0` (`aa_0071b5a0`, W19-Q) | next init step after this |
| Consumer | `DES_CalculateSBoxSubstitution` (`aa_0071ba90`) | reads filled banks |

## Confidence

| Claim | Level |
|---|---|
| Control flow / double loop bounds | **High / Sealed** |
| Output banks d12e90..d15e90 (0x4000 total) | **High / Sealed** |
| Source tables = FIPS DES S1..S8 layout | **High** (byte match S1/S2 prefix) |
| Role = S-box LUT builder (not P-perm) | **High** (consumer + write targets) |
| Bit-exact filled LUT vs FIPS vectors | **Open** |
| Canonical product/PDB name | **Probable** (role-based) |
