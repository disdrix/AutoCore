# Function record: Item_PatenteeMatchesCharacterOrEmpty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522950` |
| **Canonical name** | `Item_PatenteeMatchesCharacterOrEmpty_Inferred` |
| **Ghidra name** | `FUN_00522950` |
| **Address** | `0x00522950`–`0x005229b1` inclusive (**98 B** / `0x62`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` / Reverse-Engineer + item-hover craft status |
| **Classification** | worker |
| **Completion status** | **Dual A/B sealed** (MEGA-108 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias / rejected plates

| Name | Status |
|---|---|
| `FUN_00522950` | Ghidra default — twin |
| `Item_PatenteeMatchesCharacterOrEmpty_Inferred` | **Preferred** structural |
| `Named_CalleeOf_Mission_Mission_Object_00522950` | Scaffold — **retired** |
| `UI_ItemHover_FormatCraftStatus` | Partition **host** hint for parent `0x0085ce20` — **not** this VA |
| Mission helper / Mission_Mission_Object callee | **Rejected** — zero mission xrefs |

## Purpose

Boolean gate used before Reverse-Engineer UI copy and Inv RE action:

1. `item == null` → **false**
2. C-string at **`item+0x101`** empty → **true** (no patent restriction)
3. Else `_stricmp(item+0x101, characterName)` where `characterName` comes from character **MI this-adjust + vtbl+0x160** → **true** iff equal (case-insensitive)

Sibling UI (`FUN_00847240`) prints the same field as **`"Patented By: "` + string**, sealing the field role.

Does **not** implement full RE eligibility (broken bit, stack, recipe, craft material type `0x1a`, cargo).

## Signature (sealed)

```c
// ECX = Character*; stack Item*; AL bool; RET 4 (all exits)
bool __thiscall Item_PatenteeMatchesCharacterOrEmpty_Inferred(
    Character *character,
    Item *item);
```

| Item | Value |
|---|---|
| Body | `0x00522950`–`0x005229b1` inclusive (**98 B** / `0x62`) |
| Full hex | see raw MEGA-108 re-verify |

## Layout

| Offset | Object | Role |
|---|---|---|
| +0x101 | Item | patented-by C-string (NUL-terminated) |
| +0x4 → … | Character | MI vbtable path to secondary base |
| vtbl +0x160 | Character secondary | returns `char*` name (product open) |

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `FUN_0085ce20` @ `0085cee3` — `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (dualed) |
| Caller | `FUN_0093d110` @ `0093d507` — Inv Reverse Engineer action (residual) |
| Caller | `FUN_00847240` @ `0084797c` — item detail / patented-by line (residual) |
| Caller | `FUN_0052e640` @ `0052e699` — RE eligibility float helper (residual MEGA-117 family) |
| Callee | `_stricmp` via IAT `0x009c6678` |
| Virtual | character `+0x160` |

## Evidence for name

1. Field display string `"Patented By: "` @ `0x00a698a8` with same `item+0x101` in `FUN_00847240`.
2. Four RE/item-hover call sites; fail paths use `"Cannot be Reverse Engineered."`.
3. Character this from `DAT_00d1b6d8` / `[obj+0xe98]` — local character, not item.
4. Empty-or-match predicate matches RE gate usage (mismatch blocks RE).

`_Inferred` retained: no PDB; vtbl+0x160 English structural.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00522950_FUN_00522950.md`
- Annotated: `docs/reconstruction/raw/aa_00522950_FUN_00522950.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Item_PatenteeMatchesCharacterOrEmpty_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00522950.cpp`
- Function FUN: `docs/reconstruction/functions/aa_00522950_FUN_00522950.md`
- Review A: `docs/reconstruction/reviews/A_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md`
- Agent report: `docs/agents/task-dual-ab-00522950-mega-108-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / body size | **High** (bytes + callers) |
| Patented-by field role | **High** (product UI string) |
| Character name via +0x160 | **Probable** (string return + stricmp) |
| Product function English | **Open** → `_Inferred` |
| Runtime Confirmed | Open |
