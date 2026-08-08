# Function record: FUN_007aec70

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **Canonical name** | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` |
| **Ghidra name** | `FUN_007aec70` |
| **Address** | `0x007aec70`–`0x007aecc3` (**84 B** / `0x54`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIWindow complete-dtor helper |
| **Completion status** | **Dual A/B sealed** (WQ9L-G, 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Rejected alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70` |

## Purpose

Partial teardown leaf of `CNDUIWindow_CompleteDtor`: optionally destroy/delete owned RefCountedPtr shell at `+0x294`, clear text via `vtbl[+0x2B4]("")`, zero `+0x29C`/`+0x2A0`.

## Signature

```c
// ECX = this; bare RET (C3); void
void __fastcall FUN_007aec70(void* self);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.md`
- Annotated: `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_007aec70.cpp`
- Named record: `docs/reconstruction/functions/aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md`

## Callers / callees

- **Callers (code):** `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c83`
- **DATA xrefs:** many subclass vtbl slots
- **Callees:** `RefCountedPtr_Dtor_Inferred` (`FUN_0096efd0`), `operator_delete`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | High |
| ECX this / bare RET | High |
| Ownership flag gate | High |
| Parameter product English | Tentative (`_Inferred`) |
| Runtime Confirmed | Open (terminal false) |
