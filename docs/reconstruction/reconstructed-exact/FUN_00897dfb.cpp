// =============================================================================
// FUN_00897dfb
// -----------------------------------------------------------------------------
// Stable ID: aa_00897dfb
// Address:   0x00897dfb  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00897dfb @ 0x00897dfb
// Stable ID: aa_00897dfb
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0040cf50, FUN_007fd350, FUN_00897dfb.
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

uint32_t /* width from decompiler */ FUN_00897dfb(void)



{

  char cVar1;

  uint8_t *puVar2;

  int *piVar3;

  int iVar4;

  int unaff_EBX;

  int *unaff_ESI;

  uint8_t *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  cVar1 = FUN_0040cf50();

  if ((cVar1 == '\0') && (DAT_00d1b6d8 != 0)) {

    (**(code **)(*(int *)unaff_ESI[unaff_EBX + -0x9aad] + 0x120))(&stack0x0000000c,1,1);

    (**(code **)(*(int *)unaff_ESI[unaff_EBX + -0x9aad] + 0x140))(&stack0x00000008,1);

    uVar7 = 1;

    if ((int *)unaff_ESI[0x157] == (int *)0x0) {

      iVar4 = *unaff_ESI;

      puVar2 = &stack0x00000010;

    }

    else {

      iVar4 = *(int *)unaff_ESI[0x157];

      puVar2 = &stack0x00000008;

    }

    (**(code **)(iVar4 + 0x120))(puVar2,1,1);

    uVar6 = 1;

    if ((int *)unaff_ESI[0x159] == (int *)0x0) {

      puVar5 = &stack0x0000001c;

      piVar3 = (int *)(**(code **)(*unaff_ESI + 0x140))(puVar5,1);

      iVar4 = *piVar3;

    }

    else {

      puVar5 = (uint8_t *)0x1;

      piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x120))(&stack0x0000000c,1);

      iVar4 = *piVar3;

      piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x159] + 0x140))(&stack0x00000008,1);

      iVar4 = *piVar3 + (iVar4 - (int)puVar2);

    }

    FUN_007fd350(&DAT_00d1a840,puVar5,uVar6,iVar4,uVar7,0);

    return 1;

  }

  return 1;

}
