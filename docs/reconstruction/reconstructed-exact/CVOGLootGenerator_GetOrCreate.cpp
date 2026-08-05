// =============================================================================
// CVOGLootGenerator_GetOrCreate
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce940
// Address:   0x004ce940  (autoassault.exe, image base 0x400000)
// System:    loot / economy content (lazy singleton)
// Generated: 2026-07-29 dual W17-J (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite; decompiler void/SEH artifacts fixed.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Lazy ensure/get of process-wide CVOGLootGenerator at DAT_00b037e8.
//   First create: operator_new(0xbc) + FUN_0050c1b0(this=new, DAT_00b041fc).
//   Returns singleton pointer in EAX (0 on OOM). No stack args.
//
// PEERS:
//   CVOGSectorMap_InitGenerators also constructs into DAT_00b037e8 (size 0xbc).
//   FUN_0050c1b0 dual: LootManager_ctor_Inferred / CVOGLootGenerator ctor.
//
// NOTE: Ghidra types as void and mis-lifts SEH restore. Prefer this clean.
// =============================================================================

#include <cstdint>

extern "C" void* operator_new(std::uint32_t size);
// Ctor: __thiscall ECX=mem, arg0=table root; returns this* in EAX.
extern "C" void* __thiscall FUN_0050c1b0(void* self, void* tableRoot);

// Globals (autoassault image).
extern "C" void* DAT_00b037e8; // CVOGLootGenerator* singleton
extern "C" void* DAT_00b041fc; // shared table root

static constexpr std::uint32_t kLootGeneratorSize = 0xbcu;

void* CVOGLootGenerator_GetOrCreate(void)
{
  // SEH frame present in retail (handler LAB_009a1f0c); omitted as non-behavioral
  // for the success path description. Construction is not thread-locked.

  if (DAT_00b037e8 != nullptr) {
    return DAT_00b037e8;
  }

  void* mem = operator_new(kLootGeneratorSize);
  if (mem == nullptr) {
    DAT_00b037e8 = nullptr;
    return nullptr;
  }

  // __thiscall ctor with table root.
  DAT_00b037e8 = FUN_0050c1b0(mem, DAT_00b041fc);
  return DAT_00b037e8;
}
