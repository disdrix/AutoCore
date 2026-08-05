// =============================================================================
// Named_s_d_006129b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006129b0
// Address:   0x006129b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_s_d_006129b0 @ 0x006129b0
// Stable ID: aa_006129b0
// Embedded strings (evidence for future rename):
//   - "%s: %d / %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1, do×1, while×1.
//  - Notable callees: FUN_00403450, Named_s_d_006129b0, FUN_007a69d0, FUN_007a6de0, _snprintf, block, strncat.
//  - Strings: "%s: %d / %d".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s: %d / %d"
 * Domain alias of FUN_006129b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00612a78) */



int __thiscall

Named_s_d_006129b0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,char *param_4,size_t param_5)



{

  char *pcVar1;

  char cVar2;

  short *psVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  uint8_t local_298 [128];

  char local_218 [2];

  uint32_t /* width from decompiler */ local_216 [124];

  void *pvStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a855b;

  pvStack_14 = ExceptionList;

  psVar3 = (short *)param_1[0x10];

  if ((psVar3 != (short *)0x0) && (*psVar3 != 0)) {

    local_218[0] = '\0';

    local_218[1] = '\0';

    puVar6 = local_216;

    for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    *(uint16_t *)puVar6 = 0;

    puVar7 = local_298;

    ExceptionList = &pvStack_14;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(psVar3,uVar4);

    uVar4 = 0xffffffff;

    uStack_c = 0;

    FUN_007a69d0(puVar7,0xffffffff,(int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 2) * 4),

                 param_1[0xc]);

    uVar4 = FUN_007a6de0(puVar7,uVar4);

    _snprintf(local_218,0x200,"%s: %d / %d",uVar4);

    strncat(param_4,local_218,param_5);

    pcVar1 = param_4 + 1;

    do {

      cVar2 = *param_4;

      param_4 = param_4 + 1;

    } while (cVar2 != '\0');

    ExceptionList = pvStack_14;

    return (int)param_4 - (int)pcVar1;

  }

  ExceptionList = &pvStack_14;

  iVar5 = (**(code **)(*param_1 + 0x18))(param_2,param_3,param_4,param_5);

  ExceptionList = pvStack_24;

  return iVar5;

}
