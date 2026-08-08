// =============================================================================
// CNDUIWindow_ReleaseTextLayoutAndNested_Inferred  (aa_007aff00)
// -----------------------------------------------------------------------------
// Address:   0x007aff00  (autoassault.exe, image base 0x400000)
// Body:      0x007aff00–0x007aff51 inclusive (82 B / 0x52)
// Wave:      WQ9L-G OWN-ONLY dual 2026-08-05
// System:    CNDUIWindow complete-dtor helper
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Partial teardown helper called from CNDUIWindow_CompleteDtor (FUN_007b5be0)
//   after FUN_007aec70.
//   - If gate +0x20C != 0: complete-dtor + delete owned text layout at +0x28C.
//   - Always: clear nested CS-guarded list at +0x1E8 via FUN_00424060.
//   - Always: zero +0x128 and +0x12C.
//   Does NOT free this. Does NOT DeleteCriticalSection (parent does later).
//
// ABI:
//   ECX = this (CNDUIWindow*). Bare RET (C3). void.
//
// DECOMPILER CORRECTION:
//   Ghidra showed FUN_00424060() with no this; bytes seal
//   LEA ECX,[ESI+0x1E8] before CALL.
//
// PEERS:
//   UiTextLayout_CompleteDtor_Inferred (FUN_00797d70) — stdcall RET 4
//   Parent may free +0x28C again if still set; may re-call FUN_00424060 after
//   nested vtbl restamp + DeleteCriticalSection.
//
// REJECTED SCAFFOLD:
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00
// =============================================================================

#include <cstdint>

extern "C" void __stdcall UiTextLayout_CompleteDtor_Inferred(void* layout);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall FUN_00424060(void* nested /*ECX*/);

// Partial teardown only — does not free self.
extern "C" void __fastcall CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(
    uint8_t* self /*ECX*/)
{
  if (*reinterpret_cast<int32_t*>(self + 0x20C) != 0) {
    void* layout = *reinterpret_cast<void**>(self + 0x28C);
    if (layout != nullptr) {
      UiTextLayout_CompleteDtor_Inferred(layout);
      operator_delete(layout);
    }
    *reinterpret_cast<void**>(self + 0x28C) = nullptr;
  }

  // Nested object at +0x1E8 (CS + owned list head) — thiscall
  FUN_00424060(self + 0x1E8);

  *reinterpret_cast<uint32_t*>(self + 0x128) = 0;
  *reinterpret_cast<uint32_t*>(self + 0x12C) = 0;
}

// Ghidra twin name
extern "C" void __fastcall FUN_007aff00(uint8_t* self)
{
  CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(self);
}
