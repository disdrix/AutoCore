// =============================================================================
// FUN_00928730
// -----------------------------------------------------------------------------
// Stable ID: aa_00928730
// Address:   0x00928730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928730 @ 0x00928730
// Stable ID: aa_00928730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_00928730.
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

uint32_t /* width from decompiler */

FUN_00928730(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (*(int *)(unaff_ESI + 0x1c) != 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

    return 0;

  }

  if ((unaff_EDI != (uint32_t /* width from decompiler */ *)0x0) || (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0)) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x4c) + 0x4c))

                      (*(int **)(unaff_ESI + 0x4c),0,&local_8,0,0);

    if (iVar1 < 0) {

      return 0;

    }

    if (unaff_EDI != (uint32_t /* width from decompiler */ *)0x0) {

      *unaff_EDI = uStack_4;

    }

    if (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0) {

      *unaff_EBX = local_8;

    }

    if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_2 = 0;

    }

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = 0;

    }

    if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14);

    }

    if (param_5 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_5 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18);

    }

  }

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_1 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 1;

  return 1;

}
