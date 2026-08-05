# Function record: DES_BuildPermutationP_Tables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b5a0` |
| **Canonical name** | `DES_BuildPermutationP_Tables` |
| **Prior scaffold** | `FUN_0071b5a0` |
| **Address** | `0x0071b5a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 W19-Q |
| **Bit-for-bit / runtime / diff** | Open (deferred; static banks empty; no Launcher) |

## Purpose

Initialize the four precomputed DES **P-permutation** OR-contribution banks (`DAT_00d11658` + `k*0x400`) used by `DES_CalculatePermutationP`. Reads FIPS P (`DAT_00afcd48`) and bit masks (`DAT_00afcd68`). Leaf; sole caller `DES_InitializeCipher`.

## Signature (decompiler-derived)

```c
void DES_BuildPermutationP_Tables(void)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071b5a0_DES_BuildPermutationP_Tables.md`
- Annotated: `docs/reconstruction/raw/aa_0071b5a0_DES_BuildPermutationP_Tables.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/DES_BuildPermutationP_Tables.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0071b5a0_DES_BuildPermutationP_Tables.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0071b5a0_DES_BuildPermutationP_Tables.md`
- Legacy scaffold: `functions/aa_0071b5a0_FUN_0071b5a0.md`, `raw/aa_0071b5a0_FUN_0071b5a0*.md`, `reconstructed-exact/FUN_0071b5a0.cpp`

## Callers / callees

| Direction | Target | Evidence |
|---|---|---|
| Caller | `DES_InitializeCipher` (`0x0071c000`) @ `0x0071c070` | Ghidra `get_function_xrefs` |
| Callees | none (leaf) | decompile |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live Ghidra 2026-07-29 | **High** |
| Role = P-table bank builder for CalculatePermutationP | **High** (bases + FIPS P + init order) |
| Zero 0x400 dwords @ d11658 | **High** (`rep stosd` + decompile) |
| DAT_00afcd48 ≡ FIPS P | **High** (`read_memory`) |
| Banks empty offline | **High** (`read_memory` all-zero) |
| Post-init bank ≡ classic P for all 256×4 rows | **Open** (needs runtime dump) |
