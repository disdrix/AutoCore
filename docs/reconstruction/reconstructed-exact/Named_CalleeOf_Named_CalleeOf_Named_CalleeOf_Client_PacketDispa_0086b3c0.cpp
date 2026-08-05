// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_0086b3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0086b3c0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x0086b3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_008697c0×2, FUN_0086a290×2, FUN_0086b370, FUN_0086b3c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_0086b3c0(int *param_1)



{

  int iVar1;

  char in_AL;

  uint32_t /* width from decompiler */ uVar2;

  int local_8;

  int local_4;

  

  if (in_AL != (char)param_1[0x14a]) {

    *(char *)(param_1 + 0x14a) = in_AL;

    if (in_AL != '\0') {

      param_1[0x155] = -1;

      FUN_008697c0(0);

      FUN_0086a290(1);

      param_1[0x13f] = 0;

      param_1[0x140] = 2;

      *(uint8_t *)((int)param_1 + 0xc5) = 1;

      if ((int *)param_1[399] != (int *)0x0) {

        iVar1 = *param_1;

        uVar2 = (**(code **)(*(int *)param_1[399] + 0x140))(&local_8,1);

        (**(code **)(iVar1 + 0x130))(uVar2);

      }

      local_8 = (int)((float)DAT_00d1e818 * (float)param_1[0x14d] * DAT_00aaa67c);

      local_4 = (int)((float)DAT_00d1e81c * (float)param_1[0x14e] * DAT_00aaa678);

      (**(code **)(*param_1 + 0x110))(&local_8);

      (**(code **)(*param_1 + 0x34c))();

      return;

    }

    FUN_008697c0(1);

    FUN_0086a290(0);

    local_8 = param_1[0x14b];

    local_4 = param_1[0x14c];

    param_1[0x13f] = 0xf;

    param_1[0x140] = 1;

    (**(code **)(*param_1 + 0x110))(&local_8);

    (**(code **)(*param_1 + 0x130))(param_1 + 0x14f);

    *(uint8_t *)((int)param_1 + 0xc5) = 0;

    FUN_0086b370();

  }

  return;

}
