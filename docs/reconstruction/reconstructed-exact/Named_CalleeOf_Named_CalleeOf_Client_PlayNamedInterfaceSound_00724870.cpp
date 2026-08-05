// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00724870
// -----------------------------------------------------------------------------
// Stable ID: aa_00724870
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x00724870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×7, do×6, while×6, goto×2, for×2, return×2.
//  - Notable callees: PathFileExistsA×2, FUN_00722790, FUN_00724870, FUN_007b6420, FUN_007b66c0, FUN_007b6a20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
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

uint8_t Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00724870(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  char *in_EAX;

  int iVar2;

  BOOL BVar3;

  char *pcVar4;

  char *pcVar5;

  uint uVar6;

  char *pcVar7;

  uint uVar8;

  char *pcVar9;

  char *pcVar10;

  CHAR local_208 [259];

  char local_105;

  char local_104 [260];

  

  local_105 = '\0';

  iVar2 = -(int)in_EAX;

  do {

    cVar1 = *in_EAX;

    in_EAX[(int)(local_208 + iVar2)] = cVar1;

    in_EAX = in_EAX + 1;

  } while (cVar1 != '\0');

  FUN_00722790(local_208);

  iVar2 = FUN_007b6a20();

  if ((*(byte *)(iVar2 + 4) & 1) != 0) {

    BVar3 = PathFileExistsA(local_208);

    if (BVar3 != 0) goto LAB_00724972;

    pcVar4 = (char *)FUN_007b6420();

    pcVar10 = (char *)&DAT_00d1e574;

    do {

      pcVar7 = pcVar10;

      if (0xf < *(uint *)(pcVar10 + 0x14)) {

        pcVar7 = *(char **)pcVar10;

      }

      pcVar9 = local_104;

      do {

        cVar1 = *pcVar7;

        *pcVar9 = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar9 = pcVar9 + 1;

        pcVar5 = pcVar4;

      } while (cVar1 != '\0');

      do {

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      uVar6 = (int)pcVar5 - (int)pcVar4;

      pcVar7 = &local_105;

      do {

        pcVar9 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = pcVar4;

      for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *pcVar7 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar7 = pcVar7 + 1;

      }

      BVar3 = PathFileExistsA(local_104);

      if (BVar3 != 0) goto LAB_00724972;

      pcVar10 = pcVar10 + 0x1c;

    } while ((int)pcVar10 < 0xd1e7a4);

  }

  cVar1 = FUN_007b66c0(iVar2);

  if (cVar1 == '\0') {

    return 0;

  }

LAB_00724972:

  if (param_2 != 0) {

    pcVar4 = local_208;

    param_2 = param_2 - (int)pcVar4;

    do {

      cVar1 = *pcVar4;

      pcVar4[param_2] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = 2;

  }

  return 1;

}
