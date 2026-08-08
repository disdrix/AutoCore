# Function record: FUN_005ebec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **Canonical name** | `FUN_005ebec0` |
| **Named form** | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| **Address** | `0x005ebec0`–`0x005ebef0` inclusive (**49 B** / `0x31`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-070 OWN-ONLY (parent `0x004ea350` GetObjectsInArea) |
| **Completion status** | **Dual sealed** (A/B **accept**) |
| **Bit-for-bit / runtime / diff** | Open — terminal **false** |

## Purpose

Derived thiscall constructor for the **0xD0 sphere-query collect** object: base-init, install vtbl `009dce90`, empty-init collect triad at `+0xC0`.

## Signature (decompiler-derived, ABI sealed)

```c
uint32_t * __thiscall FUN_005ebec0(uint32_t *self /* ECX */, uint32_t params /* stack */);
// RET 4; EAX = self
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-070 re-verify) | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ebec0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| Named record | `docs/reconstruction/functions/aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005ebec0-mega-070-report.md` |

## Callers / callees

| Direction | Targets |
|---|---|
| Callees | `FUN_005eb210` (base ctor) |
| Callers | `FUN_004ea350` @ `0x004ea770`; `FUN_005dd080` @ `0x005dd368`; factory @ `0x005ebfcf` |
| Xrefs | 3 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler / disasm / bytes | **High** |
| thiscall RET 4 + collect triad | **High** |
| Sphere-query collect ctor role | **High** |
| Product class English | **Open** → use named `_Inferred` form |
| Runtime Confirmed | **Open** |

## Retired scaffolds

- `Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0` — do not use as identity.
