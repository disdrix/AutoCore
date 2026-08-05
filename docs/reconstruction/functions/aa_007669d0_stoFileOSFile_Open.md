# Function record: stoFileOSFile_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007669d0` |
| **Canonical name** | `stoFileOSFile_Open` (class/file **Confirmed**; method Open **Inferred**) |
| **Ghidra name** | `FUN_007669d0` |
| **Address** | `0x007669d0` |
| **Body** | `0x007669d0`–`0x00766d8c` exclusive (**956 B** / `0x3BC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | arda2 storage OS file open |
| **Completion status** | **Dual-reviewed** W37-E — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

`stoFileOSFile` open worker: store mode, optionally remap `.ogg`/`.dds` paths under quality settings, `CreateFileA` with mode-dependent access/disposition, stash HANDLE, return 0/-1. Fail path formats system error and logs via `vog_LogMessage` against `stoFileOSFile.cpp:0xB9`.

## Signature

```c
// ECX = this; stack path*, mode, dwFlagsAndAttributes; RET 0x0C
int32_t __thiscall stoFileOSFile_Open(
    stoFileOSFile* self,
    const char* path,
    uint32_t mode,
    DWORD attrs);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`89 4C 24 10` save) | **High** |
| path | stack | **High** |
| mode | stack → `this+4` | **High** |
| attrs | stack → CreateFile 6th arg | **High** |
| return 0/-1 | `33 C0` / `83 C8 FF` | **High** |
| cleanup | dual `C2 0C 00` | **High** |

## Mode matrix

| mode | access | disposition |
|---|---|---|
| 0 | — | fail immediately |
| 1 | `0x20001` | `OPEN_EXISTING` (3) |
| 2 | `0x20006` | `OPEN_EXISTING` (3) |
| 3 | `0x20007` | `OPEN_EXISTING` (3) |
| 4,5 | `0` | `OPEN_EXISTING` (3) |
| 6 | `0x20006` | `CREATE_ALWAYS` (2) |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | 10 funcs / 14 sites (see scaffold record) — includes path-list open mode 1, pack extract write mode 6 |
| Callees | `FUN_007a69d0`, CRT `strstr`/`fopen`/`fclose`, Win32 CreateFile/GetLastError/FormatMessage, `FUN_0076cec0`, `vog_LogMessage` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.md` (W37-E append)
- Annotated: `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/stoFileOSFile_Open.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007669d0.cpp`
- Scaffold: `docs/reconstruction/functions/aa_007669d0_FUN_007669d0.md`
- Review A: `docs/reconstruction/reviews/A_aa_007669d0_stoFileOSFile_Open.md`
- Review B: `docs/reconstruction/reviews/B_aa_007669d0_stoFileOSFile_Open.md`
- Scratch: `docs/reconstruction/tmp/a_007669d0.md`

## Confidence

| Claim | Level |
|---|---|
| Open CF + CreateFile matrix | **High** |
| ABI RET 0x0C | **High** |
| stoFileOSFile plate | **High** |
| Quality remap details | **High** (CF); 5th DDS table string **Med** |
| Exact C++ method name | **Med** |
