# Function record: Outpost_CastSkillsForFaction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606d70` |
| **Canonical name** | `Outpost_CastSkillsForFaction` |
| **Former name** | `FUN_00606d70` |
| **Address** | `0x00606d70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (ECX = outpost; stack factionIndex) |
| **System** | skills-abilities / outpost |
| **Completion status** | **Named + dual A/B 2026-07-29** (accept-with-gaps) |
| **Evidence** | `"Invalid outpost skill cast for skill %d, map: %s"`; prologue ABI; ValidateTarget + CastSkillOnTarget; sole CaptureOutpost caller |

## Signature

```c
void __thiscall Outpost_CastSkillsForFaction(void* thisOutpost, int factionIndex /*0..3*/);
```

## Summary

Casts each **enabled** skill in the **faction skill bank** (`this + factionIndex*0x48 + 0xd4/0xd8`, stride `0x10`) against every object resolved from the shared object vector (`this+0x228/0x22c`, stride `8`). Builds TFID batches (flush at **99**, terminator `{−1,−1,0,0}`), calls `CVOGReaction_CastSkillOnTarget`, frees the resolved skill runtime.

## Artifacts

| Kind | Path |
|---|---|
| Dual A | `reviews/A_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| Dual B | `reviews/B_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| Agent report | `docs/agents/task-dual-ab-00606d70-outpost-castskillsforfaction-report.md` |
| Raw | `raw/aa_00606d70_FUN_00606d70.md` |
| Annotated | `raw/aa_00606d70_FUN_00606d70.annotated.md` |
| Clean | `reconstructed-exact/Outpost_CastSkillsForFaction.cpp` (also `FUN_00606d70.cpp`) |
| Prior alias | `Skill_Invalid_outpost_skill_cast_for_skill_d_map_s_00606d70.cpp` |

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Caller (sole) | `FUN_006082e0` | CaptureOutpost; xref `0x0060855b`; passes capturer root race |
| Callee | `CVOGReaction_ResolveSkillTargets` | skillId + rank → 0x630 or null |
| Callee | `CVOGReaction_ResolveObjectTarget` | type arg **1** |
| Callee | `Skill_ValidateTargetForSkill` | notify **0** @ `0x00606EB6` |
| Callee | `CVOGReaction_CastSkillOnTarget` | 0x2031 packer; no wire in unit |
| Callee | `operator_delete` | free skill; returns |
| Callee | `FUN_007a4480` | log level 1 |

## Key constants / offsets

| Item | Value |
|---|---|
| Faction count | 4 (`[0,3]`) |
| Bank stride | `0x48` |
| Skill vec | bank `+0xd4/+0xd8`, entry `0x10` |
| Enable flag | entry `+0x0C` |
| Object vec | `this+0x228/+0x22c`, entry `8` |
| Batch flush | `> 0x62` (99) |
| Terminator | `DAT_009de7d8` = `{0xFFFFFFFF,0xFFFFFFFF,0,0}` |
| Aim | `&DAT_00d029d0` (zeros) |

## Gaps

- Invalid-log polarity (miss-only vs always)
- Rank width / CONCAT22 artifact
- Decompiler SSA merge of this/bank/batch/source
- Runtime verification
