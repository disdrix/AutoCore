// =============================================================================
// FUN_00969a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00969a50
// Address:   0x00969a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969a50 @ 0x00969a50
// Stable ID: aa_00969a50
// Embedded strings (evidence for future rename):
//   - "Diffuse"
//   - "Ambient"
//   - "Emissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: strstr×3, FUN_00969a50.
//  - Strings: "Diffuse"; "Ambient"; "Emissive".
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

void __thiscall

FUN_00969a50(int param_1,uint32_t /* width from decompiler */ param_2,float param_3,float param_4,float param_5)



{

  int *piVar1;

  char *pcVar2;

  uint8_t local_2c [4];

  char *local_28;

  

  if (*(int *)(*(int *)(param_1 + 4) + 0xc) != 0) {

    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);

    (**(code **)(*piVar1 + 0x10))(piVar1,param_2,local_2c);

  }

  if ((local_28 != (char *)0x0) &&

     (((pcVar2 = strstr(local_28,"Diffuse"), pcVar2 != (char *)0x0 ||

       (pcVar2 = strstr(local_28,"Ambient"), pcVar2 != (char *)0x0)) ||

      (pcVar2 = strstr(local_28,"Emissive"), pcVar2 != (char *)0x0)))) {

    param_3 = DAT_00afa2f8 * param_3;

    param_4 = DAT_00afa2f8 * param_4;

    param_5 = DAT_00afa2f8 * param_5;

  }

  if (*(int *)(param_1 + 4) != 0) {

    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))(piVar1,param_2,&param_3,0xffffffff);

  }

  return;

}
