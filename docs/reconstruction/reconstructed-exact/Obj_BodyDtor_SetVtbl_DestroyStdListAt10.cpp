// =============================================================================
// Obj_BodyDtor_SetVtbl_DestroyStdListAt10
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3b20
// Address:   0x005b3b20  (autoassault.exe, image base 0x400000)
// Body:      0x005b3b20 – 0x005b3b2e exclusive (14 B / 0x0E)
// System:    host object / MSVC std::list member dtor
// Generated: 2026-07-29 W28-N dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving; bytes override decompile (ADD ECX,0x10 + tail JMP).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC body destructor for an unknown host object whose final vtbl is
// PTR_FUN_009d95b4 and whose embedded circular std::list shell lives at +0x10.
// Installs final vtbl, then tail-jumps StdList_Destroy_FreeHead(this+0x10).
// Sole code caller: scalar-deleting dtor FUN_005b44d0 (vtbl[0]).

#include <cstdint>

// W27-K sealed: free all list nodes + sentinel, null list+4, size=0.
extern "C" void __fastcall StdList_Destroy_FreeHead(void *list);

// Retail bytes: mov [ecx],0x009d95b4; add ecx,0x10; jmp StdList_Destroy_FreeHead
extern "C" void __fastcall Obj_BodyDtor_SetVtbl_DestroyStdListAt10(void *self)
{
  *reinterpret_cast<const void **>(self) =
      reinterpret_cast<const void *>(0x009d95b4); // PTR_FUN_009d95b4
  StdList_Destroy_FreeHead(static_cast<uint8_t *>(self) + 0x10);
}

// Scaffold alias
extern "C" void __fastcall FUN_005b3b20(void *self)
{
  Obj_BodyDtor_SetVtbl_DestroyStdListAt10(self);
}
