// =============================================================================
// Class_00a733ec_ScalarDeletingDtor_Inferred  (FUN_00416f00)
// -----------------------------------------------------------------------------
// Stable ID: aa_00416f00
// Address:   0x00416f00  (autoassault.exe, image base 0x400000)
// Body:      0x00416f00 – 0x00416f2e inclusive (47 B / 0x2F); pad CC after
// System:    MSVC scalar-deleting destructor (vtbl PTR_FUN_00a733ec)
// Generated: 2026-08-05 WQ9J-E dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Decompiler "Subroutine does not return" on operator_delete is FALSE
//            — bytes fall through to MOV EAX,ESI / POP ESI / RET 4.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC scalar-deleting dtor for objects whose primary vtbl is
// PTR_FUN_00a733ec[0] (= this function). Complete teardown is INLINE (no
// separate complete-dtor call): reinstall vtbl, optionally invoke owned free
// callback at +0x10 with context at +0x04, free host iff (flags & 1).
//
// Object layout (0x14 from factories FUN_00416830 / FUN_004168c0):
//   +0x00 vtbl
//   +0x04 context / payload (passed to free callback)
//   +0x08 / +0x0c zeros in factories
//   +0x10 free callback (void (*)(void* context) cdecl) or null
// Factory 00416830 sets callback = LAB_00573240; 004168c0 sets callback = null.
// Adjacent .rdata string "UNI_BUTTONS" is NOT proven class English (next blob).

#include <cstdint>

using FreeCallback = void(__cdecl *)(void *context);

struct Class_00a733ec {
  void *vtbl;                 // +0x00 → PTR_FUN_00a733ec
  void *context;              // +0x04
  uint32_t field_08;          // +0x08
  uint32_t field_0c;          // +0x0c
  FreeCallback free_callback; // +0x10
};

// External (image)
extern "C" void *operator_delete(void *p);
// vtbl stamp written by this dtor / factories
extern "C" void *const PTR_FUN_00a733ec; // @ 0x00a733ec; [0] = 0x00416f00

// ECX = this; stack flags; RET 4; returns this* in EAX
extern "C" Class_00a733ec *__thiscall Class_00a733ec_ScalarDeletingDtor_Inferred(
    Class_00a733ec *self, uint8_t flags)
{
  FreeCallback cb = self->free_callback;
  self->vtbl = const_cast<void **>(
      reinterpret_cast<void *const *>(&PTR_FUN_00a733ec));

  if (cb != nullptr) {
    cb(self->context); // cdecl; callee cleans? bytes: PUSH arg; CALL; ADD ESP,4
  }

  if ((flags & 1) != 0) {
    operator_delete(self); // returns — not noreturn
  }

  return self;
}

// Ghidra alias
extern "C" Class_00a733ec *__thiscall FUN_00416f00(Class_00a733ec *self,
                                                    uint8_t flags)
{
  return Class_00a733ec_ScalarDeletingDtor_Inferred(self, flags);
}
