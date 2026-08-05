# Review A (reconstruction fidelity): `aa_005d4050` VehiclePhys_SetModeHelper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4050` |
| **VA** | `0x005d4050` |
| **Canonical name** | `VehiclePhys_SetModeHelper_Inferred` (was `FUN_005d4050`) |
| **Ghidra symbol** | `FUN_005d4050` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — vehicle residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d4050_VehiclePhys_SetModeHelper_Inferred.md` |
| **System** | input-drive-control / vehicle phys mode |
| **Callers** | `Vehicle_createVehicleAction` `0x004fb660` (mode **1**), `FUN_005d4240`, `FUN_005d4700` |
| **Callees** | mode-object vtbl+0x1c (query id), heap alloc via `DAT_00b05060` vtbl+0x10, `FUN_0063f400` (mode-2 ctor), COM release |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Set / replace physics mode-helper COM** at `this+0x54` (this = physics object / chassis wrapper that `createVehicleAction` and `DestroyVehicleAction` also touch as `entity+8`).

Live CF:

```
// Early-out if current helper reports same mode id
if (this+0x54 != null && (**(this+0x54)->vtbl+0x1c)() == mode)
  return;

if (mode == 1):
  _DAT_00af4f8e++                    // global install counter
  Release(this+0x54) if non-null
  this+0x54 = &PTR_PTR_00af4f88      // static singleton mode-1 object
  // (no AddRef on singleton path — pointer install only)

else if (mode == 2):
  // Alloc 0x60-tagged object via global factory DAT_00b05060
  // FUN_0063f400(this) constructs full mode-2 state (vtable PTR_FUN_009e3ec0, floats, …)
  // Swap into this+0x54 with AddRef/Release dance
  // Odd: after assign, immediately Release the new object once more (may leave null if sole ref)

// other mode values: no-op fallthrough
```

Post-create path: `Vehicle_createVehicleAction` ends with `FUN_005d4050(1)` → install **mode-1 singleton** at phys+0x54.

`read_memory` @ `0x00af4f88`: `9c 3c 9e 00 | 00 00 01 00 | 00 00 80 3f | …` → vtable-ish + refcount field + float 1.0 — consistent with static COM/singleton blob.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005d4050` |
| Mode-2 ctor | `batch_decompile` @ `0x0063f400` |
| Singleton blob | `read_memory` `0x00af4f88` |
| Callers | `get_function_callers` |
| Create path | `fn_004fb660_createVehicleAction.md` (`FUN_005d4050(1)`) |
| Teardown pair | `A_aa_004f7d60_*` clears same `+0x54` |

---

## 3. Signature

```c
// ECX = physics object (entity+8 / chassis host)
// mode: 1 = singleton helper; 2 = heap-constructed full helper
void __thiscall VehiclePhys_SetModeHelper(PhysHost *this, int mode);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Field is `this+0x54` COM pointer | **High** |
| Mode id via vtbl+0x1c early-out | **High** |
| Mode 1 → static `PTR_PTR_00af4f88` | **High** |
| Mode 2 → alloc + `FUN_0063f400` | **High** |
| createVehicleAction uses mode 1 | **High** |
| Modes other than 1/2 are no-ops | **High** CF |
| Product English for mode-1 vs mode-2 | **Open** residual |
| Mode-2 double-Release after assign | **High** CF / intent **Open** (may self-destruct if ref hits 0) |

**Verdict:** **accept-with-gaps**
