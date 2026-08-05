// =============================================================================
// Map_Tree_Predecessor_Isnil15  (was FUN_005a2850)
// Address:  0x005a2850  Stable: aa_005a2850
// Dual: reviews/A|B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md
// =============================================================================

// void __fastcall Map_Tree_Predecessor_Isnil15(Node** pIt)
// RET (C3) — no stack cleanup
// Node: left@0 parent@4 right@8 isnil@0x15
extern "C" void __fastcall Map_Tree_Predecessor_Isnil15(int* pIt)
{
  int* cur = (int*)*pIt;
  if (*(char*)((int)cur + 0x15) != '\0') {
    *pIt = cur[2];
    return;
  }
  int left = *cur;
  if (*(char*)(left + 0x15) == '\0') {
    int n = left;
    int r = *(int*)(left + 8);
    while (*(char*)(r + 0x15) == '\0') {
      n = r;
      r = *(int*)(r + 8);
    }
    *pIt = n;
    return;
  }
  int* parent = (int*)cur[1];
  if (*(char*)((int)parent + 0x15) == '\0') {
    do {
      if (*pIt != *parent) break;
      *pIt = (int)parent;
      parent = (int*)parent[1];
    } while (*(char*)((int)parent + 0x15) == '\0');
    if (*(char*)((int)parent + 0x15) == '\0') {
      *pIt = (int)parent;
    }
  }
}
