# Function record: CVOGHBBase_Stop

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081d0` |
| **Canonical name** | `CVOGHBBase_Stop` |
| **Address** | `0x005081d0` |
| **Body range** | `0x005081d0`–`0x005081df` (16 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005081d0_CVOGHBBase_Stop.md`, `reviews/B_aa_005081d0_CVOGHBBase_Stop.md` (2026-07-29) |
| **Last reviewed** | `2026-07-29` |
| **Prior scaffold** | `FUN_005081d0` / `aa_005081d0_FUN_005081d0.md` |

## Purpose

If heartbeat `fDormant` (`this+0x21`) is clear (armed), set it to **1** and tail-call virtual OnEnd (`vtbl+0x10`). Idempotent when already dormant. Does **not** dequeue from `CVOGHBList`, clear owner, set period, or stamp last-fire.

Inverse of `CVOGHBBase_Start` (`aa_005081c0`).

## Signature (decompiler + bytes)

```c
void __fastcall CVOGHBBase_Stop(CVOGHBBase *this);  // this = ECX; ret 0
```

## Layout (this unit)

| Offset | Field | Role in Stop |
|---|---|---|
| `+0x00` | `pVTable` | load for OnEnd |
| `+0x21` | `fDormant` (byte) | gate + set to 1 |

Ctor (`aa_00508200`) seeds `fDormant=1`. Start (`aa_005081c0`) clears it + OnStart. TryFire (`aa_005082c0`) treats dormant as **Inactive** when period due.

## Algorithm

1. `if (*(byte*)(this+0x21) != 0) return;`
2. `*(byte*)(this+0x21) = 1;`
3. `jmp *(void**)(*this + 0x10);` // OnEnd, tail-call

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.md`
- Annotated: `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_Stop.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005081d0-cvoghbbase-stop-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | Virtual only — `vtbl+0x10` OnEnd (no direct FUN_* in body) |
| **Callers (xref sample)** | 19 static xrefs including `Client_Input_DriveControlTick`, `Client_CreateVehicleObjectApply`, skill/AI packs (`FUN_00512add` region), list/lifecycle helpers. Full pairing audit open. |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `fDormant` @ +0x21 | **High** |
| OnEnd = vtbl+0x10 tail-call | **High** |
| Stop ≠ Dequeue | **High** |
| OnEnd product English name | **Inferred** |
| Full caller pairing audit | Open |

## Related

- `aa_005081c0` CVOGHBBase_Start (inverse)
- `aa_00508200` CVOGHBBase_ctor
- `aa_005082c0` CVOGHBBase_TryFire
- `aa_00508350` CVOGHBBase_RescheduleAfterFire
- `aa_005078f0` CVOGHBList_Enqueue
- `aa_00507950` CVOGHBList_Tick
