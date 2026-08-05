// =============================================================================
// AssResolverCore_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00983940
// Address:   0x00983940–0x009839af  (autoassault.exe, image base 0x400000)
// System:    assets / assManager resolver-B core + effect probe host
// Generated: 2026-07-23 scaffold as FUN_00983940; dual A/B seal 2026-07-29 (W31-G)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
//            DAT_00d1ef58 store is WORD (bytes win over decompiler dword plate).
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement constructor for a CS-guarded resolver/probe core object.
//   Nested member via FUN_00469db0; zeros triple at +0x2c; CRITICAL_SECTION at
//   +0x38; ready flag at +0x50; clears process globals DAT_00d1ef44..5c / word 58.
//
// ABI (bytes):
//   stdcall 1 formal (self*); RET 4; returns self in EAX.
//   Body 112 B; SEH LAB_009ac8fc (EH state stays -1).
//
// CALLERS:
//   AssManager_InitPrecompileAndResolvers (0x007b75b0) flag bit1:
//     new(0x5c); *mem = PTR_FUN_00aa1f1c; *(mem+4)=0; this(mem+8) → self+0x0c
//   FUN_00985010 @ 0x00985051 / 0x0098507b (stack placement ×2 before probes)
//

#include <cstdint>
#include <windows.h>

extern "C" void* FUN_00469db0(void* self /*stack*/);

// Process globals (retail)
extern "C" uint32_t DAT_00d1ef44;
extern "C" uint32_t DAT_00d1ef48;
extern "C" uint32_t DAT_00d1ef50;
extern "C" uint32_t DAT_00d1ef5c;
extern "C" uint16_t DAT_00d1ef58; // WORD store in retail

struct AssResolverCore {
  uint8_t member_head[0x2c]; // FUN_00469db0 span
  uint32_t tri_2c;           // +0x2c
  uint32_t tri_30;           // +0x30
  uint32_t tri_34;           // +0x34
  CRITICAL_SECTION cs;       // +0x38 (0x18)
  uint8_t ready;             // +0x50
};

// Retail: stack(self*); RET 4; return self
extern "C" AssResolverCore* AssResolverCore_Ctor_Inferred(AssResolverCore* self /*stack*/)
{
  FUN_00469db0(self);
  self->tri_2c = 0;
  self->tri_30 = 0;
  self->tri_34 = 0;
  InitializeCriticalSection(&self->cs);
  self->ready = 1;
  DAT_00d1ef44 = 0;
  DAT_00d1ef48 = 0;
  DAT_00d1ef50 = 0;
  DAT_00d1ef5c = 0;
  DAT_00d1ef58 = 0; // WORD
  return self;
}

extern "C" AssResolverCore* FUN_00983940(AssResolverCore* self)
{
  return AssResolverCore_Ctor_Inferred(self);
}
