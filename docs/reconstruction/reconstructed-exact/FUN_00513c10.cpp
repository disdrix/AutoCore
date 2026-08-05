// =============================================================================
// FUN_00513c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00513c10
// Address:   0x00513c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513c10 @ 0x00513c10
// Stable ID: aa_00513c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×7, return×7.
//  - Notable callees: FUN_00513bc0, FUN_00513c10, FUN_00521eb0.
//  - Return sites: 7.

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

char __thiscall FUN_00513c10(int *param_1,int param_2,int param_3)



{

  char cVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  

  if (param_3 == 0) {

    return '\x03';

  }

  if ((short *)(param_3 + 0xb0) != (short *)0x0) {

    cVar1 = FUN_00513bc0(param_3);

    if (cVar1 != '\0') {

      if (((uint)param_1[0x5f] >> 0x13 & 1) != 0) {

        return '\0';

      }

      sVar3 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4b4);

      sVar2 = (**(code **)(*param_1 + 0x8c))();

      if (sVar3 <= sVar2) {

        return '\0';

      }

      if (param_2 == 0) {

        return '\x03';

      }

      sVar3 = (**(code **)(*param_1 + 0x8c))();

      iVar4 = FUN_00521eb0();

      if ((iVar4 < sVar3 + 1) && (*(int *)(param_2 + 0x6b4) < 1)) {

        return '\x01';

      }

      return (sVar3 + 1 <= (int)*(short *)(param_3 + 0xb0)) * '\x02' + '\x02';

    }

  }

  return '\x03';

}
