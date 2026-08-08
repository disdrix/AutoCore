# Function record: Class_00a733ec_Factory_NullFreeCallback_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004168c0` |
| **Canonical name** | `Class_00a733ec_Factory_NullFreeCallback_Inferred` |
| **Ghidra name** | `FUN_004168c0` |
| **Address** | `0x004168c0` |
| **Body** | `0x004168c0`–`0x0041691f` inclusive (**96 B** / `0x60`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Class_00a733ec factory (null free-callback variant) |
| **Completion status** | **Dual-reviewed** WQ9K-I — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-I** |

## Purpose

MSVC-style heap factory for the class whose primary vtbl is `PTR_FUN_00a733ec`. Allocates **0x14** bytes, stamps vtbl, stores caller **context** at `+0x04`, zeros `+0x08`/`+0x0c`, and leaves free-callback at `+0x10` as **null** so the scalar dtor skips the optional free path.

Twin factory `FUN_00416830` (WQ9K-H) differs only by installing `LAB_00573240` at `+0x10`.

## Signature

```c
// 1 stack arg; RET 4; returns object* in EAX (null on OOM)
void *Class_00a733ec_Factory_NullFreeCallback_Inferred(void *context);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | **0** recovered (Ghidra); structural seal via twin + vtbl family |
| Callees | `operator_new(0x14)` |

## Related (not all OWN)

- Twin factory: `FUN_00416830` @ `0x00416830` (WQ9K-H)
- Scalar dtor: `Class_00a733ec_ScalarDeletingDtor_Inferred` @ `0x00416f00`
- Vtbl: `PTR_FUN_00a733ec` @ `0x00a733ec` → `[0]=0x00416f00`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.md`
- Annotated: `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_NullFreeCallback_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004168c0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004168c0_FUN_004168c0.md`
- Review A: `reviews/A_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md`
- Review B: `reviews/B_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Factory CF + ABI | **High** |
| Null free-cb vs twin | **High** |
| Vtbl family link | **High** |
| Product English | **Open** |
| Caller recovery | **Open** |
| Runtime | **Open** |
