// =============================================================================
// GfxBody_CompleteDtor_Inferred  (aa_00763f60)
// -----------------------------------------------------------------------------
// Address:   0x00763f60  (autoassault.exe, image base 0x400000)
// Wave:      W31-C OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Ignore Ghidra false-noreturn on operator_delete (bytes fall through).
// Bit-for-bit vs retail EXE: DEFERRED.
// Reject:    Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00763f60
// =============================================================================

#include <cstdint>

extern uint32_t PTR_LAB_00a9da8c;

extern "C" void __fastcall FUN_00763740(void* self);
// Hosts vector of {vtbl, …} at EBX = self+0x128 (unaff_EBX in decompile).
extern "C" void FUN_004380f0(void);
extern "C" void FUN_00968110(void* ptr_vec_host /* self+0xDC */);
extern "C" void FUN_0096aec0(void* aligned_host /* self+0x98 */);
extern "C" void __fastcall FUN_0096d7a0(void* self);
extern "C" void __cdecl operator_delete(void* p);

// Graphics-body composite complete destructor. Does not free this.
// Matching ctor: FUN_00764030 (installs same PTR_LAB_00a9da8c).
// Size ~0x14C (three instances embedded in ListTrackedObj at +0x30/+0x17C/+0x2C8).
extern "C" void __fastcall GfxBody_CompleteDtor_Inferred(uint32_t* self)
{
  // SEH: LAB_009b0ac6; EH state starts at 5 (omitted structural detail).

  self[0] = reinterpret_cast<uint32_t>(&PTR_LAB_00a9da8c);

  FUN_00763740(self);

  // FUN_004380f0 uses EBX = self+0x128 set by LEA before call.
  // Destroys [begin,end) of 8-byte elements via (**elem)(0), then operator_delete(begin).
  // (Register host setup is structural; call site is thiscall-equivalent via EBX.)
  FUN_004380f0();

  FUN_00968110(reinterpret_cast<char*>(self) + 0xDC);

  void* buf_a = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xD0);
  if (buf_a != nullptr) {
    operator_delete(buf_a);
  }
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xD0) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xD4) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xD8) = 0;

  void* buf_b = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0xC0);
  if (buf_b != nullptr) {
    operator_delete(buf_b);
  }
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xC0) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xC4) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0xC8) = 0;

  FUN_0096aec0(reinterpret_cast<char*>(self) + 0x98);
  FUN_0096d7a0(self);
}

// Scaffold alias
extern "C" void __fastcall FUN_00763f60(uint32_t* self)
{
  GfxBody_CompleteDtor_Inferred(self);
}
