// =============================================================================
// FUN_00861d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00861d70
// Address:   0x00861d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00861d70 @ 0x00861d70
// Stable ID: aa_00861d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00791f30, FUN_00861d70.
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

void __thiscall FUN_00861d70(int param_1,float param_2)



{

  char cVar1;

  float fVar2;

  

  if (*(int **)(param_1 + 0x4fc) != (int *)0x0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x4fc) + 0xd0))();

    if (cVar1 != '\0') {

      fVar2 = *(float *)(param_1 + 0x508) + param_2;

      *(float *)(param_1 + 0x508) = fVar2;

      if ((*(float *)(param_1 + 0x520) <= fVar2 && fVar2 != *(float *)(param_1 + 0x520)) &&

         (*(char *)(param_1 + 0x50c) == '\0')) {

        (**(code **)(**(int **)(param_1 + 0x4fc) + 0xfc))(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x524));

        *(uint8_t *)(param_1 + 0x50c) = 1;

      }

    }

  }

  FUN_00791f30(param_2);

  return;

}
