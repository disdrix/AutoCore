# Function record: CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006226a0` |
| **Canonical name** | `CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred` |
| **Ghidra name** | `FUN_006226a0` |
| **Address** | `0x006226a0`–`0x006227a7` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Name confidence** | Class **Confirmed** (RTTI); method role **Inferred** (no product string) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (R11-020)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open. Terminal **false**. |

## Purpose

Multi-target spawn path for **`CVOGHBSkill_OnKill`**: for each non-sentinel entry in a 16-byte target table, resolve the object, construct and arm a new OnKill skill heartbeat on the world HB list.

## Signature

```c
uint32_t __thiscall CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred(
    CVOGHBSkill_OnKill* this,  // ECX unused
    void* pSourceObj,
    void* pSkillBlob,
    void* pWorld,
    TargetEntry* pTargetTable,
    uint32_t* pTfid16,
    uint32_t arg7);
```

## Artifacts

- Raw / annotated / clean twin / duals / report: see `aa_006226a0_FUN_006226a0.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.cpp`

## Confidence

| Claim | Level |
|---|---|
| Class RTTI OnKill | **Confirmed** |
| vtbl+0x2c install | **Confirmed** |
| Multi-target HB fanout CF | **High** |
| Method English | Tentative |
