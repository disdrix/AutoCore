# Function record: CDlgQuickBar_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a16b0` |
| **Canonical name** | `CDlgQuickBar_CreateChildWidgets_Inferred` |
| **Address** | `0x008a16b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / client QuickBar UI |
| **Completion status** | **Dual A/B complete** (2026-07-29 W21-R) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_008a16b0` | Ghidra default / scaffold |
| `UI_qb_hazard_gauge` | Prior plate-string seed (too narrow; superseded) |
| `CDlgQuickBar_CreateChildWidgets_Inferred` | Dual canonical |

## Purpose

Build and wire CDlgQuickBar child chrome: allocate/parent children (including two `UI_QuickBar_CreateSlotButton` page buttons labeled 1/2), load hazard XML skins, Y-reposition `+0x684`, rebind page columns, restore or auto-pick remembered column selection. Client UI only — no network.

## Signature

```c
// ECX = CDlgQuickBar* host; void; MSVC SEH
void __fastcall CDlgQuickBar_CreateChildWidgets_Inferred(int *host);
```

## Key host slots

| Index | Off | Role |
|------:|----:|------|
| `0x143` | `+0x50c` | current page |
| `0x189`/`0x18a` | `+0x624`/`+0x628` | 0x488 chrome pair |
| `0x199` | `+0x664` | mid widget (0x580) |
| `0x19b`/`0x19c` | `+0x66c`/`+0x670` | page buttons index 0/1 |
| `0x1a0` | `+0x680` | hazard gauge |
| `0x1a1` | `+0x684` | Y-reposition target |
| `399+col` | `+0x63c+` | 10 page column widgets (after `FUN_008a1110`) |

## String evidence

- `i_d_qb_2d_btn_inc.xml`
- `i_d_qb_2d_wnd_hazard_bar.xml`
- `i_d_qb_2d_wnd_hazard_inc.xml`
- `i_d_qb_2d_wnd_hazard_gauge.xml`
- `i_d_qb_2d_wnd_hazard_label.xml`
- Vtable-adjacent: `Show Quick Menu` / `Hide Quick Menu` @ `0x00a4d338`

## Artifacts

- Raw + re-verify: `docs/reconstruction/raw/aa_008a16b0_FUN_008a16b0.md`
- Annotated: `docs/reconstruction/raw/aa_008a16b0_FUN_008a16b0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CDlgQuickBar_CreateChildWidgets_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_008a16b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_008a16b0_FUN_008a16b0.md`
- Review A: `docs/reconstruction/reviews/A_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008a16b0_CDlgQuickBar_CreateChildWidgets_Inferred.md`

## Callers / callees

**Callers:** virtual (data xref `0x00a4d320`); no direct call sites.  
**Callees (key):** `FUN_00792600`, `operator_new`, `FUN_0082f4a0`, `FUN_007b5dd0`, `FUN_0079c860`, `FUN_008c4f10`, `UI_QuickBar_CreateSlotButton` (`FUN_00825bf0`), `FUN_0097ffa0`, `FUN_008b0ce0`, `FUN_008a0370`, `FUN_008a04b0`, `FUN_008a1110`, `FUN_008a0e10`, `FUN_008a0210`, `UI_QuickBarSlotButton_SetSelected` (`FUN_00826780`), `FUN_008a0770`, `sprintf`, host vtbls `+0xa8/+0x3f4/+0x404/+0x448/+0x34c`.

## Confidence

| Claim | Level |
|---|---|
| Role = QuickBar host CreateChildWidgets | **High** |
| Two slot buttons at +0x66c/+0x670 indices 0/1 | **High** |
| Hazard XML chrome + gauge | **High** |
| Tail rebind + selection restore | **High** CF |
| Host is `CDlgQuickBar` | **Probable** (RTTI on sibling activate path) |
| Product method name | **Inferred** |
| Early 0x488/0x4cc child product roles | **Open** |
| Runtime / bit-exact | Open |
