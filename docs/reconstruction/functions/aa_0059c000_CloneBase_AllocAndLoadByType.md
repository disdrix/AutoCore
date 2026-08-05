# Function record: CloneBase_AllocAndLoadByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059c000` |
| **Canonical name** | `CloneBase_AllocAndLoadByType` |
| **Ghidra name** | `FUN_0059c000` |
| **Address** | `0x0059c000` |
| **Body range** | `0x0059c000`–`0x0059c443` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | gamedata / clonebase materialize |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + type map sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0059c000_CloneBase_AllocAndLoadByType.md`, `reviews/B_aa_0059c000_CloneBase_AllocAndLoadByType.md` |
| **Last reviewed** | `2026-07-29` (W19-F) |

## Alias

- `FUN_0059c000` (Ghidra)
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c000` (auto parent-seed — **misleading**; parent logs VOG_DEBUG_STOP only on **failure**)

## Purpose

Materialize a **typed clonebase payload** for a catalog **record**:

1. Optional cache fill via `FUN_00540850(cbid)` when `DAT_00b04694` set.
2. Else switch on `record+0x38` type → `operator_new` + ctor/vtbl + type-specific DB loader → store at `record+0x3c`.
3. On success, convert/copy names into `obj+0x10`, `record+0x40`, `record+0x188`; return **0**.
4. Unknown type → **`0x80004005` (`E_FAIL`)**; loader error → loader status.

## Signature

```c
// cdecl (stack arg, bare ret)
int32_t CloneBase_AllocAndLoadByType(int /*CloneBaseRecord**/ rec);
```

## Algorithm

1. SEH frame install.
2. If cache flag: lookup by `+0x34`; non-null → name fill.
3. Switch type (`+0x38`) over sealed case set (generic / 8 / 10 / 0xc|0x18 / 0xe vehicle / 0x10 / 0x12 / 0x14 / 0x1a / 0x1c / 0x32 / default).
4. Propagate non-zero loader status; else name fill + return 0.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.md`
- Annotated: `docs/reconstruction/raw/aa_0059c000_FUN_0059c000.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CloneBase_AllocAndLoadByType.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0059c000.cpp`
- Legacy alias plate: `reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0059c000.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0059c000-004ce5f0-w19f-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callers** | `FUN_004f1e20` @ `0x004f1e71` (CS-protected ensure-load); `FUN_004eb0c0` @ `0x004eb0e1` |
| **Callees** | `operator_new`; typed ctors; `VehicleDb_LoadCloneBase`; `DB_ReadPowerPlantSpecific`; loaders `FUN_007e*`; `FUN_00540850`; `FUN_00403450`; `strncpy`; `free`; case `0x14` → `FUN_0059b620` |

## Confidence

| Claim | Level |
|---|---|
| cdecl stack-arg + bare ret | **High** |
| Type switch + alloc sizes | **High** |
| Default `E_FAIL` `0x80004005` | **High** (bytes) |
| Vehicle type `0xe` → `VehicleDb_LoadCloneBase` | **High** |
| Record `+0x34/+0x38/+0x3c/+0x40/+0x188` map | **High** |
| Product/PDB symbol | Open |
| Full type→product-class English | Open / partial (vehicle, powerplant named) |
| Cache flag English (`DAT_00b04694`) | Open |

## Related

- `VehicleDb_LoadCloneBase` (type 0xe loader body — other VA)
- `GameData_LookupCloneBaseByCbid` (`0x00404d70`)
- Parent ensure-load `FUN_004f1e20`
