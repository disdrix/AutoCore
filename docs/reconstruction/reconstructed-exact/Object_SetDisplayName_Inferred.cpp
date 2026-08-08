// =============================================================================
// Object_SetDisplayName_Inferred  (Ghidra: FUN_00516720)
// -----------------------------------------------------------------------------
// Stable ID: aa_00516720
// Address:   0x00516720 – 0x00516899 exclusive  (377 B / 0x179)
// Module:    autoassault.exe  (image base 0x400000)
// System:    object-identity / display-name
//            (R10-031 partition parent 0x0051b230 skills-abilities residual)
// Generated: 2026-08-05 R10-031 OWN dual (live Ghidra seal)
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Assign the owned display-name string at object+0x158 from an input name.
//   Prefer a composed display name (mods / prefixes / [$swap]) when the object
//   reports a non-zero vtbl+0x60 count, has a host at +0xA4, and the name
//   manager singleton is live. Otherwise store the input only when it differs
//   from the template default and is longer than one character; else leave
//   +0x158 NULL so UI falls back to the template name.
//
// ABI (sealed):
//   __thiscall
//   ECX     = object*  (self)
//   [ESP+4] = char*    nameOrNull
//   return  = void
//   epilogue RET 4
//
// CONTRACT NOTES:
//   - nameOrNull == NULL → immediate return; does NOT free/clear +0x158.
//   - Non-null always frees prior +0x158 first, then may re-store.
//   - Compose path uses FUN_005146a0 with cap 0x5A (90).
//   - Fallback compares with strncmp(..., 0x41) against template default.
//   - Fallback alloc size uses entry strlen saved at [ESP+0x0C] (assembly),
//     not the decompiler's reused pcVar3 expression.
//
// CALLEES:
//   operator_delete[] / operator_new[]
//   vtbl+0x60
//   FUN_004ce940, FUN_007a69d0, FUN_007a6880, FUN_005146a0
//   FUN_004eb240, PTR_FUN_00af8c9c (wide helper), FUN_00403450
//   strncmp, free
// =============================================================================

#include <cstdint>
#include <cstring>

// External symbols (Ghidra names preserved where product English open).
extern "C" void operator_delete[](void *p);
extern "C" void *operator_new[](unsigned size);
extern "C" void *FUN_004ce940(void);
extern "C" void *FUN_007a69d0(/* locale setup args as used at site */);
extern "C" std::uint32_t FUN_007a6880(void *localeObj);
extern "C" void FUN_005146a0(void *self, char *name, std::uint32_t locale,
                             int cap, char *outBuf);
extern "C" void *FUN_004eb240(void *descriptor /* this from +0xA8 */);
extern "C" void FUN_00403450(void *mbOut /*CString-like*/,
                             const wchar_t *wide, unsigned codePage);
extern "C" int strncmp(const char *a, const char *b, size_t n);
extern "C" void free(void *p);

// Indirect: OS-selected wide-string getter (IAT-style pointer @ 0x00af8c9c).
extern "C" void * (*PTR_FUN_00af8c9c)(void);

// Object layout fragments used here (not a full type).
//   +0x00  vtbl*
//   +0xA4  host / owner gate (void*)
//   +0xA8  template / descriptor (void*)
//   +0x158 owned display-name char* (heap)

void __thiscall Object_SetDisplayName_Inferred(void *self, char *nameOrNull)
{
  auto *obj = reinterpret_cast<std::uint8_t *>(self);
  auto **vtbl = *reinterpret_cast<void ***>(obj);
  auto &nameField = *reinterpret_cast<char **>(obj + 0x158);
  auto *hostAtA4 = *reinterpret_cast<void **>(obj + 0xA4);
  auto *descAtA8 = *reinterpret_cast<void **>(obj + 0xA8);

  // 1) Null name: no-op (preserve existing +0x158).
  if (nameOrNull == nullptr) {
    return;
  }

  // 2) Drop prior owned string.
  if (nameField != nullptr) {
    operator_delete[](nameField);
  }
  nameField = nullptr;

  // 3) Entry strlen (assembly stores at [ESP+0x0C] for fallback alloc).
  const char *scan = nameOrNull;
  while (*scan != '\0') {
    ++scan;
  }
  const unsigned nameLen = static_cast<unsigned>(scan - nameOrNull);

  // 4) Compose path gate: vtbl+0x60, host +0xA4, name manager.
  using Vtbl60_t = int(__thiscall *)(void *);
  const int gateCount = reinterpret_cast<Vtbl60_t>(vtbl[0x60 / 4])(self);

  if (gateCount != 0 && hostAtA4 != nullptr && FUN_004ce940() != nullptr) {
    // Stack compose buffer: decompiler shows uStack_84 + acStack_80[128];
    // site pushes cap 0x5A into FUN_007a69d0 / FUN_005146a0.
    alignas(4) char composeBuf[128 + 4];
    char *outPtr = composeBuf;

    FUN_007a69d0(/* cap/setup as at 0x0051677A: PUSH 0x5A */);
    // Live site sequence: PUSH &buf; PUSH 0x5A; CALL FUN_007a69d0;
    // MOV ECX,EAX; CALL FUN_007a6880; PUSH EAX; PUSH name; MOV ECX,self;
    // CALL FUN_005146a0
    // Represented here with the sealed arity from site + callee decompile:
    std::uint32_t locale = FUN_007a6880(FUN_007a69d0());
    FUN_005146a0(self, nameOrNull, locale, 0x5A, outPtr);

    // strlen(composeBuf) + 1 → operator_new[] → copy including NUL.
    const char *cscan = outPtr;
    while (*cscan != '\0') {
      ++cscan;
    }
    const unsigned composedLen =
        static_cast<unsigned>(cscan - outPtr);
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

  // 5) Fallback: template default vs custom.
  // FUN_004eb240(this = *(self+0xA8)) → default name source (often wide).
  void *defaultSrc = FUN_004eb240(descAtA8);

  // SSO-style MB buffer (acStack_80[128]); pointer field uStack_84 starts as
  // stack base; may promote to malloc inside FUN_00403450 when size > 0x80.
  char stackMb[128];
  char *mbPtr = stackMb;
  void *wideOrStr = PTR_FUN_00af8c9c();
  FUN_00403450(&mbPtr /* out CString-like holding char* */,
               static_cast<const wchar_t *>(wideOrStr),
               /* code page from site */ 0);

  // Site always compares against converted default held at uStack_84.
  // Reconstruct: after FUN_00403450, mb pointer is in the CString slot.
  // Decompiler: strncmp(param_2, uStack_84, 0x41)
  char *defaultMb = mbPtr; // simplified; live uses CString *slot
  (void)defaultSrc;        // feeds wide path via PTR_FUN in image order

  int cmp = strncmp(nameOrNull, defaultMb, 0x41);
  bool storeCustom = false;
  if (cmp != 0) {
    if (nameLen > 1) {
      storeCustom = true;
    }
  }

  if (mbPtr != stackMb) {
    free(mbPtr);
  }

  if (storeCustom) {
    // Assembly: size = saved nameLen + 1 from [ESP+0x0C]
    char *dst = static_cast<char *>(operator_new[](nameLen + 1));
    nameField = dst;
    const char *src = nameOrNull;
    char ch;
    do {
      ch = *src++;
      *dst++ = ch;
    } while (ch != '\0');
  }

  return;
}
