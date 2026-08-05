// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00772910
// -----------------------------------------------------------------------------
// Stable ID: aa_00772910
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x00772910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ecc_sys (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, while×2, do×1.
//  - Notable callees: FUN_007701d0, FUN_00770850, FUN_00771920, FUN_00772910, toupper.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_CalleeOf_Named_ecc_sys_00772910(int *param_1,uint param_2)



{

  char *pcVar1;

  int iVar2;

  char cVar3;

  char *in_EAX;

  int iVar5;

  int iVar4;

  

  iVar2 = param_2;

  if (((int)param_2 < 2) || (0x40 < (int)param_2)) {

    return -3;

  }

  cVar3 = *in_EAX;

  if (cVar3 == '-') {

    in_EAX = in_EAX + 1;

  }

  param_2 = (uint)(cVar3 == '-');

  FUN_007701d0();

  cVar3 = *in_EAX;

  while (cVar3 != '\0') {

    if (iVar2 < 0x24) {

      iVar4 = toupper((int)cVar3);

      cVar3 = (char)iVar4;

    }

    iVar4 = 0;

    do {

      if (cVar3 == PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[iVar4]) break;

      if (cVar3 == PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[iVar4 + 1]) {

        iVar4 = iVar4 + 1;

        break;

      }

      if (cVar3 == PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[iVar4 + 2]) {

        iVar4 = iVar4 + 2;

        break;

      }

      if (cVar3 == PTR_s_0123456789ABCDEFGHIJKLMNOPQRSTUV_00afa2a8[iVar4 + 3]) {

        iVar4 = iVar4 + 3;

        break;

      }

      iVar4 = iVar4 + 4;

    } while (iVar4 < 0x40);

    if (iVar2 <= iVar4) break;

    iVar5 = FUN_00771920(param_1,iVar2,param_1);

    if (iVar5 != 0) {

      return iVar5;

    }

    iVar4 = FUN_00770850(iVar4,param_1);

    if (iVar4 != 0) {

      return iVar4;

    }

    pcVar1 = in_EAX + 1;

    in_EAX = in_EAX + 1;

    cVar3 = *pcVar1;

  }

  if (*param_1 != 0) {

    param_1[2] = param_2;

  }

  return 0;

}
