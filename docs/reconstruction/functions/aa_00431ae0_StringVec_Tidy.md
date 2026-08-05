# Function record: StringVec_Tidy

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431ae0` |
| **Canonical name** | `StringVec_Tidy` |
| **Ghidra name** | `FUN_00431ae0` |
| **Address** | `0x00431ae0`–`0x00431b27` exclusive (**71 B** / `0x47`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `vector<basic_string>` tidy / buffer release (elem stride 0x1c) |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W33-D 2026-07-29) — CF/ABI/destroy+free+null sealed by bytes |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StringVec_Tidy` (**Inferred** structural; MSVC-style `_Tidy`)
- Ghidra: `FUN_00431ae0`
- Thunk: `thunk_FUN_00431ae0` @ `0x00431ad0`
- **Reject**: `Named_CalleeOf_Named_CalleeOf_Named_assManager_00431ae0`

## Purpose

Release all capacity of a `StringVecShell`: for each live `basic_string` in `[begin, end)` call the destructor (stride `0x1c`), `operator_delete` the buffer, then null begin/end/capEnd. Null begin is a no-op free with forced zero triad.

## Signature (sealed)

```c
// ECX=self; bare RET; void
void StringVec_Tidy(StringVecShell* self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.md` (+ W33-D append)
- Annotated: `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVec_Tidy.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00431ae0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00431ae0_FUN_00431ae0.md`
- Review A/B: `reviews/A_aa_00431ae0_StringVec_Tidy.md`, `reviews/B_aa_00431ae0_StringVec_Tidy.md`
- Sibling range-dtor only: `FUN_00431aa0` (unowned; used by grow path)

## Callers / callees

| Callers | Callees |
|---|---|
| Listing/path cleanup (`FUN_009839b0`, `FUN_009841d0`, …), EH catch sites | IAT `~basic_string`, `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| ECX=self + bare RET | **High** |
| stride 0x1c destroy loop | **High** |
| free + null after delete | **High** (bytes win) |
| Not range-dtor-only (`FUN_00431aa0`) | **High** |
| Product demangle | **Low** (open) |
