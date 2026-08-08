// =============================================================================
// TargetFilter_FindNearestWorldObjByCbidList_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092adf0
// Address:   0x0092adf0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / inventory-transfer (adjacent)
// Generated: 2026-08-04 WQ8R-I dual A/B seal
// Exactness: Behavior-preserving rewrite. Bytes win on ABI / Find ECX path.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Walk the client world-object list under TraversalLock. Among objects that:
//     (1) are not the local player (this-adjusted character host vs object+0xAC),
//     (2) have COID absent from the character locker grid (*(char+0xCBC)),
//     (3) match any CBID in ctx whitelist (ctx+0x28 count, ctx+0x2C array)
//         against *(clonebase+0x34),
//   pick the nearest to origin (squared distance) into *bestOut / *bestDistSq.
//
// ABI
//   EDI = TargetFilterCtx*  (*ctx = Client*)
//   stack: float* origin, void** bestOut, float* bestDistSq
//   ret 0x0C; returns 1
//
// CALLER
//   FUN_0092af80 when ctx+0x28 > 0 (sibling arms: ResolveObjectTarget, 0092abc0,
//   0092a980, 0092a760). Grandcaller FUN_0092bf60 supplies character position.
//
// CALLEES
//   FUN_004294f0 TraversalLock
//   FUN_004022a0 IterateNext
//   InventoryGrid_FindItemByCoid (0x00571010)  this = *(character+0xCBC)
//   object vtbl +0x144
//   LeaveCriticalSection
// =============================================================================

#include <cstdint>

struct Client;
struct Character;
struct InventoryGrid;
struct Object;

extern "C" {
void TraversalLock(/* list lock from client */);
int  IterateNext(void *state, Object **outObj);
Object *InventoryGrid_FindItemByCoid(InventoryGrid *grid, int coidLo, int coidHi);
void __stdcall LeaveCriticalSection(void *cs);
}

// Filter context (partial; only fields used here)
struct TargetFilterCtx {
  Client *client;          // +0x00
  // ...
  // +0x28 int cbidCount
  // +0x2C int cbidArray[]
};

std::uint32_t TargetFilter_FindNearestWorldObjByCbidList_Inferred(
    float *origin,
    void **bestOut,
    float *bestDistSq)
{
  // EDI = TargetFilterCtx* (register, not a C++ formal)
  TargetFilterCtx *ctx = /* EDI */;

  Object *iterOut = nullptr;
  void *lockState[4] = {};
  TraversalLock();
  int iterRc = IterateNext(lockState, &iterOut);
  Object *obj = iterOut;

  while (iterRc == 0) {
    if (obj != nullptr) {
      Character *ch = *reinterpret_cast<Character **>(
          reinterpret_cast<char *>(ctx->client) + 0xE98);

      void *selfAdj = nullptr;
      void *host = *reinterpret_cast<void **>(reinterpret_cast<char *>(ch) + 0x250);
      if (host != nullptr) {
        int *v = *reinterpret_cast<int **>(reinterpret_cast<char *>(host) + 4);
        selfAdj = reinterpret_cast<char *>(host) + v[1] + 4;
      }

      auto *objAC = *reinterpret_cast<void **>(reinterpret_cast<char *>(obj) + 0xAC);
      int coidLo = *reinterpret_cast<int *>(reinterpret_cast<char *>(obj) + 0x160);
      int coidHi = *reinterpret_cast<int *>(reinterpret_cast<char *>(obj) + 0x164);
      auto *locker = *reinterpret_cast<InventoryGrid **>(
          reinterpret_cast<char *>(ch) + 0xCBC);

      int cbidCount = *reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x28);
      if (objAC != selfAdj
          && InventoryGrid_FindItemByCoid(locker, coidLo, coidHi) == nullptr
          && cbidCount > 0) {
        int *cbidList = reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x2C);
        void *clonebase = *reinterpret_cast<void **>(reinterpret_cast<char *>(obj) + 0xA8);
        int objCbid = *reinterpret_cast<int *>(reinterpret_cast<char *>(clonebase) + 0x34);

        for (int i = 0; i < cbidCount; ++i) {
          if (cbidList[i] == objCbid) {
            // vtbl +0x144 refresh
            using Vfn = void(__thiscall *)(Object *);
            auto **vtbl = *reinterpret_cast<Vfn ***>(obj);
            vtbl[0x144 / 4](obj);

            float *px = reinterpret_cast<float *>(reinterpret_cast<char *>(obj) + 0x80);
            float dx = px[0] - origin[0];
            float dy = px[1] - origin[1];
            float dz = px[2] - origin[2];
            float d2 = dx * dx + dy * dy + dz * dz;
            if (d2 < *bestDistSq) {
              *bestDistSq = d2;
              *bestOut = obj;
            }
          }
        }
      }
    }
    iterRc = IterateNext(lockState, &iterOut);
    obj = iterOut;
  }

  void *listRoot = *reinterpret_cast<void **>(
      reinterpret_cast<char *>(ctx->client) + 0xD34);
  void *csHost = *reinterpret_cast<void **>(reinterpret_cast<char *>(listRoot) + 0x20);
  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(csHost) + 0x28) != 0) {
    *reinterpret_cast<char *>(reinterpret_cast<char *>(csHost) + 0x28) = 0;
    LeaveCriticalSection(reinterpret_cast<char *>(csHost) + 4);
  }
  return 1;
}
