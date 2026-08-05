// =============================================================================
// FUN_0042fe60
// -----------------------------------------------------------------------------
// Stable ID: aa_0042fe60
// Address:   0x0042fe60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042fe60 @ 0x0042fe60
// Stable ID: aa_0042fe60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: BitStream_writeBits×3, FUN_00424d10, FUN_00424f70, FUN_0042bb40, FUN_0042bc80, FUN_0042bdd0, FUN_0042bdf0, FUN_0042c540.
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

void __fastcall FUN_0042fe60(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int *unaff_ESI;

  uint8_t auStack_27c [636];

  

  iVar1 = unaff_ESI[0x6e];

  if (((iVar1 == 1) || (iVar1 == 4)) || (iVar1 == 0xb)) {

    (**(code **)(*unaff_ESI + 0xc))(param_1);

    FUN_0042c540();

  }

  else if (iVar1 == 7) {

    unaff_ESI[0x6e] = 8;

    (**(code **)(*unaff_ESI + 0x10))(param_1);

    if (unaff_ESI[0x4a] == 0) {

      FUN_00424f70(0x5d2);

      BitStream_writeBits(8,&stack0xfffff677);

      BitStream_writeBits(0x40,unaff_ESI + 0x4e);

      BitStream_writeBits(0x40,unaff_ESI + 0x50);

      FUN_0042bb40(in_EAX,0xff);

      if (*(char *)((int)unaff_ESI + 0x135) != '\0') {

        FUN_007838a0();

        FUN_0042bc80(5,auStack_27c);

        FUN_0042bdf0();

      }

      FUN_0042bdd0(unaff_ESI + 0x3e);

      FUN_00424d10();

    }

    (**(code **)(*param_2 + 0x10))();

    return;

  }

  return;

}
