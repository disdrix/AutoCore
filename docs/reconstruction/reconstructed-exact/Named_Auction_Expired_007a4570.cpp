// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1, switch×1, goto×1.
//  - Notable callees: sprintf×2, FUN_007a4570, strncpy.
//  - Strings: "Auction Outbid"; "Auction Sold"; "Auction Won"; "Auction Expired".
//  - Return sites: 3.

// =============================================================================
// Named_Auction_Expired_007a4570
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4570
// Address:   0x007a4570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Auction Expired"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Auction_Expired_007a4570(int *param_1,char *param_2,char *param_3,char param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  char local_208;

  uint32_t /* width from decompiler */ local_207;

  

  if (param_2 == (char *)0x0) {

    return;

  }

  if (param_4 < '\x01') {

    *param_2 = '\0';

    if (param_3 == (char *)0x0) {

      return;

    }

  }

  else {

    local_208 = '\0';

    puVar3 = &local_207;

    for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    *(uint16_t *)puVar3 = 0;

    *(uint8_t *)((int)puVar3 + 2) = 0;

    switch(param_4) {

    case '\x01':

      uVar1 = (**(code **)(*param_1 + 0x58))(param_3);

      pcVar4 = "Auction Outbid";

      break;

    case '\x02':

      uVar1 = (**(code **)(*param_1 + 0x58))(param_3);

      pcVar4 = "Auction Sold";

      break;

    case '\x03':

      uVar1 = (**(code **)(*param_1 + 0x58))(param_3);

      pcVar4 = "Auction Won";

      break;

    case '\x04':

      uVar1 = (**(code **)(*param_1 + 0x58))(param_3);

      pcVar4 = "Auction Expired";

      break;

    case '\x05':

      uVar1 = (**(code **)(*param_1 + 0x58))(param_3);

      pcVar4 = "Auction Cancelled";

      break;

    case '\x06':

      uVar1 = (**(code **)(*param_1 + 0x58))("Item Lost In Mail");

      sprintf(&local_208,"%s",uVar1);

    default:

      param_3 = &local_208;

      *param_2 = '\0';

      goto LAB_007a467f;

    }

    uVar1 = (**(code **)(*param_1 + 0x58))(pcVar4,uVar1);

    sprintf(&local_208,"%s: %s",uVar1);

    param_3 = &local_208;

    *param_2 = '\0';

  }

LAB_007a467f:

  strncpy(param_2,param_3,0x31);

  param_2[0x31] = '\0';

  return;

}
