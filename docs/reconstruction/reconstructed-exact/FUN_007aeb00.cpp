// =============================================================================
// FUN_007aeb00
// -----------------------------------------------------------------------------
// Stable ID: aa_007aeb00
// Address:   0x007aeb00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aeb00 @ 0x007aeb00
// Stable ID: aa_007aeb00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×7, return×5.
//  - Notable callees: FUN_007aeb00.
//  - Return sites: 5.

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

FUN_007aeb00(int *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint8_t auStack_58 [84];

  uint8_t uStack_4;

  uint8_t uStack_3;

  uint8_t uStack_2;

  uint8_t uStack_1;

  

  cVar1 = (**(code **)(*param_1 + 0x324))();

  if (cVar1 == '\0') {

    cVar1 = (**(code **)(*param_1 + 0x328))();

    if (cVar1 == '\0') {

      uVar5 = (**(code **)(*param_1 + 0x14c))(param_2,param_3,param_4);

      return uVar5;

    }

    iVar2 = (**(code **)(*param_1 + 700))();

    if (iVar2 != 0) {

      cVar1 = (**(code **)(*param_1 + 0x14c))(param_2,param_3,param_4);

      if (cVar1 != '\0') {

        uVar5 = (**(code **)(*param_1 + 0x168))(param_2,param_3,param_4);

        return uVar5;

      }

      return 0;

    }

  }

  else {

    iVar2 = (**(code **)(*param_1 + 0x290))();

    if (iVar2 != 0) {

      uStack_2 = 0xff;

      uStack_3 = 0xff;

      uStack_4 = 0xff;

      uStack_1 = 0xff;

      uStack_60 = *param_2;

      uStack_5c = param_2[1];

      piVar3 = (int *)(**(code **)(*param_1 + 0x1a0))();

      iVar2 = (**(code **)(*piVar3 + 0x10))(&uStack_60,5,auStack_58,0);

      if (iVar2 != 0) {

        iVar4 = (**(code **)(*param_1 + 0x290))();

        if (iVar2 == iVar4) {

          return 1;

        }

      }

    }

  }

  return 0;

}
