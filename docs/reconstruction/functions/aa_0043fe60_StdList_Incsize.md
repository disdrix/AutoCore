# Function record: StdList_Incsize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fe60` |
| **Canonical name** | `StdList_Incsize` |
| **Ghidra name** | `FUN_0043fe60` |
| **Address** | `0x0043fe60`–`0x0043fece` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared MSVC `std::list` |
| **Completion status** | **Dual sealed** (W23-E 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_0043fe60`
- Prior scaffold: `Named_CalleeOf_Auth_AuthServer_0043fe60` (misleading domain — shared leaf)
- Twin leaf (not owned): `FUN_00403600` (`__thiscall`, max `0x6666666`)

## Purpose

MSVC-shaped **`std::list::_Incsize`**: if `_Mysize + count` would exceed max `0x3fffffff`, throw with `"list<T> too long"`; else `_Mysize += count` at `list+8`.

## Signature

```c
void __fastcall StdList_Incsize(uint32_t count /*ECX*/, StdListHeader *list /*EDX*/);
// plain RET — no stack args
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.md` (+ W23-E live seal)
- Annotated: `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdList_Incsize.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0043fe60.cpp`
- Reviews: `reviews/A_aa_0043fe60_StdList_Incsize.md`, `reviews/B_aa_0043fe60_StdList_Incsize.md`

## Callers / callees

**Callees:** `FUN_00401a40`, `_CxxThrowException`, `basic_string` ctor.

**Callers (sample):** `FUN_00480350` (PushPayloadNode), Auth `00728700`…`00728c20`, `FUN_00436b00`, `FUN_0043fb50`, `FUN_0046a5e0`, `FUN_0046ebf0`, `FUN_00725bd0`, `FUN_0076d250`, `FUN_007c8890`, `FUN_007c9230`, `FUN_007ce550`, `FUN_0095e3e0`, `FUN_00968a50`, `FUN_00989850`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ bytes | **High** |
| ECX=count, EDX=list*, `+8` size | **High** |
| Max constant `0x3fffffff` | **High** |
| String `"list<T> too long"` | **High** |
| Role = MSVC `_Incsize` | **High** |
| Product symbol / exception C++ type name | **Open** |
| Runtime / bit-exact | **Open** |
