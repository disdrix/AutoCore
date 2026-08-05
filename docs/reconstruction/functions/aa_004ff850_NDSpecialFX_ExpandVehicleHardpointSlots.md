# Function record: NDSpecialFX_ExpandVehicleHardpointSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff850` |
| **Canonical name** | `NDSpecialFX_ExpandVehicleHardpointSlots` |
| **Ghidra name** | `FUN_004ff850` |
| **Address** | `0x004ff850` |
| **Body range** | `0x004ff850`–`0x004ffe2e` (1502 B / `0x5DE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / vehicle create-from-packet |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Dual A/B** | `reviews/A_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md`, `reviews/B_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` |
| **Last reviewed** | `2026-07-29` (W23-Q) |

## Naming evidence

| Source | Value |
|---|---|
| Strings | `"%s_WHEELSET_%d"`, `"%s_VEHICLE_EXHAUST_%d"`, `"%s_VEHICLE_BRAKES_%d"`, `"%s_VEHICLE_LIGHTS_%d"`, `"%s_VEHICLE_MELEE_%d"` |
| Callee dual | `NDSpecialFX_InstantiateFromTemplate` @ `0x004a0b90` |
| Name field | `template+0xD5` (matches NDSpecialFX ctor dual) |
| Caller | `CVOG_CreateFromPacketDispatch` |
| Prior auto | `Drive_s_VEHICLE_EXHAUST_d` — **superseded** (single-string bias) |

**Decision:** promote structural `NDSpecialFX_ExpandVehicleHardpointSlots` (not `_Inferred` for family; product/PDB still open).

## Purpose / signature / artifacts

See twin record `aa_004ff850_FUN_004ff850.md` for full tables.
