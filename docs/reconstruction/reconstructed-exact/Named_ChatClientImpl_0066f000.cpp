// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: FUN_0067b110×2, FUN_0067bdf0×2, FUN_0066f000, FUN_0067b070, FUN_0067b260, FUN_0067bac0, FUN_0067bdc0, FUN_0076cec0.
//  - Strings: "Unable to bind for peer connection.".
//  - Return sites: 2.

// =============================================================================
// Named_ChatClientImpl_0066f000
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f000
// Address:   0x0066f000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_0066f000(int param_1)



{

  SOCKET *pSVar1;

  SOCKET SVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  sockaddr local_13c;

  uint8_t local_12c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_128 [28];

  char local_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8f37;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pSVar1 = operator_new(4);

  if (pSVar1 == (SOCKET *)0x0) {

    pSVar1 = (SOCKET *)0x0;

  }

  else {

    *pSVar1 = 0xffffffff;

  }

  *(SOCKET **)(param_1 + 0x20c) = pSVar1;

  if (*pSVar1 == 0xffffffff) {

    SVar2 = socket(2,2,0);

    *pSVar1 = SVar2;

  }

  FUN_0067bac0(1);

  FUN_0067bdc0(0xffff,4,1);

  FUN_0067b070();

  local_4 = 0;

  gethostname(local_10c,0xff);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_128,local_10c);

  local_4._0_1_ = 1;

  FUN_0067b260(local_128,0x2289,&local_13c);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_128);

  iVar3 = bind(**(SOCKET **)(param_1 + 0x20c),&local_13c,0x10);

  if ((int)-(uint)(iVar3 != 0) < 0) {

    uVar4 = FUN_0076cec0(local_12c,"Unable to bind for peer connection.");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0x210,3,uVar4);

    local_4 = 0xffffffff;

    FUN_0067b110();

    ExceptionList = local_c;

    return 0xffffffff;

  }

  FUN_0067bdf0(0xffff,0x1002,0x10000);

  FUN_0067bdf0(0xffff,0x1001,0x10000);

  local_4 = 0xffffffff;

  FUN_0067b110();

  ExceptionList = local_c;

  return 0;

}
