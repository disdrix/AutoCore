// =============================================================================
// MissionStagingTree_EraseRange
// -----------------------------------------------------------------------------
// Purpose:  MSVC ordered-map range erase [first, last) for the mission staging
//           tree. Full-range fast path destroys the whole tree; otherwise walks
//           successors and erases node-by-node.
//
// Address:  0x00539150  (autoassault.exe, image base 0x400000)
// Body:     0x00539150-0x00539203 (exclusive end; ret 0xc)
// Stable:   aa_00539150
// System:   missions-progression
// Ghidra:   FUN_00539150
// Canonical: MissionStagingTree_EraseRange (Inferred — peers DestroySubtree /
//            EraseNode; product English open)
//
// ABI:      void __thiscall (Map* this, Node** outIter, Node* first, Node* last)
//           ECX = map; ret 0xc
//
// Callees:  FUN_00537ef0 (MissionStagingTree_DestroySubtree)
//           FUN_00538780 (MissionStagingTree_EraseNode)
// Callers:  FUN_0053ae70 (map clear+free header @ 0x0053ae82)
//           char dtor fragment @ 0x0052f607 (map @ char+0x508)
//
// Exactness: CF mirrors live decompile + entry/epilogue read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-L).
// =============================================================================

#include <stdint.h>

/* Node: MSVC _Tree node (nil flag at +0x49). Link polarity Probable. */
typedef struct StagingNode {
  struct StagingNode *link0; /* +0x00 */
  struct StagingNode *link1; /* +0x04 */
  struct StagingNode *link2; /* +0x08 */
  /* ... payload ... */
  /* char color; char isnil @ +0x49 */
} StagingNode;

typedef struct StagingMap {
  /* +0x00 unused / pad in this unit */
  StagingNode *header; /* +0x04 */
  uint32_t size;       /* +0x08 */
} StagingMap;

void FUN_00537ef0(void *node);                   /* DestroySubtree */
void FUN_00538780(void *outScratch, void *node); /* EraseNode */

void __thiscall MissionStagingTree_EraseRange(
    StagingMap *map,
    StagingNode **outIter,
    StagingNode *first,
    StagingNode *last)
{
  StagingNode *header = map->header;
  StagingNode *cur = first;
  StagingNode *end = last;

  /* Full clear: [begin, end) == [leftmost, header] */
  if (first == *(StagingNode **)header && last == header) {
    FUN_00537ef0(((void **)header)[1]);
    /* reset header self-links + size */
    *(StagingNode **)((char *)map->header + 4) = map->header;
    map->size = 0;
    *(StagingNode **)map->header = map->header;
    *(StagingNode **)((char *)map->header + 8) = map->header;
    *outIter = *(StagingNode **)map->header;
    return;
  }

  while (cur != end) {
    StagingNode *succ = cur;
    /* successor when cur is a real node (isnil at +0x49 == 0) */
    if (*(char *)((char *)cur + 0x49) == 0) {
      succ = ((StagingNode **)cur)[2];
      if (*(char *)((char *)succ + 0x49) == 0) {
        char c = *(char *)((char *)*(void **)succ + 0x49);
        void *p = *(void **)succ;
        while (c == 0) {
          c = *(char *)((char *)*(void **)p + 0x49);
          succ = (StagingNode *)p;
          p = *(void **)p;
        }
      } else {
        char c = *(char *)((char *)((void **)cur)[1] + 0x49);
        void *parent = ((void **)cur)[1];
        void *child = cur;
        while (1) {
          succ = (StagingNode *)parent;
          if (!(c == 0 && child == ((void **)succ)[2]))
            break;
          c = *(char *)((char *)((void **)succ)[1] + 0x49);
          parent = ((void **)succ)[1];
          child = succ;
        }
      }
    }
    FUN_00538780(&first, cur);
    cur = succ;
  }
  *outIter = cur;
}

/* Ghidra scaffold alias */
void __thiscall FUN_00539150(
    int param_1, uint32_t *param_2, int *param_3, int *param_4)
{
  MissionStagingTree_EraseRange(
      (StagingMap *)param_1,
      (StagingNode **)param_2,
      (StagingNode *)param_3,
      (StagingNode *)param_4);
}
