// =============================================================================
// FUN_0051b350  (canonical: ServerCreateFromPacket)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b350
// Address:   0x0051b350–0x0051b54e  (autoassault.exe, image base 0x400000)
// System:    object-spawn / network create (client)
// Generated: 2026-07-23 scaffold; **re-sealed 2026-08-04** dual A/B WQ9R-I
// Exactness: Twin of ServerCreateFromPacket.cpp — traps corrected (unaff_EDI,
//            unpack thiscall, COID +0x160).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// Embedded strings:
//   - "ServerCreateFromPacket"
//   - "Invalid CBID allocated: %d, coid : %I64d"
//   - "Invalid CBID initified: %d, coid : %I64d"
//   - "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)"
// =============================================================================

// See ServerCreateFromPacket.cpp for full sealed behavioral notes.
// This twin keeps the Ghidra symbol as the entry symbol for scaffold paths.

#include <cstdint>

extern "C" void *__thiscall FUN_00786a00(void *profiler, const char *name);
extern "C" void __thiscall FUN_00786990(void *profiler);
extern "C" void __thiscall FUN_00787d40(void *stream, void *dst, unsigned n);
extern "C" void __thiscall Map_LowerBoundFindByIntKey(void *map, void **outIt, int *key);
extern "C" void *CVOGReaction_GiveItemByCbid(int cbid);
extern "C" void FUN_007a4480(int level, const char *fmt, ...);
extern "C" void *FUN_0040fb90(void);
extern "C" void __fastcall FUN_00403430(void *p);
extern void *DAT_00b041fc;
extern void *DAT_00afa27c;

using VInitCbid = int(__thiscall *)(void *self, int cbid, void *host, int one);
using VInitCoid = int(__thiscall *)(void *self, std::uint32_t lo, std::uint32_t hi,
                                    int zero, void *stream, int one);
using VGetChildList = void *(__thiscall *)(void *self, void **outListHead);
using VScalarDtor = void(__thiscall *)(void *self, int one);

extern "C" void *FUN_0051b350(void *param_1 /* stream */, void *param_2 /* host */)
{
  FUN_00786a00(DAT_00afa27c, "ServerCreateFromPacket");

  void *result = nullptr;
  int cbid = 0;
  FUN_00787d40(param_1, &cbid, 4);
  if (cbid == -1) {
    FUN_00786990(DAT_00afa27c);
    return nullptr;
  }

  std::uint32_t coidLo = 0, coidHi = 0;
  FUN_00787d40(param_1, &coidLo, 8);

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
    FUN_00786990(DAT_00afa27c);
    return nullptr;
  }

  auto *vtbl = *reinterpret_cast<std::uint8_t **>(obj);
  auto initCbid = *reinterpret_cast<VInitCbid *>(vtbl + 8);
  if (initCbid(obj, cbid, param_2, 1) < 0) {
    FUN_007a4480(1, "Invalid CBID initified: %d, coid : %I64d", cbid, coidLo, coidHi);
    FUN_00786990(DAT_00afa27c);
    return nullptr;
  }

  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x160) = coidLo;
  *reinterpret_cast<std::uint32_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x164) = coidHi;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x168) = 1;

  auto initCoid = *reinterpret_cast<VInitCoid *>(vtbl + 0x20);
  if (initCoid(obj, coidLo, coidHi, 0, param_1, 1) >= 0) {
    if (remapped) {
      *reinterpret_cast<std::uint8_t *>(reinterpret_cast<std::uint8_t *>(obj) + 0x17c) |= 0x80u;
    }
    result = obj;
    FUN_00786990(DAT_00afa27c);
    return result;
  }

  FUN_007a4480(1, "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)",
               cbid, coidLo, coidHi);

  void *listSentinel = FUN_0040fb90();
  void *listHead = nullptr;
  auto getChildren = *reinterpret_cast<VGetChildList *>(vtbl + 0x2b0);
  getChildren(obj, &listHead);
  if (listHead != nullptr) {
    void *node = *reinterpret_cast<void **>(listHead);
    void *head = listHead;
    while (node != head) {
      void *payload = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(node) + 8);
      if (payload != nullptr) {
        auto dtor = *reinterpret_cast<VScalarDtor *>(*reinterpret_cast<void ***>(payload));
        dtor(payload, 1);
      }
      node = *reinterpret_cast<void **>(node);
    }
  }
  FUN_00403430(listSentinel);

  FUN_00786990(DAT_00afa27c);
  return nullptr;
}
