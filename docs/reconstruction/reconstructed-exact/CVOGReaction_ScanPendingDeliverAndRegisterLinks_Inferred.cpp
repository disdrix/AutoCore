// =============================================================================
// CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred  (FUN_004de760)
// -----------------------------------------------------------------------------
// Stable ID: aa_004de760
// Address:   0x004de760–0x004de9e6  (autoassault.exe, image base 0x400000)
// Body size: 647 bytes (0x287)
// System:    missions-progression / object-hash links
// Generated: 2026-07-23 scaffold as FUN_004de760; dual A/B seal 2026-07-29 (W23-M)
// Exactness: Behavior-preserving rewrite of decompiler + entry/exit-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Under TraversalLock on character pending-objectives hash (+0x55c):
//     for each pending objective's evaluators:
//       if type vcall(+0x50) == 3 (Deliver) and RTTI cast succeeds and
//       deliver[+0x1c] == host[+0xfc]:
//         match world objects (optional single object, or host list at +0xe4e8)
//         whose MI field +0x34 == deliver[+0x18];
//         predicate vcall(+0xc) selects RegisterObjectHashEntry mode 5 vs 8;
//         pass objective id from hash entry and links -1,-1.
//
// ABI
//   __thiscall: ECX = host*; stack character*, optionalObject* (0 = scan list);
//   ret 8.
//
// NOTE
//   Prior coverage alias "Mission_CVOGObjectiveRequirement_RTTI_Type_Descriptor"
//   is incorrect — this is worker code that *references* RTTI for dynamic_cast.
//

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *fmt, ...);
extern "C" void * __RTDynamicCast(void *obj, long vfDelta, void *srcType, void *targetType, int isRef);
extern "C" void FUN_004dbef0(void *objAdj, std::uint32_t mode, std::uint32_t a, std::uint32_t b, std::uint32_t objId);
// Peer sealed name: CVOGReaction_RegisterObjectHashEntry_Inferred (this = host in ECX)

// Ghidra RTTI symbols (addresses sealed via body immediates / decompile names):
extern "C" void CVOGObjectiveRequirement_RTTI_Type_Descriptor;
extern "C" void CVOGObjectiveRequirement_Deliver_RTTI_Type_Descriptor;

extern "C" void CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred(
    void *host /*ECX*/,
    void *character /*stack+4*/,
    void *optionalObject /*stack+8; null => scan host list*/)
{
  void *ch = character;
  int *hash = *reinterpret_cast<int **>(static_cast<char *>(ch) + 0x55c);
  int *cursor = nullptr;

  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(hash) + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<char *>(reinterpret_cast<char *>(hash) + 0x1d) = 1;

  void *opt = optionalObject;

  for (;;) {
    int *h = *reinterpret_cast<int **>(static_cast<char *>(ch) + 0x55c);
    if (*reinterpret_cast<char *>(reinterpret_cast<char *>(h) + 0x1d) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }

    int *entry = nullptr;
    if (cursor == nullptr) {
      cursor = *reinterpret_cast<int **>(reinterpret_cast<char *>(h) + 0x14);
      if (cursor == nullptr)
        goto exhausted;
      entry = *reinterpret_cast<int **>(reinterpret_cast<char *>(cursor) + 8);
    } else {
      cursor = *reinterpret_cast<int **>(reinterpret_cast<char *>(cursor) + 0x14);
      if (cursor == nullptr) {
      exhausted:
        entry = nullptr;
      } else {
        entry = *reinterpret_cast<int **>(reinterpret_cast<char *>(cursor) + 8);
      }
    }

    if (entry == nullptr) {
      *reinterpret_cast<char *>(
          *reinterpret_cast<char **>(static_cast<char *>(ch) + 0x55c) + 0x1d) = 0;
      return;
    }

    int i = 0;
    for (;;) {
      int *objective = reinterpret_cast<int *>(*entry);
      int count;
      if (*reinterpret_cast<int *>(reinterpret_cast<char *>(objective) + 0x158) == 0) {
        count = 0;
      } else {
        count = (*reinterpret_cast<int *>(reinterpret_cast<char *>(objective) + 0x15c) -
                *reinterpret_cast<int *>(reinterpret_cast<char *>(objective) + 0x158)) >> 2;
      }
      if (count <= i)
        break;

      int *req = *reinterpret_cast<int **>(
          *reinterpret_cast<int *>(reinterpret_cast<char *>(objective) + 0x158) + i * 4);
      int type = (*(int(__thiscall **)(int *))(*req + 0x50))(req);
      if (type == 3) {
        int *deliver = static_cast<int *>(__RTDynamicCast(
            req, 0,
            &CVOGObjectiveRequirement_RTTI_Type_Descriptor,
            &CVOGObjectiveRequirement_Deliver_RTTI_Type_Descriptor,
            0));
        if (deliver[7] == *reinterpret_cast<int *>(static_cast<char *>(host) + 0xfc)) {
          if (opt == nullptr) {
            unsigned j = 0;
            for (;;) {
              // host list via character MI +0xa8 → +0xe4e8 context
              int *listRoot = *reinterpret_cast<int **>(
                  *reinterpret_cast<int *>(
                      *reinterpret_cast<int *>(static_cast<char *>(ch) + 4) + 4) +
                  0xa8 + reinterpret_cast<int>(ch));
              int *ctx = *reinterpret_cast<int **>(reinterpret_cast<char *>(listRoot) + 0xe4e8);
              if (*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x2c) == 0 ||
                  (unsigned)((*reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x30) -
                              *reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x2c)) >> 2) <= j)
                break;

              int *slot = *reinterpret_cast<int **>(
                  *reinterpret_cast<int *>(reinterpret_cast<char *>(ctx) + 0x2c) + j * 4);
              int *resolved = reinterpret_cast<int *>(
                  (*(int(__thiscall **)(int *))(*slot + 0x1d8))(slot));
              if (resolved == nullptr ||
                  *reinterpret_cast<int *>(
                      *reinterpret_cast<int *>(
                          *reinterpret_cast<int *>(
                              *reinterpret_cast<int *>(reinterpret_cast<char *>(resolved) + 4) + 4) +
                          0xac + reinterpret_cast<int>(resolved)) +
                      0x34) != deliver[6]) {
                ++j;
              } else {
                char ok = (*(char(__thiscall **)(int *, void *, int *))(*deliver + 0xc))(
                    deliver, ch, entry);
                int *objAdj = reinterpret_cast<int *>(
                    *reinterpret_cast<int *>(
                        *reinterpret_cast<int *>(reinterpret_cast<char *>(resolved) + 4) + 4) +
                    4 + reinterpret_cast<int>(resolved));
                std::uint32_t objId =
                    *reinterpret_cast<std::uint32_t *>(*entry + 0x10);
                if (ok == 0) {
                  FUN_004dbef0(objAdj, 5, 0xffffffffu, 0xffffffffu, objId);
                } else {
                  FUN_004dbef0(objAdj, 8, 0xffffffffu, 0xffffffffu, objId);
                }
                ++j;
              }
            }
          } else if (*reinterpret_cast<int *>(
                         *reinterpret_cast<int *>(
                             *reinterpret_cast<int *>(
                                 *reinterpret_cast<int *>(static_cast<char *>(opt) + 4) + 4) +
                             0xac + reinterpret_cast<int>(opt)) +
                         0x34) == deliver[6]) {
            char ok = (*(char(__thiscall **)(int *, void *, int *))(*deliver + 0xc))(
                deliver, ch, entry);
            int *base = *reinterpret_cast<int **>(
                *reinterpret_cast<int *>(static_cast<char *>(opt) + 4) + 4);
            std::uint32_t objId = *reinterpret_cast<std::uint32_t *>(*entry + 0x10);
            std::uint32_t mode = (ok == 0) ? 5u : 8u;
            FUN_004dbef0(reinterpret_cast<int *>(
                             reinterpret_cast<char *>(base) + 4 + reinterpret_cast<int>(opt)),
                         mode, 0xffffffffu, 0xffffffffu, objId);
          }
        }
      }
      ++i;
    }
  }
}

// Also available under historical scaffold name FUN_004de760 (same VA).
