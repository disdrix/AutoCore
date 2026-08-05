# Function record: UI_InventoryPanel_MessageHandler_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008be900` |
| **Canonical name** | `UI_InventoryPanel_MessageHandler_Inferred` |
| **Ghidra name** | `FUN_008be900` |
| **Address** | `0x008be900`–`0x008beb13` |
| **Size** | 531 bytes (`0x213`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` / UI message dispatch |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W20-F)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Inventory / item panel UI message handler. Slot ids `0x9c43..0x9c46`; close `0x9c40`; specials `0x9c41`/`0x9c42`. Message `0xe` tries inventory use then UseObject-if-interactable. Default fallthrough `UI_DefaultMessageHandler`.

## Signature

```c
uint32_t __thiscall UI_InventoryPanel_MessageHandler_Inferred(
    void *this, int msg, int controlId);
// ECX=this; ret 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008be900_FUN_008be900.md`
- Annotated: `docs/reconstruction/raw/aa_008be900_FUN_008be900.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/UI_InventoryPanel_MessageHandler_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_008be900.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008be900_UI_InventoryPanel_MessageHandler_Inferred.md`

## Callers / callees

- **Callers:** DATA slot `0x00a457a4` only (no CODE xrefs).
- **Callees:** `Client_UseInventoryItem_Inferred` (`FUN_00941d50`), `Client_SendUseObject_IfInteractable`, `FUN_007fd420`, `FUN_007fca10`, `FUN_004024b0`, `FUN_008bda60`, `UI_DefaultMessageHandler` (`FUN_0087b500`).

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompiler | **High / Confirmed** |
| ABI thiscall + ret 8 + id band | **Confirmed** |
| msg 0xe use cascade | **Confirmed** |
| Product panel class English | **Inferred** |
| Msg code product names | **Tentative** |
