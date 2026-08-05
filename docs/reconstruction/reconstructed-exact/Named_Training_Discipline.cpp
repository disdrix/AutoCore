// =============================================================================
// Named_Training_Discipline
// -----------------------------------------------------------------------------
// Stable ID: aa_00895590
// Address:   0x00895590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Training_Discipline @ 0x00895590
// Stable ID: aa_00895590
// Embedded strings (evidence for future rename):
//   - "Training Discipline"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0052ad60, FUN_0052b040, FUN_007a69d0, FUN_007a6de0, FUN_007fb690, Named_Training_Discipline.
//  - Strings: "Training Discipline".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Training Discipline"
 * Domain alias of FUN_00895590 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Training_Discipline(void)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  code *pcVar7;

  uint32_t /* width from decompiler */ local_204;

  uint32_t /* width from decompiler */ local_200;

  uint8_t local_1fc [508];

  

  if ((((*(int *)(unaff_ESI + 0x520) != -1) &&

       (cVar1 = FUN_0052b040(*(int *)(unaff_ESI + 0x520),local_1fc), cVar1 != '\0')) &&

      (DAT_00d1b6d8 != 0)) &&

     (iVar2 = FUN_0052ad60(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x520)), iVar2 < *(int *)(unaff_ESI + 0x524))

     ) {

    iVar2 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

            (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

    if ((*(int *)(unaff_ESI + 0x52c) <= iVar2) &&

       ((*(int *)(unaff_ESI + 0x52c) < iVar2 ||

        (*(uint *)(unaff_ESI + 0x528) <=

         *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))) {

      pcVar7 = FUN_009361c0;

      local_200 = 0xff;

      local_204 = 0;

      uVar5 = 0;

      uVar4 = 0xffffffff;

      pcVar3 = "Training Discipline";

      uVar6 = DAT_00afdef4;

      FUN_007a69d0("Training Discipline",0xffffffff,0,DAT_00afdef4,0,0xff,FUN_009361c0);

      uVar4 = FUN_007a6de0(pcVar3,uVar4);

      FUN_007fb690(0,0x40800000,uVar4,uVar5,uVar6,local_204,local_200,pcVar7);

    }

  }

  return;

}
