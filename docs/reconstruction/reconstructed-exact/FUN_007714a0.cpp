// =============================================================================
// FUN_007714a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007714a0
// Address:   0x007714a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007714a0 @ 0x007714a0
// Stable ID: aa_007714a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, for×2, return×1.
//  - Notable callees: FUN_00770490, FUN_007714a0.
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

int __thiscall FUN_007714a0(int *param_1,int *param_2)



{

  int *in_EAX;

  int iVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  uint *puVar6;

  int local_10;

  int local_c;

  int *local_8;

  

  piVar5 = param_2;

  local_10 = *param_1;

  iVar1 = *param_2;

  iVar4 = iVar1;

  local_8 = param_1;

  if (local_10 < iVar1) {

    local_8 = param_2;

    iVar4 = local_10;

    local_10 = iVar1;

  }

  param_2 = (int *)iVar4;

  if ((local_10 + 1 <= in_EAX[1]) || (iVar1 = FUN_00770490(), iVar1 == 0)) {

    iVar1 = *in_EAX;

    *in_EAX = local_10 + 1;

    piVar3 = (int *)param_1[3];

    piVar5 = (int *)piVar5[3];

    puVar6 = (uint *)in_EAX[3];

    uVar2 = 0;

    iVar4 = 0;

    if (0 < (int)param_2) {

      local_c = (int)param_2;

      do {

        iVar4 = *piVar3;

        piVar3 = piVar3 + 1;

        uVar2 = iVar4 + *piVar5 + uVar2;

        *puVar6 = uVar2;

        *puVar6 = uVar2 & 0xfffffff;

        piVar5 = piVar5 + 1;

        uVar2 = uVar2 >> 0x1c;

        puVar6 = puVar6 + 1;

        local_c = local_c + -1;

        iVar4 = (int)param_2;

      } while (local_c != 0);

    }

    if (param_2 != (int *)local_10) {

      for (; iVar4 < local_10; iVar4 = iVar4 + 1) {

        uVar2 = uVar2 + *(int *)(local_8[3] + iVar4 * 4);

        *puVar6 = uVar2;

        *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar6 + 3) & 0xf;

        uVar2 = uVar2 >> 0x1c;

        puVar6 = puVar6 + 1;

      }

    }

    *puVar6 = uVar2;

    if (*in_EAX < iVar1) {

      for (iVar1 = iVar1 - *in_EAX; puVar6 = puVar6 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar6 = 0;

      }

    }

    iVar1 = *in_EAX;

    if (0 < iVar1) {

      do {

        if (*(int *)(in_EAX[3] + -4 + *in_EAX * 4) != 0) break;

        iVar1 = *in_EAX + -1;

        *in_EAX = iVar1;

      } while (0 < iVar1);

      iVar1 = *in_EAX;

    }

    if (iVar1 == 0) {

      in_EAX[2] = 0;

    }

    iVar1 = 0;

  }

  return iVar1;

}
