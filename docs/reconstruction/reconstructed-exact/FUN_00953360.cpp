// =============================================================================
// FUN_00953360
// -----------------------------------------------------------------------------
// Stable ID: aa_00953360
// Address:   0x00953360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00953360 @ 0x00953360
// Stable ID: aa_00953360
// Embedded strings (evidence for future rename):
//   - "TrickID: %i - "
//   - "LocationID: %i - "
//   - "GroupID: %i - "
//   - "Group: %S - "
//   - "Filename: %S: "
//   - "Debug:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: for×11, do×10, while×10, if×1, return×1.
//  - Notable callees: sprintf×5, FUN_008f8200, FUN_00953360, __RTDynamicCast.
//  - Strings: "TrickID: %i - "; "LocationID: %i - "; "GroupID: %i - "; "Group: %S - ".
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

uint32_t /* width from decompiler */ __fastcall FUN_00953360(int param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint uVar8;

  byte bVar9;

  uint32_t /* width from decompiler */ *puVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ uVar13;

  char *pcVar14;

  char *pcVar15;

  uint32_t /* width from decompiler */ uVar16;

  char local_420 [2];

  uint32_t /* width from decompiler */ local_41e [65];

  uint32_t /* width from decompiler */ local_318 [2];

  byte local_310;

  byte local_30f;

  uint8_t local_30e [196];

  uint8_t local_24a [65];

  char cStack_209;

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  iVar2 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

  local_208[0] = '\0';

  local_208[1] = '\0';

  puVar10 = local_206;

  for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  local_420[0] = '\0';

  local_420[1] = '\0';

  pcVar3 = local_420 + 2;

  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {

    pcVar3[0] = '\0';

    pcVar3[1] = '\0';

    pcVar3[2] = '\0';

    pcVar3[3] = '\0';

    pcVar3 = pcVar3 + 4;

  }

  pcVar3[0] = '\0';

  pcVar3[1] = '\0';

  iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c);

  bVar9 = 0;

  if (*(char *)(iVar6 + 0x716) != '\0') {

    do {

      puVar10 = (uint32_t /* width from decompiler */ *)((uint)bVar9 * 0x110 + *(int *)(iVar6 + 0x720));

      puVar12 = local_318;

      for (iVar7 = 0x44; iVar7 != 0; iVar7 = iVar7 + -1) {

        *puVar12 = *puVar10;

        puVar10 = puVar10 + 1;

        puVar12 = puVar12 + 1;

      }

      sprintf(local_420,"TrickID: %i - ",local_318[0]);

      iVar6 = 0;

      do {

        cVar1 = local_420[iVar6];

        *(char *)((int)local_206 + iVar6 + -2) = cVar1;

        iVar6 = iVar6 + 1;

      } while (cVar1 != '\0');

      sprintf(local_420,"LocationID: %i - ",(uint)local_310);

      pcVar3 = local_420;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)local_420;

      pcVar3 = &cStack_209;

      do {

        pcVar11 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_420;

      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar3 = pcVar3 + 1;

      }

      sprintf(local_420,"GroupID: %i - ",(uint)local_30f);

      pcVar3 = local_420;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)local_420;

      pcVar3 = &cStack_209;

      do {

        pcVar11 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_420;

      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar3 = pcVar3 + 1;

      }

      sprintf(local_420,"Group: %S - ",local_24a);

      pcVar3 = local_420;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)local_420;

      pcVar3 = &cStack_209;

      do {

        pcVar11 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_420;

      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar3 = pcVar3 + 4;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar3 = pcVar3 + 1;

      }

      sprintf(local_420,"Filename: %S: ",local_30e);

      pcVar3 = local_420;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      uVar4 = (int)pcVar3 - (int)local_420;

      pcVar3 = &cStack_209;

      do {

        pcVar11 = pcVar3 + 1;

        pcVar3 = pcVar3 + 1;

      } while (*pcVar11 != '\0');

      pcVar11 = local_420;

      for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar11;

        pcVar11 = pcVar11 + 4;

        pcVar3 = pcVar3 + 4;

      }

      uVar16 = 0;

      pcVar15 = local_208;

      pcVar14 = "Debug:";

      uVar13 = 6;

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *pcVar3 = *pcVar11;

        pcVar11 = pcVar11 + 1;

        pcVar3 = pcVar3 + 1;

      }

      uVar5 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                              &CDlgChatLog::RTTI_Type_Descriptor,0,6,"Debug:",pcVar15,0);

      FUN_008f8200(uVar5,uVar13,pcVar14,pcVar15,uVar16);

      iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x3c);

      bVar9 = bVar9 + 1;

    } while (bVar9 < *(byte *)(iVar6 + 0x716));

  }

  return 0;

}
