# Annotated low-level: Skill_ApplyStatusEffectLocal (`aa_0051aa00`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051aa00` |
| **VA** | `0x0051aa00` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | skills-abilities |
| **Source raw** | `aa_0051aa00_Skill_ApplyStatusEffectLocal.md` (capture 2026-07-23) |
| **Related** | `Client_RecvSkillStatusEffect` (`0x00811170`), `CVOGReaction_CastSkillOnTarget` (`0x004d09a0`), `Skill_StartCastAgainHeartbeat` (`0x00519200`) |

This file is the **annotated** layer. It does not replace the immutable raw capture.

---

## 1. Signature (working hypothesis)

```c
// Decompiler: __fastcall with (pCasterObj, nInferred, pPacket, bIsLocalCaster)
// Real convention needs assembly; callers pass source object + 0x2031 buffer + local-match char.
int Skill_ApplyStatusEffectLocal(
    void* pCasterObj,      // resolved source object (packet source TFID)
    int   scratch,         // decompiler nInferred / register pollution — Probable unused
    void* pPacket,         // SkillStatusEffect workspace (0x2031 layout)
    char  bIsLocalCaster); // nonzero when local character matches source
// returns: 0 success path default; 0x11 cancel/supersede; 2 fail/debug
```

| Packet field (from topic + body) | Offset | Use here |
|---|---:|---|
| size | `+0x04` u16 | target count = `(size - 0x40) / 0x18` |
| skillId | `+0x08` | load skill / binding key |
| level | `+0x0C` i16 | rank reevaluate |
| lDelayTime | `+0x10` | `<1` immediate apply; else active-skill HB |
| position | `+0x18..` float3 | effect position stack copy |
| bIsItemSkill | `+0x38` | learned vs item/reaction skill path |
| extra / seed | `+0x3c` | optional rand on sim |
| first target TFID | `+0x40` | cancel compare vs active binding |

---

## 2. Decompiler corrections

| Artifact | Correction | Confidence |
|---|---|---|
| `this` typed as `CVOGHBBase*` for skill runtime | Skill object reused as HB-shaped cast; offsets use HB field names incorrectly for skill | **High** for mis-type |
| `nInferred` / `unaff_EDI` into SetRank / StartCastAgain | Register pollution; treat as unrecovered formals | **High** |
| Return `0x11` | Cancel / active-binding supersede path | **Probable** |
| Default `local_4f8 = 2` then `0` on skill found | Fail vs ok local status | **Probable** |
| `world+0x7e` | Server/sim flag (same as cast gate elsewhere) | **High** |
| Target strip: stride 0x18 → copy 16B TFID only into heap | Mana shorts dropped for local apply list | **High** |
| Item skill path: `operator_delete(this)` noreturn warning | Free of temp skill from ResolveSkillTargets — treat as normal free | **Probable** |
| `FUN_006061e0` | Active-skill heartbeat ctor (0x674 alloc) | **Probable** |
| `FUN_005538a0` | Immediate local effect apply | **Tentative** name |

---

## 3. Control flow (ordered)

```text
local_status = 2
if packet+0x38 == 0:   // learned / non-item skill
  skill = caster.vtbl+0x234(skillId)
  if null:
    Skill_EnsureLoadedInTree(...); reload
    if still null → debug stop, return 2
    Skill_SetRankAndReevaluate(skill, packet level, ...)
  else if skill rank sum != packet level:
    Skill_SetRankAndReevaluate(...)
else:  // item / reaction skill
  skill = CVOGReaction_ResolveSkillTargets(skillId, level...)

if skill == null → debug stop, return local_status

local_status = 0
extra = packet+0x3c
if world+0x7e (sim): maybe re-roll extra via RandomUnitScalar / FUN_0051b720

if non-item:
  LookupActiveCastBinding(skillId)
  if binding valid:
    local_status = 0x11
    resolve binding target; maybe FX cancel helper
    Skill_ClearCastBindingAndMaybeRestartCd(...)
    if client (world+0x7e==0): FUN_00514e00()
    if binding matches packet first target OR skill flag OR invalid packet target:
      return 0x11
  if sim:
    if !skill casting-skip flag: Skill_StartCastAgainHeartbeat(caster, skill, delay, ...)
    Skill_ClearActiveCastCounterAndQueueId(skillId)
else:  // item
  Skill_InsertCategoryCooldown(category, delay + skill period)

// Build compact TFID list from packet targets
n = (packet.size - 0x40) / 0x18
heap = new TFID[n]; copy each 16B from stride-0x18 slots

// Presentation hooks (vtbl+0x19c seat path or caster+0xac)
maybe FUN_004e2600 / FUN_00514ff0

if packet.lDelayTime < 1:
  FUN_005538a0(caster, world, heap, position, extra)   // apply now
  maybe decrement caster cast counter
else:
  if !bIsLocalCaster: caster.vtbl+0x238(3, skillId, level, delay, 0..)  // VFX cue
  new active-skill HB (0x674) via FUN_006061e0(...); enqueue; Start

delete heap
if non-item: return local_status
else: delete temp skill; // fallthrough
// fail:
VOG_DEBUG_STOP; return local_status
```

---

## 4. Side-effect order

1. Load/create skill runtime (tree load + rank reevaluate, or reaction resolve).
2. Possibly rewrite `packet+0x3c` on sim random path.
3. Non-item: active cast binding cancel/clear; optimistic CD HB on sim.
4. Item: category cooldown insert.
5. Heap-allocate compact TFID list from packet.
6. UI/FX helpers.
7. Immediate apply **or** delayed active-skill heartbeat.
8. Free list; return status; item path frees temp skill.

**Network:** none in this function (operates on already-received / local-built buffer).

---

## 5. Field map (touched)

| Offset | Object | Role |
|---|---|---|
| `packet+0x08` | skillId | lookup key |
| `packet+0x0c` | level i16 | rank |
| `packet+0x10` | lDelayTime | immediate vs delayed |
| `packet+0x18..0x20` | position | effect origin |
| `packet+0x38` | bIsItemSkill | path split |
| `packet+0x3c` | extra | sim rand / apply seed |
| `packet+0x40` | first target TFID | cancel compare |
| `caster+0xa4` | world | `+0x7e` sim; `+0xe4ec` HB list |
| `caster+0x160` | source TFID | cancel FX args |
| skill is-casting / category | skill runtime | CD HB / insert |

---

## 6. Call-site context

| Caller | VA | Notes |
|---|---|---|
| `Client_RecvSkillStatusEffect` | `0x00811170` | Success path after local-caster match |
| `CVOGReaction_CastSkillOnTarget` | `0x004d09a0` | After packing 0x2031; `bIsLocalCaster=0` |

---

## 7. Open questions

1. True calling convention (fastcall vs thiscall/stdcall).
2. Meaning of return `2` vs `0` vs `0x11` for Recv handler.
3. Identity of `FUN_005538a0` / `FUN_006061e0` / `FUN_00514e20` / `FUN_00514e00`.
4. Whether item-skill `operator_delete` is always taken (noreturn warning).
5. Exact skill rank sum fields (`this[9].nPeriodSentinel` style HB overlay).

---

## 8. Dual residual seal (2026-07-29)

Scratch: `reviews/a_0051aa00.md`. Closed: 0x2031 body field map; wire vs local `0x11`; `sizeof(CVOGHBBase)==0x28` overlay→skill offsets; `FUN_005538a0`→`Skill_ApplyEffectsOnTarget_Inferred`; `FUN_006061e0`→`CVOGHBWakeupSkill_ctor` (RTTI `.?AVCVOGHBWakeupSkill@@`). Open: runtime/diff; `+0x614` bit0 English; product names for `FUN_00514e00`/`FUN_00514e20`.
