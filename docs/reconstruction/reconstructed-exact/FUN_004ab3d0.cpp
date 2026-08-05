// =============================================================================
// FUN_004ab3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ab3d0
// Address:   0x004ab3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ab3d0 @ 0x004ab3d0
// Stable ID: aa_004ab3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: FUN_004ab3d0.
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

int FUN_004ab3d0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  

  iVar4 = param_1;

  if (*(int *)(param_1 + 4) == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;

  }

  iVar5 = uVar6 * -0x55555555;

  uVar6 = uVar6 / 3;

  iVar7 = 0;

  if (3 < uVar6) {

    param_1 = (uVar6 - 4 >> 2) + 1;

    iVar7 = param_1 * 4;

    iVar5 = 0x18;

    do {

      iVar1 = *(int *)(iVar4 + 4);

      if (0.0 < (*(float *)(iVar1 + -0xc + iVar5) - *(float *)(iVar1 + -4 + iVar5)) *

                (*(float *)(iVar1 + -0x18 + iVar5) - *(float *)(iVar1 + -0x10 + iVar5)) -

                (*(float *)(iVar1 + -0x14 + iVar5) - *(float *)(iVar1 + -0xc + iVar5)) *

                (*(float *)(iVar1 + -0x10 + iVar5) - *(float *)(iVar1 + -8 + iVar5))) {

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + -0x18 + iVar5);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + -0x14 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + -0x18 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + -0x10 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + -0x14 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + -0xc + iVar5);

        iVar1 = *(int *)(iVar4 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar5 + -0x10 + iVar1) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar5 + -0xc + iVar1) = uVar3;

      }

      iVar1 = *(int *)(iVar4 + 4);

      if (0.0 < (*(float *)(iVar1 + 0xc + iVar5) - *(float *)(iVar1 + 0x14 + iVar5)) *

                (*(float *)(iVar1 + iVar5) - *(float *)(iVar1 + 8 + iVar5)) -

                (*(float *)(iVar1 + 4 + iVar5) - *(float *)(iVar1 + 0xc + iVar5)) *

                (*(float *)(iVar1 + 8 + iVar5) - *(float *)(iVar1 + 0x10 + iVar5))) {

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar5);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc + iVar5);

        iVar1 = *(int *)(iVar4 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + iVar1) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + iVar1) = uVar3;

      }

      iVar1 = *(int *)(iVar4 + 4);

      if (0.0 < (*(float *)(iVar1 + 0x24 + iVar5) - *(float *)(iVar1 + 0x2c + iVar5)) *

                (*(float *)(iVar1 + 0x18 + iVar5) - *(float *)(iVar1 + 0x20 + iVar5)) -

                (*(float *)(iVar1 + 0x1c + iVar5) - *(float *)(iVar1 + 0x24 + iVar5)) *

                (*(float *)(iVar1 + 0x20 + iVar5) - *(float *)(iVar1 + 0x28 + iVar5))) {

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + iVar5);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24 + iVar5);

        iVar1 = *(int *)(iVar4 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20 + iVar1) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24 + iVar1) = uVar3;

      }

      iVar1 = *(int *)(iVar4 + 4);

      if (0.0 < (*(float *)(iVar1 + 0x3c + iVar5) - *(float *)(iVar1 + 0x44 + iVar5)) *

                (*(float *)(iVar1 + 0x30 + iVar5) - *(float *)(iVar1 + 0x38 + iVar5)) -

                (*(float *)(iVar1 + 0x34 + iVar5) - *(float *)(iVar1 + 0x3c + iVar5)) *

                (*(float *)(iVar1 + 0x38 + iVar5) - *(float *)(iVar1 + 0x40 + iVar5))) {

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30 + iVar5);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c + iVar5);

        iVar1 = *(int *)(iVar4 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x38 + iVar1) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x3c + iVar1) = uVar3;

      }

      iVar5 = iVar5 + 0x60;

      param_1 = param_1 + -1;

    } while (param_1 != 0);

  }

  if (iVar7 < (int)uVar6) {

    iVar5 = iVar7 * 0x18;

    iVar7 = uVar6 - iVar7;

    do {

      iVar1 = *(int *)(iVar4 + 4);

      if (0.0 < (*(float *)(iVar1 + 0xc + iVar5) - *(float *)(iVar1 + 0x14 + iVar5)) *

                (*(float *)(iVar1 + iVar5) - *(float *)(iVar1 + 8 + iVar5)) -

                (*(float *)(iVar1 + 4 + iVar5) - *(float *)(iVar1 + 0xc + iVar5)) *

                (*(float *)(iVar1 + 8 + iVar5) - *(float *)(iVar1 + 0x10 + iVar5))) {

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar5);

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 8 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar5) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc + iVar5);

        iVar1 = *(int *)(iVar4 + 4);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 8 + iVar1) = uVar2;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc + iVar1) = uVar3;

      }

      iVar5 = iVar5 + 0x18;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  return iVar5;

}
