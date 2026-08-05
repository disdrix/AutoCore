// =============================================================================
// FUN_004cf3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf3b0
// Address:   0x004cf3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cf3b0 @ 0x004cf3b0
// Stable ID: aa_004cf3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: ROUND×2, FUN_004cf3b0, Object_ResolveFromTFID.
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

void FUN_004cf3b0(int *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  float unaff_ESI;

  TFID_16 TStack_14;

  float fStack_4;

  

  iVar1 = (**(code **)(*param_1 + 0x210))(0);

  if (iVar1 == 0) {

    iVar1 = (**(code **)(*param_1 + 0x1d8))();

    if (iVar1 != 0) {

      TStack_14._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x234);

      if (((*(uint *)(iVar1 + 0x228) & *(uint *)(iVar1 + 0x22c)) != 0xffffffff) ||

         ((char)*(uint32_t /* width from decompiler */ *)(iVar1 + 0x230) != '\0')) {

        TStack_14.dwCoidLo = *(uint *)(iVar1 + 0x228);

        TStack_14.dwCoidHi = *(uint *)(iVar1 + 0x22c);

        TStack_14._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x230);

        TStack_14._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x234);

        piVar2 = Object_ResolveFromTFID(&TStack_14);

        if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x1dc))(), iVar1 != 0)) {

          return;

        }

      }

    }

    (**(code **)(*param_1 + 0x23c))();

    (**(code **)(*param_1 + 0x244))();

    iVar1 = (**(code **)(*param_1 + 0x244))();

    (**(code **)(*param_1 + 0x248))

              ((int)ROUND((*(float *)(&DAT_009cc390 + param_2 * 4) + g_flOne) *

                          ((float)iVar1 / (*(float *)(&DAT_009cc390 + (int)param_1 * 4) + g_flOne)))

              );

    iVar1 = (**(code **)(*param_1 + 0x244))();

    fStack_4 = (float)iVar1 * unaff_ESI;

    (**(code **)(*param_1 + 0x240))((int)ROUND(fStack_4));

  }

  return;

}
