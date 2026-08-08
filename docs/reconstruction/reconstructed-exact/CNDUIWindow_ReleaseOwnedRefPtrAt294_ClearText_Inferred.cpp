// =============================================================================
// CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred  (aa_007aec70)
// -----------------------------------------------------------------------------
// Address:   0x007aec70  (autoassault.exe, image base 0x400000)
// Body:      0x007aec70–0x007aecc3 inclusive (84 B / 0x54)
// Wave:      WQ9L-G OWN-ONLY dual 2026-08-05
// System:    CNDUIWindow complete-dtor helper
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Partial teardown helper called from CNDUIWindow_CompleteDtor (FUN_007b5be0)
//   after FUN_007a8580 and before FUN_007aff00.
//   - If owned shell* at +0x294 and flag +0xBB: RefCountedPtr dtor + delete shell.
//   - If shell was non-null: null shell/flag and invoke this->vtbl[+0x2B4]("").
//   - Always zero +0x29C and +0x2A0.
//   Does NOT free this.
//
// ABI:
//   ECX = this (CNDUIWindow*). Bare RET (C3). void.
//
// EVIDENCE:
//   DAT_00a1419b = empty C-string "".
//   FUN_0096efd0 = RefCountedPtr_Dtor_Inferred (sealed W38-P).
//   Parent RTTI .?AVCNDUIWindow@@ on PTR_FUN_00a960ac.
//
// REJECTED SCAFFOLD:
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70 (parent debug path, not this body)
// =============================================================================

#include <cstdint>

extern "C" void __fastcall RefCountedPtr_Dtor_Inferred(void** self /*ECX*/);
extern "C" void __cdecl operator_delete(void* p);
extern const char DAT_00a1419b; // ""

// Partial teardown only — does not free self.
extern "C" void __fastcall CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(
    uint8_t* self /*ECX*/)
{
  void* shell = *reinterpret_cast<void**>(self + 0x294);
  if (shell != nullptr) {
    if (self[0xBB] != 0) {
      // thiscall ECX = shell (heap host of refcounted handle)
      RefCountedPtr_Dtor_Inferred(reinterpret_cast<void**>(shell));
      operator_delete(shell);
    }
    *reinterpret_cast<void**>(self + 0x294) = nullptr;
    self[0xBB] = 0;

    // this->vtbl[+0x2B4](this, "")
    void** vtbl = *reinterpret_cast<void***>(self);
    using Vfn = void(__thiscall*)(void* self, const char* text);
    reinterpret_cast<Vfn>(vtbl[0x2B4 / 4])(self, &DAT_00a1419b);
  }

  *reinterpret_cast<uint32_t*>(self + 0x29C) = 0;
  *reinterpret_cast<uint32_t*>(self + 0x2A0) = 0;
}

// Ghidra twin name
extern "C" void __fastcall FUN_007aec70(uint8_t* self)
{
  CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(self);
}
