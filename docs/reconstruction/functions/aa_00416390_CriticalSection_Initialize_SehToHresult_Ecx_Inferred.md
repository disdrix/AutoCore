# Function record: CriticalSection_Initialize_SehToHresult_Ecx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416390` |
| **Canonical name** | `CriticalSection_Initialize_SehToHresult_Ecx_Inferred` |
| **Ghidra name** | `FUN_00416390` |
| **Address** | `0x00416390`–`0x0041640A` exclusive (**122 B** / `0x7A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / Win32 sync (CRITICAL_SECTION init) |
| **Classification** | worker |
| **Calling convention** | **ECX** = `LPCRITICAL_SECTION`; **EAX** = HRESULT; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-I 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00416390_CriticalSection_Initialize_SehToHresult_Ecx_Inferred.md` |
| **Dual B** | `reviews/B_aa_00416390_CriticalSection_Initialize_SehToHresult_Ecx_Inferred.md` |
| **Name confidence** | Inferred (API + SEH→HRESULT structure; no product demangle) |
| **Last reviewed** | `2026-08-04` (WQ9I-I) |

## Alias

- Ghidra: `FUN_00416390`
- Prior scaffold: partial raw/annotated/clean only
- Reject: bare `InitializeCriticalSection` thunk (no SEH/HRESULT); thiscall product method; skill/domain names

## Purpose

MSVC SEH-wrapped **`InitializeCriticalSection(cs)`** returning **HRESULT**:

| Path | EAX |
|---|---|
| Success | `0` (`S_OK`) |
| `STATUS_NO_MEMORY` (`0xC0000017`) | `0x8007000E` (`E_OUTOFMEMORY`) |
| Any other SEH | `0x80004005` (`E_FAIL`) |

## Signature

```c
HRESULT CriticalSection_Initialize_SehToHresult_Ecx_Inferred(
    /*ECX*/ LPCRITICAL_SECTION cs);
/* ret 0 */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `InitializeCriticalSection` via IAT dword `[0x009c61ec]` |
| **Callers** | `FUN_00489dc5` @ `0x00489e50` — `LEA ECX,[ESI+0x18]`; `TEST EAX,EAX` / `JGE` else `DAT_00d1f0f0 = 1` |
| **Pair** | `Mem_ZeroSixDwords_Ecx_Inferred` (`0x00416370`) pre-zeros same `+0x18` region |
| **SEH** | scope `DAT_00aaa698` filter `0x004163C4` / handler `0x004163D4`; frame `DAT_00489cb0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416390_FUN_00416390.md`
- Annotated: `docs/reconstruction/raw/aa_00416390_FUN_00416390.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CriticalSection_Initialize_SehToHresult_Ecx_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00416390.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416390_FUN_00416390.md`
- Report: `docs/agents/task-dual-ab-00416370-00416390-wq9ii-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + ret 0 + ECX/HRESULT ABI | **High** |
| InitCS IAT + success return 0 | **High** |
| SEH STATUS_NO_MEMORY → E_OUTOFMEMORY else E_FAIL | **High** (bytes) |
| Product demangle / CRT helper identity | **Inferred** |
| Runtime / bit-exact | **Open** |
