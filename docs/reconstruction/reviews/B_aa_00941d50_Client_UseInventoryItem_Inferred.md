# Review B (skeptical / adversarial): `Client_UseInventoryItem_Inferred` @ `0x00941d50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941d50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00941d50_Client_UseInventoryItem_Inferred.md` |
| **Verdict** | **accept-with-gaps** — **0x2045 packet holds**; name oversell risk on equip arm |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | Function is only "use item" | **Overstated** — half the CF is equip / customize confirm via `FUN_00941b20` (toasts: town-only, no inventory space, permanent customize) | **Stands as dual-arm.** Prefer name *UseOrEquipInventoryItem* product-unknown; keep `_Inferred` Use for 0x2045 arm |
| 2 | Packet is S2C because catalog says `SMSG_` | **False friend** — builder calls `Client_SendSectorPacket`; direction is **C2S**. Catalog prefix is historical | **Retracted S2C.** C2S sealed |
| 3 | `coidItem` is full 16B TFID | **False** — only 8B from `item+0x160/+0x164`; catalog Size=0x8 matches; full TFID is **target** @+0x10 | **Sealed as 8B COID** |
| 4 | `ucSkillNumber` carries the cast skill id | **False for this builder** — constant 0; skill object used only for LocalCastValidate / ResolveCastTarget | **Hold 0.** Server must not require non-zero skill# from this client path |
| 5 | Every inventory use emits 0x2045 | **False** — bit `0x80` clear → equip arm, no sector use packet | **Stands** |
| 6 | Type `0xe` block means "weapons never use" | **Local gate only** — type code at `*(item+0xa8)+0x38`; equip arm specially messages type 0xe "only changed in town" | **Hold as type-0xe exclusion on use arm** |
| 7 | Seed TFID formal order is identical to RequestCastSkill plate | **Fragile** — decomp shows `local_3c` pre-seed and invalid-check on `stack0xffffffb4` | **Do not over-seal seed homes.** Out TFID → packet **holds** |
| 8 | `DAT_00d1a630` is live aim vector | **Static zeros** at image (`read_memory` 16B 0) — zero aim/context placeholder | **Hold as zero aim** |
| 9 | Opcode might be wrong / share 0x2030 cast | **Falsified** — literal `0x2045`; cast skill is separate `0x2030` size 0x28 with skillId@+0x18 | **Sealed distinct** |

---

## 2. Surviving contract for AutoCore

```
// C2S InventoryUseItem — SEALED
struct InventoryUseItemC2S {          // size 0x28
    uint32 opcode;                    // +0x00 = 0x2045
    uint32 pad;                       // +0x04 ignored
    int64  coidItem;                  // +0x08 item instance COID (lo/hi u32)
    TFID   fidTarget;                 // +0x10 16 bytes
    uint8  ucSkillNumber;             // +0x20 client sends 0 on this path
    // +0x21..0x27 pad
};

// Client emit path (skill-use arm only):
if item has cloneMeta+0x3f2 bit0x80:
  validate reqs + LocalCastValidate(item skill)
  fidTarget = ResolveCastTarget(...)
  if fidTarget valid: send 0x2045
else:
  equip/confirm path (not this opcode)
```

Server parity notes:

- Authority: server must re-validate ownership of `coidItem`, range/LOS on `fidTarget`, and that the item grants a usable skill / consumable effect.
- Do **not** require `ucSkillNumber != 0` for parity with this retail client builder.
- Response path is **0x2046** (`InventoryUseItemResponse`, catalog size 0x18: coid, qty, charges, success) — dual-reviewed at `aa_00810280`.
- Equip/customize confirm is a **different** net path (`FUN_00931440` family); do not fold into UseItem.

---

## 3. Skeptical hits on residual "seals"

| Seal | Challenge | Hold? |
|---|---|---|
| Opcode 0x2045 | Could be mistyped 0x2046 pair | **Hold** — send site hardcodes 0x2045; enum + catalog pair cleanly |
| Size 0x28 | Could include header outside buffer | **Hold** — same `Client_SendSectorPacket(client, size, buf)` pattern as 0x2030 |
| COID @+8 | Could be grid XY (historical AddItem false friend) | **Hold** — explicit `item+0x160/164`; AddItem dual already corrected this class of error |
| Target TFID @+0x10 | Could be aim float3 (0x2030 layout) | **Hold** — 4 dwords from ResolveCastTarget return, not aim; aim global is zero |
| Skill# = 0 always | Other unknown builders? | **Hold for this function**; grep of reconstruction tree shows only this `0x2045` site |
| Broken bit gate | Meaning | **Hold as Broken** (sealed at `a_005711c0`) |

---

## 4. What would falsify the seal

1. Live capture of retail 0x2045 with non-zero `ucSkillNumber` or different field order.
2. Second client builder writing 0x2045 with alternate layout.
3. Server binary parser proving `+0x08` is 16B TFID (would contradict both catalog Size=0x8 and this builder).

None observed in static dual.

---

## 5. Open questions

1. Product name / RTTI for this function and `FUN_00941b20`.
2. Whether server ignores `ucSkillNumber` entirely and binds skill from item CBID/`cloneMeta+0x3bc`.
3. UI path `FUN_008be900` event 0xe — which widgets set EDI item before call.
4. Interaction with mission UseItem objective progress (server-side; out of unit).
5. Runtime wire capture.

**Verdict:** Adversarial review **does not break** opcode/size/COID/target/skill# layout. Name is dual-arm; packet seal stands. **accept-with-gaps.**
