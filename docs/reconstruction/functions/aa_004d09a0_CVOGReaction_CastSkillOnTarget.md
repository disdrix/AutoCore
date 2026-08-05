# Function record: CVOGReaction_CastSkillOnTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **Canonical name** | `CVOGReaction_CastSkillOnTarget` |
| **Address** | `0x004d09a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (this = world/context) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined clean** — 0x2031 packer fields verified; **no-wire-in-unit Confirmed** (2026-07-29 dual residual); runtime open |

---

## 1. Summary

Packs **SkillStatusEffect 0x2031** buffer from skill/source/target list, optionally resolves targets when list is null, writes terminator TFID, may call `Skill_ApplyStatusEffectLocal`, frees packet. Entry requires `this+0x7e != 0` (server/sim-ish) and non-null skill/source.

**Does not** send the buffer on the network (callee set: resolve / local apply / heap only).

---

## 2. Signature

```c
uint32_t __thiscall CVOGReaction_CastSkillOnTarget(
    int thisWorld,
    int pSkill,
    void* pSource,
    int* pTargetObj,
    char bNotItemSkill,
    TFID_16* pTargetList,   // null → allocate + Skill_ResolveTargetList
    uint32_t* pAimPos,      // float3
    char bHasExtra,
    uint32_t extraVal,
    char bStatusC,          // status 'c' (99) when nonzero
    int chargeConsumed);    // subtracted from skill+0x14 → lDelayTime
```

Always returns **0**.

---

## 3. Packet 0x2031 (VERIFIED from packer body + Apply consumer)

| Off | Field | Source |
|---:|---|---|
| +0x00 | msgId `0x2031` | const |
| +0x04 | size u16 | `nTargets*0x18 + 0x58` (base includes terminator slot) |
| +0x08 | skillId | `skill+0x5FC` |
| +0x0C | level | `skill+0x5f6 + skill+0x174` |
| +0x10 | remaining charge / lDelayTime | `skill+0x14 - chargeConsumed`, clamp ≥0 |
| +0x14 | status | 0 or `'c'` (99) from **bStatusC only** |
| +0x18 | position float3 | `pAimPos` |
| +0x28 | source TFID | `pSource+0x160` |
| +0x38 | item flag | `bNotItemSkill == 0` |
| +0x3C | optional extra | if `bHasExtra` |
| +0x40… | targets stride 0x18 | `{TFID16, s16 mana, s16 maxMana, pad}` |
| end | terminator TFID | `DAT_009cbf68..` |

Size: `nTargets` is pre-terminator walk count; base `0x58` = `0x40` header-to-targets + one terminator slot. Apply uses `(size-0x40)/0x18` → counts **n+1**.

---

## 4. Behavior outline

1. Gate `this+0x7e`, skill, source
2. Optional target-object rewrite for world types `0xe/0x12/0x14/3` via `vtbl+0x19c`
3. `operator_new(0x9a0)`; fill header fields
4. If no target list: `operator_new__(0x640)` + `Skill_ResolveTargetList`; map flags → local 0xd/0xe-ish (**not** written to packet status; return still 0)
5. Walk TFIDs; resolve objects; pack mana from `vtbl+0x214` plant
6. Terminator + size; maybe `Skill_ApplyStatusEffectLocal` if `!bHasExtra` and (targets present or skill flags)
7. `operator_delete(packet)`; return 0

---

## 5. Callees / callers (2026-07-29)

**Callees:** `Object_ResolveFromTFID`, `Skill_ResolveTargetList`, `Skill_ApplyStatusEffectLocal`, heap ops.

**Named callers (sample):** `NPC_TryCastSkillFromSet` `0x005d1280`, `Outpost_CastSkillsForFaction` `0x00606d70`, `Outpost_CastSkillsForBeaconShare` `0x006070e0`, `Skill_CVOGHBSkill_Summon` `0x00521650`, `FUN_004d1b80` (+ bulk FUN_*).

---

## 6. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.*` |
| Clean | `reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` |
| Dual A/B | `reviews/A_aa_004d09a0_*.md`, `reviews/B_aa_004d09a0_*.md` |
| Chain | `reviews/CHAIN_2026-07-29_castskillontarget_0x2031_packer.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| S2C handler | `Client_RecvSkillStatusEffect` @ `0x00811170` |
| Scratch | `tmp/a_004d09a0.md` |

---

## 7. Confidence

| Dimension | Level |
|---|---|
| Size formula / field sources | **High / VERIFIED** (plate + body + Apply) |
| Control flow | High |
| No network send in unit | **High / Confirmed** (callees 2026-07-29) |
| `operator_delete` “no return” decomp warning | Ignore — normal free |
| Overall | **Human-refined; dual residual sealed; runtime open** |

---

## 8. Open questions

1. Full consumer set of packed buffer on **wire** (which unit emits S2C 0x2031 for NPC/reaction).
2. Exact type of `thisWorld` / `+0x7e` flag English.
3. Runtime multi-target observation / bit-exact.
