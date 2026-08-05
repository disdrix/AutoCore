# Function record: CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521310` |
| **Canonical name** | `CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred` |
| **Ghidra name** | `FUN_00521310` |
| **Address** | `0x00521310` |
| **Body range** | `0x00521310`–`0x00521430` (288 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | character create / vehicle attach / sector map |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF sealed; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md`, `reviews/B_aa_00521310_CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.md` (2026-07-29 W18-R) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00521310`
- ~~`Named_CalleeOf_CVOGSectorMap_AddCharacter_00521310`~~ (**wrong direction** — this **calls** AddCharacter)

## Purpose

Character create-apply finish: CurrentVehicleCoid → SetVehicle → AddCharacter (+ optional LOD / equip-gfx cleanup).

## Signature

```c
void __thiscall CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred(
    CharSub *this_adj, int *pkt_or_ctx,
    uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, uint32_t flag);  // ret 0x18
```

## Algorithm

1. Optional pre (`FUN_005c93f0`) when flag.
2. Resolve vehicle from character CurrentVehicleCoid.
3. `Creature::SetVehicle`; optional vehicle+0x101.
4. `CVOGSectorMap_AddCharacter(this_adj - 0xda0)`.
5. If packet type 0x2016 + AutoAssault LOD handler → `FUN_00760fe0(0, 999.f)`.
6. Optional `FUN_004962b0` equip-gfx clear.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00521310_FUN_00521310.md`
- Annotated: `docs/reconstruction/raw/aa_00521310_FUN_00521310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCharacter_CreateApply_AttachVehicleAddToMap_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00521310.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00725a70-00521310-w18r-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005c93f0`, `FUN_004bafe0`, `FUN_004c49d0` (SetVehicle), `FUN_0053d970`, `CVOGSectorMap_AddCharacter`, `__RTDynamicCast`, `FUN_00760fe0`, `FUN_004962b0` |
| **Callers** | `CVOGCharacter_CreateFromPacket` @ `0x005238c7`; xref `0x0053bed3` (undefined fn) |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **High** |
| SetVehicle + AddCharacter role | **High** |
| Packet 0x2016 + 999.f | **High** |
| Product English name | **Inferred** |
| Runtime / bit-exact | Open |

## Related

- `aa_004bafe0` Object_ResolveTarget_VCall1d4
- `aa_004c49d0` / Creature::SetVehicle
- `aa_004d35c0` CVOGSectorMap_AddCharacter
- `aa_004962b0` EquipGfxHost_ClearListIfFlag_Inferred
- `CVOGCharacter_CreateFromPacket`
