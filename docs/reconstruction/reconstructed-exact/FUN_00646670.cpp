// =============================================================================
// FUN_00646670
// -----------------------------------------------------------------------------
// Stable ID: aa_00646670
// Address:   0x00646670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646670 @ 0x00646670
// Stable ID: aa_00646670
// Embedded strings (evidence for future rename):
//   - "HK_NULL"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, goto×2, return×2, while×2.
//  - Notable callees: FUN_00637f70, FUN_00646490, FUN_00646670.
//  - Strings: "HK_NULL".
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

uint32_t /* width from decompiler */ __thiscall FUN_00646670(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EBP;

  int iVar5;

  int *unaff_retaddr;

  int iStack_38;

  uint32_t /* width from decompiler */ uStack_4;

  

  FUN_00646490(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),*(uint32_t /* width from decompiler */ *)(param_2 + 0x18));

  iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0,0x12);

  iVar5 = 0;

  if (0 < param_1) {

    do {

      uVar2 = **(uint32_t /* width from decompiler */ **)(iStack_38 + iVar5 * 4);

      iVar4 = (**(code **)(**(int **)(unaff_EBX + 0x10) + 4))(uVar2,&stack0xffffffc0);

      if (iVar4 == 1) {

        iVar4 = FUN_00637f70(uVar2,"HK_NULL");

        if (iVar4 != 0) {

          if (unaff_retaddr == (int *)0x0) goto LAB_0064682b;

          iVar4 = (**(code **)(*unaff_retaddr + 4))

                            (uStack_4,*(uint32_t /* width from decompiler */ *)(iVar5 * 4),*(uint32_t /* width from decompiler */ *)(iVar5 * 4),uVar2,

                             &stack0xffffffc0);

          goto LAB_00646757;

        }

        unaff_EBP = 0;

      }

      else {

LAB_00646757:

        if (iVar4 != 0) {

LAB_0064682b:

          (**(code **)(*DAT_00b05060 + 0x14))(iVar3,0,0x12);

          (**(code **)(*DAT_00b05060 + 0x14))(0,0,0x12);

          (**(code **)(*DAT_00b05060 + 0x14))(0,0,0x12);

          (**(code **)(*DAT_00b05060 + 0x14))(iStack_38,0,0x12);

          return 1;

        }

      }

      *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5 * 4) = unaff_EBP;

      iVar5 = iVar5 + 1;

    } while (iVar5 < param_1);

  }

  iVar5 = 0;

  if (0 < param_1) {

    do {

      iVar4 = iVar5 * 4;

      iVar1 = iVar5 * 4;

      iVar5 = iVar5 + 1;

      **(uint32_t /* width from decompiler */ **)(iStack_38 + iVar4) = *(uint32_t /* width from decompiler */ *)(iVar3 + iVar1);

    } while (iVar5 < param_1);

  }

  (**(code **)(*DAT_00b05060 + 0x14))(iVar3,0,0x12);

  (**(code **)(*DAT_00b05060 + 0x14))(0,0,0x12);

  (**(code **)(*DAT_00b05060 + 0x14))(0,0,0x12);

  (**(code **)(*DAT_00b05060 + 0x14))(iStack_38,0,0x12);

  return 0;

}
