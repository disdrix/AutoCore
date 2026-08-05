// =============================================================================
// FUN_007ad3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ad3c0
// Address:   0x007ad3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ad3c0 @ 0x007ad3c0
// Stable ID: aa_007ad3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007ad3c0.
//  - Return sites: 3.

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

FUN_007ad3c0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char cVar5;

  

  uVar4 = param_8;

  uVar3 = param_7;

  uVar2 = param_6;

  piVar1 = param_2;

  if (param_2 == (int *)0x0) {

    return 0;

  }

  if ((*(int *)(param_1 + 0x2b0) != 0) &&

     (cVar5 = (**(code **)(**(int **)(param_1 + 0x2b0) + 0x27c))

                        (param_2,param_3,param_4,param_5,param_6,param_7,param_8), cVar5 != '\0')) {

    return 1;

  }

  param_2 = (int *)0xffffffff;

  (**(code **)(*piVar1 + 0x25c))(uVar4,param_3,param_4,param_5,uVar2,uVar3,&param_2,0);

  return 1;

}
