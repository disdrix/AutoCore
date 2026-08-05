# Function record: CVOGGraphicsBase_PostLoadScaleAndSelectFx

| Field | Value |
|---|---|
| **Stable ID** | `aa_00585e00` |
| **Canonical name** | `CVOGGraphicsBase_PostLoadScaleAndSelectFx` |
| **Ghidra name** | `FUN_00585e00` |
| **Address** | `0x00585e00` |
| **Body range** | `0x00585e00`–`0x00586056` (**599 B** inclusive last RET) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / graphics / select-fx / LogicUI |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI+CF+constants sealed; product method English Probable |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md`, `reviews/B_aa_00585e00_CVOGGraphicsBase_PostLoadScaleAndSelectFx.md` |
| **Last reviewed** | `2026-07-29` (W26-N) |

## Alias

- `FUN_00585e00` (Ghidra)
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_Setup_00585e00`

## Purpose

Post-`CVOGGraphicsBase::InitializeGraphics` path (flag bit0 on `obj+0x188`): compute reciprocal mesh scale, apply host scale vtbl, place graphics via vtbl mode 3, optionally run near-range `Object_PlayPickupSpecialFX` and `Client_SendLogicUiPacket` type **0x1F**.

## Signature

```c
// Machine: __thiscall, ECX=this, stack char, RET 4; return x87 ST0 float
float __thiscall CVOGGraphicsBase_PostLoadScaleAndSelectFx(void *this, char skipSideFx);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.md`
- Annotated: `docs/reconstruction/raw/aa_00585e00_FUN_00585e00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGGraphicsBase_PostLoadScaleAndSelectFx.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00585e00.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00585e00-00540890-w26n-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `FUN_00586060` (`CVOGGraphicsBase::InitializeGraphics`) @ `0x0058645a` arg `0` |
| **Callees** | `FUN_005130e0`; gfx `+0x48/+0x10`; host `+0xB8`; `FUN_004e88e0`×2; `FUN_0040cf90`; `FUN_00404bd0`; `FUN_00516c40`; `Object_PlayPickupSpecialFX` (`FUN_0051aed0`); `Client_SendLogicUiPacket` |

## Confidence

| Claim | Level |
|---|---|
| thiscall + RET 4 + ST0 float | **High** |
| CF stages + constants 2.0/0.5/50/3.5/0 | **High** |
| Caller class string `CVOGGraphicsBase::InitializeGraphics` | **High** |
| Method English `PostLoadScaleAndSelectFx` | **Probable** (role, not plate) |
| Runtime / bit-exact | Open |
