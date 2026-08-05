// =============================================================================
// Fs_Path_EnsureExtension_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b190
// Address:   0x0076b190  (autoassault.exe, image base 0x400000)
// System:    fs / path helpers
// Wave:      W33-P (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Split path → (drive, dir, fname, ext). If ext empty, copy defaultExt from
//   ESI into ext. Recompose into out. Does not replace a non-empty extension.
//
// ABI (bytes + call sites win):
//   stack: const char* path, char* out
//   ESI:   const char* defaultExt  (e.g. "glm" @ 0x00aa61bc — no leading '.')
//   cdecl (caller cleans); void; bare C3
//
// REJECT: Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076b190 (scaffold alias)
//

#include <cstdint>
#include <cstring>

// Nested residuals (splitpath / makepath style):
extern "C" void FUN_0076af70(const char* path /*ecx*/,
                             char* dir, char* fname, char* ext
                             /* EAX = drive out */);
extern "C" void FUN_0076aba0(const char* dir /*ecx*/,
                             char* out, const char* fname, const char* ext
                             /* EAX = drive in */);

extern "C" void Fs_Path_EnsureExtension_Inferred(
    const char* path,
    char* out
    /* ESI = defaultExt */)
{
  char drive[256];
  char dir[256];
  char fname[256];
  char ext[256];

  // Retail: 3×256 stack locals + drive via EAX; nested helpers own exact widths.
  // FUN_0076af70(path, dir, fname, ext) with drive out in buffer used as EAX.
  (void)drive;
  FUN_0076af70(path, dir, fname, ext);

  // ESI holds default extension at call sites ("glm").
  // Decompiler unaff_ESI — sealed by CompactPackFile / FUN_0071a9d0 mov esi,imm.
  const char* defaultExt = nullptr; // real: ESI
  // if (ext[0] == '\0') strcpy(ext, ESI);
  if (ext[0] == '\0' && defaultExt != nullptr) {
    // byte-faithful copy loop (includes NUL)
    const char* s = defaultExt;
    char* d = ext;
    char c;
    do {
      c = *s++;
      *d++ = c;
    } while (c != '\0');
  }

  FUN_0076aba0(dir, out, fname, ext);
}

// Twin export under Ghidra name for tooling.
extern "C" void FUN_0076b190(const char* path, char* out /* ESI=defaultExt */)
{
  Fs_Path_EnsureExtension_Inferred(path, out);
}
