# Function record: CVOGHBSkill_Virus_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061fdf0` |
| **Canonical name** | `CVOGHBSkill_Virus_OnHeartBeat` |
| **Ghidra name** | `FUN_0061fdf0` |
| **Address** | `0x0061fdf0`–`0x00620186` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | Class **Confirmed** RTTI; method role **High** (vtbl+0x0c OnHeartBeat) |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9R-B** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Virtual **OnHeartBeat** for **`CVOGHBSkill_Virus`**: shared skill pulse, primary-target resolve, ally multi-target gather (mode **1**), spawn child Virus HBs with remaining budget counters.

## Signature

```c
void __thiscall CVOGHBSkill_Virus_OnHeartBeat(
    CVOGHBSkill_Virus* this,   // ECX
    uint32_t* pOutStatus);     // stack; ret 4
```

## RTTI / vtbl

| Item | Value |
|---|---|
| Type | `.?AVCVOGHBSkill_Virus@@` @ type_info `0x00af2b08` |
| COL | `0x00aae0b8` |
| Vtbl | `PTR_FUN_009d14bc` |
| This method | vtbl[+0x0c] = `0x0061fdf0` |
| Ctor | `FUN_0061f940` installs vtbl |

## Sealed CF highlights

| Fact | Confidence |
|---|---|
| mode=1 / filterA=-1 gather | **High** (bytes + Gather residual) |
| maxTargets `+0x102` default 4 | **High** |
| default radius 50.0f | **High** (`DAT_00a0f524`) |
| RNG gate `(u%100)>25` | **High** |
| Child size 0x6e0 + same ctor | **High** |
| List `world+0xe4ec` | **High** (Enqueue dual) |
| Product skill design English | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0061fdf0_FUN_0061fdf0.md`
- Annotated: `docs/reconstruction/raw/aa_0061fdf0_FUN_0061fdf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Virus_OnHeartBeat.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0061fdf0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md`, `B_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061fdf0_FUN_0061fdf0.md`
