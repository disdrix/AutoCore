// =============================================================================
// Named_DIK_NUMPADEQUALS_007f6080
// -----------------------------------------------------------------------------
// Stable ID: aa_007f6080
// Address:   0x007f6080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_DIK_NUMPADEQUALS_007f6080 @ 0x007f6080
// Stable ID: aa_007f6080
// Embedded strings (evidence for future rename):
//   - "NUMPAD0"
//   - "NUMPAD1"
//   - "NUMPAD2"
//   - "NUMPAD3"
//   - "NUMPAD4"
//   - "NUMPAD5"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~1702 non-empty decompiler lines.
//  - Control keywords: if×239, return×123, do×117, while×117, switch×2, goto×2.
//  - Notable callees: _strnicmp×4, FUN_007f6080, atoi.
//  - Strings: "F10"; "F11"; "F12"; "NUMPAD0".
//  - Return sites: 123.

/*
 * Behavioral notes:
 * String-driven rename evidence: "DIK_NUMPADEQUALS"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Named_DIK_NUMPADEQUALS_007f6080(void)



{

  char *in_EAX;

  uint uVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  bool bVar5;

  

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "A";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1e;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "B";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x30;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "C";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2e;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "D";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x20;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "E";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x12;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x21;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "G";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x22;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "H";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x23;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "I";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x17;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "J";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x24;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "K";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x25;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "L";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x26;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "M";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x32;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "N";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x31;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "O";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x18;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "P";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x19;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "Q";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x10;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "R";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x13;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "S";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1f;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "T";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x14;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "U";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x16;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "V";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2f;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "W";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x11;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "X";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2d;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "Y";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x15;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "Z";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2c;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "0";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xb;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "1";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 2;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "2";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 3;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "3";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 4;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "4";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 5;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "5";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 6;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "6";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 7;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "7";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 8;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "8";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 9;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "9";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 10;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F1";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3b;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F2";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3c;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F3";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3d;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F4";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3e;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F5";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3f;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F6";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x40;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F7";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x41;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F8";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x42;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F9";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x43;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F10";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x44;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F11";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x57;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "F12";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x58;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD0";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x52;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD1";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4f;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD2";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x50;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD3";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x51;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD4";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4b;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD5";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4c;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD6";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4d;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD7";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x47;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD8";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x48;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPAD9";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x49;

  }

  iVar2 = 0xc;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMPADENTER";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x9c;

  }

  iVar2 = 0x11;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "DIK_NUMPADEQUALS";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x8d;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "PERIOD";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x34;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MULTIPLY";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x37;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SUBTRACT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4a;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "ADD";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x4e;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "DECIMAL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x53;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "DIVIDE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xb5;

  }

  iVar2 = 0xc;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "PRINTSCREEN";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xb7;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SLASH";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x35;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "GRAVE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x29;

  }

  iVar2 = 10;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "BACKSLASH";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2b;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SPACE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x39;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SHIFT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2a;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "LSHIFT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x2a;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RSHIFT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x36;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "CONTROL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1d;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "LCONTROL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1d;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RCONTROL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x9d;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NEXT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd1;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "PGDOWN";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd1;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "PRIOR";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xc9;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "PGUP";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xc9;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "HOME";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 199;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "END";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xcf;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "INSERT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd2;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = " DELETE ";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd3;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "DELETE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd3;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "ALT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x38;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "LALT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x38;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RALT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xb8;

  }

  iVar2 = 4;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "TAB";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MINUS";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xc;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "EQUALS";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "ESCAPE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 1;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "BACK";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xe;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "LBRACKET";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1a;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "[";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1a;

  }

  iVar2 = 9;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RBRACKET";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1b;

  }

  iVar2 = 2;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "]";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1b;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RETURN";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x1c;

  }

  iVar2 = 10;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SEMICOLON";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x27;

  }

  iVar2 = 0xb;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "APOSTROPHE";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x28;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "COMMA";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x33;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "CAPITAL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x3a;

  }

  iVar2 = 8;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "NUMLOCK";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x45;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "SCROLL";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0x46;

  }

  iVar2 = 3;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "UP";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 200;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "LEFT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xcb;

  }

  iVar2 = 6;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "RIGHT";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xcd;

  }

  iVar2 = 5;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "DOWN";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xd0;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE1";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf00;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE2";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf01;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE3";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf02;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE4";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf03;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE5";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf04;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE6";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf05;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE7";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf06;

  }

  iVar2 = 7;

  bVar5 = true;

  pcVar3 = in_EAX;

  pcVar4 = "MOUSE8";

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *pcVar3 == *pcVar4;

    pcVar3 = pcVar3 + 1;

    pcVar4 = pcVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    return 0xf07;

  }

  uVar1 = _strnicmp(in_EAX,"JOY_",4);

  if (uVar1 != 0) {

LAB_007f6d2a:

    return uVar1 & 0xffff0000;

  }

  pcVar3 = in_EAX + 4;

  iVar2 = _strnicmp(pcVar3,"BUTTON",6);

  if (iVar2 == 0) {

    uVar1 = atoi(in_EAX + 10);

    return uVar1 | 0xf000;

  }

  iVar2 = _strnicmp(pcVar3,"AXIS",4);

  if (iVar2 != 0) {

    uVar1 = _strnicmp(pcVar3,"POV",3);

    if (uVar1 == 0) {

      uVar1 = (int)in_EAX[7] - 0x31;

      switch(in_EAX[9]) {

      case 'E':

        return uVar1 | 0xf210;

      case 'S':

        return uVar1 | 0xf220;

      case 'W':

        uVar1 = uVar1 | 0x40;

      }

      return uVar1 | 0xf200;

    }

    goto LAB_007f6d2a;

  }

  uVar1 = 0;

  switch(in_EAX[8]) {

  case 'F':

    uVar1 = (ushort)(short)in_EAX[0xd] - 0x58 | 0x40;

    bVar5 = in_EAX[0xe] == '-';

    break;

  default:

    goto switchD_007f6c90_caseD_47;

  case 'R':

    uVar1 = (ushort)(short)in_EAX[0xb] - 0x58 | 0x10;

    bVar5 = in_EAX[0xc] == '-';

    break;

  case 'S':

    uVar1 = (ushort)(short)in_EAX[0xe] - 0x31 | 0x20;

    bVar5 = in_EAX[0xf] == '-';

    break;

  case 'X':

  case 'Y':

  case 'Z':

    uVar1 = (ushort)(short)in_EAX[8] - 0x58;

    bVar5 = in_EAX[9] == '-';

  }

  if (bVar5) {

    uVar1 = uVar1 | 0x80;

  }

switchD_007f6c90_caseD_47:

  return uVar1 | 0xf100;

}
