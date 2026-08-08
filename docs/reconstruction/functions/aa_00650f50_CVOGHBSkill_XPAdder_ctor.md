# Function record: CVOGHBSkill_XPAdder_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f50` |
| **Canonical name** | `CVOGHBSkill_XPAdder_ctor` |
| **Prior** | `FUN_00650f50` |
| **Address** | `0x00650f50`–`0x00650f8e` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Name confidence** | **Confirmed** — RTTI `".?AVCVOGHBSkill_XPAdder@@"` via COL on vtbl `PTR_FUN_009e5304` |
| **Completion status** | Dual A/B sealed R11-025 (2026-08-05) — **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Subclass constructor for the XP-adder skill heartbeat. After `CVOGHBSkillBase_ctor`, installs `CVOGHBSkill_XPAdder` vtbl and clears the subclass float residual at `+0x6c0` used by tick/end peers to apply/reverse character XP at `+0xc54`.

## Signature

```c
CVOGHBSkill_XPAdder* __thiscall CVOGHBSkill_XPAdder_ctor(
    CVOGHBSkill_XPAdder* this,   // ECX; operator_new(0x6d0)
    void* pSourceObj,
    void* pSkillBlob,
    uint32_t arg4,
    void* pTarget,
    uint32_t* pTfid16,
    uint32_t arg7);
// RET 0x18; EAX = this
```

## Sealed control flow

```
CVOGHBSkillBase_ctor(this, pSourceObj, pSkillBlob, arg4, pTarget, pTfid16, arg7)
this.vtbl = PTR_FUN_009e5304          // CVOGHBSkill_XPAdder
*(float*)(this+0x6c0) = 0.0f          // MOVSS after XORPS
return this
```

## Artifacts

- Raw (+ append): `docs/reconstruction/raw/aa_00650f50_FUN_00650f50.md`
- Annotated: `docs/reconstruction/raw/aa_00650f50_FUN_00650f50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XPAdder_ctor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00650f50.cpp`
- Dual A/B: `reviews/A|B_aa_00650f50_CVOGHBSkill_XPAdder_ctor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00650f50_FUN_00650f50.md`
- Report: `docs/agents/task-dual-ab-00650f50-r11-report.md`

## Callers / callees

- **Callers:** `FUN_0061c940` (2 UNCONDITIONAL_CALL sites).
- **Callees:** `CVOGHBSkillBase_ctor` @ `0x005788d0`.
- **Family:** one of 14 subclass ctors under base `0x005788d0` (partition parent).

## Confidence

| Claim | Level |
|---|---|
| Product class name from RTTI | **Confirmed** |
| Ctor CF / ABI / float zero | **Confirmed** |
| Object size 0x6d0 | **Confirmed** (caller) |
| Float field English | High (peer) |
| Runtime | Open |
