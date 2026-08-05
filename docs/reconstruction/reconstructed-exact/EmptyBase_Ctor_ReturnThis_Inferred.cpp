// =============================================================================
// EmptyBase_Ctor_ReturnThis_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f5b0
// Address:   0x0063f5b0–0x0063f5bb  (autoassault.exe, image base 0x400000)
// System:    object / POD base construction
// Generated: 2026-07-29 W25-L dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + byte CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Trivial empty base constructor. Calls identity stub FUN_005edf20
//   (mov eax,ecx; ret) then returns this in EAX. Child POD/component
//   constructors invoke this first, then write fields.
//
// ABI:
//   thiscall (ECX = this). Bare ret. EAX = this.
//   Ghidra surface: __fastcall param_1 (same single register).
//
// CALLEES: FUN_005edf20 (identity)
// CALLERS: FUN_005d6720, FUN_005d67f0, FUN_005fe5c0, FUN_005fe650,
//          FUN_0064dda0, FUN_0064de10, FUN_006520c0, 0x00652028
// =============================================================================

#include <cstdint>

// FUN_005edf20 @ 0x005edf20 — pure identity on ECX/this
extern "C" void* FUN_005edf20(void* p);

void* EmptyBase_Ctor_ReturnThis_Inferred(void* this_obj)
{
  // machine: push esi; mov esi, ecx; call FUN_005edf20; mov eax, esi; pop esi; ret
  FUN_005edf20(this_obj);
  return this_obj;
}
