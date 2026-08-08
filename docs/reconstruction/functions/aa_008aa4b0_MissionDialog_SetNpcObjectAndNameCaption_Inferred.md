# Function record: MissionDialog_SetNpcObjectAndNameCaption_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa4b0` |
| **Canonical name** | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` |
| **Ghidra name** | `FUN_008aa4b0` |
| **Address** | `0x008aa4b0`–`0x008aa50e` inclusive (**95 B** / `0x5F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Parent context** | `Client_ShowNpcMissionDialogUI` (`0x009438f0`); pre thr/steer park `FUN_009373e0` |
| **Completion status** | **Dual sealed MEGA-058** (`accept-with-gaps`) |
| **Bit-for-bit / runtime / diff** | Open (terminal false) |

## Naming

| Kind | Name |
|---|---|
| Canonical | `MissionDialog_SetNpcObjectAndNameCaption_Inferred` |
| Ghidra | `FUN_008aa4b0` |
| Retired | `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` |

`_Inferred` — no product/PDB string; role from offsets + dualed parent `+0x644` NPC stamp + sibling header caption at `+0x6e0`.

## Purpose

```text
ESI=dialog, EAX=npc (0 clear):
  dialog+0x644 = npc
  w = dialog+0x6d8
  if w:
    if npc==0: w.SetText("", 1, 1)           // vtbl+0x1d8
    else:      w.SetText(npc.GetName(1,1))   // +0x160 then +0x1d8
    JMP w.Refresh()                          // vtbl+0x34c tail
```

## Signature

```c
// Register contract: ESI = dialog*, EAX = npcObject*
void MissionDialog_SetNpcObjectAndNameCaption_Inferred(void);
```

## Related units (not dualled here)

| VA | Role |
|---|---|
| `0x008aaf60` | `Client_MissionDialog_SetHeaderCaption_Inferred` — header widget `+0x6e0` |
| `0x008aa510` | response-slot TFID / caption (sibling bank) |
| `0x009438f0` | `Client_ShowNpcMissionDialogUI` — dualed parent |
| `0x009373e0` | dialog gate thr0+steer0+HB after this helper |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008aa4b0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_008aa4b0_FUN_008aa4b0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008aa4b0-mega-058-report.md` |
