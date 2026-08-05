# Function record: FUN_005accf0 (scaffold twin)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005accf0` |
| **Canonical name** | `CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred` (see named record) |
| **Ghidra name** | `FUN_005accf0` |
| **Address** | `0x005accf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CrazyTaxi objective time-budget |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W30-M 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Accumulate CrazyTaxi leg time: distance/scale × TimeLimit Percent (+ optional 5.0f).

## Signature (sealed)

```c
float __thiscall FUN_005accf0(
    void *this, void *actor, int stopsKey,
    float acc, int fromIndex, int toIndex);
// RET 0x14
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.md`
- Annotated: `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_005accf0.cpp`
- Reviews: `A_/B_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md`
- Report: `docs/agents/task-dual-ab-005aed20-005accf0-w30m-report.md`

## Callers / callees

- Callees: `FUN_004bb1c0`, `FUN_005ae050`, `SQRT`, actor vtbl+0x1a0
- Callers: **none static**

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI ret 0x14 | **High** |
| CrazyTaxi layout | **High** |
| Product English name | Inferred |
| Static callers | None found |
