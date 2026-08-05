# Function record: CVOGHBMissionPatrol_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650d30` |
| **Canonical name** | `CVOGHBMissionPatrol_ctor` |
| **Ghidra name** | `FUN_00650d30` |
| **Address** | `0x00650d30` |
| **Body** | `0x00650d30`–`0x00650dd4` (**164 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / mission-patrol HB |
| **Completion status** | **Dual A/B sealed** — W23-T 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00650d30`
- Scaffold: `Named_CalleeOf_CVOGObjectiveRequirement_Patrol_InitActive_00650d30`
- Family: `CVOGHBMissionPatrol_Fn3` / `Fn6` / `Tick`

## Purpose

In-place construct a **0x40-byte** mission-patrol heartbeat: base HB ctor, install MissionPatrol vftable `PTR_FUN_009e52e4`, copy requirement fields, type **`0xC`**, period sentinel **`-1000`**, optional MI-adjusted owner attach, pulse period **`+0x08 = 1000`**.

## Signature (machine-derived)

```c
void *__thiscall CVOGHBMissionPatrol_ctor(
    void *this /* ECX, pre-alloc 0x40 */,
    void *pOwnerOrNull /* [esp+4] */,
    int *pRequirement /* [esp+8] */);
// callee cleanup: ret 8; returns this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00650d30_FUN_00650d30.md`
- Annotated: `docs/reconstruction/raw/aa_00650d30_FUN_00650d30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBMissionPatrol_ctor.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00650d30.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00650d30_CVOGHBMissionPatrol_ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00650d30_CVOGHBMissionPatrol_ctor.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `CVOGObjectiveRequirement_Patrol_InitActive` | `0x0060e3d0` |
| Callee | `CVOGHBBase_ctor` | `0x00508200` |
| Callee | `CVOGHBBase_SetPeriodAndCounter` | `0x005081a0` |
| Callee | `CVOGHBBase_AttachOwnerObject` | `0x005083b0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from live decompile ≡ raw | **High** |
| Body size / `ret 8` | **Confirmed** (`read_memory`) |
| Vftable `0x009e52e4` MissionPatrol family | **High** |
| Type `0xC`, pulse 1000, sentinel -1000 | **High** |
| Product English class name | **Inferred** (family + sole parent) |
| Requirement field semantics | **Tentative** |

## Dual status

| Review | Verdict |
|---|---|
| A (fidelity) | **accept-with-gaps** |
| B (adversarial) | **accept-with-gaps** |
