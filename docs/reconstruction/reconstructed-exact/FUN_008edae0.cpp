// =============================================================================
// FUN_008edae0
// -----------------------------------------------------------------------------
// Stable ID: aa_008edae0
// Address:   0x008edae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008edae0 @ 0x008edae0
// Stable ID: aa_008edae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, return×2, for×1, do×1.
//  - Notable callees: FUN_0040e490×2, FUN_00792490, FUN_007b6a20, FUN_007b70b0, FUN_007fea50, FUN_008edae0, FUN_0096efd0.
//  - Return sites: 2.

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

void __fastcall FUN_008edae0(int *param_1)



{

  int *piVar1;

  void *pvVar2;

  char cVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint16_t *puVar8;

  uint16_t uStack_108;

  uint32_t /* width from decompiler */ auStack_106 [64];

  

  if ((int *)param_1[0x19f] != (int *)0x0) {

    iVar4 = (**(code **)(*(int *)param_1[0x19f] + 700))();

    if (iVar4 != 0) {

      uStack_108 = 0;

      puVar7 = auStack_106;

      for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar7 = 0;

        puVar7 = puVar7 + 1;

      }

      piVar1 = (int *)param_1[0x19f];

      *(uint16_t *)puVar7 = 0;

      iVar4 = (**(code **)(*piVar1 + 0x2b8))();

      if (iVar4 != 0) {

        pcVar5 = (char *)(**(code **)(*(int *)param_1[0x19f] + 0x2b8))();

        pcVar6 = (char *)&uStack_108;

        do {

          cVar3 = *pcVar5;

          *pcVar6 = cVar3;

          pcVar5 = pcVar5 + 1;

          pcVar6 = pcVar6 + 1;

        } while (cVar3 != '\0');

      }

      (**(code **)(*(int *)param_1[0x19f] + 0x58))();

      (**(code **)(*(int *)param_1[0x19f] + 0xcc))(0);

      if ((char)uStack_108 != '\0') {

        puVar8 = &uStack_108;

        FUN_007b6a20(puVar8);

        FUN_007b70b0(puVar8);

      }

    }

    (**(code **)(*(int *)param_1[0x19f] + 0x34c))();

    (**(code **)(*(int *)param_1[0x19f] + 0x440))();

    (**(code **)(*param_1 + 0xb0))(param_1[0x19f]);

  }

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 != '\0') {

    (**(code **)(*param_1 + 0x3b8))(param_1[0x15e]);

    (**(code **)(*param_1 + 0x3b8))(param_1[0x15d]);

    (**(code **)(*param_1 + 0x3b8))(param_1[0x16a]);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  iVar4 = FUN_0040e490(param_1 + 0x16c);

  while (iVar4 != 0) {

    iVar4 = FUN_0040e490(param_1 + 0x16c);

  }

  param_1[0x16f] = 0;

  FUN_007fea50();

  if (DAT_00d1b780 != (int *)0x0) {

    *(uint32_t /* width from decompiler */ *)(*DAT_00d1b780 + 0x498) = 0x4e2a;

    *(uint32_t /* width from decompiler */ *)(*DAT_00d1b780 + 0x49c) = 0x4e2b;

  }

  pvVar2 = (void *)param_1[0x1a0];

  if (pvVar2 == (void *)0x0) {

    param_1[0x1a0] = 0;

    return;

  }

  FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
