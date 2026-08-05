# Function record: Client_UseInventoryItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941d50` |
| **Canonical name** | `Client_UseInventoryItem_Inferred` |
| **Address** | `0x00941d50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` / `skills-abilities` |
| **Completion status** | **Dual A/B complete** — C2S **0x2045** packet sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Alias

- Ghidra: `FUN_00941d50`
- Prior scaffold: `Named_CalleeOf_Client_QuickBar_ActivateSlot_00941d50`
- QuickBar residual map: `Client_UseInventoryItem_Inferred`

## Purpose

Inventory item activation. Skill-bearing items (`cloneMeta+0x3f2 & 0x80`) emit **C2S InventoryUseItem `0x2045` size `0x28`**. Other items take equip/confirm path `FUN_00941b20`.

## Signature (register + stack)

```c
// ESI = client, EDI = item*
uint32_t Client_UseInventoryItem_Inferred(uint32_t mode /* typically 1 */);
```

## Sealed packet (skill-use arm)

| Off | Size | Field | Value / source |
|---|---|---|---|
| +0x00 | 4 | opcode | `0x2045` |
| +0x04 | 4 | pad | unwritten |
| +0x08 | 8 | coidItem | `item+0x160/+0x164` |
| +0x10 | 16 | fidTarget | `Client_Skill_ResolveCastTarget` out |
| +0x20 | 1 | ucSkillNumber | `0` |
| total | 0x28 | | `Client_SendSectorPacket` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.md`
- Annotated: `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UseInventoryItem_Inferred.cpp`
- Scaffold clean (legacy): `docs/reconstruction/reconstructed-exact/FUN_00941d50.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00941d50_Client_UseInventoryItem_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00941d50_Client_UseInventoryItem_Inferred.md`

## Callers / callees

| Direction | Addr | Name |
|---|---|---|
| Caller | `0x009436c0` | `Client_QuickBar_ActivateSlot` |
| Caller | `0x00941f50` | `FUN_00941f50` (COID→use) |
| Caller | `0x008be900` | `FUN_008be900` (UI event 0xe) |
| Callee | `0x00941b20` | equip/confirm arm |
| Callee | `0x00514390` | use/equip requirements |
| Callee | `0x0051a790` | `Skill_LocalCastValidate` |
| Callee | `0x0093b3a0` | `Client_Skill_ResolveCastTarget` |
| Callee | — | `TFID_EqualsObjectId`, `Client_SendSectorPacket` |

## Confidence

| Claim | Level |
|---|---|
| Opcode 0x2045 + size 0x28 | **Confirmed** |
| COID + target TFID + skill#=0 layout | **Confirmed / High** |
| Dual-arm equip vs use split | **High** |
| Product symbol | Tentative (`_Inferred`) |
| Runtime wire | Open |
