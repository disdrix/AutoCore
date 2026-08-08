# Function record: Client_Interact_OpenCVOGStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00938670` |
| **Canonical name** | `Client_Interact_OpenCVOGStore_Inferred` |
| **Ghidra name** | `FUN_00938670` |
| **Address** | `0x00938670`–`0x009387dc` inclusive (**365 B** / `0x16D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` |
| **Partition** | MEGA-027 (WAVE_2026-08-05 mega residual) |
| **Parent context** | `Client_InteractClickPickTarget` (`0x009247b0`) type case **0x16**; also `FUN_00946c00` event case **3** |
| **Completion status** | **Dual A/B sealed** 2026-08-05 — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Terminal** | **false** |

## Purpose

Client interact helper that opens a **CVOGStore** UI from a world/event TFID:

1. If local vehicle entity exists (`client+0xe98 → +0x250`): set flag **+0x109=1**, handbrake **1**, longitudinal input **0**.
2. `Object_ResolveFromTFID` + `__RTDynamicCast` **ClonedObjectBase → CVOGStore**.
3. Early-out when the matching store dialog is already visible and bound to this store.
4. Send C2S sector packet **opcode 0x2024**, size **0x18**, via communicator `client+0xc78`.
5. Stamp TFID into dialog host slot and open dialog index **0x0B** (`store+0x4e5==0`) or **0x0C** (else) through `FUN_007fef20`.

## Signature (assembly-sealed)

```c
// ESI live-in client*; stack TFID_16; void; RET 0x10
void Client_Interact_OpenCVOGStore_Inferred(
    /*ESI*/ ClientController* client,
    TFID_16 storeTfid /* 4 stack dwords */);
```

| Formal | Source | Conf |
|---|---|---|
| client | ESI live-in | **Confirmed** |
| storeTfid | stack 16 B | **Confirmed** |
| return | void | **Confirmed** |
| cleanup | `RET 0x10` | **Confirmed** |

## Key constants / offsets

| Symbol / offset | Value | Role |
|---|---|---|
| RTTI CVOGStore | `0x00afe0c8` | cast target |
| RTTI ClonedObjectBase | `0x00af8e10` | cast source |
| Opcode | `0x2024` | C2S store interact |
| Packet size | `0x18` | send length |
| Dialog A | `0x0B` → host `client+0x105c` | when `store+0x4e5==0` |
| Dialog B | `0x0C` → host `client+0x1060` | when `store+0x4e5!=0` |
| Host TFID slots | `+0x528` / `+0x548` | stamp |
| Host bound store | `+0x588` / `+0x5a0` | already-open compare |
| Vehicle entity | `client+0xe98 → +0x250` | park gate |

## Callers

| Address | Parent | Notes |
|---|---|---|
| `0x00924f8c` | `Client_InteractClickPickTarget` | `MOV ESI, DAT_00d1a840`; type **0x16** |
| `0x00947057` | `FUN_00946c00` | `MOV ESI,EBX`; event case **3** |

## Callees

| Target | Role |
|---|---|
| `VehicleEntity_SetFlag_109` | `entity+0x109 = 1` |
| `VehicleEntity_SetHandbrake` | park |
| `VehicleEntity_SetLongitudinalInput` | longitudinal **0** |
| `Object_ResolveFromTFID` | TFID → object* |
| `__RTDynamicCast` | → CVOGStore |
| `FUN_007fef20` | open dialog by index |
| vtbl `+0x3d8` / `+0x18` | visible? / send |

## Artifacts

- Raw (+ MEGA-027 re-verify): `docs/reconstruction/raw/aa_00938670_FUN_00938670.md`
- Annotated: `docs/reconstruction/raw/aa_00938670_FUN_00938670.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_Interact_OpenCVOGStore_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00938670.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InteractClickPickTarget_00938670.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00938670_FUN_00938670.md`
- Report: `docs/agents/task-dual-ab-00938670-mega-027-report.md`

## Gaps

- Product English for dialogs **0x0B** / **0x0C**.
- Product English for `CVOGStore+0x4e5`.
- Product name for `FUN_007fef20`.
- Full 0x2024 payload map (middle dword in 0x18 buffer).
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RTTI / callers | **Confirmed** |
| Store-open role | **High** |
| Product UI English | **Tentative** → `_Inferred` |
| Runtime | **Open** |
