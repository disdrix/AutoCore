// =============================================================================
// Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4260
// Address:   0x005b4260  (autoassault.exe, image base 0x400000)
// Body:      0x005b4260 – 0x005b42e6 exclusive (134 B / 0x86)
// System:    host object / MSVC ctor + populate
// Generated: 2026-07-29 W30-O dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving; SEH + ret 0x14 sealed from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Convenience constructor — same empty shell as the default ctor
// (vtbl, empty list at +0x10, zero F4 at +0x20), then FUN_005b3fa0(this, p2..p6)
// under MSVC SEH (handler 0x009a6860). Final ret 0x14 (five stack args).
// No live code xrefs; production uses default ctor + separate populate.

#include <cstdint>

extern "C" void *__fastcall StdList_BuySelfLinkedSentinel_0x30(void * /*list_ecx*/);

// Populate path — not owned by W30-O; signature from decompile + thiscall ret 0x14.
extern "C" void *__thiscall FUN_005b3fa0(void *self, uint32_t p2, uint32_t p3,
                                         uint32_t p4, uint32_t p5, uint32_t p6);

extern "C" void *__thiscall Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate(
    void *self, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6)
{
  auto *base = static_cast<uint8_t *>(self);
  void *list = base + 0x10;

  // SEH frame present in retail (handler 0x009a6860); state -1 → 0 after list init.
  *reinterpret_cast<const void **>(self) =
      reinterpret_cast<const void *>(0x009d95b4);

  void *sentinel = StdList_BuySelfLinkedSentinel_0x30(list);
  *reinterpret_cast<void **>(static_cast<uint8_t *>(list) + 4) = sentinel;
  *reinterpret_cast<uint32_t *>(static_cast<uint8_t *>(list) + 8) = 0;

  *reinterpret_cast<float *>(base + 0x20) = 0.0f;
  *reinterpret_cast<float *>(base + 0x24) = 0.0f;
  *reinterpret_cast<float *>(base + 0x28) = 0.0f;
  *reinterpret_cast<float *>(base + 0x2c) = 0.0f;

  FUN_005b3fa0(self, p2, p3, p4, p5, p6);
  return self;
}

// Scaffold alias
extern "C" void *__thiscall FUN_005b4260(void *self, uint32_t p2, uint32_t p3,
                                          uint32_t p4, uint32_t p5, uint32_t p6)
{
  return Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate(self, p2, p3, p4, p5, p6);
}
