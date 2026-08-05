// =============================================================================
// FUN_00575e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00575e10
// Address:   0x00575e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00575e10 @ 0x00575e10
// Stable ID: aa_00575e10
// Embedded strings (evidence for future rename):
//   - "../logs/AutoAssaultCrash.log"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: for×5, do×2, while×2, return×1.
//  - Notable callees: CreateProcessA, FUN_00575e10, fclose, fopen, fwrite.
//  - Strings: "../logs/AutoAssaultCrash.log".
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

void FUN_00575e10(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1)



{

  char cVar1;

  FILE *_File;

  uint uVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  _STARTUPINFOA *p_Var7;

  uint32_t /* width from decompiler */ *puVar8;

  size_t _Size;

  FILE *_File_00;

  _SECURITY_ATTRIBUTES local_1a8;

  _SECURITY_ATTRIBUTES local_19c;

  char local_190 [32];

  _PROCESS_INFORMATION local_170;

  _STARTUPINFOA local_160;

  char cStack_119;

  char local_118 [4];

  char local_114 [4];

  char local_110;

  uint32_t /* width from decompiler */ local_10f;

  

  pcVar3 = "../logs/AutoAssaultCrash.log";

  pcVar6 = local_190;

  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

    *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar3;

    pcVar3 = pcVar3 + 4;

    pcVar6 = pcVar6 + 4;

  }

  *pcVar6 = *pcVar3;

  _File = fopen(local_190,"w");

  _File_00 = _File;

  uVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::size

                    (param_1);

  _Size = 1;

  pcVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::c_str

                     (param_1);

  fwrite(pcVar3,_Size,uVar2,_File_00);

  fclose(_File);

  p_Var7 = &local_160;

  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {

    p_Var7->cb = 0;

    p_Var7 = (_STARTUPINFOA *)&p_Var7->lpReserved;

  }

  local_1a8.nLength = 0xc;

  local_19c.nLength = 0xc;

  local_118[0] = s_notepad_009d37fc[0];

  local_118[1] = s_notepad_009d37fc[1];

  local_118[2] = s_notepad_009d37fc[2];

  local_118[3] = s_notepad_009d37fc[3];

  local_110 = s_notepad_009d37fc[8];

  local_114[0] = s_notepad_009d37fc[4];

  local_114[1] = s_notepad_009d37fc[5];

  local_114[2] = s_notepad_009d37fc[6];

  local_114[3] = s_notepad_009d37fc[7];

  puVar8 = &local_10f;

  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

  }

  *(uint16_t *)puVar8 = 0;

  *(uint8_t *)((int)puVar8 + 2) = 0;

  local_160.cb = 0x44;

  local_1a8.lpSecurityDescriptor = (LPVOID)0x0;

  local_1a8.bInheritHandle = 1;

  local_19c.lpSecurityDescriptor = (LPVOID)0x0;

  local_19c.bInheritHandle = 0;

  pcVar3 = local_190;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  uVar2 = (int)pcVar3 - (int)local_190;

  pcVar3 = &cStack_119;

  do {

    pcVar6 = pcVar3 + 1;

    pcVar3 = pcVar3 + 1;

  } while (*pcVar6 != '\0');

  pcVar6 = local_190;

  for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar6;

    pcVar6 = pcVar6 + 4;

    pcVar3 = pcVar3 + 4;

  }

  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *pcVar3 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    pcVar3 = pcVar3 + 1;

  }

  CreateProcessA((LPCSTR)0x0,local_118,&local_1a8,&local_19c,0,8,(LPVOID)0x0,(LPCSTR)0x0,&local_160,

                 &local_170);

  return;

}
