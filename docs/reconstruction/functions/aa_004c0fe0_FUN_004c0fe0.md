# Function record: FUN_004c0fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0fe0` |
| **Canonical name** | `VOGEnvironmentLiquid_InitFilterPipeline_Inferred` |
| **Ghidra name** | `FUN_004c0fe0` |
| **Address** | `0x004c0fe0` |
| **Body range** | `0x004c0fe0`–`0x004c16cf` inclusive (**1776 B** / `0x6F0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentLiquid / particle fluid child |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (W37-F); CF/ABI/strings/slots sealed; nested helper English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md`, `reviews/B_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_004c0fe0`
- `Named_VOGEnvironmentLiquid_004c0fe0` (scaffold string-only; prefer pipeline `_Inferred` name)

## Purpose

Initialize the **0x40 liquid-environment child** filter/RT pipeline after ctor:

1. Allocate four **0x18** filter hosts → child `+0x20/+0x28/+0x30/+0x38`.
2. Load **UIFluidDownsample / BlurHorizontal / BlurVertical / SurfaceBlend** `.fx`.
3. Bind `BackBufferTexture`, set `UIMapExtents0`.
4. Allocate four **0xd4** RT hosts (full + cascaded `>>2` dims) → `+0x3c/+0x24/+0x2c/+0x34`.
5. Create buffer textures format **`0x15`** flags **`0x4011`**; wire parent `+0x98` / optional `NormalMapTexture`.
6. Pair-setup filters/RTs; enable surface-blend flag; return **0**.

Product path: `VOGEnvironmentLiquid.cpp`.

## Signature

```c
uint32_t __thiscall VOGEnvironmentLiquid_InitFilterPipeline_Inferred(
    void* liquid_child /* ECX, size 0x40 */);
// bare RET; returns 0; SEH LAB_009a1a6d
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.md` (+ W37-F append)
- Annotated: `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VOGEnvironmentLiquid_InitFilterPipeline_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c0fe0.cpp`
- Named record: `docs/reconstruction/functions/aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md`
- Report: `docs/agents/task-dual-ab-005b3520-004c0fe0-w37f-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller (sole) | `0x004c1960` | `ParticleFluidPhase_CreateLiquidChild_Inferred` (W34-O) |
| Related ctor | `0x004c1800` | liquid child ctor (zeros slots; `DAT_00b03794`) |
| Callees | many | `operator_new`, `FUN_009886d0`, `FUN_009685e0`, FX load/bind, `FUN_0096f0e0`, `FUN_007567b0`, `FUN_009888b0`, `vog_LogMessage`, … |

## Confidence

| Claim | Level |
|---|---|
| Body 1776 B + thiscall + return 0 | **Confirmed** |
| UIFluid*.fx + VOGEnvironmentLiquid.cpp plates | **Confirmed** |
| Filter/RT slot offsets | **Confirmed** |
| Dim source `DAT_00d1f058` device `+0x80/+0x84` | **Confirmed** |
| Texture fmt `0x15` / flags `0x4011` | **Confirmed** |
| Nested helper product English | **Open** |
| Clean is contract-level (not full EH rewrite) | **Noted** |
| Runtime | **Open** |
