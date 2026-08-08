// =============================================================================
// FUN_0090c810  (twin of MedalUI_CountDisplayableEntries_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c810
// Address:   0x0090c810  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-103 dual — Ghidra-name twin of named clean
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer: MedalUI_CountDisplayableEntries_Inferred.cpp
// Retired: Named_VOG_DEBUG_STOP_0090c810.cpp (error-string misname)

#include <cstdint>

extern "C" void* __cdecl FUN_0051a0e0(uint32_t id);  // MedalDef_LookupById
extern "C" void __cdecl FUN_007a4480(int channel, const char* msg);

// EBX = character* (DAT_00d1b6d8); EAX = count; bare RET
extern "C" int FUN_0090c810(void)
{
  uint8_t* character;
  int iVar2;
  uint8_t* iVar1;
  uint8_t* iVar3;
  void* lookup;

#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov character, ebx
  }
#else
  character = nullptr;
#endif

  if (character == nullptr) {
    return 0;
  }

  if (*reinterpret_cast<int*>(character + 0x574) == 0) {
    iVar2 = 0;
  } else {
    iVar2 = (*reinterpret_cast<int*>(character + 0x578) -
             *reinterpret_cast<int*>(character + 0x574)) >>
            2;
  }

  iVar1 = *reinterpret_cast<uint8_t**>(character + 0x540);
  iVar3 = nullptr;

  if (iVar1[0x1d] != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  iVar1[0x1d] = 1;

  while (true) {
    iVar1 = *reinterpret_cast<uint8_t**>(character + 0x540);
    if (iVar1[0x1d] == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    if (iVar3 == nullptr) {
      iVar3 = *reinterpret_cast<uint8_t**>(iVar1 + 0x14);
    } else {
      iVar3 = *reinterpret_cast<uint8_t**>(iVar3 + 0x14);
    }

    if (iVar3 == nullptr) {
      iVar1 = nullptr;
    } else {
      iVar1 = *reinterpret_cast<uint8_t**>(iVar3 + 0x08);
    }

    if (iVar1 == nullptr) {
      break;
    }

    lookup = FUN_0051a0e0(*reinterpret_cast<uint32_t*>(iVar1 + 0x100));
    if (lookup != nullptr) {
      iVar2 = iVar2 + 1;
    }
  }

  (*reinterpret_cast<uint8_t**>(character + 0x540))[0x1d] = 0;
  return iVar2;
}
