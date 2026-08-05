# Function record: Win32_ThrowLastErrorAsHresult_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004048c0` |
| **Canonical name** | `Win32_ThrowLastErrorAsHresult_Inferred` |
| **Ghidra name** | `FUN_004048c0` |
| **Address** | `0x004048c0` |
| **Body range** | `0x004048c0`–`0x004048d9` (26 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `crt-com` / Win32 last-error → C++ throw |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + HRESULT pack sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md`, `reviews/B_aa_004048c0_Win32_ThrowLastErrorAsHresult_Inferred.md` (2026-07-29 W22-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004048c0`
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_004048c0` (legacy scaffold)
- Structural: `GetLastError` → `HRESULT_FROM_WIN32` → `Cxx_ThrowException_Param`
- Related throw leaf: `Cxx_ThrowException_Param_Inferred` @ `0x004048e0`

## Purpose

**Noreturn** Win32 last-error throw helper:

1. `err = GetLastError()` (IAT `[0x009c6230]`).
2. If `(int)err > 0`: pack `err = (err & 0xffff) | 0x80070000` (classic `HRESULT_FROM_WIN32`).
3. `FUN_004048e0(err)` → `_CxxThrowException` with ThrowInfo `DAT_00acc3fc`.

Used after failed Win32 APIs that leave a last-error code (e.g. `WideCharToMultiByte` failure in `MbcsString_ConvertFromWide`). Not a recovery path — always throws.

## Signature

```c
__declspec(noreturn) void Win32_ThrowLastErrorAsHresult_Inferred(void);
```

## Algorithm

```
err = GetLastError()
if ((int)err > 0)
  err = (err & 0xffff) | 0x80070000
FUN_004048e0(err)   // noreturn
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004048c0_FUN_004048c0.md`
- Annotated: `docs/reconstruction/raw/aa_004048c0_FUN_004048c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Win32_ThrowLastErrorAsHresult_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004048c0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004048c0_FUN_004048c0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004048c0-00404510-w22g-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | IAT `0x009c6230` | `GetLastError` |
| Callee | `0x004048e0` | `Cxx_ThrowException_Param_Inferred` |
| Caller | `0x00403450` | `MbcsString_ConvertFromWide` |
| Caller | `0x00404b30` | Win32 fail site |
| Caller | `0x00427530` | Win32 fail site |
| Caller | `0x0050c1b0` | Win32 fail site |
| Caller | `0x00517400` | Win32 fail site |
| Caller | `0x005197b0` | Win32 fail site |
| Caller | `0x005320d0` | Win32 fail site |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| HRESULT pack `(x&0xffff)\|0x80070000` when signed >0 | **High** |
| Always throws (noreturn) | **High** |
| ThrowInfo via sealed `004048e0` / `DAT_00acc3fc` | **High** |
| Role = last-error → HRESULT throw | **High** |
| Product English symbol | **Inferred / Open** |
| Runtime / differential | Open |
