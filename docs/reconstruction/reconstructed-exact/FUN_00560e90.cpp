// =============================================================================
// FUN_00560e90  (alias → WorldObj_RebindActivate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560e90
// Address:   0x00560e90  (autoassault.exe, image base 0x400000)
// System:    world-object / phys rebind
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W24-B)
// Exactness: Behavior-preserving rewrite. Prefer named plate.
// =============================================================================

#include <cstdint>

extern "C" void FUN_0055fbf0(void* manager /*ECX*/, void* obj /*stack*/);
extern "C" void FUN_0055fa40(void* manager /*ECX*/, void* obj /*stack*/);

// Retail: __thiscall manager (ECX) + stack (obj, unused) ret 8.
// Decompiler shows only object formal; bytes prove ECX=this.
void FUN_00560e90(void* manager /*ECX*/, void* obj /*stack*/)
{
  FUN_0055fbf0(manager, obj);
  FUN_0055fa40(manager, obj);
  void* sub = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(obj) + 0x44);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(sub) + 0x28) = 1;
}

// Canonical: WorldObj_RebindActivate_Inferred
