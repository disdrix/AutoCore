# Function record: Host_DualCNDHash_TraverseNextObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **Canonical name** | `Host_DualCNDHash_TraverseNextObject_Inferred` |
| **Ghidra name** | `FUN_004bae00` |
| **Address** | `0x004bae00`–`0x004bae63` inclusive (**100 B** / `0x64`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation (pick-list / SelectBestPick residual) |
| **Completion status** | **Dual A/B sealed** (MEGA-011 2026-08-05) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; not claimed Confirmed) |
| **Terminal** | **false** |

## Alias / superseded

- Scaffold: `FUN_004bae00`
- Retired: `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00` (wrong parent chain)

## Purpose

Single-step dual-CNDHash object enumerator on a host with two hash tables:

1. `listSelect == 0` → enable `host+0xd`, hash `host+0x8` (list B).
2. `listSelect != 0` → enable `host+0xc`, hash `host+0x4` (list A).
3. If enable and hash non-null: `CNDHash_TraversalLock_Set` → `TraverseToNext` (payload `node+0xc`) → clear `hash+0x1d`.
4. Return object* or NULL.

Primary dualed consumer: `Client_Interact_SelectBestPickTarget` — two passes flag **0 then 1** over host at `Client+0xBC`. Shared by world-object flush and other host sweeps (13 callers / 28 sites).

## Signature

```c
void* /* object* */ __thiscall Host_DualCNDHash_TraverseNextObject_Inferred(
    void* host /* ECX */,
    char listSelect,
    int* cursor);
// RET 8; EAX = object*|NULL
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX | **Confirmed** |
| listSelect | stack0 | **Confirmed** |
| cursor | stack1 | **Confirmed** |
| cleanup | RET 8 | **Confirmed** |

## Host layout (sealed)

| Off | Role |
|----:|------|
| `+0x4` | CNDHash* list A |
| `+0x8` | CNDHash* list B |
| `+0xc` | enable A |
| `+0xd` | enable B |

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `Client_Interact_SelectBestPickTarget` `0x00490070` | pick residual parent; ECX=`Client+0xBC` |
| Caller | `Client_FlushWorldObjectState_Inferred` `0x00943b80` | dual sweeps; ECX=`host+0xD34` |
| Caller | 11 other functions | session `+0xE4E8` family etc. |
| Callee | `CNDHash_TraversalLock_Set_Inferred` `0x00402c40` | dualed MEGA-110 |
| Callee | `FUN_004bc530` | TraverseToNext residual MEGA-029 |

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.md` |
| Annotated | `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_DualCNDHash_TraverseNextObject_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004bae00.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_004bae00_FUN_004bae00.md` |
| Report | `docs/agents/task-dual-ab-004bae00-mega-011-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF: dual select + lock/walk/unlock | **High** |
| ABI thiscall RET 8; ECX=host | **Confirmed** |
| SelectBestPick host = Client+0xBC | **High** |
| CNDHash family role via callees | **High** |
| Product host class English | **Open** (`_Inferred`) |
| Runtime Confirmed | **Open** |
