// =============================================================================
// FUN_00928800
// -----------------------------------------------------------------------------
// Stable ID: aa_00928800
// Address:   0x00928800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928800 @ 0x00928800
// Stable ID: aa_00928800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×11, return×3.
//  - Notable callees: FUN_00928800.
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

uint32_t /* width from decompiler */ FUN_00928800(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar2;

  uint uVar3;

  uint uVar4;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_EBP;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_retaddr;

  int **ppiVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *local_8;

  uint32_t /* width from decompiler */ *puStack_4;

  

  if (*(uint *)(unaff_ESI + 0x1c) < *(uint *)(unaff_ESI + 0x28)) {

    piVar1 = *(int **)(*(int *)(unaff_ESI + 0x48) + *(uint *)(unaff_ESI + 0x1c) * 4);

    uVar6 = 0;

    ppiVar5 = &local_8;

    iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,0,ppiVar5,0,0);

    if (-1 < iVar2) {

      if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

        *in_EAX = uVar6;

      }

      if (param_1 != (int *)0x0) {

        *param_1 = (int)ppiVar5;

      }

      if (unaff_EBP != (uint32_t /* width from decompiler */ *)0x0) {

        *unaff_EBP = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

      }

      uVar4 = (uint)(*(int *)(unaff_ESI + 0x34) != 0) + *(int *)(unaff_ESI + 0x2c);

      uVar3 = *(uint *)(unaff_ESI + 0x1c) / uVar4;

      uVar4 = *(uint *)(unaff_ESI + 0x1c) - uVar3 * uVar4;

      if (unaff_EBX != (int *)0x0) {

        *unaff_EBX = *(int *)(unaff_ESI + 0x44) * uVar4;

      }

      if (local_8 != (int *)0x0) {

        *local_8 = *(int *)(unaff_ESI + 0x44) * uVar3;

      }

      if (puStack_4 != (uint32_t /* width from decompiler */ *)0x0) {

        if (uVar4 < *(uint *)(unaff_ESI + 0x2c)) {

          uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44);

        }

        else {

          uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34);

        }

        *puStack_4 = uVar6;

      }

      if (unaff_retaddr != (uint32_t /* width from decompiler */ *)0x0) {

        if (*(uint *)(unaff_ESI + 0x30) <= uVar3) {

          *unaff_retaddr = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38);

          *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + 1;

          return 1;

        }

        *unaff_retaddr = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44);

      }

      *(int *)(unaff_ESI + 0x1c) = *(int *)(unaff_ESI + 0x1c) + 1;

      return 1;

    }

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  return 0;

}
