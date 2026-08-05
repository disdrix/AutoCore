// =============================================================================
// FUN_00401a40  (scaffold alias — prefer Std_LengthError_CtorFromString.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401a40
// Address:   0x00401a40  (autoassault.exe, image base 0x400000)
// System:    MSVC STL / std::length_error
// Generated: 2026-07-23 scaffold; 2026-07-29 W20-L rename note
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold unit for FUN_00401a40 @ 0x00401a40
// Canonical name (W20-L): Std_LengthError_CtorFromString
// See: reconstructed-exact/Std_LengthError_CtorFromString.cpp

/*
 * Behavioral notes:
 * - W20-L: std::length_error ctor from string; RTTI sealed.
 * - Live decompile ≡ 2026-07-23 raw (no CF delta).
 */

uint32_t * __thiscall FUN_00401a40(uint32_t *param_1, uint32_t param_2)
{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009bc828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401aa0(param_2);
  *param_1 = (uint32_t)&PTR_FUN_009c7634;
  ExceptionList = local_c;
  return param_1;
}
