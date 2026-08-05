# Function record: GfxBody_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00763f60` |
| **Canonical name** | `GfxBody_CompleteDtor_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00763f60` |
| **Address** | `0x00763f60` |
| **Body** | `0x00763f60`–`0x0076402d` inclusive (**206 B** / `0xCE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics-body composite complete dtor |
| **Completion status** | **Dual-reviewed** W31-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style **complete destructor** for the graphics-body class keyed by vtbl `PTR_LAB_00a9da8c`: install vtbl, nested gfx teardown (`FUN_00763740`), destroy subobject vector @ `+0x128`, free ptr-vector @ `+0xDC`, free buffer triples @ `+0xD0` and `+0xC0`, aligned free host @ `+0x98`, base complete dtor `FUN_0096d7a0`. Does **not** free `this`.

Matching ctor: `FUN_00764030` (same vtbl). Embedded ×3 in `ListTrackedObj` @ `+0x30` / `+0x17C` / `+0x2C8` (W30-P).

## Signature

```c
// ECX = this. SEH LAB_009b0ac6. ADD ESP,0x10; RET. void.
void __fastcall GfxBody_CompleteDtor_Inferred(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `ListTrackedObj_CompleteDtor` (`0x004be2a0`) ×3; `FUN_004bd310`; `FUN_004b6ab0`; `FUN_004eb0f0`; `FUN_00581e20`; `FUN_0058e190`; `FUN_005b3fa0`; SEH unwinds |
| Callees | `FUN_00763740`, `FUN_004380f0`, `FUN_00968110`, `operator_delete`, `FUN_0096aec0`, `FUN_0096d7a0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.md`
- Annotated: `docs/reconstruction/raw/aa_00763f60_FUN_00763f60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxBody_CompleteDtor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00763f60.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00763f60_GfxBody_CompleteDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00763f60_GfxBody_CompleteDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00763f60_FUN_00763f60.md`

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role (no free this) | **High** |
| ABI ECX + SEH + `ADD ESP,0x10; RET` | **High** |
| Vtbl `00a9da8c` + offset map | **High** |
| Stage order ≡ bytes | **High** |
| Product class English / demangle | **Low** |
| Nested callee product types | **Low** |
