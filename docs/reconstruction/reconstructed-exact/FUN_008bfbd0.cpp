// =============================================================================
// FUN_008bfbd0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bfbd0
// Address:   0x008bfbd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bfbd0 @ 0x008bfbd0
// Stable ID: aa_008bfbd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: FUN_008bfbd0.
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

void __fastcall FUN_008bfbd0(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if (param_1[0x168] != 0) {

      (**(code **)(*(int *)param_1[0x168] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x50d) == '\0') || ((char)param_1[0x145] == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x168] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x168] + 0xd4))((char)param_1[0x145]);

      (**(code **)(*(int *)param_1[0x168] + 0x34c))();

    }

    if (param_1[0x169] != 0) {

      (**(code **)(*(int *)param_1[0x169] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x50e) == '\0') || (*(char *)((int)param_1 + 0x515) == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x169] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x169] + 0xd4))(*(uint8_t *)((int)param_1 + 0x515));

      (**(code **)(*(int *)param_1[0x169] + 0x34c))();

    }

    if (param_1[0x16a] != 0) {

      (**(code **)(*(int *)param_1[0x16a] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x50f) == '\0') || (*(char *)((int)param_1 + 0x516) == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x16a] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x16a] + 0xd4))(*(uint8_t *)((int)param_1 + 0x516));

      (**(code **)(*(int *)param_1[0x16a] + 0x34c))();

    }

    if (param_1[0x16b] != 0) {

      (**(code **)(*(int *)param_1[0x16b] + 0xd4))(1);

      if (((char)param_1[0x144] == '\0') || (*(char *)((int)param_1 + 0x517) == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x16b] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x16b] + 0xd4))(*(uint8_t *)((int)param_1 + 0x517));

      (**(code **)(*(int *)param_1[0x16b] + 0x34c))();

    }

    if (param_1[0x16c] != 0) {

      (**(code **)(*(int *)param_1[0x16c] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x511) == '\0') || ((char)param_1[0x146] == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x16c] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x16c] + 0xd4))((char)param_1[0x146]);

      (**(code **)(*(int *)param_1[0x16c] + 0x34c))();

    }

    if (param_1[0x16d] != 0) {

      (**(code **)(*(int *)param_1[0x16d] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x512) == '\0') || (*(char *)((int)param_1 + 0x519) == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x16d] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x16d] + 0xd4))(*(uint8_t *)((int)param_1 + 0x519));

      (**(code **)(*(int *)param_1[0x16d] + 0x34c))();

    }

    if (param_1[0x16e] != 0) {

      (**(code **)(*(int *)param_1[0x16e] + 0xd4))(1);

      if ((*(char *)((int)param_1 + 0x513) == '\0') || (*(char *)((int)param_1 + 0x51a) == '\0')) {

        uVar2 = 0;

      }

      else {

        uVar2 = 1;

      }

      (**(code **)(*(int *)param_1[0x16e] + 0x3c8))(uVar2,1);

      (**(code **)(*(int *)param_1[0x16e] + 0xd4))(*(uint8_t *)((int)param_1 + 0x51a));

                    /* WARNING: Could not recover jumptable at 0x008bfea1. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(*(int *)param_1[0x16e] + 0x34c))();

      return;

    }

  }

  return;

}
