# Function record: StdString_OperatorPlus_String

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416410` |
| **Canonical name** | `StdString_OperatorPlus_String` (**Inferred** structural) |
| **Ghidra name** | `FUN_00416410` |
| **Address** | `0x00416410`–`0x00416489` (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC free `operator+(basic_string const&, basic_string const&)` |
| **Completion status** | **Dual-reviewed** W33-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style free binary `operator+` for two `basic_string` operands. Builds a temporary from `lhs`, appends `rhs` via `operator+=(basic_string const&)`, then copy-constructs into the hidden return object.

## Signature

```c
// cdecl; stack out*, lhs*, rhs*; RET plain; returns out*
MsvcBasicString* StdString_OperatorPlus_String(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    const MsvcBasicString* rhs);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_006874b0`, `FUN_00750260`, `FUN_009839b0`, `FUN_00984340` |
| Callees | IAT `[0x009c62ec]` copy-ctor → `0x006ead80`; IAT `[0x009c62a0]` `+=string` → `0x006eb12a`; IAT `[0x009c62f4]` dtor → `0x006eace6` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416410_FUN_00416410.md`
- Annotated: `docs/reconstruction/raw/aa_00416410_FUN_00416410.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdString_OperatorPlus_String.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416410.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416410_FUN_00416410.md`
- Review A: `docs/reconstruction/reviews/A_aa_00416410_StdString_OperatorPlus_String.md`
- Review B: `docs/reconstruction/reviews/B_aa_00416410_StdString_OperatorPlus_String.md`
- Peer: `aa_00416490` StdString_OperatorPlus_Cstr

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| ABI cdecl + 3 stack + C3 | **High** |
| rhs string overload | **High** |
| Twin byte-diff only at += IAT | **High** |
| Product demangle | **Low** |
| Runtime | **Open** |
