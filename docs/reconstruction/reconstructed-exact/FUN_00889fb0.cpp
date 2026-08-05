// =============================================================================
// FUN_00889fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00889fb0
// Address:   0x00889fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00889fb0 @ 0x00889fb0
// Stable ID: aa_00889fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00822cb0×4, FUN_00756c90×2, FUN_00889fb0.
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

void FUN_00889fb0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int in_EAX;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (((char)param_2 != '\0' || (in_EAX != param_1[0x14a])))) {

    param_1[0x14a] = in_EAX;

    if (in_EAX == 0) {

      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();

      if (cVar1 == '\0') {

        (**(code **)(*(int *)param_1[0x143] + 0x43c))();

        (**(code **)(*(int *)param_1[0x143] + 4))(1);

      }

      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)param_1[0x144] + 4))(0);

        (**(code **)(*(int *)param_1[0x144] + 0x440))();

      }

      FUN_00822cb0(param_2);

      (**(code **)(*(int *)param_1[0x145] + 0x94))();

      FUN_00822cb0(param_2);

      FUN_00756c90();

    }

    else if (in_EAX == 1) {

      cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)param_1[0x143] + 4))(0);

        (**(code **)(*(int *)param_1[0x143] + 0x440))();

      }

      cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();

      if (cVar1 == '\0') {

        (**(code **)(*(int *)param_1[0x144] + 0x43c))();

        (**(code **)(*(int *)param_1[0x144] + 4))(1);

      }

      FUN_00822cb0(param_2);

      FUN_00756c90();

      FUN_00822cb0(param_2);

      (**(code **)(*(int *)param_1[0x146] + 0x94))();

      return;

    }

  }

  return;

}
