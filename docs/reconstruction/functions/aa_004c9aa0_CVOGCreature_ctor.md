# Function record: CVOGCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9aa0` |
| **Canonical name** | `CVOGCreature_ctor` |
| **Ghidra name** | `FUN_004c9aa0` |
| **Prior aliases** | `Named_CalleeOf_CVOGReaction_GiveItemByCbid_004c9aa0` |
| **Address** | `0x004c9aa0`–`0x004c9f7b` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | creature runtime / world object factory |
| **Completion status** | **Dual-sealed 2026-07-29 W21-F** — structure/ABI/vtbl/factories; field English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC constructor for **CVOGCreature**: optional most-derived dual-base cookies, parent base `FUN_005c82a0(0)`, creature vtbl install (incl. SetupGraphics), large default field run, map head + 0x60 subobject.

Most-derived heap size **0x690**. Character ctor calls with **flag 0** as base.

## Signature

```c
// __thiscall; ret 4; returns this
uint32_t* CVOGCreature_ctor(uint32_t* self, int mostDerivedFlag);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.md`
- Annotated: `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGCreature_ctor.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_004c9aa0.cpp`
- Reviews: `reviews/A_aa_004c9aa0_CVOGCreature_ctor.md`, `reviews/B_aa_004c9aa0_CVOGCreature_ctor.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `CVOGSpawnPoint_CreateCreature` | `new(0x690)` + flag 1 |
| Caller | `CVOGReaction_GiveItemByCbid` | `0x690` + flag 1 |
| Caller | `Skill_SpawnTemplateAndStartHB` (`00620480`) | `0x690` + flag 1 |
| Caller | `CVOGCharacter_ctor` (`00536920`) | flag **0** base |
| Caller | `FUN_004ca150`, `FUN_00568670`, `FUN_00503780`, `FUN_00855810` | flag 1 |
| Callee | `FUN_00518940` | most-derived only |
| Callee | `FUN_005c82a0` | parent base, flag 0 |
| Callee | `FUN_0058d9c0` | map head → `this+0x158` |
| Callee | `FUN_0096e0e0` | mid-init |
| Callee | `operator_new(0x60)` + `FUN_005d55f0` | subobj → `this+0xF8` |

## Key offsets (this)

| Offset | Init | Confidence |
|---|---|---|
| +0x0 | primary vtbl `009cbe74` | **High** |
| +0x4 / +0x44 | dual-base cookies when flag≠0 | **High** |
| +0x40 | SetupGraphics vtbl `009cbe38` | **High** |
| +0x100 | byte 1 (`param_1+0x40` as byte store) | **High** |
| +0x124 | float 15.0f (`DAT_00aaa7a4`) | **High** |
| +0x158 | map head (`0058d9c0`) | **High** |
| +0xF8 | 0x60 subobject ptr | **High** |
| +0x309 | byte 1 (cleared by skill spawn later) | **High** |
| complete-object | vb adjust **−0x4fc** | **High** |

## Confidence

| Claim | Level |
|---|---|
| ABI + mostDerived gate + return this | **High** |
| Creature identity via SetupGraphics vtbl + factories | **High** |
| Parent chain + map head + 0x60 subobj | **High** |
| Full field English dictionary | **Open** |
| Product name `CVOGCreature_ctor` | **Probable** |
