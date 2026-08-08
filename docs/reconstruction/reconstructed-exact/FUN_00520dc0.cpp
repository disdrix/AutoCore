// =============================================================================
// FUN_00520dc0  (machine twin of CVOGCharacter_CleanupDraggingObject)
// -----------------------------------------------------------------------------
// Stable ID: aa_00520dc0
// Address:   0x00520dc0 – 0x00520f39  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-001 dual seal
// Exactness: Ghidra-symbol twin; prefer named clean for port notes.
// See:       CVOGCharacter_CleanupDraggingObject.cpp
// =============================================================================

#include <cstdint>

extern "C" {
  std::uint32_t __thiscall FUN_00786a00(void* prof, const char* name);
  void          __fastcall FUN_00786990(void* prof);
  char __thiscall FUN_005714e0(void* grid, void* item, std::uint8_t* outX, std::uint8_t* outY,
                               char allowStack, int page);
  char __thiscall FUN_00571620(void* grid, void* item, std::uint32_t x, std::uint32_t y,
                               std::uint32_t qty);
  unsigned __thiscall FUN_004fabc0(void* host, void* item, int* outOpt);
  void* __thiscall FUN_00502e90(void* host, void* item);
}

extern void* DAT_00afa27c;

// ECX=this; RET 4; AL bool — assembly-corrected (not raw decompiler)
bool __thiscall FUN_00520dc0(void* param_1 /*, std::uint32_t unused */)
{
  FUN_00786a00(DAT_00afa27c, "CVOGCharacter::CleanupDraggingObject");

  void* piVar1 = *reinterpret_cast<void**>(reinterpret_cast<char*>(param_1) + 0xCD0);
  if (piVar1 == nullptr) {
    FUN_00786990(DAT_00afa27c);
    return false;
  }

  std::uint8_t local_14 = 0;
  std::uint8_t local_18 = 0;

  void* host = *reinterpret_cast<void**>(reinterpret_cast<char*>(param_1) + 0x250);
  void* cargo = *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x2B0);
  if (FUN_005714e0(cargo, piVar1, &local_14, &local_18, 1, -1) != 0) {
    auto** vtbl = *reinterpret_cast<void***>(piVar1);
    using QtyFn = std::uint32_t(__thiscall*)(void*);
    std::uint32_t uVar3 = reinterpret_cast<QtyFn>(vtbl[0x25C / 4])(piVar1);
    if (FUN_00571620(cargo, piVar1, local_14, local_18, uVar3) != 0)
      goto LAB_00520f0a;
  }

  void* locker = *reinterpret_cast<void**>(reinterpret_cast<char*>(param_1) + 0xCBC);
  if (FUN_005714e0(locker, piVar1, &local_14, &local_18, 1, -1) != 0) {
    auto** vtbl = *reinterpret_cast<void***>(piVar1);
    using QtyFn = std::uint32_t(__thiscall*)(void*);
    std::uint32_t uVar3 = reinterpret_cast<QtyFn>(vtbl[0x25C / 4])(piVar1);
    if (FUN_00571620(locker, piVar1, local_14, local_18, uVar3) != 0)
      goto LAB_00520f0a;
  }

  {
    int iStack_10 = 0;
    unsigned iVar4 = FUN_004fabc0(host, piVar1, &iStack_10);
    if (iStack_10 == 0 &&
        (iVar4 == 0 || iVar4 == 1 || iVar4 == 10 || iVar4 == 0xD || iVar4 == 0xF)) {
      FUN_00502e90(host, piVar1);
    }
  }

LAB_00520f0a:
  *reinterpret_cast<void**>(reinterpret_cast<char*>(param_1) + 0xCD0) = nullptr;
  FUN_00786990(DAT_00afa27c);
  return true;
}
