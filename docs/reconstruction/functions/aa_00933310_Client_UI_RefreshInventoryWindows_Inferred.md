# Function record: Client_UI_RefreshInventoryWindows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933310` |
| **Canonical name** | `Client_UI_RefreshInventoryWindows_Inferred` (**Inferred** role) |
| **Ghidra symbol** | `FUN_00933310` |
| **Address** | `0x00933310` |
| **Body** | `0x00933310`–`0x0093336f` inclusive (**96 B** / `0x60`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Agent** | MEGA-099 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |
| **Hash** | `a04b98d42bef5dfd0234a2fbaae83339f2d6cccd70eb691f4bd712d07fe98c30` |

## Rejected misname

`Named_CalleeOf_Client_RecvInventoryUseItemResponse_00933310` — xref-seed scaffold only; **5** call sites across inventory use/remove/tinker/gadget parents.

## Purpose

After inventory item mutations, pack **item/object*** (EAX) as uint map key with stack descriptor `(client, 1, 0, -1, -1)` + CL flag, then **insert-or-find** into **`client+0xF14`** via dualed isnil31 InsertOrFind (`0x00402b30`). Mechanism is map side-effect, not a direct inventory window walk. Shared map shell with `Client_NotifyActiveMissionChanged`.

## Signature

```c
// EAX = item/object*; CL = flag; stack client,a1,a2,a3,a4; void; RET 0x14
void Client_UI_RefreshInventoryWindows_Inferred(
    void *itemOrObject,
    uint8_t flag,
    void *client,
    int a1, int a2, int a3, int a4);
```

## Layout / constants

| Item | Value |
|---|---|
| Map shell | `client + 0xF14` |
| Key | uint32 = item/object* (value dword0) |
| Site constants | a1=1, a2=0, a3=a4=-1, CL=0 |
| Callee | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` |
| Cleanup | `RET 0x14` |

## Call graph

| Role | Target |
|---|---|
| **Callers (5)** | `Client_RecvInventoryUseItemResponse`; `FUN_00810170`; `FUN_0080d570` ×2; `FUN_0080d930` |
| Insert-or-find | `0x00402b30` (MEGA-040 dualed) |
| Often next | `Client_RefreshOpenMissionUiWindows` `0x0093a940` (parent, not callee) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00933310_FUN_00933310.md`
- Annotated: `docs/reconstruction/raw/aa_00933310_FUN_00933310.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_RefreshInventoryWindows_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00933310.cpp`
- Reviews: `A_aa_00933310_*` / `B_aa_00933310_*`
- FUN record: `aa_00933310_FUN_00933310.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / map offset | **High** |
| Inventory-mutation role | **High** |
| Product window English | **Tentative** (`_Inferred`) |
| Runtime | Open |
