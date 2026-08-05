// =============================================================================
// FUN_0084b120
// -----------------------------------------------------------------------------
// Stable ID: aa_0084b120
// Address:   0x0084b120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084b120 @ 0x0084b120
// Stable ID: aa_0084b120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0084b120, FUN_00972db0.
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

void FUN_0084b120(void)



{

  float fVar1;

  int in_EAX;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  float fStack_4;

  

  if ((*(int *)(in_EAX + 0x518) != 0) &&

     (iVar2 = (**(code **)(**(int **)(in_EAX + 0x534) + 0x290))(), iVar2 != 0)) {

    iVar2 = *(int *)(*(int *)(*(int *)(in_EAX + 0x518) + 0xa8) + 0x38);

    fStack_4 = DAT_00d1e51c;

    fVar1 = DAT_00d1e51c;

    if ((iVar2 != 0xc) &&

       ((fVar1 = DAT_00d1e520, iVar2 != 0x10 && (fVar1 = fStack_4, iVar2 == 0x1c)))) {

      fVar1 = DAT_00a1e728 - DAT_00d1e520;

    }

    fStack_4 = fVar1;

    piVar3 = (int *)(**(code **)(**(int **)(in_EAX + 0x534) + 0x290))();

    uVar5 = 0;

    uVar4 = 3;

    (**(code **)(*piVar3 + 0x10))(3,fStack_4,0,0);

    FUN_00972db0(uVar4,fStack_4,uVar5);

  }

  return;

}
