// =============================================================================
// IdvFileError_Ctor_MsgBracketErrno
// -----------------------------------------------------------------------------
// Stable ID: aa_006874b0
// Address:   0x006874b0–0x00687624  (autoassault.exe, image base 0x400000)
// System:    SpeedTree / IDV IdvFileError
// Generated: 2026-07-29 W34-B dual seal (body ≡ 2026-07-23 raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (W34-B sealed):
 * - Product: IdvFileError::IdvFileError(string const&, bool include_errno)
 * - RTTI: .?AVIdvFileError@@ @ 0x00af5480; catchables: IdvFileError, runtime_error, exception
 * - ThrowInfo: DAT_00ac9e00; object size 0x28
 * - Message: msg + " [" + (include_errno ? strerror(*errno()) : "") + "]"
 * - Base: FUN_00685b40 (exception + intermediate vtbl PTR_FUN_009ea778 + string @ +0x0c)
 * - Installs PTR_FUN_009ead64; __thiscall RET 8; returns this
 * - Supersedes scaffold Named_CalleeOf_* plate
 */

// FUN_00685b40: base exception+string ctor (intermediate vtbl PTR_FUN_009ea778)
// FUN_00416490: operator+(string, cstr)  — W33-F
// FUN_00416410: operator+(string, string) — W33-F
// PTR_FUN_009ead64: IdvFileError vftable
// DAT_009ead6c: " ["
// DAT_00a62c94: "]"

struct IdvFileError {
  void** vtbl;       // +0
  // exception/runtime_error base fields through +0x0b
  // basic_string message @ +0x0c  (MSVC8 SSO shell ~0x1c; object total 0x28)
};

uint32_t* __thiscall IdvFileError_Ctor_MsgBracketErrno(
    uint32_t* this_obj,
    /* const std::string* */ uint32_t msg,
    char include_errno)
{
  uint8_t local_98[28];  // string temps (MSVC basic_string shells)
  uint8_t local_7c[28];
  uint8_t local_60[28];
  uint8_t local_44[28];
  uint8_t local_28[28];
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;
  bool use_empty;
  uint32_t part;
  uint32_t built;

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t*)&LAB_009a9f39;
  local_c = ExceptionList;
  use_empty = (include_errno == 0);

  if (use_empty) {
    ExceptionList = &local_c;
    part = basic_string_ctor_cstr(local_60, "");
  } else {
    ExceptionList = &local_c;
    part = basic_string_ctor_cstr(local_28, strerror(*_errno()));
  }

  local_4 = (uint32_t)use_empty;
  built = FUN_00416490(local_7c, msg, &DAT_009ead6c);       /* msg + " [" */
  local_4 = 2;
  built = FUN_00416410(local_98, built, part);               /* + errno_or_empty */
  local_4 = (local_4 & 0xffffff00) | 3;
  built = FUN_00416490(local_44, built, &DAT_00a62c94);      /* + "]" */
  local_4 = (local_4 & 0xffffff00) | 4;
  FUN_00685b40(this_obj, built);                             /* base + embed string */

  /* destroy temps in reverse construction order (EH states 10..6) */
  local_4 = (local_4 & 0xffffff00) | 10;
  basic_string_dtor(local_44);
  local_4 = 9;
  basic_string_dtor(local_98);
  local_4 = (local_4 & 0xffffff00) | 8;
  basic_string_dtor(local_7c);
  local_4 = (local_4 & 0xffffff00) | 7;
  if (use_empty) {
    basic_string_dtor(local_60);
  }
  local_4 = (local_4 & 0xffffff00) | 6;
  if (!use_empty) {
    basic_string_dtor(local_28);
  }

  *this_obj = (uint32_t)&PTR_FUN_009ead64;                   /* IdvFileError vtbl */
  ExceptionList = local_c;
  return this_obj;
}
