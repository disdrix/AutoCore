# Function record: StdDeque_ThrowTooLong_00436860

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436860` |
| **Canonical name** | `StdDeque_ThrowTooLong_00436860` |
| **Ghidra name** | `FUN_00436860` |
| **Address** | `0x00436860`–`0x004368aa` (75 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `containers` / MSVC STL deque |
| **Completion status** | **partial** — dual A/B **accept** (W29-C) |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00436860_StdDeque_ThrowTooLong_00436860.md`, `reviews/B_aa_00436860_StdDeque_ThrowTooLong_00436860.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00436860`
- Role twins (not merged): `FUN_0040ff30`, `FUN_0051b5f0`, `FUN_005b2a80`

## Purpose

Shared **deque length-overflow throw** helper (MSVC `deque::_Xlen` class): plate `"deque<T> too long"` → exception via `FUN_00401a40` → `_CxxThrowException(..., DAT_00acc388)`. Noreturn. Body **75 B** (compact fold via `FUN_00401a40`).

## Signature

```c
void __cdecl StdDeque_ThrowTooLong_00436860(void);  /* noreturn */
```

## Artifacts

- Raw / annotated / clean twin under `aa_00436860` / `FUN_00436860` / `StdDeque_ThrowTooLong_00436860`
- Scaffold record: `functions/aa_00436860_FUN_00436860.md`
- Report: `docs/agents/task-dual-ab-00436860-00423e00-w29c-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `basic_string` ctor, `FUN_00401a40`, `_CxxThrowException` |
| **Callers** | `FUN_00436650`, `FUN_0043c9b0`, `FUN_0043d990`, `FUN_0043ea60` |

## Confidence

| Claim | Level |
|---|---|
| CF + plate + ThrowInfo | **High** |
| Product `_Xlen` name | **Inferred** |
| Runtime | Open |
