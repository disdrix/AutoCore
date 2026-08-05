// =============================================================================
// Path_GetFileName — named clean plate
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6420
// Address:   0x007b6420 – 0x007b644f
// See FUN_007b6420.cpp for dual-seal notes.
// =============================================================================

#include <cstring>

char *Path_GetFileName(char *path)
{
  char *bs = std::strrchr(path, '\\');
  char *sl = std::strrchr(path, '/');

  if (bs == nullptr) {
    if (sl == nullptr) {
      return path;
    }
    return sl + 1;
  }
  if (sl == nullptr || sl < bs) {
    return bs + 1;
  }
  return sl + 1;
}
