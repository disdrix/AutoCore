# OWN-ONLY dual A/B batch report

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Scope:** Dual EACH if no prior `A_aa_*` for seven VAs (wave15 equip residual cluster).

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x004d3310` | `aa_004d3310` | `CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred` | **accept-with-gaps** |
| `0x004d28c0` | `aa_004d28c0` | `CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred` | **accept-with-gaps** |
| `0x004d9b50` | `aa_004d9b50` | `CVOGSectorMap_RemoveCharacter_Inferred` | **accept-with-gaps** |
| `0x004f70f0` | `aa_004f70f0` | `Vehicle_HasEquippedTFID_Inferred` | **accept-with-gaps** |
| `0x00519d20` | `aa_00519d20` | `VehiclePaintColor_LookupById_Inferred` | **accept-with-gaps** |
| `0x0051f4e0` | `aa_0051f4e0` | `Character_SetLocalVehiclePtr_Inferred` | **accept-with-gaps** |
| `0x0051f550` | `aa_0051f550` | `BuildRaceClassSuffix_Inferred` | **accept-with-gaps** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `batch_decompile`, `decompile_function`, `read_memory`, `get_bulk_xrefs`, callers. No `disassemble_bytes`. Program: `autoassault.exe`.

**Parent chain seals:**

- CompletelyDestroyObject `FUN_009440e0`: `004d9b50` remove → optional `004d3310` dec index → `004d28c0` pool fan-out; equip destroy uses `004f70f0`.
- Paint/tint: `00519d20` lookup + `0051f4e0` local-vehicle slot; garage uses `0051f550` race/class suffix.

---

## Written

### Dual A/B (14 files)

- `docs/reconstruction/reviews/A_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0051f550_BuildRaceClassSuffix_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0051f550_BuildRaceClassSuffix_Inferred.md`

### Named function records (7)

- `docs/reconstruction/functions/aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md`
- `docs/reconstruction/functions/aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md`
- `docs/reconstruction/functions/aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md`
- `docs/reconstruction/functions/aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md`
- `docs/reconstruction/functions/aa_00519d20_VehiclePaintColor_LookupById_Inferred.md`
- `docs/reconstruction/functions/aa_0051f4e0_Character_SetLocalVehiclePtr_Inferred.md`
- `docs/reconstruction/functions/aa_0051f550_BuildRaceClassSuffix_Inferred.md`

### Other

- Legacy scaffold `functions/aa_*_FUN_*.md` left in place (pointer peers)
- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Prior `A_aa_*` for any of 7 VAs | **None existed** — all dualled |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Dual of sibling `FUN_004d32c0` (enter/+1) | Out of VA list (referenced only) |
| Dual of lazy loader `FUN_00519a30` | Out of VA list |
| Full bit-exact clean / Ghidra rename apply | Docs-only dual |
| `disassemble_bytes` | Project rule: prefer decompile/read_memory |

---

## Sealed one-liners

1. **`004d3310`**: SectorMap leave — `+0xe818--`, optional `004d28c0`, raceHist[`def+0x532`]--.
2. **`004d28c0`**: Level-index transition → clamp ≤0xF → rescale combat pools on `+0xe4e8` vector via `004cf3b0`.
3. **`004d9b50`**: Erase character* from `+0xe75c` vector; optional `+0xf6` set rebuild / sole-remaining.
4. **`004f70f0`**: Bool — TFID in weapon mounts (`004f5680`) or equip slots `+0x270..+0x254`.
5. **`00519d20`**: Paint color hash lookup (`b042b4/b8/bc`); lazy `00519a30`; return `*payload` or 0.
6. **`0051f4e0`**: `char+0xcd0 = veh`; non-null → `vtbl+0x158()`.
7. **`0051f550`**: Static `DAT_00b04600` ← `_h|_m|_b` + `_c|_e|_o|_r` from `0x009ceee0`.

---

## AutoCore impact

- Closes dual gap on **CompletelyDestroyObject equip/sector residual** chain and **paint/garage** helpers.
- Pairs with existing: `CVOGSectorMap_AddCharacter`, `Object_ScaleCombatPoolsByLevelTable_Inferred`, `Client_RecvInventoryUsePaint`, inventory cursor duals.
- No server packet ownership in these units (client sector map, equip predicate, paint table, UI suffix).
