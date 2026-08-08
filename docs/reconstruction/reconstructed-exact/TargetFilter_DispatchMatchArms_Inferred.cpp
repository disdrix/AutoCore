// =============================================================================
// TargetFilter_DispatchMatchArms_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092af80
// Address:   0x0092af80  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (partition) / skill-reaction target-filter family
// Generated: 2026-08-05 R11-039 dual A/B seal
// Exactness: Behavior-preserving rewrite. Bytes win on ABI (EAX/ESI/ret 8).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Dispatch target-filter context arms that fill *bestOut / *bestDistSq:
//     1. Direct COID via CVOGReaction_ResolveObjectTarget when halves valid
//     2. CBID whitelist nearest world obj (dualed 0x0092adf0) when +0x28 > 0
//     3. Residual arms at +0x80 / +0x54 / +0xAC (with 00929cd0 fallback)
//   Returns true if any arm was eligible (sticky AL), not whether a hit exists.
//
// ABI
//   EAX = TargetFilterCtx*  (*ctx = Client*)
//   ESI = void **bestOut
//   stack: float *origin, float *bestDistSq
//   ret 8; returns AL bool
//
// CALLER
//   FUN_0092bf60 @ 0x0092bff5 — sole static CALL; supplies char pos vtbl+0x1A0
//   and max-dist sentinel DAT_00aaaaf8.
//
// CALLEES
//   CVOGReaction_ResolveObjectTarget (0x004bae70)  this = *(client+0xD34)
//   TargetFilter_FindNearestWorldObjByCbidList_Inferred (0x0092adf0)
//   FUN_0092abc0, FUN_0092a980, FUN_0092a760, FUN_00929cd0  [residual]
// =============================================================================

#include <cstdint>

struct Client;
struct Object;

struct TargetFilterCtx {
  Client *client; // +0x00
  // ...
  // +0x20 uint32 coidLo; +0x24 coidHi
  // +0x28 int cbidCount
  // +0x54 int arm54Count
  // +0x80 int arm80Count
  // +0xAC int armAcCount
};

extern "C" {
Object *CVOGReaction_ResolveObjectTarget(void *resolveCtx, unsigned char bGlobal,
                                         uint32_t coidLo, uint32_t coidHi);
uint32_t TargetFilter_FindNearestWorldObjByCbidList_Inferred(float *origin,
                                                             Object **bestOut,
                                                             float *bestDistSq);
uint32_t FUN_0092abc0(float *origin, Object **bestOut, float *bestDistSq);
uint32_t FUN_0092a980(float *origin, Object **bestOut, float *bestDistSq);
char     FUN_0092a760(float *origin, Object **bestOut, float *bestDistSq);
uint32_t FUN_00929cd0(TargetFilterCtx *ctx, float *origin, Object **bestOut,
                      float *bestDistSq);
}

// Register formals: EAX = ctx, ESI = bestOut (not expressible in portable C ABI).
bool TargetFilter_DispatchMatchArms_Inferred(float *origin, float *bestDistSq)
{
  // Live registers (from image):
  TargetFilterCtx *ctx = /* EAX */;
  Object **bestOut     = /* ESI */;

  bool any = false;

  uint32_t lo = *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(ctx) + 0x20);
  uint32_t hi = *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(ctx) + 0x24);
  if ((lo & hi) != 0xFFFFFFFFu) {
    void *resolveCtx =
        *reinterpret_cast<void **>(reinterpret_cast<char *>(ctx->client) + 0xD34);
    *bestOut = CVOGReaction_ResolveObjectTarget(resolveCtx, 0, lo, hi);
    any = true;
  }

  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x28) > 0) {
    TargetFilter_FindNearestWorldObjByCbidList_Inferred(origin, bestOut, bestDistSq);
    any = true;
  }

  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x80) > 0) {
    FUN_0092abc0(origin, bestOut, bestDistSq);
    any = true;
  }

  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x54) > 0) {
    // Callee FUN_0092a980 consumes EBX = ctx (bytes: MOV EBX,EDI before CALL).
    FUN_0092a980(origin, bestOut, bestDistSq);
    any = true;
  }

  if (*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0xAC) > 0) {
    char ok = FUN_0092a760(origin, bestOut, bestDistSq);
    if (ok == 0) {
      FUN_00929cd0(ctx, origin, bestOut, bestDistSq);
    }
    any = true;
  }

  return any;
}
