// =============================================================================
// FUN_0081e9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0081e9c0
// Address:   0x0081e9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0081e9c0 @ 0x0081e9c0
// Stable ID: aa_0081e9c0
// Embedded strings (evidence for future rename):
//   - "joy_custom.ini"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2, while×1.
//  - Notable callees: fgets×2, fopen×2, strtok×2, FUN_007a4480, FUN_0081e0f0, FUN_0081e9c0, fclose.
//  - Strings: "joy_custom.ini"; ");

  if ((_File == (FILE *)0x0) && (_File = fopen("; "), _File == (FILE *)0x0)) {

    FUN_007a4480(1,".
//  - Return sites: 2.

  if ((_File == (FILE *)0x0) && (_File = fopen("
//   - "), _File == (FILE *)0x0)) {

    FUN_007a4480(1,"
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

void FUN_0081e9c0(uint32_t /* width from decompiler */ param_1)



{

  FILE *_File;

  char *pcVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_410;

  uint16_t local_40c;

  uint8_t local_40a;

  uint16_t local_408;

  uint32_t /* width from decompiler */ local_406 [256];

  

  _File = fopen("joy_custom.ini","r");

  if ((_File == (FILE *)0x0) && (_File = fopen("joystick.ini","r"), _File == (FILE *)0x0)) {

    FUN_007a4480(1,"Can\'t find either joystick INI files for initing, skipping...");

    return;

  }

  local_408 = 0;

  puVar4 = local_406;

  for (iVar3 = 0xff; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  local_410 = DAT_00a77ae8;

  local_40c = DAT_00a77aec;

  local_40a = DAT_00a77aee;

  pcVar1 = fgets((char *)&local_408,0x400,_File);

  while (pcVar1 != (char *)0x0) {

    pcVar1 = strtok((char *)&local_408,(char *)&local_410);

    if (((pcVar1 != (char *)0x0) && (*pcVar1 != '#')) &&

       (pcVar2 = strtok((char *)0x0,(char *)&local_410), pcVar2 != (char *)0x0)) {

      FUN_0081e0f0(param_1,pcVar1);

    }

    pcVar1 = fgets((char *)&local_408,0x400,_File);

  }

  fclose(_File);

  return;

}
