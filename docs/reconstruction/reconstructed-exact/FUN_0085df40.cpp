// =============================================================================
// FUN_0085df40
// -----------------------------------------------------------------------------
// Stable ID: aa_0085df40
// Address:   0x0085df40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085df40 @ 0x0085df40
// Stable ID: aa_0085df40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, return×1.
//  - Notable callees: FUN_00758460×3, FUN_0085df40.
//  - Return sites: 1.

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

void FUN_0085df40(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ unaff_EBP;

  int *unaff_ESI;

  int iVar2;

  int iVar3;

  int iStack_10;

  uint8_t local_8 [8];

  

  if ((unaff_ESI != (int *)0x0) && (*unaff_ESI != 0)) {

    (**(code **)(*param_1 + 0x140))(local_8,1);

    iVar2 = unaff_ESI[0xe];

    iVar1 = unaff_ESI[0xf];

    iVar3 = 0;

    if (0 < unaff_ESI[0x16]) {

      do {

        if (iStack_10 < unaff_ESI[0x12] + iVar2) {

          iVar2 = unaff_ESI[0xe];

          iVar1 = iVar1 + unaff_ESI[0x11];

        }

        FUN_00758460((float)iVar2,(float)iVar1,(float)(unaff_ESI[0x12] + iVar2),

                     (float)(unaff_ESI[0x13] + iVar1),*unaff_ESI,0,unaff_EBP,1,unaff_ESI + 10,0,

                     &DAT_00d1ecac);

        iVar2 = iVar2 + unaff_ESI[0x10];

        iVar3 = iVar3 + 1;

      } while (iVar3 < unaff_ESI[0x16]);

    }

    iVar3 = 0;

    if (0 < unaff_ESI[0x15]) {

      do {

        if (iStack_10 < unaff_ESI[0x12] + iVar2) {

          iVar2 = unaff_ESI[0xe];

          iVar1 = iVar1 + unaff_ESI[0x11];

        }

        FUN_00758460((float)iVar2,(float)iVar1,(float)(unaff_ESI[0x12] + iVar2),

                     (float)(unaff_ESI[0x13] + iVar1),*unaff_ESI,0,unaff_EBP,1,unaff_ESI + 6,0,

                     &DAT_00d1ecac);

        iVar2 = iVar2 + unaff_ESI[0x10];

        iVar3 = iVar3 + 1;

      } while (iVar3 < unaff_ESI[0x15]);

    }

    iVar3 = 0;

    if (0 < unaff_ESI[0x14]) {

      do {

        if (iStack_10 < unaff_ESI[0x12] + iVar2) {

          iVar2 = unaff_ESI[0xe];

          iVar1 = iVar1 + unaff_ESI[0x11];

        }

        FUN_00758460((float)iVar2,(float)iVar1,(float)(unaff_ESI[0x12] + iVar2),

                     (float)(unaff_ESI[0x13] + iVar1),*unaff_ESI,0,unaff_EBP,1,unaff_ESI + 2,0,

                     &DAT_00d1ecac);

        iVar2 = iVar2 + unaff_ESI[0x10];

        iVar3 = iVar3 + 1;

      } while (iVar3 < unaff_ESI[0x14]);

    }

  }

  return;

}
