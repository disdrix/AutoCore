# Function record: Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe640` |
| **Canonical name** | `Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred` |
| **Ghidra name** | `FUN_007fe640` |
| **Address** | `0x007fe640` |
| **Body range** | `0x007fe640` – `0x007fe710` exclusive (**209 B** / `0xD1`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host / CNDHash (stamp family **00a2c2e4**; field **owner+0x3084**) |
| **Calling convention** | stdcall; Stack[0x4]=owner*; void; **`RET 4`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-D 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| **Dual B** | `reviews/B_aa_007fe640_Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9I-D) |

## Alias

- Ghidra: `FUN_007fe640`
- Reject: `Named_VOG_DEBUG_STOP_007fe640` (assert string only)
- Related: sole recreate caller of `CNDHash_Recreate_00a2c2e4` with **BL=2**

## Purpose

Traverse all ordered entries of the host CNDHash at **`owner+0x3084`**, invoke per-object teardown vfuncs, unlock, then **recreate** the hash with **log2=2** (matches host ctor seed).

## Signature

```c
// stdcall; RET 4
void Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred(void* owner /*Stack[0x4]*/);
// Recreate handoff: EAX = *(owner+0x3084); BL = 2
```

## Behavioral summary

1. Early-out if `*(owner+0x3084) == 0`.
2. Soft TraversalLock assert @ hash+0x1d; set lock = 1.
3. Ordered walk: head `hash+0x14`, next `node+0x20`, payload `node+0xc`.
4. Per object: `vtbl+0x3d8` → maybe `vtbl+0x440`; if `obj+0x2b0`: secondary `vtbl+0xb0(obj)`.
5. Unlock @+0x1d; `CNDHash_Recreate_00a2c2e4` (EAX/BL=2).

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_007a4480` (log); `CNDHash_Recreate_00a2c2e4` (`0x004195d0`, dualed WQ9H-E) |
| **Callers** | `FUN_00934880` @ `0x009348bc`; `FUN_009349b0` @ `0x009349d4` |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.md`
- Annotated: `docs/reconstruction/raw/aa_007fe640_FUN_007fe640.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_007fe640.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_007fe640_FUN_007fe640.md`
- Report: `docs/agents/task-dual-ab-0040a6e0-007fe640-wq9id-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + lock/walk/teardown/unlock/recreate order | **High** |
| EAX/BL recreate handoff (bytes) | **High** |
| Host field +0x3084 chain with ctor | **High** |
| stdcall RET 4 | **High** |
| Product host / vtbl English | **Inferred / open** |
| Runtime / bit-exact | **Open** |
