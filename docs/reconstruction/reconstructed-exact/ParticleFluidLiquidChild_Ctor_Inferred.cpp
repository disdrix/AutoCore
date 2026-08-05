// =============================================================================
// ParticleFluidLiquidChild_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1800
// Address:   0x004c1800–0x004c187d inclusive (126 B / 0x7E)
// Module:    autoassault.exe (image base 0x400000)
// System:    client / particle fluid phase / liquid child (phase+0xc4)
// Generated: 2026-08-04 W37-G dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Construct the 0x40 liquid-environment child allocated by
// ParticleFluidPhase_CreateLiquidChild_Inferred (0x004c1960, W34-O):
//   - store phase* parent at +0x00
//   - install empty 0xC list sentinel at +0x08 / size 0 at +0x0C
//   - zero active flag +0x10 and +0x14
//   - construct host-link subobject at +0x18 via FUN_004c17b0 (unowned)
//   - zero +0x20..+0x3C (8 dwords)
//   - publish DAT_00b03794 = this
//
// ABI: __thiscall ECX=this, stack phase*, returns this, RET 4.
// Reject scaffold Named_CalleeOf_*Drive_NDRiver_fx_004c1800.
//
// Bytes win: FUN_004c17b0 is thiscall on this+0x18 with stack parent=this
// (decompiler shows FUN_004c17b0(param_1) flattened).

#include <cstdint>

extern "C" void *ExceptionList;
extern "C" void *DAT_00b03794;
extern "C" void *StdList_AllocSentinel_0xC_Inferred(void); // FUN_004933f0 (W32-P)
// Host-link subobject ctor: ECX=subobj (+0x18), stack=parent child*
extern "C" void *__thiscall FUN_004c17b0(void *subobj /*ECX*/, void *parent);

extern "C" void *__thiscall ParticleFluidLiquidChild_Ctor_Inferred(
    void *self /*ECX*/, void *phase /*stack*/)
{
  // Retail SEH frame (LAB_009a1aa2) omitted in clean contract form.
  *reinterpret_cast<void **>(self) = phase;

  void *sentinel = StdList_AllocSentinel_0xC_Inferred();
  *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x08) = sentinel;
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x0C) = 0;

  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(self) + 0x10) = 0;
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x14) = 0;

  FUN_004c17b0(reinterpret_cast<char *>(self) + 0x18, self);

  auto *tail = reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(self) + 0x20);
  for (int i = 0; i < 8; ++i) {
    tail[i] = 0;
  }

  DAT_00b03794 = self;
  return self;
}

// Ghidra twin
extern "C" void *__thiscall FUN_004c1800(void *self /*ECX*/, void *phase /*stack*/)
{
  return ParticleFluidLiquidChild_Ctor_Inferred(self, phase);
}
