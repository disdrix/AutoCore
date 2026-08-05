# Function record: StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a74f0` |
| **Canonical name** | `StdUninitFillN_BasicStringW` (**Inferred**) |
| **Ghidra name** | `FUN_004a74f0` |
| **Address** | `0x004a74f0`–`0x004a757c` exclusive (**140 B** / `0x8C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / MSVC `_Uninit_fill_n` `basic_string<wchar_t>` stride `0x1c` |
| **Completion status** | Dual A/B sealed W36-R 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC-style **`_Uninit_fill_n`** for `basic_string<wchar_t>` elements size **0x1c**: placement copy-ctor of `*value` into `dest` for `count` slots. Full SEH loop (not a thin thiscall rebind like char `StdUninitFillN_BasicString` @ `0x00430390`). Used by insert-n fill arms and related wstring-vector helpers.

## Signature

```c
// cdecl; stack dest*, count, value*; bare RET; void
void StdUninitFillN_BasicStringW(
    BasicStringW_0x1c* dest,
    int count,
    const BasicStringW_0x1c* value);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23 happy-path CF
- Full body hex via `read_memory` (140 B); stride imm `0x1C`; bare `C3`
- 3 xrefs: `FUN_004a7ad0`, `FUN_004a7a70`, `FUN_004a8100`
- Dual A/B **accept-with-gaps**

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a74f0_FUN_004a74f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdUninitFillN_BasicStringW.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004a74f0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_004a74f0_FUN_004a74f0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| Scratch | `docs/reconstruction/tmp/a_004a74f0.md` |
