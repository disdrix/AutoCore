// =============================================================================
// FUN_00788fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00788fd0
// Address:   0x00788fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00788fd0 @ 0x00788fd0
// Stable ID: aa_00788fd0
// Embedded strings (evidence for future rename):
//   - "NDAssetImage::GetPixel() - request of pixel [%d,%d] is outside image[%dx%d] or not locked."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_004336c0, FUN_00788fd0, FUN_007a4480, NDAssetImage::GetPixel.
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

uint __thiscall FUN_00788fd0(int param_1,uint param_2,uint param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    if ((((-1 < (int)param_2) && (-1 < (int)param_3)) && (param_2 < *(uint *)(iVar1 + 0xc))) &&

       (param_3 < *(uint *)(iVar1 + 0x10))) {

      FUN_004336c0(&param_3,param_2,param_3,1);

      return param_3 >> 8 & 0xff;

    }

    if (iVar1 != 0) {

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

      goto LAB_00788ffd;

    }

  }

  uVar2 = 0;

LAB_00788ffd:

  if (iVar1 == 0) {

    uVar3 = 0;

  }

  else {

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

  }

  FUN_007a4480(1,

               "NDAssetImage::GetPixel() - request of pixel [%d,%d] is outside image[%dx%d] or not locked."

               ,param_2,param_3,uVar3,uVar2);

  return 0;

}
