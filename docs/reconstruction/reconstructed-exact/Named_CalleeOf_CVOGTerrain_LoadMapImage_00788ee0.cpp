// =============================================================================
// Named_CalleeOf_CVOGTerrain_LoadMapImage_00788ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00788ee0
// Callee of CVOGTerrain_LoadMapImage
// Address:   0x00788ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrain_LoadMapImage: config/load helper. Evidence string: "NDAssetImage::GetPixel() - request of pixel [%d,%d] is outside image[%dx%d] or not locked.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "NDAssetImage::GetPixel() - request of pixel [%d,%d] is outside image[%dx%d] or not locked."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×2.
//  - Notable callees: CONCAT31, FUN_00788ee0, FUN_007a4480, NDAssetImage::GetPixel.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGTerrain_LoadMapImage
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Named_CalleeOf_CVOGTerrain_LoadMapImage_00788ee0(int param_1,uint param_2,uint param_3)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  uVar3 = *(uint *)(param_1 + 4);

  if (uVar3 == 0) {

LAB_00788f0b:

    uVar5 = 0;

  }

  else {

    if ((((-1 < (int)param_2) && (-1 < (int)param_3)) && (param_2 < *(uint *)(uVar3 + 0xc))) &&

       (param_3 < *(uint *)(uVar3 + 0x10))) {

      piVar1 = (int *)(uVar3 + 0x1b0);

      if (((*piVar1 != 0) && (-1 < (int)param_3)) &&

         (((int)param_3 < *(int *)(uVar3 + 0x10) &&

          ((-1 < (int)param_2 && (uVar3 = *(uint *)(uVar3 + 0xc), (int)param_2 < (int)uVar3)))))) {

        iVar4 = uVar3 * param_3 + *piVar1;

        return CONCAT31((int3)((uint)iVar4 >> 8),*(uint8_t *)(iVar4 + param_2));

      }

      goto LAB_00788f2b;

    }

    if (uVar3 == 0) goto LAB_00788f0b;

    uVar5 = *(uint32_t /* width from decompiler */ *)(uVar3 + 0x10);

  }

  if (uVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(uVar3 + 0xc);

  }

  uVar3 = FUN_007a4480(1,

                       "NDAssetImage::GetPixel() - request of pixel [%d,%d] is outside image[%dx%d] or not locked."

                       ,param_2,param_3,uVar2,uVar5);

LAB_00788f2b:

  return uVar3 & 0xffffff00;

}
