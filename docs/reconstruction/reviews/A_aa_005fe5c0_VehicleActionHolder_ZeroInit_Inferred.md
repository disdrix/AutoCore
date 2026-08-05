# Review A (reconstruction fidelity): `aa_005fe5c0` VehicleActionHolder_ZeroInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe5c0` |
| **VA** | `0x005fe5c0` |
| **Canonical name** | `VehicleActionHolder_ZeroInit_Inferred` (was `FUN_005fe5c0`) |
| **Ghidra symbol** | `FUN_005fe5c0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — vehicle residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe5c0_VehicleActionHolder_ZeroInit_Inferred.md` |
| **System** | input-drive-control / vehicle action holder |
| **Callers** | **Sole:** `Vehicle_createVehicleAction` `0x004fb660` |
| **Callees** | `FUN_0063f5b0` → `FUN_005edf20` (thin pass-through / debug stub) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Zero-initialize the vehicle action holder** allocated by `operator_new(0xC)` immediately after createVehicleAction stores it at `entity+0x1a0`.

Live body:

```
FUN_0063f5b0();           // returns arg; chains FUN_005edf20 (no field writes observed)
*holder = 0;              // +0x00 VehicleAction*
holder[1] = 0;            // +0x04 hkVehicleFramework*
holder[2] = 0;            // +0x08 driver input*
*(byte*)(holder+3) = 0;   // +0x0c flag byte
return holder;
```

Creates a clean triple before fill-in: action / framework / analog driver input (see createVehicleAction verified plate).

**Note:** parent uses `operator_new(0xC)` (12 bytes) while decompile writes a byte at **+0x0c** (13th byte). Either heap rounding absorbs it, alloc is effectively larger, or the flag write is borderline OOB — residual. Product intent: three null pointers + optional trailing flag.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005fe5c0` |
| Stub chain | `batch_decompile` `0x0063f5b0` |
| Callers | `get_function_callers` → only `004fb660` |
| Layout plate | `fn_004fb660_createVehicleAction.md` (holder +0/+4/+8) |
| Related dual | `A_aa_004fb660_Vehicle_createVehicleAction.md` (open: name this unit) |

---

## 3. Signature

```c
// ECX = freshly allocated holder (typically 0xC from createVehicleAction)
undefined4 *__fastcall VehicleActionHolder_ZeroInit(undefined4 *holder);
// returns holder
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Zeros three dwords at +0/+4/+8 | **High** |
| Writes byte at +0xc | **High** CF |
| Sole caller createVehicleAction | **High** |
| Not a full VehicleAction ctor | **High** (no vtbl, no 0x48 heap) |
| FUN_0063f5b0 is side-effect free for fields | **High** (pass-through) |
| Exact alloc size vs +0xc write | **Open** residual |

**Verdict:** **accept-with-gaps**
