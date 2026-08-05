# Dual A/B report — `aa_00606d70` Outpost_CastSkillsForFaction

**Date:** 2026-07-29  
**Owned VA:** `0x00606d70` only  
**Tools:** Ghidra `decompile_function` / `read_memory` / `analyze_function_complete` / `get_function_callers` / `audit_globals_in_function` (no Launcher; no WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG)  
**Verdict:** **accept-with-gaps**

---

## Sealed facts

### Role

| Fact | Evidence |
|---|---|
| Outpost **faction skill-bank** multi-target cast | Name + body; skills from `this+faction*0x48+0xd4` |
| Fired from **CaptureOutpost** path | Sole caller `FUN_006082e0` @ xref `0x0060855b`; string `Invalid faction in CaptureOutpost` |
| Not UI / not C2S 0x2030 | Callees: ResolveSkillTargets → ResolveObjectTarget → ValidateTarget → CastSkillOnTarget |
| CastSkillOnTarget = packer/local apply only | Downstream dual `aa_004d09a0` — no wire in unit |

### Signature

```c
void __thiscall Outpost_CastSkillsForFaction(void *thisOutpost, int factionIndex /*0..3*/);
```

Prologue (`read_memory` @ `0x00606d70`): `ECX`→`ESI` this; `[esp+4]` factionIndex; early-out if `<0` or `>=4`; require object vec `ESI+0x228` non-null and `(end-begin)>>3 != 0`.

### Gates

| Gate | Effect |
|---|---|
| `factionIndex ∉ [0,3]` | return |
| `this+0x228 == 0` | return |
| object count `((+0x22c)-(+0x228))>>3 == 0` | return |
| skill entry `+0x0C == 0` | skip entry |
| `ResolveSkillTargets` → null | log Invalid; advance |
| `ResolveObjectTarget` → null | skip object |
| `ValidateTargetForSkill` AL==0 (notify **0**) | skip object |

### Layouts

| Structure | Location | Stride / size |
|---|---|---|
| Per-faction skill bank base | `this + factionIndex * 0x48` | 4 banks |
| Skill vector | bank `+0xd4` / `+0xd8` | **0x10** |
| Skill entry | `+0` skillId, `+4` rank byte, `+0xC` enabled char | 0x10 |
| Shared object vector | `this+0x228` / `+0x22c` | **8** |
| Object TFID on resolve | `obj+0x160..+0x16c` | 16 bytes |
| Batch buffer | stack `local_640[400]` dwords | 100 TFID slots |

### Batch / cast contract

| Fact | Value |
|---|---|
| Flush when | `batchCount > 0x62` (**99** targets) |
| Terminator | `DAT_009de7d8..e4` = **`{0xFFFFFFFF,0xFFFFFFFF,0,0}`** (`read_memory`) |
| Aim | `&DAT_00d029d0` — BSS all zeros |
| Cast args (decomp) | `(skill, outpostAsSource, 0, 0, batch, aimZero, 0, 0xFFFFFFFF, 0, 0)` |
| Source | MI adjust `*( *(this+4) + 4 ) + this + 4` |
| Free | `operator_delete(skill)` after cast(s) — **returns** (noreturn warning false) |

### Caller contract (context)

```
CaptureOutpost FUN_006082e0:
  ... world map +0x7e != 0 ...
  Outpost_CastSkillsForFaction(this=outpost, factionIndex=capturerRootRace);
```

### Constants (`read_memory`)

| Symbol | VA | LE bytes | Meaning |
|---|---|---|---|
| TFID terminator block | `0x009de7d8` | `ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00` | end-of-list TFID |
| Aim / zero vec | `0x00d029d0` | 32× `00` | zero aim passed into cast |
| Invalid format string | `0x009de858` | string | `"Invalid outpost skill cast for skill %d, map: %s"` |

---

## Gaps

1. **Invalid-log polarity** — decomp runs log after both resolve-miss and post-success `operator_delete`; skillId register may be clobbered by object loop. Miss-only vs always-on **unsealed**.
2. **Rank packing** — entry `+0x04` byte is sealed as rank input; decomp `CONCAT22` with skill-vector-begin high half is artifact; u8 vs u16 product width open.
3. **Decompiler SSA merge** — `param_1` / `iVar4` alias this, bank base, batch count, and source adjust. Port must use distinct locals (algorithm still sealed).
4. **CastSkillOnTarget ECX/world** — whether hidden thiscall world is passed; capture path already gates map `+0x7e`.
5. **Object-vector product type** — who lives in `+0x228` (all sector objects vs filtered set).
6. **Runtime / bit-exact / image diff** — not done.
7. **No `disassemble_bytes`** per rules — rank/log CF residual not asm-closed.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00606d70_Outpost_CastSkillsForFaction.md` | accept-with-gaps |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00606d70_Outpost_CastSkillsForFaction.md` | accept-with-gaps |

---

## Files touched / authoritative

| Role | Absolute path |
|---|---|
| Dual A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| Dual B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00606d70_Outpost_CastSkillsForFaction.md` |
| Raw (unchanged body) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00606d70_FUN_00606d70.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00606d70_FUN_00606d70.annotated.md` |
| Clean | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Outpost_CastSkillsForFaction.cpp` |
| This report | `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-00606d70-outpost-castskillsforfaction-report.md` |
| Downstream context | `docs\reconstruction\reviews\A_aa_004d09a0_CVOGReaction_CastSkillOnTarget.md` |
| Downstream context | `docs\reconstruction\reviews\A_aa_00553650_Skill_ValidateTargetForSkill.md` |

---

## AutoCore port sketch

```csharp
// Capture path only; faction = capturer root race [0..3]
void CastSkillsForFaction(Outpost op, int faction)
{
    if ((uint)faction > 3) return;
    var objs = op.ObjectRefSpan; // +0x228/+0x22c, 8-byte entries
    if (objs.IsEmpty) return;

    foreach (var entry in op.FactionSkillBank(faction)) // +faction*0x48+0xd4, stride 0x10
    {
        if (!entry.Enabled) continue; // +0x0C
        var skill = ResolveSkillTargets(entry.SkillId, entry.Rank); // +0, +4
        if (skill is null)
        {
            LogInvalid(entry.SkillId, op.MapName);
            continue;
        }

        Span<Tfid16> batch = stackalloc Tfid16[100];
        int n = 0;
        foreach (var oref in objs)
        {
            var obj = ResolveObjectTarget(type: 1, oref.A, oref.B);
            if (obj is null) continue;
            if (!ValidateTargetForSkill(skill, obj, notify: false)) continue;

            batch[n++] = obj.Tfid; // +0x160
            if (n > 99)
            {
                batch[n] = Tfid16.Terminator_FF_FF_0_0;
                CastSkillOnTarget(skill, op.AsSource(), null, batch, aim: default,
                    hasExtra: false, extra: unchecked((int)0xFFFFFFFF),
                    statusC: false, charge: 0);
                n = 0;
            }
        }
        if (n > 0)
        {
            batch[n] = Tfid16.Terminator_FF_FF_0_0;
            CastSkillOnTarget(/* same */);
        }
        FreeSkillRuntime(skill); // 0x630
    }
}
```
