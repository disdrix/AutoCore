// =============================================================================
// FUN_0053e270
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e270
// Address:   0x0053e270  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e270 @ 0x0053e270
// Stable ID: aa_0053e270
// Embedded strings (evidence for future rename):
//   - "ERROR: Invalide rotation in map:%s(%d), object COID:%I64d CBID:%d\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0053d810, FUN_0053e270, FUN_00568100, FUN_007a4480, s.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

FUN_0053e270(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  char *pcVar4;

  

  uVar2 = param_4;

  pcVar4 = (char *)FUN_00568100(&param_4);

  if (*pcVar4 == '\0') {

    if (param_2 != 0) {

      iVar1 = *(int *)(param_1[1] + 4);

      FUN_007a4480(1,"ERROR: Invalide rotation in map:%s(%d), object COID:%I64d CBID:%d\n",

                   param_2 + 0xb4,*(uint32_t /* width from decompiler */ *)(param_2 + 0xfc),

                   *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x164),

                   *(uint32_t /* width from decompiler */ *)((int)param_1 + iVar1 + 0x168),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0xac + (int)param_1) + 0x34));

    }

  }

  else {

    *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) = param_2;

    cVar3 = FUN_0053d810(param_3,uVar2,param_5);

    if (cVar3 != '\0') {

      if (*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) != 0) {

        (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x144))();

        (**(code **)(*param_1 + 8))();

        return 1;

      }

    }

  }

  return 0;

}
