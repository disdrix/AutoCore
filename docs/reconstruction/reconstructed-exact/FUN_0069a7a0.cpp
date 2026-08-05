// =============================================================================
// FUN_0069a7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a7a0
// Address:   0x0069a7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069a7a0 @ 0x0069a7a0
// Stable ID: aa_0069a7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0069a7a0.
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

void __fastcall FUN_0069a7a0(int param_1)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  

  iVar3 = 0;

  if (((*(int *)(param_1 + 0x18) != 0) && (iVar1 = *(int *)(param_1 + 0x1c), 1 < iVar1)) &&

     (*(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0, iVar1 != 1 && -1 < iVar1 + -1)) {

    pfVar2 = (float *)(*(int *)(param_1 + 0x18) + 0x58);

    do {

      iVar3 = iVar3 + 1;

      *(float *)(param_1 + 0x28) =

           (pfVar2[-0x10] + pfVar2[2]) *

           (float)(((int)((pfVar2[-1] - pfVar2[-0x13]) * (pfVar2[-1] - pfVar2[-0x13]) +

                         (pfVar2[1] - pfVar2[-0x11]) * (pfVar2[1] - pfVar2[-0x11]) +

                         (*pfVar2 - pfVar2[-0x12]) * (*pfVar2 - pfVar2[-0x12])) >> 1) + 0x1fc00000)

           + *(float *)(param_1 + 0x28);

      pfVar2 = pfVar2 + 0x12;

    } while (iVar3 < *(int *)(param_1 + 0x1c) + -1);

  }

  return;

}
