// =============================================================================
// FUN_009372c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009372c0
// Address:   0x009372c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009372c0 @ 0x009372c0
// Stable ID: aa_009372c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: FUN_005876c0×2, FUN_007fef20×2, FUN_0085fd80×2, FUN_009372c0.
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

void FUN_009372c0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  char cVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_10 = param_1;

  local_18[0] = 0x202a;

  local_c = param_2;

  local_8 = param_3;

  local_4 = param_4;

  if (*(int *)(unaff_ESI + 0xc78) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_18,0x18,0);

  }

  cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x105c) + 0x3d8))();

  if (cVar2 == '\0') {

    cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1060) + 0x3d8))();

    if (cVar2 == '\0') goto LAB_009373a2;

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1060) + 0x5a0);

    FUN_0085fd80();

    if (iVar1 != 0) {

      FUN_005876c0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xe04) + 0xe4e8));

    }

    uVar3 = 0xc;

  }

  else {

    iVar1 = *(int *)(*(int *)(unaff_ESI + 0x105c) + 0x588);

    FUN_0085fd80();

    if (iVar1 != 0) {

      FUN_005876c0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xe04) + 0xe4e8));

    }

    uVar3 = 0xb;

  }

  FUN_007fef20(uVar3,0,0);

LAB_009373a2:

  cVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1040) + 0x3d8))();

  if ((cVar2 != '\0') && (*(int *)(*(int *)(unaff_ESI + 0x1040) + 0x528) == 0)) {

    FUN_007fef20(4,0,0);

  }

  return;

}
