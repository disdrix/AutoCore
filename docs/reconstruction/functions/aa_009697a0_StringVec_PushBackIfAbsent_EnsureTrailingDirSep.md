# Function record: StringVec_PushBackIfAbsent_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009697a0` |
| **Canonical name** | `StringVec_PushBackIfAbsent_EnsureTrailingDirSep` |
| **Ghidra name** | `FUN_009697a0` |
| **Address** | `0x009697a0`–`0x0096982D` exclusive (**141 B** / `0x8D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `vector<basic_string>` unique append after trailing-sep normalize |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W34-J 2026-07-29) — CF/ABI/scan sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StringVec_PushBackIfAbsent_EnsureTrailingDirSep` (**Inferred** structural)
- Ghidra: `FUN_009697a0`
- Family: push_front `StringVec_PushFront_EnsureTrailingDirSep` (`0x00969830`); erase sibling `FUN_009696c0`

## Purpose

After ensuring a trailing directory separator on the input path, append that string to a `StringVecShell` only when no equal element is already present (linear equality scan, stride `0x1c`).

## Signature (sealed)

```c
// EDI=self; stack path*; RET 4; void
void StringVec_PushBackIfAbsent_EnsureTrailingDirSep(
    StringVecShell* self /*EDI*/,
    const void* path);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.md` (+ W34-J append)
- Annotated: `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVec_PushBackIfAbsent_EnsureTrailingDirSep.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_009697a0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_009697a0_FUN_009697a0.md`
- Review A/B: `reviews/A_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md`, `reviews/B_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md`
- Nested normalize: `aa_009694e0` (W32-A); nested push_back: `aa_004301f0` (W33-D)

## Callers / callees

| Callers | Callees |
|---|---|
| None sealed in Ghidra xrefs | `BasicString_CopyEnsureTrailingDirSep`, IAT `operator==`, `StringVec_PushBack`, IAT dtor |

## Confidence

| Claim | Level |
|---|---|
| EDI + RET 4 ABI | **High** |
| Absent-only push_back CF | **High** |
| Trailing-sep via W32-A helper | **High** |
| Caller / product English | **Open / Low** |
