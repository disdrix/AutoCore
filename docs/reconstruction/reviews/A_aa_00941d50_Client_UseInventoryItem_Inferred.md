# Review A (reconstruction fidelity): `aa_00941d50` Client_UseInventoryItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941d50` |
| **VA** | `0x00941d50` |
| **Canonical name** | `Client_UseInventoryItem_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00941d50_Client_UseInventoryItem_Inferred.md` |
| **System** | `inventory-transfer` / `skills-abilities` |
| **Verdict** | **accept-with-gaps** (C2S **0x2045** packet **sealed**) |

---

## 1. Purpose

Client entry for inventory item activation. Register convention: **client in ESI**, **item object in EDI**, stack formal `param_1` (mode; callers pass `1`).

Two arms:

1. **Non-skill item** (`cloneMeta+0x3f2` bit `0x80` clear) → `FUN_00941b20(item, param_1, 1)` equip / permanent-customize confirm path (**no 0x2045**).
2. **Skill-bearing usable item** (bit `0x80` set) → local cast gates + **C2S InventoryUseItem `0x2045` size `0x28`**.

This dual seals the **0x2045** arm and packet layout.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.md` |
| Annotated | `docs/reconstruction/raw/aa_00941d50_FUN_00941d50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UseInventoryItem_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00941d50_Client_UseInventoryItem_Inferred.md` |
| Packet catalog | `Documentation/PACKET STRUCTURES.md` → `SMSG_Sector_InventoryUseItem` Size=`0x28` |
| Opcode enum | `src/AutoCore.Game/Constants/GameOpcode.cs` → `InventoryUseItem = 0x2045` |
| Related dual | `A/B_aa_009436c0_Client_QuickBar_ActivateSlot` (type-2 caller) |
| Related dual | `A/B_aa_0093b3a0_Client_Skill_ResolveCastTarget` |
| Related dual | `A/B_aa_00810280_Client_RecvInventoryUseItemResponse` (S2C **0x2046**) |
| Live Ghidra | `decompile_function` `0x00941d50`, callees `0x00941b20` / `0x00941f50` / `0x008be900`, `read_memory` invalid TFID `0x00a15870` + `DAT_00d1a630` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| C2S opcode **`0x2045`** hardcoded at packet `+0` | **Confirmed** | `auStack_2c[0] = 0x2045` |
| Send size **`0x28`** via `Client_SendSectorPacket` | **Confirmed** | literal size arg |
| `coidItem` @ `+0x08/+0x0c` from `item+0x160/+0x164` | **Confirmed** | `EDI[0x58]/[0x59]`; same COID plate as AddItem/Grab duals |
| `fidTarget` @ `+0x10` = 16B from `Client_Skill_ResolveCastTarget` return | **Confirmed** | 4 dwords copied into `uStack_1c..uStack_10` |
| `ucSkillNumber` @ `+0x20` written **0** | **Confirmed** | `uStack_c = 0`; skill looked up from item for gates only |
| Packet `+0x04` pad unwritten by this builder | **High** | never assigned; matches other C2S builders (e.g. 0x2030) |
| Catalog layout ≡ builder (PACKET STRUCTURES `InventoryUseItem`) | **Confirmed** | Size 0x28; coid@8; TFID@0x10; skill#@0x20 |
| S2C pair **0x2046** UseItem response | **High** | GameOpcode + Recv dual `aa_00810280` |
| Gate: broken bit clear (`item+0x17c` bit 19) | **High** | `EDI[0x5f]>>0x13&1==0`; sealed **Broken** elsewhere |
| Gate: clone type `+0x38 != 0xe` | **High** | blocks type-0xe (weapon-class meta) |
| Branch: `cloneMeta+0x3f2 & 0x80` → skill-use arm | **High** | else equip arm `FUN_00941b20` |
| Skill object via item vtbl `+0x234(cloneMeta+0x3bc)` | **High** | null → no send |
| `Skill_LocalCastValidate` must return 0 | **High** | same cast pipeline as RequestCastSkill |
| Invalid TFID → abort send | **High** | `TFID_EqualsObjectId` vs `g_abTfidInvalid_A15870` (`ffffffff ffffffff 0 0`) |
| Client ESI / item EDI | **High** | unaff_* + all three callers |
| `param_1` unused on 0x2045 arm; forwarded to equip arm | **High** | body |
| Aim/context arg = `&DAT_00d1a630` (static zeros) | **High** | `read_memory` 16B zero BSS/data |
| Sole builder of **0x2045** in client image (this unit) | **High** | only hardcoded `0x2045` site under reconstruction tree |

---

## 4. Sealed C2S packet: InventoryUseItem

```
C2S  opcode = 0x2045  (GameOpcode.InventoryUseItem)
size = 0x28
send = Client_SendSectorPacket(client, 0x28, buf)

Offset  Size  Field              Source in aa_00941d50
------  ----  -----------------  ------------------------------------------
+0x00   4     opcode             constant 0x2045
+0x04   4     pad                not written (ignore on parse)
+0x08   8     coidItem           item+0x160 (lo), item+0x164 (hi)
+0x10  16     fidTarget          ResolveCastTarget out TFID (4×u32)
+0x20   1     ucSkillNumber      constant 0 in this builder
+0x21   7     pad to 0x28        not written
```

Catalog twin (`Documentation/PACKET STRUCTURES.md`):

```cpp
struct SMSG_Sector_InventoryUseItem : public SMSG_Sector_Base // Size=0x28
{
    int coidItem;                 // +0x8  Size=0x8
    struct TFID fidTarget;        // +0x10 Size=0x10
    unsigned int ucSkillNumber;   // +0x20 Size=0x1
};
```

Direction note: catalog uses `SMSG_` prefix historically; **this function is C2S** (client builds + `Client_SendSectorPacket`). S2C answer is **0x2046** `InventoryUseItemResponse` (size 0x18 catalog).

---

## 5. Control flow (0x2045 arm)

```
gates:
  client+0xe98 (char) != 0
  char+0x250 (vehicle/entity host) != 0
  item (EDI) != 0
  !(item+0x17c bit19 Broken)
  type(item+0xa8 +0x38) != 0xe
  cloneMeta = *(item+0xa8 +0x3c);  (cloneMeta+0x3f2 & 0x80) != 0
  *(client+0xe04 + 0xf6) == 0          // world/sim gate
  FUN_00514390(item thiscall, char, 1)  // equip/use reqs (level/tech/race…)
  pSkill = item->vtbl[+0x234](*(cloneMeta+0x3bc))
  pSkill != 0
  Skill_LocalCastValidate(entity, 1, pSkill, 0) == 0
  ResolveCastTarget(out, pSkill, seed, &DAT_00d1a630, report=1)
  !TFID_EqualsObjectId(validated, g_abTfidInvalid_A15870)

then:
  pack 0x2045 size 0x28; send; return 1
else:
  return 0
```

Equip arm (bit `0x80` clear): early return of `FUN_00941b20` — town-only type-0xe toast, inventory-space gates, permanent-customize confirm UI (`client+0x3bf8/0x3bfc`), then `FUN_00931440(param_1)`. **Out of 0x2045 seal scope.**

---

## 6. Callers

| Addr | Name | Role |
|---|---|---|
| `0x009436c0` | `Client_QuickBar_ActivateSlot` | type-2 cargo use → `FUN_00941d50(1)` |
| `0x00941f50` | `FUN_00941f50` | resolve item by COID pair via `FUN_00571010`, then use with `param_3` |
| `0x008be900` | `FUN_008be900` | UI event `param_2==0xe` in id window `0x9c43..0x9c46`; on fail → `Client_SendUseObject_IfInteractable` |

---

## 7. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Outer char/vehicle/item/broken/type gates | **Yes** |
| `+0x3f2&0x80` equip vs skill-use split | **Yes** |
| Req check + skill resolve + LocalCastValidate | **Yes** |
| ResolveCastTarget + invalid abort | **Yes** |
| Packet pack + SendSectorPacket 0x28 | **Yes** |
| No invented fields beyond decomp | **Yes** |

---

## 8. Gaps / open

1. Product symbol for `Client_UseInventoryItem` (still `_Inferred`); equip sibling `FUN_00941b20` product name.
2. ResolveCastTarget seed formal vs `local_3c` / `stack0xffffffb4` slot naming — decomp noise; **out TFID → packet is sealed**.
3. Meaning of `ucSkillNumber` when non-zero (this builder always 0; server may derive skill from item COID/CBID).
4. `cloneMeta+0x3bc` skill-id/ref type (passed to vtbl+0x234).
5. Full semantic of `FUN_00514390` req matrix (level/tech/race/status 0x26) — partial only.
6. Runtime / live capture of 0x2045 wire bytes; bit-for-bit open.
7. AutoCore server handler for C2S `InventoryUseItem` not present (opcode enum only).

**Verdict:** Opcode + size + field map **sealed High/Confirmed**. Dual-purpose equip arm documented but not packet-sealed. **accept-with-gaps.**
