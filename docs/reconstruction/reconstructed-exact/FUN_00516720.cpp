// =============================================================================
// FUN_00516720  — twin of Object_SetDisplayName_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00516720
// Address:   0x00516720 – 0x00516899 exclusive  (377 B / 0x179)
// Module:    autoassault.exe  (image base 0x400000)
// System:    object-identity / display-name
// Generated: 2026-08-05 R10-031 OWN dual (live Ghidra seal)
// Canonical: Object_SetDisplayName_Inferred
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// See Object_SetDisplayName_Inferred.cpp for full plate, ABI, and contract.
// This twin keeps the Ghidra inventory name as a link target.
//
// ABI: __thiscall; ECX=object*; stack char* nameOrNull; RET 4; void.
// Field: *(this+0x158) owned display-name string.
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void operator_delete[](void *p);
extern "C" void *operator_new[](unsigned size);
extern "C" void *FUN_004ce940(void);
extern "C" void *FUN_007a69d0();
extern "C" std::uint32_t FUN_007a6880(void *localeObj);
extern "C" void FUN_005146a0(void *self, char *name, std::uint32_t locale,
                             int cap, char *outBuf);
extern "C" void *FUN_004eb240(void *descriptor);
extern "C" void FUN_00403450(void *mbOut, const wchar_t *wide, unsigned cp);
extern "C" int strncmp(const char *a, const char *b, size_t n);
extern "C" void free(void *p);
extern "C" void * (*PTR_FUN_00af8c9c)(void);

// Ghidra inventory name — same body as Object_SetDisplayName_Inferred.
void __thiscall FUN_00516720(void *self, char *nameOrNull)
{
  auto *obj = reinterpret_cast<std::uint8_t *>(self);
  auto **vtbl = *reinterpret_cast<void ***>(obj);
  auto &nameField = *reinterpret_cast<char **>(obj + 0x158);
  auto *hostAtA4 = *reinterpret_cast<void **>(obj + 0xA4);
  auto *descAtA8 = *reinterpret_cast<void **>(obj + 0xA8);

  if (nameOrNull == nullptr) {
    return;
  }

  if (nameField != nullptr) {
    operator_delete[](nameField);
  }
  nameField = nullptr;

  const char *scan = nameOrNull;
  while (*scan != '\0') {
    ++scan;
  }
  const unsigned nameLen = static_cast<unsigned>(scan - nameOrNull);

  using Vtbl60_t = int(__thiscall *)(void *);
  const int gateCount = reinterpret_cast<Vtbl60_t>(vtbl[0x60 / 4])(self);

  if (gateCount != 0 && hostAtA4 != nullptr && FUN_004ce940() != nullptr) {
    alignas(4) char composeBuf[128 + 4];
    char *outPtr = composeBuf;
    std::uint32_t locale = FUN_007a6880(FUN_007a69d0());
    FUN_005146a0(self, nameOrNull, locale, 0x5A, outPtr);

    const char *cscan = outPtr;
    while (*cscan != '\0') {
      ++cscan;
    }
    const unsigned composedLen = static_cast<unsigned>(cscan - outPtr);
    char *dst = static_cast<char *>(operator_new[](composedLen + 1));
    nameField = dst;
    const char *src = outPtr;
    char ch;
    do {
      ch = *src++;
      *dst++ = ch;
    } while (ch != '\0');
    return;
  }

  void *defaultSrc = FUN_004eb240(descAtA8);
  (void)defaultSrc;

  char stackMb[128];
  char *mbPtr = stackMb;
  void *wideOrStr = PTR_FUN_00af8c9c();
  FUN_00403450(&mbPtr, static_cast<const wchar_t *>(wideOrStr), 0);

  char *defaultMb = mbPtr;
  int cmp = strncmp(nameOrNull, defaultMb, 0x41);
  bool storeCustom = false;
  if (cmp != 0 && nameLen > 1) {
    storeCustom = true;
  }

  if (mbPtr != stackMb) {
    free(mbPtr);
  }

  if (storeCustom) {
    char *dst = static_cast<char *>(operator_new[](nameLen + 1));
    nameField = dst;
    const char *src = nameOrNull;
    char ch;
    do {
      ch = *src++;
      *dst++ = ch;
    } while (ch != '\0');
  }
}
