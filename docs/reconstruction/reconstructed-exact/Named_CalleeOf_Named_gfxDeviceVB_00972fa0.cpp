// =============================================================================
// Named_CalleeOf_Named_gfxDeviceVB_00972fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00972fa0
// Callee of Named_gfxDeviceVB (+2 other named callers)
// Address:   0x00972fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (2026-07-29 dual): Local point → world point via basis mat4.
// Role: Xform_TransformLocalPointToWorld_Inferred. Parent-seed name is NOT exclusive
// (24 xrefs: unproject, DCT, gfx, physics). Prefer FUN_00972fa0.cpp for refined plate.
// Dual: reviews/A|B_aa_00972fa0_Xform_TransformLocalPointToWorld_Inferred.md
//
// CC (assembly): EAX=basis*, EDI=out xyz*, stack=local xyz*, RET 4, return EAX=out.
// Dirty: basis+0xbc bit0 → FUN_00972e50; point kernel FUN_0076f6e0 (w=1).

// READABILITY:
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076f6e0, FUN_00972e50.
//  - Return sites: 1 (EAX=EDI).

void Named_CalleeOf_Named_gfxDeviceVB_00972fa0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if ((*(byte *)(in_EAX + 0xbc) & 1) != 0) {

    FUN_00972e50();

  }

  FUN_0076f6e0();

  *unaff_EDI = local_c;

  unaff_EDI[1] = local_8;

  unaff_EDI[2] = local_4;

  return;

}
