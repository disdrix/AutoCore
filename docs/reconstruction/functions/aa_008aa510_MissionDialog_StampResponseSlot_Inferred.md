# Function record: MissionDialog_StampResponseSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa510` |
| **Canonical name** | `MissionDialog_StampResponseSlot_Inferred` |
| **Ghidra name** | `FUN_008aa510` |
| **Address** | `0x008aa510` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Body** | `0x008aa510`–`0x008aa55b` exclusive (**75 B** / `0x4B`); pad `CC` before clear peer `0x008aa560` |
| **Dual verdict** | **accept-with-gaps** (MEGA-046 A/B) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Naming

| Form | Status |
|---|---|
| `MissionDialog_StampResponseSlot_Inferred` | **Primary** (meaningful; product English open → `_Inferred`) |
| `FUN_008aa510` | Ghidra twin keep |
| `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510` | **Retired** MEGA-046 |

Rationale: stamps one response-button slot (caption + TFID). Peer wipe is dualed `MissionDialog_ClearResponseButtonSlots_Inferred` @ `0x008aa560`. Not reward chrome (`+0x558`/`+0x698`).

## Purpose

```
if slot in [0, dialog.count@0x510):
  if widget@0x708[slot]:
    setCaption(caption, 1, 1)   // vtbl+0x1d8
    refresh()                   // vtbl+0x34c
  tfid@0x518[slot] = (lo, hi)
```

## ABI

| Slot | Role |
|---|---|
| EDI | `MissionDialogHost*` |
| ESI | `int slotIndex` |
| EDX | `const char* caption` |
| stack +4 / +8 | `tfidLo` / `tfidHi` |
| return | void, **`RET 8`** |

## Call graph (evidence only; parents not dualled here)

```
Client_ShowNpcMissionDialogUI  [0x009438f0]
  ├─ FUN_008ac110          rebuild response XML chrome
  └─ FUN_008aa510 ×1..2    stamp Complete|OK|Accept/Decline  (−1,−1)

FUN_0093e450               choice / no-choices dialog path
  ├─ FUN_008ac110
  ├─ FUN_008aa510          "Work in progress" (−1,−1) when no choices
  └─ loop: FUN_0057a250 → FUN_008aa510  dynamic caption + TFID

FUN_008aa560  MissionDialog_ClearResponseButtonSlots_Inferred  [peer wipe; dualed]
  └─ clears 8× TFID@+0x518 and widgets@+0x708  (inverse family)
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_StampResponseSlot_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008aa510.cpp` |
| FUN record | `docs/reconstruction/functions/aa_008aa510_FUN_008aa510.md` |
| Review A | `docs/reconstruction/reviews/A_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008aa510-mega-046-report.md` |

## Gaps

- Product/PDB name.
- Vtbl +0x1d8 / +0x34c product English.
- Dynamic TFID domain from `FUN_0057a250`.
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / body / RET 8 | **High** |
| Register + stack ABI | **High** |
| Response banks shared with clear peer | **High** |
| Caption role (string seals) | **High** |
| Product symbol | **Open** |
