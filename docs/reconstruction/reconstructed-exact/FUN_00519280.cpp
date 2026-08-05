// =============================================================================
// FUN_00519280
// -----------------------------------------------------------------------------
// Stable ID: aa_00519280
// Address:   0x00519280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00519280 @ 0x00519280
// Stable ID: aa_00519280
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "MatAmbient"
//   - "MatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×5, while×1, return×1.
//  - Notable callees: FUN_0051d4a0×3, FUN_00608720×3, FUN_0096f840×3, FUN_009700f0×3, FUN_00519280, FUN_0051def0.
//  - Strings: "MatDiffuse"; "MatAmbient"; "MatEmissive".
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

void FUN_00519280(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = g_flOne;

  FUN_0051def0(0,0,0,0,g_flOne);

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = g_flOne;

  iVar2 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0xc0) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2;

    }

    if (iVar1 <= iVar2) break;

    FUN_0096f840("MatDiffuse",&local_10);

    iVar1 = *(int *)(param_2 + 4);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(param_2 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(param_2 + 8) - iVar1 >> 4)))

    {

      FUN_0051d4a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,&local_10);

    }

    else {

      iVar1 = *(int *)(param_2 + 8);

      FUN_00608720(iVar1,1,&local_10,param_2,param_1);

      *(int *)(param_2 + 8) = iVar1 + 0x10;

    }

    FUN_0096f840("MatAmbient",&local_10);

    iVar1 = *(int *)(param_2 + 4);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(param_2 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(param_2 + 8) - iVar1 >> 4)))

    {

      FUN_0051d4a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,&local_10);

    }

    else {

      iVar1 = *(int *)(param_2 + 8);

      FUN_00608720(iVar1,1,&local_10,param_2,param_1);

      *(int *)(param_2 + 8) = iVar1 + 0x10;

    }

    FUN_0096f840("MatEmissive",&local_10);

    iVar1 = *(int *)(param_2 + 4);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(param_2 + 0xc) - iVar1 >> 4) <= (uint)(*(int *)(param_2 + 8) - iVar1 >> 4)))

    {

      FUN_0051d4a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,&local_10);

    }

    else {

      iVar1 = *(int *)(param_2 + 8);

      FUN_00608720(iVar1,1,&local_10,param_2,param_1);

      *(int *)(param_2 + 8) = iVar1 + 0x10;

    }

    FUN_009700f0("MatDiffuse",&stack0x0000000c);

    FUN_009700f0("MatAmbient",&stack0x0000000c);

    FUN_009700f0("MatEmissive",&stack0x0000000c);

    iVar2 = iVar2 + 1;

  }

  return;

}
