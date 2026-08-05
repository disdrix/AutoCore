// =============================================================================
// FUN_0093d6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093d6e0
// Address:   0x0093d6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093d6e0 @ 0x0093d6e0
// Stable ID: aa_0093d6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, switch×1, goto×1.
//  - Notable callees: FUN_007fc270×2, Client_RefreshOpenMissionUiWindows, FUN_00571010, FUN_00571b80, FUN_0085fd20, FUN_008801b0, FUN_00931d60, FUN_0093d6e0.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __fastcall FUN_0093d6e0(uint32_t /* width from decompiler */ param_1,char param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  iVar1 = *(int *)(param_3 + 0xe98);

  *(uint8_t *)(param_3 + 0xc70) = 0;

  if ((iVar1 == 0) || (in_EAX == (int *)0x0)) {

    return 0;

  }

  switch(param_2) {

  case '\x01':

    iVar1 = *(int *)(*(int *)(iVar1 + 0x250) + 0x2b0);

    iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0x1040) + 0x50c) + 0x580);

    break;

  case '\x02':

    FUN_007fc270(param_2);

    (**(code **)(*in_EAX + 0x2ac))(*(uint32_t /* width from decompiler */ *)(param_3 + 0xd34));

    if (*(int *)(param_3 + 0x1078) == 0) {

      return 0;

    }

    FUN_008801b0(*(int *)(param_3 + 0x1078));

    return 0;

  case '\x03':

    iVar1 = *(int *)(iVar1 + 0xcbc);

    iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0x1034) + 0x510) + 0x580);

    break;

  case '\x04':

    iVar2 = *(int *)(param_3 + 0x105c);

    if (iVar2 == 0) {

      return 0;

    }

    iVar1 = *(int *)(*(int *)(iVar2 + 0x588) + 0x35c);

    iVar2 = *(int *)(iVar2 + 0x5ac);

    break;

  case '\x05':

    iVar1 = *(int *)(iVar1 + 0xce0);

    iVar2 = *(int *)(*(int *)(param_3 + 0x1050) + 0x588);

    break;

  default:

    goto switchD_0093d715_default;

  }

  if ((iVar1 != 0) && (iVar2 != 0)) {

    if (param_2 != '\x04') {

      iVar1 = FUN_00571010(in_EAX[0x58],in_EAX[0x59]);

      if (iVar1 != 0) {

        FUN_00571b80(in_EAX,param_4,0);

      }

      FUN_0085fd20();

      *(int *)(iVar2 + 0x500) = *(int *)(iVar2 + 0x500) + -1;

      (**(code **)(*in_EAX + 0x260))(param_4);

    }

    (**(code **)(*in_EAX + 0x218))

              (*(uint32_t /* width from decompiler */ *)

                (*(int *)(*(int *)(*(int *)(param_3 + 0xe98) + 4) + 4) + 0xa8 +

                *(int *)(param_3 + 0xe98)));

    FUN_007fc270(unaff_retaddr);

    Client_RefreshOpenMissionUiWindows(param_3);

    *(uint8_t *)(param_3 + 0x30b4) = 1;

    *(uint8_t *)(param_3 + 0x30b5) = 0;

    if (*(int **)(param_3 + 0x309c) != (int *)0x0) {

      (**(code **)(**(int **)(param_3 + 0x309c) + 4))(0);

    }

    FUN_00931d60();

    return 1;

  }

switchD_0093d715_default:

  return 0;

}
