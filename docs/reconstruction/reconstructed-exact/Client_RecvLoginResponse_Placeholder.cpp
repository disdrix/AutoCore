// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×3.
//  - Notable callees: FUN_007fdfb0×2, Client_RecvLoginResponse_Placeholder, FUN_0076c130, FUN_007fc360.
//  - Strings: "OnConnectionFailed: code:%d\n"; "Failed to login!  Please try again in a moment."; "Could not connect to the authentication server.".
//  - Return sites: 4.

// =============================================================================
// Client_RecvLoginResponse_Placeholder
// -----------------------------------------------------------------------------
// Stable ID: aa_00822070
// Address:   0x00822070  (autoassault.exe, image base 0x400000)
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

void Client_RecvLoginResponse_Placeholder(uint8_t param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b02b6;

  local_c = ExceptionList;

  if (DAT_00d1b77c == 0) {

    return;

  }

  if (DAT_00d1b780 == (int *)0x0) {

    return;

  }

  if (*DAT_00d1b780 != DAT_00d1b77c) {

    return;

  }

  ExceptionList = &local_c;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  local_4 = 0;

  FUN_0076c130("OnConnectionFailed: code:%d\n",param_1);

  piVar1 = *(int **)(DAT_00d1b77c + 0xa74);

  if (piVar1 == (int *)0x0) goto LAB_00822189;

  piVar2 = (int *)piVar1[0x164];

  if (piVar2 == (int *)0x0) {

LAB_00822170:

    if (DAT_00d1b1e4 != '\0') goto LAB_00822178;

  }

  else {

    if (DAT_00d1b1e4 == '\0') {

      *(uint8_t *)((int)piVar2 + 0x489) = 0;

      piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

      piVar2[0x8b] = *piVar3;

      piVar2 = (int *)piVar1[0x165];

      *(uint8_t *)((int)piVar2 + 0x489) = 0;

      piVar3 = (int *)(**(code **)(*piVar2 + 0x170))(3);

      piVar2[0x8b] = *piVar3;

      (**(code **)(*(int *)piVar1[0x159] + 0xd4))(1);

      (**(code **)(*(int *)piVar1[0x15b] + 0xd4))(1);

      FUN_007fdfb0(&DAT_00d1a840,"Failed to login!  Please try again in a moment.",0x4e24,1,0);

      goto LAB_00822170;

    }

LAB_00822178:

    DAT_00d1b1e4 = '\0';

  }

  (**(code **)(*piVar1 + 0x34c))();

LAB_00822189:

  FUN_007fc360();

  FUN_007fdfb0(&DAT_00d1a840,"Could not connect to the authentication server.",0xffffffff,1,0);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return;

}
