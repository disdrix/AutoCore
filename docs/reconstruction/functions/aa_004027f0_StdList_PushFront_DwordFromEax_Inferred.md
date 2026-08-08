# Function record: StdList_PushFront_DwordFromEax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004027f0` |
| **Canonical name** | `StdList_PushFront_DwordFromEax_Inferred` |
| **Address** | `0x004027f0`–`0x0040281e` (**47 B** / `0x2F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (partition) + multi-system list host |
| **Completion status** | **Human-refined** + dual A/B seal 2026-08-05 (MEGA-089); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_004027f0`
- Prior scaffold (**retired**): `Named_CalleeOf_Client_RecvCreateCharacter_004027f0`
- Parent hint: callee of `Client_RecvCreateCharacter` (also vehicle create + other hosts)

## Purpose

Thread-unsafe MSVC **`std::list` push_front** of a **dword** element:

1. `head = *(list+4)` (`_Myhead` sentinel).
2. `node = FUN_00418700(head, head->_Next, eax_val)` — `operator_new(0xC)`; fields `{_Prev, _Next, _Myval=*val}`.
3. `FUN_00418790(1, list)` — `_Mysize += 1`; may throw `std::length_error("list<T> too long")`.
4. `head->_Next = node`; `node->_Next->_Prev = node`.

## Signature (sealed)

```c
// stack list*; EAX = const uint32_t* val; ret 4
// NOT __thiscall (list not in ECX)
void StdList_PushFront_DwordFromEax_Inferred(void *list, const uint32_t *val_in_eax);
```

## Layout (sealed)

| Off | Field |
|----:|-------|
| list+0x04 | `_Myhead` sentinel* |
| list+0x08 | `_Mysize` |
| node+0x00 | `_Prev` |
| node+0x04 | `_Next` |
| node+0x08 | `_Myval` (dword) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.md`
- Annotated: `docs/reconstruction/raw/aa_004027f0_FUN_004027f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdList_PushFront_DwordFromEax_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004027f0.cpp`
- FUN record: `docs/reconstruction/functions/aa_004027f0_FUN_004027f0.md`
- Reviews: `docs/reconstruction/reviews/A_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md`, `B_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md`
- Report: `docs/agents/task-dual-ab-004027f0-mega-089-report.md`

## Callers / callees

| Direction | Address / name | Notes |
|-----------|----------------|-------|
| Callee | `FUN_00418700` @ `0x00418700` | `_Buynode` 0xC / `RET 0xC` |
| Callee | `FUN_00418790` @ `0x00418790` | `_Incsize` fastcall ECX/EDX |
| Caller | `Client_RecvCreateCharacter` @ `0x00814823` | list character+`0xf08` |
| Caller | `Client_CreateVehicleObjectApply` @ `0x008128c2` | list +`0xefc` |
| Caller | `FUN_0080af70` @ `0x0080b03f` | list ESI+`0xf08` |
| Caller | `FUN_0093ffb0` @ `0x00940cff`, `0x00940e2c` | list +`0xaa8` |
| Caller | `FUN_008c7700`, `FUN_00919dc0`, `FUN_00946c00` | additional hosts |

## Confidence

| Claim | Level |
|---|---|
| Function boundary + RET 4 | **High / Sealed** |
| push_front CF + node 0xC layout | **High / Sealed** |
| EAX value-pointer ABI | **High / Sealed** |
| `"list<T> too long"` size path via callee | **High** (callee dual/raw) |
| Product list/element English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
