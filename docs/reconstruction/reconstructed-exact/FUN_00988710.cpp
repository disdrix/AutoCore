// =============================================================================
// FUN_00988710  (twin of UiOwnedBlock_CompleteBeforeDelete_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00988710
// Address:   0x00988710  (autoassault.exe, image base 0x400000)
// Body:      0x00988710–0x0098879e inclusive (143 B / 0x8F)
// Wave:      MEGA-123 OWN-ONLY dual 2026-08-05
// System:    UI owned-block complete destructor
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Ghidra-name twin of UiOwnedBlock_CompleteBeforeDelete_Inferred.
//   Complete dtor of heap-owned tree+iface block; host free is caller-side.
//
// ABI: ECX=this; bare RET; void. SEH LAB_009ad7cd.
// =============================================================================

#include <cstdint>

struct UiOwnedBlock_Inferred {
  void* head;
  std::uint32_t size;
  void* iface;
};

extern "C" void* __cdecl FUN_0044f3c0(void* out_it, void* first, void* last);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall UiOwnedBlock_CompleteBeforeDelete_Inferred(UiOwnedBlock_Inferred* self);

extern "C" void __fastcall FUN_00988710(UiOwnedBlock_Inferred* self)
{
  // Full body lives in UiOwnedBlock_CompleteBeforeDelete_Inferred.cpp
  UiOwnedBlock_CompleteBeforeDelete_Inferred(self);
}
