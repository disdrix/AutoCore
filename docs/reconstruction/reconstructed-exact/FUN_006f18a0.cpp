// =============================================================================
// FUN_006f18a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f18a0
// Address:   0x006f18a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f18a0 @ 0x006f18a0
// Stable ID: aa_006f18a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_006f18a0.
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

void __thiscall

FUN_006f18a0(int param_1,uint8_t *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  

  uVar2 = param_7;

  iVar1 = *(int *)(param_1 + 0x10);

  do {

    iVar1 = iVar1 + -1;

    if (iVar1 < 0) {

      *param_2 = 1;

      return;

    }

    pcVar3 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)

                                 (*(int *)(*(int *)(param_1 + 0xc) + iVar1 * 4) + 0xc))

                               (&param_7,param_3,param_4,param_5,param_6,uVar2);

  } while (*pcVar3 != '\0');

  *param_2 = 0;

  return;

}
