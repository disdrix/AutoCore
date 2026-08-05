// =============================================================================
// FUN_00561370  (scaffold twin of WorldMgr_RebindAllObjects_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00561370
// Address:   0x00561370  (autoassault.exe, image base 0x400000)
// System:    world / phys manager rebind
// Generated: 2026-07-29 W27-P (updates 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Named clean: WorldMgr_RebindAllObjects_Inferred.cpp
// ABI: void __thiscall (ECX=manager); bare ret; body 0x00561370–0x0056144a exclusive.

#include <cstdint>

extern "C" void __thiscall FUN_0055fbf0(void* manager, void* obj);
extern "C" void __thiscall FUN_0055fa40(void* manager, void* obj);
extern "C" void __thiscall FUN_0055f7a0(void* manager, void* obj, char flag);

extern "C" void __thiscall FUN_00561370(void* param_1)
{
  auto* const m = reinterpret_cast<uint8_t*>(param_1);
  int32_t local_i;

  local_i = 0;
  if (0 < *reinterpret_cast<int32_t*>(m + 0x0c)) {
    do {
      auto* island = reinterpret_cast<uint8_t*>(
          (*reinterpret_cast<void***>(m + 0x08))[local_i]);
      int32_t bi = 0;
      if (0 < *reinterpret_cast<int32_t*>(island + 0x40)) {
        do {
          void* body = (*reinterpret_cast<void***>(island + 0x3c))[bi];
          FUN_0055fbf0(param_1, body);
          FUN_0055fa40(param_1, body);
          bi = bi + 1;
          *reinterpret_cast<uint8_t*>(
              *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(body) + 0x44) + 0x28) = 1;
        } while (bi < *reinterpret_cast<int32_t*>(island + 0x40));
      }
      local_i = local_i + 1;
    } while (local_i < *reinterpret_cast<int32_t*>(m + 0x0c));
  }

  local_i = 0;
  if (0 < *reinterpret_cast<int32_t*>(m + 0x18)) {
    do {
      auto* island = reinterpret_cast<uint8_t*>(
          (*reinterpret_cast<void***>(m + 0x14))[local_i]);
      int32_t bi = 0;
      if (0 < *reinterpret_cast<int32_t*>(island + 0x40)) {
        do {
          void* body = (*reinterpret_cast<void***>(island + 0x3c))[bi];
          FUN_0055fbf0(param_1, body);
          FUN_0055fa40(param_1, body);
          bi = bi + 1;
          *reinterpret_cast<uint8_t*>(
              *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(body) + 0x44) + 0x28) = 1;
        } while (bi < *reinterpret_cast<int32_t*>(island + 0x40));
      }
      local_i = local_i + 1;
    } while (local_i < *reinterpret_cast<int32_t*>(m + 0x18));
  }

  local_i = 0;
  if (0 < *reinterpret_cast<int32_t*>(m + 0x124)) {
    do {
      FUN_0055f7a0(param_1,
                   (*reinterpret_cast<void***>(m + 0x120))[local_i],
                   1);
      local_i = local_i + 1;
    } while (local_i < *reinterpret_cast<int32_t*>(m + 0x124));
  }
}
