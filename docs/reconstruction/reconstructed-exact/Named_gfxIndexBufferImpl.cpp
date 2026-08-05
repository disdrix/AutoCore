// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00985b40, FUN_00988e90, FUN_00988f20, vog_LogMessage.
//  - Strings: ",0x61,3,

                   ".
//  - Return sites: 2.

// =============================================================================
// Named_gfxIndexBufferImpl
// -----------------------------------------------------------------------------
// Stable ID: aa_00988f20
// Address:   0x00988f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxIndexBufferImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Named_gfxIndexBufferImpl(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,char param_5)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  FUN_00988e90();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = param_2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = param_4;

  if (param_5 == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 2;

  }

  else {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 4;

  }

  iVar3 = FUN_00985b40(DAT_00d1f648,param_1,param_3);

  if (iVar3 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxIndexBufferImpl.cpp",0x61,3,

                   "Failed to Allocate Index Buffer");

    iVar3 = -1;

  }

  else {

    if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar3 = (**(code **)*param_4)(param_1);

    }

    iVar2 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x390) =

           *(int *)(DAT_00d1f614 + 0x390) + *(int *)(param_1 + 0x14) * *(int *)(param_1 + 0x1c);

      piVar1 = (int *)(iVar2 + 0x348);

      *piVar1 = *piVar1 + *(int *)(param_1 + 0x1c);

      piVar1 = (int *)(iVar2 + 0x344);

      *piVar1 = *piVar1 + 1;

      return iVar3;

    }

  }

  return iVar3;

}
