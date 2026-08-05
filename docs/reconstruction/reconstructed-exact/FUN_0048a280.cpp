// =============================================================================
// FUN_0048a280
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a280
// Address:   0x0048a280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a280 @ 0x0048a280
// Stable ID: aa_0048a280
// Embedded strings (evidence for future rename):
//   - "GetCapabilities() - Enter"
//   - "GetCapabilities(), capability = %d\n"
//   - "EffectEvent"
//   - "GetCapabilities() - Exit"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0056f570×3, GetCapabilities×3, CreateEventA, FUN_0048a280, FUN_0048ac10.
//  - Strings: "GetCapabilities() - Enter"; "426"; "462"; "GetCapabilities(), capability = %d\n".
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

void FUN_0048a280(int *param_1)



{

  int iVar1;

  char *pcVar2;

  char *pcVar3;

  bool bVar4;

  char local_100 [256];

  

  FUN_0056f570("GetCapabilities() - Enter");

  if (param_1 == (int *)0x0) goto LAB_0048a2f4;

  *param_1 = 0;

  FUN_0048ac10(local_100);

  iVar1 = 4;

  bVar4 = true;

  pcVar2 = local_100;

  pcVar3 = "426";

  do {

    if (iVar1 == 0) break;

    iVar1 = iVar1 + -1;

    bVar4 = *pcVar2 == *pcVar3;

    pcVar2 = pcVar2 + 1;

    pcVar3 = pcVar3 + 1;

  } while (bVar4);

  if (bVar4) {

LAB_0048a2dc:

    *param_1 = 1;

  }

  else {

    iVar1 = 4;

    bVar4 = true;

    pcVar2 = local_100;

    pcVar3 = "462";

    do {

      if (iVar1 == 0) break;

      iVar1 = iVar1 + -1;

      bVar4 = *pcVar2 == *pcVar3;

      pcVar2 = pcVar2 + 1;

      pcVar3 = pcVar3 + 1;

    } while (bVar4);

    if (bVar4) goto LAB_0048a2dc;

  }

  FUN_0056f570("GetCapabilities(), capability = %d\n",*param_1);

LAB_0048a2f4:

  if (*param_1 != 0) {

    DAT_00b034fc = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,"EffectEvent");

  }

  FUN_0056f570("GetCapabilities() - Exit");

  return;

}
