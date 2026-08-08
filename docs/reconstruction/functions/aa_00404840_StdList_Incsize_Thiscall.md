# Function record: StdList_Incsize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404840` |
| **Canonical name** | `StdList_Incsize_Thiscall` |
| **Ghidra name** | `FUN_00404840` |
| **Address** | `0x00404840`–`0x004048AE` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` |
| **Completion status** | **Dual sealed** (R10-006 2026-08-05) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_00404840`
- Prior scaffold: `Named_CalleeOf_Client_DebugListMissionsStatus_00404840` (misleading domain — shared leaf)
- Fastcall twin (sealed W23-E): `StdList_Incsize` @ `0x0043fe60` (same max, different ABI)
- Max-`0x1fffffff` peer: `StdList_Incsize_Max1fffffff` @ `0x00416010`

## Purpose

MSVC-shaped **`std::list::_Incsize`**: if `_Mysize + count` would exceed max `0x3fffffff`, throw with `"list<T> too long"`; else `_Mysize += count` at `list+8`.

This unit is the **`__thiscall`** clone (list in ECX, count on stack, `RET 4`). Used after BuyNode (`0x00418700`) by push_back / insert-N wrappers.

## Signature

```c
void __thiscall StdList_Incsize_Thiscall(StdListHeader *list /*ECX*/, uint32_t count /*stack*/);
// RET 4 — cleans one dword
```

## Algorithm

```
size = list->_Mysize            // [ECX+8]
if (0x3fffffffU - size < count)
  throw length_error path with "list<T> too long"  // 0x00a1581c / DAT_00acc388
list->_Mysize = size + count
ret 4
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404840_FUN_00404840.md` (+ R10-006 live re-verify)
- Annotated: `docs/reconstruction/raw/aa_00404840_FUN_00404840.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdList_Incsize_Thiscall.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00404840.cpp`
- FUN record: `docs/reconstruction/functions/aa_00404840_FUN_00404840.md`
- Reviews: `reviews/A_aa_00404840_StdList_Incsize_Thiscall.md`, `reviews/B_aa_00404840_StdList_Incsize_Thiscall.md`
- Report: `docs/agents/task-dual-ab-00404840-r10-report.md`

## Callers / callees

**Callees:** `FUN_00401a40`, `_CxxThrowException`, `basic_string` ctor.

**Callers (sample):** `FUN_00402d10` StdList_PushBack_Dword, `FUN_004040f0` insert-one, `FUN_00517db0`, `FUN_0052b350`, inventory/character serialize paths, 32 xrefs total.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ bytes | **High** |
| ECX=list*, stack count, `+8` size, `RET 4` | **High** |
| Max constant `0x3fffffff` | **High** |
| String `"list<T> too long"` | **High** |
| Role = MSVC `_Incsize` | **High** |
| Distinct from fastcall twin `0043fe60` | **High** |
| Product symbol / exception C++ type name | **Open** |
| Runtime / bit-exact | **Open** |
