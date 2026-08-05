# Function record: CVOGEnvironmentReflect_InitBufferedViewChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3420` |
| **Canonical name** | `CVOGEnvironmentReflect_InitBufferedViewChild_Inferred` |
| **Address** | `0x005b3420` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / CVOGEnvironmentReflect / gfxBufferedView |
| **Completion status** | **Dual-reviewed** — raw/annotated/clean + A/B reviews (2026-08-04 W37-M) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Install the Reflect host’s **buffered-view** child: `new(0x198)` + `gfxBufferedView` ctor → store at **`host+0x158`**, parent link **`child+4`**, configure near/far/resource/flags, call **vtbl+0x18** with **(256,256)**. Sole consumer is Reflect Enable (W33-T).

## Signature (ABI-corrected)

```c
void __fastcall CVOGEnvironmentReflect_InitBufferedViewChild_Inferred(void *self /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.md`
- Annotated: `docs/reconstruction/raw/aa_005b3420_FUN_005b3420.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005b3420_CVOGEnvironmentReflect_InitBufferedViewChild_Inferred.md`

## Callers / callees

- **Callees:** `operator_new`, `FUN_00968a50`, `FUN_0075b3b0` (`GfxView_SetNear_Inferred`), `FUN_0075bf40`, `FUN_0075b450`, `FUN_0075b390`, vtbl+`0x18`.
- **Callers (1):** `FUN_005b39a0` (`CVOGEnvironmentReflect_Enable_Inferred`).

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / body bounds | **Confirmed** |
| gfxBufferedView RTTI | **Confirmed** |
| near 0.5 / far 1e5 / 256×256 pair | **Confirmed** |
| Nested helper product English | **Open** |
