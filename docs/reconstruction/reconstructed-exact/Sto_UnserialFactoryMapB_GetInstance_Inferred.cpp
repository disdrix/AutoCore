// =============================================================================
// Sto_UnserialFactoryMapB_GetInstance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00438ca0
// Address:   0x00438ca0–0x00438cf9  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — abstract unserialization factory (map B)
// Generated: 2026-07-23 scaffold as FUN_00438ca0; dual A/B seal 2026-07-29 (W35-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Meyers-style singleton getter for process-static NestedHash bag B
//   (DAT_00d1fcec) — second creator-tag map for stoAbstractUnserializationFactory.
//
//   First call (DAT_00d1fd14 bit0 clear):
//     1. Set once-flag bit0
//     2. NestedHash_Ctor_Sentinel0x10_Inferred(&DAT_00d1fcec)  // FUN_00457ac0
//     3. atexit(LAB_009c3300)  // MOV EAX,&bag; JMP RET4 — process-exit no-op free
//   Always returns &DAT_00d1fcec in EAX.
//
// ABI (bytes):
//   cdecl; no stack args; ADD ESP,0xC; RET. SEH LAB_009bcc2d. Body 90 B.
//
// CALLERS (exclusive pair):
//   FUN_00444a40 — Sto_AbstractUnserializationFactory sibling insert
//   FUN_00437c90 — factory lookup / invoke creator
//
// TWIN:
//   Sto_UnserialFactoryMapA_GetInstance_Inferred (0x00438c40) — bag DAT_00d1fd18
//
// REJECT scaffold: Named_CalleeOf_*_gfxBody_*
//

#include <cstdint>

struct NestedHash_Sentinel0x10 {
  uint32_t pad00;
  uint32_t pad04;
  void*    sentinel;      // +0x08
  uint32_t size;          // +0x0c
  uint32_t shell_unk10;   // +0x10
  void*    buckets_begin; // +0x14
  void*    buckets_end;   // +0x18
  void*    buckets_cap;   // +0x1c
  uint32_t flag20;        // +0x20
  uint32_t flag24;        // +0x24
}; // 0x28

// BSS: DAT_00d1fcec bag; DAT_00d1fd14 once bit0

extern "C" NestedHash_Sentinel0x10*
NestedHash_Ctor_Sentinel0x10_Inferred(NestedHash_Sentinel0x10* self /*stack*/); // FUN_00457ac0

extern "C" int _atexit(void (*func)(void));
extern "C" void LAB_009c3300(void);

extern "C" NestedHash_Sentinel0x10*
Sto_UnserialFactoryMapB_GetInstance_Inferred(void)
{
  // SEH frame LAB_009bcc2d (omitted)
  static NestedHash_Sentinel0x10 g_mapB; // stand-in for DAT_00d1fcec
  static uint32_t g_once;               // stand-in for DAT_00d1fd14

  if ((g_once & 1u) == 0) {
    g_once |= 1u;
    NestedHash_Ctor_Sentinel0x10_Inferred(&g_mapB);
    _atexit(LAB_009c3300);
  }
  return &g_mapB;
}

// Ghidra twin symbol
extern "C" NestedHash_Sentinel0x10* FUN_00438ca0(void)
{
  return Sto_UnserialFactoryMapB_GetInstance_Inferred();
}
