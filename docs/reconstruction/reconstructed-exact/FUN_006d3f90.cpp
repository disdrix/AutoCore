// =============================================================================
// FUN_006d3f90
// -----------------------------------------------------------------------------
// Stable ID: aa_006d3f90
// Address:   0x006d3f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d3f90 @ 0x006d3f90
// Stable ID: aa_006d3f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_006d3e80×3, FUN_006d3ac0, FUN_006d3f90.
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

int __thiscall

FUN_006d3f90(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int *param_3,int param_4,int param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  uint8_t local_9d;

  int local_9c;

  int local_98;

  uint32_t /* width from decompiler */ local_94;

  uint8_t local_90 [140];

  

  local_9c = param_4;

  iVar3 = param_5;

  if (param_4 < param_5) {

    local_98 = param_4 << 7;

    iVar4 = param_5 << 7;

    local_94 = param_1;

    do {

      iVar1 = local_98;

      if ((*(char *)(*param_3 + 0x7c + local_98) == '\x01') &&

         (pcVar2 = (char *)FUN_006d3ac0(&local_9d,param_2,*param_3 + local_98 + 0x50,param_6),

         iVar3 = param_5, *pcVar2 == '\0')) {

        iVar3 = *param_3;

        FUN_006d3e80(iVar1 + iVar3);

        FUN_006d3e80(iVar4 + -0x80 + iVar3);

        FUN_006d3e80(local_90);

        iVar3 = param_5 + -1;

        iVar4 = iVar4 + -0x80;

        param_5 = iVar3;

      }

      else {

        local_9c = local_9c + 1;

        local_98 = iVar1 + 0x80;

      }

    } while (local_9c < iVar3);

  }

  return iVar3;

}
