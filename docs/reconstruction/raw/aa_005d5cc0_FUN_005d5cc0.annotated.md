# Annotated low-level: FUN_005d5cc0 → CVOGWaypoint_DoFollowObjectShortcutsUpdate

| Field | Value |
|---|---|
| Stable ID | `aa_005d5cc0` |
| VA | `0x005d5cc0`–`0x005d62fb` (**1596 B** / `0x63C`) |
| System | skills-abilities / waypoint path AI (plate: CVOGWaypoint) |
| Date | 2026-08-05 (MEGA-057 refresh) |
| Ghidra name | `FUN_005d5cc0` |
| Canonical name | `CVOGWaypoint_DoFollowObjectShortcutsUpdate` |
| Evidence | Live decompile + `disassemble_function` + `read_memory` + callers/xrefs |

---

## Machine-level notes

- **ABI:** thiscall; **ECX** = `CVOGWaypoint* this`; no stack args; **void**; **`RET`** (not `RET n`).
- **SEH:** `LAB_009a7110`; scope enter/leave via `FUN_0076cf00` / `FUN_0076cef0`.
- **Plate string (product):** `"CVOGWaypoint::DoFollowObjectShortcutsUpdate"` @ `0x009dace4`.
- **Sole caller:** `CVOGWaypoint_UpdateState` @ `0x005d6300` state case **2** (call site `0x005d6353`).
- Prefer assembly when decompiler conflicts (surface-distance this-arg; operator_delete return).

### Constants (`read_memory`)

| Symbol | VA | Value |
|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `1.0f` |
| `DAT_00a0f70c` | `0x00a0f70c` | `0.2f` (direction-dot threshold) |
| `_DAT_009dace0` | `0x009dace0` | `1e7f` (min-distance init) |

### this offsets

| Off | Role |
|---|---|
| `+0x10` | owner entity |
| `+0x20..+0x2c` | output desired pose (float4) |
| `+0x30` | follow-object TFID |
| `+0x40/+0x44` | active shortcut/path COID lo/hi |
| `+0x48` | secondary path id |
| `+0x4c` | patrol/follow range float |
| `+0x52` | follow target resolved+flagged |
| `+0x53` | within patrol range of follow target |

### Callees (annotated)

| Addr / name | Role here |
|---|---|
| `FUN_0076cf00` / `FUN_0076cef0` | scope enter/leave |
| `Object_ResolveFromTFID` (`0x004bb950`) | resolve follow TFID |
| `__RTDynamicCast` | object → `CVOGPhysicsBase` |
| `Object_GetWorldPositionPtr` (`0x00404c90`) | world pos float* |
| `Object_SurfaceDistance3D_Inferred` (`0x0053e510`) | surface distance owner↔target |
| `FUN_005d5960` | state-1 peer path update (called when path COID valid) |
| `FUN_004d5910` | gather shortcut candidates into local vector |
| `operator_delete` (`0x00489822`) | free candidate vector buffer |
| vtbl `+0x2c` | write/get pose (float3 out) |
| vtbl `+0x10` | path/query along direction |

---

## Pseudocode (annotated; CF ≡ raw)

```c
// thiscall: ECX = CVOGWaypoint* this; void; RET 0
void __thiscall CVOGWaypoint_DoFollowObjectShortcutsUpdate(CVOGWaypoint *this)
{
  // SEH + scope "CVOGWaypoint::DoFollowObjectShortcutsUpdate"
  void *follow = Object_ResolveFromTFID(/* via owner map */ &this->follow_tfid /* +0x30 */);
  if (follow == NULL || ((*(uint*)(follow + 0x17c) >> 5) & 1) == 0) {
    this->flag_follow_valid /* +0x52 */ = 0;
    goto unscope;
  }
  this->flag_follow_valid = 1;

  CVOGPhysicsBase *targetPhys =
    __RTDynamicCast(follow, 0, &CVOGClonedObjectBase_RTTI, &CVOGPhysicsBase_RTTI, 0);

  // target pose float4 (physics rb+0xb0 or entity +0x84 dual)
  float tgt[4] = *GetPose4(targetPhys);
  // owner pose float4 from this->owner (+0x10)
  float own[4] = *GetPose4(this->owner);

  // bytes: ECX=owner, stack=targetPhys  (decompiler residual: single arg)
  float dist = (float)Object_SurfaceDistance3D_Inferred(this->owner, targetPhys);

  this->flag_in_patrol /* +0x53 */ = (this->patrol_range /* +0x4c */ > dist) ? 1 : 0;

  if (dist < 1.0f) {
    // snap desired pose to target
    CopyPose4(this->pose /* +0x20 */, tgt);
    goto unscope;
  }

  // path COID pair valid?
  if ((this->path_coid_lo /* +0x40 */ & this->path_coid_hi /* +0x44 */) != 0xFFFFFFFF) {
    FUN_005d5960(this);  // state-1 peer
    // unit dir: target - owner_world
    // unit dir: saved_pose - owner_world
    // if dot < 0.2f: clear path COIDs +0x40/44/48 to -1; snap pose from owner world
    goto unscope;
  }

  // no path: gather shortcuts around owner pose
  float owner_world[4] = *Object_GetWorldPositionPtr(this->owner);
  vector<void*> candidates; // local_3c/local_38/local_34
  float best = 1e7f;
  FUN_004d5910(/*owner map ctx*/, owner_world, &candidates);

  if (candidates empty) {
    CopyPose4(this->pose, tgt);
  } else {
    void *bestObj = NULL;
    for (each c in candidates) {
      float p[3]; c->vtbl[+0x2c](&p);
      // both (tgt-p) and (p-owner_world) within dist²; track min (tgt-p)²
      if (ok && closer) bestObj = c;
    }
    if (!bestObj) {
      CopyPose4(this->pose, tgt);
    } else {
      // store COID from bestObj+0x134 → +0x40/+0x44 (sign extend)
      // normalize dir owner_world - tgt; vtbl+0x10(-1, dir)
      // set +0x48 from result+0x134 or -1; vtbl+0x2c → this+0x20
    }
  }
  if (candidates.buf) operator_delete(candidates.buf);

unscope:
  FUN_0076cef0();
  return;
}
```

---

## Control-flow summary

```
enter scope
  resolve follow TFID → null/flag? → +0x52=0 → exit
  +0x52=1; cast physics; load poses
  surface dist vs +0x4c → +0x53
  dist < 1 → pose=target → exit
  path COID valid?
    yes → FUN_005d5960; dir-dot gate; maybe clear path → exit
    no  → gather shortcuts → pick nearest → set COIDs/pose
  free vector
exit scope
```

---

## Gaps (annotated)

1. Product English for `FUN_004d5910` (shortcut gather) and `FUN_005d5960` (state-1 peer).
2. Exact class of candidate objects (vtbl `+0x10` / `+0x2c` / `+0x134` COID).
3. Bit meaning of object flag `+0x17c` bit 5 beyond "usable follow target".
4. Runtime / bit-exact / differential — open.
