# Function record: CVOGCharacter_CleanupDraggingObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520dc0` |
| **Canonical name** | `CVOGCharacter_CleanupDraggingObject` |
| **Ghidra name** | `FUN_00520dc0` |
| **Address** | `0x00520dc0`–`0x00520f39` (**378 B** / `0x17A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Dual complete (accept-with-gaps)** — 2026-08-05 MEGA-001 OWN-ONLY |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Purpose

Product method **`CVOGCharacter::CleanupDraggingObject`**: dispose the object held in the character dragging slot (`this+0xCD0`) by:

1. **Cargo place** — `InventoryGrid_FindFreeForItem` + `InventoryGrid_PlaceItemFootprint` on `*( *(this+0x250)+0x2B0 )`
2. **Locker place** — same pair on `*(this+0xCBC)`
3. **Equip fallback** — `Character_TryEquipItem`(`*(this+0x250)`, drag, &out); if `out==0` and status ∈ `{0,1,10,13,15}`, `FUN_00502e90`(host, drag)

Always nulls `+0xCD0` after a non-null drag. Returns **false** if no drag object, else **true**.

## Signature

```c
bool __thiscall CVOGCharacter_CleanupDraggingObject(void* self /*, uint32_t unused_stack */);
// ECX=this; RET 4; AL bool
```

## Closed form

```text
Profiler_Enter("CVOGCharacter::CleanupDraggingObject")
drag = *(this+0xCD0)
if !drag: Leave; return false
if FindFree(cargo)+Place: goto clear
if FindFree(locker)+Place: goto clear
code = TryEquip(host=*(this+0x250), drag, &out)
if out==0 && code in {0,1,0xA,0xD,0xF}: EquipSwitch(host, drag)
clear:
*(this+0xCD0)=0
Leave; return true
```

## Sealed facts

| Fact | Evidence |
|---|---|
| Product name | string `0x009cf0b0` |
| Body size 378 B | CF + disasm end `RET 4` |
| ABI thiscall + RET 4 + AL bool | prologue/epilogue bytes |
| Cargo vs locker grids | distinct ECX loads in asm |
| FindFree args `1,-1` | push sequence both paths |
| Qty via vtbl+0x25C | call-site before Place |
| Always clear non-null drag | store 0 at CLEAR |

## Not sealed / gaps

| Item | Status |
|---|---|
| Direct callers | **0** Ghidra xrefs — open |
| Unread stack dword meaning | open |
| TryEquip status English | open |
| Runtime Confirmed | open |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CleanupDraggingObject.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00520dc0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` |
| Machine record | `docs/reconstruction/functions/aa_00520dc0_FUN_00520dc0.md` |
| Report | `docs/agents/task-dual-ab-00520dc0-mega-001-report.md` |

## Related (not OWN)

| VA | Role |
|---|---|
| `0x005714e0` | FindFreeForItem (dualed) |
| `0x00571620` | PlaceItemFootprint (dualed) |
| `0x004fabc0` | Character_TryEquipItem (dualed) |
| `0x00502e90` | menu_equip type switch (residual) |
| `0x00786a00` / `0x00786990` | profiler enter/leave (dualed) |
