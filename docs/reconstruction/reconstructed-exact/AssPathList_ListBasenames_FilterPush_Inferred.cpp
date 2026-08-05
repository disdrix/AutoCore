// =============================================================================
// AssPathList_ListBasenames_FilterPush_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009698a0
// Address:   0x009698a0–0x00969a4c  (autoassault.exe, image base 0x400000)
// System:    asset path-list enumeration / filter collect
// Generated: 2026-07-29 W34-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (W34-B sealed):
 * - stdcall RET 0xC; three stack formals + EDI out dword-vec shell*
 * - For each path string in path_list (stride 0x1c): path + "*.*" then
 *   FUN_0076b3f0 (Fs_ListDirBasenames_Inferred) into local string vec
 * - For each basename: FUN_00989e00(ECX=0x00d1eac8) → handle; classifier
 *   vtbl[+0x10](handle, &class_id); if type_filter==0 || class_id==type_filter
 *   push handle to EDI vec (FUN_00436ef0 if capacity else FUN_0043bfb0 grow)
 * - Returns 0
 * - Wrapper 0x00996aa0: EDI=out; path_list=*DAT_00d1f1fc; then this
 * - Decompiler unaff_EDI is intentional register formal (not true unaff)
 * - operator_delete false-noreturn: loop continues after basename-vec free
 */

// StringVecShell: +4 begin, +8 end, stride 0x1c (basic_string elements)
// PtrVecShell:    +4 begin, +8 end, +0xc cap, stride 4 (dword elements)
// DAT_00aa1d38: "*.*"
// DAT_00d1eac8: this for FUN_00989e00 asset-name resolve

uint32_t __stdcall AssPathList_ListBasenames_FilterPush_Inferred(
    /* StringVecShell* */ uint32_t path_list,
    /* classifier* */     uint32_t* classifier,
    int type_filter
    /* EDI: PtrVecShell* out_ids */)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;
  uint32_t handle;           // local_44
  uint32_t cur_path;         // local_40
  int class_id;              // local_3c
  uint8_t list_scratch[4];   // local_38 (out arg shell for list)
  uint8_t* names_begin;      // local_34
  uint8_t* names_end;        // local_30
  uint32_t names_cap;        // local_2c
  uint8_t pattern[0x1c];     // local_28 basic_string (SSO layout)
  // ... SSO buffer through local_10

  // NOTE: EDI is live register formal set by caller / wrapper 0x00996aa0.
  // Pseudocode uses out_ids for clarity; retail passes it in EDI.

  local_4 = 0xffffffff;
  puStack_8 = (uint8_t*)&LAB_009afb56;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  cur_path = *(uint32_t*)(path_list + 4);
  if (cur_path != *(uint32_t*)(path_list + 8)) {
    do {
      FUN_00416490(pattern, cur_path, &DAT_00aa1d38);  /* path + "*.*" */
      names_begin = 0;
      names_end = 0;
      names_cap = 0;
      local_4 = 1;

      {
        const char* cstr = basic_string_cstr(pattern); /* SSO vs heap */
        FUN_0076b3f0(cstr, &names_begin);              /* out vec shell @ local_34 */
      }

      if (names_begin != names_end) {
        uint8_t* el = names_begin + 4; /* walk strings; decompiler +4 SSO entry */
        do {
          const char* base = basic_string_cstr(el - 4);
          FUN_00989e00(/*this=*/0x00d1eac8, &handle, base);
          (*(void (**)(uint32_t*, int*))(*(uint32_t*)*classifier + 0x10))(
              &handle, &class_id);

          if (type_filter == 0 || class_id == type_filter) {
            /* EDI out vec capacity check: size vs capacity (>>2) */
            uint32_t begin = *(uint32_t*)(out_ids + 4);
            uint32_t end = *(uint32_t*)(out_ids + 8);
            uint32_t cap = *(uint32_t*)(out_ids + 0xc);
            if (begin == 0 ||
                (uint32_t)((cap - begin) >> 2) <= (uint32_t)((end - begin) >> 2)) {
              FUN_0043bfb0(out_ids, end, 1, &handle);   /* grow + insert */
            } else {
              /* FUN_00436ef0(count=1): EAX=end, EDX=&handle; write *end++ */
              FUN_00436ef0(/*count*/1, &handle /*, EAX=end*/);
              *(uint32_t*)(out_ids + 8) = end + 4;
            }
          }

          el += 0x1c;
        } while (el - 4 != names_end);
      }

      /* destroy basename string vec (stride 0x1c) + operator_delete(names_begin) */
      local_4 = local_4 & 0xffffff00;
      if (names_begin != 0) {
        for (uint8_t* p = names_begin; p != names_end; p += 0x1c) {
          basic_string_dtor(p);
        }
        operator_delete(names_begin); /* continues — not true noreturn */
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
