# Annotated low-level: FUN_005bc3c0 / Emitter_UpdateTick_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005bc3c0` |
| VA | `0x005bc3c0`–`0x005bdce6` exclusive (**6438** B / `0x1926`) |
| System | client::fx / emitter |
| Date | 2026-07-29 W28-I |
| Preferred name | `Emitter_UpdateTick_Inferred` |
| Ghidra name | `FUN_005bc3c0` |

## Machine-level notes

- **`__thiscall`**: ECX = emitter host; stack `(float *dt, int host_field_2c, int camera_or_world)`; **`ret 0x0C`**.
- Return **0** = HostTick removes from list `+0x1E0`; **1** = keep and run `ObjectMotion_SlotListTick`.
- SEH frame uses `LAB_009a6bd4`.
- Prologue: `55 8B EC 83 E4 F0 6A FF 68 D4 6B 9A 00 …` (align stack, push SEH).
- Epilogue (`read_memory` @ `0x005bdce0`): `8B E5 5D C2 0C 00` then `CC` pad.
- String evidence: `"Emitter found at 0,0,0: %d %I64d"` via `FUN_007a4480`.
- Sole dualed interval-spawn child: `Emitter_SpawnOnIntervalTick_Inferred` @ `0x005bc120` (call site `0x005bdcc1`).
- Quat factor labeled `g_flLevelUpUiBase_Inferred` is **2.0f** @ `DAT_00a10e74` (misnomer).
- `DAT_00aaa668` = **-1.0f** (mode `+0x261==3` axis flip scale).
- `DAT_00af3f70` = **-10.0f** (skybox/UI projection scale).

## Stage map (CF)

| Stage | VA region / label | Role |
|---|---|---|
| Counters | entry | `emitter[0x233]++`; `DAT_00d17958+0x148++` |
| Object death snapshot | early | if object`+0x90e&1`: capture basis; may set `+0x7f9`; clear object ptr |
| Stop flag | `+0x7ff` | clear → **return 1** |
| Countdown | dword `0x204` / `+0x810` | `-= *dt`; still `>0` → **return 1** |
| Early kill | mid | invalid identity + `+0x7f9` + empty list → **return 0** |
| Flag gate | `+0x989&8` | live object without destroy → **return 1** |
| Lifetime | byte `0x1fe` / dword `0x202` | secondary timer; may set `+0x7fa` or `FUN_004b8dc0` |
| Snapshot + ring | `FUN_005b83e0` | copy pose; walk ring at `emitter+5` stride `0xbd` |
| Pose branches | object / skybox / attach | fill `+0x220..+0x22f` basis + scale/vel |
| Join | `LAB_005bd44d` | offset compose, motion, spawn |
| Interval spawn | near end | if mode & empty list → `FUN_005bc120` |
| Exit | epilogue | clear `+0x7fe`; **return 1** |

## Key emitter offsets (byte)

| Offset | Role |
|---|---|
| `+0x0` | active child / list head (`*emitter`) |
| `+0x4` | parent / owner link |
| `+0x8` | world object ptr |
| `+0x7f9` | kill/pending flag |
| `+0x7fa` | lifetime expired flag |
| `+0x7fe` | first-frame / special motion flag (cleared at exit) |
| `+0x7ff` | hard stop |
| `+0x804` / related | used by spawn child |
| `+0x808` | secondary lifetime countdown (dword `0x202`) |
| `+0x810` | primary countdown (dword `0x204`) |
| `+0x820..` | pose snapshots `0x205..` |
| `+0x880..` | live basis `0x220..` |
| `+0x8CC` | tick age (dword `0x233`) |
| `+0x989` | flag byte (bits 3,4,5,7 used) |
| `+0x98a` | skybox/UI bit0 |
| `+0x98d` | scale bit1 |

## Callers

| Caller | Site | Notes |
|---|---|---|
| `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) | `0x004b90ef` | only xref; keep→SlotListTick; kill→unlink+`FUN_005be310` |

## Open questions

1. Product / Torque original method name.
2. Full product meaning of every `+0x989` flag bit.
3. Nested helpers (`FUN_005b83e0`, `FUN_005bb1f0`, …) not OWN — residual.
4. Runtime golden multi-path (object / skybox / attach) — open.
