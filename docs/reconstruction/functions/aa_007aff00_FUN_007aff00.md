# Function record: FUN_007aff00

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **Canonical name** | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` |
| **Ghidra name** | `FUN_007aff00` |
| **Address** | `0x007aff00`–`0x007aff51` (**82 B** / `0x52`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIWindow complete-dtor helper |
| **Completion status** | **Dual A/B sealed** (WQ9L-G, 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Rejected alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00` |

## Purpose

Partial teardown leaf of `CNDUIWindow_CompleteDtor`: gated free of owned text layout at `+0x28C`, nested CS-list clear at `+0x1E8`, zero `+0x128`/`+0x12C`.

## Signature

```c
// ECX = this; bare RET (C3); void
void __fastcall FUN_007aff00(void* self);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.md`
- Annotated: `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_007aff00.cpp`
- Named record: `docs/reconstruction/functions/aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md`

## Callers / callees

- **Callers (code):** `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` @ `0x007b5c8a`
- **DATA xrefs:** many subclass vtbl slots
- **Callees:** `UiTextLayout_CompleteDtor_Inferred` (`FUN_00797d70`), `operator_delete`, `FUN_00424060`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | High |
| Nested LEA ECX correction | High |
| Gated layout free | High |
| Parameter product English | Tentative (`_Inferred`) |
| Runtime Confirmed | Open (terminal false) |
