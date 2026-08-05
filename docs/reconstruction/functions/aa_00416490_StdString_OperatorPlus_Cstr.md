# Function record: StdString_OperatorPlus_Cstr

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416490` |
| **Canonical name** | `StdString_OperatorPlus_Cstr` (**Inferred** structural) |
| **Ghidra name** | `FUN_00416490` |
| **Address** | `0x00416490`–`0x00416509` (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC free `operator+(basic_string const&, char const*)` |
| **Completion status** | **Dual-reviewed** W33-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style free binary `operator+` for `basic_string` + C string. Builds a temporary from `lhs`, appends `rhs` via `operator+=(char const*)`, then copy-constructs into the hidden return object.

## Signature

```c
// cdecl; stack out*, lhs*, const char* rhs; RET plain; returns out*
MsvcBasicString* StdString_OperatorPlus_Cstr(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    const char* rhs);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0076ba10`, `FUN_005b7250`, `FUN_006874b0`, `FUN_009698a0`, `FUN_009839b0`, `FUN_00984340`, `FUN_00985010` |
| Callees | IAT `[0x009c62ec]` copy-ctor → `0x006ead80`; IAT `[0x009c62b0]` `+=cstr` → `0x006eafe8`; IAT `[0x009c62f4]` dtor → `0x006eace6` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416490_FUN_00416490.md`
- Annotated: `docs/reconstruction/raw/aa_00416490_FUN_00416490.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdString_OperatorPlus_Cstr.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416490.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416490_FUN_00416490.md`
- Review A: `docs/reconstruction/reviews/A_aa_00416490_StdString_OperatorPlus_Cstr.md`
- Review B: `docs/reconstruction/reviews/B_aa_00416490_StdString_OperatorPlus_Cstr.md`
- Peer: `aa_00416410` StdString_OperatorPlus_String
- Related path helper: `aa_009694e0` BasicString_CopyEnsureTrailingDirSep (uses sibling `FUN_00416510`)

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| ABI cdecl + 3 stack + C3 | **High** |
| rhs C-string overload | **High** |
| Twin byte-diff only at += IAT | **High** |
| Product demangle | **Low** |
| Runtime | **Open** |
