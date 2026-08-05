// =============================================================================
// FUN_007b3060
// -----------------------------------------------------------------------------
// Stable ID: aa_007b3060
// Address:   0x007b3060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b3060 @ 0x007b3060
// Stable ID: aa_007b3060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00755a50, FUN_007b3060, wcslen.
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

uint8_t __thiscall

FUN_007b3060(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,uint32_t /* width from decompiler */ param_6,

            int *param_7,int param_8)



{

  int iVar1;

  size_t sVar2;

  int *piVar3;

  uint uVar4;

  uint8_t local_9;

  uint8_t local_8 [8];

  

  uVar4 = 0;

  local_9 = 0;

  sVar2 = wcslen((wchar_t *)(param_4 + *(int *)(param_1 + 0x118) * 2));

  if (sVar2 != 0) {

    do {

      piVar3 = (int *)FUN_00755a50(local_8);

      iVar1 = *piVar3;

      param_2 = param_2 + iVar1;

      if (param_5 < param_2) {

        if ((int)(iVar1 * 3 + (iVar1 * 3 >> 0x1f & 3U)) >> 2 <= (param_5 - param_2) + iVar1) {

          uVar4 = uVar4 + 1;

        }

        local_9 = 1;

        break;

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 < sVar2);

  }

  *param_7 = uVar4 + param_8 + *(int *)(param_1 + 0x118);

  return local_9;

}
