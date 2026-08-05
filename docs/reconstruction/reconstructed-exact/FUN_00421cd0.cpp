// =============================================================================
// FUN_00421cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00421cd0
// Address:   0x00421cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00421cd0 @ 0x00421cd0
// Stable ID: aa_00421cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×1.
//  - Notable callees: FUN_0041d7b0×2, FUN_00421cd0, FUN_00437cd0.
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

int FUN_00421cd0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  uint8_t *puVar5;

  int *unaff_EBX;

  int unaff_EDI;

  uint8_t local_4 [4];

  

  iVar4 = param_1;

  if (unaff_EDI != 0) {

    if (in_EAX == 0) {

      in_EAX = 1;

    }

    FUN_00437cd0();

    puVar1 = *(uint32_t /* width from decompiler */ **)(iVar4 + 4);

    iVar3 = (**(code **)*puVar1)(puVar1,&DAT_00a860e8,&param_1);

    if (iVar3 < 0) {

      FUN_0041d7b0();

    }

    else {

      iVar3 = (**(code **)(*unaff_EBX + 0x10))(unaff_EBX,in_EAX);

      FUN_0041d7b0();

      if (-1 < iVar3) goto LAB_00421d35;

    }

    return iVar3;

  }

LAB_00421d35:

  puVar5 = param_4;

  if (param_4 == (uint8_t *)0x0) {

    puVar5 = local_4;

  }

  piVar2 = *(int **)(iVar4 + 4);

  iVar4 = (**(code **)(*piVar2 + 0x10))(piVar2,0,&DAT_00aa9110,param_3,puVar5,param_2);

  return iVar4;

}
