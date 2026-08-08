# Function record: CNDUIWindow_ReleaseTextLayoutAndNested_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **Canonical name** | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` |
| **Ghidra name** | `FUN_007aff00` |
| **Address** | `0x007aff00`–`0x007aff51` (**82 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIWindow complete-dtor helper |
| **Completion status** | **Dual A/B sealed** (WQ9L-G, 2026-08-05) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Rejected alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00` |

## Purpose

When gate `+0x20C` is set, complete-dtor + delete owned text layout at `+0x28C`; always clear nested CS-guarded list at `+0x1E8` via `FUN_00424060` and zero `+0x128`/`+0x12C`. Called from `CNDUIWindow_CompleteDtor` after `FUN_007aec70`. Parent may free `+0x28C` again and later restamp nested vtbl + `DeleteCriticalSection`.

## Signature

```c
void __fastcall CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(void* self /*ECX*/);
```

## Naming basis

- Parent RTTI / complete dtor: `CNDUIWindow`.
- Layout dtor sealed name: `UiTextLayout_CompleteDtor_Inferred` (`0x00797d70`, WQ9L-F).
- No product demangle on this VA → `_Inferred`.
- Scaffold VOG_DEBUG_STOP alias rejected.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.md`
- Annotated: `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_007aff00.cpp`
- Ghidra record: `docs/reconstruction/functions/aa_007aff00_FUN_007aff00.md`
- Reviews A/B: `docs/reconstruction/reviews/A_aa_007aff00_…` / `B_aa_007aff00_…`

## Gaps

- Product English for gate `+0x20C` and fields `+0x128`/`+0x12C`.
- Nested object class at `+0x1E8`.
- Runtime / bit-exact / differential.
