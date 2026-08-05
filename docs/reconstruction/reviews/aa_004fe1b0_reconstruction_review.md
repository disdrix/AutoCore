# Reconstruction review: `aa_004fe1b0` Vehicle_EquipPowerPlant

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **VA** | `0x004fe1b0` |
| **Canonical name** | `Vehicle_EquipPowerPlant` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_004fe1b0_Vehicle_EquipPowerPlant.md` | Authoritative Ghidra decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_004fe1b0_Vehicle_EquipPowerPlant.annotated.md` | Scaffold annotation |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Vehicle_EquipPowerPlant.cpp` | Clean port surface |
| Function record | `docs/reconstruction/functions/aa_004fe1b0_Vehicle_EquipPowerPlant.md` | Completion / confidence |
| Callers | `Client_RecvInventoryEquip`, `Client_RecvInventoryUnequipNotify`, `Vehicle_EquipFromCreate` | Class-10 hardpoint / clear path |
| Packet / system docs | `Documentation/PACKET STRUCTURES.md`, `systems/inventory-transfer.md` | Equip flow context |

**Primary claims under review (clean must match low-level):**

1. Same non-null plant already at `this+0x268` → log CBID + return
2. `FUN_00512670` always before mutation
3. Optional `*ppOutPrevious = old plant`
4. Previous plant: optional `FUN_004fbb50` unbind unless `bKeepPreviousAttached`; always vfunc `+0x158(0)`
5. Store new pointer at `+0x268`
6. Owner notify: vehicle `+0xb0` → vfunc `+0x1dc` → char vfunc `+0x5c`
7. Non-null new plant: type check clonebase `+0x38 == 10`; TFID copy to `+0x620/+0x624`; bind vfunc `+0x158(vehicle ctx)`; `FUN_004fdcb0`; vfunc `+0x218(vehicle+link+0xa8)`; `Vehicle_CalcHeatMaximum` → `+0x244`
8. Null new plant: TFID sentinels `0xFFFFFFFF` at `+0x620/+0x624` + heat recalc

**Not re-authored:** No edits to raw. Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth for CF, offsets, callees |
| Plate comment | Raw header | Slot `+0x268`, MaxHeat `+0x244`, TFID `+0x620/+0x624` |
| Clean implementation | `Vehicle_EquipPowerPlant.cpp` | Line-by-line map to raw |
| Caller equip path | `Client_RecvInventoryEquip` case 10 | Confirms plant equip + previous-out scratch |

No runtime / CE / differential verification.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Same-plant early out | Yes | Yes | **Yes** |
| `FUN_00512670` | Yes | Yes | **Yes** |
| Optional previous out | Yes | Yes | **Yes** |
| Unbind gate on `bKeepPreviousAttached` | Yes | Yes | **Yes** |
| vfunc+0x158(0) on previous | Yes | Yes | **Yes** |
| Store `+0x268` | Yes | Yes | **Yes** |
| Owner notify chain | Yes | Yes | **Yes** |
| Type==10 check + unhappy log | Yes | Yes | **Yes** |
| TFID copy / bind / post / heat | Yes | Yes | **Yes** |
| Clear path sentinels + heat | Yes | Yes | **Yes** |

### 3.2 Offsets

| Offset | Meaning (from plate + body) | Clean |
|---|---|---|
| `+0x268` | Power plant slot | Preserved |
| `+0x244` | MaxHeat store | Preserved |
| `+0x620/+0x624` | Plant COID lo/hi | Preserved |
| Clonebase `+0x38` | Type id (expect 10) | Preserved |

### 3.3 Type renames only

Clean uses `std::uint32_t` for decompiler `undefined4`; no invented clamps, no reordered calls, no modernized vehicle class.

### 3.4 Function record honesty

Record should remain partial / human-refined with runtime open — appropriate for unresolved `FUN_*` bind helpers.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `FUN_00512670` / `FUN_004fbb50` / `FUN_004fdcb0` identity | Medium (naming) | Still FUN_*; semantics inferred as guard/unbind/post-attach |
| vfunc `+0x158` / `+0x218` names | Doc | Attach vs post-attach labels are interpretive |
| Owner notify side effects | Open | vfunc+0x5c body not in this unit |
| Heat formula | Out of scope | `Vehicle_CalcHeatMaximum` not dual-reviewed here |
| Annotated layer | Meta | Still mostly raw copy; offsets now documented in clean header |

**No revision required** for clean-vs-raw faithfulness of the refined body.

---

## 5. What remains uncertain

1. Exact semantics of `bKeepPreviousAttached` at CreateVehicle vs S2C equip.
2. Whether unhappy-type path still fully attaches (yes in raw — log only, no early return).
3. Identity of vehicle field at link `+0xa8` passed to vfunc+0x218.
4. Runtime round-trip not observed.
5. Live Ghidra re-decompile not performed this session.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean C++ is a faithful refinement of the raw decompile (control flow, offsets, constants, call order) with documentation of hardpoint layout.

**Gaps:** Unresolved bind helpers, no runtime seal, heat formula external. Function record remains partial on bit-exact / runtime.
