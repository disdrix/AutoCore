# System map: Inventory transfer (client)

| Field | Value |
|---|---|
| System | Grid inventory grab/drop/equip/add + cargo grid placement |
| Priority | **High** (#4 inventory) |
| Program | `autoassault.exe` |
| Status | Map from Ghidra + `docs/inventory-cargo-wire-re.md` |
| Bit-for-bit | Deferred |

## Scope

C2S grab/drop, S2C responses, multi-cell footprint place/find, locker vs cargo types, equip/unequip notifies. CargoSendAll (`0x2040`) is no-op in packet dispatch on this build.

## Known entry points

| Address | Symbol | Role |
|--------:|--------|------|
| `0x00860e20` | `Client_SendInventoryGrab_FromGrid` | C2S `0x2034` size `0x20` (dual residual pack/split 2026-07-29: written fields + caller ABI sealed) |
| `0x00860a50` | `Client_UI_InventoryDropToGrid` | C2S `0x2036` size `0x20` |
| `0x00813730` | `Client_RecvInventoryDropResponse` | S2C `0x2037` place into cargo/locker/trade (dual residual 2026-07-29: dispatch + EAX/EBX ABI Confirmed) |
| `0x00811be0` | `Client_RecvInventoryGrabResponse` | S2C grab / stack split (dual residual 2026-07-29: dispatch/ABI/fields sealed) |
| `0x008151a0` | `Client_RecvInventoryAddItem` | S2C add |
| `0x00813f40` | `Client_RecvInventoryEquip` | S2C `0x203C` equip (dual residual 2026-07-29: class map + wheelset sealed) |
| `0x00813bf0` | `Client_RecvInventoryUnequipNotify` | S2C unequip (dual residual sealed 2026-07-29: demux + class map) |
| `0x004fe1b0` | `Vehicle_EquipPowerPlant` | Hardpoint `+0x268` (dual review) |
| `0x00502090` | `Vehicle_SetEquippedArmor` | Hardpoint `+0x254` type `0x1c` |
| `0x00502460` | `Vehicle_SetEquippedRaceItem` | Hardpoint `+0x270` type 6/subtype `0xb` |
| `0x004fadb0` | `Inventory_SerializeAddItemPacket` | Fill `0x2047` fields (dual review) |
| `0x00530df0` | `Client_SendInventoryAddItem` | C2S/build `0x2047` AddItem |
| `0x005721c0` | `CVOGReaction_RemoveInventoryItem` | Remove by CBID + qty |
| `0x00571620` | `InventoryGrid_PlaceItemFootprint` | Stamp COID into every footprint cell |
| `0x00571830` | `InventoryGrid_MergeStackQty` | Add qty delta onto existing stack by COID (dual 2026-07-29) |
| `0x005713a0` | `InventoryGrid_FindFreeSlot` | First-fit free rect |
| `0x005714e0` | `InventoryGrid_FindFreeForItem` | Item space probe; type-4 / stack / tail FindFreeSlot |
| `0x00570720` | `InventoryGrid_AllocateCellArray_Inferred` | width×height cells ×8 empty=`-1` |
| `0x004f3a30` | `Vehicle_CreateCargoInventoryFromPageCount` | Empty 6×pages×13 grid |

## Behavioral flow

```
UI Grab → SendInventoryGrab (0x2034) → GrabResponse → cursor/stack
UI Drop → DropToGrid (0x2036) → DropResponse → PlaceItemFootprint on target type
  type 1 cargo, 3 locker, 5 trade, 6 other
```

## Call / data flow

- Grab packet: opcode `0x2034` size `0x20`; item TFID from object `+0x160/+0x164/+0x168`; `ucTypeFrom` from window `+0x56c+4`; `lQuantity@+0x1c` = whole or partial-split request (peel is GrabResponse, not FromGrid).
- DropResponse switch on inventoryType `@+0x1a`; place via `FUN_00571620` with X/Y `@+0x18/+0x19`.
- Footprint sizes from clonebase `+0x406/+0x407` (InvSizeX/Y).

## Raw-only offset inventory (2026-07-28)

Evidence limited to raw decompiles of place / find / can-place / allocate / DropResponse. No invented field names beyond raw uses.

### DropResponse packet (`aa_00813730`) — `inventoryType` + place args

| Offset | Raw use |
|-------:|---------|
| `*pkt` | Opcode; early-out when `0x203b` |
| `+0x18` | Origin X into `FUN_00571620` |
| `+0x19` | Origin Y into `FUN_00571620` |
| **`+0x1a`** | **`inventoryType`** `switch`: cases **1 / 3 / 5 / 6**; default invalid |
| `+0x1c` | Qty dword (concat path) |
| `+0x22` | Success flag |
| `+0x23` | Swap-path flag |
| `+0x28/+0x2c` | Swap counterpart ids |
| `+0x38` | Concat/split branch |

`PlaceItemFootprint` (`aa_00571620`) itself **does not** read `inventoryType`; the switch resolves a grid, then places.

| Type `@+0x1a` | Grid expression (raw) |
|-------------:|------------------------|
| 1 | `*(*(client+0xe98)+0x250)+0x2b0` |
| 3 | `*(client+0xe98)+0xcbc` |
| 5 | `*(client+0xe98)+0xce0` |
| 6 | TFID lookup → `obj+0xce0` |

### InventoryGrid layout (place/find/can/alloc raws)

| Offset | Raw use | Units |
|-------:|---------|-------|
| `+0x04` | Compared to **4** → min 2×2 footprint when size zero | place |
| `+0x08` | Width; `nTotal = w*h`; X bounds | alloc / find / can |
| `+0x0c` | Height + **cell index multiplier** `idx = h*a + b` | all four |
| `+0x10` | Total cell count (alloc write) | alloc |
| `+0x14` | Page-dim derive | alloc |
| `+0x18` | `nTotal / h` (alloc write) | alloc |
| `+0x1c` | Page dim; FindFree page window; CanPlace page check | alloc / find / can |
| `+0x24` | Type-4 attach arg / saved register in place | place |
| `+0x28` | Cell array ptr; cells **8 B**; empty `0xFFFFFFFF` halves; empty test `(lo&hi)==-1` | all four |

### Clonebase / item (place raw)

| Location | Raw use |
|----------|---------|
| `item[0x2a]+0x38` | Object type; reject `0x12/14/16/36/38/3a`; type 4 early |
| `item[0x2a]+0x3c` | Blob ptr |
| `blob+0x406` / `+0x407` | Footprint X (`char`) / Y (`byte`) |
| `item[0x58]/[0x59]` | Cell stamp lo/hi |
| `item[0x5f]` | Flags; success `\|0x10` |

Stamp loop index **sealed** 2026-07-29 (asm dual residual `a_00571620`): `idx = height*(originX+dx)+(originY+dy)` for `dx∈[0,sizeX)`, `dy∈[0,sizeY)`; same family as FindFree/CanPlace. Decompiler `unaff_*` body is non-authoritative.

## State owners

| Owner | Notes |
|-------|-------|
| Inventory grid cells `@+0x28` | 8-byte COID pairs; empty halves `0xFFFFFFFF` |
| Client inventory type windows | cargo/locker/trade pointers |

## State transitions

| Event | Effect |
|-------|--------|
| Successful drop | Multi-cell stamp of item COID |
| Failed drop | UI error string; no place |
| Grab split | New stack object + residual qty |

## Mission collect progress (cross-system, 2026-07-29)

Collect objectives (**RequirementType = 2**, class `CVOGObjectiveRequirement_Collect`) **re-count cargo inventory** for eval fraction and journal text. They do **not** use the UseItem-style 0x2071 slot-float threshold for those two methods.

### Bridge units

| Piece | Address | Role |
|-------|---------|------|
| `InventoryGrid_CountItemsByCbid` | `0x005711c0` | Sum stack qty by CBID (`clonebase+0x34`); exclude **Broken** bit19 (`item+0x17c`) unless `includeBroken` |
| `CVOGObjectiveRequirement_Collect_Eval` | `0x00611940` | `min(1, count/NumToCollect)` on cargo |
| `CVOGObjectiveRequirement_Collect_SlotAction` | `0x006124b0` | UI `"name: have / need"` from **same** live count |
| Collect XML deserialize | `0x00611a00` | CBID `+0x10`, NumToCollect `+0x14`, drop %, targets, … |
| Collect ctor | `0x00611690` | type code **2**, vtable `PTR_FUN_009e12c4` |

### Data path

```
Grab/Drop/Add place into cargo (type 1)
  → cells at InventoryGrid (+0x28 COID pairs)
  → later Collect_Eval / Collect_SlotAction:
       cargo = *( *(character+0x250) + 0x2b0 )   // same as DropResponse case 1
       count = CountItemsByCbid(cargo, req.CBID, 0)
       fraction / UI from count vs req.NumToCollect
```

Same cargo grid pointer as DropResponse **type 1** (`inventory-transfer` raw table `+0x1a == 1`).

### Dual reviews

| Unit | Reviews |
|------|---------|
| `InventoryGrid_CountItemsByCbid` | A/B `aa_005711c0` |
| `CVOGObjectiveRequirement_Collect_Eval` | A/B `aa_00611940` |
| `CVOGObjectiveRequirement_Collect_SlotAction` | A/B `aa_006124b0` |

Chain: `docs/reconstruction/reviews/CHAIN_2026-07-29_inventory_collect.md`.  
Missions map: `systems/missions-progression.md` § Inventory collect dependency.

### Related (Deliver, not Collect)

Deliver (type **3**, ctor `0x00610bc0`) also calls `CountItemsByCbid` for turn-in readiness (`0x00611290` / `0x00610f20`). Do not conflate with Collect.

## External effects

Network send via sector connection vtable `+0x18`; UI toasts; mission UI refresh hooks.

## Dependencies

- **Mission collect** recounts **this** cargo grid via `InventoryGrid_CountItemsByCbid` (sealed static chain 2026-07-29)
- Equip path intersects vehicle hardpoints (see owner-wheel RE)

## Important functions

See entry table; unit records under `functions/aa_*`.

## Evidence

Ghidra batch decompiles; `docs/inventory-cargo-wire-re.md`; `docs/inventory-grid-footprint.md`.

## Confidence

| Area | Level |
|------|-------|
| Opcodes/sizes | High |
| Multi-cell place | High |
| DropResponse type map | High |
| Full trade path | Probable |

## Equip chain (2026-07-23; residual 2026-07-29)

```
Drop HARDPOINT=2 (C2S 0x2036)
  → server TryEquip
  → S2C InventoryEquip 0x203C (Client_RecvInventoryEquip)
       local: putInHand / cargo pull → FUN_00502e90 vehicle equip + UI
       non-local: class switch → ornament/plant/weapon/wheelset/armor helpers
Unequip grab:
  → S2C 0x203E (Client_RecvInventoryUnequipNotify) then GrabResponse
Add cargo:
  → Client_SendInventoryAddItem → Inventory_SerializeAddItemPacket (0x2047 fields)
```

Hardpoint slots (equip helpers sealed 2026-07-29): armor `+0x254`, **wheelset `+0x258`**, weapon array `+0x260`, melee `+0x264`, power plant `+0x268`, ornament `+0x26c`, race item `+0x270`.

### RecvInventoryEquip class map (static seal 2026-07-29)

| Class | Path | Slot / named |
|---:|---|---|
| 6 / subtype 10 | `FUN_004fe620` | ornament `+0x26c` |
| 10 | `Vehicle_EquipPowerPlant` | plant |
| 0xc / subtype 9 | `FUN_004fe800` | melee `+0x264` |
| 0xc else | `FUN_004fe110` → `Vehicle_AttachWeapon` | `+0x260` |
| **0x10** | **`FUN_004ff510` → `Vehicle_SetWheelset`** | **`+0x258`** |
| 0x1c | `FUN_00502180` → `Vehicle_SetEquippedArmor` | `+0x254` |

Unequip non-local clear map (Recv `0x203E`, residual `reviews/a_00813bf0.md`): class 6/sub10 ornament; 10 PP; 0xc melee-or-weapon; 0x10 wheelset; 0x1c armor. RaceItem not in that switch.

## Open questions

- ~~Complete equip chain to **wheelset**~~ **Sealed in RecvInventoryEquip case 0x10** (static 2026-07-29)
- Whether any client rebuilds from CargoSendAll on other paths
- Local path equips via `FUN_00502e90` (includes plant/wheelset/armor); prior “local never EquipPowerPlant” only true of *direct* callees of `0x00813f40`
- Optional product renames for equip FUN_* helpers
- Runtime equip putInHand true/false capture

## Verification gaps

Runtime grab/drop/equip round-trip; dual reviews still open for some grab/drop units.

## Human-readability (2026-07-23)

Plates + CF summaries upgraded on Client_Recv/Send/UI inventory clean units; dual-review links on Grab/Drop/DropResponse/DropToGrid/Equip. Hardpoint send/click still scaffold bodies with refined plates.

## Next recommended work

1. Full body refine for Grab_Hardpoint / Drop_Hardpoint / Unequip send / ItemClickDispatch (plates done)
2. ~~Dual-review PlaceFootprint~~ — A/B present (`accept-with-gaps`); seal stamp index via asm/CE
3. Runtime grab/drop/equip round-trip
4. Optional product renames for sealed equip helpers (`FUN_004fe620`/`004fe800`/`004ff510`/`00502180`/`00502e90`)
5. ~~Wheelset equip path~~ **Done 2026-07-29 (static)** — case 0x10 → `Vehicle_SetWheelset`
6. ~~Mission collect inventory sync~~ **Done 2026-07-29 (static)** — see Mission collect progress section + chain note
7. Runtime: Grab/Add → journal Collect string refresh timing (Launcher approval); equip putInHand capture

