# Function record: FUN_005ebf00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf00` |
| **Canonical name** | `FUN_005ebf00` |
| **Inferred name** | `VOGPhysics_SphereQueryCollect_Dtor_Inferred` |
| **Address** | `0x005ebf00`–`0x005ebf67` (104 B / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Completion status** | **Dual sealed (R12-038)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Complete-object destructor for the dualed **sphere query collect** type: releases the `+0xC0` collect triad, then tail-jumps base dtor `FUN_006343d0`.

## Signature

```c
void __thiscall FUN_005ebf00(uint32_t *self /* ECX */);
// no stack args; ends in JMP FUN_006343d0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.md`
- Annotated: `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005ebf00.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Dtor_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md`
- Dual A/B: `reviews/A|B_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md`
- Report: `docs/agents/task-dual-ab-005ebf00-r12-report.md`

## Callers / callees

| Direction | Target |
|---|---|
| Caller | `FUN_005ebf70` @ `0x005ebf73` (scalar-deleting dtor) |
| Callee | per-element vcall `+0x14`; allocator free tag `0x12`; tail `FUN_006343d0` |

## Confidence

| Claim | Level |
|---|---|
| CF / thiscall / triad offsets / tail JMP | **High** |
| Sphere-collect dtor identity (vtbl `009dce90`) | **High** |
| Product English / element type / runtime | **Open** |
