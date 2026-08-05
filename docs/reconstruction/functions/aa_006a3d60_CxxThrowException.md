# Function record: _CxxThrowException

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d60` |
| **Canonical name** | `_CxxThrowException` |
| **Address** | `0x006a3d60` |
| **Body range** | `0x006a3d60`–`0x006a3d65` (6 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CRT / MSVC C++ EH |
| **Completion status** | **complete-for-thunk** — dual A/B **accept**; import trampoline sealed |
| **Bit-for-bit / runtime / diff** | N/A (external CRT); IAT bind may vary at load |
| **Dual A/B** | `reviews/A_aa_006a3d60_CxxThrowException.md`, `reviews/B_aa_006a3d60_CxxThrowException.md` |
| **Last reviewed** | `2026-07-29` |

## Purpose

Named import trampoline for MSVC `_CxxThrowException`. Entire body is `jmp [IAT]`. Used by C++ throw sites across the binary. No game domain logic.

## Signature

```c
__declspec(noreturn)
void __stdcall _CxxThrowException(void *pExceptionObject, ThrowInfo *pThrowInfo);
```

## Layout / algorithm

1. `jmp dword ptr [0x009c64d8]`  
2. IAT slot holds CRT implementation pointer (observed `0x006ebcee` in static dump).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.md`
- Annotated: `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CxxThrowException.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-006a3d60-cxxthrowexception-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | CRT via IAT only |
| **Callers** | Ubiquitous throw sites (not exhaustively listed) |

## Confidence

| Claim | Level |
|---|---|
| 6-byte `jmp [IAT]` form | **High** |
| Symbol `_CxxThrowException` | **High** |
| Noreturn / stdcall CRT contract | **High** (standard MSVC) |
| No game logic in body | **High** |
| Live IAT target address | **Medium** (image/load dependent) |

## Related

- Any unit that throws (e.g. `aa_004048e0` and family) calls this trampoline.
- Do not re-dual MSVC EH tables under this VA unless scoped separately.
