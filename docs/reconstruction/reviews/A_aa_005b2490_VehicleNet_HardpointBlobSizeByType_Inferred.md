# Review A (reconstruction fidelity): `aa_005b2490` VehicleNet_HardpointBlobSizeByType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2490` |
| **VA** | `0x005b2490` |
| **Canonical name** | `VehicleNet_HardpointBlobSizeByType_Inferred` (was `FUN_005b2490`) |
| **Ghidra symbol** | `FUN_005b2490` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of UnpackGhost) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2490_VehicleNet_HardpointBlobSizeByType_Inferred.md` |
| **System** | input-drive-control / GhostVehicle hardpoint delta |
| **Parent** | `VehicleNet_AllocHardpointBlobByType` `0x005b2800` ← `VehicleNet_UnpackGhostVehicle` `0x005f7720` |
| **Dual status** | **Present** |
| **Verdict** | **accept** (table sealed; type English residual only) |

---

## 1. Purpose

**Map clonebase / equip type → hardpoint net blob byte size** for malloc in AllocHardpointBlobByType.

```
def = FUN_00404d70(handle)
if def == 0: return 0
switch (def+0x38):
  case 8, 0x32:  return 0xE0
  case 0x0A:     return 0x150
  case 0x0C:     return 0x188
  case 0x10, 0x1C: return 0x158
  default:       return 0xD8
```

No allocation, no wire IO. Parent always stores returned size to out-param then malloc if >0.

**Caller:** only `FUN_005b2800`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b2490` |
| Callers | `get_function_callers` → `FUN_005b2800` |
| Parent dual | `A_aa_005b2800_VehicleNet_AllocHardpointBlobByType.md` (already listed this table) |
| Raw / clean | `raw/aa_005b2490_*`, `FUN_005b2490.cpp` |

---

## 3. Signature

```c
size_t HardpointBlobSizeByType(void *typeOrDefHandle);
// resolve via FUN_00404d70; switch *(def+0x38)
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Size table exact | **High** |
| Null def → 0 | **High** |
| Type field at def `+0x38` | **High CF** |
| Product English for cases 8/0xA/0xC/… | **Low** residual |
| Resolve helper `0x00404d70` body | **Open** (out of unit; still missing dual) |

**Verdict:** **accept**
