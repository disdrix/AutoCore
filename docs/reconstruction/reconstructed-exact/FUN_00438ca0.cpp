// =============================================================================
// FUN_00438ca0 — Ghidra twin of Sto_UnserialFactoryMapB_GetInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00438ca0
// Address:   0x00438ca0–0x00438cf9  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — abstract unserialization factory (map B)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W35-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: Sto_UnserialFactoryMapB_GetInstance_Inferred.cpp
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

extern NestedHash_Sentinel0x10 DAT_00d1fcec;
extern uint32_t DAT_00d1fd14;
extern "C" NestedHash_Sentinel0x10* FUN_00457ac0(NestedHash_Sentinel0x10* self /*stack*/);
extern "C" int _atexit(void (*func)(void));
extern "C" void LAB_009c3300(void);
extern void* ExceptionList;
extern unsigned char LAB_009bcc2d;

/*
 * Behavioral notes (W35-D):
 * - Meyers getter twin of FUN_00438c40; bag DAT_00d1fcec; once DAT_00d1fd14 bit0.
 * - atexit LAB_009c3300 → same RET4 no-op as MapA.
 * - Callers: FUN_00444a40 (insert), FUN_00437c90 (lookup).
 * - Body 90 B; cdecl; return &DAT_00d1fcec.
 */

extern "C" NestedHash_Sentinel0x10* FUN_00438ca0(void)
{
  void* local_c;
  unsigned char* puStack_8;
  uint32_t local_4;

  puStack_8 = &LAB_009bcc2d;
  local_c = ExceptionList;
  if ((DAT_00d1fd14 & 1u) == 0) {
    DAT_00d1fd14 = DAT_00d1fd14 | 1u;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00457ac0(&DAT_00d1fcec);
    _atexit(LAB_009c3300);
  }
  ExceptionList = local_c;
  return &DAT_00d1fcec;
}
