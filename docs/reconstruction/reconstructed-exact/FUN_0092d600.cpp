// =============================================================================
// FUN_0092d600
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d600
// Address:   0x0092d600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092d600 @ 0x0092d600
// Stable ID: aa_0092d600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT13, FUN_0092d600.
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

void FUN_0092d600(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  int unaff_ESI;

  int unaff_retaddr;

  

  if (*(int *)(unaff_ESI + 0x1140) != 0) {

    puVar3 = (uint *)(**(code **)(**(int **)(unaff_ESI + 0x1140) + 0x164))(0);

    param_4 = (*puVar3 >> 0x18) * param_4;

    (**(code **)(**(int **)(unaff_ESI + 0x1140) + 400))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xde8) + 0x2c),unaff_retaddr + -4,param_1 + -2,

               (param_2 - unaff_retaddr) + 10,(param_3 - param_1) + 4,

               CONCAT13(((char)(param_4 / 0xff) + (char)(param_4 >> 0x1f)) -

                        (char)((longlong)param_4 * 0x80808081 >> 0x3f),(int3)*puVar3));

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0xde8) + 0x2c);

    *(int *)(iVar1 + 0x68) = *(int *)(iVar1 + 0x68) + 1;

    iVar2 = *(int *)(iVar1 + 0x68);

    *(float *)(iVar1 + 0x74) = (float)-iVar2;

    if (*(int *)(iVar1 + 0x70) < iVar2) {

      *(int *)(iVar1 + 0x70) = iVar2;

    }

  }

  return;

}
