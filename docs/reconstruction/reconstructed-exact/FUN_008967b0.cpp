// =============================================================================
// FUN_008967b0  (clean twin — Ghidra symbol)
// Canonical: UI_SkillPanel_UpdateSharedColumnClassHints_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008967b0
// Address:   0x008967b0 – 0x00896986 inclusive (471 B)
// System:    skills-abilities
// Dual:      R11-034 OWN-ONLY 2026-08-05
// Exactness: Decompiler-faithful control flow. ABI notes in header.
// =============================================================================
//
// ABI: EDI-this (panel*); no stack args; plain RET; frame SUB ESP,0x164.
// Parent dual: LookupClassDisplayName_Inferred (0x0051f940).
// Product strings: "This column of skills is shared by the", "class", "%s %s %s."
// sprintf machine arity = 3 format args (decompiler undercounts to 2).
// =============================================================================

#include <cstdint>
#include <cstdio>

extern "C" void*       FUN_007a69d0(void);
extern "C" const char* FUN_007a6de0(void* pool /*ECX*/, const char* src, int mode);
extern "C" const char* FUN_0051f940(unsigned classId, unsigned raceId);
extern "C" void*       DAT_00d1b6d8;

// Native entry: EDI = panel object*. Decompiler shows void(void) + unaff_EDI.
extern "C" void FUN_008967b0(void)
{
  uint8_t bVar1; // classId
  uint8_t bVar2; // raceId
  int iVar3;
  const char* uVar4;
  int unaff_EDI; // live-in panel*
  const char* uVar5;
  uint32_t local_160[24];
  char local_100[256];

  void* locale = FUN_007a69d0(); // ESI in asm
  (void)locale;

  if (DAT_00d1b6d8 != nullptr) {
    local_160[0]  = 1;
    local_160[1]  = 3;
    local_160[2]  = 0;
    local_160[3]  = 2;
    local_160[4]  = 1;
    local_160[5]  = 3;
    local_160[6]  = 0;
    local_160[7]  = 2;
    local_160[8]  = 1;
    local_160[9]  = 3;
    local_160[10] = 0;
    local_160[11] = 2;
    local_160[12] = 1;
    local_160[13] = 3;
    local_160[14] = 0;
    local_160[15] = 2;
    local_160[16] = 1;
    local_160[17] = 3;
    local_160[18] = 0;
    local_160[19] = 2;
    local_160[20] = 3;
    local_160[21] = 1;
    local_160[22] = 2;
    local_160[23] = 0;

    if (*(int*)(unaff_EDI + 0x51c) == 1) {
      if (*(int*)(unaff_EDI + 0x744) != 0) {
        iVar3 = *(int*)(*(int*)(*(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) +
                                0xac + (uintptr_t)DAT_00d1b6d8) + 0x3c);
        bVar1 = *(uint8_t*)(iVar3 + 0x531);
        bVar2 = *(uint8_t*)(iVar3 + 0x532);
        // FUN_007a6de0("class", -1) — result remains as sprintf %3
        uVar4 = FUN_007a6de0(locale, "class", -1);
        // Lookup: cdecl 2-arg; decompiler may show trailing garbage args
        uVar4 = FUN_0051f940(local_160[((unsigned)bVar1 + (unsigned)bVar2 * 4) * 2], bVar2);
        uVar4 = FUN_007a6de0(locale, uVar4, -1);
        uVar5 = FUN_007a6de0(locale, "This column of skills is shared by the", -1);
        // Machine passes 3 strings; third is prior ring("class")
        std::sprintf(local_100, "%s %s %s.", uVar5, uVar4, /* classWord */ "class");
        (**(void(__thiscall***)(int, char*))(**(int**)(unaff_EDI + 0x744) + 0x308))(
            *(int*)(unaff_EDI + 0x744), local_100);
      }
      if (*(int*)(unaff_EDI + 0x748) != 0) {
        iVar3 = *(int*)(*(int*)(*(int*)(*(int*)((uint8_t*)DAT_00d1b6d8 + 4) + 4) +
                                0xac + (uintptr_t)DAT_00d1b6d8) + 0x3c);
        bVar1 = *(uint8_t*)(iVar3 + 0x531);
        bVar2 = *(uint8_t*)(iVar3 + 0x532);
        uVar4 = FUN_007a6de0(locale, "class", -1);
        uVar4 = FUN_0051f940(local_160[((unsigned)bVar1 + (unsigned)bVar2 * 4) * 2 + 1], bVar2);
        uVar4 = FUN_007a6de0(locale, uVar4, -1);
        uVar5 = FUN_007a6de0(locale, "This column of skills is shared by the", -1);
        std::sprintf(local_100, "%s %s %s.", uVar5, uVar4, /* classWord */ "class");
        (**(void(__thiscall***)(int, char*))(**(int**)(unaff_EDI + 0x748) + 0x308))(
            *(int*)(unaff_EDI + 0x748), local_100);
      }
    }
  }
  return;
}
