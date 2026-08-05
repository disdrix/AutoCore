// =============================================================================
// FUN_00782890
// -----------------------------------------------------------------------------
// Stable ID: aa_00782890
// Address:   0x00782890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782890 @ 0x00782890
// Stable ID: aa_00782890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×8, return×7, while×1.
//  - Notable callees: FUN_00782890.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __fastcall FUN_00782890(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int iVar3;

  

  iVar3 = *(int *)(in_EAX + 0xc);

  if ((iVar3 != 0) || (*(int *)(in_EAX + 8) != 0)) {

    iVar1 = *(int *)(in_EAX + 8);

    if ((iVar1 != 0) == (iVar3 != 0)) {

      iVar2 = *(int *)(iVar3 + 8);

      while (iVar2 != 0) {

        iVar3 = *(int *)(iVar3 + 8);

        iVar2 = *(int *)(iVar3 + 8);

      }

      *(int *)(iVar3 + 8) = iVar1;

      *(int *)(*(int *)(in_EAX + 8) + 0x10) = iVar3;

      *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0xc) + 0x10) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

      if (*(int *)(in_EAX + 0x10) == 0) {

        param_2[1] = *(int *)(in_EAX + 0xc);

      }

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

      *param_2 = *param_2 + -1;

      return 1;

    }

    if (iVar3 == 0) {

      iVar3 = iVar1;

    }

    iVar1 = *(int *)(in_EAX + 0x10);

    if (iVar1 != 0) {

      if (*(int *)(iVar1 + 0xc) == in_EAX) {

        *(int *)(iVar1 + 0xc) = iVar3;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

        *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

        *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

        *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

        *param_2 = *param_2 + -1;

        return 1;

      }

      *(int *)(iVar1 + 8) = iVar3;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

      *param_2 = *param_2 + -1;

      return 1;

    }

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = 0;

    param_2[1] = iVar3;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *param_2 = *param_2 + -1;

    return 1;

  }

  iVar3 = *(int *)(in_EAX + 0x10);

  if (iVar3 == 0) {

    param_2[1] = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *param_2 = *param_2 + -1;

    return 1;

  }

  if (*(int *)(iVar3 + 0xc) == in_EAX) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *param_2 = *param_2 + -1;

    return 1;

  }

  *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

  *param_2 = *param_2 + -1;

  return 1;

}
