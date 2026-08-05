# Function record: NDAssetImage_TransferFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00432580` |
| **Canonical name** | `NDAssetImage_TransferFields_Inferred` |
| **Ghidra name** | `FUN_00432580` |
| **Address** | `0x00432580`–`0x00432625` (**165 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NDAssetImage buffer ownership move |
| **Completion status** | **Dual A/B sealed** (W23-C 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Steal / move owned image payload fields from **src (EBX)** into **dest (stack)**: pre-clear dest via `FUN_004321b0`, copy field blocks and ownership pointers, zero src ownership. Success returns 1; pre-clear failure returns 0.

## Signature (decompiler + bytes)

```c
// Ghidra:
undefined4 FUN_00432580(int param_1);  // dest*; unaff_EBX = src*

// Bytes:
//   mov ebp, [esp+8]; mov esi, ebp; call FUN_004321b0
//   ... rep movsd / zero src ...
//   mov al, 1; pop ebp; ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00432580_FUN_00432580.md` (+ W23-C append)
- Annotated: `docs/reconstruction/raw/aa_00432580_FUN_00432580.annotated.md`
- Clean (named): `docs/reconstruction/reconstructed-exact/NDAssetImage_TransferFields_Inferred.cpp`
- Clean (scaffold): `docs/reconstruction/reconstructed-exact/FUN_00432580.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00432580_NDAssetImage_TransferFields_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00432580_NDAssetImage_TransferFields_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00432580_FUN_00432580.md`

## Callers / callees

| Role | Name | VA |
|---|---|---|
| Caller | `FUN_00432cb0` | decode-by-format success |
| Caller | `FUN_0098acc0` | NDAssetImage load sibling |
| Caller | `FUN_0098ae80` | `NDAssetImage_Flip` |
| Callee | `FUN_004321b0` | dest pre-clear |

Xrefs: **4** (`0x00432e5e`, `0x0043306c`, `0x0098af37`, `0x0098ae62`).

## Confidence

| Claim | Level |
|---|---|
| Control flow + block sizes + ret 4 + EBX=src | **High** |
| Role as ownership transfer / steal | **High** |
| Product field English names | **Probable / Tentative** |
| Full object layout beyond transferred fields | **Tentative** |
| Runtime / bit-exact | **Open** |
