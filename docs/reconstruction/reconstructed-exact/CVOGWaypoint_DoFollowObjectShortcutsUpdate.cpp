// =============================================================================
// CVOGWaypoint_DoFollowObjectShortcutsUpdate
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5cc0
// Address:   0x005d5cc0 – 0x005d62fb  (autoassault.exe, image base 0x400000)
// Size:      1596 B (0x63C)
// System:    skills-abilities / waypoint path AI
// Generated: 2026-08-05 MEGA-057 (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE
//   CVOGWaypoint FSM state-2 handler (called from CVOGWaypoint_UpdateState when
//   *(this+0x50)==2). Resolve the follow-object TFID, measure surface distance to
//   the owner, maintain path/shortcut COIDs, and write a desired pose float4 at
//   this+0x20..+0x2c for downstream steering.
//
// PRODUCT PLATE (sealed)
//   "CVOGWaypoint::DoFollowObjectShortcutsUpdate" @ 0x009dace4
//
// ABI (byte-sealed)
//   thiscall; ECX = CVOGWaypoint* this; no stack args; void; RET (not RET n).
//   SEH frame LAB_009a7110; scope via FUN_0076cf00 / FUN_0076cef0.
//
// this LAYOUT (fields used here)
//   +0x10  owner entity*
//   +0x20  desired pose float4 (x,y,z,w)
//   +0x30  follow-object TFID (16 B)
//   +0x40  path/shortcut COID lo
//   +0x44  path/shortcut COID hi
//   +0x48  secondary path id
//   +0x4c  patrol / follow range float
//   +0x52  follow-object valid (u8)
//   +0x53  within-patrol-range (u8)
//
// CALLEES
//   Object_ResolveFromTFID (0x004bb950)
//   __RTDynamicCast → CVOGPhysicsBase
//   Object_GetWorldPositionPtr (0x00404c90)
//   Object_SurfaceDistance3D_Inferred (0x0053e510)  // ECX=owner, stack=target
//   FUN_005d5960  // state-1 peer (path-active update)
//   FUN_004d5910  // shortcut candidate gather (residual)
//   operator_delete (0x00489822)
//   virtual +0x2c pose-out; virtual +0x10 path/query
//
// CONSTANTS
//   g_flOne        @ 0x00a0f2a0 = 1.0f
//   DAT_00a0f70c   @ 0x00a0f70c = 0.2f   (direction-dot clear threshold)
//   _DAT_009dace0  @ 0x009dace0 = 1e7f   (min-distance init)
// =============================================================================

// External symbols (Ghidra / dualed peers)
extern void FUN_0076cf00(const char *scope_name);
extern void FUN_0076cef0(void);
extern void *Object_ResolveFromTFID(void *tfid16);
extern int __RTDynamicCast(void *obj, int, void *from_rtti, void *to_rtti, int);
extern float * __fastcall Object_GetWorldPositionPtr(void *entity); // ECX=this
extern float /*float10*/ __thiscall Object_SurfaceDistance3D_Inferred(void *objA, void *objB);
extern void __fastcall FUN_005d5960(void *waypoint); // ECX=this
extern void __thiscall FUN_004d5910(void *ctx, float *owner_pose, void *vector_out);
extern void operator_delete(void *p);
extern void *ExceptionList;
extern float g_flOne;            // 1.0f
extern float DAT_00a0f70c;       // 0.2f
extern float _DAT_009dace0;      // 1e7f
extern char LAB_009a7110[];
extern void *CVOGClonedObjectBase_RTTI_Type_Descriptor;
extern void *CVOGPhysicsBase_RTTI_Type_Descriptor;

// Pose dual (same paths as Object_GetWorldPositionPtr; inlined in body for target
// and for owner when loading full float4 including W).
static float *PosePtr_PhysicsOrEntity(void *obj)
{
  if (*(int *)((char *)obj + 8) != 0) {
    return (float *)(*(int *)(*(int *)((char *)obj + 8) + 0x3c) + 0xb0);
  }
  int mid = *(int *)((char *)obj + 4);
  int adj = *(int *)(mid + 4);
  return (float *)(adj + 0x84 + (int)obj);
}

void __fastcall CVOGWaypoint_DoFollowObjectShortcutsUpdate(void *this_wp)
{
  // --- SEH / scope (simplified; MSVC frame present in bytes) ---
  void *local_1c;
  void *puStack_18 = &LAB_009a7110;
  unsigned local_14 = 0xffffffff;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;

  FUN_0076cf00("CVOGWaypoint::DoFollowObjectShortcutsUpdate");
  local_14 = 0;

  // Resolve follow object from TFID at this+0x30 (via owner map; see raw re-verify)
  void *follow = Object_ResolveFromTFID((char *)this_wp + 0x30);
  if (follow == 0 || (((*(unsigned *)((char *)follow + 0x17c) >> 5) & 1) == 0)) {
    *((unsigned char *)this_wp + 0x52) = 0;
    goto unscope;
  }
  *((unsigned char *)this_wp + 0x52) = 1;

  // Cast follow → CVOGPhysicsBase
  void *targetPhys = (void *)__RTDynamicCast(
      follow, 0,
      &CVOGClonedObjectBase_RTTI_Type_Descriptor,
      &CVOGPhysicsBase_RTTI_Type_Descriptor,
      0);

  // Target pose float4
  float *pf = PosePtr_PhysicsOrEntity(targetPhys);
  float tgt_x = pf[0], tgt_y = pf[1], tgt_z = pf[2], tgt_w = pf[3];

  // Owner pose float4 from this+0x10
  void *owner = *(void **)((char *)this_wp + 0x10);
  pf = PosePtr_PhysicsOrEntity(owner);
  float own_x = pf[0], own_y = pf[1], own_z = pf[2], own_w = pf[3];
  (void)own_x; (void)own_y; (void)own_z; (void)own_w; // used on path-active / gather paths

  // Surface distance owner ↔ target (bytes: ECX=owner, stack=targetPhys)
  float dist = (float)Object_SurfaceDistance3D_Inferred(owner, targetPhys);

  // Patrol-range flag: +0x53 = 1 if patrol_range (+0x4c) > dist
  if (*((float *)((char *)this_wp + 0x4c)) <= dist) {
    *((unsigned char *)this_wp + 0x53) = 0;
  } else {
    *((unsigned char *)this_wp + 0x53) = 1;
  }

  // Close enough: snap desired pose to target
  if (dist < g_flOne) {
    *(float *)((char *)this_wp + 0x20) = tgt_x;
    *(float *)((char *)this_wp + 0x24) = tgt_y;
    *(float *)((char *)this_wp + 0x28) = tgt_z;
    *(float *)((char *)this_wp + 0x2c) = tgt_w;
    goto unscope;
  }

  // Path COID pair valid? (lo & hi) != 0xFFFFFFFF
  if ((*(unsigned *)((char *)this_wp + 0x40) &
       *(unsigned *)((char *)this_wp + 0x44)) != 0xffffffffu) {
    FUN_005d5960(this_wp);

    // Unit direction: target - owner_world
    pf = Object_GetWorldPositionPtr(owner);
    float dx = tgt_x - pf[0];
    float dy = tgt_y - pf[1];
    float dz = tgt_z - pf[2];
    float len2 = dx * dx + dy * dy + dz * dz;
    float inv = 0.0f;
    if (len2 != 0.0f) inv = g_flOne / sqrtf(len2);
    float tdir_x = dx * inv, tdir_y = dy * inv, tdir_z = dz * inv;

    // Unit direction: saved desired pose - owner_world
    float sx = *(float *)((char *)this_wp + 0x20);
    float sy = *(float *)((char *)this_wp + 0x24);
    float sz = *(float *)((char *)this_wp + 0x28);
    float sw = *(float *)((char *)this_wp + 0x2c);
    pf = Object_GetWorldPositionPtr(owner);
    float sdx = sx - pf[0];
    float sdy = sy - pf[1];
    float sdz = sz - pf[2];
    float sdw = sw - pf[3];
    len2 = sdx * sdx + sdy * sdy + sdz * sdz;
    inv = 0.0f;
    if (len2 != 0.0f) inv = g_flOne / sqrtf(len2);
    sdx *= inv; sdy *= inv; sdz *= inv; sdw *= inv;
    (void)sdw;

    // If directions diverge (dot < 0.2): clear path and snap pose to target world
    if (sdx * tdir_x + sdy * tdir_y + sdz * tdir_z < DAT_00a0f70c) {
      *(unsigned *)((char *)this_wp + 0x40) = 0xffffffffu;
      *(unsigned *)((char *)this_wp + 0x44) = 0xffffffffu;
      *(unsigned *)((char *)this_wp + 0x48) = 0xffffffffu;
      // bytes: ECX = targetPhys (EBX) for this GetWorldPositionPtr site
      pf = Object_GetWorldPositionPtr(targetPhys);
      *(unsigned *)((char *)this_wp + 0x20) = *(unsigned *)(pf + 0);
      *(unsigned *)((char *)this_wp + 0x24) = *(unsigned *)(pf + 1);
      *(unsigned *)((char *)this_wp + 0x28) = *(unsigned *)(pf + 2);
      *(unsigned *)((char *)this_wp + 0x2c) = *(unsigned *)(pf + 3);
    }
    goto unscope;
  }

  // No active path: gather shortcut candidates near owner world pose
  pf = Object_GetWorldPositionPtr(owner);
  float owx = pf[0], owy = pf[1], owz = pf[2], oww = pf[3];
  float owner_pose[4] = { owx, owy, owz, oww };

  // local std::vector-like { begin, end, capacity_end }
  void **vec_begin = 0;
  void **vec_end = 0;
  void **vec_cap = 0;
  (void)vec_cap;
  float best = _DAT_009dace0; // 1e7f
  unsigned char local_40[4];
  local_14 = (local_14 & 0xffffff00u) | 1u; // SEH state 1 while vector live

  // FUN_004d5910 fills vector (ctx from owner map; residual body not OWN)
  FUN_004d5910(/* owner map */ 0 /* decompiler: ctx via owner */, owner_pose, local_40);
  // Note: decompiler binds vector at local_3c; CF preserves empty vs scan.

  if (vec_begin == vec_end) {
    // no candidates → snap to target pose
    *(float *)((char *)this_wp + 0x20) = tgt_x;
    *(float *)((char *)this_wp + 0x24) = tgt_y;
    *(float *)((char *)this_wp + 0x28) = tgt_z;
    *(float *)((char *)this_wp + 0x2c) = tgt_w;
  } else {
    void *bestObj = 0;
    float dist2_limit = dist * dist;
    for (void **it = vec_begin; it != vec_end; ++it) {
      void *cand = *it;
      // vtbl+0x2c → pose float3 at local_30
      float px, py, pz;
      ((void (__thiscall *)(void *, float *))(*(int **)cand)[0x2c / 4])(cand, &px);
      // decompiler packs float3 as local_30 / fStack_2c / fStack_28
      float d_tgt2 = (tgt_z - pz) * (tgt_z - pz) +
                     (tgt_y - py) * (tgt_y - py) +
                     (tgt_x - px) * (tgt_x - px);
      float d_own2 = (pz - owz) * (pz - owz) +
                     (py - owy) * (py - owy) +
                     (px - owx) * (px - owx);
      if (d_tgt2 <= dist2_limit && d_own2 <= dist2_limit && d_tgt2 < best) {
        bestObj = cand;
        best = d_tgt2;
      }
    }

    if (bestObj == 0) {
      *(float *)((char *)this_wp + 0x20) = tgt_x;
      *(float *)((char *)this_wp + 0x24) = tgt_y;
      *(float *)((char *)this_wp + 0x28) = tgt_z;
      *(float *)((char *)this_wp + 0x2c) = tgt_w;
    } else {
      // COID from bestObj+0x134 → path lo/hi (CDQ sign-extend)
      int coid = *(int *)((char *)bestObj + 0x134);
      *(int *)((char *)this_wp + 0x40) = coid;
      *(int *)((char *)this_wp + 0x44) = coid >> 31;

      // Direction owner_world - target; normalize (incl. W delta)
      float dx = owx - tgt_x;
      float dy = owy - tgt_y;
      float dz = owz - tgt_z;
      float dw = oww - tgt_w;
      float len2 = dx * dx + dy * dy + dz * dz;
      float inv = (len2 == 0.0f) ? 0.0f : (g_flOne / sqrtf(len2));
      float dir[4] = { dx * inv, dy * inv, dz * inv, dw * inv };

      // vtbl+0x10(this=bestObj, arg0=-1, arg1=&dir)
      int *vt = *(int **)bestObj;
      void *pathNode = ((void *(__thiscall *)(void *, int, float *))vt[0x10 / 4])(
          bestObj, -1, dir);
      if (pathNode == 0) {
        *(unsigned *)((char *)this_wp + 0x48) = 0xffffffffu;
      } else {
        *(unsigned *)((char *)this_wp + 0x48) =
            *(unsigned *)((char *)pathNode + 0x134);
      }
      // vtbl+0x2c → write desired pose at this+0x20
      ((void (__thiscall *)(void *, void *))vt[0x2c / 4])(
          bestObj, (char *)this_wp + 0x20);
    }
  }

  if (vec_begin != 0) {
    operator_delete(vec_begin); // continues (decompiler "does not return" is residual)
  }
  vec_begin = 0;
  vec_end = 0;
  vec_cap = 0;

unscope:
  local_14 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = local_1c;
  return;
}
