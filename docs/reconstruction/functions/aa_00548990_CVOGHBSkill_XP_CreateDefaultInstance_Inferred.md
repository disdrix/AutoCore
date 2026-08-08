# Function record: CVOGHBSkill_XP_CreateDefaultInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548990` |
| **Canonical name** | `CVOGHBSkill_XP_CreateDefaultInstance_Inferred` |
| **Prior** | `FUN_00548990` |
| **Address** | `0x00548990`–`0x005489e2` (83 B / `0x53`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Class** | **`CVOGHBSkill_XP`** — RTTI **Confirmed** `.?AVCVOGHBSkill_XP@@` (COL `0x00aade00` → type_info `0x00af29ec` on vtbl `PTR_FUN_009d119c`) |
| **Name confidence** | Class **Confirmed**; method role **Inferred** (default factory; no PDB) |
| **Completion status** | Named + dual A/B accept 2026-08-05 (R12-022) |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

**Default-instance factory** for **`CVOGHBSkill_XP`**:

1. `operator_new(0x6c0)` — retail XP heartbeat size (matches parent dual alloc).
2. On non-null: **`CVOGHBSkillBase_DefaultCtor`** (`0x00578830`, thiscall ECX=new) — empty skill-HB shell (Attach null; no blob/period).
3. Install vtbl **`PTR_FUN_009d119c`** (XP subclass).
4. Return instance* or **null**.

Not the multi-target apply/arm path (`0x0061c590`), which uses full **`CVOGHBSkillBase_ctor`** (`0x005788d0`) + pulse/period/Enqueue.

## Signature (image-sealed)

```c
// no stack formals; RET (C3); EAX = CVOGHBSkill_XP* or null
void *CVOGHBSkill_XP_CreateDefaultInstance_Inferred(void);
```

## Sealed facts

| Fact | Level |
|---|---|
| Body bounds + plain `RET` (`C3`) | **Confirmed** |
| Alloc size `0x6c0` | **Confirmed** |
| Base = DefaultCtor `00578830` (not full ctor `005788d0`) | **Confirmed** |
| Vtbl imm `009d119c` | **Confirmed** |
| Class RTTI `CVOGHBSkill_XP` | **Confirmed** |
| Sole inbound = DATA vtbl+0x48 (`009d11e4`) | **Confirmed** |
| Method English CreateDefaultInstance | **Inferred** |

## Artifacts

- Raw (+ R12-022 append): `docs/reconstruction/raw/aa_00548990_FUN_00548990.md`
- Annotated: `docs/reconstruction/raw/aa_00548990_FUN_00548990.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_XP_CreateDefaultInstance_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_00548990.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md`
- Report: `docs/agents/task-dual-ab-00548990-r12-report.md`
- Scaffold record: `docs/reconstruction/functions/aa_00548990_FUN_00548990.md`

## Callers / callees

- **Callers:** none by CALL; **DATA** from `0x009d11e4` (vtbl+0x48).
- **Callees:** `operator_new`, `CVOGHBSkillBase_DefaultCtor`.
- **Parent dual (context, not owned):** `0x0061c590` `CVOGHBSkill_XP_ApplyToTargetList_Inferred` — same class vtbl, different slot/role.

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High / Confirmed** |
| Class RTTI | **Confirmed** |
| Method product English | **Inferred** |
| Types beyond void*/null | Tentative |
