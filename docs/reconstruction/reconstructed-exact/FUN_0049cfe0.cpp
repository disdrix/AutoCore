// =============================================================================
// FUN_0049cfe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049cfe0
// Address:   0x0049cfe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049cfe0 @ 0x0049cfe0
// Stable ID: aa_0049cfe0
// Embedded strings (evidence for future rename):
//   - "speed"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0049cfe0, FUN_00799200, FUN_007a4480.
//  - Strings: "speed"; "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ FUN_0049cfe0(int param_1,int *param_2)



{

  float fVar1;

  char cVar2;

  int iVar3;

  int *local_4;

  

  if (param_2 != (int *)0x0) {

    iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_4);

    fVar1 = g_flOne;

    if ((iVar3 == 0) && (local_4 != (int *)0x0)) {

      *(byte *)(param_1 + 0x3e3) = *(byte *)(param_1 + 0x3e3) | 8;

      *(float *)(param_1 + 0x3c) = fVar1;

      cVar2 = FUN_00799200(local_4,L"speed",(float *)(param_1 + 0x3c),param_1 + 0x40,&param_2);

      if (cVar2 != '\0') {

        *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) & 0x7f | (char)param_2 << 7;

      }

      (**(code **)(*local_4 + 8))(local_4);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
