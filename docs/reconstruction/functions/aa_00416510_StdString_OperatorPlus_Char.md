# Function record: StdString_OperatorPlus_Char

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416510` |
| **Canonical name** | `StdString_OperatorPlus_Char` (**Inferred** structural) |
| **Ghidra name** | `FUN_00416510` |
| **Address** | `0x00416510`–`0x00416589` (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC free `operator+(basic_string const&, char)` |
| **Completion status** | **Dual-reviewed** W34-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style free binary `operator+` for `basic_string` + single `char`. Builds a temporary from `lhs`, appends `rhs` via `operator+=(char)`, then copy-constructs into the hidden return object.

## Signature

```c
// cdecl; stack out*, lhs*, char rhs; RET plain; returns out*
MsvcBasicString* StdString_OperatorPlus_Char(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    char rhs);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_009694e0` / `BasicString_CopyEnsureTrailingDirSep` (1 xref @ `0x00969554`) |
| Callees | IAT `[0x009c62ec]` copy-ctor → `0x006ead80`; IAT `[0x009c6294]` `+=char` → `0x006eb20c`; IAT `[0x009c62f4]` dtor → `0x006eace6` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416510_FUN_00416510.md`
- Annotated: `docs/reconstruction/raw/aa_00416510_FUN_00416510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdString_OperatorPlus_Char.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416510.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416510_FUN_00416510.md`
- Review A: `docs/reconstruction/reviews/A_aa_00416510_StdString_OperatorPlus_Char.md`
- Review B: `docs/reconstruction/reviews/B_aa_00416510_StdString_OperatorPlus_Char.md`
- Peers: `aa_00416490` StdString_OperatorPlus_Cstr; `aa_00416410` StdString_OperatorPlus_String
- Parent path helper: `aa_009694e0` BasicString_CopyEnsureTrailingDirSep

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| ABI cdecl + 3 stack + C3 | **High** |
| rhs single-char overload | **High** |
| Twin byte-diff only at += IAT | **High** |
| Product demangle | **Low** |
| Runtime | **Open** |
