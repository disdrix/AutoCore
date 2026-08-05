# Review A (reconstruction fidelity): `aa_005b2800` VehicleNet_AllocHardpointBlobByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2800` |
| **VA** | `0x005b2800` |
| **Canonical name** | `VehicleNet_AllocHardpointBlobByType` (inferred; Ghidra `FUN_005b2800`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2800_VehicleNet_AllocHardpointBlobByType.md` |
| **System** | input-drive-control / GhostVehicle hardpoint delta |
| **Evidence pass** | Live `batch_decompile`; size helper `FUN_005b2490`; sole primary caller `VehicleNet_UnpackGhostVehicle` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate a zeroed-capacity hardpoint / equip net blob** sized from clonebase type:

1. `_Size = FUN_005b2490(param_1)` — type switch on def `+0x38`:
   - cases **8 / 0x32** → `0xE0`
   - case **0xA** → `0x150`
   - case **0xC** → `0x188`
   - cases **0x10 / 0x1C** → `0x158`
   - default → `0xD8`
   - null def → `0`
2. `*param_2 = _Size` (out size always written).
3. If `(int)_Size > 0` → `malloc(_Size)` and return pointer; else return **null**.

Does **not** initialize blob contents (malloc only). Parent unpack fills payload and may call `VehicleNet_PostCorrectionEvent`.

**Caller:** `VehicleNet_UnpackGhostVehicle` `0x005f7720` (delta hardpoint path per parent dual).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b2800_FUN_005b2800.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2800_FUN_005b2800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b2800.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b2800_FUN_005b2800.md` |

**Three-rep:** present.

---

## 3. Signature

```c
void *VehicleNet_AllocHardpointBlobByType(void *typeOrDefHandle, size_t *outSize);
```

| Formal | Source | Conf |
|---|---|---|
| `param_1` | fed to `FUN_005b2490` → `FUN_00404d70` resolve | **High role** |
| `param_2` out size | always stored | **High** |
| return | malloc or null | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| size = helper(param_1) | **Yes** | **High** |
| *out = size | **Yes** | **High** |
| if size>0 malloc else null | **Yes** | **High** |
| No free / no fill | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Size-by-type then malloc | **High** | body |
| Size table via `FUN_005b2490` switch | **High** | live decompile of helper |
| Used on ghost vehicle hardpoint delta | **High** | sole unpack caller |
| English type names for case 8/0xA/… | **Tentative** | open |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Map clonebase type codes (8, 0xA, 0xC, …) to product hardpoint classes.
2. Parent fill path after malloc (payload opcodes) not owned here.

**Verdict:** **accept-with-gaps**
