# Object Layouts

Unresolved padding and overlapping hypotheses are listed explicitly.

## VehicleEntity — drive input region (partial)

Module: `autoassault.exe`. Base: entity `this` as used by `VehicleEntity_Set*Input`.

| Offset | Size | Proposed field | Evidence | Confidence | Conflicts |
|--------|------|----------------|----------|------------|-----------|
| +0x101 | 1 | `suppressDriveAxisApply` (char) | DriveControlTick skips SetSteer/Longitudinal/Handbrake apply when non-zero | Probable | Full flag set unknown |
| +0x109 | 1 | related mode flag | cleared via `VehicleEntity_SetFlag_109(0)` near axis clears | Tentative | Meaning unresolved |
| +0x614 | 4 | `longitudinalInput` f32 | SetLongitudinalInput store | High | Sign convention: accel→-1, reverse→+1 (from DriveControlTick) |
| +0x618 | 4 | `steerInput` f32 | SetSteerInput store | High | left→+1, right→-1 |
| +0x61c | 1 | `handbrakeFlag` u8 | SetHandbrake store | High | — |

## Drive-axis gate object (unresolved type)

Resolved pointer (final `wobj` only — intermediate `*(this+4)` / next load are **unchecked** and fault if null):

```text
wobj = *( *( *(entity + 4) + 4 ) + entity + 0xB0 )
```

| Offset | Size | Proposed field | Evidence | Confidence | Conflicts |
|--------|------|----------------|----------|------------|-----------|
| +0x00 | ? | object header unknown | — | Unknown | — |
| +0xB4 | 1 | `driveAxisSuppressFlags` | `& 0xC7` gate in both axis setters | Probable as suppress bits | "Lock" unproven; bit meanings unknown |

### Gate semantics

| Condition | Effect |
|-----------|--------|
| `wobj == null` | Write **allowed** (designed "unlocked" state unproven) |
| `(flags & 0xC7) == 0` | Write **allowed** |
| `(flags & 0xC7) != 0` | Write **suppressed** (prior value retained) |

Mask `0xC7` = bits `0x01 | 0x02 | 0x04 | 0x40 | 0x80`.


## InventoryGrid (partial — place/find/can/alloc raws)

Module: `autoassault.exe`. `this` as used by `InventoryGrid_PlaceItemFootprint` (`0x00571620`), `FindFreeSlot` (`0x005713a0`), `CanPlace` (`0x00570840`), `AllocateCellArray` (`0x00570720`).

| Offset | Size | Proposed field | Evidence | Confidence | Conflicts |
|--------|------|----------------|----------|------------|-----------|
| +0x04 | 4 | grid kind (`i32`); **4** forces min 2×2 when footprint zero | place compares `*(this+4)==4` | High as gate | Full enum unknown |
| +0x08 | 4 | width (X extent) | alloc `nTotal=w*h`; find/can X bounds | High | — |
| +0x0c | 4 | height + cell-index stride | `idx = *(+0xc)*a + b` in place/find/can | High | Width/height labels vs page axes still dual-read risk |
| +0x10 | 4 | total cells | alloc stores `nTotal` | High | — |
| +0x14 | 4 | page factor | alloc page-dim derive | Probable | Exact meaning open |
| +0x18 | 4 | derived dim (`nTotal/h`) | alloc write | Probable | — |
| +0x1c | 4 | page height / window | find page window; CanPlace `(y%pageH)+sizeY<=pageH` (aa_00570840 sealed 2026-07-29); alloc derive | High | — |
| +0x21 | 1 | dirty / needs-refresh flag | MergeStackQty (`0x00571830`) stores **1** on success | High (write) | Product English name open |
| +0x24 | 4 | owner object `*` | MergeStackQty dirties via `FUN_00512670` if non-null; CreateCargo vfunc `+0x18` stores; type-4 place passes to item vfunc | High (pointer use) | Name Probable |
| +0x28 | 4 | cell array `*` | stamp/read target; cells **8 B**; empty both dwords `0xFFFFFFFF` | High | Index `height*x+y` sealed (place residual 2026-07-29) |

## InventoryDropResponse packet fields (partial — raw `aa_00813730`)

Packet base = DropResponse buffer (`unaff_EBX` in decompile).

| Offset | Size | Proposed field | Evidence | Confidence | Conflicts |
|--------|------|----------------|----------|------------|-----------|
| +0x00 | 4 | opcode | early-out if `0x203b` (**Confirmed** bytes); dispatch **`0x2037`** Confirmed | High / opcode Confirmed | body never +compares 0x2037; ABI EAX=client EBX=packet Confirmed |
| +0x18 | 1 | place origin X | arg to `FUN_00571620` | High | — |
| +0x19 | 1 | place origin Y | arg to `FUN_00571620` | High | — |
| **+0x1a** | 1 | **inventoryType** | `switch` cases 1/3/5/6 | High | cargo/locker labels High; trade/other Probable |
| +0x1c | 4 | quantity (concat path) | dword use | Probable | AutoCore base Write omits |
| +0x22 | 1 | success | fail → toast (**Confirmed** `CMP BYTE [EBX+0x22],0`) | High | — |
| +0x23 | 1 | swap flag | non-zero → swap/concat | High | — |
| +0x28/+0x2c | 4+4 | swap counterpart ids | `FUN_00571010` args | Probable | AutoCore Write omits |
| +0x38 | 1 | concat/split flag | branch at `unaff_EBX[0xe]` | Probable | docs sub-mode 1=merge; AutoCore Write omits |

`inventoryType` → grid (raw expressions only): type **1** `*(*(client+0xe98)+0x250)+0x2b0`; **3** `*(client+0xe98)+0xcbc`; **5** `*(client+0xe98)+0xce0`; **6** TFID lookup then `+0xce0`.

## Client object — skill target-select region (partial)

Module: `autoassault.exe`. Base: client `this` / global singleton `&DAT_00d1a840` as used by `Client_PromptSkillTargetSelect` (`0x0093bac0`).

| Offset | Size | Proposed field | Evidence | Confidence | Conflicts |
|--------|------|----------------|----------|------------|-----------|
| **+0x30c0** | 4 | **`pendingSkillOrMode`** — skill path: **pending skill id** while target-select active; also small UI modes `{0,2,3,4,5}` and **-1** clear | Store from EAX every entry of PromptSkillTargetSelect; skill enter `CastSkillFromQuickBarSlot` `MOV EAX,skillId`; complete `FUN_00941ac0` reads as skill arg to RequestCast; cancel `OR EAX,-1` | **Confirmed** (skill-path pending skill) | Not skill-only — multi-mode SM (`FUN_0093d110` switch) |
| **+0x30c4** | 1 | `showSkillTargetPrompt` | `*(char*)(+0x30c4)=param_2`; gates select-or-ESC toast | **Confirmed** | — |
| +0x109c | 4 | chat/UI message sink | null-checked before `FUN_008f8200` | High | Product type open |
| +0x1168 | 4 | cursor controller `*` | switch writes `+0x4e8/+0x4ec/+0x4f0` (or dword index form) | High role | Type name open |

See residual `reviews/a_0093bac0.md` and duals `A_/B_aa_0093bac0_*`.

## Notes

- Full `VehicleEntity` layout is **not** claimed.
- Havok framework / `VehicleAction` layouts remain under `physics/` (deferred primary priority).
- InventoryGrid stamp formula sealed (`height*(ox+dx)+(oy+dy)`; see `aa_00571620` / `a_00571620.md`). Full inventoryType English name map remains open (caller-side).
- Full Client layout is **not** claimed; only the pending-skill pair above is sealed from this dual.
