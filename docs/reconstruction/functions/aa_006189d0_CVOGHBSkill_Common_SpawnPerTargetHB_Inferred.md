# Function record: CVOGHBSkill_Common_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006189d0` |
| **Canonical name** | `CVOGHBSkill_Common_SpawnPerTargetHB_Inferred` |
| **Ghidra name** | `FUN_006189d0` |
| **Address** | `0x006189d0`–`0x00618be2` (Ghidra body; **530 B** / `0x212`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Parent dual** | `0x00618180` `CVOGHBSkill_Common_ctor` (not edited) |
| **Partition** | R12-040 / `WAVE_2026-08-05_r12_residual_partition_map.md` |
| **Completion status** | **dual A/B accept-with-gaps** (R12-040) |
| **Bit-for-bit / runtime / diff** | Open — **never Runtime Confirmed** |
| **Dual date** | `2026-08-05` |
| **Dual start** | 2646 |
| **Terminal** | **false** |

## Alias

- Ghidra: `FUN_006189d0`
- Scaffold: `aa_006189d0_FUN_006189d0` (superseded for product claim)
- Role labels: Common Execute / multi-target HB spawn / vtbl+0x2c fanout

## Purpose

Virtual method on RTTI class **`CVOGHBSkill_Common`** at **vtbl+0x2c** (`PTR_FUN_009e1f2c` slot @ `0x009e1f58`). For each **0x10-stride** target-table entry until sentinel `(-1,-1,type0)`:

1. Chance-gate via `FUN_00589b80(skill+0xe4, rngSlice[i])` using `Rng_CloneSeededTable_Inferred(seed)`.
2. Resolve TFID with `CVOGReaction_ResolveObjectTarget` (`ECX=*(world+0xe4e8)`).
3. `operator_new(0x6d0)` → `CVOGHBSkill_Common_ctor(..., flag=0, scale=1.0f)`.
4. Owner null → scalar dtor; else `CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`.
5. Unless self-target: emit object events **0x14** (to target) and **0x15** (to source) via vtbl+0x238.

Returns **true** if any child HB was successfully started.

## Signature

```c
// virtual __thiscall — ECX = CVOGHBSkill_Common* this (unused in body)
// 6 stack args; ret 0x18; EAX = bool (spawnCount != 0)
bool CVOGHBSkill_Common_SpawnPerTargetHB_Inferred(
    CVOGHBSkill_Common *this,
    void *pSourceObj,
    void *pSkillBlob,
    void *pWorld,
    TargetEntry *pTargetTable,  // stride 0x10; sentinel {-1,-1,0}
    void *pTfid16,
    uint32_t rngSeed);
```

## Sealed facts

| Fact | Level |
|---|---|
| Class RTTI `.?AVCVOGHBSkill_Common@@` | **Confirmed** |
| DATA install vtbl+0x2c @ `0x009e1f58` | **Confirmed** |
| Body bounds + `ret 0x18` + `setne` bool return | **High** |
| Child size `0x6d0` + Common_ctor `0x00618180` | **High** |
| Resolve thiscall world+0xe4e8; list world+0xe4ec | **High** |
| Events 0x14/0x15 via vtbl+0x238 | **High** (opcodes sealed) |
| Method product English / PDB | **Inferred** / Open |
| Runtime Confirmed | **Rejected** (Terminal false) |

## Artifacts

- Raw (+ R12 append): `docs/reconstruction/raw/aa_006189d0_FUN_006189d0.md`
- Annotated: `docs/reconstruction/raw/aa_006189d0_FUN_006189d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006189d0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_006189d0_FUN_006189d0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_006189d0_CVOGHBSkill_Common_SpawnPerTargetHB_Inferred.md`
- Report: `docs/agents/task-dual-ab-006189d0-r12-report.md`

## Callers / callees

**Callers:** vtbl dispatch only (no UNCONDITIONAL_CALL).

**Callees:** see scaffold record / dual report.

## Confidence

| Claim | Level |
|---|---|
| CF sealed | **High** |
| Class Confirmed | **Confirmed** |
| Name `_Inferred` | Required — method English open |
| Port-safe ABI | **High** |
