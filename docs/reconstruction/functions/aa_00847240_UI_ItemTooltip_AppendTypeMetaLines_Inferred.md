# Function record: UI_ItemTooltip_AppendTypeMetaLines_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847240` |
| **Canonical name** | `UI_ItemTooltip_AppendTypeMetaLines_Inferred` |
| **Ghidra name** | `FUN_00847240` |
| **Address** | `0x00847240` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual complete (accept-with-gaps)** — R11-029 2026-08-05 |
| **Terminal** | **false** |

## Boundary

| Start | End (exclusive) | Size |
|-------|-----------------|------|
| `0x00847240` | `0x008479f0` | `0x7B0` (1968 B) |

## Signature

```c
// cdecl; EDI = UiTextHost* (caller-live)
int UI_ItemTooltip_AppendTypeMetaLines_Inferred(Item *item, char showMeta);
// caller: ADD ESP, 8; ret C3; EAX = line_count_delta
```

## Role

Build and append the **type header + meta footer** of an item tooltip / detail text block:

1. Type-class / subtype English (incl. weapon mount detail for class `0xc`).
2. Rarity name + color (`blob+0x4b8` → table `DAT_00b04214` stride `0x48`).
3. Optional meta (`showMeta`): customize-on-equip / customized-for, not-tradable, charges.
4. Patentee line from `item+0x101`.
5. RE / memorize forbid lines (session-gated).

## Dual

| Path | Verdict |
|------|---------|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |

## Key callees (dualed)

- `Item_RequiresBindOrTradeLock` `0x00513fc0`
- `Item_PatenteeMatchesCharacterOrEmpty_Inferred` `0x00522950`
- `EnsureLootRarityTableLoaded_Inferred` `0x005129b0`

## Key callers

- `UI_ItemDetailPanel_Refresh_Inferred` `0x0084b890`
- `FUN_00843a60` (equipped compare residual)

## Retired names

- `Mission_Mission_Object_00847240` — string-weak

## Artifacts

See twin record `aa_00847240_FUN_00847240.md` for full path table.
