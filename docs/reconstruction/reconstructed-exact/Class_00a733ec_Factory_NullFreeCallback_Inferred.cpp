// =============================================================================
// Class_00a733ec_Factory_NullFreeCallback_Inferred  (FUN_004168c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004168c0
// Address:   0x004168c0  (autoassault.exe, image base 0x400000)
// Body:      0x004168c0 – 0x0041691f inclusive (96 B / 0x60)
// System:    Class_00a733ec factory — null free-callback variant
// Generated: 2026-08-05 WQ9K-I dual seal (batch_decompile + read_memory)
// Exactness: Behavior-preserving rewrite from decompile + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Heap-allocate a 0x14-byte object whose primary vtbl is
// PTR_FUN_00a733ec, store caller context at +0x04, zero +0x08/+0x0c, and set
// free-callback +0x10 to null. Twin factory FUN_00416830 is identical except
// it installs free callback LAB_00573240 at +0x10.
//
// Scalar dtor (vtbl[0] = 0x00416f00) will skip free-callback when null, then
// free host iff (flags & 1).
//
// Object layout (0x14):
//   +0x00 vtbl → PTR_FUN_00a733ec
//   +0x04 context / payload
//   +0x08 field (0)
//   +0x0c field (0)
//   +0x10 free_callback (null here)
//
// Adjacent .rdata UTF-16 "UNI_BUTTONS" after vtbl is NOT proven class English.

#include <cstdint>

using FreeCallback = void(__cdecl *)(void *context);

struct Class_00a733ec {
  void *vtbl;                 // +0x00
  void *context;              // +0x04
  uint32_t field_08;          // +0x08
  uint32_t field_0c;          // +0x0c
  FreeCallback free_callback; // +0x10
};

// External (image)
extern "C" void *operator_new(uint32_t size);
extern "C" void *const PTR_FUN_00a733ec; // @ 0x00a733ec; [0] = 0x00416f00

// 1 stack arg; RET 4; returns object* in EAX (null on OOM)
extern "C" Class_00a733ec *Class_00a733ec_Factory_NullFreeCallback_Inferred(
    void *context)
{
  // SEH frame LAB_009ab4eb (omitted — compiler prolog/epilog)
  Class_00a733ec *obj =
      static_cast<Class_00a733ec *>(operator_new(0x14));
  if (obj == nullptr) {
    return nullptr;
  }

  obj->vtbl = const_cast<void **>(
      reinterpret_cast<void *const *>(&PTR_FUN_00a733ec));
  obj->context = context;
  obj->field_0c = 0;
  obj->field_08 = 0;
  obj->free_callback = nullptr; // sole twin difference vs 00416830
  return obj;
}

// Ghidra alias
extern "C" Class_00a733ec *FUN_004168c0(void *context)
{
  return Class_00a733ec_Factory_NullFreeCallback_Inferred(context);
}
