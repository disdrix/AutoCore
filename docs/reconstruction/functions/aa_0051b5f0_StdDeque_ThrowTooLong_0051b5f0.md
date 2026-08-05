# Function record: StdDeque_ThrowTooLong_0051b5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5f0` |
| **Canonical name** | `StdDeque_ThrowTooLong_0051b5f0` |
| **Ghidra name** | `FUN_0051b5f0` |
| **Address** | `0x0051b5f0` |
| **Body range** | `0x0051b5f0`–`0x0051b65f` (112 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `containers` / MSVC STL deque |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + plate string sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md`, `reviews/B_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` (2026-07-29 W21-E) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0051b5f0`
- `Named_CalleeOf_Named_CalleeOf_Skill_QueueDeferredCastId_0051b5f0` (legacy xref scaffold)
- Role twins (other VAs, not merged): `FUN_0040ff30`, `FUN_00436860`, `FUN_005b2a80`

## Purpose

MSVC **`deque::_Xlen()`-class** noreturn helper: construct plate message `"deque<T> too long"`, build typed exception (`exception::exception` + message copy + vftable `PTR_FUN_009c7634`), throw via `_CxxThrowException` with `ThrowInfo` at `DAT_00acc388`. Invoked when deque map growth would exceed max size (e.g. skill deferred-cast id queue map grow `FUN_0051c3b0`).

## Signature

```c
void __cdecl StdDeque_ThrowTooLong_0051b5f0(void);  /* noreturn */
```

## Algorithm

1. Install SEH frame (`LAB_009a3502`).
2. `basic_string` ctor from `"deque<T> too long"` @ `0x00a31520` (IAT).
3. EH state = 0; `exception::exception(&ex)`; vftable `PTR_FUN_009c7628`.
4. Copy-construct message into exception; vftable `PTR_FUN_009c7634`.
5. `_CxxThrowException(&ex, &DAT_00acc388)` — never returns.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b5f0_FUN_0051b5f0.md`
- Annotated: `docs/reconstruction/raw/aa_0051b5f0_FUN_0051b5f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdDeque_ThrowTooLong_0051b5f0.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0051b5f0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0051b5f0_FUN_0051b5f0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051b5f0-005210b0-w21e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `basic_string` ctor/copy (IAT), `exception::exception`, `_CxxThrowException` @ `0x006a3d60` |
| **Callers** | `FUN_0051c3b0` @ `0x0051c3b0` (map overflow → throw); parents of that grow helper include skill deferred-cast deque push paths |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Plate string `"deque<T> too long"` | **High** (`read_memory` @ `0x00a31520`) |
| Noreturn throw path | **High** |
| Role = deque length overflow | **High** (string + parent map-grow guards) |
| Product English `_Xlen` symbol | **Inferred** |
| Exact exception C++ type | Open (vftable RTTI / `FUN` hierarchy) |
| Runtime / differential | Open |

## Related

- Vector twin pattern: `StdVector_ThrowTooLong_00418130` / `StdVector_ThrowTooLong` @ `0x004540b0` (same ThrowInfo family, different plate)
- Deque grow consumers: `FUN_0051c3b0`, skill queue `Skill_QueueDeferredCastId` family
