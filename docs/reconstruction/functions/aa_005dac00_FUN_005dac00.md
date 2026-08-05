# Function record: FUN_005dac00 / CVOGHBRecreateObject_RecreateOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dac00` |
| **Canonical name** | `CVOGHBRecreateObject_RecreateOwner_Inferred` |
| **Ghidra name** | `FUN_005dac00` |
| **Address** | `0x005dac00` |
| **Body range** | `0x005dac00` – `0x005dae45` (582 B, inclusive RET) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat / world-object lifecycle (recreate HB) |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 (CF + ABI + callers + key offsets); product English for vfuncs open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human: `CVOGHBRecreateObject_RecreateOwner_Inferred`
- Former scaffold: `Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_005dac00` (**misleading** — primary callers are recreate HB paths)

## Purpose

Recreate/rebind the HB owner object: dynamic-cast to physics + graphics, refresh pose/orient vcalls, clear soft flag bit0 at layout `+0x181`, apply zero impulse vector, optionally soft-request phys body type, and finish with `FUN_004cd540(..., 1)`.

## Signature (sealed)

```c
// __thiscall; ECX = CVOGHBBase* / CVOGHBRecreateObject*; plain RET; void
void CVOGHBRecreateObject_RecreateOwner_Inferred(void *pHB);
```

| Formal | Source | Conf |
|---|---|---|
| `this` / `pHB` | ECX; `+0x18` = owner | **High** |
| Return | void | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.md`
- Annotated: `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBRecreateObject_RecreateOwner_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005dac00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md`

## Callers / callees

### Callers (2)

| Address | Function | Notes |
|---|---|---|
| `0x005dafba` | `CVOGHBRecreateObject_OnHeartBeat` (`FUN_005dae50`) | when transform helper `local_12c == 0` |
| `0x004cd50c` | `FUN_004cd4e0` | RTTI `CVOGHBRecreateObject` + flag |

### Callees

`__RTDynamicCast`, `FUN_004bcda0`, owner vcall `+0x2a4`, gfx vcalls `+0xfc` / `*vtbl` / `+0xb8` / `+0x100`, `FUN_004e88e0`, `FUN_004e87d0`, phys vcall `+0x10`, `FUN_00560e90`, `FUN_00418d10`, `FUN_0053d970` (`Object_SetPhysBodyTypeIfNotReady_Inferred`), `CVOGPhysics_ApplyImpulseVector`, `FUN_0040d040`, phys vcalls `+0x244`/`+0x240`, `FUN_00516a00`, `FUN_004cd540`.

## Sealed facts

| Fact | Level |
|---|---|
| ECX thiscall; plain RET; void | **Sealed** |
| Owner at `this+0x18`; dual RTTI Physics+Graphics | **Sealed** |
| Require `phys[2] != 0` body host | **Sealed** |
| Clear `*(layout+0x181) &= ~1` | **Sealed** |
| Zero impulse `@DAT_00bc5670` | **Sealed** |
| Soft gate → `FUN_0053d970(0)` | **Sealed** |
| Skip `FUN_00516a00` when type is 0x12 or 0x14 | **Sealed** |
| Callers = recreate HB family only | **Sealed** |

## Gaps

| Gap | Status |
|---|---|
| Product English for vfuncs / `FUN_004cd540` / `FUN_00516a00` | Open |
| Runtime recreate differential | Open |
| PDB / retail name | Open |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Recreate-owner semantic name | **High** (structural) / product English **Tentative** (`_Inferred`) |
| Parameter types beyond HB/owner | **Probable** |
