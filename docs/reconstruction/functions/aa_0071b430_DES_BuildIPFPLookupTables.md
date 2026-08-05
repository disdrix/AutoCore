# Function record: DES_BuildIPFPLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b430` |
| **Canonical name** | `DES_BuildIPFPLookupTables` |
| **Prior scaffold** | `FUN_0071b430` |
| **Address** | `0x0071b430`–`0x0071b59d` exclusive (**365** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | auth / DES |
| **Completion status** | **Dual A/B sealed** 2026-07-29 (W25-Q) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run); filled-table golden vectors open |

## Alias

| Name | Role |
|------|------|
| `FUN_0071b430` | Ghidra / scaffold |

## Purpose

One-shot **DES IP/FP nibble LUT builder**. Zeroes a 0x800-byte destination, then expands a 64-entry 1-based FIPS permutation vector (IP or FP) into nibble-indexed 8-byte contribution rows consumed by `DES_PermuteBlock`.

## Signature (sealed)

```c
// cdecl: two stack args; bare ret
void DES_BuildIPFPLookupTables(undefined4 *dst /*0x800 bytes*/, int perm /*char[64] 1-based*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.md` (+ 2026-07-29 live)
- Annotated: `docs/reconstruction/raw/aa_0071b430_FUN_0071b430.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/DES_BuildIPFPLookupTables.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0071b430.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0071b430_DES_BuildIPFPLookupTables.md`
- Review B: `docs/reconstruction/reviews/B_aa_0071b430_DES_BuildIPFPLookupTables.md`
- Scaffold record: `docs/reconstruction/functions/aa_0071b430_FUN_0071b430.md`

## Callers / callees

| Direction | Target | Notes |
|-----------|--------|-------|
| Caller | `DES_InitializeCipher` @ `0x0071c000` | sole UNCONDITIONAL_CALL; twice (IP then FP) |
| Callees | none | leaf |
| Outputs | `DAT_00d16ef0` (IP), `DAT_00d12690` (FP) | 0x800 B each |
| Sources | `DAT_00afca50` (IP FIPS), `DAT_00afca90` (FP FIPS) | exact FIPS 46-3 |
| Consumer | `DES_PermuteBlock` (`aa_0071bd40`) | uses filled banks |

## Confidence

| Claim | Level |
|---|---|
| Control flow / triple nested loops | **High / Sealed** |
| Clear size 0x200 dwords = 0x800 bytes | **High / Sealed** |
| IP/FP static tables = FIPS | **High** (`read_memory` exact) |
| Role = IP/FP LUT builder (not apply) | **High** (init-only + consumer) |
| ABI cdecl 2-arg bare ret | **High** |
| Post-init bank contents bit-exact vs hand expand | **Open** |
| Canonical product/PDB name | **Probable** (role-based) |
