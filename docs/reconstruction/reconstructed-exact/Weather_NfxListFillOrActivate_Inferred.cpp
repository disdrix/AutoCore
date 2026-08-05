// =============================================================================
// Weather_NfxListFillOrActivate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00556b10
// Address:   0x00556b10–0x00556ce2  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00556b10
// System:    client weather / NDSpecialFX nfx
// Dual:      W32-I 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = weather host; stack (outList*, weatherObj*, mode); RET 0xC.
// Clears outList, then either:
//   mode==0: resolve weather/TOD script names, ensure "_nfx.xml", push resource ids
//   mode!=0: activate/load weather FX paths via FUN_004b88e0 / FUN_00553d20
// Caller FUN_005575c0: host+0x190 mode0, host+0x1a4 mode1.
// Name inferred from _nfx.xml + weather FX load string on sibling FUN_00553d20.
// =============================================================================

#include <cstdint>
#include <cstring>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;
  uint32_t capacity;
  int32_t  begin;
  int32_t  size;
};

// Clear / resize-to-0 wrapper (FUN_0043d650 → FUN_0043d940).
extern "C" void FUN_0043d650(GuardedVectorHeader* list /*ECX*/, uint32_t newSize);

// W31-I: ECX=container; stack value*; RET 4.
extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* c /*ECX*/,
                                                const uint32_t* value);

// Name resolvers (unowned).
extern "C" char FUN_00555660(void* table /*ECX*/, int index, char* outName);
extern "C" char FUN_00553ce0(void* host /*ECX*/, uint32_t slot, char* outName);
extern "C" int  FUN_00555600(void* table /*ECX*/, int index);
extern "C" void* FUN_00553d20(char* nameSlot /*ECX*/, char freeOld);

// Resource open / resolve (unowned).
extern "C" void* FUN_007b6a20(void);
extern "C" char  FUN_007b6730(void* /*fastcall*/, char* path, uint32_t mask);
extern "C" void  FUN_00989e00(void* cache /*ECX*/, uint32_t* outId, char* path);

// Apply collector (unowned; large).
extern "C" void FUN_004b88e0(void* host /*ECX*/, uint32_t a, char b, char c, char d);

// DAT_009ca184
static const char kNfxXmlSuffix[] = "_nfx.xml";

static void AppendNfxSuffixIfMissing(char* pathWork /*inout, NUL-terminated*/)
{
  if (std::strstr(pathWork, kNfxXmlSuffix) != nullptr) {
    return;
  }
  // Retail: walk to NUL then write 9-byte DAT_009ca184 block (8 chars + NUL).
  char* p = pathWork;
  while (*p != '\0') {
    ++p;
  }
  // memcpy of dword/dword/byte as in body.
  *reinterpret_cast<uint32_t*>(p) = 0x78666e5fu;       // "_nfx" LE
  *reinterpret_cast<uint32_t*>(p + 4) = 0x6c6d782eu;   // ".xml" LE
  p[8] = '\0';
}

static void TryPushResolvedNfx(GuardedVectorHeader* list, char* nameBuf, void* resolveHost)
{
  AppendNfxSuffixIfMissing(nameBuf);
  // Retail: FUN_007b6a20(); FUN_007b6730(path, 0xffffffff)
  void* mgr = FUN_007b6a20();
  (void)mgr;
  if (FUN_007b6730(nullptr, nameBuf, 0xffffffffu) != 0) {
    uint32_t id = 0;
    FUN_00989e00(resolveHost, &id, nameBuf);
    GuardedVector_PushBack_Thiscall(list, &id);
  }
}

void Weather_NfxListFillOrActivate_Inferred(
    void* weatherHost /*ECX*/,
    GuardedVectorHeader* outList,
    void* weatherObj,
    char mode)
{
  FUN_0043d650(outList, 0);

  if (weatherObj == nullptr) {
    return;
  }

  char nameBuf[260];

  if (mode == 0) {
    // Fill path: weather profile name @ weather+0x558 index family.
    const int weatherNameIndex =
        *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(weatherObj) + 0x558);
    if (FUN_00555660(weatherObj, weatherNameIndex, nameBuf) != 0) {
      TryPushResolvedNfx(outList, nameBuf, weatherHost);
    }

    // TOD / env-time slot name (host field family +0x150).
    const int todIndex =
        *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(weatherHost) + 0x150);
    if (FUN_00553ce0(weatherHost, static_cast<uint32_t>(todIndex), nameBuf) != 0) {
      TryPushResolvedNfx(outList, nameBuf, weatherHost);
    }
    return;
  }

  // Activate path.
  const int weatherNameIndex =
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(weatherObj) + 0x558);
  if (FUN_00555600(weatherObj, weatherNameIndex) != 0) {
    FUN_004b88e0(outList, 1, 0, 0, 0);
  }

  const int todIndex =
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(weatherHost) + 0x150);
  if (todIndex >= 0 && todIndex < 4) {
    // FUN_00553d20 loads NDSpecialFX ("Failed to load weather FX: %s" on miss).
    if (FUN_00553d20(reinterpret_cast<char*>(weatherHost), 0) != nullptr) {
      FUN_004b88e0(outList, 1, 0, 0, 0);
      return;
    }
  }
}
