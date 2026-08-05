// =============================================================================
// Phys_ActionBase_ctor  (FUN_00636370)
// -----------------------------------------------------------------------------
// Stable ID: aa_00636370
// Address:   0x00636370  (autoassault.exe, image base 0x400000)
// System:    physics / Havok-like action base
// Generated: 2026-07-29 W17-P dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Base constructor for dual-vtable action-like objects.
//   - Sets refcount at +6 = 1
//   - Installs primary base vtbl PTR_FUN_009e39f4 and secondary PTR_LAB_009e5e78
//     (with intermediate secondary PTR_LAB_009e3a68 during MI construction)
//   - Clears +0x0c and +0x14
//   - Stores optional host at +0x18; if non-null, appends this to host's
//     growable ptr list (FUN_00507290: ECX=host, stack=this; list at host+0x94)
//     and addrefs host (+6)
//
// ABI: __thiscall; ECX=this; one stack arg = host*; ret 4; returns this in EAX.
// Body: 0x00636370 .. 0x006363b2
//
// CALLERS (context): VehicleAction_ctor 0x00597f90, Phys_FlipperConstraint_ctor
//   0x00600140, FUN_00658bf0. Derived ctors overwrite class vtables after this returns.
//
// NOTE: Ghidra decompile shows FUN_00507290(this) only — machine seal shows
//   thiscall with ECX=host and stack arg=this. Prefer annotated/machine form.
//

#include <cstdint>

// Forward: host-side vector push (owned elsewhere)
// void __thiscall FUN_00507290(void *host, void *actionPtr);

extern "C" void *PTR_FUN_009e39f4;
extern "C" void *PTR_LAB_009e3a68;
extern "C" void *PTR_LAB_009e5e78;
void __thiscall FUN_00507290(void *host, void *elem);

void *__thiscall Phys_ActionBase_ctor(void *self, void *host)
{
  *(uint16_t *)((char *)self + 6) = 1;

  *(void **)((char *)self + 8) = &PTR_LAB_009e3a68;
  *(uint32_t *)((char *)self + 0xc) = 0;
  *(uint32_t *)((char *)self + 0x14) = 0;

  *(void **)self = &PTR_FUN_009e39f4;
  *(void **)((char *)self + 8) = &PTR_LAB_009e5e78;
  *(void **)((char *)self + 0x18) = host;

  if (host != 0) {
    FUN_00507290(host, self);
    *(int16_t *)((char *)host + 6) =
        (int16_t)(*(int16_t *)((char *)host + 6) + 1);
  }
  return self;
}

// Ghidra-facing alias (decompiler layout)
uint32_t *__thiscall FUN_00636370(uint32_t *param_1, int param_2)
{
  return (uint32_t *)Phys_ActionBase_ctor(param_1, (void *)param_2);
}
