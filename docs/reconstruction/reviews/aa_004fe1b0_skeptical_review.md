# Skeptical / adversarial review: `Vehicle_EquipPowerPlant` @ `0x004fe1b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Power-plant hardpoint swap unit and package claims |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack.

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_004fe1b0_Vehicle_EquipPowerPlant.md` | Immutable decompile |
| `raw/aa_004fe1b0_*.annotated.md` | Scaffold notes |
| `reconstructed-exact/Vehicle_EquipPowerPlant.cpp` | Clean surface |
| `functions/aa_004fe1b0_*.md` | Record status |
| Sibling equip units Armor / RaceItem | Compare hardpoint pattern |
| `Client_RecvInventoryEquip` case 10 | Caller contract |
| `Documentation/PACKET STRUCTURES.md` | Equip flow narrative |

**Not performed:** fresh Ghidra re-decompile, disassembly, CE/runtime, full vfunc body recovery.

---

## 2. Evidence used (authoritative body)

Mechanical facts from raw alone:

1. Compares `pNewPowerPlant` to `*(this+0x268)`; if equal and non-null, logs and returns.
2. Always calls `FUN_00512670` before writes.
3. Optionally writes previous pointer to `*ppOutPrevious`.
4. On previous non-null: conditional `FUN_004fbb50`, then vcall slot `+0x158` with arg `0`.
5. Stores new pointer at `+0x268`.
6. Optional owner chain at entity-relative `+0xb0`.
7. Non-null path copies two dwords from plant object into `this+0x620/+0x624`, binds, posts, writes heat to `+0x244`.
8. Null path writes `0xFFFFFFFF` to both TFID slots and still recalculates heat.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — `+0x268` is the PowerPlant hardpoint

| Sub-claim | Attack result |
|-----------|----------------|
| Slot written/read at `+0x268` | **Not broken.** Explicit. |
| Semantic name “PowerPlant” | **Working name.** Supported by plate string “powerplant”, type check `== 10`, caller case 10. Not a string table proof of enum name. |

### Claim 2 — Type id 10 means power plant

| Sub-claim | Attack result |
|-----------|----------------|
| Body compares clonebase `+0x38` to `10` | **Not broken.** |
| “Unhappy type” only logs | **Holds** — no early return after log; attach still proceeds. Port that aborts on type mismatch is **wrong**. |
| Cross-system type table maps 10→PowerPlant | **Probable** via RecvInventoryEquip switch + plate; not sealed inside this function alone. |

### Claim 3 — `+0x620/+0x624` are plant TFID halves

| Sub-claim | Attack result |
|-----------|----------------|
| Two dwords copied from plant link `+0x164/+0x168` | **Not broken.** |
| These are COID lo/hi of TFID | **Probable** — matches TFID_16 layout used elsewhere; not proven by type recovery in this unit. |
| Clear path uses `-1,-1` invalid sentinel | **Holds** as bit pattern `0xFFFFFFFF` each dword. |

### Claim 4 — `Vehicle_CalcHeatMaximum` is the only pool update

| Sub-claim | Attack result |
|-----------|----------------|
| Heat written to `+0x244` | **Not broken.** |
| Armor/race use `Vehicle_RecalcCombatPools` instead | **Contrast holds** — this unit does **not** call RecalcCombatPools; heat-only. |
| Heat formula correctness | **Out of scope** — callee not reviewed. |

### Claim 5 — `bKeepPreviousAttached` means “leave old object bound”

| Sub-claim | Attack result |
|-----------|----------------|
| Gates only `FUN_004fbb50` | **Not broken.** |
| Still runs vfunc+0x158(0) on previous | **Holds** — keep flag does **not** skip the zero-bind vcall. Name “KeepPreviousAttached” can mislead: parent bind is still cleared via vfunc. |
| CreateVehicle passes true to preserve something else | **Unproven here** — caller `Vehicle_EquipFromCreate` must be checked separately. |

### Claim 6 — Clean ≡ retail exact behavior

| Sub-claim | Attack result |
|-----------|----------------|
| Clean mirrors decompiler CF | **Yes.** |
| Decompiler ≡ retail | **Not sealed.** Multi-level pointer chains for vfuncs are Ghidra reconstructions. |
| `__thiscall` signature complete | **Probable.** No `unaff_*` residues in this body (stronger than many inventory units). |

### Claim 7 — Overconfident naming

| Name | Warranted? | Attack |
|------|------------|--------|
| `Vehicle_EquipPowerPlant` | Working | Plate + strings |
| `bKeepPreviousAttached` | Tentative | Only gates `FUN_004fbb50` |
| `MaxHeat` at `+0x244` | Probable | Plate; formula external |
| Partial / runtime open | Correct | Do not elevate |

---

## 4. Alternate interpretations

### Minimal hard reading

```
guard();
if (out) *out = slot;
if (slot) { if (!keep) unbind(slot); clear_parent(slot); }
slot = neu;
notify_owner_if_any();
if (neu) {
  warn_if_type!=10;
  copy_tfid(neu → veh+0x620/624);
  attach(neu, veh); post(neu, veh.field_a8);
  veh.maxHeat = CalcHeatMaximum(veh);
} else {
  veh.tfid = {-1,-1};
  veh.maxHeat = CalcHeatMaximum(veh);
}
```

### Risky over-read

- Claiming this is the only plant equip path (false — CreateVehicle nests too).
- Claiming type mismatch aborts equip (false — log only).
- Claiming `bKeepPreviousAttached` skips all detach (false — vfunc+0x158(0) still runs).

---

## 5. What would seal or kill claims

| Evidence | Effect |
|----------|--------|
| Live re-decompile of `0x004fe1b0` | Seal or fix CF |
| Bodies of `FUN_004fbb50` / `FUN_004fdcb0` / vfunc+0x158 | Name attach/unbind |
| Runtime equip/unequip capture of `+0x268/+0x620/+0x244` | Seal offsets |
| Type-10 unhappy log with still-attached plant | Confirm log-only policy |

---

## 6. Verdict

### **needs-more-evidence**

Reconstruction faithfulness is good enough for **accept-with-gaps** on the dual (companion reconstruction review). Skeptical bar for **verified complete** is not met: bind helpers unresolved, no runtime, heat callee open, keep-flag naming slightly misleading.

**Do not** mark bit-exact or runtime complete.
