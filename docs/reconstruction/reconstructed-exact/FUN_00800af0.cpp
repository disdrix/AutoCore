// =============================================================================
// FUN_00800af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00800af0
// Address:   0x00800af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00800af0 @ 0x00800af0
// Stable ID: aa_00800af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00419620, FUN_00419b40, FUN_00800af0, FUN_00887320.
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

void FUN_00800af0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ *param_5)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  int *piVar4;

  void *local_c;

  uint8_t *puStack_8;

  int *local_4;

  

  local_4 = (int *)0xffffffff;

  puStack_8 = &LAB_009b8034;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x3084) != 0) {

    ExceptionList = &local_c;

    iVar2 = FUN_00419b40(param_2,param_3);

    piVar4 = (int *)0x0;

    if (iVar2 != 0) {

      piVar4 = *(int **)(iVar2 + 0xc);

    }

    if (piVar4 == (int *)0x0) {

      if (*(int *)(param_1 + 0xf40) == 0) {

        ExceptionList = local_c;

        return;

      }

      pvVar3 = operator_new(0x530);

      if (pvVar3 == (void *)0x0) {

        piVar4 = (int *)0x0;

      }

      else {

        local_4 = piVar4;

        piVar4 = (int *)FUN_00887320(pvVar3);

      }

      local_4 = (int *)0xffffffff;

      if (**(int **)(param_1 + 0xf40) != 0) {

        (**(code **)(*(int *)**(int **)(param_1 + 0xf40) + 0xa8))(piVar4);

      }

      (**(code **)(*piVar4 + 0x43c))();

      piVar4[0x144] = param_2;

      piVar4[0x145] = param_3;

      FUN_00419620(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3084),param_2,param_3,piVar4,0);

    }

    (**(code **)(*(int *)piVar4[0x149] + 0x224))(param_4,*param_5);

    (**(code **)(*piVar4 + 0x448))();

    if ((piVar4[0x14a] != 0) &&

       (cVar1 = (**(code **)(*(int *)piVar4[0x14a] + 0xd8))(), cVar1 != '\0')) {

      (**(code **)(*(int *)piVar4[0x14a] + 0x454))(0x3f800000,1);

    }

  }

  ExceptionList = local_c;

  return;

}
