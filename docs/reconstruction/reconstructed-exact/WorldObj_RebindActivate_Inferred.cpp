// =============================================================================
// WorldObj_RebindActivate_Inferred  (FUN_00560e90)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560e90
// Address:   0x00560e90–0x00560eb1  (autoassault.exe, image base 0x400000)
// Body size: 34 bytes
// System:    world-object / phys rebind
// Generated: 2026-07-23 scaffold as FUN_00560e90; dual A/B seal 2026-07-29 (W24-B)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   On a world/phys manager (this):
//     1. Unbind object links   FUN_0055fbf0(manager, obj)
//     2. Re-bind object links  FUN_0055fa40(manager, obj)
//     3. Set flag byte *(obj+0x44)+0x28 = 1
//   Used after phys mode restore, HB recreate, airlift teardown/setup, etc.
//
// ABI (retail)
//   __thiscall Manager* this  (ECX)
//   stack: Object* obj, int staged_unused   → ret 8
//   Second stack dword is cleaned but never read in this body.
//   Callers often stage value 1 via mov byte [esp],1 before push obj.
//
// SIBLINGS (not owned)
//   0x00560ec0 WorldObj_EnrollActivate_Inferred  (bind + counters + refcount)
//   0x00561450 WorldObj_RemoveOrDefer_Inferred   (unbind chain)
//
// READABILITY CF:
//   esi=this; edi=obj
//   call unbind; call bind; flag=1; ret 8
//

#include <cstdint>

// Peer helpers (not dual-sealed in W24-B)
extern "C" void FUN_0055fbf0(void* manager /*ECX*/, void* obj /*stack*/);
extern "C" void FUN_0055fa40(void* manager /*ECX*/, void* obj /*stack*/);

// Clean plate: explicit manager + object. Retail also has unread 2nd stack formal.
void WorldObj_RebindActivate_Inferred(void* manager /*ECX*/, void* obj /*stack*/)
{
  FUN_0055fbf0(manager, obj);
  FUN_0055fa40(manager, obj);
  void* sub = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 0x44);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(sub) + 0x28) = 1;
}

// Legacy Ghidra name — see FUN_00560e90.cpp
// void FUN_00560e90(int param_1); // understates this + ret 8
