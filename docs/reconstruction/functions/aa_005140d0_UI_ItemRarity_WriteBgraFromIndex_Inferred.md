# Function record: UI_ItemRarity_WriteBgraFromIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005140d0` |
| **Canonical name** | `UI_ItemRarity_WriteBgraFromIndex_Inferred` |
| **Ghidra name** | `FUN_005140d0` |
| **Address** | `0x005140d0`–`0x0051416a` exclusive (+ jump table `@0x0051416c`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Name confidence** | **High** role (rarity-index BGRA palette writer); product English **Inferred** |
| **Completion status** | **Dual residual sealed 2026-08-05 R12-016** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** (no Runtime Confirmed) |

## Purpose

Leaf fixed palette: map signed rarity index (typically clone-base `blob+0x4b8`) to a 4-byte **BGRA** color for item tooltip / detail rarity text. Does not load rarity name strings (`EnsureLootRarityTableLoaded` / `DAT_00b04214`) and does not append UI text.

## Signature

```c
uint8_t* UI_ItemRarity_WriteBgraFromIndex_Inferred(uint8_t outBgra[4], int16_t rarityIndex);
// cdecl; bare ret; EAX = out
```

## Sealed facts

| Claim | Confidence |
|---|---|
| Indices 0..5 + default colors | **High** |
| cdecl stack formals / bare RET / EAX=out | **High** |
| Leaf | **High** |
| BGRA memory / AARRGGBB dword | **High** |
| Parent uses `blob+0x4b8` as index | **High** (dualed `00847240`) |
| Product symbol | **Open** → `_Inferred` |

### Palette

| index | AARRGGBB | notes |
|------:|----------|-------|
| 0 | `0xFF919191` | gray |
| 1 | `0xFFFFFFFF` | white |
| 2 | `0xFF2828FF` | blue |
| 3 | `0xFFF014F0` | purple |
| 4 | `0xFFFF0A23` | orange-red |
| 5 | `0xFFFF8A0A` | gold |
| default | `0xFFF0E43C` | cyan (`index < 0` or `> 5`) |

## Callers (7)

`FUN_00847240` (parent dual R11-029), `FUN_0084b890`, `FUN_00843a60`, `FUN_008becd0`, `FUN_008b6590`, `FUN_008c03c0`, `FUN_00904d50`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.md`
- Annotated: `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_ItemRarity_WriteBgraFromIndex_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_005140d0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md`, `B_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_005140d0_FUN_005140d0.md`
- Report: `docs/agents/task-dual-ab-005140d0-r12-report.md`

## Retired names

- `Named_CalleeOf_Mission_Mission_Object_005140d0`
