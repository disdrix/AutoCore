# Function record: CVOGHBSkill_OnDoHit_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621350` |
| **Canonical name** | `CVOGHBSkill_OnDoHit_Ctor` |
| **Ghidra name** | `FUN_00621350` |
| **Address** | `0x00621350`–`0x00621383` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** class (RTTI); **High** ctor role |
| **Completion status** | **Dual residual sealed 2026-08-05 R11-017** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Construct a **`CVOGHBSkill_OnDoHit`** heartbeat object: call parent `CVOGHBSkillBase_ctor`, install vtbl **`PTR_FUN_009d15c4`**, return `this`. No extra fields. Intermediate base for further subclass factories.

## Signature

```c
void* __thiscall CVOGHBSkill_OnDoHit_Ctor(
    void *thisHb,
    void *pSourceObj, void *pSkillBlob, uint32_t arg4,
    void *pTarget, void *pTfid16, uint32_t arg7);
// ret 0x18; EAX = this
```

## Sealed facts

| Claim | Confidence |
|---|---|
| RTTI `.?AVCVOGHBSkill_OnDoHit@@` | **Confirmed** |
| Vtbl `PTR_FUN_009d15c4` | **Confirmed** |
| Body base-then-vtbl linear | **High** |
| ABI `ret 0x18` / thiscall | **High** |
| Callers: `FUN_00621f50`, `FUN_006235e0` | **Confirmed** |
| Product design English | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00621350_FUN_00621350.md`
- Annotated: `docs/reconstruction/raw/aa_00621350_FUN_00621350.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnDoHit_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00621350.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md`, `B_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00621350_FUN_00621350.md`
- Report: `docs/agents/task-dual-ab-00621350-r11-report.md`

## Related

- Parent: `aa_005788d0` `CVOGHBSkillBase_ctor`
- Callers (not OWN): `FUN_00621f50`, `FUN_006235e0`
