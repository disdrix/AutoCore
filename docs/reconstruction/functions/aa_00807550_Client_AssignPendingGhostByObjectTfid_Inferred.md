# Function record: Client_AssignPendingGhostByObjectTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807550` |
| **Canonical name** | `Client_AssignPendingGhostByObjectTfid_Inferred` |
| **Ghidra symbol** | `FUN_00807550` |
| **Address** | `0x00807550`–`0x008075cb` exclusive (**123 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client net / pending ghost map (TFID) |
| **Completion status** | **Dual sealed (WQ9H-G)** — accept-with-gaps; Terminal false |
| **Bit-for-bit / runtime / diff** | Open |

## Alias history

- Ghidra: `FUN_00807550`
- Prior plate: `Net_Assigned_pending_ghost_I64d`
- Prior chain: `Named_CalleeOf_Client_CreateVehicleObjectApply_00807550` (**narrow**)

## Purpose

Resolve a pending-ghost map entry by the object's TFID (`object+0x160`) via dualed `StdMap_Find_Tfid_Isnil29_Inferred`. On hit with `payload+0x5c == 0`: log `"Assigned a pending ghost to %I64d"`, invoke object vtbl `+0x2b8` with the node payload (`node+0x20`), then erase the node via dualed `Map_EraseNode_B`.

## Signature

```c
// EAX = client/host (register); stack Object* object; RET 4
void Client_AssignPendingGhostByObjectTfid_Inferred(void* object);
```

## Layout (sealed)

| Offset | Role |
|---|---|
| host `+0xc78` | manager iface; vtbl `+0x48` → manager |
| manager `+0x244` | map shell (head at map `+4`) |
| object `+0x160` | TFID key (8 B) |
| node `+0x20` | payload pointer |
| payload `+0x5c` | assigned gate (must be 0) |
| object vtbl `+0x2b8` | assign pending ghost |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00807550_FUN_00807550.md`
- Annotated: `docs/reconstruction/raw/aa_00807550_FUN_00807550.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_AssignPendingGhostByObjectTfid_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00807550.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md`
- Scaffold alias: `docs/reconstruction/functions/aa_00807550_FUN_00807550.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Client_CreateVehicleObjectApply` @ `0x0081288f`, `0x008129e3`, `0x00812a17` | EAX=host before call |
| Caller | `FUN_0080af70` @ `0x0080b059` | EAX=host |
| Callee | `StdMap_Find_Tfid_Isnil29_Inferred` (`0x004cba00`) | dualed WQ9G-G |
| Callee | `Map_EraseNode_B` (`0x00409220`) | dualed WQ9E-G |
| Callee | `FUN_007a4480` | log |

## Confidence

| Claim | Level |
|---|---|
| Body + RET 4 + EAX host + map/key layout | **Confirmed** (bytes + disasm) |
| Find → assign → erase CF | **Confirmed** |
| Plate string pending ghost | **Confirmed** |
| Product host/manager/payload English | **Tentative** (`_Inferred`) |
| vtbl `+0x2b8` product name | **Open** |
