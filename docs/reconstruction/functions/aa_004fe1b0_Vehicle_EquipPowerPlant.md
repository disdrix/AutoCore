# Function record: Vehicle_EquipPowerPlant

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **Canonical name** | `Vehicle_EquipPowerPlant` |
| **Address** | `0x004fe1b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean + dual review (accept-with-gaps / needs-more-evidence)** — runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Swap vehicle PowerPlant hardpoint at `+0x268`. Optional previous-out, unbind old plant, attach new, copy plant TFID to `+0x620/+0x624`, recalculate MaxHeat into `+0x244`.

## Signature (decompiler-derived)

```c
void __thiscall Vehicle_EquipPowerPlant(
    void* thisVehicle,
    void* pNewPowerPlant,
    void** ppOutPrevious,
    bool bKeepPreviousAttached);
```

## Behavioral summary

1. Same non-null plant → log CBID, return  
2. `FUN_00512670`; optional previous out; unbind previous (`FUN_004fbb50` unless keep; always vfunc+0x158(0))  
3. Store new at `+0x268`; owner notify via `+0xb0`  
4. Non-null: type check `==10` (log only if unhappy); TFID copy; bind; post; `Vehicle_CalcHeatMaximum` → `+0x244`  
5. Null: TFID sentinels `0xFFFFFFFF`; heat recalc  

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `Client_RecvInventoryEquip` | Class 10 path |
| Caller | `Client_RecvInventoryUnequipNotify` | Clear with null plant |
| Caller | `Vehicle_EquipFromCreate` | Create nest |
| Callee | `Vehicle_CalcHeatMaximum` | MaxHeat |
| Callee | `FUN_00512670`, `FUN_004fbb50`, `FUN_004fdcb0` | Guard / unbind / post |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Slot `+0x268` / heat `+0x244` / TFID `+0x620/624` | High |
| Type 10 = power plant | High (plate + callers) |
| `bKeepPreviousAttached` full semantics | Probable (gates only FUN_004fbb50) |
| Bind helper names | Tentative |
| Overall | Probable — refined; runtime open |

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| Reconstruction | `reviews/aa_004fe1b0_reconstruction_review.md` | accept-with-gaps |
| Skeptical | `reviews/aa_004fe1b0_skeptical_review.md` | needs-more-evidence |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004fe1b0_Vehicle_EquipPowerPlant.md`
- Annotated: `docs/reconstruction/raw/aa_004fe1b0_Vehicle_EquipPowerPlant.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Vehicle_EquipPowerPlant.cpp`
