// =============================================================================
// FUN_00931440
// -----------------------------------------------------------------------------
// Stable ID: aa_00931440
// Address:   0x00931440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931440 @ 0x00931440
// Stable ID: aa_00931440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00931440.
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

uint32_t /* width from decompiler */ __thiscall FUN_00931440(int param_1,uint8_t param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_50 [2];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40 [2];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint8_t local_8;

  uint8_t local_5;

  

  if (*(int *)(*(int *)(in_EAX + 0xa8) + 0x38) == 0xe) {

    local_48 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x160);

    local_44 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x164);

    local_50[0] = 0x2053;

    if (*(int *)(param_1 + 0xc78) != 0) {

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_50,0x10,0);

      return 0;

    }

  }

  else {

    local_38 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x160);

    local_34 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x164);

    local_30 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x168);

    local_2c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x16c);

    local_40[0] = 0x203c;

    local_8 = 0;

    local_5 = param_2;

    if (*(int *)(param_1 + 0xc78) != 0) {

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_40,0x40,0);

    }

  }

  return 0;

}
