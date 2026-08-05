# Function record: Object_CollectAllGraphicsPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1ff0` |
| **Canonical name** | `Object_CollectAllGraphicsPreloads` (plate-backed) |
| **Ghidra name** | `FUN_004f1ff0` |
| **Address** | `0x004f1ff0` |
| **Body** | `0x004f1ff0`–`0x004f2531` exclusive (**1345 B** / `0x541`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object graphics preload collection |
| **Completion status** | **Dual-reviewed** W32-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Profile-bracketed (`CollectAllGraphicsPreloads`) collector that builds object path-stem (`this+0x188`) + fixed suffixes, existence-gates files, and enqueues hits into the preload guarded vector. Type/`kind` branches select turret / fork / dual-tread geo+anm packs. Tail always runs residual collectors `FUN_004eb3b0` and optionally `FUN_004a04f0(param_2,1,0,0)` when `this+0x88 ≠ 0` (mission-media map walk → `MissionHost_CollectMediaPreloads_Inferred`).

## Signature

```c
// ECX = object host (MOV EBP,ECX). RET 0x4. void.
void __thiscall Object_CollectAllGraphicsPreloads(void* self, uint32_t param_2);
```

## Suffix constants (sealed)

| Suffix | Address |
|---|---|
| `_tint.dds` | `0x009cd060` |
| `_tur.geo` | `0x00a67574` |
| `_frkt.geo` | `0x009cd010` |
| `_frkb.geo` | `0x009cd004` |
| `_trdleft.geo` | `0x009cd050` |
| `_trdleft_ai.anm` | `0x009cd040` |
| `_trdright.geo` | `0x009cd030` |
| `_trdright_ai.anm` | `0x009cd01c` |

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004f2540` @ `0x004f25e6`; `FUN_004f26e0` @ `0x004f273e` |
| Callees | timer pair `0076cf00`/`0076cef0`; exists pair `007b6a20`/`007b6730`; enqueue `00989e00`+`0043d670`; `GameData_LookupCloneBaseByCbid` (`00404d70`); `004f1e20`; `004eb010`; `004eb3b0`; `004a04f0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.md`
- Annotated: `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_CollectAllGraphicsPreloads.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004f1ff0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md`
- Review B: `docs/reconstruction/reviews/B_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md`
- Scaffold record: `docs/reconstruction/functions/aa_004f1ff0_FUN_004f1ff0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (decompile ≡ live) | **High** |
| ABI ECX + RET 0x4 | **High** |
| Plate name | **High** |
| Suffix / type-gate CF | **High** |
| Type `0x0e`/`0x12` product English | **Low** |
| Nested residual collectors | **Open** (not OWN) |

## Rejected plates

- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0` (scaffold chain).
