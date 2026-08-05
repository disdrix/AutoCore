// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, goto×1, while×1, return×1.
//  - Notable callees: CVOGTerrain_ApplyTilesetTextures, indices, m_ucTileSet, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp"; "Invalid tileset type! defaulting to Universal".
//  - Return sites: 1.

// =============================================================================
// CVOGTerrain_ApplyTilesetTextures
// -----------------------------------------------------------------------------
// Stable ID: aa_004a86f0
// Address:   0x004a86f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* CVOGTerrain::ApplyTilesetTextures [VOGTerrain.cpp]. Maps m_ucTileSet (this+0x1c) -> 8 terrain

   texture layer indices (this+0x344..+0x360) via per-tileset table at DAT_00aefb60/DAT_00aefb88

   (stride 0x15 dwords). Terrain is rendered with 8 blended texture layers chosen by tileset type.

   Defaults to Universal on invalid tileset. */



void __fastcall CVOGTerrain_ApplyTilesetTextures(int param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  iVar2 = 0;

  puVar1 = &DAT_00aefb88;

  do {

    if (*puVar1 == (uint)*(byte *)(param_1 + 0x1c)) {

      iVar3 = iVar2;

      if (iVar2 != 0) goto LAB_004a8733;

      break;

    }

    puVar1 = puVar1 + 0x15;

    iVar2 = iVar2 + 1;

  } while ((int)puVar1 < 0xaf06b0);

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGTerrain.cpp",0x288,3,

                 "Invalid tileset type! defaulting to Universal");

  iVar2 = iVar3;

LAB_004a8733:

  iVar3 = (&DAT_00aefb9c)[iVar2 * 0x15];

  *(int *)(param_1 + 0x364) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x344) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefba0)[iVar2 * 0x15];

  *(int *)(param_1 + 0x368) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x348) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefba4)[iVar2 * 0x15];

  *(int *)(param_1 + 0x36c) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34c) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefba8)[iVar2 * 0x15];

  *(int *)(param_1 + 0x370) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x350) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefbac)[iVar2 * 0x15];

  *(int *)(param_1 + 0x374) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x354) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefbb0)[iVar2 * 0x15];

  *(int *)(param_1 + 0x378) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x358) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefbb4)[iVar2 * 0x15];

  *(int *)(param_1 + 0x37c) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x35c) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  iVar3 = (&DAT_00aefbb8)[iVar2 * 0x15];

  *(int *)(param_1 + 0x380) = iVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x360) = *(uint32_t /* width from decompiler */ *)(&DAT_00aefb60 + iVar3 * 4);

  return;

}
