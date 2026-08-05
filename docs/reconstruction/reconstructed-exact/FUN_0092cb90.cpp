// =============================================================================
// FUN_0092cb90
// -----------------------------------------------------------------------------
// Stable ID: aa_0092cb90
// Address:   0x0092cb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092cb90 @ 0x0092cb90
// Stable ID: aa_0092cb90
// Embedded strings (evidence for future rename):
//   - "playreview.html"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: fprintf×2, FUN_0092cb90, ShellExecuteA, _chmod, fclose, fopen, remove.
//  - Strings: "playreview.html"; ");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"; ");

    fprintf(_File,"; "Refresh\"\nCONTENT=\"0; URL=%s\">".
//  - Return sites: 1.

  if (_File != (FILE *)0x0) {

    fprintf(_File,"
//   - ");

    fprintf(_File,"
//   - "Refresh\"\nCONTENT=\"0; URL=%s\">"
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_0092cb90(uint32_t /* width from decompiler */ param_1)



{

  FILE *_File;

  

  _chmod("playreview.html",0x80);

  remove("playreview.html");

  _File = fopen("playreview.html","wt");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"<!-- saved from url=(0026)http://www.autoassault.com -->\n");

    fprintf(_File,"<META HTTP-EQUIV=\"Refresh\"\nCONTENT=\"0; URL=%s\">",param_1);

    fclose(_File);

    ShellExecuteA((HWND)0x0,(LPCSTR)0x0,"playreview.html",(LPCSTR)0x0,(LPCSTR)0x0,1);

  }

  return;

}
