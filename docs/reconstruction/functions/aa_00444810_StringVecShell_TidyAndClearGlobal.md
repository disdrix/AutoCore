# Function record: StringVecShell_TidyAndClearGlobal

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444810` |
| **Canonical name** | `StringVecShell_TidyAndClearGlobal` |
| **Ghidra name** | `FUN_00444810` |
| **Address** | `0x00444810`–`0x0044484A` exclusive (**58 B** / `0x3A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir path-list shell tidy + `DAT_00d1f1fc` clear |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W34-K 2026-07-29) — CF/ABI/tidy+global sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StringVecShell_TidyAndClearGlobal` (**Inferred** structural)
- Ghidra: `FUN_00444810`
- Parent complete dtor: `Palantir_CompleteDtor` (`aa_00754320`)
- Nested tidy: `StringVec_Tidy` (`aa_00431ae0`, W33-D)

## Purpose

Fully release a `StringVecShell` buffer and clear the process-wide published pointer `DAT_00d1f1fc`. Retail uses this from Palantir complete-dtor SEH unwind when the shell lives at `Palantir+0xA0` (same shell the normal dtor path tidies in-line).

## Signature (sealed)

```c
// ECX=shell; bare RET; void; SEH LAB_009bd525
void StringVecShell_TidyAndClearGlobal(StringVecShell* shell);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00444810_FUN_00444810.md` (+ W34-K append)
- Annotated: `docs/reconstruction/raw/aa_00444810_FUN_00444810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVecShell_TidyAndClearGlobal.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00444810.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00444810_FUN_00444810.md`
- Review A/B: `reviews/A_aa_00444810_StringVecShell_TidyAndClearGlobal.md`, `reviews/B_aa_00444810_StringVecShell_TidyAndClearGlobal.md`

## Callers / callees

| Callers | Callees |
|---|---|
| Palantir dtor unwind `@009afd09`, `@009afd4a` | `StringVec_Tidy` (`0x00431ae0`) |

## Confidence

| Claim | Level |
|---|---|
| ECX=shell + bare RET | **High** |
| Order: tidy then null global | **High** |
| Not capacity-preserving clear | **High** |
| Product demangle / English | **Low** |
