// =============================================================================
// Host_ClearElem0x28Array_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00494170
// Address:   0x00494170–0x004941af  (64 B / 0x40, autoassault.exe base 0x400000)
// System:    host / cookie-vector free (stride 0x28)
// Generated: 2026-07-29 W30-Q dual A/B (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + body bounds seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00494170
// =============================================================================
//
// PURPOSE:
//   Free the MSVC cookie-vector of 0x28-byte elements at host+0x28 and zero the
//   host dim fields at +4 and +8. Element complete dtor is FUN_005b8000
//   (Elem0x28_CompleteDtor, W29-F). Same free fragment is inlined in
//   Class_009c7a1c_CompleteDtor (0x004970b0); this VA is the standalone helper.
//
// ABI:
//   ECX = host (Ghidra __fastcall; thiscall-equivalent single-register this).
//   No stack formals. Bare RET. Void.
//
// NOTE:
//   No static callers in Ghidra xref DB (orphan relative to static graph).
//   Product host type English open — structural Inferred name.
// =============================================================================

#include <cstdint>

extern "C" void _eh_vector_destructor_iterator_(
    void* arr, uint32_t stride, int count, void* dtor);
extern "C" void operator_delete[](void* p);
extern "C" void __thiscall FUN_005b8000(void* elem);  // Elem0x28_CompleteDtor

// Machine: void __fastcall FUN_00494170(int host)
extern "C" void __fastcall Host_ClearElem0x28Array_Inferred(void* host)
{
  auto* h = reinterpret_cast<uint8_t*>(host);
  void* arr = *reinterpret_cast<void**>(h + 0x28);
  if (arr != nullptr) {
    int count = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(arr) - 4);
    _eh_vector_destructor_iterator_(arr, 0x28, count,
                                    reinterpret_cast<void*>(&FUN_005b8000));
    operator_delete[](reinterpret_cast<uint8_t*>(arr) - 4);
  }
  *reinterpret_cast<uint32_t*>(h + 0x28) = 0;
  *reinterpret_cast<uint32_t*>(h + 4) = 0;
  *reinterpret_cast<uint32_t*>(h + 8) = 0;
}
