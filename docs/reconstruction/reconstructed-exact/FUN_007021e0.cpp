// =============================================================================
// FUN_007021e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007021e0
// Address:   0x007021e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007021e0 @ 0x007021e0
// Stable ID: aa_007021e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_007021e0×2, FUN_007020e0.
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

int __thiscall FUN_007021e0(int param_1,int *param_2,int *param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int *local_8;

  int local_4;

  

  local_8 = (int *)(param_4 + 0x1c);

  local_4 = 0;

  iVar4 = 0;

  do {

    piVar1 = (int *)*local_8;

    iVar2 = piVar1[3];

    if (*(char *)(iVar2 + 0x44) == '\0') {

      cVar3 = FUN_007020e0(param_5,param_1,param_1 + 4);

      *(char *)(iVar2 + 0x44) = cVar3;

      if (cVar3 == '\x01') {

        iVar4 = FUN_007021e0(param_2,param_3,iVar2,param_5);

        if (iVar4 == 2) break;

      }

      else if (cVar3 == '\x04') {

        iVar4 = 2;

        break;

      }

    }

    if (*(char *)(iVar2 + 0x44) == '\x02') {

      *(int **)(*piVar1 + 0x10) = piVar1;

      *param_2 = *param_2 + 1;

      *param_3 = (int)piVar1;

    }

    local_4 = local_4 + 1;

    local_8 = local_8 + 4;

  } while (local_4 < 3);

  *(uint32_t /* width from decompiler */ *)(param_4 + 0x10) = 0x7f7fffff;

  *(int *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4) = param_4;

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  return iVar4;

}
