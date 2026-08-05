// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_0042c3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c3d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto
// Address:   0x0042c3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: for×2, if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0042c3d0, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Packet_faile_0042c3d0(int param_1,int param_2)



{

  int iVar1;

  int *in_EAX;

  int *piVar2;

  int *piVar3;

  int unaff_EBX;

  uint uVar4;

  uint uVar5;

  int *piVar6;

  int *piVar7;

  

  uVar4 = *(int *)(param_1 + 0x18) + 7;

  uVar5 = uVar4 >> 3;

  *(int *)(unaff_EBX + 0x94) = *(int *)(unaff_EBX + 0x94) + uVar5;

  piVar2 = malloc(uVar5 + 0x24);

  piVar2[1] = *in_EAX;

  piVar2[2] = in_EAX[1];

  piVar2[3] = in_EAX[2];

  piVar2[4] = in_EAX[3];

  piVar2[5] = in_EAX[4];

  iVar1 = *(int *)(unaff_EBX + 0x78);

  piVar2[7] = uVar5;

  piVar2[6] = iVar1 + param_2;

  piVar6 = *(int **)(param_1 + 0xc);

  piVar7 = piVar2 + 8;

  for (uVar4 = uVar4 >> 5; uVar4 != 0; uVar4 = uVar4 - 1) {

    *piVar7 = *piVar6;

    piVar6 = piVar6 + 1;

    piVar7 = piVar7 + 1;

  }

  piVar3 = (int *)(unaff_EBX + 0x9c);

  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(char *)piVar7 = (char)*piVar6;

    piVar6 = (int *)((int)piVar6 + 1);

    piVar7 = (int *)((int)piVar7 + 1);

  }

  if ((int *)*piVar3 != (int *)0x0) {

    piVar6 = (int *)*piVar3;

    do {

      piVar7 = piVar6;

      if ((uint)piVar2[6] < (uint)piVar7[6]) break;

      piVar6 = (int *)*piVar7;

      piVar3 = piVar7;

    } while ((int *)*piVar7 != (int *)0x0);

  }

  *piVar2 = *piVar3;

  *piVar3 = (int)piVar2;

  return;

}
