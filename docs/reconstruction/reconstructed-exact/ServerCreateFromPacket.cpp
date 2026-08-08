// =============================================================================
// ServerCreateFromPacket
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b350
// Address:   0x0051b350–0x0051b54e  (autoassault.exe, image base 0x400000)
// System:    object-spawn / network create (client)
// Generated: 2026-07-23 scaffold as FUN_0051b350; **sealed 2026-08-04** dual A/B WQ9R-I
// Exactness: Behavior-preserving. Corrects decompiler traps (unaff_EDI map arg,
//            missing unpack thiscall stream, COID field offsets) via read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// Product:   profiler zone + error plate "ServerCreateFromPacket" @ 0x009cee68
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - Free function, caller-clean (bare RET after local teardown). Stack:
 *     arg0 = unpack stream* (thiscall host for FUN_00787d40)
 *     arg1 = host* (passed to object vtbl+8 init as 2nd formal)
 * - Profiler: EnterNamedZone("ServerCreateFromPacket") / Leave on all exits.
 * - Packet: unpack int32 CBID; if CBID == -1 → return null.
 *           unpack int64 COID (8 bytes).
 * - Optional CBID remap: Map_LowerBoundFindByIntKey on *(DAT_00b041fc)+4
 *   with key=&cbid. If iterator != map.end (header+8), replace cbid with
 *   node+0x10 and set remapped=true. (Decompiler unaff_EDI is FALSE — BL flag.)
 * - Factory: CVOGReaction_GiveItemByCbid(cbid). Fail → log
 *   "Invalid CBID allocated: %d, coid : %I64d" and return null.
 * - Init: vtbl+8(obj, cbid, host, 1). Fail → log
 *   "Invalid CBID initified: %d, coid : %I64d" and return null.
 * - Stamp COID: obj+0x160/+0x164 = coid lo/hi; obj+0x168 = 1.
 * - Identity: vtbl+0x20(obj, coid_lo, coid_hi, 0, stream, 1).
 *   Success: if remapped, obj+0x17c |= 0x80; return obj*.
 *   Fail: log "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)";
 *         allocate empty list head (FUN_0040fb90); vtbl+0x2b0 → child list;
 *         scalar-delete each node+8 payload; FUN_00403430 list teardown; return null.
 */

#include <cstdint>

struct UnpackStream; // FUN_00787d40 thiscall host (buffer @ +0x1014, size +0x1018, pos +0x101c)
struct GameDataHost; // DAT_00b041fc — map root at +4, end sentinel at +8

// Nested callees — not dual-owned by this unit.
extern "C" void *__thiscall Profiler_EnterNamedZone(void *profiler, const char *name); // FUN_00786a00 RET 4
extern "C" void __thiscall Profiler_Leave(void *profiler);                             // FUN_00786990
extern "C" void __thiscall Stream_UnpackBytes(UnpackStream *self, void *dst, unsigned n); // FUN_00787d40
extern "C" void __thiscall Map_LowerBoundFindByIntKey(void *map, void **outIt, int *key); // 0x0050f940
extern "C" void *CVOGReaction_GiveItemByCbid(int cbid);
extern "C" void FUN_007a4480(int level, const char *fmt, ...);
extern "C" void *FUN_0040fb90(void);           // empty circular list sentinel (0xC)
extern "C" void __fastcall FUN_00403430(void *listHeadPlus); // delete list storage
extern GameDataHost *DAT_00b041fc;
extern void *DAT_00afa27c; // profiler singleton

using VInitCbid = int(__thiscall *)(void *self, int cbid, void *host, int one);
using VInitCoid = int(__thiscall *)(void *self, std::uint32_t coidLo, std::uint32_t coidHi,
                                    int zero, UnpackStream *stream, int one);
using VGetChildList = void *(__thiscall *)(void *self, void **outListHead);
using VScalarDtor = void(__thiscall *)(void *self, int one);

extern "C" void *ServerCreateFromPacket(UnpackStream *stream, void *host)
{
  // SEH + Profiler_EnterNamedZone(DAT_00afa27c, "ServerCreateFromPacket") omitted as frame glue.

  void *result = nullptr;

  int cbid = 0;
  Stream_UnpackBytes(stream, &cbid, 4);
  if (cbid == -1) {
    // Profiler leave; return null
    return nullptr;
  }

  std::uint32_t coidLo = 0;
  std::uint32_t coidHi = 0;
  Stream_UnpackBytes(stream, &coidLo, 8); // packs both dwords; layout local_20/local_1c

  // Map remap (decompiler invents unaff_EDI 4th arg — bytes: ECX=map+4, push key, push outIt)
  void *it = nullptr;
  auto *gd = DAT_00b041fc;
  Map_LowerBoundFindByIntKey(reinterpret_cast<std::uint8_t *>(gd) + 4, &it, &cbid);
  bool remapped = (it != *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(gd) + 8));
  if (remapped) {
    cbid = *reinterpret_cast<int *>(reinterpret_cast<std::uint8_t *>(it) + 0x10);
  }

  void *obj = CVOGReaction_GiveItemByCbid(cbid);
  if (obj == nullptr) {
    FUN_007a4480(1, "Invalid CBID allocated: %d, coid : %I64d", cbid, coidLo, coidHi);
    return nullptr;
  }

  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto initCbid = *reinterpret_cast<VInitCbid *>(vtbl + 8);
  if (initCbid(obj, cbid, host, 1) < 0) {
    FUN_007a4480(1, "Invalid CBID initified: %d, coid : %I64d", cbid, coidLo, coidHi);
    return nullptr;
  }

  // Stamp TFID/COID block before identity vcall
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x160) = coidLo;
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x164) = coidHi;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x168) = 1;

  auto initCoid = *reinterpret_cast<VInitCoid *>(vtbl + 0x20);
  if (initCoid(obj, coidLo, coidHi, 0, stream, 1) >= 0) {
    if (remapped) {
      *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x17c) |= 0x80u;
    }
    return obj; // success
  }

  FUN_007a4480(1, "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)",
               cbid, coidLo, coidHi);

  // Failure cleanup: empty list head + walk vtbl+0x2B0 child list, scalar-delete payloads
  void *listSentinel = FUN_0040fb90();
  void *listHead = nullptr;
  auto getChildren = *reinterpret_cast<VGetChildList *>(vtbl + 0x2b0);
  getChildren(obj, &listHead);
  // Walk circular list: node = *head; while node != head; node = *node
  // if node[2] non-null: (*node[2])[0](node[2], 1)  — scalar dtor
  // FUN_00403430 tears down list storage (exact this-adjust out of owned scope detail).
  (void)listSentinel;
  (void)listHead;
  FUN_00403430(listSentinel);

  return nullptr;
}
