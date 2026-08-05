// =============================================================================
// FUN_007a4ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4ae0
// Address:   0x007a4ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4ae0 @ 0x007a4ae0
// Stable ID: aa_007a4ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: strncpy×5, FUN_007a4ae0, time.
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

void __thiscall FUN_007a4ae0(int *param_1,char *param_2,char param_3,int param_4)



{

  char *pcVar1;

  time_t tVar2;

  int unaff_retaddr;

  

  if (param_3 == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x210) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x208);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x214) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20c);

    param_2[0x1d3] = '\0';

    if (param_2 + 0x1c2 != (char *)0x0) {

      strncpy(param_2 + 0x1d3,param_2 + 0x1c2,0x10);

      param_2[0x1e3] = '\0';

    }

    pcVar1 = (char *)(**(code **)(*param_1 + 0x38))

                               (*(uint32_t /* width from decompiler */ *)(param_2 + 0x1f0),*(uint32_t /* width from decompiler */ *)(param_2 + 500),

                                *(uint32_t /* width from decompiler */ *)(param_2 + 0x1f8));

    *param_2 = '\0';

    if (pcVar1 != (char *)0x0) {

      strncpy(param_2,pcVar1,0x31);

      param_2[0x31] = '\0';

    }

    if (((unaff_retaddr == 0) || (*(int *)(unaff_retaddr + 0x208) != *(int *)(param_2 + 0x208))) ||

       (*(int *)(unaff_retaddr + 0x20c) != *(int *)(param_2 + 0x20c))) {

      param_2[0x224] = '\x04';

    }

    else {

      param_2[0x224] = '\x05';

    }

  }

  else {

    if (param_4 != 0) {

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x210) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x208);

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x214) = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20c);

      param_2[0x1d3] = '\0';

      if ((char *)(param_4 + 0x1c2) != (char *)0x0) {

        strncpy(param_2 + 0x1d3,(char *)(param_4 + 0x1c2),0x10);

        param_2[0x1e3] = '\0';

      }

    }

    pcVar1 = (char *)(**(code **)(*param_1 + 0x38))

                               (*(uint32_t /* width from decompiler */ *)(param_2 + 0x1f0),*(uint32_t /* width from decompiler */ *)(param_2 + 500),

                                *(uint32_t /* width from decompiler */ *)(param_2 + 0x1f8));

    *param_2 = '\0';

    if (pcVar1 != (char *)0x0) {

      strncpy(param_2,pcVar1,0x31);

      param_2[0x31] = '\0';

    }

    param_2[0x224] = '\x03';

  }

  param_2[0x208] = -1;

  param_2[0x209] = -1;

  param_2[0x20a] = -1;

  param_2[0x20b] = -1;

  param_2[0x20c] = -1;

  param_2[0x20d] = -1;

  param_2[0x20e] = -1;

  param_2[0x20f] = -1;

  param_2[0x1c2] = '\0';

  strncpy(param_2 + 0x1c2,"",0x10);

  param_2[0x1d2] = '\0';

  param_2[0x1e8] = '\0';

  param_2[0x1e9] = '\0';

  param_2[0x1ea] = '\0';

  param_2[0x1eb] = '\0';

  param_2[0x1ec] = '\0';

  param_2[0x1ed] = '\0';

  param_2[0x1ee] = '\0';

  param_2[0x1ef] = '\0';

  tVar2 = time((time_t *)0x0);

  *(int *)(param_2 + 0x218) = (int)tVar2;

  param_2[0x248] = '\0';

  *(int *)(param_2 + 0x21c) = (int)tVar2 + 0x278d00;

  return;

}
