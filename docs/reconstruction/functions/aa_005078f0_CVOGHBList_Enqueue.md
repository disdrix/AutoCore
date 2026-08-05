# Function record: CVOGHBList_Enqueue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005078f0` |
| **Canonical name** | `CVOGHBList_Enqueue` |
| **Address** | `0x005078f0` |
| **Body** | `0x005078f0`–`0x00507946` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / map-owned timed-action list |
| **Completion status** | **Sealed (dual A/B 2026-07-29)** — CF, HRESULT, pending layout, grow double |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual review** | A: **accept** · B: **accept** |

## Purpose

Thread-safe append of a `CVOGHBBase*` into the list **pending** buffer (`+0x28`/`+0x2c`). Does **not** insert into the active set; `CVOGHBList_Tick` (`0x00507950`) promotes pending → active under the same critical section, then runs TryFire on actives.

## Signature (decompiler-derived, sealed)

```c
// __thiscall
// this     : CVOGHBList*
// pAction  : CVOGHBBase*  (null → E_INVALIDARG)
// returns  : 0 success; 0x80070057 (E_INVALIDARG) if pAction == null
uint __thiscall CVOGHBList_Enqueue(void *this, CVOGHBBase *pAction);
```

## Layout used

| Offset | Field |
|---|---|
| `+0x04` | `CRITICAL_SECTION` |
| `+0x28` | pending `CVOGHBBase**` |
| `+0x2c` | pending count |
| `+0x30` | pending capacity raw (`& 0x7fffffff`; high bit = no-owned-heap sentinel) |

## Algorithm

1. If `pAction == null` → return `0x80070057`.
2. `EnterCriticalSection(this+4)`.
3. If `count == (capRaw & 0x7fffffff)` → `FUN_005b3370(this+0x28, 4)` (double capacity or 1 if empty).
4. `pending[count] = pAction; count++`.
5. `LeaveCriticalSection`; return `0`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.md`
- Annotated: `docs/reconstruction/raw/aa_005078f0_CVOGHBList_Enqueue.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBList_Enqueue.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005078f0_CVOGHBList_Enqueue.md`
- Review B: `docs/reconstruction/reviews/B_aa_005078f0_CVOGHBList_Enqueue.md`
- Report: `docs/agents/task-dual-ab-005078f0-cvoghb-list-enqueue-report.md`

## Callers / callees

**Callees:** `EnterCriticalSection`, `LeaveCriticalSection`, `FUN_005b3370` (grow).

**Callers (Ghidra xrefs, partial):** `Vehicle_EnsureRegenerationHeartbeat`, `Skill_StartCastAgainHeartbeat`, `Skill_ApplyStatusEffectLocal`, `Vehicle_ActivateEnterWorld`, `Client_CreateVehicleObjectApply`, `CVOGReaction_RecordFirstTimeEvent`, `CVOGObjectiveRequirement_Patrol_InitActive`, `VehicleNet_UnpackGhostVehicle`, many effect/HB factories. Typical list: world/map `+0xe4ec`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** (sealed) |
| Pending vs active semantics | **High** (sealed vs Tick) |
| Grow double / element size 4 | **High** (sealed from `0x005b3370`) |
| Parameter names `pAction` / list-this | **High** (named + call sites) |
| Product RTTI names for grow/allocator | Tentative |

## Related

- `CVOGHBList_Tick` `aa_00507950` — promote + TryFire
- `CVOGHBList_ctor` `aa_00507d10` — layout seed / CS init
- `CVOGHBBase_Start` `aa_005081c0` — Start ≠ Enqueue
