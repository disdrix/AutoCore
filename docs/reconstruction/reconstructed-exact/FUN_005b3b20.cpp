// =============================================================================
// FUN_005b3b20  (scaffold alias → Obj_BodyDtor_SetVtbl_DestroyStdListAt10)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3b20
// Address:   0x005b3b20  (autoassault.exe, image base 0x400000)
// Body:      14 B; tail JMP to StdList_Destroy_FreeHead
// System:    host object / MSVC std::list member dtor
// Refined:   2026-07-29 W28-N
// =============================================================================

#include <cstdint>

extern "C" void __fastcall StdList_Destroy_FreeHead(void *list);

// Bytes: c7 01 b4 95 9d 00 | 83 c1 10 | e9 rel32→00497360
extern "C" void __fastcall FUN_005b3b20(void *self)
{
  *reinterpret_cast<const void **>(self) =
      reinterpret_cast<const void *>(0x009d95b4);
  StdList_Destroy_FreeHead(static_cast<uint8_t *>(self) + 0x10);
}
