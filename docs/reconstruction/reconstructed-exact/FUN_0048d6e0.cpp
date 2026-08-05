// =============================================================================
// FUN_0048d6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d6e0
// Address:   0x0048d6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d6e0 @ 0x0048d6e0
// Stable ID: aa_0048d6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×12, return×6, do×4, while×4, goto×1.
//  - Notable callees: FUN_0048a940×2, FUN_0048cea0×2, FUN_0048ae90, FUN_0048af60, FUN_0048c120, FUN_0048d1e0, FUN_0048d450, FUN_0048d6e0.
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

char * FUN_0048d6e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  void *pvVar5;

  char *pcVar6;

  int *piVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a074b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar3 = FUN_0048af60();

  pcVar4 = (char *)FUN_0048cea0(param_1,param_3);

  do {

    if (pcVar4 == (char *)0x0) {

      if ((iVar3 != 0) && (*(char *)(iVar3 + 0x2c) == '\0')) {

        *(uint8_t *)(iVar3 + 0x2c) = 1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = 6;

        pcVar4 = PTR_s_Error_reading_Element_value__00aef920;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        FUN_0048a940(PTR_s_Error_reading_Element_value__00aef920,

                     (int)pcVar4 - (int)(PTR_s_Error_reading_Element_value__00aef920 + 1));

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = 0xffffffff;

      }

      ExceptionList = local_c;

      return (char *)0x0;

    }

    if (*pcVar4 == '\0') {

      ExceptionList = local_c;

      return pcVar4;

    }

    if (*pcVar4 == '<') {

      pcVar6 = "</";

      do {

        if (*pcVar6 == '\0') {

          ExceptionList = local_c;

          return pcVar4;

        }

      } while (((pcVar4 + -0xa89ddc)[(int)pcVar6] == *pcVar6) &&

              (pcVar1 = pcVar4 + -0xa89ddb + (int)pcVar6, pcVar6 = pcVar6 + 1, *pcVar1 != '\0'));

      if (*pcVar6 == '\0') {

        ExceptionList = local_c;

        return pcVar4;

      }

      piVar7 = (int *)FUN_0048d450(pcVar4,param_3);

      if (piVar7 == (int *)0x0) {

        ExceptionList = local_c;

        return (char *)0x0;

      }

      param_1 = (**(code **)(*piVar7 + 8))(pcVar4,param_2,param_3);

LAB_0048d806:

      FUN_0048ae90(piVar7);

    }

    else {

      pvVar5 = operator_new(0x30);

      piVar7 = (int *)0x0;

      local_4 = 0;

      if (pvVar5 != (void *)0x0) {

        piVar7 = (int *)FUN_0048c120(&DAT_00a1419b);

      }

      local_4 = 0xffffffff;

      if (piVar7 == (int *)0x0) {

        if ((iVar3 != 0) && (*(char *)(iVar3 + 0x2c) == '\0')) {

          *(uint8_t *)(iVar3 + 0x2c) = 1;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = 3;

          pcVar4 = PTR_s_Memory_allocation_failed__00aef914;

          do {

            cVar2 = *pcVar4;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          FUN_0048a940(PTR_s_Memory_allocation_failed__00aef914,

                       (int)pcVar4 - (int)(PTR_s_Memory_allocation_failed__00aef914 + 1));

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x40) = 0xffffffff;

          *(uint32_t /* width from decompiler */ *)(iVar3 + 0x3c) = 0xffffffff;

        }

        ExceptionList = local_c;

        return (char *)0x0;

      }

      if (DAT_00aef8c9 == '\0') {

        param_1 = (**(code **)(*piVar7 + 8))(param_1,param_2,param_3);

      }

      else {

        param_1 = (**(code **)(*piVar7 + 8))(pcVar4,param_2);

      }

      cVar2 = FUN_0048d1e0();

      if (cVar2 == '\0') goto LAB_0048d806;

      (**(code **)*piVar7)(1);

    }

    pcVar4 = (char *)FUN_0048cea0(param_1,param_3);

  } while( true );

}
