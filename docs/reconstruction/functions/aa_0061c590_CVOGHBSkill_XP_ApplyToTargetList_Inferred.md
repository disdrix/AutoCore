# Function record: CVOGHBSkill_XP_ApplyToTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c590` |
| **Canonical name** | `CVOGHBSkill_XP_ApplyToTargetList_Inferred` |
| **Prior** | `FUN_0061c590` |
| **Address** | `0x0061c590`–`0x0061c6af` (288 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` (COL `0x00aade00` → type_info `0x00af29ec` on vtbl `PTR_FUN_009d119c`) |
| **Name confidence** | Class **Confirmed**; method role **Inferred** (multi-target apply/arm; no PDB) |
| **Completion status** | Named + dual A/B accept 2026-08-05 (R11-015) |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Walk a **sentinel-terminated 0x10-byte TFID row table**. For each row that resolves to a live object, construct a **`CVOGHBSkill_XP`** heartbeat (`operator_new(0x6c0)` + `CVOGHBSkillBase_ctor` + XP vtbl), force always-ready period (`SetPeriodAndCounter(-1000,true)` after copying skill pulse to `HB+0x08`), then **Enqueue+Start** on `world+0xe4ec` if ValidateTarget attached an owner, else **scalar-delete**.

## Signature (image-sealed)

```c
// ret 0x18; EAX = 1
uint32_t CVOGHBSkill_XP_ApplyToTargetList_Inferred(
    void *pSourceObj,
    void *pSkillBlob,     // [+0x1c] → child HB +0x08
    void *pWorld,         // +0xe4e8 resolve ctx; +0xe4ec HB list; also ctor arg4
    void *pTfidRows,      // 0x10-byte records
    void *pTfid16,
    uint32_t arg7);
```

## Sealed facts

| Fact | Level |
|---|---|
| Body bounds + `ret 0x18` + return 1 | **Confirmed** |
| Vtbl install `009d119c`; slot +0x2C self-ref | **Confirmed** |
| Base `CVOGHBSkillBase_ctor` `005788d0` | **Confirmed** |
| Resolve thiscall ctx `*(world+0xe4e8)` | **Confirmed** (bytes; decompiler omit) |
| Enqueue `*(world+0xe4ec)` + Start | **Confirmed** |
| Size `0x6c0`; period `-1000,true` | **Confirmed** |
| No UNCONDITIONAL_CALL callers; DATA-only vtbl | **Confirmed** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0061c590_FUN_0061c590.md` (+ R11-015 append)
- Annotated: `docs/reconstruction/raw/aa_0061c590_FUN_0061c590.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_ApplyToTargetList_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0061c590.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred.md`
- Report: `docs/agents/task-dual-ab-0061c590-r11-report.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061c590_FUN_0061c590.md`

## Callers / callees

- **Callers:** none by CALL; **DATA** from `0x009d11c8` (vtbl+0x2C).
- **Callees:** `operator_new`, `CVOGHBSkillBase_ctor`, `CVOGReaction_ResolveObjectTarget`, `CVOGHBBase_SetPeriodAndCounter`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, vtbl[0] dtor.
- **Parent (not owned):** `0x005788d0` `CVOGHBSkillBase_ctor`.

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High / Confirmed** |
| Class RTTI | **Confirmed** |
| Method product English | **Inferred** |
| Types of pSource/pTfid16/arg7 beyond base plate | Tentative |
