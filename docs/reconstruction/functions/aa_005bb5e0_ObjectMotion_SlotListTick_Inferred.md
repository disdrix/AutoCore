# Function record: ObjectMotion_SlotListTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bb5e0` |
| **Canonical name** | `ObjectMotion_SlotListTick_Inferred` |
| **Ghidra name** | `FUN_005bb5e0` |
| **Address** | `0x005bb5e0`–`0x005bb666` |
| **Module** | `autoassault.exe` |
| **System** | client object motion / reaction slot list |
| **Completion status** | **dual-sealed** 2026-07-29 W27-D |
| **Dual A/B** | `reviews/A_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md`, `reviews/B_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` |

## Purpose

Sole list walker over motion host `+0xA24` calling dualed SlotTick; remove contract 0 → unlink + delete + `+0xA28--`.

```c
uint32_t __thiscall ObjectMotion_SlotListTick_Inferred(void *motion_host, float *dt, uint32_t flag);
// ret 8; returns remaining count
```

## Artifacts

- Named: `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotListTick_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005bb5e0.cpp`

## Callers

| Caller | Site | Notes |
|---|---|---|
| `NDSpecialFX_HostTick_Inferred` | `0x004b9103` | after `FUN_005bc3c0` keep on `+0x1E0` child |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / count-- | **Confirmed** |
| SlotTick linkage | **Confirmed** (W26-H) |
| Product English | **Inferred** |
