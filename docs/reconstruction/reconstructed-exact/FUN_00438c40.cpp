// =============================================================================
// FUN_00438c40 — Ghidra twin of Sto_UnserialFactoryMapA_GetInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00438c40
// Address:   0x00438c40–0x00438c99  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — abstract unserialization factory (map A)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W35-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: Sto_UnserialFactoryMapA_GetInstance_Inferred.cpp
// =============================================================================

#include <cstdint>

struct NestedHash_Sentinel0x10 {
  uint32_t pad00;
  uint32_t pad04;
  void*    sentinel;
  uint32_t size;
  uint32_t shell_unk10;
  void*    buckets_begin;
  void*    buckets_end;
  void*    buckets_cap;
  uint32_t flag20;
  uint32_t flag24;
}; // 0x28

extern NestedHash_Sentinel0x10 DAT_00d1fd18;
extern uint32_t DAT_00d1fd40;
extern "C" NestedHash_Sentinel0x10* FUN_00457ac0(NestedHash_Sentinel0x10* self /*stack*/);
extern "C" int _atexit(void (*func)(void));
extern "C" void LAB_009c3310(void);
extern void* ExceptionList;
extern unsigned char LAB_009bcc4d;

/*
 * Behavioral notes (W35-D):
 * - Meyers getter: once-flag DAT_00d1fd40 bit0 → NestedHash ctor on DAT_00d1fd18.
 * - atexit LAB_009c3310 is process-exit no-op (JMP to RET 4).
 * - Callers: FUN_004449b0 (insert), FUN_00437b00 (lookup).
 * - Body 90 B; cdecl; return &DAT_00d1fd18.
 */

extern "C" NestedHash_Sentinel0x10* FUN_00438c40(void)
{
  void* local_c;
  unsigned char* puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_009bcc4d;
  local_c = ExceptionList;
  if ((DAT_00d1fd40 & 1u) == 0) {
    DAT_00d1fd40 = DAT_00d1fd40 | 1u;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00457ac0(&DAT_00d1fd18);
    _atexit(LAB_009c3310);
  }
  ExceptionList = local_c;
  return &DAT_00d1fd18;
}
