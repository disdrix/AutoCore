// =============================================================================
// FUN_0091a350
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a350
// Address:   0x0091a350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091a350 @ 0x0091a350
// Stable ID: aa_0091a350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007a0120, FUN_0091a350, FUN_00930fc0.
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

uint32_t /* width from decompiler */ FUN_0091a350(void)



{

  int iVar1;

  char cVar2;

  int *unaff_ESI;

  uint8_t auStack_14 [16];

  

  cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

  if (cVar2 != '\0') {

    unaff_ESI[0x156] = DAT_00aaa668;

    *(uint8_t *)((int)unaff_ESI + 0xa32) = 0;

    (**(code **)(*unaff_ESI + 0x478))();

    if (unaff_ESI[0x1d6] != 0) {

      FUN_00930fc0(&DAT_00d1a840,auStack_14,0,0);

    }

    if (((DAT_00d1b6d8 != 0) && (iVar1 = *(int *)(DAT_00d1b6d8 + 0x250), iVar1 != 0)) &&

       (*(char *)(iVar1 + 0x106) != '\0')) {

      *(uint8_t *)(iVar1 + 0x107) = 0;

      iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x284);

      if (iVar1 != 0) {

        FUN_007a0120(0,2,8,0x61,0,unaff_ESI[0x152],0x3ecccccd,0x3f800000,

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x68),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x68),0x40400000,

                     0xffffffff,0,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x30),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x34),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x30),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x38),DAT_00afdfc8,

                     DAT_00afdfcc,DAT_00afdfd0,DAT_00afdfd4,DAT_00afdfd8,DAT_00afdfdc,DAT_00d1a6c0,

                     DAT_00d1a6c4,DAT_00d1a6c8,1);

      }

    }

    return 1;

  }

  return 0;

}
