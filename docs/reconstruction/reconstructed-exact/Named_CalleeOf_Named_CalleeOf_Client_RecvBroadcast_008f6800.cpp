// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_008f6800
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6800
// Callee of Named_CalleeOf_Client_RecvBroadcast
// Address:   0x008f6800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper. Evidence string: ");

  if ((local_22c != (FILE *)0x0) || (local_22c = fopen(in_EAX,". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - ");

  if ((local_22c != (FILE *)0x0) || (local_22c = fopen(in_EAX,"
//   - "[%s %s %02d %02d:%02d:%02d %04d] "
//   - "
//   - "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, do×2, while×2, return×1.
//  - Notable callees: FUN_007a6de0×2, fopen×2, sprintf×2, FUN_007a69d0, FUN_008f6030, FUN_008f6800, GetLocalTime, fclose.
//  - Strings: "wt+"; "[%s %s %02d %02d:%02d:%02d %04d] "; "%s%s\n".
//  - Return sites: 1.

  if ((local_22c != (FILE *)0x0) || (local_22c = fopen(in_EAX,"
//   - "[%s %s %02d %02d:%02d:%02d %04d] "
//   - "%s%s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_008f6800(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  char *in_EAX;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  char *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar12;

  FILE *local_22c;

  _SYSTEMTIME local_228;

  char local_218;

  uint32_t /* width from decompiler */ local_217;

  char local_110;

  uint32_t /* width from decompiler */ local_10f;

  

  local_22c = fopen(in_EAX,"at");

  if ((local_22c != (FILE *)0x0) || (local_22c = fopen(in_EAX,"wt+"), local_22c != (FILE *)0x0)) {

    FUN_007a69d0();

    local_110 = '\0';

    puVar12 = &local_10f;

    for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar12 = 0;

      puVar12 = puVar12 + 1;

    }

    *(uint16_t *)puVar12 = 0;

    *(uint8_t *)((int)puVar12 + 2) = 0;

    if (((unaff_EBX != (char *)0x0) && (*unaff_EBX != '\0')) ||

       ((param_2 != (char *)0x0 && (*param_2 != '\0')))) {

      GetLocalTime(&local_228);

      uVar8 = (uint)local_228.wYear;

      uVar10 = (uint)local_228.wSecond;

      uVar3 = (uint)local_228.wMinute;

      uVar9 = (uint)local_228.wHour;

      uVar11 = (uint)local_228.wDay;

      uVar4 = FUN_007a6de0((&DAT_00af921c)[local_228.wMonth],0xffffffff);

      uVar5 = FUN_007a6de0((&PTR_DAT_00af9250)[local_228.wDayOfWeek],0xffffffff);

      sprintf(&local_110,"[%s %s %02d %02d:%02d:%02d %04d] ",uVar5,uVar4,uVar11,uVar9,uVar3,uVar10,

              uVar8);

    }

    local_218 = '\0';

    puVar12 = &local_217;

    for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {

      *puVar12 = 0;

      puVar12 = puVar12 + 1;

    }

    *(uint16_t *)puVar12 = 0;

    *(uint8_t *)((int)puVar12 + 2) = 0;

    if ((unaff_EBX != (char *)0x0) && (*unaff_EBX != '\0')) {

      pcVar6 = (char *)FUN_008f6030();

      sprintf(&local_218,pcVar6);

    }

    if ((param_2 != (char *)0x0) && (pcVar6 = param_2, *param_2 != '\0')) {

      do {

        cVar2 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar2 != '\0');

      uVar3 = (int)pcVar6 - (int)param_2;

      pcVar6 = (char *)((int)&local_228.wMilliseconds + 1);

      do {

        pcVar1 = pcVar6 + 1;

        pcVar6 = pcVar6 + 1;

      } while (*pcVar1 != '\0');

      for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)param_2;

        param_2 = param_2 + 4;

        pcVar6 = pcVar6 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar6 = *param_2;

        param_2 = param_2 + 1;

        pcVar6 = pcVar6 + 1;

      }

    }

    fprintf(local_22c,"%s%s\n",&local_110,&local_218);

    fclose(local_22c);

  }

  return;

}
