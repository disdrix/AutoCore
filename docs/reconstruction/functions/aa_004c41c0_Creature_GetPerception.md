# Function record: Creature_GetPerception

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c41c0` |
| **Canonical name** | `Creature_GetPerception` |
| **Address** | `0x004c41c0`–`0x004c428e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / character stats |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — ABI/CF/clamp/thr/product string sealed; field English + vtbl English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias

- Ghidra: `FUN_004c41c0`
- Scaffold: `Named_CalleeOf_Client_DebugDumpEntityCombatStats_004c41c0`

## Purpose

Getter for creature **Perception** stat:

```
score = min(min(int16(creature+0x142), 200) + int16(creature+0x14a), 250)
thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
return max(score, thr)
```

Product name from UI `"Perception"` localization key. Same arithmetic + thr shape as Combat (`FUN_004c4070`); Theory (`FUN_004c4140`) is the thr-less sibling with floor 1.

## Signature (sealed)

```c
// __fastcall / thiscall: creature in ECX; int return in EAX; plain RET
// Indirect call: MI this-adjust then vtbl+0x1DC (not a static FUN_* callee)
int __fastcall Creature_GetPerception(void *creature);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.md` (+ scaffold `aa_004c41c0_FUN_004c41c0.md`)
- Annotated: `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Creature_GetPerception.cpp` (+ `FUN_004c41c0.cpp`)
- Dual A: `docs/reconstruction/reviews/A_aa_004c41c0_Creature_GetPerception.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004c41c0_Creature_GetPerception.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Callees | — | **no static FUN_***; indirect **vtbl+0x1DC** (×2 paths) |
| Caller | `0x00845360` | UI requirements — `"Perception"` label |
| Caller | `0x00514390` | req gate vs skill/item short |
| Caller | `0x004ceba0` | `Skill_NonCreatureCastAutoHit` (return may be discarded in high pcode) |
| Caller | `0x00955eb0` | `Client_DebugDumpEntityCombatStats` — **P** field |
| Caller | others | `004c4c10`, `004c4dd0`, `004c8f00`, `00568250`, `00846820`, `008d0b70`, `008f97c0`, `00933d60` |
| Sibling | `0x004c4070` | Combat getter (not owned) |
| Sibling | `0x004c4140` | Theory getter (not owned) |

## Confidence

| Claim | Level |
|---|---|
| ECX creature + plain RET | **High** |
| Offsets +0x142 / +0x14a shorts | **High** |
| Cap base 200 / sum 250 | **High** |
| thr 1/-100 via vtbl+0x1DC | **High** |
| return max(score, thr) | **High** |
| Product name Perception | **High** (UI string) |
| Field-level base vs bonus English | **Probable** |
| vtbl+0x1DC = vehicle/MI present | **Probable** |
