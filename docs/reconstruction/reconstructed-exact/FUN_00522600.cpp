// =============================================================================
// FUN_00522600
// -----------------------------------------------------------------------------
// Stable ID: aa_00522600
// Address:   0x00522600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522600 @ 0x00522600
// Stable ID: aa_00522600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00522600.
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

void __thiscall FUN_00522600(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  

  if ((*(int *)(param_1 + 0x250) != 0) && (*(int *)(*(int *)(param_1 + 0x250) + 0x270) != 0)) {

    iVar2 = (**(code **)(*param_2 + 0x214))();

    if (iVar2 != 0) {

      iVar1 = *(int *)(*(int *)(iVar2 + 4) + 4);

      fVar4 = *(float *)(*(int *)(*(int *)(iVar2 + 0xac + iVar1) + 0x3c) + 0x500) * DAT_00aaa68c;

      iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

      iVar2 = (**(code **)(*(int *)(iVar2 + iVar1 + 4) + 0x27c))();

      iVar2 = iVar2 - iVar3;

      if (iVar2 < -5) {

        fVar4 = 0.0;

      }

      else {

        if (5 < iVar2) {

          iVar2 = 5;

        }

        fVar4 = (float)iVar2 * DAT_009ceea8 + fVar4;

        if (fVar4 < 0.0) {

          fVar4 = 0.0;

        }

      }

      *(float *)(param_1 + 0x600) =

           (float)*(int *)(param_1 + 0x608) + *(float *)(param_1 + 0x600) + fVar4;

    }

  }

  return;

}
