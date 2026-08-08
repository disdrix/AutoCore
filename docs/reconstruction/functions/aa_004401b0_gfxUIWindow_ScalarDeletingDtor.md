# Function record: gfxUIWindow_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004401b0` |
| **Canonical name** | `gfxUIWindow_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004401b0` |
| **Address** | `0x004401b0` |
| **Body** | `0x004401b0`–`0x004401cd` inclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / graphics — gfxUIWindow MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** MEGA-129 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for **gfxUIWindow** (RTTI `.?AVgfxUIWindow@@`). Bound as **vtbl[0]** of primary vtbl `PTR_FUN_00a9f304`. Always runs dualed complete dtor `gfxUIWindow_CompleteDtor` (`0x00759de0`); if `(flags & 1)` frees the host with `operator_delete`; returns `this` via **`RET 4`**. Does **not** contain the complete-body teardown.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall gfxUIWindow_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA `PTR_FUN_00a9f304[0]` @ `0x00a9f304` (virtual delete / explicit scalar dispatch) |
| Callees | `gfxUIWindow_CompleteDtor` (`FUN_00759de0`), `operator_delete` (`0x00489822`) |

## RTTI / vtbl

| Item | Value |
|---|---|
| Vtbl | `PTR_FUN_00a9f304` |
| Slot | `[0]` |
| COL ptr | `0x00a9f300` → COL `0x00ab96a4` |
| type_info | `0x00afe190` → `.?AVgfxUIWindow@@` |

## Artifacts

- Raw (+ MEGA-129 re-verify): `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.md`
- Annotated: `docs/reconstruction/raw/aa_004401b0_FUN_004401b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/gfxUIWindow_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004401b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004401b0_FUN_004401b0.md`
- Review A: `docs/reconstruction/reviews/A_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004401b0_gfxUIWindow_ScalarDeletingDtor.md`
- Complete peer: `aa_00759de0_gfxUIWindow_CompleteDtor.md` (WQ9L-F)

## Confidence

| Claim | Level |
|---|---|
| Scalar-deleting CF/ABI/RET 4 | **High** |
| vtbl[0] + RTTI product name | **High** |
| Complete-then-optional-free contract | **High** |
| Complete dtor internals | **Not owned** (peer dualed) |
| Runtime | **Open** |
