// =============================================================================
// Named_Bzip_memory_error
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ad70
// Address:   0x0071ad70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Bzip_memory_error @ 0x0071ad70
// Stable ID: aa_0071ad70
// Embedded strings (evidence for future rename):
//   - "Bzip output full.\n"
//   - "Bzip memory error.\n"
//   - "Bzip parm error.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×6, if×4, for×2, switch×1.
//  - Notable callees: printf×3, FUN_0047f730, FUN_004832d0, Named_Bzip_memory_error.
//  - Strings: "Bzip output full.\n"; "Bzip memory error.\n"; "Bzip parm error.\n".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Bzip memory error.
"
 * Domain alias of FUN_0071ad70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall

Named_Bzip_memory_error(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint *param_4)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint uVar2;

  uint unaff_EBX;

  

  switch(param_3) {

  case 0:

    for (uVar2 = unaff_EBX >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *param_2 = *in_EAX;

      in_EAX = in_EAX + 1;

      param_2 = param_2 + 1;

    }

    for (uVar2 = unaff_EBX & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)in_EAX;

      in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

    *param_4 = unaff_EBX;

    break;

  case 1:

    iVar1 = FUN_0047f730(param_4,0xffffffff);

    if (iVar1 != 0) {

      return 0xffffffff;

    }

    break;

  case 2:

    iVar1 = FUN_004832d0(param_2,param_4,in_EAX,unaff_EBX);

    if (iVar1 == -8) {

      printf("Bzip output full.\n");

      return 0xffffffff;

    }

    if (iVar1 == -3) {

      printf("Bzip memory error.\n");

      return 0xffffffff;

    }

    if (iVar1 == -2) {

      printf("Bzip parm error.\n");

      return 0xffffffff;

    }

    break;

  case 3:

    return 0xffffffff;

  }

  return 0;

}
