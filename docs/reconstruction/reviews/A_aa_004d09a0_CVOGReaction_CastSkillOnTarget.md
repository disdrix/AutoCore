# Review A (reconstruction fidelity): `aa_004d09a0` CVOGReaction_CastSkillOnTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d09a0` |
| **VA** | `0x004d09a0` |
| **Canonical name** | `CVOGReaction_CastSkillOnTarget` |
| **Review date** | `2026-07-23` (residual dual strengthen `2026-07-29`) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Reaction / NPC / outpost path that **packs SkillStatusEffect `0x2031`** from skill + source + targets, optionally resolves a target list, may call `Skill_ApplyStatusEffectLocal`, then frees the packet.

Entry: `this+0x7e != 0` && skill && source.

Packet (VERIFIED from packer body + Apply consumer):

| Off | Field |
|---:|---|
| +0x00 | `0x2031` |
| +0x04 | size u16 = `nTargets*0x18 + 0x58` (base includes terminator slot) |
| +0x08 | skillId `skill+0x5FC` |
| +0x0C | level `skill+0x5f6 + skill+0x174` |
| +0x10 | remaining charge / lDelayTime `skill+0x14 - consumed` clamp ≥0 |
| +0x14 | status 0 or `'c'` (99) from **param_10 only** |
| +0x18 | aim float3 |
| +0x28 | source TFID `source+0x160` |
| +0x38 | item flag (`bNotItemSkill == 0`) |
| +0x3C | optional extra when `bHasExtra` |
| +0x40… | targets stride 0x18 + terminator TFID |

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` |
| Annotated | `docs/reconstruction/raw/aa_004d09a0_CVOGReaction_CastSkillOnTarget.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` |
| Prior dual | `aa_004d09a0_reconstruction_review.md` / skeptical sibling |
| Function record | `docs/reconstruction/functions/aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| System map | `docs/reconstruction/systems/skills-abilities.md` |
| S2C sibling | `Client_RecvSkillStatusEffect` `0x00811170` / chain `CHAIN_2026-07-29_s2c_2031_skillstatuseffect.md` |
| Local apply | `Skill_ApplyStatusEffectLocal` `0x0051aa00` |
| Ghidra (2026-07-29) | `decompile_function`, `get_function_callees`, `get_function_callers`, `get_function_xrefs` |
| Seal chain | `reviews/CHAIN_2026-07-29_castskillontarget_0x2031_packer.md` |
| Scratch | `tmp/a_004d09a0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate `+0x7e` / skill / source | **High** | Raw body |
| Opcode `0x2031` + size formula | **High / VERIFIED** | Plate + stores; Apply uses `(size-0x40)/0x18` |
| Size base `0x58` includes terminator slot | **High / Confirmed** | `0x40` header + `0x18` term; nTargets excludes term write |
| Field sources skill/source/aim | **High** | Body |
| Targets TFID base **+0x40** (mana shorts @ +0x50 of first slot) | **High / Confirmed** | cursor `pPacket+0x14` dwords; Apply walks `packet+0x40` |
| Null list → `Skill_ResolveTargetList` + flag map | **High** CF | Codes 0xd/0xe family into **local only** |
| Mapped resolve codes written into packet status | **Falsified** | status only from param_10; local_8 never stored to +0x14 |
| Target rewrite types 0xe/0x12/0x14/3 via vtbl+0x19c | **High** | CF |
| Mana shorts from plant vtbl+0x214 → +0x12c/+0x12e | **High** | When resolve ok |
| Optional ApplyStatusEffectLocal when targets/flags and `!bHasExtra` | **High** | End of body |
| **Network send inside this unit** | **High / Confirmed no** | Callees: resolve/apply/heap only (2026-07-29) |
| Named callers NPC / Outpost / Summon | **High** | xrefs + decomp call sites |
| `this` type (world/sim) English name | **Probable** | +0x7e family; non-zero enables pack |
| Function return value | **High** | always `0` (even after resolve flag map) |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Entry gate | **Yes** |
| Target-object remap | **Yes** |
| Alloc 0x9a0 + header fill | **Yes** |
| Optional ResolveTargetList | **Yes** |
| TFID walk + terminator | **Yes** |
| Free owned list / packet | **Yes** |
| No invented fields | **Yes** (human-refined clean) |
| No invented wire send | **Yes** |

---

## 5. Callees (sealed 2026-07-29)

| Address | Name | Role |
|---|---|---|
| `0x004bb950` | `Object_ResolveFromTFID` | target object from TFID |
| `0x00550300` | `Skill_ResolveTargetList` | null-list path |
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` | optional local apply |
| heap | `operator_new` / `operator_new[]` / `operator_delete` / `operator_delete[]` | packet + optional list |

**No** PacketDispatch, sector send, or bitstream helper in the callee set.

---

## 6. Gaps

1. Wire emission of packed `0x2031` (if any) is **outside** this unit — not traced to a specific emit call site this pass.
2. Exact product English for `thisWorld` / `+0x7e` (sim/server polarity family sealed; name open).
3. ResolveTargetList flag→code map English vs full `eSkillResponses` table (local only; return always 0).
4. Runtime cast not observed; bit-exact open.

**Verdict:** 0x2031 packer CF + field map + **no-wire-in-unit** sealed. **accept-with-gaps.**
