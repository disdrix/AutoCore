// =============================================================================
// Named_CalleeOf_Named_NDRenderEngine_0079dbc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079dbc0
// Callee of Named_NDRenderEngine
// Address:   0x0079dbc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_NDRenderEngine: presentation/world helper. Evidence string: "D3DXSaveSurfaceToFile 9.0c doesn\'t support TGA -- saving as bitmap.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "D3DXSaveSurfaceToFile 9.0c doesn\'t support TGA -- saving as bitmap."
//   - "Unknown extension -- saving as bitmap.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×8, return×8.
//  - Notable callees: _strnicmp×7, OutputDebugStringA×2, FUN_0079dbc0, strrchr.
//  - Strings: "jpg"; "png"; "dib"; "hdr".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_NDRenderEngine
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_NDRenderEngine_0079dbc0(void)



{

  char *in_EAX;

  char *pcVar1;

  int iVar2;

  

  pcVar1 = strrchr(in_EAX,0x2e);

  if (pcVar1 == (char *)0x0) {

    return 0;

  }

  pcVar1 = pcVar1 + 1;

  iVar2 = _strnicmp(pcVar1,"jpg",0x104);

  if (iVar2 == 0) {

    return 1;

  }

  iVar2 = _strnicmp(pcVar1,"png",0x104);

  if (iVar2 == 0) {

    return 3;

  }

  iVar2 = _strnicmp(pcVar1,"dib",0x104);

  if (iVar2 == 0) {

    return 6;

  }

  iVar2 = _strnicmp(pcVar1,"hdr",0x104);

  if (iVar2 == 0) {

    return 7;

  }

  iVar2 = _strnicmp(pcVar1,"pfm",0x104);

  if (iVar2 == 0) {

    return 8;

  }

  iVar2 = _strnicmp(pcVar1,"tga",0x104);

  if (iVar2 == 0) {

    OutputDebugStringA("D3DXSaveSurfaceToFile 9.0c doesn\'t support TGA -- saving as bitmap.");

    return 0;

  }

  iVar2 = _strnicmp(pcVar1,"bmp",0x104);

  if (iVar2 != 0) {

    OutputDebugStringA("Unknown extension -- saving as bitmap.\n");

  }

  return 0;

}
