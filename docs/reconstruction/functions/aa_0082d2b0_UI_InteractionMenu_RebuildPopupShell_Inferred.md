# Function record: UI_InteractionMenu_RebuildPopupShell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d2b0` |
| **Canonical name** | `UI_InteractionMenu_RebuildPopupShell_Inferred` |
| **Ghidra name** | `FUN_0082d2b0` |
| **Address** | `0x0082d2b0`–`0x0082d3ce` exclusive |
| **Body size** | **286 B** (`0x11E`); `ret` (`C3`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / interaction-menu UI shell (shared popup host) |
| **Agent** | MEGA-072 OWN-ONLY dual 2026-08-05 |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |
| **Partition** | MEGA-072 / P86 / parent dual `0x0082fe20` |

## Alias

- Human: `UI_InteractionMenu_RebuildPopupShell_Inferred`
- Ghidra: `FUN_0082d2b0`
- Retired: `Named_CalleeOf_Skill_i_m_qb_2d_btn_menu_skills_xml_0082d2b0`
- Informal: `UI_pop_blocker` (XML evidence)

## Purpose

When the menu host is active (`this+0x4C0`), rebuild the popup shell: replace owned CNDHash at `+0x534`, destroy prior dialog at `+0x538`, construct a 0x488 NDUI dialog, load `i_d_pop_2d_wnd_blocker.xml` at layer **70000**, reattach, update depth counters (`+0x68` / float `+0x74` / max `+0x70`), and fire host `vtbl+0x3f4(1)`.

Shared by dualed interaction-menu populate and multiple other `+0x4C0`-gated menu hosts — not skill-cast residual.

## Signature

```c
// __thiscall; ECX = menu host*; ret 0
void UI_InteractionMenu_RebuildPopupShell_Inferred(MenuHost* host);
```

## Layout / contracts

| Offset / slot | Role |
|---|---|
| `this+0x4C0` | active/valid menu gate |
| `this+0x534` | owned CNDHash* (rebuild via `new(0x34)` + `FUN_00416920` CL=2) |
| `this+0x538` | owned popup/blocker dialog* |
| `this+0x68` | depth / child count |
| `this+0x74` | float depth (`-(float)count`) |
| `this+0x70` | max depth |
| `this+0x4A4` | secondary flag (cleared) |
| `vtbl+0x450` | pre-rebuild clear |
| `vtbl+0xbc` | destroy child widget |
| `vtbl+0xa8` | attach child dialog |
| `vtbl+0x3f4` | post-rebuild notify (arg 1) |
| dialog `vtbl+0x28` | load XML |
| dialog `vtbl+0x74` | set layer/z |
| DATA xref `0x00a733b8` | vtbl method pointer |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082d2b0_FUN_0082d2b0.md`
- Annotated: `docs/reconstruction/raw/aa_0082d2b0_FUN_0082d2b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_RebuildPopupShell_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082d2b0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082d2b0_UI_InteractionMenu_RebuildPopupShell_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082d2b0_FUN_0082d2b0.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | dualed `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0x0082fe20`); skill/equip/other menu hosts; DATA vtbl `0x00a733b8` |
| Callees | `operator_new`, `FUN_00416920`, `FUN_007b5dd0`, host/dialog vtbl |
| Peer dual | `CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred` (`0x0082ce20`) |
| Dualed parent | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0x0082fe20`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile / raw / asm | **Confirmed** |
| Shell rebuild role + multi-caller | **Confirmed** |
| Product English name | **Inferred** |
