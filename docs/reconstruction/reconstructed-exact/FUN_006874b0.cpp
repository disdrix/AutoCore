// =============================================================================
// FUN_006874b0  (scaffold twin of IdvFileError_Ctor_MsgBracketErrno)
// -----------------------------------------------------------------------------
// Stable ID: aa_006874b0
// Address:   0x006874b0–0x00687624
// Wave:      W34-B 2026-07-29
// Canonical: IdvFileError_Ctor_MsgBracketErrno
// =============================================================================

// See IdvFileError_Ctor_MsgBracketErrno.cpp for named clean + full notes.

uint32_t* __thiscall FUN_006874b0(
    uint32_t* this_obj,
    uint32_t msg,
    char include_errno)
{
  uint8_t local_98[28];
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
  built = FUN_00416490(local_7c, msg, &DAT_009ead6c);
  local_4 = 2;
  built = FUN_00416410(local_98, built, part);
  local_4 = (local_4 & 0xffffff00) | 3;
  built = FUN_00416490(local_44, built, &DAT_00a62c94);
  local_4 = (local_4 & 0xffffff00) | 4;
  FUN_00685b40(this_obj, built);

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

  *this_obj = (uint32_t)&PTR_FUN_009ead64;
  ExceptionList = local_c;
  return this_obj;
}
