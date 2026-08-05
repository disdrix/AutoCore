// =============================================================================
// FUN_004eb4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb4a0
// Address:   0x004eb4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004eb4a0 @ 0x004eb4a0
// Stable ID: aa_004eb4a0
// Embedded strings (evidence for future rename):
//   - "Unsupported shape"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_004b5cb0, FUN_004eb4a0, FUN_007a4480.
//  - Strings: "Unsupported shape".
//  - Return sites: 5.

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

void FUN_004eb4a0(int *param_1,float param_2,float param_3,float param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *param_1;

  if (iVar1 != 0) {

    if (param_1[0x18] != 0) {

      FUN_004b5cb0(param_1[0x18],param_5,param_2);

      return;

    }

    if ((*(int *)(iVar1 + 0x54) - *(int *)(iVar1 + 0x50) & 0xfffffffcU) != 0) {

      iVar1 = **(int **)(iVar1 + 0x50);

      iVar2 = *(int *)(iVar1 + 4);

      if (iVar2 == 1) {

        *(float *)(iVar1 + 0x68) = param_2 * param_3;

        return;

      }

      if (iVar2 == 3) {

        *(float *)(iVar1 + 0x6c) = param_2 * param_4;

        *(float *)(iVar1 + 0x68) = param_2 * param_3;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30) = 0;

        return;

      }

      if (iVar2 == 2) {

        *(float *)(iVar1 + 0x6c) = param_2;

        *(float *)(iVar1 + 0x68) = param_2 * param_3;

        *(float *)(iVar1 + 0x70) = param_2 * param_4;

        return;

      }

      FUN_007a4480(0xffffffff,"Unsupported shape");

    }

  }

  return;

}
