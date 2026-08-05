// =============================================================================
// FUN_0094d380
// -----------------------------------------------------------------------------
// Stable ID: aa_0094d380
// Address:   0x0094d380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094d380 @ 0x0094d380
// Stable ID: aa_0094d380
// Embedded strings (evidence for future rename):
//   - "Either select someone and type /enemy or type /enemy [name] to add someont to your enemies"
//   - "That person is already on your enemy list."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×9, return×6, do×5, while×5, for×1, goto×1.
//  - Notable callees: FUN_00573bb0, FUN_008073b0, FUN_008f8200, FUN_0094d380.
//  - Strings: "That person is already on your enemy list.".
//  - Return sites: 6.

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

void FUN_0094d380(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  char *pcVar3;

  int iVar4;

  char *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  char acStack_120 [24];

  uint16_t local_108;

  uint32_t /* width from decompiler */ local_106 [64];

  

  local_108 = 0;

  puVar5 = local_106;

  for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  if (unaff_EBX != (char *)0x0) {

    pcVar2 = unaff_EBX;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if (pcVar2 != unaff_EBX + 1) {

      iVar4 = -2 - (int)unaff_EBX;

      do {

        cVar1 = *unaff_EBX;

        unaff_EBX[(int)local_106 + iVar4] = cVar1;

        unaff_EBX = unaff_EBX + 1;

      } while (cVar1 != '\0');

      goto LAB_0094d42e;

    }

  }

  if ((*(int **)(in_EAX + 0x3048) != (int *)0x0) &&

     (iVar4 = (**(code **)(**(int **)(in_EAX + 0x3048) + 0x210))(0), iVar4 != 0)) {

    iVar4 = (**(code **)(**(int **)(in_EAX + 0x3048) + 0x210))(0);

    pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160))

                               ();

    pcVar2 = (char *)&local_108;

    do {

      cVar1 = *pcVar3;

      *pcVar2 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

LAB_0094d42e:

  pcVar2 = (char *)&local_108;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (pcVar2 == (char *)((int)&local_108 + 1)) {

    if (**(int **)(in_EAX + 0xf40) == 0) {

      return;

    }

    if (DAT_00d1b8dc == 0) {

      return;

    }

    pcVar2 = 

    "Either select someone and type /enemy or type /enemy [name] to add someont to your enemies list."

    ;

  }

  else {

    iVar4 = FUN_00573bb0(&local_108);

    if (iVar4 == 0) {

      uStack_12c = 0;

      acStack_120[0] = '\0';

      acStack_120[1] = '\0';

      acStack_120[2] = '\0';

      acStack_120[3] = '\0';

      acStack_120[4] = '\0';

      acStack_120[5] = '\0';

      acStack_120[6] = '\0';

      acStack_120[7] = '\0';

      acStack_120[8] = '\0';

      acStack_120[9] = '\0';

      acStack_120[10] = '\0';

      acStack_120[0xb] = '\0';

      acStack_120[0xc] = '\0';

      acStack_120[0xd] = '\0';

      acStack_120[0xe] = '\0';

      acStack_120[0xf] = '\0';

      acStack_120[0x10] = '\0';

      acStack_120[0x11] = '\0';

      acStack_120[0x12] = '\0';

      acStack_120[0x13] = '\0';

      uStack_124 = param_2;

      acStack_120[0x14] = '\0';

      acStack_120[0x15] = '\0';

      acStack_120[0x16] = '\0';

      acStack_120[0x17] = '\0';

      uStack_130 = 0x802c;

      uStack_128 = param_1;

      iVar4 = 0;

      do {

        cVar1 = *(char *)((int)local_106 + iVar4 + -2);

        acStack_120[iVar4] = cVar1;

        iVar4 = iVar4 + 1;

      } while (cVar1 != '\0');

      FUN_008073b0(0x28,&uStack_130);

      return;

    }

    if (**(int **)(in_EAX + 0xf40) == 0) {

      return;

    }

    if (DAT_00d1b8dc == 0) {

      return;

    }

    pcVar2 = "That person is already on your enemy list.";

  }

  FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,pcVar2,0);

  return;

}
