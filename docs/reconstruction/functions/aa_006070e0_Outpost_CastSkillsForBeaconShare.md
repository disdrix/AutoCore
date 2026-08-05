# Function record: Outpost_CastSkillsForBeaconShare

| Field | Value |
|---|---|
| **Stable ID** | `aa_006070e0` |
| **Canonical name** | `Outpost_CastSkillsForBeaconShare` |
| **Former name** | `FUN_006070e0` |
| **Address** | `0x006070e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` (ECX = outpost) |
| **System** | skills-abilities / outpost |
| **Completion status** | **Human-refined + dual A/B 2026-07-29** (accept-with-gaps) |
| **Evidence** | `"Invalid outpost skill cast for skill %d, map: %s"`; sole caller `FUN_006078e0` ratio gate; ValidateTarget + CastSkillOnTarget |

## Signature

```c
void __thiscall Outpost_CastSkillsForBeaconShare(void* thisOutpost, int factionIndex /*0..3*/);
```

## Summary

Casts **beacon-share-gated** skills from the per-faction skill bank (`factionBase+0xd4`, stride **0x10**) when:

1. `factionIndex ∈ [0,3]`
2. entry flag at **+0xC** is **0** (polarity **opposite** of `Outpost_CastSkillsForFaction`)
3. outpost beacon-share ratio `*(float*)(this+0x24c) >=` entry threshold float at **+0x8**

Targets come from the **per-faction** TFID vector (`factionBase+0xb4/+0xb8`, stride 8), resolved with `CVOGReaction_ResolveObjectTarget(**0**, …)` (faction sibling uses mode **1**). Nested container walk (vtbl **+0x1ec**, CS iterator) filters entities (vtbl **+0x1d8** / field **+0x250**) then `Skill_ValidateTargetForSkill`. TFIDs (`entity+0x160`) batch-flush when count **> 0x62**, terminator `DAT_009de7d8` (`FFFFFFFF FFFFFFFF 00000000 00000000`), aim `&DAT_00d029d0` (zero BSS), cast via `CVOGReaction_CastSkillOnTarget`.

**Caller:** `FUN_006078e0` only — recomputes `+0x24c = factionBeacons/totalBeacons`; on **change**, calls with `factionIndex = *(this+0x234)`.

## Artifacts

| Kind | Path |
|---|---|
| Dual A | `docs/reconstruction/reviews/A_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| Raw | `docs/reconstruction/raw/aa_006070e0_FUN_006070e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006070e0_FUN_006070e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Outpost_CastSkillsForBeaconShare.cpp` |
| Legacy clean | `docs/reconstruction/reconstructed-exact/FUN_006070e0.cpp` |
| Agent report | `docs/agents/task-dual-ab-006070e0-outpost-castskills-beaconshare-report.md` |

## Callers / callees

| Dir | Symbol | VA |
|---|---|---|
| Caller | `FUN_006078e0` (beacon share recompute) | `0x006078e0` |
| Callee | `CVOGReaction_ResolveSkillTargets` | `0x0054c570` |
| Callee | `CVOGReaction_ResolveObjectTarget` | `0x004bae70` |
| Callee | `Skill_ValidateTargetForSkill` | `0x00553650` |
| Callee | `CVOGReaction_CastSkillOnTarget` | `0x004d09a0` |
| Callee | `FUN_004294f0` / `FUN_004022a0` | CS list walk |
| Callee | `FUN_007a4480` | log |
| Callee | `operator_delete` / `LeaveCriticalSection` | heap / CS |

## Sibling

`Outpost_CastSkillsForFaction` `aa_00606d70` @ `0x00606d70` — shared bank/cast/terminator; **not** interchangeable (flag polarity, ratio, target list, resolve mode, nested walk).

## Gaps (open)

1. Product English for vfuncs `+0x1ec`, `+0x1d8`, field `+0x250`.
2. ResolveObjectTarget mode **0** vs **1** product meaning.
3. Entry `+0xC` flag English (spent / disabled / opposite bank class).
4. Whether invalid log runs after successful free (Ghidra noreturn on delete).
5. Runtime / diff / bit-exact; PDB name.
