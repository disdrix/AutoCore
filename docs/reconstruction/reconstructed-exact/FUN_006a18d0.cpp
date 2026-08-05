// =============================================================================
// FUN_006a18d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a18d0
// Address:   0x006a18d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a18d0 @ 0x006a18d0
// Stable ID: aa_006a18d0
// Embedded strings (evidence for future rename):
//   - "CBezierSpline"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0069fac0×11, atof×8, FUN_006a13e0, FUN_006a18d0, atoi.
//  - Strings: "CBezierSpline".
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

void __fastcall FUN_006a18d0(float *param_1)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  bool bVar4;

  double dVar5;

  int local_120;

  float local_118;

  float local_114;

  float local_110;

  float local_10c;

  char local_108 [260];

  

  FUN_0069fac0();

  pcVar3 = "CBezierSpline";

  iVar1 = 0xd;

  bVar4 = true;

  pcVar2 = local_108;

  do {

    pcVar3 = pcVar3 + 1;

    if (iVar1 == 0) break;

    iVar1 = iVar1 + -1;

    bVar4 = *pcVar2 == *pcVar3;

    pcVar2 = pcVar2 + 1;

  } while (bVar4);

  if (bVar4) {

    FUN_0069fac0();

    dVar5 = atof(local_108);

    *param_1 = (float)dVar5;

    FUN_0069fac0();

    dVar5 = atof(local_108);

    param_1[1] = (float)dVar5;

    FUN_0069fac0();

    dVar5 = atof(local_108);

    param_1[2] = (float)dVar5;

    FUN_0069fac0();

    if (local_108[0] == '{') {

      FUN_0069fac0();

      local_120 = atoi(local_108);

      if (0 < local_120) {

        do {

          FUN_0069fac0();

          dVar5 = atof(local_108);

          local_110 = (float)dVar5;

          FUN_0069fac0();

          dVar5 = atof(local_108);

          local_10c = (float)dVar5;

          FUN_0069fac0();

          dVar5 = atof(local_108);

          local_118 = (float)dVar5;

          FUN_0069fac0();

          dVar5 = atof(local_108);

          local_114 = (float)dVar5;

          FUN_0069fac0();

          dVar5 = atof(local_108);

          FUN_006a13e0(&local_110,&local_118,(float)dVar5);

          local_120 = local_120 + -1;

        } while (local_120 != 0);

      }

    }

  }

  return;

}
