// =============================================================================
// FUN_0082e160
// -----------------------------------------------------------------------------
// Stable ID: aa_0082e160
// Address:   0x0082e160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082e160 @ 0x0082e160
// Stable ID: aa_0082e160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_0082e160.
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

void __fastcall FUN_0082e160(int *param_1)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t auStack_8 [8];

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    if ((param_1[0x153] != 0) && (param_1[0x15d] != 0)) {

      iVar1 = *(int *)param_1[0x15d];

      uVar3 = (**(code **)(*(int *)param_1[0x153] + 0x120))(auStack_8,1,0);

      (**(code **)(iVar1 + 0x114))(uVar3);

    }

    if ((param_1[0x154] != 0) && (param_1[0x15e] != 0)) {

      iVar1 = *(int *)param_1[0x15e];

      uVar3 = (**(code **)(*(int *)param_1[0x154] + 0x120))(auStack_8,1,0);

      (**(code **)(iVar1 + 0x114))(uVar3);

    }

    if ((param_1[0x15b] != 0) && (param_1[0x15f] != 0)) {

      iVar1 = *(int *)param_1[0x15f];

      uVar3 = (**(code **)(*(int *)param_1[0x15b] + 0x120))(auStack_8,1,0);

      (**(code **)(iVar1 + 0x114))(uVar3);

    }

    if (DAT_00d1b6d8 == 0) {

      if (param_1[0x15d] != 0) {

        (**(code **)(*(int *)param_1[0x15d] + 4))(0);

      }

      if (param_1[0x15e] != 0) {

        (**(code **)(*(int *)param_1[0x15e] + 4))(0);

      }

      if (param_1[0x15f] != 0) {

        (**(code **)(*(int *)param_1[0x15f] + 4))(0);

      }

    }

  }

  return;

}
