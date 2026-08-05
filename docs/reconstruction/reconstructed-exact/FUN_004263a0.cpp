// =============================================================================
// FUN_004263a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004263a0
// Address:   0x004263a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004263a0 @ 0x004263a0
// Stable ID: aa_004263a0
// Embedded strings (evidence for future rename):
//   - "LogNetConnection"
//   - "PKT   OK - ssthresh = %f     cwnd=%f"
//   - "PKT SSOK - ssthresh = %f     cwnd=%f"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×15, goto×3, return×2.
//  - Notable callees: FUN_00783b60×3, FUN_00783aa0×2, FUN_004263a0, FUN_007845c0.
//  - Strings: "LogNetConnection"; "PKT   OK - ssthresh = %f     cwnd=%f"; "PKT SSOK - ssthresh = %f     cwnd=%f".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004263a0(void)



{

  float fVar1;

  char *pcVar2;

  uint uVar3;

  char unaff_BL;

  int *unaff_ESI;

  float fVar4;

  char *pcVar5;

  

  if ((_DAT_00d20060 & 1) == 0) {

    _DAT_00d20060 = _DAT_00d20060 | 1;

    DAT_00d2005c = FUN_00783b60("LogNetConnection");

  }

  if (*(char *)(DAT_00d2005c + 4) != '\0') {

    DAT_00d179a0 = DAT_00d2005c;

    FUN_007845c0();

    FUN_00783aa0();

    DAT_00d179a0 = 0;

  }

  pcVar2 = (char *)unaff_ESI[0x48];

  unaff_ESI[0x48] = *(int *)(pcVar2 + 0x10);

  if (*pcVar2 == '\0') {

    if (unaff_BL == '\0') goto LAB_0042642b;

  }

  else if (unaff_BL == '\0') {

    *(uint8_t *)(unaff_ESI + 0x3b) = 1;

LAB_0042642b:

    fVar1 = g_flLevelUpUiBase_Inferred;

    if ((*(byte *)(unaff_ESI + 0x2d) & 0xc) != 0) {

      fVar4 = (float)unaff_ESI[0x70] * DAT_00a0f298;

      if ((float)unaff_ESI[0x70] * DAT_00a0f298 < g_flLevelUpUiBase_Inferred) {

        fVar4 = g_flLevelUpUiBase_Inferred;

      }

      unaff_ESI[0x70] = (int)fVar4;

      fVar4 = (float)unaff_ESI[0x6f] - g_flOne;

      unaff_ESI[0x6f] = (int)fVar4;

      if (fVar4 < fVar1) {

        unaff_ESI[0x6f] = (int)fVar1;

      }

    }

    (**(code **)(*unaff_ESI + 0x40))();

    unaff_ESI[0x47] = unaff_ESI[0x47] + -1;

                    /* WARNING: Subroutine does not return */

    operator_delete(pcVar2);

  }

  unaff_ESI[0x2a] = *(int *)(pcVar2 + 4);

  if ((*(byte *)(unaff_ESI + 0x2d) & 0xc) != 0) {

    if ((float)unaff_ESI[0x70] < (float)unaff_ESI[0x6f] ||

        (float)unaff_ESI[0x70] == (float)unaff_ESI[0x6f]) {

      if ((float)unaff_ESI[0x6f] <= DAT_00a0f694 && DAT_00a0f694 != (float)unaff_ESI[0x6f]) {

        unaff_ESI[0x6f] = (int)(g_flOne / (float)unaff_ESI[0x6f] + (float)unaff_ESI[0x6f]);

      }

      if ((_DAT_00d20060 & 4) == 0) {

        _DAT_00d20060 = _DAT_00d20060 | 4;

        DAT_00d20054 = FUN_00783b60();

      }

      if (*(char *)(DAT_00d20054 + 4) == '\0') goto LAB_004265c8;

      fVar1 = (float)unaff_ESI[0x6f];

      fVar4 = (float)unaff_ESI[0x70];

      pcVar5 = "PKT   OK - ssthresh = %f     cwnd=%f";

      DAT_00d179a0 = DAT_00d20054;

    }

    else {

      uVar3 = _DAT_00d20060 & 2;

      unaff_ESI[0x6f] = (int)((float)unaff_ESI[0x6f] + g_flOne);

      if (uVar3 == 0) {

        _DAT_00d20060 = _DAT_00d20060 | 2;

        DAT_00d20058 = FUN_00783b60();

      }

      if (*(char *)(DAT_00d20058 + 4) == '\0') goto LAB_004265c8;

      fVar1 = (float)unaff_ESI[0x6f];

      fVar4 = (float)unaff_ESI[0x70];

      pcVar5 = "PKT SSOK - ssthresh = %f     cwnd=%f";

      DAT_00d179a0 = DAT_00d20058;

    }

    FUN_00783aa0(pcVar5,(double)fVar4,(double)fVar1);

    DAT_00d179a0 = 0;

  }

LAB_004265c8:

  (**(code **)(*unaff_ESI + 0x3c))();

  unaff_ESI[0x47] = unaff_ESI[0x47] + -1;

                    /* WARNING: Subroutine does not return */

  operator_delete(pcVar2);

}
