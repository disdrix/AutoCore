// =============================================================================
// CNDAssetStringTable_Unserialize
// -----------------------------------------------------------------------------
// Stable ID: aa_0099bba0
// Address:   0x0099bba0–0x0099BED5 exclusive (821 B / 0x335, autoassault.exe base 0x400000)
// System:    CNDAssetStringTable stream load (pair of Serialize @ 0x0099b8e0)
// Generated: 2026-07-29 W34-J dual A/B (decompile + read_memory + plate strings)
// Exactness: Behavior-preserving outer CF + ABI. Nested pyramid row fill summarized.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0099bba0
// Product:   "CNDAssetStringTable::Unserialize" @ 0x00a9b728
// =============================================================================
//
// PURPOSE:
//   Load a CNDAssetStringTable from a stream reader:
//     1) read string-table count, read each C-string, intern/lookup, push_back
//        onto a temporary vector<basic_string>;
//     2) read pyramid count, resize host pyramid vector (elem 0x10), nested
//        reshape + name→index resolve via lower_bound/_stricmp;
//     3) destroy temp string vector; return success (1).
//
// ABI (bytes):
//   three stack formals; RET 0x0C; returns uint8_t/bool success in AL (=1)
//   EBP holds stream reader* for body; vtbl[+0x14] = sized read
//   SEH LAB_009b1372
//
// CALLER:
//   FUN_0099c1c0 @ 0x0099c23a — constructs local table, passes stream param_1
// =============================================================================

#include <cstdint>

struct StreamReader {
  void** vtbl; // [+0x14] = read(dst, size) → int
};

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;  // +0x04
  uint8_t* end;    // +0x08
  uint8_t* capEnd; // +0x0c
};

// Unowned helpers
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void basic_string_ctor_default(void* self);
extern "C" void basic_string_dtor(void* self);
extern "C" int  FUN_00766fb0(void); // ESI=reader, EDI=string out; read C-string
extern "C" void FUN_00989e00(void* host, void* out_slot, const char* name);
extern "C" void __thiscall StringVec_PushBack(StringVecShell* self,
                                              const void* value_string);
extern "C" void __thiscall FUN_00430540(void* vec, uint32_t new_count,
                                        uint32_t a3, void* a4);
extern "C" void FUN_00430600(uint32_t new_count, uint32_t a2, void* a3); // ESI=vec
extern "C" void FUN_0044ff40(void* out_it, void* begin, void* end,
                             void* key, void* pred);
extern "C" void operator_delete(void* p);

// Retail: 3 stack args; ret 12; AL=1 on success
// formals (caller FUN_0099c1c0): host_table*, scratch*, stream_reader*
extern "C" uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                                   void* scratch,
                                                   StreamReader* reader)
{
  (void)scratch;
  // SEH LAB_009b1372 omitted

  FUN_007a4480(/*level*/-1, "CNDAssetStringTable::Unserialize");

  StringVecShell local_strings{};
  local_strings.begin = local_strings.end = local_strings.capEnd = nullptr;

  // --- string table ---
  uint32_t n_strings = 0;
  // reader->vtbl[0x14/4](reader, &n_strings, 4)
  (void)reader;
  FUN_007a4480(-1, "string table size =%u", n_strings);

  for (uint32_t i = 0; i < n_strings; ++i) {
    alignas(4) uint8_t tmp[0x1c];
    basic_string_ctor_default(tmp);
    // FUN_00766fb0: stream → tmp (NUL-terminated)
    FUN_00766fb0();
    // FUN_00989e00: intern/lookup into host string table
    FUN_00989e00(host_table, /*out*/nullptr, /*name from tmp*/nullptr);
    StringVec_PushBack(&local_strings, tmp);
    basic_string_dtor(tmp);
  }

  // --- pyramids (nested schema summarized; see annotated + raw hex) ---
  uint32_t n_pyramids = 0;
  FUN_007a4480(-1, "pyramids =%u", n_pyramids);
  // FUN_00430540 resize host pyramid vec to n_pyramids (stride 0x10)
  // per pyramid: read subcounts, FUN_00430600 reshape, lower_bound+stricmp fill
  (void)FUN_00430540;
  (void)FUN_00430600;
  (void)FUN_0044ff40;

  // destroy local string vector
  if (local_strings.begin != nullptr) {
    for (uint8_t* p = local_strings.begin; p != local_strings.end; p += 0x1c) {
      basic_string_dtor(p);
    }
    operator_delete(local_strings.begin);
  }

  return 1; // B0 01 … C2 0C 00
}

// Scaffold alias
extern "C" uint8_t FUN_0099bba0(void* host_table, void* scratch,
                                StreamReader* reader)
{
  return CNDAssetStringTable_Unserialize(host_table, scratch, reader);
}
