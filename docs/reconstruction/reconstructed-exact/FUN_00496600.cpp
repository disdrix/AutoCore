// =============================================================================
// FUN_00496600
// -----------------------------------------------------------------------------
// Stable ID: aa_00496600
// Address:   0x00496600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496600 @ 0x00496600
// Stable ID: aa_00496600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_004073a0, FUN_00410420, FUN_00496600, FUN_0074b580, FUN_0074b8f0, FUN_0074ba00, FUN_0074c310, FUN_00972cc0.
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

uint8_t __thiscall FUN_00496600(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int *piVar8;

  uint8_t uVar9;

  int aiStack_114 [13];

  uint8_t local_e0 [196];

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a0cac;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_00972cc0();

  FUN_0074ba00();

  local_14 = 0;

  FUN_0074b8f0(param_2,param_3);

  FUN_00410420(0,0);

  piVar1 = *(int **)(param_1 + 0xb0);

  uVar9 = 0;

  for (piVar8 = *(int **)(param_1 + 0xac); piVar8 != piVar1; piVar8 = piVar8 + 1) {

    piVar2 = (int *)*piVar8;

    uVar6 = (**(code **)(*piVar2 + 0x48))();

    uVar7 = (**(code **)(*piVar2 + 0xc))(uVar6);

    cVar5 = FUN_0074c310(local_e0,uVar7,uVar6);

    if (((cVar5 != '\0') && (*(char *)piVar2[0x1e] == '\x01')) &&

       (iVar3 = *(int *)((char *)piVar2[0x1e] + 4), iVar3 != 0)) {

      iVar4 = *(int *)(param_4 + 4);

      aiStack_114[0] = iVar3;

      if ((iVar4 == 0) ||

         ((uint)(*(int *)(param_4 + 0xc) - iVar4 >> 2) <= (uint)(*(int *)(param_4 + 8) - iVar4 >> 2)

         )) {

        FUN_004073a0(*(uint32_t /* width from decompiler */ *)(param_4 + 8),1,aiStack_114);

      }

      else {

        piVar2 = *(int **)(param_4 + 8);

        *piVar2 = iVar3;

        *(int **)(param_4 + 8) = piVar2 + 1;

      }

      uVar9 = 1;

    }

  }

  local_14 = 0xffffffff;

  FUN_0074b580();

  ExceptionList = pvStack_1c;

  return uVar9;

}
