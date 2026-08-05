// =============================================================================
// Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3f60
// Address:   0x005b3f60  (autoassault.exe, image base 0x400000)
// Body:      0x005b3f60 – 0x005b3f9a exclusive (58 B / 0x3A)
// System:    host object / MSVC default ctor
// Generated: 2026-07-29 W30-O dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving; bytes seal list base at +0x10 and movss zeros.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Default constructor for a 0x30-byte host object whose construction /
// final vtbl is PTR_FUN_009d95b4. Installs vtbl, creates an empty circular
// std::list shell at this+0x10 (sentinel via FUN_005b43b0), zeros four floats
// at this+0x20..+0x2c. Does not touch +0x04..+0x0C or +0x1C.
// Live callers: FUN_004cd8f0, FUN_004cd9a0 (both operator_new(0x30) then this).

#include <cstdint>

// Buy 0x30 node; self-link as list sentinel; return sentinel (ECX unused).
extern "C" void *__fastcall StdList_BuySelfLinkedSentinel_0x30(void * /*list_ecx*/);

// Retail: mov [esi],vtbl; lea edi,[esi+0x10]; call buy; head/size; movss zeros; ret this
extern "C" void *__fastcall Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(void *self)
{
  auto *base = static_cast<uint8_t *>(self);
  void *list = base + 0x10;

  *reinterpret_cast<const void **>(self) =
      reinterpret_cast<const void *>(0x009d95b4); // PTR_FUN_009d95b4

  void *sentinel = StdList_BuySelfLinkedSentinel_0x30(list); // FUN_005b43b0
  *reinterpret_cast<void **>(static_cast<uint8_t *>(list) + 4) = sentinel;
  *reinterpret_cast<uint32_t *>(static_cast<uint8_t *>(list) + 8) = 0;

  *reinterpret_cast<float *>(base + 0x20) = 0.0f;
  *reinterpret_cast<float *>(base + 0x24) = 0.0f;
  *reinterpret_cast<float *>(base + 0x28) = 0.0f;
  *reinterpret_cast<float *>(base + 0x2c) = 0.0f;

  return self;
}

// Scaffold alias
extern "C" void *__fastcall FUN_005b3f60(void *self)
{
  return Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(self);
}
