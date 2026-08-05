// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, while×1, return×1.
//  - Notable callees: FUN_009700f0×3, FUN_005194f0, FUN_0051def0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP"; "MatDiffuse"; "MatAmbient"; "MatEmissive".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_005194f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005194f0
// Address:   0x005194f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOG_DEBUG_STOP_005194f0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar2 = param_2;

  iVar1 = param_1;

  if (*(int *)(param_1 + 0xc0) == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;

  }

  if (*(int *)(param_2 + 4) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4;

  }

  if (iVar4 * 3 != iVar3) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  param_2 = 0;

  iVar4 = 0;

  param_1 = 2;

  while( true ) {

    iVar3 = *(int *)(iVar1 + 0xc0);

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar1 + 0xc4) - iVar3 >> 2;

    }

    if (iVar3 <= param_2) break;

    iVar3 = *(int *)(iVar2 + 4);

    if (iVar3 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar2 + 8) - iVar3 >> 4;

    }

    if (iVar5 <= param_1) break;

    FUN_009700f0("MatDiffuse",iVar4 + iVar3);

    FUN_009700f0("MatAmbient",*(int *)(iVar2 + 4) + 0x10 + iVar4);

    FUN_009700f0("MatEmissive",*(int *)(iVar2 + 4) + 0x20 + iVar4);

    param_2 = param_2 + 1;

    param_1 = param_1 + 3;

    iVar4 = iVar4 + 0x30;

  }

  FUN_0051def0(0,0,0,0,g_flOne);

  return;

}
