// =============================================================================
// FUN_0057644c
// -----------------------------------------------------------------------------
// Stable ID: aa_0057644c
// Address:   0x0057644c  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057644c @ 0x0057644c
// Stable ID: aa_0057644c
// Embedded strings (evidence for future rename):
//   - "Processor: %d Count (includes HT):%d \r\n"
//   - "Time and date: %s %s \r\n"
//   - "------------------------------------------------------------------------------------------"
//   - " \r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Count, FUN_00575e10, FUN_00575f60, FUN_0057644c, FUN_006339a0, FUN_006339b0, FUN_00633fc0, GetCurrentThread.
//  - Strings: "Processor: %d Count (includes HT):%d \r\n"; "Time and date: %s %s \r\n"; " \r\n".
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

void FUN_0057644c(void)



{

  uint16_t uVar1;

  uint8_t uVar2;

  HANDLE pvVar3;

  int unaff_EBP;

  code *unaff_ESI;

  uint8_t *puVar4;

  int iVar5;

  undefined *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0;

  GetSystemInfo((LPSYSTEM_INFO)(unaff_EBP + -0x78));

  (*unaff_ESI)(unaff_EBP + -0x478,0x400,"Processor: %d Count (includes HT):%d \r\n",

               *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x60),*(uint32_t /* width from decompiler */ *)(unaff_EBP + -100));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_EBP + -0x2c),(char *)(unaff_EBP + -0x478));

  _strtime((char *)(unaff_EBP + -0x44));

  _strdate((char *)(unaff_EBP + -0x54));

  (*unaff_ESI)(unaff_EBP + -0x478,0x400,"Time and date: %s %s \r\n",unaff_EBP + -0x44,

               unaff_EBP + -0x54);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_EBP + -0x2c),(char *)(unaff_EBP + -0x478));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_EBP + -0x2c),

             "----------------------------------------------------------------------------------------------------"

            );

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_EBP + -0x2c)," \r\n");

  uVar2 = DAT_009d3906;

  uVar1 = DAT_009d3904;

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -0x34) = DAT_009d3900;

  *(uint16_t *)(unaff_EBP + -0x30) = uVar1;

  *(uint8_t *)(unaff_EBP + -0x2e) = uVar2;

  FUN_006339b0(unaff_EBP + -0x34);

  uVar7 = *(uint32_t /* width from decompiler */ *)(unaff_EBP + 0x1c);

  puVar6 = &DAT_009d37b4;

  iVar5 = unaff_EBP + -0x2c;

  puVar4 = &DAT_00a1419b;

  pvVar3 = GetCurrentThread();

  FUN_00633fc0(pvVar3,puVar4,iVar5,puVar6,uVar7);

  FUN_006339a0();

  if (DAT_00b04800 == '\0') {

    FUN_00575e10(unaff_EBP + -0x2c);

  }

  else {

    FUN_00575f60(unaff_EBP + -0x2c,*(uint32_t /* width from decompiler */ *)(unaff_EBP + 0xc));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (unaff_EBP + -0x2c));

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return;

}
