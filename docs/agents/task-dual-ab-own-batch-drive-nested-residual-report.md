# OWN-ONLY dual A/B batch report — DriveControlTick nested residual

**Date:** 2026-07-29  
**Workspace:** `docs/reconstruction/`  
**Seeds:** `DriveControlTick` `0x009223b0`, `PushDriveAxes` `0x004fbc10`, `setDrivingInputs` `0x00504c70`  
**Rule:** Dual EACH nested residual with **no prior `A_aa_*`** (cap 8). MUST A+B.

| VA | Stable ID | Name | Verdict |
|----|-----------|------|---------|
| `0x004f5110` | `aa_004f5110` | `Vehicle_FireAllSecondaryWeapons_Inferred` | **accept-with-gaps** |
| `0x004f52e0` | `aa_004f52e0` | `Vehicle_CanFireAllSecondaryHeatOK_Inferred` | **accept-with-gaps** |
| `0x004ff350` | `aa_004ff350` | `Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred` | **accept-with-gaps** |
| `0x005063c0` | `aa_005063c0` | `Object_SetRootField60_WalkParentChain_Inferred` | **accept-with-gaps** |
| `0x00516a00` | `aa_00516a00` | `Object_RefreshActiveSkillEffects_Inferred` | **accept-with-gaps** |
| `0x00525cc0` | `aa_00525cc0` | `Vehicle_SetActivePowerSlot_Inferred` | **accept-with-gaps** |
| `0x0056b400` | `aa_0056b400` | `Weapon_SetSuppressFlag_Cb_Inferred` | **accept-with-gaps** |

**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile`, `get_function_callees` / `callers`, `read_memory`. No `disassemble_bytes`. Program: `autoassault.exe`.

---

## Written

### Dual A/B (14 files)

- `docs/reconstruction/reviews/A_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md`
- `docs/reconstruction/reviews/A_aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md`
- `docs/reconstruction/reviews/B_aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md`
- `docs/reconstruction/reviews/A_aa_005063c0_Object_SetRootField60_WalkParentChain_Inferred.md`
- `docs/reconstruction/reviews/B_aa_005063c0_Object_SetRootField60_WalkParentChain_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md`
- `docs/reconstruction/reviews/A_aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md`
- `docs/reconstruction/reviews/B_aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md`
- `docs/reconstruction/reviews/A_aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md`

### Named function records (7)

- `docs/reconstruction/functions/aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md`
- `docs/reconstruction/functions/aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md`
- `docs/reconstruction/functions/aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md`
- `docs/reconstruction/functions/aa_005063c0_Object_SetRootField60_WalkParentChain_Inferred.md`
- `docs/reconstruction/functions/aa_00516a00_Object_RefreshActiveSkillEffects_Inferred.md`
- `docs/reconstruction/functions/aa_00525cc0_Vehicle_SetActivePowerSlot_Inferred.md`
- `docs/reconstruction/functions/aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md`

### Other

- Legacy `functions/aa_*_FUN_*.md` dual pointer stamps
- This report

---

## Skipped

| Item | Reason |
|------|--------|
| Seeds `009223b0` / `004fbc10` / `00504c70` | Already had `A_aa_*` + `B_aa_*` |
| All direct DCT / Push / setDriving callees already dualled | `A_aa_*` present (setters, push math, camera, cast terrain, QB, etc.) |
| Nested that already had `A_aa_*` | e.g. `004c4e20`, `00404a20`, `004e8a40`, `0053eec0`, `00503f30`, … |
| `0076f5f0` / `009729d0` (GfxView tertiary) | Cap 8; 7 higher-value drive/activate residuals taken first; still missing A if later batch wants them |
| Ledgers / WORK_QUEUE / RESUME / CHANGE_LOG | Task: no ledgers |
| Launcher / runtime | Not approved |
| Ghidra rename/plate apply | Docs-only dual |

---

## Sealed one-liners

1. **`004f5110`**: secondary fire-all — hardpoint `+0x260` ×3, vtbl **+0x3C**, OR `FUN_0056d520`.
2. **`004f52e0`**: secondary heat **∀** (first fail→0; empty→1); primary twin is **∃**.
3. **`004ff350`**: equip walk clear-gfx vs cast-skills; status hooks only `+0x26c`/`+0x270`.
4. **`005063c0`**: walk parent `+0xAC` → store root `+0x60`.
5. **`00516a00`**: type-gated skill hash + vfunc array → `FUN_00514e70(id)`.
6. **`00525cc0`**: active slot `+0xD64` ∈ `[-1,2]` + optional skill cast on continent gate.
7. **`0056b400`**: weapon `+0xCB` suppress; set zeros f32 `+0xD8`; clear may TacArc via `+0xC0`.

---

## Nesting provenance

```
DriveControlTick 0x009223b0
  └─ Input_TryFireSecondaryWeapons 0x0091a550
       ├─ FUN_004f52e0  (heat ∀)     ← dualled
       └─ FUN_004f5110  (fire-all)   ← dualled

setDrivingInputs 0x00504c70
  └─ Vehicle_ActivateEnterWorld 0x00503f30
       ├─ FUN_005063c0  ← dualled
       ├─ FUN_0056b400  ← dualled
       ├─ FUN_00516a00  ← dualled
       ├─ FUN_00525cc0  ← dualled
       └─ FUN_004ff350  ← dualled

PushDriveAxes 0x004fbc10
  └─ (nested 004c4e20 / 00404a20 / 004e8a40 already dualled — skip)
```

---

## AutoCore impact

- Secondary fire heat quantifier must stay **∀** (not primary ∃) or overheat UX is wrong.
- Enter-world residual sealed for equip cast/clear, skill refresh, power slot re-apply, weapon suppress clear.
- No server packet ownership in these units beyond existing net mask callers of ActivateEnterWorld.
