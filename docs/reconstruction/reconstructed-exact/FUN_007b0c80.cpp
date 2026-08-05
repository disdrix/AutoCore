// =============================================================================
// FUN_007b0c80
// -----------------------------------------------------------------------------
// Stable ID: aa_007b0c80
// Address:   0x007b0c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b0c80 @ 0x007b0c80
// Stable ID: aa_007b0c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_004101a0, FUN_007a7380, FUN_007b0c80.
//  - Return sites: 3.

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

void __thiscall FUN_007b0c80(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,char param_4)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ unaff_ESI;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  uint8_t auStack_c [12];

  

  local_1c = 0;

  iVar1 = (**(code **)(*param_1 + 700))();

  if (iVar1 != 0) {

    piVar2 = (int *)(**(code **)(*param_1 + 700))();

    if (*piVar2 != 0) {

      piVar2 = (int *)(**(code **)(*param_1 + 700))();

      iVar1 = FUN_007a7380(*(uint32_t /* width from decompiler */ *)(*piVar2 + 0x24));

      if (-1 < iVar1) {

        iVar1 = param_3[1];

        iVar4 = *param_3;

        iStack_18 = iVar4;

        iStack_14 = iVar1;

        (**(code **)(*param_1 + 0x2d0))(&iStack_10);

        if (param_4 != '\0') {

          piVar2 = (int *)(**(code **)(*param_1 + 0x120))(auStack_c,param_3,1);

          iVar4 = iVar4 - *piVar2;

          iVar3 = (**(code **)(*param_1 + 0x120))(&iStack_18,param_3,1);

          iVar1 = iVar1 - *(int *)(iVar3 + 4);

          iStack_18 = iVar1;

        }

        if ((((-1 < iVar4) && (iVar4 <= iStack_14)) && (-1 < iVar1)) && (iVar1 <= iStack_10)) {

          puVar5 = &local_1c;

          (**(code **)(*param_1 + 700))(puVar5);

          FUN_004101a0(puVar5);

          *unaff_retaddr = unaff_ESI;

          return;

        }

        *unaff_retaddr = unaff_ESI;

        return;

      }

    }

  }

  *param_2 = local_1c;

  return;

}
