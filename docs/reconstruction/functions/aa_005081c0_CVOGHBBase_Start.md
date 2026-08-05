# Function record: CVOGHBBase_Start

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081c0` |
| **Canonical name** | `CVOGHBBase_Start` |
| **Address** | `0x005081c0` |
| **Body range** | `0x005081c0`–`0x005081cf` (16 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005081c0_CVOGHBBase_Start.md`, `reviews/B_aa_005081c0_CVOGHBBase_Start.md` (2026-07-29 residual) |
| **Last reviewed** | `2026-07-29` |

## Purpose

If heartbeat `fDormant` (`this+0x21`) is set, clear it and tail-call virtual OnStart (`vtbl+4`). Idempotent when already armed. Does **not** enqueue into `CVOGHBList`, attach owner, set period, or stamp last-fire.

## Signature (decompiler + bytes)

```c
void __fastcall CVOGHBBase_Start(CVOGHBBase *this);  // this = ECX; ret 0
```

## Layout (this unit)

| Offset | Field | Role in Start |
|---|---|---|
| `+0x00` | `pVTable` | load for OnStart |
| `+0x21` | `fDormant` (byte) | gate + clear to 0 |

Ctor (`aa_00508200`) seeds `fDormant=1`. TryFire (`aa_005082c0`) treats dormant as **Inactive** when period due. Sibling Stop (`0x005081d0`) sets dormant=1 + OnEnd `vtbl+0x10`.

## Algorithm

1. `if (*(byte*)(this+0x21) == 0) return;`
2. `*(byte*)(this+0x21) = 0;`
3. `jmp *(void**)(*this + 4);` // OnStart, tail-call

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.md`
- Annotated: `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_Start.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005081c0-cvoghbbase-start-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | Virtual only — `vtbl+4` OnStart (no direct FUN_* in body) |
| **Callers (sample)** | 50+ xrefs; pattern: `new` + subclass ctor → `CVOGHBList_Enqueue` → **Start**. Named: `Skill_StartCastAgainHeartbeat` (`0x00519200`), `CVOGObjectiveRequirement_Patrol_InitActive` (`0x0060e3d0`), `CVOGReaction_RecordFirstTimeEvent` (`0x00522bc0`), vehicle combat-pool ensures (`0x004f7ec0`, `0x004fedc0`, `0x005021d0`), many skill/AI packs |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `fDormant` @ +0x21 | **High** |
| OnStart = vtbl+4 tail-call | **High** |
| Start ≠ Enqueue | **High** |
| OnStart product English name | **Inferred** |
| Full caller pairing audit | Open |

## Related

- `aa_00508200` CVOGHBBase_ctor
- `aa_005082c0` CVOGHBBase_TryFire
- `aa_00508350` CVOGHBBase_RescheduleAfterFire
- `aa_005078f0` CVOGHBList_Enqueue
- `aa_00507950` CVOGHBList_Tick
- `aa_00519200` Skill_StartCastAgainHeartbeat
