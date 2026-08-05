// =============================================================================
// FxCache_ApplyWithNfxEnsure
// -----------------------------------------------------------------------------
// Stable ID: aa_00542790
// Address:   0x00542790  (autoassault.exe, image base 0x400000)
// System:    client-fx / skills-abilities
// Generated: 2026-07-29 W20-I dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Full skill/FX apply path when the resource subsystem is live:
//   gate DAT_00d1f050+0x6c, lookup cache key in host+0xf0c, ensure nfx master
//   (SkillDef name + "_nfx.xml" + LoadMasterFromXML), open resource, resolve FX
//   via FUN_004a16d0, then call target entity vtbl[+0x238] — or transform
//   fallback FUN_00545d70. Returns 1 on success, 0 on fail.
//
// ABI: __thiscall — ECX = host*; 7 stack args; ret 0x1c.
// Body: 00542790–00542a8c (764 bytes), MSVC SEH.
//
// SIBLING: FxCache_EnsureMasterAndResolve (0x005408f0) — lighter ensure+resolve.
//
// SEALED: ret 0x1c; gate; _nfx.xml @ 009ca184; default pose @ 009d00a8; live≡raw.
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void* ExceptionList;
extern "C" uint8_t* DAT_00d1f050;
extern "C" uint32_t DAT_009d00a8[4];
extern "C" uint32_t DAT_009ca184; // "_nfx" dwords into "_nfx.xml"
extern "C" uint32_t DAT_009ca188;
extern "C" uint8_t  DAT_009ca18c;

extern "C" void* CNDHash_LookupByKey(void* hash, uint32_t key);
extern "C" uint32_t FUN_0054b480(void); // SkillDefMap_GetGlobal
extern "C" void FUN_00418890(void* outIt, uint32_t* pKey);
extern "C" void FUN_00540090(void* nameSrc, char* dst, uint32_t cap);
extern "C" void FUN_00989e00(void* a, char* path);
extern "C" void FUN_0043d670(void* a);
extern "C" char FUN_004ed310(void* a, void* b, void* c);
extern "C" uint32_t FUN_004a6390(char* scriptBaseName); // FxMaster_LoadMasterFromXML
extern "C" void FUN_00971820(void* a);
extern "C" void FUN_0043d650(int a);
extern "C" void FUN_004a04f0(void* a, int b, int c, int d);
extern "C" int FUN_004a16d0(uint32_t eventId, int mode, int slotOrFlags);
extern "C" void FUN_00545d70(void* transform4);
extern "C" void FUN_005b2ba0(void); // SEH / frame helper

// SEH registration label (image)
extern "C" void LAB_009a40df(void);

uint32_t __thiscall FxCache_ApplyWithNfxEnsure(
    int host,
    uint32_t key,
    uint32_t eventId,
    uint32_t argA,
    uint32_t argB,
    int sourceObj,
    int* targetEntity,
    uint32_t argC)
{
  int* savedTarget = targetEntity;
  void* sehNext = ExceptionList;
  void* sehHandler = reinterpret_cast<void*>(&LAB_009a40df);

  // Gate: resource/FX subsystem
  if (*reinterpret_cast<int*>(DAT_00d1f050 + 0x6c) == 0) {
    return 0;
  }

  uint32_t zeroPad[4] = {0, 0, 0, 0};
  (void)zeroPad;
  uint32_t local_event = eventId;
  uint32_t local_key = key;
  uint32_t local_argA = argA;
  uint32_t local_argB = argB;
  uint32_t local_argC = argC;
  uint8_t local_414 = 0;
  uint8_t local_42c[4] = {0, 0, 0, 0};
  uint32_t local_430 = 0;
  uint8_t local_428[4];

  // Transform snapshot from source (+0x160) or default DAT_009d00a8
  uint32_t* pSrcXform = (sourceObj == 0)
                            ? DAT_009d00a8
                            : reinterpret_cast<uint32_t*>(sourceObj + 0x160);
  uint32_t snapA[4] = {pSrcXform[0], pSrcXform[1], pSrcXform[2], pSrcXform[3]};

  // Target entity transform at +0x160 (param_7 + 0x58 dwords) or default
  int* pTgtXform = (targetEntity == nullptr)
                       ? reinterpret_cast<int*>(DAT_009d00a8)
                       : (targetEntity + 0x58);
  int snapB[4] = {pTgtXform[0], pTgtXform[1], pTgtXform[2], pTgtXform[3]};
  (void)snapB;

  ExceptionList = &sehNext;
  (void)sehHandler;
  (void)host;

  void* value = CNDHash_LookupByKey(
      *reinterpret_cast<void**>(host + 0xf0c), key);
  if (value == nullptr) {
    goto fail;
  }

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(value) + 10) == '\0') {
    int it = 0;
    uint32_t keyCopy = key;
    (void)FUN_0054b480();
    FUN_00418890(&it, &keyCopy);
    auto* map = reinterpret_cast<uint8_t*>(FUN_0054b480());
    if (it == *reinterpret_cast<int*>(map + 4)) {
      goto fail;
    }

    // Path buffer: skill name then append "_nfx.xml"
    alignas(4) char pathBuf[0x410];
    std::memset(pathBuf, 0, sizeof(pathBuf));
    FUN_00540090(reinterpret_cast<void*>(it + 0x10), pathBuf, 0x400);

    char* end = pathBuf;
    while (*end != '\0') {
      ++end;
    }
    *reinterpret_cast<uint32_t*>(end) = DAT_009ca184;
    *reinterpret_cast<uint32_t*>(end + 4) = DAT_009ca188;
    *reinterpret_cast<uint8_t*>(end + 8) = DAT_009ca18c;

    int pathState = it; // decompiler reuses local_46c
    FUN_00989e00(&pathState, pathBuf);
    FUN_0043d670(&pathState);

    char opened = FUN_004ed310(local_428, local_42c, &local_430);
    if (opened != '\0') {
      char* nfx = std::strstr(pathBuf, "_nfx.xml");
      if (nfx != nullptr) {
        *nfx = '\0';
        FUN_004a6390(pathBuf);
      }
      goto ready;
    }
    FUN_00971820(local_428);
    local_414 = 1;
    (void)local_414;
  } else {
  ready:
    FUN_0043d650(0);
    local_42c[0] = 0;
    local_430 = 0;
    FUN_004a04f0(local_428, 1, 1, 1);
    char opened2 = FUN_004ed310(local_428, local_42c, &local_430);
    if (opened2 != '\0') {
      int fx = FUN_004a16d0(local_event, 1, -1);
      if (fx == 0 || savedTarget == nullptr) {
        goto fail;
      }
      // targetEntity->vtbl[+0x238](event, key, argA, argB, source, argC, 1, fx)
      using VFn = void(__thiscall*)(int*, uint32_t, uint32_t, uint32_t, uint32_t,
                                    int, uint32_t, int, int);
      auto** vtbl = reinterpret_cast<void***>(savedTarget);
      auto fn = reinterpret_cast<VFn>((*vtbl)[0x238 / 4]);
      fn(savedTarget, local_event, local_key, local_argA, local_argB, sourceObj,
         local_argC, 1, fx);
      goto success;
    }
    FUN_00971820(local_428);
  }

  FUN_00545d70(snapA);

success:
  FUN_005b2ba0();
  ExceptionList = sehNext;
  return 1;

fail:
  FUN_005b2ba0();
  ExceptionList = sehNext;
  return 0;
}
