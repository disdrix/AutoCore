// =============================================================================
// PhysSim_FlushPendingBodyPairs_Inferred  (FUN_00561320)
// -----------------------------------------------------------------------------
// Stable ID: aa_00561320
// Address:   0x00561320  (autoassault.exe, image base 0x400000)
// Body:      0x00561320 – 0x00561360 (exclusive end 0x00561361)
// System:    physics / island pair glue
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W19-M)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Drain the pending body-pair vector at world+0x20 (count at +0x24).
// For each (bodyA, bodyB), if bodyA->host (+0x44) != bodyB->host, call
// FUN_00560a30(world, hostA, hostB) to merge hosts. Then clear count to 0.
// Producer: PhysSim_PushBodyPair_Inferred (0x0055efd0). Consumers: island step
// (FUN_00561910) flushes multiple times; also remove/defer paths.
//
// ABI: ECX = world/sim; zero stack args; bare ret (c3).
//
// RELATED:
//   - PhysSim_PushBodyPair_Inferred @ 0x0055efd0 (producer)
//   - FUN_00560a30 host merge (callee; not dualed here)
//   - Island step FUN_00561910 verified notes
//

#include <cstdint>

// Forward: host merge (ECX=world, stack hostA, hostB)
extern "C" void *__thiscall FUN_00560a30(void *world, void *hostA, void *hostB);

void __thiscall PhysSim_FlushPendingBodyPairs_Inferred(void *world)
{
  int count = *(int *)((char *)world + 0x24);
  int i = 0;
  if (count > 0) {
    do {
      uint8_t *data = *(uint8_t **)((char *)world + 0x20);
      void *bodyA = *(void **)(data + i * 8);
      void *bodyB = *(void **)(data + i * 8 + 4);
      void *hostA = *(void **)((char *)bodyA + 0x44);
      void *hostB = *(void **)((char *)bodyB + 0x44);
      if (hostA != hostB) {
        FUN_00560a30(world, hostA, hostB);
      }
      i = i + 1;
    } while (i < *(int *)((char *)world + 0x24));
  }
  *(int *)((char *)world + 0x24) = 0;
}

// Ghidra alias — note: decompiler omits this on 00560a30 call
void __fastcall FUN_00561320(int param_1)
{
  PhysSim_FlushPendingBodyPairs_Inferred((void *)param_1);
}

// Misleading auto parent-seed alias
void Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_00561320(int param_1)
{
  FUN_00561320(param_1);
}
