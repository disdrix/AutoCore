// =============================================================================
// FUN_007228a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007228a0
// Address:   0x007228a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007228a0 @ 0x007228a0
// Stable ID: aa_007228a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0071f760, FUN_0071f810, FUN_007227e0, FUN_007228a0, ROUND.
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

void FUN_007228a0(float param_1)



{

  int iVar1;

  int *piVar2;

  int in_EAX;

  int iVar3;

  int extraout_EDX;

  int unaff_ESI;

  float10 fVar4;

  

  iVar1 = *(int *)(unaff_ESI + 0x2a8 + in_EAX * 4);

  if (iVar1 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1b0) = 0;

    iVar1 = *(int *)(unaff_ESI + 0x2a8 + in_EAX * 4);

    piVar2 = *(int **)(iVar1 + 0x10);

    if (((piVar2 != (int *)0x0) && (*(int *)(iVar1 + 0x1c) != 0)) && (iVar1 = *piVar2, iVar1 != 0))

    {

      iVar3 = FUN_0071f760(1);

      if (iVar3 != 0) {

        iVar3 = *(int *)(unaff_ESI + 0x2a8 + in_EAX * 4);

        param_1 = *(float *)(iVar3 + 0x1a4) - param_1;

        if (param_1 <= g_flOne) {

          *(float *)(iVar3 + 0x1a4) = param_1;

        }

        else {

          *(float *)(iVar3 + 0x1a4) = g_flOne;

        }

        fVar4 = (float10)FUN_007227e0(*(uint32_t /* width from decompiler */ *)

                                       (*(int *)(unaff_ESI + 0x2a8 + in_EAX * 4) + 0x1a4));

        (**(code **)(extraout_EDX + 0x3c))(iVar1,(int)ROUND(fVar4));

      }

      iVar1 = *(int *)(unaff_ESI + 0x2a8 + in_EAX * 4);

      if (*(float *)(iVar1 + 0x1a4) <= *(float *)(iVar1 + 0x1b0)) {

        FUN_0071f810();

      }

    }

  }

  return;

}
