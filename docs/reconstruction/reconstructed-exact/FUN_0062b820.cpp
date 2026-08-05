// =============================================================================
// FUN_0062b820
// -----------------------------------------------------------------------------
// Stable ID: aa_0062b820
// Address:   0x0062b820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062b820 @ 0x0062b820
// Stable ID: aa_0062b820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: block×2, FUN_005b3300, FUN_0062b820.
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

/* WARNING: Removing unreachable block (ram,0x0062b8f1) */

/* WARNING: Removing unreachable block (ram,0x0062b91b) */



void __thiscall FUN_0062b820(int *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  

  piVar3 = (int *)*param_1;

  iVar4 = 0;

  if (0 < piVar3[1]) {

    do {

      if (*(int *)(*piVar3 + iVar4 * 4) < 0) {

        iVar5 = param_2[1] + 1;

        if ((int)(param_2[2] & 0x7fffffffU) < iVar5) {

          iVar2 = (param_2[2] & 0x7fffffffU) * 2;

          if (iVar2 <= iVar5) {

            iVar2 = iVar5;

          }

          FUN_005b3300(param_2,iVar2,0xc);

        }

        param_2[1] = iVar5;

        puVar1 = (uint32_t /* width from decompiler */ *)(*param_2 + -0xc + iVar5 * 0xc);

        piVar3 = (int *)(**(code **)*DAT_00b05060)(*(int *)(*(int *)*param_1 + iVar4 * 4) * -4,1);

        *puVar1 = piVar3;

        puVar1[1] = -*(int *)(*(int *)*param_1 + iVar4 * 4);

        *piVar3 = iVar4;

        puVar1[2] = 1;

        *(int *)(*(int *)*param_1 + iVar4 * 4) = param_2[1] + -1;

      }

      else {

        iVar5 = *(int *)(*piVar3 + *(int *)(*piVar3 + iVar4 * 4) * 4);

        piVar3 = (int *)(*param_2 + iVar5 * 0xc);

        *(int *)(*piVar3 + *(int *)(*param_2 + 8 + iVar5 * 0xc) * 4) = iVar4;

        piVar3 = piVar3 + 2;

        *piVar3 = *piVar3 + 1;

      }

      piVar3 = (int *)*param_1;

      iVar4 = iVar4 + 1;

    } while (iVar4 < piVar3[1]);

  }

  *(uint32_t /* width from decompiler */ *)(*param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[1] + 4) = 0;

  return;

}
