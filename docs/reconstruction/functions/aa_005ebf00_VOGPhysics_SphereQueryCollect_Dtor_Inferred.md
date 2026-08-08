# Function record: VOGPhysics_SphereQueryCollect_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebf00` |
| **Canonical name** | `VOGPhysics_SphereQueryCollect_Dtor_Inferred` |
| **Ghidra name** | `FUN_005ebf00` |
| **Address** | `0x005ebf00`–`0x005ebf67` (104 B / `0x68`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Paired ctor** | `0x005ebec0` `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| **Completion status** | **Dual sealed (R12-038)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
void __thiscall VOGPhysics_SphereQueryCollect_Dtor_Inferred(
    uint32_t *self /* ECX */);
// no stack args; retail ends in JMP FUN_006343d0 (base dtor)
// Object size: 0xD0 (base 0xC0 + collect triad @ +0xC0)
```

## Semantics (sealed)

```text
SphereQueryCollect_Dtor(self):
  *self = PTR_FUN_009dce90                 // reinstall derived vtbl
  for i = count(+0xC4)-1 .. 0:
    entry_obj = *(obj**)(begin(+0xC0) + i*8)
    vcall(entry_obj, slot +0x14)           // release
  count(+0xC4) = 0
  if capacity(+0xC8) >= 0:
    free(begin, (cap & 0x7fffffff)*8, tag 0x12)  // DAT_00b05060 vtbl+0x14
  JMP FUN_006343d0(self)                   // base query dtor
```

## Naming rationale

- Family: pairs dualed `VOGPhysics_SphereQueryCollect_Ctor_Inferred` (`aa_005ebec0`).
- Role: **complete-object dtor** (not scalar-deleting — that is residual `FUN_005ebf70`).
- Evidence: reinstalls same vtbl `009dce90`; tears down same `+0xC0` triad ctor empty-inits.
- `_Inferred`: product/PDB class English for vtbl `009dce90` open (DATA xrefs = ctor + this dtor only).

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.md` |
| Annotated | `docs/reconstruction/raw/aa_005ebf00_FUN_005ebf00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ebf00.cpp` |
| FUN record | `docs/reconstruction/functions/aa_005ebf00_FUN_005ebf00.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005ebf00_VOGPhysics_SphereQueryCollect_Dtor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005ebf00-r12-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI thiscall / no stack args / tail JMP | **High** |
| Collect triad +0xC0 walk/free / stride 8 / tag 0x12 | **High** |
| Pair with sphere collect ctor vtbl `009dce90` | **High** |
| Distinct from scalar dtor / base dtor / sibling vtbl | **High** |
| Product English / element type / runtime | **Open** |
