// =============================================================================
// FUN_00803a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00803a20
// Address:   0x00803a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803a20 @ 0x00803a20
// Stable ID: aa_00803a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00803a20, strncpy.
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

void __fastcall FUN_00803a20(uint32_t /* width from decompiler */ param_1,byte *param_2)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  byte *pbVar4;

  int *unaff_EDI;

  bool bVar5;

  

  if (param_2 != (byte *)0x0) {

    pbVar2 = (byte *)(unaff_EDI + 0x18);

    pbVar4 = param_2;

    do {

      bVar1 = *pbVar2;

      bVar5 = bVar1 < *pbVar4;

      if (bVar1 != *pbVar4) {

LAB_00803a54:

        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);

        goto LAB_00803a59;

      }

      if (bVar1 == 0) break;

      bVar1 = pbVar2[1];

      bVar5 = bVar1 < pbVar4[1];

      if (bVar1 != pbVar4[1]) goto LAB_00803a54;

      pbVar2 = pbVar2 + 2;

      pbVar4 = pbVar4 + 2;

    } while (bVar1 != 0);

    iVar3 = 0;

LAB_00803a59:

    if (iVar3 != 0) {

      strncpy((char *)(unaff_EDI + 0x18),(char *)param_2,0x100);

      unaff_EDI[0x16] = 1;

                    /* WARNING: Could not recover jumptable at 0x00803a7b. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*unaff_EDI + 0x38))();

      return;

    }

  }

  return;

}
