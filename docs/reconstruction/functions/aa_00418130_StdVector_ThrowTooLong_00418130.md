# Function record: StdVector_ThrowTooLong_00418130

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418130` |
| **Canonical name** | `StdVector_ThrowTooLong_00418130` |
| **Ghidra name** | `FUN_00418130` |
| **Address** | `0x00418130` |
| **Body range** | `0x00418130`–`0x0041817a` (75 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `containers` / MSVC STL vector |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + plate string sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00418130_StdVector_ThrowTooLong_00418130.md`, `reviews/B_aa_00418130_StdVector_ThrowTooLong_00418130.md` (2026-07-29 W20-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00418130`
- `Named_CalleeOf_Named_CalleeOf_Client_UpdateMissionJournal_00418130` (legacy xref scaffold)
- Role twin of `StdVector_ThrowTooLong` @ `0x004540b0` (separate clean file to avoid collision)

## Purpose

MSVC **`vector::_Xlen()`-class** noreturn helper: construct plate message `"vector<T> too long"`, wrap as C++ exception (`FUN_00401a40`), throw via `_CxxThrowException` with `ThrowInfo` at `DAT_00acc388`. Invoked when vector growth/insert would exceed max size. Sibling clone of sealed `aa_004540b0` with minor EH-state store ordering difference.

## Signature

```c
void __cdecl StdVector_ThrowTooLong_00418130(void);  /* noreturn */
```

## Algorithm

1. Install SEH frame (`LAB_009bc919`).
2. `basic_string` ctor from `"vector<T> too long"` @ `0x00a15830` (IAT `[0x009c62f8]`).
3. EH state = 0.
4. `FUN_00401a40(&ex, &msg)` — exception object ctor.
5. `_CxxThrowException(&ex, &DAT_00acc388)` — never returns.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00418130_FUN_00418130.md`
- Annotated: `docs/reconstruction/raw/aa_00418130_FUN_00418130.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_ThrowTooLong_00418130.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00418130.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00418130_FUN_00418130.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00418130-00404130-w20g-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | basic_string ctor (IAT), `FUN_00401a40`, `_CxxThrowException` |
| **Callers** | 30+ grow/insert overflow sites; sample: `FUN_00403980` (UiToastVector_InsertN), `FUN_00403680` (CombatFloater InsertN), `FUN_004073a0`, `FUN_004e2f20`, `FUN_004e4620`, `FUN_004e53e0`, `FUN_00402130`, … |

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

- Sibling plate-string throw sites: `FUN_004540b0` (sealed `StdVector_ThrowTooLong`), `FUN_004932e0`, `FUN_00506320`
- Consumers: toast/floater insert-N max-size arms; dword insert helpers using size-max checks
