# Function record: Character_TryEquipItem (`FUN_004fabc0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fabc0` |
| **Canonical name** | `Character_TryEquipItem` (proposed) |
| **Ghidra name** | `FUN_004fabc0` |
| **Address** | `0x004fabc0` |
| **Body** | `0x004fabc0` … `0x004fad57` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / equip |
| **Completion status** | **Dual complete (accept-with-gaps)** — 2026-07-29 W17-E; **Broken→9** / **`\|0x10`** / type switch sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Prior scaffold: `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004fabc0`
- Human role: **equip attempt dispatcher** (gates + type switch)

## Purpose

Character/host tries to equip or apply an inventory item: set sticky flag **`0x10`** on `item+0x17c`, dirty via `FUN_00512670`, reject **Broken** with status **9**, apply session/precheck gates, then dispatch by clonebase type to type-specific equip helpers.

## Signature (decompiler + bytes)

```c
// ECX = host Character*; stack: Item*, optional out*; ret 8
unsigned int __thiscall Character_TryEquipItem(int host /* ECX */, int *item, unsigned int *outOpt);
```

## Closed form

```text
if (!item) return 8;
if (out) *out = 0;
item.flags[+0x17c] |= 0x10;
FUN_00512670(item);                 // | 0x20000 dirty chain
if (Broken(item)) return 9;         // bit19 / 0x80000
if (session[+0xf6]) return 0xf;
if (!precheck(host)) return 6;
switch (clonebase_type(item)):
  6,10,0xc,0xe,0x10,0x1c → type helpers / vehicle path
  8,0x32 → return 0xc
  default → return 8
```

## Sealed gates

| Gate | Value | Evidence |
|------|-------|----------|
| Flag OR | **`item+0x17c \|= 0x10`** | `83 8e 7c 01 00 00 10` |
| Dirty | **`FUN_00512670`** | rel call @ `004FABEE` → `00512670` |
| Broken | bit **19** → code **9** | `shr 0x13` / `test al,1` / `mov eax,9` |
| ABI | **`ret 8`** | `c2 08 00` |
| Type switch | jump @ `004fad58`, index @ `004fad78` | tables in body |

## Not this unit

| Role | VA |
|------|-----|
| Dirty helper | `0x00512670` |
| Broken setter | `0x00513de0` |
| Type-specific equip helpers | `0x004f65e0`…`0x004f6940`, `0x004f6560`, `0x004ce5f0` |
| Confirm UI parent | `0x00941b20` `Client_ConfirmEquipOrCustomizeItem` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.md`
- Annotated: `docs/reconstruction/raw/aa_004fabc0_FUN_004fabc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_TryEquipItem.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004fabc0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004fabc0_Character_TryEquipItem.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004fabc0_Character_TryEquipItem.md`
- Report: `docs/agents/task-dual-ab-004fabc0-character-tryequipitem-report.md`

## Callers / callees (sample)

| Direction | Examples |
|-----------|----------|
| Callees | `FUN_00512670`, `FUN_00514390`, `FUN_004f6940`, `FUN_004f6840`, `FUN_004f65e0`, `FUN_004f6890`, `FUN_004f67e0`, `FUN_004ce5f0`, `FUN_004f6560`, `__RTDynamicCast` |
| Callers | `Client_ConfirmEquipOrCustomizeItem` `00941b20`, `Client_UI_InventoryItemClickDispatch` `008635b0`, `Client_SendInventoryDrop_Hardpoint` `00863430`, `FUN_00862b70`, `FUN_0085fa20`, `FUN_008012f0`, `FUN_00520dc0`, `FUN_0092fb30` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High / Sealed** |
| Broken → status 9 | **High / Sealed** |
| `\|0x10` + dirty always (when item non-null) | **High / Sealed** |
| Type-case map | **High / Sealed** |
| Status-code product English | Tentative / Open |
| Original PDB symbol | Open |
