// =============================================================================
// FUN_007b4590
// -----------------------------------------------------------------------------
// Stable ID: aa_007b4590
// Address:   0x007b4590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b4590 @ 0x007b4590
// Stable ID: aa_007b4590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00758460×4, CONCAT13, FUN_007b4590.
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

void __fastcall FUN_007b4590(int *param_1)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  int unaff_EBX;

  uint unaff_EDI;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_8 [8];

  

  (**(code **)(*param_1 + 0x140))(local_8,1);

  iVar2 = param_1[0x79];

  iVar3 = (**(code **)(*param_1 + 0x164))(0);

  bVar1 = *(byte *)(iVar3 + 3);

  param_1[0x1a] = param_1[0x1a] + 1;

  uVar4 = CONCAT13((char)(((uint)bVar1 * (unaff_EDI >> 0x18)) / 0xff),(int3)unaff_EDI);

  iVar3 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar3;

  if (param_1[0x1c] < iVar3) {

    param_1[0x1c] = iVar3;

  }

  FUN_00758460(0,0,(float)param_1[0x78],(float)unaff_EBX,&DAT_00d1ec78,0,uVar4,1,0,0,&DAT_00d1ecac);

  FUN_00758460((float)(iVar2 - param_1[0x78]),0,(float)iVar2,(float)unaff_EBX,&DAT_00d1ec78,0,uVar4,

               1,0,0,&DAT_00d1ecac);

  iVar3 = param_1[0x78];

  FUN_00758460((float)iVar3,0,(float)(iVar2 - iVar3),(float)iVar3,&DAT_00d1ec78,0,uVar4,1,0,0,

               &DAT_00d1ecac);

  iVar3 = param_1[0x78];

  FUN_00758460((float)iVar3,(float)(unaff_EBX - iVar3),(float)(iVar2 - iVar3),(float)unaff_EBX,

               &DAT_00d1ec78,0,uVar4,1,0,0,&DAT_00d1ecac);

  return;

}
