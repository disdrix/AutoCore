// =============================================================================
// FUN_008120d0  (scaffold twin of Client_CreateObjectFromCbidPacket_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008120d0
// Address:   0x008120d0 – 0x008122de  (autoassault.exe, image base 0x400000)
// System:    client net / object create
// Dual:      W26-L 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
//            FUN_0092a3b0 residual noted in raw append (bytes).
// =============================================================================

#include <cstdint>

extern "C" void* CVOGReaction_GiveItemByCbid(int cbid);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void FUN_009972a0(void);
extern "C" void FUN_008024d0(int game, std::uint32_t a, std::uint32_t b,
                             int z0, int z1, int z2,
                             std::uint32_t idLo, std::uint32_t idHi);
extern "C" void FUN_007fb2b0(std::uint32_t idLo, std::uint32_t idHi);
extern std::uint32_t DAT_00d1d86c;
extern std::uint32_t DAT_00d1d870;

// stdcall-like RET 8; EAX = object* or null
int* FUN_008120d0(int param_1, int param_2)
{
  int* piVar1;
  std::uint32_t uVar2;
  std::uint32_t uVar3;

  piVar1 = (int*)CVOGReaction_GiveItemByCbid(*(int*)(param_2 + 4));
  if (piVar1 != nullptr) {
    (**(void(__thiscall***)(int*, std::uint32_t, std::uint32_t, int))(*piVar1 + 8))(
        piVar1,
        *reinterpret_cast<std::uint32_t*>(param_2 + 4),
        *reinterpret_cast<std::uint32_t*>(param_1 + 0xe04),
        0);
    (**(void(__thiscall***)(int*))(*piVar1 + 0x1cc))(piVar1);

    uVar2 = 0;
    if ((((*reinterpret_cast<std::uint32_t*>(param_2 + 8) &
           *reinterpret_cast<std::uint32_t*>(param_2 + 0xc)) == 0xffffffffu) &&
         (*(char*)(param_2 + 0xa8) == '\0') &&
         (*(char*)(param_2 + 0xa7) == '\0') &&
         (*(char*)(param_2 + 0xa0) == '\0'))) {
      uVar2 = 1;
    }

    uVar3 = 0;
    piVar1[0x61] = piVar1[0x61] ^ static_cast<int>((uVar2 ^ static_cast<std::uint32_t>(piVar1[0x61])) & 1);

    if (((*reinterpret_cast<std::uint32_t*>(param_2 + 8) &
          *reinterpret_cast<std::uint32_t*>(param_2 + 0xc)) != 0xffffffffu) ||
        (((*(char*)(param_2 + 0xc0) == '\0' && (*(char*)(param_2 + 0xa8) == '\0')) &&
          ((*(char*)(param_2 + 0xa7) == '\0' && (*(char*)(param_2 + 0xa2) == '\0')) &&
           ((*(char*)(param_2 + 0xa0) == '\0' ||
             (*(char*)(*reinterpret_cast<int*>(param_1 + 0xe04) + 0xf5) == '\0'))))))) {
      uVar3 = 1;
    }

    (**(void(__thiscall***)(int*, int, int, std::uint32_t, std::uint32_t,
                            std::uint32_t, std::uint32_t))(*piVar1 + 0xc4))(
        piVar1,
        param_2,
        2,
        *reinterpret_cast<std::uint32_t*>(param_1 + 0xe04),
        static_cast<std::uint32_t>(*(char*)(param_2 + 0xa1) == '\0'),
        uVar3,
        uVar3);

    if (*(char*)(param_2 + 0xa1) != '\0') {
      FUN_009972a0();
      FUN_008024d0(param_1, DAT_00d1d86c, DAT_00d1d870, 0, 0, 0,
                   static_cast<std::uint32_t>(piVar1[0x58]),
                   static_cast<std::uint32_t>(piVar1[0x59]));
    }

    if (*(char*)(param_2 + 0xc0) != '\0') {
      FUN_007fb2b0(static_cast<std::uint32_t>(piVar1[0x58]),
                   static_cast<std::uint32_t>(piVar1[0x59]));
    }
    return piVar1;
  }

  FUN_007a4480(1, "allocatenewobjectfromcbid failed %d Get a programmer",
               *reinterpret_cast<std::uint32_t*>(param_2 + 4));
  return nullptr;
}
