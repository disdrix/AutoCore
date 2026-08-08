# Function record: LthkWorld_GetPenetrations_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560c90` |
| **Canonical name** | `LthkWorld_GetPenetrations_Inferred` |
| **Ghidra name** | `FUN_00560c90` |
| **Address** | `0x00560c90`–`0x00560e33` (420 B / `0x1A4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition parent** | `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` |
| **Completion status** | **Dual sealed (R12-024)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Signature

```c
void __thiscall LthkWorld_GetPenetrations_Inferred(
    void *self /* ECX */,
    void *query_obj /* stack */,
    uint32_t user_ctx /* stack */,
    void *dispatch_table /* stack; null → self+0xCC */);
// RET 0xC
```

## Semantics (sealed)

```text
GetPenetrations(self, query, user_ctx, dispatch):
  profiler_open("LthkWorld::getPenetrations")
  if dispatch == null: dispatch = self[+0xCC]
  shape_extents(query, dispatch)                 // vcall +0x18
  triad = { stack_buf, 0, 0x80000080 }
  broadphase_fill(*(self+0xC4), triad)           // vcall +0x24
  typeA = shape_type(query)                      // vcall +0x14
  profiler("Stnarrowphase")
  for cand in triad (8 B records, ptr+4, -0x10):
    if cand == query: continue
    if !pair_filter(*(self+0xD0)+8, query, cand): continue
    if cand.shape == null: continue
    typeB = shape_type(cand)
    // cdecl:
    dispatch.matrix[typeA][typeB](query, cand, dispatch, user_ctx)
      // matrix base +0x118c; index typeA*0x20+typeB
  profiler_close("lt")
  if triad.capacity high-bit clear:
    alloc_free(triad.begin, (cap&0x7fffffff)*8, tag=0x12)
  // RET 0xC
```

## Naming rationale

- Plate string **`LthkWorld::getPenetrations`** is embedded RDTSC tag — method English **High**.
- Role matches callers: GetObjectsInArea collect hits + HB recreate penetration pass.
- `_Inferred`: product/PDB **class** ownership of `self` (true LthkWorld vs VOG wrapper) still open; method name alone is not full RTTI seal.
- Scaffold `Named_CalleeOf_*VOG_DEBUG_STOP*00560c90` **retired**.
- Prior alias `Named_LthkWorld_getPenetrations` **promoted** to this inferred form.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00560c90_FUN_00560c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00560c90_FUN_00560c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LthkWorld_GetPenetrations_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560c90.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00560c90_FUN_00560c90.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00560c90_LthkWorld_GetPenetrations_Inferred.md` |
| Report | `docs/agents/task-dual-ab-00560c90-r12-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 0xC / 2 callers | **High** |
| Method plate + narrowphase loop | **High** |
| Filter = self+0xD0 (asm vs unaff_EBX) | **High** |
| Product class / full matrix map | **Open** |
| Runtime | **Open** |
