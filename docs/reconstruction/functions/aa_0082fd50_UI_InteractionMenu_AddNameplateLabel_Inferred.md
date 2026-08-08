# Function record: UI_InteractionMenu_AddNameplateLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082fd50` |
| **Canonical name** | `UI_InteractionMenu_AddNameplateLabel_Inferred` |
| **Ghidra name** | `FUN_0082fd50` |
| **Address** | `0x0082fd50`–`0x0082fe20` exclusive |
| **Body size** | **208 B** (`0xD0`); epilogue `pop esi; pop ebp; add esp,8; ret` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction menu / social UI |
| **Completion status** | **Dual sealed** (MEGA-084 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Alias

- Human: `UI_InteractionMenu_AddNameplateLabel_Inferred`
- Ghidra: `FUN_0082fd50`
- Prior plate-only: `UI_int_btn_generic_0082fd50` (superseded for role)

## Purpose

Populate the interaction-menu **nameplate label** for a resolved owner/target: create generic button id `0x1117F` from `i_m_int_2d_btn_generic.xml`, set label to the object's display name (`vtbl+0x160`), store at host `+0x53C`, force non-interactive, apply one of two ARGB tints from `target+0x6B4`, set `btn+0x170 = -2`, finalize chrome.

## Signature

```c
// register-arg fragment (parent-preserved)
// EDI = menu host*; EBX = owner/target*; ret 0
void UI_InteractionMenu_AddNameplateLabel_Inferred(MenuHost* menu, Object* target);
```

## Layout / contracts

| Offset / slot | Role |
|---|---|
| host `+0x53C` | nameplate button pointer |
| target `+0x6B4` | color gate (`<1` → `0xFF1EA0B4`, else `0xFFA01EB4`) |
| btn `+0x170` | written `0xFFFFFFFE` |
| object `vtbl+0x160` | display-name getter |
| host `vtbl+0x444` | create(xml, 0, id, -1) |
| btn `vtbl+0x1D8` | set text |
| btn `vtbl+0xD4` | disable (always 0 here) |
| btn `vtbl+0x15C` | set color |
| btn `vtbl+0x1E4` | post-setup |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082fd50_FUN_0082fd50.md`
- Annotated: `docs/reconstruction/raw/aa_0082fd50_FUN_0082fd50.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddNameplateLabel_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082fd50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082fd50_UI_InteractionMenu_AddNameplateLabel_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082fd50_FUN_0082fd50.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0x0082fe20`) ×2 sites |
| Callees | none direct (vtbl leaf) |
| Dualed parent | `aa_0082fe20` |
| Dualed peer pack | `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` (`0x0082fb30`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile / raw | **Confirmed** |
| ABI regs + id/slot/colors | **Confirmed** |
| Nameplate role (dynamic name + disable) | **High** |
| Product host class / `+0x6B4` English | **Inferred / Open** |
