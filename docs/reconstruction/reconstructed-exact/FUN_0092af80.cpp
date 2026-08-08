// =============================================================================
// FUN_0092af80  (clean twin of TargetFilter_DispatchMatchArms_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092af80
// Address:   0x0092af80  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (partition)
// Generated: 2026-08-05 R11-039 dual A/B seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named twin: TargetFilter_DispatchMatchArms_Inferred.cpp
// =============================================================================

#include <cstdint>

struct Object;

extern "C" {
Object *CVOGReaction_ResolveObjectTarget(void *resolveCtx, unsigned char bGlobal,
                                         uint32_t coidLo, uint32_t coidHi);
uint32_t FUN_0092adf0(float *origin, Object **bestOut, float *bestDistSq);
uint32_t FUN_0092abc0(float *origin, Object **bestOut, float *bestDistSq);
uint32_t FUN_0092a980(float *origin, Object **bestOut, float *bestDistSq);
char     FUN_0092a760(float *origin, Object **bestOut, float *bestDistSq);
uint32_t FUN_00929cd0(void *ctx, float *origin, Object **bestOut, float *bestDistSq);
}

// EAX = TargetFilterCtx*, ESI = Object**, stack origin + bestDistSq, ret 8
bool FUN_0092af80(float *origin, float *bestDistSq)
{
  void *ctx = /* EAX → EDI */;
  Object **bestOut = /* ESI */;
  bool any = false;

  uint32_t lo = *(uint32_t *)((char *)ctx + 0x20);
  uint32_t hi = *(uint32_t *)((char *)ctx + 0x24);
  if ((lo & hi) != 0xFFFFFFFFu) {
    void *client = *(void **)ctx;
    void *resolveCtx = *(void **)((char *)client + 0xD34);
    *bestOut = CVOGReaction_ResolveObjectTarget(resolveCtx, 0, lo, hi);
    any = true;
  }

  if (*(int *)((char *)ctx + 0x28) > 0) {
    FUN_0092adf0(origin, bestOut, bestDistSq);
    any = true;
  }
  if (*(int *)((char *)ctx + 0x80) > 0) {
    FUN_0092abc0(origin, bestOut, bestDistSq);
    any = true;
  }
  if (*(int *)((char *)ctx + 0x54) > 0) {
    FUN_0092a980(origin, bestOut, bestDistSq); // EBX = ctx
    any = true;
  }
  if (*(int *)((char *)ctx + 0xAC) > 0) {
    if (FUN_0092a760(origin, bestOut, bestDistSq) == 0) {
      FUN_00929cd0(ctx, origin, bestOut, bestDistSq);
    }
    any = true;
  }
  return any;
}
