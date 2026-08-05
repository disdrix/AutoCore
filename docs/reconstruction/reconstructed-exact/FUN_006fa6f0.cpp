// =============================================================================
// FUN_006fa6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006fa6f0
// Address:   0x006fa6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fa6f0 @ 0x006fa6f0
// Stable ID: aa_006fa6f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006fa670×4, FUN_006f8340, FUN_006fa6f0.
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

void FUN_006fa6f0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,

                 uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  char cVar1;

  char cVar2;

  ushort uVar3;

  ushort local_8;

  ushort local_6 [3];

  

  local_6[1] = 0;

  FUN_006f8340(&local_8,local_6);

  FUN_006fa670(param_1,&local_8,param_8);

  if (param_4 == 0) {

    cVar1 = '\x03';

  }

  else {

    cVar1 = (param_4 == 1) + '\x01';

  }

  if (param_5 == 0) {

    cVar2 = '\x03';

  }

  else {

    cVar2 = (param_5 == 1) + '\x01';

  }

  uVar3 = (ushort)(1 << cVar1 + 4);

  local_8 = local_8 ^ uVar3;

  FUN_006fa670(param_1,&local_8,param_8);

  local_6[0] = local_6[0] ^ (ushort)(1 << cVar2 + 4);

  FUN_006fa670(param_1,&local_8,param_8);

  local_8 = local_8 ^ uVar3;

  FUN_006fa670(param_1,&local_8,param_8);

  return;

}
