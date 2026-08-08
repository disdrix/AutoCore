// =============================================================================
// FUN_005310a0  — Ghidra twin of Character_GiveItemByCbid_Inventory_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005310a0
// Address:   0x005310a0  (autoassault.exe, image base 0x400000)
// Body:      0x005310a0–0x00531247 inclusive (424 B / 0x1A8)
// System:    missions-progression / inventory-transfer
// Generated: 2026-08-05 MEGA-003 dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite; assembly-corrected arity/loop.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Named reconstruction: Character_GiveItemByCbid_Inventory_Inferred.cpp
// Purpose: give count items by CBID into inventory (factory + serial + SendAdd).
// ABI: __thiscall ECX=character; stack cbid, count; RET 8; AL bool.

#include <cstdint>

extern "C" void *__cdecl CVOGReaction_GiveItemByCbid(int cbid, int unused_zero);
extern "C" void __thiscall FUN_00512160(void *item, std::uint32_t lo,
                                        std::uint32_t hi, std::uint8_t flag);
extern "C" std::uint8_t __fastcall FUN_00513e70(void *item);
extern "C" void __thiscall Client_SendInventoryAddItem(void *character,
                                                       void *item,
                                                       std::uint32_t flag);
extern "C" unsigned __cdecl FUN_007a4480(int level, const char *fmt, ...);

static constexpr float g_flOne = 1.0f;

// Ghidra-shaped formals: param_1 = ECX this; param_2 = cbid; param_3 = count
// (decompiler surface historically dropped param_3 — assembly has RET 8).
extern "C" std::uint8_t __thiscall FUN_005310a0(std::int32_t param_1,
                                                 std::int32_t param_2,
                                                 std::int32_t param_3)
{
  std::int32_t iVar1;
  std::int32_t iVar2;
  std::uint8_t first;
  void *piVar4;
  void *puVar5;
  std::uint32_t uVar6;
  std::uint32_t uVar7;
  std::int32_t remaining;

  iVar1 = *reinterpret_cast<std::int32_t *>(
      *reinterpret_cast<std::int32_t *>(
          *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) +
      0xa8 + param_1);

  if (*reinterpret_cast<char *>(iVar1 + 0x7e) == '\0') {
    return 1;
  }

  remaining = param_3;
  first = 0;
  uVar7 = static_cast<std::uint32_t>(param_3);

  do {
    piVar4 = CVOGReaction_GiveItemByCbid(param_2, 0);
    if (piVar4 == nullptr) {
      FUN_007a4480(1, "Invalid CBID: %d (bad item)", param_2);
      return 0;
    }

    iVar1 = *reinterpret_cast<std::int32_t *>(
        *reinterpret_cast<std::int32_t *>(
            *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) +
        0xa8 + param_1);

    // vtbl+8
    (*reinterpret_cast<void(__thiscall **)(void *, std::int32_t, std::int32_t,
                                           std::int32_t)>(
        *reinterpret_cast<std::int32_t *>(piVar4) + 8))(
        piVar4, param_2, iVar1, 1);

    uVar6 = *reinterpret_cast<std::uint32_t *>(iVar1 + 0xe6e0);
    iVar2 = *reinterpret_cast<std::int32_t *>(iVar1 + 0xe6e4);
    *reinterpret_cast<std::uint32_t *>(iVar1 + 0xe6e0) = uVar6 + 1;
    *reinterpret_cast<std::uint32_t *>(iVar1 + 0xe6e4) =
        static_cast<std::uint32_t>(iVar2) +
        static_cast<std::uint32_t>(uVar6 > 0xfffffffeu);
    FUN_00512160(piVar4, uVar6, static_cast<std::uint32_t>(iVar2), 1);

    puVar5 = (*reinterpret_cast<void *(__thiscall **)(void *)>(
        *reinterpret_cast<std::int32_t *>(piVar4) + 0x1cc))(piVar4);
    (*reinterpret_cast<void(__thiscall **)(
        void *, std::int32_t, float, float, float, float, float, float, float,
        std::int32_t)>(*reinterpret_cast<std::int32_t *>(puVar5)))(
        puVar5, 1, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, g_flOne, 0);

    (*reinterpret_cast<void(__thiscall **)(void *, std::uint32_t)>(
        *reinterpret_cast<std::int32_t *>(piVar4) + 0x2a4))(
        piVar4,
        *reinterpret_cast<std::uint32_t *>(
            *reinterpret_cast<std::int32_t *>(
                *reinterpret_cast<std::int32_t *>(
                    *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) +
                0xa8 + param_1) +
            0xe4e8));

    (*reinterpret_cast<void(__thiscall **)(void *, std::int32_t)>(
        *reinterpret_cast<std::int32_t *>(piVar4) + 0x218))(
        piVar4,
        *reinterpret_cast<std::int32_t *>(
            *reinterpret_cast<std::int32_t *>(
                *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) +
            0xa8 + param_1));

    if (first == 0) {
      first = 1;
      if (FUN_00513e70(piVar4) != 0) {
        remaining = 1;
      } else {
        uVar7 = 1;
      }
    }

    (*reinterpret_cast<void(__thiscall **)(void *, std::uint32_t)>(
        *reinterpret_cast<std::int32_t *>(piVar4) + 0x260))(piVar4, uVar7);
    Client_SendInventoryAddItem(reinterpret_cast<void *>(param_1), piVar4,
                                uVar7);

    remaining -= 1;
  } while (remaining != 0);

  return 1;
}
