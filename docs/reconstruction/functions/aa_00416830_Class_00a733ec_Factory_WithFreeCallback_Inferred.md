# Function record: Class_00a733ec_Factory_WithFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416830` |
| **Canonical name** | `Class_00a733ec_Factory_WithFreeCallback_Inferred` |
| **Ghidra name** | `FUN_00416830` |
| **Address** | `0x00416830` |
| **Body** | `0x00416830`–`0x00416892` inclusive (**99 B** / `0x63`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Class_00a733ec heap factory |
| **Completion status** | **Dual-reviewed** WQ9K-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-H** |

## Purpose

`operator_new(0x14)` then init:
- `+0` = `PTR_FUN_00a733ec`
- `+4` = context arg
- `+8` / `+0xc` = 0
- `+0x10` = `LAB_00573240` (cdecl free: scalar-delete context if non-null)

Null-new returns null. **`RET 4`**.

## Signature

```c
// stack context; RET 4; returns Class_00a733ec* or null
void *Class_00a733ec_Factory_WithFreeCallback_Inferred(void *context);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | **none** recovered (0 CALL xrefs) |
| Callees | `operator_new` |
| DATA | writes vtbl `0x00a733ec`; embeds free cb `0x00573240` |

## Related (not OWN)

- Scalar dtor (vtbl[0]): `aa_00416f00` `Class_00a733ec_ScalarDeletingDtor_Inferred` (WQ9J-E dualed)
- Null-callback twin factory: `FUN_004168c0` (WQ9K-I OWN)
- Free thunk body: `LAB_00573240` (not a function symbol)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416830_FUN_00416830.md`
- Annotated: `docs/reconstruction/raw/aa_00416830_FUN_00416830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_WithFreeCallback_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416830.cpp`
- Review A: `reviews/A_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md`
- Review B: `reviews/B_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| Size 0x14 + field writes | **High** |
| ABI stack arg + RET 4 + return ptr | **High** |
| Free cb scalar-delete semantics | **High** (bytes @ 00573240) |
| Vtbl binding to dualed dtor | **High** |
| Product English / call sites | **Open** |
| Runtime | **Open** |
