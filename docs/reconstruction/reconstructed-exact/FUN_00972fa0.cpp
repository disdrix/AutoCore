// =============================================================================
// FUN_00972fa0 / Xform_TransformLocalPointToWorld_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00972fa0
// Address:   0x00972fa0  (autoassault.exe, image base 0x400000)
// System:    gfx-math (shared basis transform)
// Generated: 2026-07-23 scaffold; dual refine 2026-07-29 (assembly CC)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed register CC.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B:  reviews/A_aa_00972fa0_Xform_TransformLocalPointToWorld_Inferred.md
//            reviews/B_aa_00972fa0_Xform_TransformLocalPointToWorld_Inferred.md
// =============================================================================

// PURPOSE:
//   Map a local-space point through a basis object's world matrix to a
//   world-space point. If basis+0xbc bit0 is set, rebuild the cached matrix
//   first (FUN_00972e50). Uses point kernel FUN_0076f6e0 (homogeneous w=1).
//   Twin direction helper: FUN_009729d0 (w=0).
//
// CALLING CONVENTION (assembly-sealed; NOT plain cdecl/thiscall):
//   EAX  = basis*          // mat4 at +0; dirty flags at +0xbc
//   EDI  = float* outWorld // xyz destination
//   [esp+4 on entry after CALL] = const float* localPoint
//   returns EAX = outWorld
//   RET 4
//
// READABILITY:
//  - Control flow from Ghidra decompile; registers from disassemble_function.
//  - Callee bodies not inlined (OWN VA only).

// Forward decls of callees (roles only; separate units).
extern "C" int __fastcall FUN_00972e50(int basis);
extern "C" void FUN_0076f6e0(void); // EAX=in xyz*, EBX=out xyz*, ESI=mat4 base

extern "C" float *FUN_00972fa0(void)
{
  // Phantoms match live register use; stack arg recovered from RET 4 + [ESP+…].
  int basis_reg;            // EAX on entry — basis object
  float *out_reg;           // EDI on entry — world xyz out
  float *local_point;       // stack arg0
  float tmp_x, tmp_y, tmp_z;

  // if ((*(byte *)(basis + 0xbc) & 1) != 0) FUN_00972e50(basis);
  if ((*(unsigned char *)((char *)(uintptr_t)basis_reg + 0xbc) & 1u) != 0) {
    FUN_00972e50(basis_reg);
  }

  // ESI = basis; EAX = local_point; EBX = &tmp
  FUN_0076f6e0();

  out_reg[0] = tmp_x;
  out_reg[1] = tmp_y;
  out_reg[2] = tmp_z;
  return out_reg;
}

// Decompiler-faithful skeleton (for CF compare with raw; formals omitted by Ghidra):
#if 0
void FUN_00972fa0_decompiler_shape(void)
{
  int in_EAX;
  unsigned *unaff_EDI;
  unsigned local_c, local_8, local_4;
  if ((*(unsigned char *)(in_EAX + 0xbc) & 1) != 0) {
    FUN_00972e50();
  }
  FUN_0076f6e0();
  *unaff_EDI = local_c;
  unaff_EDI[1] = local_8;
  unaff_EDI[2] = local_4;
}
#endif
