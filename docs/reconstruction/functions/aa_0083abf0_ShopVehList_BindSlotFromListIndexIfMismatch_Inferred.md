# Function record: ShopVehList_BindSlotFromListIndexIfMismatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083abf0` |
| **Canonical name** | `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` |
| **Ghidra name** | `FUN_0083abf0` |
| **Address** | `0x0083abf0` |
| **Body** | `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shopveh list UI (drive parent uses `i_d_shopveh_2d_wnd_list_vehicle.xml`) |
| **Completion status** | **Dual-reviewed** WQ9L-J — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-J** |

## Purpose

Conditional bind: resolve list-index entity via residual list lookup, and only if the target slot is unbound or bound to a different entity id, call residual bind worker `FUN_0083ab90`. Already-matching binds are no-ops. Sole caller is dualed reindex parent `FUN_0083ac90`.

## Signature

```c
// ECX = slot [0..4]; EDX = list_i; stack host*; RET 4; void
void ShopVehList_BindSlotFromListIndexIfMismatch_Inferred(int slot, int list_i, void *host);
```

## Host / slot layout

| Offset | Role | Conf |
|---|---|---|
| `host+0x508` | nested* (must non-null) | **High** |
| `nested+0x50` | gate int (must non-zero) | **High** |
| `nested+0x2c` | list container for `FUN_00427d20` | **High** |
| `host+0x50c` | `void* slots[5]` | **High** |
| `slot+0x508` | nested* (0 → unbound) | **High** |
| `slot+0x50c` | bound entity id (vs entity vtbl+0x1d4) | **High** |
| entity vtbl `+0x1d4` | GetEntityId-like | **High** (role); English open |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (3 CALL) | `FUN_0083ac90` only @ `0083ad5a`, `0083adb7`, `0083add0` |
| Callees | `FUN_00427d20`, `FUN_0083ab90`, entity vtbl `+0x1d4` (×1–3) |

## Related (not OWN)

- Parent reindex: `aa_0083ac90` `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (WQ9K-H dualed)
- Bind worker: `FUN_0083ab90` (residual; ends with OWN `0083a880(1)`)
- Sibling match helper: `aa_0083a860` (WQ9L-I OWN — do not write)
- Sibling OWN: `aa_0083a880` (this agent)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.md`
- Annotated: `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0083abf0.cpp`
- Review A: `reviews/A_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md`
- Review B: `reviews/B_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes / disasm) | **High** |
| ABI ECX/EDX + stack host + RET 4 | **High** |
| Gates + five slots + nested+0x2c | **High** |
| Mismatch bind via ab90 | **High** |
| Product English for host/entity | **Open** (`_Inferred`) |
| Runtime | **Open** |
