# Function record: CVOGHBSkill_Common_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00618180` |
| **Canonical name** | `CVOGHBSkill_Common_ctor` |
| **Prior** | `FUN_00618180` |
| **Address** | `0x00618180` |
| **Body range** | `0x00618180`–`0x00618265` inclusive (**230 B** / `0xE6`); Ghidra meta end `00618267` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Parent** | `CVOGHBSkillBase_ctor` @ `0x005788d0` |
| **Name confidence** | **Confirmed** class via RTTI `".?AVCVOGHBSkill_Common@@"`; ctor role **High** |
| **Completion status** | Named + dual A/B sealed 2026-08-05 (R11-014) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run); Terminal **false** |

## Purpose

Construct `CVOGHBSkill_Common` heartbeat action: call skill-base ctor, install Common vtbl `PTR_FUN_009e1f2c`, seed Common-tail (`+0x6c0` byte, `+0x6c4` float, `+0x6c8=0`), optionally rescale/clamp period when remaining UI seconds exceed **30.0f** and a target-side gate holds.

## Signature (machine + dual)

```c
CVOGHBSkill_Common* __thiscall CVOGHBSkill_Common_ctor(
    CVOGHBSkill_Common *this,  // ECX
    void *pSourceObj,
    void *pSkillBlob,
    uint32_t arg4,
    void *pTarget,
    void *pTfid16,
    uint32_t arg7,
    uint8_t commonFlag,   // this+0x6c0
    float commonScale);   // this+0x6c4 — NOT int (movss)
// ret 0x20; EAX = this
```

## Sealed layout (this unit)

| Offset | Field (working) | Confidence |
|-------:|-----------------|------------|
| `+0x00` | vtbl `PTR_FUN_009e1f2c` | **Confirmed** |
| `+0x08` | `nPeriodMs` (may set 30000) | **Confirmed** |
| `+0x0C` | `nPeriodSentinel` (read; `>1` → rescale) | **Confirmed** |
| `+0x44` | skill-blob gate byte | **High** |
| `+0x6c0` | Common flag (byte arg) | **Confirmed** |
| `+0x6c4` | Common scale (float arg) | **Confirmed** |
| `+0x6c8` | zeroed dword | **Confirmed** |

Object size: **`0x6d0`** at direct allocators; Virus subclass **`0x6e0`**.

## Sealed control flow

```
CVOGHBSkillBase_ctor(this, p2..p7)
this.vtbl = PTR_FUN_009e1f2c
this[+0x6c0] = commonFlag
this[+0x6c4] = commonScale   // float
this[+0x6c8] = 0
if (this[+0x44] && pTarget && *(pTarget+0xa4) && *(*(pTarget+0xa4)+0xf6)):
    if GetRemainingSeconds(this) > 30.0f:
        if this[+0x0C] > 1:
            SetPeriodAndCounter(this, 30000/this[+0x08], true); return this
        this[+0x08] = 30000
return this
```

## RTTI

| Item | Value |
|---|---|
| Vtbl | `0x009e1f2c` |
| COL | `0x00ab1820` |
| type_info | `0x00af2918` |
| Name | `.?AVCVOGHBSkill_Common@@` |

## Artifacts

- Raw (+ R11 append): `docs/reconstruction/raw/aa_00618180_FUN_00618180.md`
- Annotated: `docs/reconstruction/raw/aa_00618180_FUN_00618180.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Common_ctor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00618180.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00618180_CVOGHBSkill_Common_ctor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00618180_CVOGHBSkill_Common_ctor.md`
- Report: `docs/agents/task-dual-ab-00618180-r11-report.md`

## Callers / callees

- **Callees:** `CVOGHBSkillBase_ctor` (`0x005788d0`), `CVOGHBBase_GetRemainingSeconds` (`0x00508280`), `CVOGHBBase_SetPeriodAndCounter` (`0x005081a0`)
- **Callers (named, 12):** `FUN_006189d0`, `FUN_0061c090`, `FUN_0061cdc0`, `FUN_0061dfc0`, `FUN_0061e2a0`, `FUN_0061f140`, `FUN_0061f940` (`CVOGHBSkill_Virus_Ctor`), `FUN_0061fa40`, `FUN_00620190`, `FUN_006238a0`, `FUN_00623f10`, `FUN_00625fe0`
- **Xrefs:** 15 UNCONDITIONAL_CALL (extra sites `0x0061bbca`, `0x0062314a`, `0x00625c7a`)

## Confidence

| Claim | Level |
|---|---|
| Product class name from RTTI | **Confirmed** |
| Ctor CF / ABI / vtbl install | **High** |
| Float scale @ +0x6c4 | **Confirmed** |
| Period 30s clamp/rescale | **High** |
| Gate/field product English | Tentative / open |
| Runtime Confirmed | Not claimed |
