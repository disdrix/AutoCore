# Function record: CVOGMission_AddActiveObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **Canonical name** | `CVOGMission_AddActiveObjective` |
| **Address** | `0x00531b00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` (character ECX + objective def stack) |
| **Completion status** | **Human-refined clean** — CF sealed; hash targets + arity asm-sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual status** | A/B **strengthened** 2026-07-29 (`accept-with-gaps`) |

## Purpose

Insert objective **definition** into active-objectives hash (`FUN_0053c460` / **`char+0x548`**). If evaluator array `[+0x158,+0x15c)` nonempty: allocate 0x14-byte runtime state node, insert into **pending** hash (`FUN_0053c760` / **`char+0x55c`**), invoke each evaluator `vtable+0x28`, set dirty `char+0x634 |= 0x10`.

## Signature (decompiler-derived + asm)

```c
void __thiscall CVOGMission_AddActiveObjective(CVOGCharacter* thisCharacter, ObjectiveDef* objectiveDef);
```

Callers: GiveMission `0x005328b2`, CompleteObjective `0x005348a2` — both `PUSH def; MOV ECX, char; CALL`.

## Behavioral summary

1. Always hash-insert **def** by id `def+0x10` into **`this+0x548`** (return ignored).
2. If evaluators nonempty: `operator_new(0x14)`, zero, store def ptr, insert node into **`this+0x55c`**; on nonzero → `operator_delete` then **fall through**; per-evaluator setup vcall; dirty bit `0x10`.
3. Empty evaluators: no node / no pending insert / no dirty.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; two callers asm-sealed |
| Control flow | High | Linear + one conditional block; delete fall-through sealed |
| Def hash `+0x548` | **High** | asm ECX load before `FUN_0053c460` |
| Pending hash `+0x55c` | **High** | asm ECX load before `FUN_0053c760` |
| Evaluator array offsets | High | Shared with EvaluatePendingObjectives / RecvObjectiveState |
| `FUN_0053c460` / `FUN_0053c760` English names | Probable role / open name | Twin CNDHash inserts; distinct node vtables |
| Dirty bit `0x10` at `+0x634` | High value | Matches FailMission dirty pattern |
| Overall | **High (static)** | Runtime/diff open |

## Open questions

- Exact type of 0x14 state node field map vs RecvObjectiveState.
- Evaluator vtable `+0x28` method identity.
- Dirty bit consumers.
- Original helper symbols.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Annotated | `raw/aa_00531b00_CVOGMission_AddActiveObjective.annotated.md` |
| Clean | `reconstructed-exact/CVOGMission_AddActiveObjective.cpp` |
| Dual A | `reviews/A_aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Dual B | `reviews/B_aa_00531b00_CVOGMission_AddActiveObjective.md` |
| Scratch | `reviews/a_00531b00.md` |
