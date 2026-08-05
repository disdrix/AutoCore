# Function record: CVOGPhaseDistort_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576ed0` |
| **Canonical name** | `CVOGPhaseDistort_ctor` |
| **Ghidra name** | `FUN_00576ed0` |
| **Address** | `0x00576ed0` |
| **Body range** | `0x00576ed0`–`0x00576f11` exclusive (**65 B** / `0x41`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / VOGEnvironmentSector phases |
| **Completion status** | **partial** — dual A/B **accept**; RTTI + CF + ABI + sole factory sealed; field English residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00576ed0_CVOGPhaseDistort_ctor.md`, `reviews/B_aa_00576ed0_CVOGPhaseDistort_ctor.md` (2026-07-29 W32-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00576ed0`
- `Named_CalleeOf_Drive_NDRiver_fx_00576ed0` (**reject** — caller string is NDRiver; this unit is Distort phase)
- Class RTTI: `CVOGPhaseDistort` (**Confirmed**)

## Purpose

Construct the process-singleton **Distort** environment phase:

1. Store GfxView* at `+0x04`
2. Install vtbl `PTR_FUN_009d3bc0` (RTTI `CVOGPhaseDistort`)
3. Zero `+0x0C` / `+0x10` / `+0x14`

Factory (`PalantirEnv_InitPhases`): if `DAT_00b04818==0`, `new(0x18)` → this ctor(view@env`+0xC0`) → singleton + owner env; vcall `+0x20`; `FUN_00576d70`; log on fail.

## Signature

```c
CVOGPhaseDistort* __thiscall CVOGPhaseDistort_ctor(
    CVOGPhaseDistort* this,
    void* view);   // GfxView* from env+0xC0
// ret 4; returns this
```

## Algorithm

```
SEH LAB_009a514a
this.view = view          // +0x04
*this = CVOGPhaseDistort_vtbl
this[+0x0C]=this[+0x10]=this[+0x14]=0
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00576ed0_FUN_00576ed0.md`
- Annotated: `docs/reconstruction/raw/aa_00576ed0_FUN_00576ed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhaseDistort_ctor.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00576ed0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00576ed0_FUN_00576ed0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00576ed0-005b35a0-w32t-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | (none) | leaf ctor (SEH only) |
| Caller | `0x0048fc90` @ `0x0048fd60` | `PalantirEnv_InitPhases_Inferred` (sole) |
| Related | `0x00576f20` | body dtor |
| Related | `0x00576d70` | phase init after vcall |
| Related | `0x00576f70` | `CVOGPhaseDistort::AddPieceInstance` plate |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes + `ret 4` | **Confirmed** |
| Vtbl / RTTI = `CVOGPhaseDistort` | **Confirmed** |
| Alloc size 0x18 + sole factory | **Confirmed** |
| View at `+0x04` | **High** |
| Field English for tails / `+0x08` | **Open** |
| Runtime / differential | Open |
