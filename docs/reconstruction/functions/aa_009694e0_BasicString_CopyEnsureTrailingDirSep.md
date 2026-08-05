# Function record: BasicString_CopyEnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009694e0` |
| **Canonical name** | `BasicString_CopyEnsureTrailingDirSep` |
| **Ghidra name** | `FUN_009694e0` |
| **Address** | `0x009694e0`–`0x009695b1` exclusive (**209 B** / `0xD1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assManager / path-string normalize helper |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W32-A 2026-07-29) — CF/ABI/trailing-sep rules sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `BasicString_CopyEnsureTrailingDirSep` (**Inferred** structural)
- Ghidra: `FUN_009694e0`
- **Reject**: `Named_CalleeOf_Named_CalleeOf_Named_assManager_009694e0` (scaffold plate)

## Purpose

Copy a MSVC `basic_string` into an out-parameter. If the source is non-empty and its last character is not `:`, `/`, or `\`, the copy receives an appended `/` (via `FUN_00416510` copy+`operator+=`). Empty and already-terminated sources are plain copies.

## Signature (sealed)

```c
// cdecl; returns out*
MsvcBasicString* BasicString_CopyEnsureTrailingDirSep(
    MsvcBasicString* out,
    const MsvcBasicString* src);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.md` (+ W32-A append)
- Annotated: `docs/reconstruction/raw/aa_009694e0_FUN_009694e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/BasicString_CopyEnsureTrailingDirSep.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_009694e0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_009694e0_FUN_009694e0.md`
- Review A/B: `reviews/A_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md`, `reviews/B_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md`
- Parent dual: `aa_00969830` StringVec_PushFront_EnsureTrailingDirSep (W31-E)

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_009696c0`, `FUN_009697a0`, `FUN_00969830` | IAT `basic_string` copy-ctor, IAT dtor, `FUN_00416510` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Trailing-sep charset `{':','/','\\'}` | **High** |
| Append char is `'/'` only | **High** |
| SSO threshold `_Myres < 0x10` | **High** |
| Product English for path-list role | **Low** (open) |
| Nested `FUN_00416510` product plate | **Med** (behavior sealed via decompile; unowned) |
