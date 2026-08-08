# Function record: ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a880` |
| **Canonical name** | `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` |
| **Ghidra name** | `FUN_0083a880` |
| **Address** | `0x0083a880` |
| **Body** | `0x0083a880`–`0x0083a94d` inclusive (**206 B** / `0xCE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh list UI (drive parent uses `i_d_shopveh_2d_wnd_list_vehicle.xml`) |
| **Completion status** | **Dual-reviewed** WQ9L-J — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-J** |

## Purpose

Apply shopveh default display quaternion to a slot object. Flag selects path:

- `0` — seed cached orient at `obj+0x5e0` and set `obj+0x5dc = 1` (reindex refresh / post-swap).
- non-zero — write into XformState via residual `FUN_0040d1a0(obj+0x510, …)` then residual post-bind helpers (bind path from `FUN_0083ab90`).

## Signature

```c
// EAX = obj*; stack uint8 flag; RET 4; void
void ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred(void *obj /* EAX */, uint8_t flag);
```

## Object / constants

| Offset / const | Role | Conf |
|---|---|---|
| `obj+0x508` | nested* (optional vtbl+0x44 / passed to `00833390`) | **High** |
| `obj+0x510` | XformState this for `FUN_0040d1a0` (quat store → `+0x590`) | **High** |
| `obj+0x5dc` | uint8 orient-seed flag (set to 1 on flag==0) | **High** |
| `obj+0x5e0` | float[4] cached orient quat | **High** |
| `DAT_00aaa97c..988` | default unit quat (‖q‖≈1; not identity) | **High** |
| `FUN_0076e5e0` | `Math_QuatNormalize` (dualed) | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (3 CALL) | `FUN_0083ac90` @ `0083ada4` / `0083ade0` (PUSH **0**); `FUN_0083ab90` @ `0083abe4` (PUSH **1**) |
| Callees | `Math_QuatNormalize` (`0076e5e0`)×2, `FUN_0040d1a0`, `FUN_00833490`, `FUN_00833390`, nested vtbl+0x44 |

## Related (not OWN)

- Parent reindex: `aa_0083ac90` `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (WQ9K-H dualed)
- Sibling match helper: `aa_0083a860` (WQ9L-I OWN — do not write)
- Bind helper: `FUN_0083ab90` (residual; calls this with flag 1)
- Sibling OWN: `aa_0083abf0` (this agent)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.md`
- Annotated: `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0083a880.cpp`
- Review A: `reviews/A_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md`
- Review B: `reviews/B_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes / disasm) | **High** |
| ABI EAX obj + stack flag + RET 4 | **High** |
| Dual flag paths + offsets | **High** |
| Default quat constants / unit norm | **High** |
| Product English for slot class | **Open** (`_Inferred`) |
| Runtime | **Open** |
