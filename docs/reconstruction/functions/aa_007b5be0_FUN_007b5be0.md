# Function record: FUN_007b5be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **Canonical name** | `FUN_007b5be0` (product: `CNDUIWindow_CompleteDtor`) |
| **Address** | `0x007b5be0` |
| **Body** | `0x007b5be0`–`0x007b5dcc` (**493 B** / `0x1ED`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / CNDUIWindow complete destructor |
| **Completion status** | **Dual-reviewed** WQ9K-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

Prior scaffold: `Named_VOG_DEBUG_STOP_007b5be0` (string-only). **Superseded** by product RTTI name `CNDUIWindow_CompleteDtor`.

## Purpose

MSVC-style **complete destructor** for **CNDUIWindow** (RTTI `.?AVCNDUIWindow@@`). Owner-debug strings, live window count decrement, free owned resources, nested CS tear, super-base `FUN_00759de0`. Does **not** free `this`.

## Signature (decompiler-derived + bytes)

```c
void __fastcall FUN_007b5be0(void* self); // ECX=this; bare RET; void
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.md`
- Annotated: `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007b5be0.cpp`
- Named record: `docs/reconstruction/functions/aa_007b5be0_CNDUIWindow_CompleteDtor.md`
- Review A/B: `A_aa_007b5be0_CNDUIWindow_CompleteDtor.md`, `B_aa_007b5be0_CNDUIWindow_CompleteDtor.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0078ca80`, `FUN_00832fa0`, `FUN_00423e50`, many UI + EH (50+) |
| Callees | `FUN_007a4480`, `FUN_007a8580`, `FUN_007aec70`, `FUN_007aff00`, `FUN_00797d70`, `operator_delete`/`[]`, `FUN_00424060`, `DeleteCriticalSection`, `FUN_00759de0` |

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + bare RET | **High** |
| Product RTTI name CNDUIWindow | **High** |
| False-noreturn corrected | **High** |
| Helper / slot English | **Low** |
| Runtime | **Open** |
