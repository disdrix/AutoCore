# Function record: PalVisibleBoundingShape_EffectMaterialInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099e6c0` |
| **Canonical name** | `PalVisibleBoundingShape_EffectMaterialInit_Inferred` |
| **Address** | `0x0099e6c0` |
| **Body** | `0x0099e6c0`–`0x0099e894` (**469 B** / `0x1D5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | mesh host FX / material init |
| **Completion status** | **Dual A/B complete** (2026-07-29 W36-H) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0099e6c0` |

## Purpose

Initialize HostPtrTable12 **slot 0** mesh host with effect **`PalVisibleBoundingShape.fx`** and four material parameters (`SolidMatDiffuse`, `SolidMatEmissive`, `WireMatDiffuse`, `WireMatEmissive`). Operates on resource handle at `self+0x20`; returns bitwise OR of stage statuses.

## Signature

```c
uint32_t __fastcall PalVisibleBoundingShape_EffectMaterialInit_Inferred(void *self /* ECX */);
```

| Slot | Source | Conf |
|---|---|---|
| self | ECX (mesh host after base ctor + dual vtbl) | **High** |
| return | EAX = status OR | **High** |
| sole caller | `FUN_0073c810` @ `0x0073c869` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.md`
- Annotated: `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PalVisibleBoundingShape_EffectMaterialInit_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0099e6c0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0099e6c0_FUN_0099e6c0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| FX path + 4 material names | **High** (image strings) |
| ABI ECX + status OR return | **High** |
| Sole caller HostPtrTable12 slot 0 | **High** |
| Unowned helper contracts | Open |
