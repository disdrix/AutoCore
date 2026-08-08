# Function record: ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083ac90` |
| **Canonical name** | `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` |
| **Ghidra name** | `FUN_0083ac90` |
| **Address** | `0x0083ac90` |
| **Body** | `0x0083ac90`–`0x0083aeb4` inclusive (**549 B** / `0x225`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh list UI (drive parent uses `i_d_shopveh_2d_wnd_list_vehicle.xml`) |
| **Completion status** | **Dual-reviewed** WQ9K-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-H** |

## Purpose

After select changes, realign `host+0x50c[5]` so each non-null slot's control id encodes the list index for that window cell (`id = list_i + 0x9ca4`). Mismatched occupancy is resolved by swapping two slot objects via dualed `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` (this VA is the swap's **sole** CALL site @ `0x0083ad72`). Out-of-range leading/trailing slots are cleared to id `-1`.

## Signature

```c
// EAX = select_index; stack host*; RET 4; void
void ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred(void *host /* + EAX select */);
```

## Host / constants

| Offset / const | Role | Conf |
|---|---|---|
| `host+0x4fc` | list count bound | **High** |
| `host+0x500` | select index (written) | **High** |
| `host+0x50c` | `void* slots[5]` | **High** |
| `0x9ca4` | control-id base | **High** |
| window radius | select±2 → 5 slots | **High** |
| `obj+0x508` | nested payload gate for clear | **High** |
| vtbl `+0x74` / `+0x78` | SetId / GetId | **High** |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (4 CALL) | `FUN_0083aff0` @ `0083af5f`; parent @ `0083b311`; `FUN_0088d8b0` @ `0088d8f3`; `FUN_0088d910` @ `0088d962` |
| Callees | `FUN_00833160` (swap), `FUN_0083a860`, `FUN_0083a880`, `FUN_0083abf0`, `FUN_00833d50`, vtbl+0x74/0x78 |

## Related (not OWN)

- Swap: `aa_00833160` `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` (WQ9J-D dualed)
- Drive scaffold: `Drive_i_d_shopveh_2d_wnd_list_vehicle_xml` (`FUN_0083aff0`)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.md`
- Annotated: `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0083ac90.cpp`
- Review A: `reviews/A_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md`
- Review B: `reviews/B_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes / disasm) | **High** |
| ABI EAX select + stack host + RET 4 | **High** |
| Five-slot window map + 0x9ca4 id | **High** |
| Sole caller of 00833160 | **High** |
| Product English for host class | **Open** (`_Inferred`) |
| Runtime | **Open** |
