# Function record: CLoadNode_WaitAssPreloadKeyRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6ad0` |
| **Canonical name** | `CLoadNode_WaitAssPreloadKeyRing_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_005c6ad0` |
| **Address** | `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CLoadNode stage cooperative wait + AssPreloader key ring |
| **Completion status** | **Dual-reviewed** W36-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

One cooperative wait tick for a CLoadNode stage's asset key ring: ExpandDeps when counter outside 1..6 (and AssPreloader live), then `ProcessKeyRingStep` with progress_flag=1 and host cursor. Yield **3** or ready **0**.

## Signature

```c
// __thiscall; RET 0x4; EAX 0/3
uint32_t CLoadNode_WaitAssPreloadKeyRing_Inferred(
    void* host /*ECX*/,
    GuardedVectorHeader* ring /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX; counter@+0x54, cursor@+0x5c | **High** |
| ring | stack; size@+0x10 | **High** |
| return | EAX 0 ready / 3 wait | **High** |

## Callers

| Caller | Ring context |
|---|---|
| `FUN_005c72f0` `_initPreload` | clonebase path **+0x174** |
| `FUN_005c7400` | anim-stage |
| `FUN_005c76f0` `_initPhysics` | **+0x14c** |
| `FUN_005c78a0` | full-stage |
| `FUN_005c79f0` | further stage |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005c6ad0.cpp` |
| Review A/B | `docs/reconstruction/reviews/A_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md`, `B_…` |
