# Function record: CVOGHBSkill_Virus_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061f940` |
| **Canonical name** | `CVOGHBSkill_Virus_Ctor` |
| **Ghidra name** | `FUN_0061f940` |
| **Address** | `0x0061f940`–`0x0061f998` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** class (RTTI); **High** ctor role |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9D-B** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Construct a **`CVOGHBSkill_Virus`** heartbeat object: call intermediate base `FUN_00618180` with trailing `(0, 1.0f)`, store multi-spread budget @ **`+0x6d0`**, install vtbl **`PTR_FUN_009d14bc`**, store period @ **`+0x6d4`**, `CVOGHBBase_SetPeriodAndCounter(period, true)`.

## Signature

```c
void* __thiscall CVOGHBSkill_Virus_Ctor(
    void *thisHb,
    void *pPrimaryTarget, void *pSkillBlob, void *pWorld,
    void *pNewTarget, void *pTfidArg, uint32_t arg7,
    int remainBudget, int remainPeriod);
// ret 0x20; EAX = this; object size 0x6e0
```

## Sealed facts

| Claim | Confidence |
|---|---|
| RTTI `.?AVCVOGHBSkill_Virus@@` | **Confirmed** |
| Vtbl `PTR_FUN_009d14bc`; OnHeartBeat @ +0x0c | **Confirmed** / **High** |
| +0x6d0 budget / +0x6d4 period | **High** |
| Sole CALL from OnHeartBeat | **High** |
| Product design English | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0061f940_FUN_0061f940.md`
- Annotated: `docs/reconstruction/raw/aa_0061f940_FUN_0061f940.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Virus_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0061f940.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0061f940_CVOGHBSkill_Virus_Ctor.md`, `B_aa_0061f940_CVOGHBSkill_Virus_Ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061f940_FUN_0061f940.md`

## Related

- OnHeartBeat: `aa_0061fdf0` `CVOGHBSkill_Virus_OnHeartBeat` (WQ9R-B dual)
- Intermediate base: `FUN_00618180` (not OWN)
