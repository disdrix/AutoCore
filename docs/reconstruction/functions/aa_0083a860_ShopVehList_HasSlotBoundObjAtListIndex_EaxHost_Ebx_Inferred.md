# Function record: ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a860` |
| **Canonical name** | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` |
| **Ghidra name** | `FUN_0083a860` |
| **Address** | `0x0083a860`–`0x0083a87a` inclusive (**27 B** / `0x1B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh list five-slot reindex helper (parent `0x0083ac90`) |
| **Completion status** | **Dual-reviewed** WQ9L-I — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-I** |

## Purpose

Predicate for parent reindex id-match path: find five-window slot whose control id encodes `list_i` (`id - 0x9ca4 == list_i` via `FUN_0083a7d0`) and return whether `slot[+0x508] != 0`. Parent uses true → `FUN_0083a880(0)` soft refresh; false → `FUN_0083abf0` reload.

## Signature

```c
// EAX = host*; EBX = list_i; AL = bool; bare RET
uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(void);
// Portable form:
uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(void *host, int list_i);
```

## Constants / offsets

| Offset / const | Role | Conf |
|---|---|---|
| `host+0x50c[5]` | five-window slots (via finder) | **High** |
| `0x9ca4` | control-id base (via finder / parent) | **High** |
| `slot+0x508` | bound payload gate | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Sole CALL | `FUN_0083ac90` @ `0x0083adc2` |
| Callee | `FUN_0083a7d0` (undualed finder) |

## Related (not OWN)

- Parent reindex: `aa_0083ac90` `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (WQ9K-H dualed)
- Soft refresh / reload: `FUN_0083a880`, `FUN_0083abf0` (WQ9L-J OWN)
- Drive scaffold: `Drive_i_d_shopveh_2d_wnd_list_vehicle_xml`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.md`
- Annotated: `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0083a860.cpp`
- Scaffold (retired): `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a860.cpp`
- Review A: `reviews/A_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md`
- Review B: `reviews/B_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md`
- FUN record: `functions/aa_0083a860_FUN_0083a860.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (full-body bytes) | **High** |
| ABI EAX host + EBX list_i + AL bool | **High** |
| +0x508 gate / sole parent call site | **High** |
| Product English for host class | **Open** (`_Inferred`) |
| Runtime | **Open** |
