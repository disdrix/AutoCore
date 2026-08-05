// =============================================================================
// Std_LengthError_CtorFromString
// -----------------------------------------------------------------------------
// Stable ID: aa_00401a40
// Address:   0x00401a40–0x00401a90  (autoassault.exe, image base 0x400000)
// System:    MSVC STL / std::length_error
// Generated: 2026-07-29 W20-L dual seal (body ≡ 2026-07-23 raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (W20-L sealed):
 * - Product: std::length_error::length_error(std::string const&)
 * - RTTI: .?AVlength_error@std@@ @ 0x00af8bf0
 * - Base: FUN_00401aa0 = logic_error(string) [vtbl PTR_FUN_009c7628]
 * - Installs length_error vtbl PTR_FUN_009c7634; __thiscall RET 4
 * - ThrowInfo DAT_00acc388 (object size 0x28); used by vector/map "too long" helpers
 * - Supersedes false Auth-seed name Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40
 */

// FUN_00401aa0: std::logic_error::logic_error(std::string const&)
// PTR_FUN_009c7634: length_error vftable

uint32_t * __thiscall Std_LengthError_CtorFromString(
    uint32_t *this_obj,
    /* const std::string* */ uint32_t msg)
{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009bc828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401aa0(msg);                 /* logic_error(msg) */
  *this_obj = (uint32_t)&PTR_FUN_009c7634;
  ExceptionList = local_c;
  return this_obj;
}
