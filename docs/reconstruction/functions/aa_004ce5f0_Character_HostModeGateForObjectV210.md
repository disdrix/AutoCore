# Function record: Character_HostModeGateForObjectV210

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ce5f0` |
| **Canonical name** | `Character_HostModeGateForObjectV210` |
| **Ghidra name** | `FUN_004ce5f0` |
| **Address** | `0x004ce5f0` |
| **Body range** | `0x004ce5f0`–`0x004ce632` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / equip / hardpoint gates |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + offsets sealed; flag/vfunc English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004ce5f0_Character_HostModeGateForObjectV210.md`, `reviews/B_aa_004ce5f0_Character_HostModeGateForObjectV210.md` |
| **Last reviewed** | `2026-07-29` (W19-F) |

## Alias

- `FUN_004ce5f0` (Ghidra)
- `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0` (auto parent-seed — **incomplete**; multi-caller)

## Purpose

Leaf **host-mode gate** for an **object**:

1. Null object → false.
2. MI-adjust object; call **vtbl+0x210(0)**; null → false.
3. Else true if `host+0xf5`, else `host+0x7e != 0`.

Used as equip precheck (vehicle type 0xe / type 0x10 helper), hardpoint drop, and confirm UI path. False often maps to equip status **1** in callers.

## Signature

```c
bool __thiscall Character_HostModeGateForObjectV210(int host, int object); // ret 4
```

## Algorithm

```
if (!object) return false;
r = object_MI.vcall_0x210(0);
if (!r) return false;
return host[+0xf5] || host[+0x7e];
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.md`
- Annotated: `docs/reconstruction/raw/aa_004ce5f0_FUN_004ce5f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Character_HostModeGateForObjectV210.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004ce5f0.cpp`
- Legacy alias plate: `reconstructed-exact/Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_004ce5f0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0059c000-004ce5f0-w19f-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (indirect vcall only) — **leaf** |
| **Callers** | `Character_TryEquipItem` `0x004fad1a`; `FUN_004f6890` `0x004f68b4`; `FUN_004f6a80` `0x004f6ea7`; `Client_SendInventoryDrop_Hardpoint` ×2; `FUN_00941b20` `0x00941b60` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + ret 4 | **High** (bytes `c2 04 00`) |
| MI adjust + vtbl+0x210(0) | **High** |
| Host flags `+0xf5` / `+0x7e` | **High** (offsets); English **Open** |
| Multi-caller gate (not confirm-only) | **High** |
| Product/PDB symbol | Open |
| Vfunc+0x210 product name | Open |

## Related

- `aa_004fabc0` Character_TryEquipItem (type 0xe uses this gate)
- `Client_SendInventoryDrop_Hardpoint`
