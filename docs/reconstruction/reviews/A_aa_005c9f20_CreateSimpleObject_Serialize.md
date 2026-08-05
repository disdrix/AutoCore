# Review A (reconstruction fidelity): `aa_005c9f20` CreateSimpleObject_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c9f20` |
| **VA** | `0x005c9f20` |
| **Canonical name** | `CreateSimpleObject_Serialize` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c9f20_CreateSimpleObject_Serialize.md` |
| **System** | `networking` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pack **CreateSimpleObject** message **opcode 0x2012** (216 / **0xD8** bytes) from a SimpleObject-shaped `this` into `param_2` buffer. Null buffer → **0**. Wire map (server `CreateSimpleObjectPacket` byte-for-byte, opcode@0): CBID, COID defaults **-1**, HP/MaxHP, Value, Faction/TeamFaction, CustomValue, Prefixes[5]/Gadgets[5]/levels, Position, Rotation, Scale, Quantity, inv XY, IsCorpse, TFID, WillEquip/IsItemLink/IsInInventory, skill lvls, IsIdentified forced **1** client, kit/infinite/bound bits, UsesLeft, CustomizedName strcpy 17, MadeFromMemory, MaxGadgets, RequiredLevel/Combat, ItemTemplateId. Source base uses **this-relative** multi-inherit offsets (e.g. `-0xbc` vbase). Sets flag bit **|0x10** and calls `FUN_00512670`. Sibling Variant2 @ `0x005ca720` same layout, different source base.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c9f20_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c9f20_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CreateSimpleObject_Serialize.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c9f20_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode 0x2012 at buffer+0 | High | Clean first store |
| Packet size 0xD8 layout documented | High | Plate map |
| Null param_2 → 0 | High | Early out |
| COID default 0xFFFFFFFF pair | High | param_2[2]/[3] |
| IsIdentified forced 1 | High | Clean + plate |
| Name strcpy to +0xae | High | Loop |
| Flag |0x10 before FUN_00512670 | High | Clean |
| Full multi-inherit field map bit-exact | Medium | Large residual offsets |
| FUN_00512670 identity | Medium | Unnamed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| null→0; *buf=0x2012; field cascade; name copy | Yes |
| Does not invent Variant2 this-base | Yes |

---

## 5. Gaps / open

1. Seal every buffer dword against AutoCore CreateSimpleObjectPacket.
2. Document this-base (-0xbc) class layout vs Variant2 (-0x10c).
3. Bit-exact live pack capture deferred.

**Verdict:** **accept-with-gaps**
