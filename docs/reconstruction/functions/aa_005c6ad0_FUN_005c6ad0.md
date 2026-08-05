# Function record: FUN_005c6ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6ad0` |
| **Canonical name** | `CLoadNode_WaitAssPreloadKeyRing_Inferred` (prefer named record) |
| **Ghidra name** | `FUN_005c6ad0` |
| **Address** | `0x005c6ad0`–`0x005c6b3e` exclusive (**110 B** / `0x6E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CLoadNode stage coop-wait + AssPreloader key ring |
| **Completion status** | **Dual-reviewed** W36-F — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Cooperative wait step used by CLoadNode stage inits: if the stage's GuardedVector preload ring is non-empty, optionally ExpandDeps when the retry counter is outside 1..6, then run one AssPreloader key-ring process step. Return **3** to yield the stage, **0** when ready.

## Signature (sealed)

```c
// __thiscall; ECX = load-node host; stack GuardedVector* ring; RET 0x4
// EAX = 0 ready / 3 wait
uint32_t CLoadNode_WaitAssPreloadKeyRing_Inferred(void* host, void* ring);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.md` (+ W36-F append)
- Annotated: `docs/reconstruction/raw/aa_005c6ad0_FUN_005c6ad0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CLoadNode_WaitAssPreloadKeyRing_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005c6ad0.cpp`
- Named record: `docs/reconstruction/functions/aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_005c6ad0_CLoadNode_WaitAssPreloadKeyRing_Inferred.md`, `B_…`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (5 / 6 xrefs) | `FUN_005c72f0`, `FUN_005c7400`, `FUN_005c76f0`, `FUN_005c78a0`, `FUN_005c79f0` |
| Callees | `AssPreloader_ProcessKeyRingStep_Inferred` (`004ed310`); `AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred` (`00971820`) |

## Confidence

| Claim | Level |
|---|---|
| CF decompile ≡ bytes | **High** |
| ECX host + stack ring + RET 4 + EAX 0/3 | **High** |
| Counter +0x54 band 1..6 / cursor +0x5c | **High** |
| Product English for host class | **Inferred** |
| Runtime | **Open** |
