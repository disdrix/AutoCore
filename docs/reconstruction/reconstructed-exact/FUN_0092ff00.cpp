// =============================================================================
// FUN_0092ff00
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ff00
// Address:   0x0092ff00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092ff00 @ 0x0092ff00
// Stable ID: aa_0092ff00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00405bd0×2, FUN_00405cb0, FUN_004e23d0, FUN_0092ff00, GetTickCount, Object_ResolveFromTFID.
//  - Return sites: 3.

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

void * __fastcall FUN_0092ff00(int param_1)



{

  TFID_16 *in_EAX;

  void *pvVar1;

  int iVar2;

  DWORD DVar3;

  uint uVar4;

  int local_28;

  int local_20 [2];

  uint local_18;

  uint local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint local_8;

  

  pvVar1 = Object_ResolveFromTFID(in_EAX);

  if (pvVar1 != (void *)0x0) {

    return pvVar1;

  }

  if (((in_EAX->bGlobal != 0) ||

      (iVar2 = FUN_004e23d0(in_EAX->dwCoidLo,in_EAX->dwCoidHi,local_20), iVar2 == 0)) ||

     (*(int *)(iVar2 + 0xc) == 0)) {

    DVar3 = GetTickCount();

    local_20[0] = param_1 + 0xd18;

    uVar4 = DVar3 / 1000;

    FUN_00405cb0();

    if (local_28 == *(int *)(param_1 + 0xd1c)) {

      local_18 = in_EAX->dwCoidLo;

      local_14 = in_EAX->dwCoidHi;

      local_10._0_1_ = in_EAX->bGlobal;

      local_10._1_1_ = in_EAX->bPad0;

      local_10._2_1_ = in_EAX->bPad1;

      local_10._3_1_ = in_EAX->bPad2;

      local_c._0_1_ = in_EAX->bPad3;

      local_c._1_1_ = in_EAX->bPad4;

      local_c._2_1_ = in_EAX->bPad5;

      local_c._3_1_ = in_EAX->bPad6;

      local_8 = uVar4;

      FUN_00405bd0();

    }

    else {

      if ((int)uVar4 <= *(int *)(local_28 + 0x20) + 10) {

        return (void *)0x0;

      }

      *(uint *)(local_28 + 0x20) = uVar4;

    }

    local_18 = in_EAX->dwCoidLo;

    local_14 = in_EAX->dwCoidHi;

    local_10._0_1_ = in_EAX->bGlobal;

    local_10._1_1_ = in_EAX->bPad0;

    local_10._2_1_ = in_EAX->bPad1;

    local_10._3_1_ = in_EAX->bPad2;

    local_c._0_1_ = in_EAX->bPad3;

    local_c._1_1_ = in_EAX->bPad4;

    local_c._2_1_ = in_EAX->bPad5;

    local_c._3_1_ = in_EAX->bPad6;

    local_8 = uVar4;

    FUN_00405bd0();

  }

  return (void *)0x0;

}
