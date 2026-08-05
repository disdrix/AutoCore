// =============================================================================
// FUN_0071f8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f8c0
// Address:   0x0071f8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f8c0 @ 0x0071f8c0
// Stable ID: aa_0071f8c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×1, while×1.
//  - Notable callees: FUN_0071f8c0, Sleep.
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

int FUN_0071f8c0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int *unaff_ESI;

  

  if (unaff_ESI == (int *)0x0) {

    return -0x7ffbfe10;

  }

  if (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0) {

    *unaff_EBX = 0;

  }

  iVar1 = (**(code **)(*unaff_ESI + 0x24))();

  if (-1 < iVar1) {

    if (((uint)unaff_ESI & 2) != 0) {

      do {

        iVar1 = (**(code **)(*unaff_ESI + 0x50))();

        if (iVar1 == -0x7787ff6a) {

          Sleep(10);

        }

        iVar1 = (**(code **)(*unaff_ESI + 0x50))();

      } while (iVar1 == -0x7787ff6a);

      if (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0) {

        *unaff_EBX = 1;

      }

      return 0;

    }

    iVar1 = 1;

  }

  return iVar1;

}
