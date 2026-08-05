// Named alias for aa_007b6420 — prefer Path_GetFileName.cpp
#include <cstring>

char *Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvInvento_007b6420(char *path)
{
  char *bs = std::strrchr(path, '\\');
  char *sl = std::strrchr(path, '/');
  if (bs == nullptr) {
    if (sl == nullptr) return path;
  } else if (sl < bs) {
    sl = bs;
  }
  return sl + 1;
}
