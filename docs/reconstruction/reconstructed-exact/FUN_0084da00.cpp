// =============================================================================
// FUN_0084da00
// -----------------------------------------------------------------------------
// Stable ID: aa_0084da00
// Address:   0x0084da00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084da00 @ 0x0084da00
// Stable ID: aa_0084da00
// Embedded strings (evidence for future rename):
//   - "Broken items using this discipline can be repaired at Control Shops\n"
//   - "Broken items using this discipline can be repaired at Fabrication Plants\n"
//   - "Broken items using this discipline can be repaired at Reactors\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007a6de0×3, FUN_007a69d0, FUN_0084da00.
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

void FUN_0084da00(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  

  if (((unaff_ESI != (int *)0x0) && (in_EAX != 0)) && (DAT_00d1b6d8 != 0)) {

    FUN_007a69d0();

    (**(code **)(*unaff_ESI + 0x268))();

    if (*(int *)(in_EAX + 0x1f8) != 0) {

      iVar1 = *unaff_ESI;

      uVar3 = DAT_00afdf0c;

      uVar2 = FUN_007a6de0("Broken items using this discipline can be repaired at Control Shops\n",

                           0xffffffff);

      (**(code **)(iVar1 + 0x22c))(uVar2,uVar3);

    }

    if (*(int *)(in_EAX + 0x1f0) != 0) {

      iVar1 = *unaff_ESI;

      uVar3 = DAT_00afdf0c;

      uVar2 = FUN_007a6de0("Broken items using this discipline can be repaired at Fabrication Plants\n"

                           ,0xffffffff);

      (**(code **)(iVar1 + 0x22c))(uVar2,uVar3);

    }

    if (*(int *)(in_EAX + 500) != 0) {

      iVar1 = *unaff_ESI;

      uVar3 = DAT_00afdf0c;

      uVar2 = FUN_007a6de0("Broken items using this discipline can be repaired at Reactors\n",

                           0xffffffff);

      (**(code **)(iVar1 + 0x22c))(uVar2,uVar3);

    }

  }

  return;

}
