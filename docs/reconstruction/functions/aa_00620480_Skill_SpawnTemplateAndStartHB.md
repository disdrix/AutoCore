# Function record: Skill_SpawnTemplateAndStartHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_00620480` |
| **Canonical name** | `Skill_SpawnTemplateAndStartHB` |
| **Ghidra name** | `FUN_00620480` |
| **Address** | `0x00620480` |
| **Body range** | `0x00620480`–`0x00620a20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills / HB action spawn |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + floats + DATA install sealed; product English / arg3 open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00620480_Skill_SpawnTemplateAndStartHB.md`, `reviews/B_aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| **Last reviewed** | `2026-07-29` (W19-E) |

## Alias

- `FUN_00620480` (Ghidra)
- `Skill_Skill_d_had_invalid_template_d` / `*_00620480` — string-seed from error log only
- Scaffold system was `unknown`

## Purpose

Skill dispatch handler (function-pointer table entry) that gates on world ctx, samples pose from a related object, spawns a template entity (direct `0x690` ctor path **or** `FUN_0058bf50` template lookup), snaps terrain height with **+100.0f** Z bias, ensures skill-tree entries, constructs/enqueues/starts a **0x6c0** HB action (`FUN_006202f0`), and optionally applies skill effects.

## Signature

```c
// Machine: 6 stack dwords, epilogue ret 0x18
// Returns 0 on invalid template; 1 on success / gate no-op
uint32_t Skill_SpawnTemplateAndStartHB(
    Object* source,
    SkillDef* skillDef,
    WorldCtx* ctx,
    undefined4 arg3,
    undefined4 arg4,
    uint32_t arg5);
```

## Layout (this unit)

### SkillDef (`param_2`)

| Offset | Role |
|---:|---|
| `+0x22` | char: 0 direct spawn / nonzero template path |
| `+0x14c` | template id |
| `+0x150` | optional effect blob* |
| `+0x154/+0x158/+0x15c` | skill ids for EnsureLoaded |
| `+0x5f6` | u16 for ResolveSkillTargets |
| `+0x5fc` | skill id (error log) |

### WorldCtx (`param_3`)

| Offset | Role |
|---:|---|
| `+0x7e` | enable gate |
| `+0xe4ec` | HB list* |

## Algorithm

1. Gate `ctx+0x7e && source && source.vtbl+0x214()`; else return 1.
2. Sample quat/pos from related object.
3. If `skillDef+0x22==0`: `new(0x690)` + `FUN_004c9aa0(1)` + vcall init.
4. Else: `FUN_0058bf50`; null → log + return 0; else transform + spawn `vtbl+0x1d8`.
5. Terrain cast at `z+100.f`; place; ensure skills; orient.
6. `new(0x6c0)` + `FUN_006202f0`; destroy if no owner else Enqueue+Start.
7. Optional ApplyEffects when `+0x150` set; return 1.

## Constants

| Symbol | Value |
|---|---|
| `DAT_00aaa688` | **5.0f** |
| `DAT_00aaa7ac` | **100.0f** |
| entity size | `0x690` |
| HB size | `0x6c0` |
| install site | `0x009d1598` → `0x00620480` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00620480_FUN_00620480.md` (+ live 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_00620480_FUN_00620480.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_SpawnTemplateAndStartHB.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00620480.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004bc180-00620480-w19e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | pose helpers `00404*`, `FUN_004c9aa0`, `FUN_0058bf50`, `CVOGMap_CastTerrainHeight`, `Skill_EnsureLoadedInTree`, `FUN_006202f0`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, `CVOGReaction_ResolveSkillTargets`, `Skill_ApplyEffectsOnTarget_Inferred`, `FUN_007a4480`, allocators |
| **Callers** | **DATA only** `@0x009d1598` (no direct CALL xrefs) — dispatch/table install |

## Confidence

| Claim | Level |
|---|---|
| Dual spawn arms + HB start CF | **High** |
| `ret 0x18` / return 0\|1 | **High** |
| Floats 5.0 / 100.0 | **High** |
| DATA install site | **High** |
| Product/PDB; unused arg3 English | Open |
| Runtime / bit-exact | Open |

## Related

- `FUN_006202f0` HB action ctor for this path
- `Skill_ApplyEffectsOnTarget_Inferred` (`0x005538a0`)
- `CVOGMap_CastTerrainHeight` (`0x004cfe60`) — cites this as map/world path consumer
- Sibling skill spawn `FUN_00615020` (shares invalid-template string family)
