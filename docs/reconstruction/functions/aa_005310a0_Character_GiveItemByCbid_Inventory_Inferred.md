# Function record: Character_GiveItemByCbid_Inventory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005310a0` |
| **Canonical name** | `Character_GiveItemByCbid_Inventory_Inferred` (**Inferred** — class English open) |
| **Ghidra name** | `FUN_005310a0` |
| **Prior scaffold** | `FUN_005310a0` / `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0` (**retired**) |
| **Address** | `0x005310a0`–`0x00531247` inclusive (**424 B** / `0x1A8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / inventory-transfer |
| **Agent** | MEGA-003 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Grant **`count`** items of catalog id **`cbid`** into the character inventory:

1. Resolve dual-base character (`+0xa8`); if readiness `*(char*)(char+0x7e)==0`, return **true** (no grant).
2. Loop `remaining = count` … `remaining--`:
   - `CVOGReaction_GiveItemByCbid(cbid, 0)` factory; null → log `"Invalid CBID: %d (bad item)"` → **false**.
   - Init item (`vtbl+8`), stamp 64-bit serial from `char+0xe6e0` via `FUN_00512160`.
   - Reset transform identity (`g_flOne` @ `0x00a0f2a0`); owner hooks `vtbl+0x2a4` / `+0x218`.
   - First unit: `FUN_00513e70` may collapse multi-grant to 1 (bind/trade-lock style gate).
   - `Client_SendInventoryAddItem(this, item, flag)`.
3. Return **true**.

```text
parents (UseItem / craft / outpost / objective)
  └─ Character_GiveItemByCbid_Inventory_Inferred  [OWN MEGA-003]
        ├─ CVOGReaction_GiveItemByCbid     (factory; dualed)
        ├─ FUN_00512160                    (serial stamp)
        ├─ FUN_00513e70                    (bind/lock gate)
        └─ Client_SendInventoryAddItem     (packet / bag path)
```

## Signature

```c
// __thiscall: ECX = character dual-base this; stack cbid, count; RET 8; AL bool
uint8_t __thiscall Character_GiveItemByCbid_Inventory_Inferred(
    void *this_char,
    int cbid,
    int count);
```

## Layout / constants

| Offset / VA | Meaning |
|---|---|
| this dual-base `+0xa8` | character\* |
| char `+0x7e` | readiness gate (0 → early success) |
| char `+0xe6e0` / `+0xe6e4` | 64-bit item instance counter |
| char `+0xe4e8` | owner field passed to `vtbl+0x2a4` |
| string `0x009cfea4` | `"Invalid CBID: %d (bad item)"` |
| float `0x00a0f2a0` | `g_flOne` = 1.0f |

## Call graph

| Role | Target |
|---|---|
| **Callers (6 / 8 sites)** | `CVOGObjectiveRequirement_UseItem_InitActive` `0x0060d540`; `FUN_0060d630`; `FUN_00531570`; `FUN_005316c0`; `FUN_00607a00`; `FUN_00610e60` |
| Callees | `CVOGReaction_GiveItemByCbid` `0x0051a170`; `FUN_00512160`; `FUN_00513e70`; `Client_SendInventoryAddItem` `0x00530df0`; `FUN_007a4480` |
| Peer factory | dualed `CVOGReaction_GiveItemByCbid` — **no** bag insert |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Character_GiveItemByCbid_Inventory_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005310a0.cpp`
- Raw: `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.md`
- Annotated: `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_005310a0_FUN_005310a0.md`
- Report: `docs/agents/task-dual-ab-005310a0-mega-003-report.md`

## Confidence

| Claim | Level |
|---|---|
| Grant-by-cbid + inventory insert CF | **Confirmed** (assembly) |
| thiscall + RET 8; cbid+count; AL bool | **Confirmed** |
| Caller / callee set | **Confirmed** |
| Character class product English | **Inferred** |
| Vtbl / bind-gate English | Tentative |
| Runtime Confirmed | **Open** |
