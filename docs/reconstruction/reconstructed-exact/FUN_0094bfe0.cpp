// =============================================================================
// FUN_0094bfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094bfe0
// Address:   0x0094bfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094bfe0 @ 0x0094bfe0
// Stable ID: aa_0094bfe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, if×4, for×2, goto×1, return×1.
//  - Notable callees: FUN_0094bfe0.
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

void FUN_0094bfe0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  int unaff_EBX;

  char *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_170 [4];

  char acStack_160 [51];

  char acStack_12d [17];

  char acStack_11c [20];

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  local_108[0] = '\0';

  local_108[1] = '\0';

  puVar5 = local_106;

  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  if (unaff_ESI != (char *)0x0) {

    pcVar2 = unaff_ESI;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if (pcVar2 != unaff_ESI + 1) {

      iVar4 = -2 - (int)unaff_ESI;

      do {

        cVar1 = *unaff_ESI;

        unaff_ESI[(int)local_106 + iVar4] = cVar1;

        unaff_ESI = unaff_ESI + 1;

      } while (cVar1 != '\0');

      goto LAB_0094c08e;

    }

  }

  if ((*(int **)(unaff_EBX + 0x3048) != (int *)0x0) &&

     (iVar4 = (**(code **)(**(int **)(unaff_EBX + 0x3048) + 0x210))(0), iVar4 != 0)) {

    iVar4 = (**(code **)(**(int **)(unaff_EBX + 0x3048) + 0x210))(0);

    pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))

                               ();

    pcVar2 = local_108;

    do {

      cVar1 = *pcVar3;

      *pcVar2 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

LAB_0094c08e:

  puVar5 = local_170;

  for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  local_170[2] = param_1;

  local_170[0] = 0x8038;

  local_170[3] = param_2;

  pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 0xe98) + 4) + 4) + 4

                                        + *(int *)(unaff_EBX + 0xe98)) + 0x160))();

  pcVar2 = acStack_12d;

  do {

    cVar1 = *pcVar3;

    *pcVar2 = cVar1;

    pcVar3 = pcVar3 + 1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  iVar4 = 0;

  do {

    cVar1 = *(char *)((int)local_106 + iVar4 + -2);

    acStack_11c[iVar4] = cVar1;

    iVar4 = iVar4 + 1;

  } while (cVar1 != '\0');

  pcVar2 = (char *)(*(int *)(unaff_EBX + 0x31f0) + 4);

  iVar4 = -(int)pcVar2;

  do {

    cVar1 = *pcVar2;

    pcVar2[(int)(acStack_160 + iVar4)] = cVar1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if ((*(int *)(unaff_EBX + 0xc7c) != 0) &&

     (cVar1 = (**(code **)(**(int **)(unaff_EBX + 0xc7c) + 8))(), cVar1 != '\0')) {

    (**(code **)(**(int **)(unaff_EBX + 0xc7c) + 0x18))(0xffffffff,local_170,0x68,0);

  }

  return;

}
