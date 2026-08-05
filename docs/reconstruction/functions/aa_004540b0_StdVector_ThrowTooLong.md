# Function record: StdVector_ThrowTooLong

| Field | Value |
|---|---|
| **Stable ID** | `aa_004540b0` |
| **Canonical name** | `StdVector_ThrowTooLong` |
| **Ghidra name** | `FUN_004540b0` |
| **Address** | `0x004540b0` |
| **Body range** | `0x004540b0`–`0x004540fa` (75 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `containers` / MSVC STL vector |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + plate string sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004540b0_StdVector_ThrowTooLong.md`, `reviews/B_aa_004540b0_StdVector_ThrowTooLong.md` (2026-07-29 W19-B) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004540b0`
- `Named_CalleeOf_Named_CalleeOf_Named_assManager_004540b0` (legacy xref scaffold)
- `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_004540b0` (legacy xref scaffold)

## Purpose

Shared MSVC **`vector::_Xlen()`-class** noreturn helper: construct plate message `"vector<T> too long"`, wrap as C++ exception (`FUN_00401a40`), throw via `_CxxThrowException` with `ThrowInfo` at `DAT_00acc388`. Invoked when vector growth/insert would exceed max size.

## Signature

```c
void __cdecl StdVector_ThrowTooLong(void);  /* noreturn */
```

## Algorithm

1. Install SEH frame (`LAB_009bc919`).
2. `basic_string` ctor from `"vector<T> too long"` @ `0x00a15830` (IAT `[0x009c62f8]`).
3. `FUN_00401a40(&ex, &msg)` — exception object ctor (vtbl `PTR_FUN_009c7634`).
4. `_CxxThrowException(&ex, &DAT_00acc388)` — never returns.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004540b0_FUN_004540b0.md`
- Annotated: `docs/reconstruction/raw/aa_004540b0_FUN_004540b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_ThrowTooLong.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004540b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004540b0_FUN_004540b0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004540b0-005739b0-w19b-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | basic_string ctor (IAT), `FUN_00401a40`, `_CxxThrowException` |
| **Callers** | 100+ vector grow/insert overflow sites; sample: `FUN_004507a0`, `FUN_00456960`, `FUN_00480d20`, `FUN_00443040`, `FUN_00443870`, `FUN_0041fae0`, `FUN_0041f380`, `FUN_004272b0`, `FUN_004306b0`, `FUN_005114e0`, `FUN_0068c4b0`, `FUN_006917f0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Plate string `"vector<T> too long"` | **High** (`read_memory` @ `0x00a15830`) |
| Noreturn throw path | **High** |
| Role = vector length overflow | **High** (string + parent insert/grow guards) |
| Product English `_Xlen` symbol | **Inferred** |
| Exact exception C++ type | Open (`FUN_00401a40` / ThrowInfo RTTI) |
| Runtime / differential | Open |

## Related

- Sibling plate-string throw sites: `FUN_00418130`, `FUN_004932e0`, `FUN_00506320` (same message, not owned here)
- Consumers: `StdVector_InsertN_Dword` family (`aa_004073a0`), insert helpers using size-max checks against `0x3fffffff`
