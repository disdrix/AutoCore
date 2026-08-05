// =============================================================================
// FUN_00869ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00869ae0
// Address:   0x00869ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00869ae0 @ 0x00869ae0
// Stable ID: aa_00869ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, goto×3, return×2.
//  - Notable callees: CONCAT31, FUN_00869ae0.
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

uint FUN_00869ae0(void)



{

  uint in_EAX;

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint64_t uVar2;

  

  if ((unaff_ESI != 0) && (unaff_EDI != 0)) {

    if (*(int *)(unaff_EDI + 0x2c8) != 0) {

      in_EAX = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 4 + unaff_ESI) + 0x27c)

               )();

      if (*(int *)(unaff_EDI + 0x2c8) < (int)in_EAX) goto LAB_00869be8;

    }

    in_EAX = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 4 + unaff_ESI) + 0x27c))

                       ();

    if (((*(int *)(unaff_EDI + 0x2c4) <= (int)in_EAX) &&

        (((*(int *)(unaff_EDI + 0x2a8) < 2 || (*(int *)(unaff_ESI + 0xcb0) == 0)) ||

         (in_EAX = (uint)*(byte *)(*(int *)(unaff_ESI + 0xcb0) + 0x1d8),

         (int)in_EAX <= *(int *)(unaff_EDI + 0x2a8))))) &&

       ((*(int *)(unaff_EDI + 0x2a4) < 2 ||

        ((in_EAX = *(uint *)(unaff_ESI + 0xcb0), in_EAX != 0 &&

         (*(int *)(unaff_EDI + 0x2a4) <= (int)(uint)*(byte *)(in_EAX + 0x1d8))))))) {

      in_EAX = 0;

      if (*(int *)(unaff_EDI + 0x2e0) != 0 || *(int *)(unaff_EDI + 0x2e4) != 0) {

        uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 4 + unaff_ESI) + 0x16c

                            ))();

        iVar1 = (int)((ulonglong)uVar2 >> 0x20);

        in_EAX = (uint)uVar2;

        if ((*(int *)(unaff_EDI + 0x2e4) <= iVar1) &&

           ((*(int *)(unaff_EDI + 0x2e4) < iVar1 || (*(uint *)(unaff_EDI + 0x2e0) < in_EAX))))

        goto LAB_00869be8;

      }

      if (*(int *)(unaff_EDI + 0x2d8) != 0 || *(int *)(unaff_EDI + 0x2dc) != 0) {

        uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 4 + unaff_ESI) + 0x16c

                            ))();

        iVar1 = (int)((ulonglong)uVar2 >> 0x20);

        in_EAX = (uint)uVar2;

        if ((iVar1 <= *(int *)(unaff_EDI + 0x2dc)) &&

           ((iVar1 < *(int *)(unaff_EDI + 0x2dc) || (in_EAX < *(uint *)(unaff_EDI + 0x2d8)))))

        goto LAB_00869be8;

      }

      return CONCAT31((int3)(in_EAX >> 8),1);

    }

  }

LAB_00869be8:

  return in_EAX & 0xffffff00;

}
