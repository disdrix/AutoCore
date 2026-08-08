// =============================================================================
// FUN_0051e180  (scaffold twin of Map_Tidy_FreeHead_B)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051e180
// Address:   0x0051e180–0x0051e1ad inclusive (46 B)
// Wave:      2026-08-04 WQ9F-H OWN dual A/B
// Named:     reconstructed-exact/Map_Tidy_FreeHead_B.cpp
// Note:      Decompiler truncates after delete; null head/size from bytes.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0051d880(void* map, void* out, void* first, void* last);
extern "C" void __cdecl operator_delete(void* p);

extern "C" void __fastcall FUN_0051e180(void* map)
{
  void* out;
  void* head = *reinterpret_cast<void**>(reinterpret_cast<char*>(map) + 4);
  void* begin = *reinterpret_cast<void**>(head);
  FUN_0051d880(map, &out, begin, head);
  operator_delete(head);
  *reinterpret_cast<void**>(reinterpret_cast<char*>(map) + 4) = nullptr;
  *reinterpret_cast<std::uint32_t*>(reinterpret_cast<char*>(map) + 8) = 0;
}
