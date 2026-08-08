// =============================================================================
// FUN_00933310  (twin of Client_UI_RefreshInventoryWindows_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00933310
// Address:   0x00933310  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/Client_UI_RefreshInventoryWindows_Inferred.cpp
// Generated: 2026-08-05 MEGA-099 — Ghidra-symbol twin kept for index stability.
// =============================================================================

#include <cstdint>

struct MapShell_Isnil31;
struct InsertPair_Isnil31;

extern "C" InsertPair_Isnil31 *FUN_00402b30(
    MapShell_Isnil31 *map /*EAX*/,
    InsertPair_Isnil31 *out /*stack*/,
    const void *value /*EBX*/);

// Assembly-corrected ABI (decompiler void(void) rejected).
extern "C" void FUN_00933310(
    /*EAX*/ void *itemOrObject,
    /*CL*/  uint8_t flag,
    /*stack*/ void *client,
    int a1,
    int a2,
    int a3,
    int a4)
{
  alignas(4) uint8_t value_blob[0x20]{};
  InsertPair_Isnil31 out{};

  *reinterpret_cast<uint32_t *>(value_blob + 0x00) =
      static_cast<uint32_t>(reinterpret_cast<uintptr_t>(itemOrObject));
  *reinterpret_cast<uint32_t *>(value_blob + 0x08) =
      *reinterpret_cast<uint32_t *>(value_blob + 0x00);

  uint32_t pack = 0;
  reinterpret_cast<uint8_t *>(&pack)[0] = static_cast<uint8_t>(a1);
  reinterpret_cast<uint8_t *>(&pack)[1] = flag;
  *reinterpret_cast<uint32_t *>(value_blob + 0x0C) = pack;
  *reinterpret_cast<uint32_t *>(value_blob + 0x10) = static_cast<uint32_t>(a2);
  *reinterpret_cast<uint32_t *>(value_blob + 0x18) = static_cast<uint32_t>(a3);
  *reinterpret_cast<uint32_t *>(value_blob + 0x1C) = static_cast<uint32_t>(a4);

  auto *map = reinterpret_cast<MapShell_Isnil31 *>(
      reinterpret_cast<uint8_t *>(client) + 0xF14);

  (void)FUN_00402b30(map, &out, value_blob);
}
