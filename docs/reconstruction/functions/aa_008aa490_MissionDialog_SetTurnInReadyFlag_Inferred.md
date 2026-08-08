# Function record: MissionDialog_SetTurnInReadyFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa490` |
| **Canonical name** | `MissionDialog_SetTurnInReadyFlag_Inferred` |
| **Ghidra name** | `FUN_008aa490` |
| **Address** | `0x008aa490`–`0x008aa4a6` (**23 B** / `0x17`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-078 — Dialog pre-present setup |
| **Parent dual / context** | `Client_ShowNpcMissionDialogUI` (`0x009438f0`) |
| **Completion status** | **Dual sealed MEGA-078** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |

## Alias / retired

| Kind | Name |
|---|---|
| Ghidra | `FUN_008aa490` |
| Retired scaffold | `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490` |

## Purpose

Apply turn-in readiness flag to the NPC mission dialog host **before** present/chrome fill:

1. `*(char*)(dialog + 0x580) = flag` (always).
2. If `*(void**)(dialog + 0x6e8) != NULL`, call child `vtbl[+4](flag)`.

Flag source at sole call site: `FUN_0052b420` turn-in readiness probe (AL → `[ESP+0x1c]` → DL).

## Signature (ABI-sealed)

```c
// EAX = dialog host (client+0x1058 / piVar2 / EBX at call site)
// DL  = turn-in ready (0/1)
// void; bare RET
void MissionDialog_SetTurnInReadyFlag_Inferred(void);
```

## Call graph (owned unit only)

```text
Client_ShowNpcMissionDialogUI  [0x009438f0]
  ├─ FUN_0052b420  turn-in readiness probe  [evidence only]
  ├─ FUN_008aa490  MissionDialog_SetTurnInReadyFlag_Inferred  [OWN MEGA-078]
  ├─ Client_NpcDialog_PrepareResponseOpcode  [0x008abd70]
  ├─ FUN_008ab550 / FUN_008aa4b0 / FUN_008aaf60 / FUN_008ac110 / ...
  └─ FUN_0092f090  axis park finalize
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_SetTurnInReadyFlag_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_008aa490.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008aa490-mega-078-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Body bounds / hex / CF | **High** |
| EAX + DL ABI / bare RET | **High** |
| +0x580 store / +0x6e8 optional vcall | **High** |
| Pre-present placement after 52b420 | **High** |
| Product class/field/method English | **Low** → `_Inferred` |
| Runtime Confirmed | **Open** |

## Gaps

- Product/PDB names for host, `+0x580`, `+0x6e8`, and child `vtbl[+4]`.
- EDX upper-byte contract at vcall (caller only assigns DL).
- Runtime / bit-exact / differential.
