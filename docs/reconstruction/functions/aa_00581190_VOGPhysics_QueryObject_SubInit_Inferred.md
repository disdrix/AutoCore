# Function record: VOGPhysics_QueryObject_SubInit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581190` |
| **Canonical name** | `VOGPhysics_QueryObject_SubInit_Inferred` |
| **Ghidra name** | `FUN_00581190` |
| **Address** | `0x00581190`–`0x005811e7` (88 B / `0x58`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Completion status** | **Dual sealed (R12-027)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
void __thiscall VOGPhysics_QueryObject_SubInit_Inferred(
    uint32_t *self /* ECX */,
    uint32_t *linked_obj /* stack */,
    uint32_t mode /* stack */);
// RET 8; EAX = self at RET (preserved)
// Writes through +0x38; parent continues query specialization past that range
```

## Semantics (sealed)

```text
SubInit(self, linked_obj, mode):
  self.refcount(+0x06) = 1
  *self = PTR_FUN_009cd99c                 // provisional base vtbl
  self[+0x08] = 0
  self[+0x0C] = linked_obj
  self[+0x10] = 0xFFFFFFFF
  self[+0x14] = 0
  self[+0x18] = 0
  self[+0x1C] = 0
  self[+0x20] = 0
  self[+0x24] = mode                       // parent passes 2
  self[+0x28] = 0
  self[+0x2C] = self
  triad_begin(+0x30/+0x34) = {0, 0}
  triad_cap(+0x38) = 0x80000000
  if linked_obj != null:
    linked_obj.refcount(+0x06)++
  // RET 8; EAX = self
```

## Naming rationale

- Family: `VOGPhysics_QueryObject_*` matches dualed parent `VOGPhysics_QueryObject_BaseCtor_Inferred`.
- Role: **sub-init** only — installs provisional vtbl + header fields; does **not** install query vtbl `009dcde0`, float block, or +0x80 copy (parent does).
- Sole call site is parent with **mode = 2**.
- `_Inferred`: product/PDB class English for vtbl `009cd99c` open (shared with peer dtor/ctor writers).
- Scaffold `Named_CalleeOf_*CVO*00581190` **retired**.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00581190_FUN_00581190.md` |
| Annotated | `docs/reconstruction/raw/aa_00581190_FUN_00581190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryObject_SubInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00581190.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00581190_FUN_00581190.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00581190_VOGPhysics_QueryObject_SubInit_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00581190-r12-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 8 / leaf | **High** |
| Sole caller parent mode-2 path | **High** |
| Offset map / refcount link | **High** |
| Product English / full mode dictionary | **Open** |
| Runtime | **Open** |
