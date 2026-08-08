// =============================================================================
// FUN_00402280  — machine twin of StdList_Destroy_FreeHead_ViaClearEsi_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402280
// Address:   0x00402280  (autoassault.exe, image base 0x400000)
// Body:      0x00402280–0x0040229c inclusive (29 B / 0x1D)
// Wave:      MEGA-067 OWN-ONLY dual 2026-08-05
// Canonical: StdList_Destroy_FreeHead_ViaClearEsi_Inferred
// Exactness: Behavior-preserving; full body from read_memory (not decomp-only).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void __cdecl operator_delete(void* p);
extern "C" void StdList_Clear_ESI(void* list /* ESI */);

// Ghidra symbol kept for VA-keyed consumers; prefer the named clean.
extern "C" void __fastcall FUN_00402280(int param_1)
{
  // ECX = list shell* (head @ +4, size @ +8)
  std::uint8_t* list = reinterpret_cast<std::uint8_t*>(param_1);

  // CALL 00415e90 with ESI = list
  StdList_Clear_ESI(list);

  void* head = *reinterpret_cast<void**>(list + 4);
  operator_delete(head);
  *reinterpret_cast<void**>(list + 4) = nullptr;
}
