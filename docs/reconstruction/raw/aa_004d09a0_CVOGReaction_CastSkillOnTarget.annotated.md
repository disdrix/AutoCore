# Annotated low-level: CVOGReaction_CastSkillOnTarget (`aa_004d09a0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **VA** | `0x004d09a0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` (capture 2026-07-23) |
| **Related** | S2C `SkillStatusEffect` opcode `0x2031`; `Skill_ApplyStatusEffectLocal` (`0x0051aa00`); `Client_RecvSkillStatusEffect` (`0x00811170`) |

This file is the **annotated** layer for the local/reaction packer that builds a `0x2031` buffer and optionally applies it locally.

---

## 1. Corrected signature (semantic)

```c
// MSVC thiscall — `this` / param_1 is world/sim context with +0x7e mode flag
undefined4 __thiscall CVOGReaction_CastSkillOnTarget(
    WorldContext*   this,          // param_1 — requires this+0x7e != 0
    SkillRuntime*   pSkill,        // param_2 — skill runtime (null aborts)
    ObjectEntity*   pSource,       // param_3 — source object (TFID @ +0x160)
    ObjectEntity*   pTargetHint,   // param_4 — may be remapped via seat vtbl+0x19c
    char            bInvertItem,   // param_5 — drives packet+0x38 item flag polarity
    TFID_16*        pTargetList,   // param_6 — null → allocate & Skill_ResolveTargetList
    float*          pAimPos,       // param_7 — 3×f32 aim / effect position
    char            bHasItemId,    // param_8 — if set, write param_9 into packet
    undefined4      itemOrExtra,   // param_9
    char            bStatusC,      // param_10 — if set, status byte = 'c' (0x63)
    int             chargeSpent);  // param_11 — subtracted from skill+0x14 → lDelayTime
```

Parameter names beyond plate evidence are **Probable**; widths and roles below are from the packer body (**High**).

---

## 2. Early abort

```text
if (this+0x7e == 0 || pSkill == NULL || pSource == NULL)
    return 0;
```

`this+0x7e` is the same “server/sim mode” style flag used by cast paths (`world+0x7e`): packing only runs when the flag is **non-zero** (local apply / reaction context). **High** (same offset family as RequestCastSkill’s skip-HB test, inverted sense).

---

## 3. Target-hint remapping

When `pTargetHint != NULL` and its linked type at `pTargetHint[0x2a]+0x38` is in `{0x0E, 0x12, 0x14, 0x03}`:

```text
seat = pTargetHint->vtbl[0x19c/4]()
if seat == 0: pTargetHint = NULL
else:         pTargetHint = seat + *(seat+4)+4 + 4   // entity interior base
```

Object types **Probable** (vehicle/seat/character class ids). Used later as origin for `Skill_ResolveTargetList` when no explicit TFID list is supplied.

---

## 4. Packet allocation and header (`0x2031`)

```text
pPacket = operator_new(0x9A0)   // large scratch; logical size written later
*pPacket = 0x2031               // dword opcode at +0x00
```

| Packet offset | Write | Source | Notes |
|---|---|---|---|
| `+0x00` | u32 `0x2031` | constant | SkillStatusEffect |
| `+0x04` | u16 size | `nTargets*0x18 + 0x58` | **VERIFIED** formula (plate) |
| `+0x08` | u32 skillId | `pSkill+0x5FC` | |
| `+0x0C` | i16 level | `(pSkill+0x5F6) + (pSkill+0x174)` | rank + bonus |
| `+0x10` | i32 lDelayTime | `max(0, (i16)(pSkill+0x14) - chargeSpent)` | remaining charge, **not** cooldown |
| `+0x14` | u8 status | `0` or `'c'`(0x63) | `-(bStatusC!=0) & 99` |
| `+0x18..+0x20` | 3×f32 | `*pAimPos` | effect / aim position |
| `+0x28` | TFID_16 | `pSource+0x160` (4 dwords) | **source owner** — must be character TFID for player cast identity |
| `+0x38` | bool/byte | `bInvertItem == 0` | `bIsItemSkill` polarity (`param_5 == 0` → true) |
| `+0x3C` | optional | `itemOrExtra` if `bHasItemId` | |
| `+0x40` … | targets | 0x18 each | TFID + i16 mana + i16 maxMana + pad |
| term | TFID invalid | `DAT_009cbf68..74` | full 24-byte slot with zero shorts |

**Size formula (Confirmed):**

```text
nInferred = nTargets * 3
size_u16  = (short)nInferred * 8 + 0x58
// ≡ nTargets * 0x18 + 0x58
// base 0x58 = 0x40 (header through first target) + 0x18 terminator slot
// nTargets = pre-terminator walk count; Apply uses (size-0x40)/0x18 → n+1
```

**Cursor math (Confirmed 2026-07-29):** write cursor starts at `pPacket+0x14` dwords (= byte **+0x50**, mana shorts of first target); first TFID is written at `cursor[-4]` (= byte **+0x40**). Do not treat +0x50 as TFID base.

---

## 5. Target list fill loop

```text
if pTargetList == NULL:
    allocate 0x640 TFID buffer
    Skill_ResolveTargetList(..., out flags local_8)
    map local_8 bits → status codes 0xD / 0xE (13 range / 14 target)  // Probable
    bOwnedList = true

cursor = pPacket + 0x14 dwords  // mana/short write head of first target (@+0x50)
for each TFID until invalid sentinel:
    obj = Object_ResolveFromTFID(tfid)
    write 16B TFID into slot (cursor[-4] … → first @ +0x40)
    if obj:
        combat = obj->vtbl+0x214()
        if combat: write i16 mana @ combat+0x12C, max @ combat+0x12E
    advance cursor by 6 dwords (0x18)
write terminator TFID at end
if bOwnedList: operator_delete__(list)
```

Target entry layout **Confirmed** from topic extraction + packer + Apply consumer: `{ TFID_16, i16 curMana, i16 maxMana, pad }` at **+0x40** stride **0x18**.

Resolve out-flags map to local codes **0xD / 0xE** only; **not** written into `packet+0x14` (status remains 0/`'c'` from `bStatusC`). Function always returns **0**.

---

## 6. Local apply + cleanup

```text
if (has_any_target OR skill+0x614==1 OR (skill+0x624&1 && source world type==0x12))
   AND bHasItemId==0:
    local_8 = Skill_ApplyStatusEffectLocal(pSource, ..., pPacket, 0)

operator_delete(pPacket)   // decompiler: "does not return" — SEH/allocator quirk; treat as free+return
return 0
```

Side effects: heap alloc/free; optional local status-effect apply (VFX/heartbeat).

**No network send in this unit (Confirmed 2026-07-29):** callees are only `Object_ResolveFromTFID`, `Skill_ResolveTargetList`, `Skill_ApplyStatusEffectLocal`, and heap ops. Wire delivery of `0x2031` (if any) is outside this function; S2C consumer sibling is `Client_RecvSkillStatusEffect` @ `0x00811170`.

Named callers (sample): `NPC_TryCastSkillFromSet`, `Outpost_CastSkillsForFaction` / `Outpost_CastSkillsForBeaconShare`, `Skill_CVOGHBSkill_Summon`, `FUN_004d1b80` (+ bulk FUN_*).

---

## 7. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `-(param_10 != 0) & 99` | status = **`'c'` (0x63)** when flag set, else 0 | **Confirmed** |
| `pPacket + 0xe` as bool | byte at **offset 0x38** (`0xe * 4`) | **Confirmed** |
| `param_11` reuse as remaining charge | remaining = skill charge (`+0x14`) − spent; clamp ≥ 0 | **High** |
| `operator_delete` noreturn warning | Allocator/EH artifact; function returns 0 on skip path | **High** |
| Source TFID from `param_3+0x160` | character/root object TFID for player casts (see topic) | **High** |

---

## 8. Open questions

- Full retail parameter order vs reaction VM push order (`NPC_TryCastSkillFromSet` `0x005D1280` path).
- Exact meaning of status `'c'` vs numeric `eSkillResponses` on success path.
- Whether `0x9A0` alloc is fixed max targets (capacity) only.
- Which unit (if any) serializes this packed buffer as sector S2C `0x2031`.

## 9. Dual residual (2026-07-29)

- A/B: `reviews/A_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md`, `reviews/B_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md`
- Chain: `reviews/CHAIN_2026-07-29_castskillontarget_0x2031_packer.md`
- Scratch: `tmp/a_004d09a0.md`
