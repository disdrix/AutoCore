# Function record: Object_SetHostModeFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f880` |
| **Canonical name** | `Object_SetHostModeFlag_Inferred` |
| **Ghidra name** | `FUN_0051f880` |
| **Address** | `0x0051f880`–`0x0051f88c` (**13 B**; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / character status (skills-abilities writer) |
| **Completion status** | **Dual A/B complete** (2026-08-04 OWN-ONLY WQ9F-I) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Alias

- `FUN_0051f880`
- Prior auto plate `Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_0051f880` (**reject** as product — parent-string only)

## Purpose

**Leaf flag setter:** write `uint8_t` to `this+0x6b8` (host-mode / vehicle-host gate). No validation, no side effects, no callees.

| Writer | Arg | Context |
|---|---|---|
| `Skill_HB_FireTail_FxTargetAndPeriodStamp` | **1** | target path; skill`+0x140` gate; `vtbl+0x210(0)` this |
| `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` | **0** | inverse of FireTail |

Readers (not OWN): hardpoint cast when `player+0x6b8`; QuickBar vehicle remap with `+0x6b9` pair; parent prefers `+0x6b8 && !+0x6b9`.

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack fHostMode, ret 4, void
void Object_SetHostModeFlag_Inferred(void *this, uint8_t fHostMode);
```

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Flag byte offset | `+0x6b8` | **High** |
| ABI `ret 4` | `C2 04 00` | **High** |
| Twin enhanced flag | `+0x6b9` / `aa_0051f890` | **High** |

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051f880_FUN_0051f880.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f880_FUN_0051f880.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_SetHostModeFlag_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0051f880.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0051f880_Object_SetHostModeFlag_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051f880_Object_SetHostModeFlag_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0051f880_FUN_0051f880.md` |
| Dual report | `docs/agents/task-dual-ab-0051f880-00574880-wq9fi-report.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes | **High** |
| ABI thiscall + 1 byte stack arg | **High** |
| Host-mode role of `+0x6b8` | **High** (cross-unit readers + Fire/OnEnd polarity) |
| Product method name | **Tentative / Inferred** |
| Exhaustive writer set | **Open** (2 static CALL xrefs known) |
