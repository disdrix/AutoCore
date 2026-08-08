# Function record: UI_InteractionMenu_AddSendTell_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f810` |
| **Canonical name** | `UI_InteractionMenu_AddSendTell_Inferred` |
| **Ghidra name** | `FUN_0082f810` |
| **Prior scaffold** | `FUN_0082f810` / `UI_int_btn_generic` |
| **Rejected misname** | skill-cast / HB residual; ECX-thiscall entry; convoy disable peer |
| **Address** | `0x0082f810`–`0x0082f849` inclusive (**58 B** / `0x3A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction menu / tell UI |
| **Agent** | MEGA-073 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps** — CF/ABI/strings/slot sealed; host class open) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; Terminal false) |

## Purpose

MSVC client leaf that adds a **"Send a Tell"** interaction-menu button for the current target menu host. Creates a generic 2D button widget from plate XML, assigns product caption and button id **`0x11176`**, and caches the widget pointer on the host at **`+0x554`**.

```text
UI_InteractionMenu_AddSendTell_Inferred(menu /*EDI*/)
  btn = menu.vtbl+0x444("i_m_int_2d_btn_generic.xml", 0, 0x11176, -1)
  if btn: btn.vtbl+0x1D8("Send a Tell", 1, 1)
  menu+0x554 = btn
```

## Signature (decompiler + bytes + parent)

```c
// Parent-preserved EDI = menu host*; no stack args; RET (C3)
void UI_InteractionMenu_AddSendTell_Inferred(/* EDI */ void* menuHost);
```

| Item | Value |
|---|---|
| Create vtbl | host `+0x444` |
| Label vtbl | btn `+0x1D8` |
| Button id | `0x11176` |
| Plate | `i_m_int_2d_btn_generic.xml` @ `0x00a721ac` |
| Caption | `Send a Tell` @ `0x00a72158` |
| Host slot | `+0x554` (`EDI[0x155]`) |
| Parent | dualed `UI_InteractionMenu_PopulateTargetButtons_Inferred` `0x0082fe20` |
| Peer | dualed `UI_InteractionMenu_AddConvoyInviteOrKick_Inferred` `0x0082fb30` |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_0082f810_FUN_0082f810.md`
- Annotated: `docs/reconstruction/raw/aa_0082f810_FUN_0082f810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddSendTell_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0082f810.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0082f810_UI_InteractionMenu_AddSendTell_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_0082f810_FUN_0082f810.md`
- Report: `docs/agents/task-dual-ab-0082f810-mega-073-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `FUN_0082fe20` | 2 UNCONDITIONAL_CALL; `MOV EDI,ESI` before both |
| Direct callees | none | leaf |
| Indirect | host `vtbl+0x444` | create from XML + id |
| Indirect | btn `vtbl+0x1D8` | set caption |

## Confidence

| Claim | Level |
|---|---|
| Control flow ≡ live decompile + asm | **Confirmed** |
| EDI host + RET 0 | **Confirmed** |
| "Send a Tell" + id `0x11176` + slot `+0x554` | **Confirmed** |
| Role vs skill-cast misname | **Confirmed reject misname** |
| Product host class English | **Inferred** |
| Runtime / bit-exact | **Open** |
