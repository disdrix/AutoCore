# Function record: DES_CalculatePermutationP

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bc40` |
| **Canonical name** | `DES_CalculatePermutationP` |
| **Address** | `0x0071bc40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (P LUT banks + sole caller) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run; static LUTs empty) |

## Purpose

DES Feistel **P-permutation**: map 32-bit S-box substitution output to 32-bit via four precomputed OR-contrib byte banks (`DAT_00d11658` + `k*0x400`, `k=0..3`). Leaf in auth DES-ECB chain; sole caller `DES_RoundFunctionF`.

## Signature (decompiler-derived)

```c
byte * DES_CalculatePermutationP(byte *param_1)
// param_1: 4-byte S-box out (stack)
// EAX:     4-byte P out buffer
// return:  in_EAX + 3 (pointer artifact)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071bc40_DES_CalculatePermutationP.md`
- Annotated: `docs/reconstruction/raw/aa_0071bc40_DES_CalculatePermutationP.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/DES_CalculatePermutationP.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0071bc40_DES_CalculatePermutationP.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0071bc40_DES_CalculatePermutationP.md`
- Legacy scaffold: `functions/aa_0071bc40_FUN_0071bc40.md`, `raw/aa_0071bc40_FUN_0071bc40*.md`, `reconstructed-exact/FUN_0071bc40.cpp`

## Callers / callees

| Direction | Target | Evidence |
|---|---|---|
| Caller | `DES_RoundFunctionF` (`0x0071bf70`) @ `0x0071bff1` | Ghidra xrefs |
| Callees | none (leaf) | analyze_function_complete |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live Ghidra 2026-07-29 | **High** |
| Role = DES P after S-box in F | **High** (caller order) |
| Four banks @ d11658 / d11a58 / d11e58 / d12258, stride 0x400 | **High** |
| Tables runtime-built (static zero) | **High** (`read_memory`) |
| Bank contents ≡ classic P bit table | **Open** (needs init dump) |
| Parameter English / portable crypto API | **Tentative** |
