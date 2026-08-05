// =============================================================================
// FUN_00794200
// -----------------------------------------------------------------------------
// Stable ID: aa_00794200
// Address:   0x00794200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00794200 @ 0x00794200
// Stable ID: aa_00794200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00794200.
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

void __thiscall FUN_00794200(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  bool bVar2;

  

  if ((*(char *)((int)param_1 + 0xc2) != '\0') && (*(char *)((int)param_1 + 0x489) == '\0')) {

    if ((int)(DAT_00d1e870 * DAT_00aaa7ac) % 0x50 < 0x29) {

      bVar2 = *(char *)((int)param_1 + 0x48a) != '\0';

      *(uint8_t *)((int)param_1 + 0x48a) = 1;

    }

    else {

      bVar2 = *(char *)((int)param_1 + 0x48a) == '\0';

      *(uint8_t *)((int)param_1 + 0x48a) = 0;

    }

    if (!bVar2) {

      (**(code **)(*param_1 + 0x34c))();

    }

  }

  (**(code **)(*param_1 + 500))(param_2);

  cVar1 = (**(code **)(*param_1 + 0xf8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x348))(param_2);

  }

  if ((int *)param_1[0xad] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(param_2);

  }

  return;

}
