# Function record: CVOGHBSkill_KillCharge_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006223c0` |
| **Canonical name** | `CVOGHBSkill_KillCharge_Ctor` |
| **Ghidra name** | `FUN_006223c0` |
| **Address** | `0x006223c0`–`0x006223f3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | **Confirmed** class (RTTI); **High** ctor role |
| **Completion status** | **Dual residual sealed 2026-08-05 R11-019** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Construct a **`CVOGHBSkill_KillCharge`** heartbeat object: call parent **`CVOGHBSkillBase_ctor`** with the six stack args, install vtbl **`PTR_FUN_009d16e4`**, return `this`. No additional field stores.

## Signature

```c
void* __thiscall CVOGHBSkill_KillCharge_Ctor(
    void *thisHb,
    void *pCaster, void *pSkillBlob, void *pWorldOrCtx,
    void *pTarget, void *pTfidBlob, uint32_t arg7);
// ret 0x18; EAX = this
// pure KillCharge size 0x6c0 (peer factory); sole CALL may alloc 0x6d0 for subclass
```

## Sealed facts

| Claim | Confidence |
|---|---|
| RTTI `.?AVCVOGHBSkill_KillCharge@@` | **Confirmed** |
| Vtbl `PTR_FUN_009d16e4` | **Confirmed** |
| ABI thiscall / 6 stack / `ret 0x18` | **High** |
| Base `CVOGHBSkillBase_ctor` `0x005788d0` | **High** |
| Sole CALL from `FUN_00622f70` | **High** |
| Product design English | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006223c0_FUN_006223c0.md`
- Annotated: `docs/reconstruction/raw/aa_006223c0_FUN_006223c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_KillCharge_Ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_006223c0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md`, `B_aa_006223c0_CVOGHBSkill_KillCharge_Ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_006223c0_FUN_006223c0.md`

## Related

- Parent base: `CVOGHBSkillBase_ctor` `0x005788d0` (partition parent)
- Sole CALL / subclass factory: `FUN_00622f70` → CommonCastOnDeath vtbl `009d1744` (residual)
- Peer pure-KillCharge factory: `FUN_006226a0` (R11-020 OWN — not dualled here)
