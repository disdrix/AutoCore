# Function record: StringVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_004301f0` |
| **Canonical name** | `StringVec_PushBack` |
| **Ghidra name** | `FUN_004301f0` |
| **Address** | `0x004301f0`–`0x00430278` exclusive (**136 B** / `0x88`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `vector<basic_string>` push_back (elem stride 0x1c) |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W33-D 2026-07-29) — CF/ABI/capacity gate sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StringVec_PushBack` (**Inferred** structural)
- Ghidra: `FUN_004301f0`
- **Reject**: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004301f0`

## Purpose

`vector<basic_string>::push_back` for this binary's string vector shell: if spare capacity exists, construct one element at `end` and advance `end` by `0x1c`; otherwise insert one at `end` via `StringVec_InsertOne` (may reallocate).

## Signature (sealed)

```c
// __thiscall; RET 4; void
void StringVec_PushBack(StringVecShell* self, const void* value_string);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.md` (+ W33-D append)
- Annotated: `docs/reconstruction/raw/aa_004301f0_FUN_004301f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StringVec_PushBack.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004301f0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_004301f0_FUN_004301f0.md`
- Review A/B: `reviews/A_aa_004301f0_StringVec_PushBack.md`, `reviews/B_aa_004301f0_StringVec_PushBack.md`
- Nested insert-one: `aa_00430310` (W32-A); nested grow: `FUN_004306b0` (W32-B)

## Callers / callees

| Callers | Callees |
|---|---|
| Path/listing push sites (`FUN_009839b0`, `FUN_009841d0`, `FUN_00984340`, `FUN_009697a0`, …) | `FUN_00431700`, `StringVec_InsertOne` (`FUN_00430310`) |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 | **High** |
| stride 0x1c + `/0x1c` magic | **High** |
| size < capacity fast path | **High** |
| capacity-miss → insert at end | **High** |
| Nested construct-n plate | **Med** (unowned `FUN_00431700`) |
| Product demangle | **Low** (open) |
