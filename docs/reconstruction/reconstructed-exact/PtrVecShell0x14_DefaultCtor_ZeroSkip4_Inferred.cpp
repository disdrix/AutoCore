// =============================================================================
// PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred  (aa_00416590)
// -----------------------------------------------------------------------------
// Address:   0x00416590 – 0x004165CF exclusive (63 B / 0x3F)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-J OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this (Elem0x14*); no stack args; plain RET (C3); void
// Peer dtor: FUN_00417ee0 (not owned) — free +8, zero triad
// =============================================================================

#include <cstdint>

// Layout of the 0x14-byte shell (elem stride sealed by eh_vector size=0x14):
//   +0x00  unk0      — zeroed
//   +0x04  unk4      — NOT written by this ctor
//   +0x08  begin*    — zeroed (pointer-vector begin)
//   +0x0C  end*      — zeroed
//   +0x10  capEnd*   — zeroed
//
// Used as:
//   - eh_vector element ctor for 9-wide array at UI host+0xEE4 (FUN_00820830 / audio)
//   - default ctor for four BSS statics at 0xd218e0 + n*0x14

extern "C" void __thiscall PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred(uint32_t* self)
{
  // Bytes also install SEH LAB_009bcfab with EH state -1; no cleanup body.
  self[0] = 0;
  // self[1] intentionally not stored
  self[2] = 0;
  self[3] = 0;
  self[4] = 0;
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_00416590(uint32_t* self)
{
  PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred(self);
}
