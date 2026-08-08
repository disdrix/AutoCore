# Function record: CVOGHBSkill_XP_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061c940` |
| **Canonical name** | `CVOGHBSkill_XP_OnHeartBeat_Inferred` |
| **Prior** | `FUN_0061c940` |
| **Address** | `0x0061c940`–`0x0061caf0` (**433 B** / `0x1B1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` (COL `0x00aade00` → type_info `0x00af29ec` on vtbl `PTR_FUN_009d119c`) |
| **Name confidence** | Class **Confirmed**; method role **Inferred** (thin OnHeartBeat / vtbl+0x0C; no PDB) |
| **Completion status** | Named + dual A/B accept 2026-08-05 (R12-004) |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Specialized **`CVOGHBSkill_XP` OnHeartBeat** (vtbl **+0x0C**). Casts skill source (`this+0x18`) to **`CVOGCharacter`**. Branches on **`character+0xcb0`**:

| Arm | Condition | Action |
|---|---|---|
| Personal | `*(character+0xcb0) == null` and `float(this+0x104) != 0` | `operator_new(0x6d0)` + **`CVOGHBSkill_XPAdder_ctor`** with **target = source** |
| Multi / convoy | `*(character+0xcb0) != null` | For **i = 0..3**, `FUN_00574760(table, i)`; non-null slots → MI-adjust target → spawn XPAdder |

Accept polarity: `pOwnerObject != null` → **`CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`**; else **vtbl[0](1)**. Tail: **`Skill_HB_RescheduleStatus_Inferred`**; return `pOutStatus`.

## Signature (image-sealed)

```c
// ret 0x04; EAX = pOutStatus
uint32_t * __thiscall CVOGHBSkill_XP_OnHeartBeat_Inferred(
    void *thisHb,          // ECX — CVOGHBSkill_XP
    uint32_t *pOutStatus); // stack
```

## Sealed facts

| Fact | Level |
|---|---|
| Body bounds + `ret 0x04` + return `param_2` | **Confirmed** |
| Vtbl DATA sole inbound at +0x0C (`009d11a8`) | **Confirmed** |
| Class RTTI `CVOGHBSkill_XP` | **Confirmed** |
| Alloc **0x6d0** + ctor `00650f50` XPAdder | **Confirmed** |
| Enqueue list `world+0xe4ec` | **Confirmed** |
| Slot loop bound **4**; helper `00574760` | **Confirmed** |
| Tail `005787a0` RescheduleStatus | **Confirmed** |
| Method product English OnHeartBeat | **Inferred** |
| Runtime | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0061c940_FUN_0061c940.md` (+ R12-004 append)
- Annotated: `docs/reconstruction/raw/aa_0061c940_FUN_0061c940.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_OnHeartBeat_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_0061c940.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0061c940_CVOGHBSkill_XP_OnHeartBeat_Inferred.md`
- Report: `docs/agents/task-dual-ab-0061c940-r12-report.md`
- Scaffold record: `docs/reconstruction/functions/aa_0061c940_FUN_0061c940.md`

## Callers / callees

- **Callers:** none by CALL; **DATA** from `0x009d11a8` (XP vtbl+0x0C).
- **Callees:** `__RTDynamicCast`, `operator_new`, `CVOGHBSkill_XPAdder_ctor` (`0x00650f50`), `FUN_00574760`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, `Skill_HB_RescheduleStatus_Inferred` (`0x005787a0`), vtbl[0] dtor.
- **Parent (context, not owned):** `0x0061c590` `CVOGHBSkill_XP_ApplyToTargetList_Inferred` (sibling vtbl+0x2C arm).

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High / Confirmed** |
| Class RTTI | **Confirmed** |
| Method product English | **Inferred** |
| `+0xcb0` product noun (convoy/party) | Medium / Tentative |
| Runtime | **Open** |

## Gaps

1. PDB method name for vtbl+0x0C.
2. Product English for `character+0xcb0` and float `this+0x104`.
3. Full identity of `FUN_00574760` host type beyond 4-slot getter.
4. Runtime / bit-exact / differential.
