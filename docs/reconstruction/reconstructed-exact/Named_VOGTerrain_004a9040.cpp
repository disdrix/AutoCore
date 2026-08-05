// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_004a9040, sprintf, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp"; "Invalid tileset type! defaulting to Universal".
//  - Return sites: 1.

// =============================================================================
// Named_VOGTerrain_004a9040
// -----------------------------------------------------------------------------
// Stable ID: aa_004a9040
// Address:   0x004a9040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGTerrain"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOGTerrain_004a9040(byte param_1,char *param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  iVar2 = 0;

  puVar1 = &DAT_00aefb88;

  do {

    if (*puVar1 == (uint)param_1) {

      iVar3 = iVar2;

      if (iVar2 != 0) goto LAB_004a9082;

      break;

    }

    puVar1 = puVar1 + 0x15;

    iVar2 = iVar2 + 1;

  } while ((int)puVar1 < 0xaf06b0);

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0x86e,3,

                 "Invalid tileset type! defaulting to Universal");

  iVar2 = iVar3;

LAB_004a9082:

  sprintf(param_2,(&PTR_s_tile2_mnt_ground_01_dds_00aefb94)[iVar2 * 0x15]);

  return;

}
