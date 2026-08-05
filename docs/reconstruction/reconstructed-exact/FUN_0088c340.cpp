// =============================================================================
// FUN_0088c340
// -----------------------------------------------------------------------------
// Stable ID: aa_0088c340
// Address:   0x0088c340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088c340 @ 0x0088c340
// Stable ID: aa_0088c340
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, while×1, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_00411e10, FUN_0083cdb0, FUN_0088c340.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ FUN_0088c340(void)



{

  int iVar1;

  int iVar2;

  int *unaff_EBX;

  int iVar3;

  

  iVar1 = DAT_00d1b8ec;

  if (((unaff_EBX[0x14d] != 0) && (DAT_00d1b8ec != 0)) && (*(int *)(DAT_00d1b8ec + 0x590) != 0)) {

    iVar3 = 0;

    FUN_00411e10();

    while( true ) {

      iVar2 = *(int *)(*(int *)(iVar1 + 0x590) + 0x538);

      if (*(char *)(iVar2 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar3 == 0) {

        iVar3 = *(int *)(iVar2 + 0x14);

      }

      else {

        iVar3 = *(int *)(iVar3 + 0x14);

      }

      if (iVar3 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar3 + 8);

      }

      if (iVar2 == 0) break;

      if (*(int *)(iVar2 + 0x608) == unaff_EBX[0x14d]) {

        (**(code **)(*unaff_EBX + 0xfc))(0,0x3f000000);

        DAT_00af9300 = 1;

        *(uint8_t *)(*(int *)(*(int *)(iVar1 + 0x590) + 0x538) + 0x1d) = 0;

        return 1;

      }

    }

    *(uint8_t *)(*(int *)(*(int *)(iVar1 + 0x590) + 0x538) + 0x1d) = 0;

    FUN_0083cdb0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x590),unaff_EBX[0x14d],0);

    (**(code **)(*unaff_EBX + 0xfc))(0,0x3f000000);

    DAT_00af9300 = 1;

    return 1;

  }

  return 0;

}
