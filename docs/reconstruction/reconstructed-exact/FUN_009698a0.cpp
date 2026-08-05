// =============================================================================
// FUN_009698a0  (scaffold twin of AssPathList_ListBasenames_FilterPush_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009698a0
// Address:   0x009698a0–0x00969a4c
// Wave:      W34-B 2026-07-29
// Canonical: AssPathList_ListBasenames_FilterPush_Inferred
// =============================================================================

// See AssPathList_ListBasenames_FilterPush_Inferred.cpp for named clean + full notes.
// EDI is an implicit register formal (out dword-vec shell*).

uint32_t __stdcall FUN_009698a0(
    uint32_t path_list,
    uint32_t* classifier,
    int type_filter)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;
  uint32_t handle;
  uint32_t cur_path;
  int class_id;
  uint8_t* names_begin;
  uint8_t* names_end;
  uint32_t names_cap;
  uint8_t pattern[0x1c];

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t*)&LAB_009afb56;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  cur_path = *(uint32_t*)(path_list + 4);
  if (cur_path != *(uint32_t*)(path_list + 8)) {
    do {
      FUN_00416490(pattern, cur_path, &DAT_00aa1d38);
      names_begin = 0;
      names_end = 0;
      names_cap = 0;
      local_4 = 1;

      {
        const char* cstr = basic_string_cstr(pattern);
        FUN_0076b3f0(cstr, &names_begin);
      }

      if (names_begin != names_end) {
        uint8_t* el = names_begin + 4;
        do {
          const char* base = basic_string_cstr(el - 4);
          FUN_00989e00(/*this=*/0x00d1eac8, &handle, base);
          (*(void (**)(uint32_t*, int*))(*(uint32_t*)*classifier + 0x10))(
              &handle, &class_id);

          if (type_filter == 0 || class_id == type_filter) {
            /* EDI = out PtrVecShell*; capacity gate then push */
            uint32_t begin = *(uint32_t*)(EDI + 4);
            uint32_t end = *(uint32_t*)(EDI + 8);
            uint32_t cap = *(uint32_t*)(EDI + 0xc);
            if (begin == 0 ||
                (uint32_t)((cap - begin) >> 2) <= (uint32_t)((end - begin) >> 2)) {
              FUN_0043bfb0(EDI, end, 1, &handle);
            } else {
              FUN_00436ef0(/*count*/1, &handle /*, EAX=end*/);
              *(uint32_t*)(EDI + 8) = end + 4;
            }
          }

          el += 0x1c;
        } while (el - 4 != names_end);
      }

      local_4 = local_4 & 0xffffff00;
      if (names_begin != 0) {
        for (uint8_t* p = names_begin; p != names_end; p += 0x1c) {
          basic_string_dtor(p);
        }
        operator_delete(names_begin);
      }
      names_begin = 0;
      names_end = 0;
      names_cap = 0;
      local_4 = 0xffffffff;
      basic_string_dtor(pattern);
      cur_path += 0x1c;
    } while (cur_path != *(uint32_t*)(path_list + 8));
  }

  ExceptionList = local_c;
  return 0;
}
