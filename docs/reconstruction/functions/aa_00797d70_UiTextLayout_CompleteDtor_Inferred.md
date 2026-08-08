# Function record: UiTextLayout_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797d70` |
| **Canonical name** | `UiTextLayout_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00797d70` |
| **Address** | `0x00797d70` |
| **Body** | `0x00797d70`–`0x00797e17` (**168 B** / `0xA8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI — owned text-layout block complete destructor |
| **Completion status** | **Dual-reviewed** WQ9L-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style complete destructor for the text-layout block owned by UI windows (notably CNDUIWindow `+0x28C`). Finalizes metrics/layout, frees buffer and run vectors, destroys embedded `wstring`. No product RTTI on this helper — name is **inferred** from CF + ownership. Reject scaffold parent-seed name tying it only to `VOG_DEBUG_STOP`.

## Signature

```c
// layout* on stack. SEH LAB_009add5a. RET 4 (C2 04 00). void.
void __stdcall UiTextLayout_CompleteDtor_Inferred(void* layout);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `CNDUIWindow_CompleteDtor`, `FUN_007aff00`, text mutate/rebuild paths |
| Callees | `FUN_00797530(1)`, `operator_delete`, `FUN_004271c0`, `~basic_string<wchar_t>` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.md`
- Annotated: `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiTextLayout_CompleteDtor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00797d70.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00797d70_FUN_00797d70.md`
- Owner complete: `aa_007b5be0_CNDUIWindow_CompleteDtor.md` (WQ9K-F)

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free host) | **High** |
| ABI stack + RET 4 | **High** |
| Object offsets sealed | **High** |
| Product class demangle | **Open** |
| Runtime | **Open** |
