// =============================================================================
// Class_00a733ec_Factory_WithFreeCallback_Inferred  (FUN_00416830)
// -----------------------------------------------------------------------------
// Stable ID: aa_00416830
// Address:   0x00416830  (autoassault.exe, image base 0x400000)
// Body:      0x00416830 – 0x00416892 inclusive (99 B / 0x63); pad CC after RET 4
// System:    heap factory for Class_00a733ec (size 0x14) with free-callback path
// Generated: 2026-08-05 WQ9K-H dual seal (decompile + read_memory + disassemble_function)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Allocate a 0x14-byte Class_00a733ec object, install primary vtbl
// PTR_FUN_00a733ec, store caller context at +0x04, zero +0x08/+0x0c, and install
// free-callback LAB_00573240 at +0x10. Twin factory FUN_004168c0 is identical
// except free-callback is null.
//
// Object layout (matches dualed scalar dtor aa_00416f00):
//   +0x00 vtbl → PTR_FUN_00a733ec   ([0] = Class_00a733ec_ScalarDeletingDtor)
//   +0x04 context / payload
//   +0x08 zero
//   +0x0c zero
//   +0x10 free callback (void (__cdecl *)(void *context)) or null
//
// Free callback LAB_00573240 (bytes):
//   if (context) context->vtbl[0](flags=1);  // scalar-delete owned context
//
// ABI: stack context; returns Class_00a733ec* or null; RET 4 (stdcall 1 arg).

#include <cstdint>

using FreeCallback = void(__cdecl *)(void *context);

struct Class_00a733ec {
  void *vtbl;                 // +0x00
  void *context;              // +0x04
  uint32_t field_08;          // +0x08
  uint32_t field_0c;          // +0x0c
  FreeCallback free_callback; // +0x10
};

extern "C" void *operator_new(uint32_t size);
extern "C" void *const PTR_FUN_00a733ec; // @ 0x00a733ec
// Free callback thunk @ 0x00573240 (not a Ghidra function symbol)
extern "C" void __cdecl LAB_00573240(void *context);

// stack context; RET 4; returns new object or null
extern "C" Class_00a733ec *Class_00a733ec_Factory_WithFreeCallback_Inferred(
    void *context)
{
  auto *obj = static_cast<Class_00a733ec *>(operator_new(0x14));
  if (obj == nullptr) {
    return nullptr;
  }

  obj->vtbl = const_cast<void **>(
      reinterpret_cast<void *const *>(&PTR_FUN_00a733ec));
  obj->context = context;
  obj->field_08 = 0;
  obj->field_0c = 0;
  obj->free_callback = &LAB_00573240;
  return obj;
}

// Ghidra alias
extern "C" Class_00a733ec *FUN_00416830(void *context)
{
  return Class_00a733ec_Factory_WithFreeCallback_Inferred(context);
}
