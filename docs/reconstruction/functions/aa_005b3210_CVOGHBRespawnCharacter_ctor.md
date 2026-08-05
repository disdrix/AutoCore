# Function record: CVOGHBRespawnCharacter_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3210` |
| **Canonical name** | `CVOGHBRespawnCharacter_ctor` |
| **Ghidra name** | `FUN_005b3210` |
| **Address** | `0x005b3210` |
| **Body range** | `0x005b3210`–`0x005b325d` (77 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / client death-respawn |
| **Completion status** | **partial** — dual A/B **accept**; RTTI + CF + bytes + sole-caller period sealed; fire-path residual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b3210_CVOGHBRespawnCharacter_ctor.md`, `reviews/B_aa_005b3210_CVOGHBRespawnCharacter_ctor.md` (2026-07-29 W23-S) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b3210`
- `Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_005b3210` (legacy scaffold)
- Class RTTI: `CVOGHBRespawnCharacter` (Confirmed)

## Purpose

Construct a thin **respawn-character heartbeat**:

1. `CVOGHBBase_ctor`
2. Install `PTR_FUN_009d957c` (CVOGHBRespawnCharacter vtbl)
3. `SetPeriodAndCounter(1, true)` → `+0x0C`/`+0x10` = 1
4. `this+0x08 = periodMs` (caller: **300000** from death UI)
5. Attach owner null or MI this-adjusted object pointer

Death UI: `new(0x24)` → ctor(localChar, 300000) → list Enqueue + Start.

## Signature

```c
CVOGHBRespawnCharacter* __thiscall CVOGHBRespawnCharacter_ctor(
    CVOGHBRespawnCharacter* this,
    void* pObject,      // may be null; MI this-adjust if non-null
    uint32_t periodMs); // pulse period at +0x08
// ret 8
```

## Algorithm

```
CVOGHBBase_ctor(this)
*this = CVOGHBRespawnCharacter_vtbl
SetPeriodAndCounter(this, 1, true)
this.periodPulse = periodMs   // +0x08
if pObject == null:
  AttachOwner(null)
else:
  AttachOwner(this_adjust(pObject))
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b3210_FUN_005b3210.md`
- Annotated: `docs/reconstruction/raw/aa_005b3210_FUN_005b3210.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBRespawnCharacter_ctor.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005b3210.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005b3210_FUN_005b3210.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00578830-005b3210-w23s-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00508200` | `CVOGHBBase_ctor` |
| Callee | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |
| Callee | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| Caller | `0x00802170` | `Client_LocalDeathUiSequence_Inferred` (sole) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Vtbl / RTTI = `CVOGHBRespawnCharacter` | **Confirmed** |
| Dual-period pattern (+0x0C/10 sentinel, +0x08 pulse) | **High** |
| Death path period 300000 | **High** (sole caller) |
| OnHeartBeat / fire semantics | **Open** (vfunc residual) |
| Runtime / differential | Open |
