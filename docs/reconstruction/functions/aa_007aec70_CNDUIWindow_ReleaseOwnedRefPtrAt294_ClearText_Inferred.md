# Function record: CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **Canonical name** | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` |
| **Ghidra name** | `FUN_007aec70` |
| **Address** | `0x007aec70`–`0x007aecc3` (**84 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIWindow complete-dtor helper |
| **Completion status** | **Dual A/B sealed** (WQ9L-G, 2026-08-05) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Rejected alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70` |

## Purpose

Release optional owned RefCountedPtr heap shell at `CNDUIWindow+0x294` (flag `+0xBB`), clear text via `vtbl[+0x2B4]("")` using shared empty literal `DAT_00a1419b`, zero `+0x29C`/`+0x2A0`. Called from `CNDUIWindow_CompleteDtor` between `FUN_007a8580` and `FUN_007aff00`.

## Signature

```c
void __fastcall CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(void* self /*ECX*/);
```

## Naming basis

- Parent RTTI / complete dtor: `CNDUIWindow` (`PTR_FUN_00a960ac`, `.?AVCNDUIWindow@@`).
- Callee sealed name: `RefCountedPtr_Dtor_Inferred` (`0x0096efd0`).
- No product demangle on this VA → `_Inferred`.
- Scaffold VOG_DEBUG_STOP alias rejected (parent debug only).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.md`
- Annotated: `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007aec70.cpp`
- Ghidra record: `docs/reconstruction/functions/aa_007aec70_FUN_007aec70.md`
- Reviews A/B: `docs/reconstruction/reviews/A_aa_007aec70_…` / `B_aa_007aec70_…`

## Gaps

- Product English for `vtbl[+0x2B4]` and shell class.
- Semantic names for `+0x29C` / `+0x2A0`.
- Runtime / bit-exact / differential.
