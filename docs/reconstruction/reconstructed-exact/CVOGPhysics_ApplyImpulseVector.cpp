// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CVOGPhysics_ApplyImpulseVector, FUN_005070b0, FUN_005070d0.
//  - Return sites: 1.

// =============================================================================
// CVOGPhysics_ApplyImpulseVector
// -----------------------------------------------------------------------------
// Purpose:  Apply a linear velocity/impulse vector to the bound rigid body via
//           body vtable +0x50. Optional readiness gate (FUN_005070b0 / +0x44)
//           may call FUN_005070d0 first. Used by network soft-apply path and
//           air-stab / boost reactions.
//
// Address:  0x0040d260  (autoassault.exe, image base 0x400000)
// Stable:   aa_0040d260
// System:   physics / CVOGPhysics
//
// Signature (behavior):
//   void __thiscall ApplyImpulseVector(CVOGPhysics* this, const void* vec3_or_vec4)
//
// Control flow:
//   1) readiness probe FUN_005070b0 on stack byte of this
//   2) if not ready && this+0x44 != 0 -> FUN_005070d0()
//   3) body = *(this+0x3c); (*body)->vtbl[+0x50](vec)
//
// Key offsets:
//   this+0x3c  rigid body* (Havok / wrapper)
//   this+0x44  readiness / secondary gate pointer
//   body vtbl +0x50  set/apply linear velocity vector
//
// Related:
//   network soft path fn_0053eec0 (ApplyImpulseVector(netVel) on large snap)
//   airStab / boost reaction impulse paths
//
// Exactness: CF mirrors raw; vec layout float3 vs float4 Tentative.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

void __thiscall CVOGPhysics_ApplyImpulseVector(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char *pcVar1;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_1;

  pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);

  if ((*pcVar1 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {

    FUN_005070d0();

  }

  (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(param_2);

  return;

}
