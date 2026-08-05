# Function record: StdUninitCopy_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6b50` |
| **Canonical name** | `StdUninitCopy_BasicStringW` (**Inferred**) |
| **Ghidra name** | `FUN_004a6b50` |
| **Address** | `0x004a6b50`–`0x004a6bdc` exclusive (**140 B** / `0x8C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / MSVC `_Uninit_copy` `basic_string<wchar_t>` stride `0x1c` |
| **Completion status** | Dual A/B sealed W36-R 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`_Uninit_copy`** for `basic_string<wchar_t>` elements size **0x1c**: placement copy-ctor over `[first, last)` into `dest`, return dest-end. SEH-guarded with catch destroy + `_CxxThrowException`. Used by `StdVector_InsertN_BasicStringW` (`0x004a7ad0`, W34-R) on grow/hole relocate arms.

## Signature

```c
// cdecl; stack first*, last*, dest*; bare RET; EAX = dest_end
BasicStringW_0x1c* StdUninitCopy_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last,
    BasicStringW_0x1c* dest);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 happy-path CF
- Full body hex via `read_memory` (140 B); stride imm `0x1C`; bare `C3`
- 4 xrefs / sole parent `FUN_004a7ad0`; IAT ctor/dtor + `_CxxThrowException` sealed
- Char twin `StdUninitCopy_BasicString` (`0x0046a2c0`, W33-G) — same shape
- Dual A/B **accept-with-gaps**

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.md` |
| Annotated | `docs/reconstruction/raw/aa_004a6b50_FUN_004a6b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitCopy_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a6b50.cpp` |
| FUN record | `docs/reconstruction/functions/aa_004a6b50_FUN_004a6b50.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| Scratch | `docs/reconstruction/tmp/a_004a6b50.md` |
