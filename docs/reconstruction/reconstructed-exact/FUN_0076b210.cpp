// =============================================================================
// FUN_0076b210
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b210
// Address:   0x0076b210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076b210 @ 0x0076b210
// Stable ID: aa_0076b210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×10, while×8, return×5, do×5, goto×2, for×1.
//  - Notable callees: block×4, FUN_00467180, FUN_0076aed0, FUN_0076b210, _strnicmp.
//  - Return sites: 5.

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

/* WARNING: Removing unreachable block (ram,0x0076b357) */

/* WARNING: Removing unreachable block (ram,0x0076b315) */

/* WARNING: Removing unreachable block (ram,0x0076b318) */

/* WARNING: Removing unreachable block (ram,0x0076b3c5) */



bool __thiscall FUN_0076b210(char *param_1,char *param_2)



{

  char *pcVar1;

  int *piVar2;

  char cVar3;

  char cVar4;

  uint uVar5;

  int iVar6;

  undefined *puVar7;

  int *piVar8;

  char *pcVar9;

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac255;

  local_c = ExceptionList;

  if (*param_2 == '\0') {

    return *param_1 == '\0';

  }

  iVar6 = -(int)param_2;

  do {

    cVar3 = *param_2;

    param_2[(int)(local_110 + iVar6)] = cVar3;

    param_2 = param_2 + 1;

  } while (cVar3 != '\0');

  local_4 = 0;

  pcVar9 = local_110;

  ExceptionList = &local_c;

  do {

    if (local_110[0] == '\0') {

      piVar8 = (int *)0x0;

      pcVar9 = param_1;

      do {

        cVar3 = *pcVar9;

        pcVar9 = pcVar9 + 1;

      } while (cVar3 != '\0');

      pcVar9 = param_1 + ((int)pcVar9 - (int)(param_1 + 1));

      while( true ) {

        if (piVar8 < (int *)0xffffffed) {

          param_1 = param_1 + *piVar8;

          if (param_1 <= pcVar9) {

            if (piVar8[3] != 0) goto LAB_0076b370;

            ExceptionList = local_c;

            return true;

          }

          ExceptionList = local_c;

          return false;

        }

        if (*param_1 == '\0') break;

        do {

          if (piVar8 == (int *)0x0) {

            ExceptionList = local_c;

            return false;

          }

          piVar2 = piVar8 + -1;

          piVar8 = piVar8 + -5;

          param_1 = (char *)(*piVar2 + 1);

LAB_0076b370:

          if ((char)piVar8[1] == '\0') {

            iVar6 = _strnicmp(param_1,(char *)piVar8[2],piVar8[3]);

            uVar5 = ~-(uint)(iVar6 != 0) & (uint)param_1;

          }

          else {

            uVar5 = FUN_0076aed0(piVar8[2]);

          }

          piVar8[4] = uVar5;

        } while (uVar5 == 0);

        param_1 = (char *)(piVar8[4] + piVar8[3]);

        piVar8 = piVar8 + 5;

      }

      ExceptionList = local_c;

      return true;

    }

    while( true ) {

      for (; *pcVar9 == '?'; pcVar9 = pcVar9 + 1) {

      }

      if (*pcVar9 != '*') break;

      pcVar9 = pcVar9 + 1;

    }

    cVar3 = *pcVar9;

    while (cVar3 != '\0') {

      puVar7 = &DAT_00a9d1c4;

      cVar4 = '*';

      do {

        if (cVar3 == cVar4) goto LAB_0076b2ef;

        cVar4 = puVar7[1];

        puVar7 = puVar7 + 1;

      } while (cVar4 != '\0');

      pcVar1 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

      cVar3 = *pcVar1;

    }

LAB_0076b2ef:

    FUN_00467180();

    local_110[0] = *pcVar9;

  } while( true );

}
