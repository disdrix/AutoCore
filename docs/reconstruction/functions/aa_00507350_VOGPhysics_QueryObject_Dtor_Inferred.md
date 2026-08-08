# Function record: VOGPhysics_QueryObject_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507350` |
| **Canonical name** | `VOGPhysics_QueryObject_Dtor_Inferred` |
| **Ghidra name** | `FUN_00507350` |
| **Address** | `0x00507350`–`0x005073bd` inclusive (**110 B** / `0x6E`); exclusive end `0x005073be` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | R13-028 |
| **Parent dual** | `0x00581190` `VOGPhysics_QueryObject_SubInit_Inferred` (R12-027) |
| **Dual start** | 2686 |
| **Terminal** | **false** |
| **Completion status** | Dual A/B **accept-with-gaps** (2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open. **Never** Runtime Confirmed this wave. |

## Purpose

Body dtor for the query-object header SubInit constructs under provisional vtbl `PTR_FUN_009cd99c`:

1. Install provisional vtbl `009cd99c`.
2. Release `linked_obj*` @ `+0x0C` (refcount short @ linked `+0x06`; zero → `vtbl[0](1)`).
3. If capacity @ `+0x38` signed ≥ 0: pool-free buffer @ `+0x30`, size `(cap & 0x7FFFFFFF)*8`, tag `0x12` via `(*DAT_00b05060)[+0x14]`.
4. Install mid vtbl `009d81e8`; if flag word @ `+0x04` high bit set → clear low 15 bits + `FUN_005ffdb0(this, 0)`.
5. Install base vtbl `009cc290`; return.

## Signature

```c
void __thiscall VOGPhysics_QueryObject_Dtor_Inferred(uint32_t *self /* ECX */);
// RET 0
```

## Layout (sealed offsets)

| Off | Role |
|----:|---|
| +0x00 | vtbl (provisional → mid → base) |
| +0x04 | ushort flag/size word (high bit owns flag-clear path) |
| +0x06 | self refcount (SubInit seeds 1; not touched here) |
| +0x0C | linked_obj* |
| +0x30 | buffer pointer |
| +0x38 | capacity (empty sentinel `0x80000000`) |

## Call graph

```text
FUN_005073f0  scalar deleting  ──┐
FUN_005074d0  derived dtor     ──┼─► VOGPhysics_QueryObject_Dtor_Inferred (0x00507350)
FUN_006343d0  derived dtor     ──┘         ├─ release linked @ +0x0C
                                           ├─ pool free buffer @ +0x30 / tag 0x12
                                           └─ FUN_005ffdb0(this, 0) if flag@+4 high

VOGPhysics_QueryObject_SubInit_Inferred (0x00581190)  [R12-027 dualed]
  └─ same provisional vtbl 009cd99c / layout through +0x38
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00507350_FUN_00507350.md` |
| Annotated | `docs/reconstruction/raw/aa_00507350_FUN_00507350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00507350.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00507350_VOGPhysics_QueryObject_Dtor_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00507350-r13-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / body span / RET 0 | High |
| Linked release + pool free + vtbl cycle | High |
| Pair with SubInit `00581190` | High (shared vtbl + layout) |
| Product English / RTTI class name | Open → `_Inferred` |
| Runtime Confirmed | **Not claimed** |
