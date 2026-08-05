// =============================================================================
// FUN_0076d510
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d510
// Address:   0x0076d510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d510 @ 0x0076d510
// Stable ID: aa_0076d510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_0076d510, strncpy, strrchr.
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

void __fastcall FUN_0076d510(uint32_t /* width from decompiler */ param_1,char *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  char *pcVar2;

  int iVar3;

  int unaff_EBX;

  char *unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_248 [12];

  char acStack_218 [532];

  

  *unaff_ESI = '\0';

  if (*param_2 != '\0') {

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

    puVar4 = local_248;

    for (iVar3 = 0x8f; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    local_248[0] = 0x23c;

    iVar3 = (*DAT_00d0dfb4)(uVar1,param_3,local_248);

    if (iVar3 != 0) {

      pcVar2 = strrchr(acStack_218,0x5c);

      if (pcVar2 == (char *)0x0) {

        pcVar2 = acStack_218;

      }

      else {

        pcVar2 = pcVar2 + 1;

      }

      strncpy(unaff_ESI,pcVar2,unaff_EBX - 1);

      unaff_ESI[unaff_EBX + -1] = '\0';

    }

  }

  return;

}
