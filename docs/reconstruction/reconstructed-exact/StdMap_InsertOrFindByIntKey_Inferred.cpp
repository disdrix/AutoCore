// =============================================================================
// StdMap_InsertOrFindByIntKey_Inferred
// -----------------------------------------------------------------------------
// Purpose:  MSVC std::map/set insert-or-find by int key. Walk tree, optional
//           predecessor, insert via RB helper or return existing iterator.
//           Writes pair{iterator, inserted}.
//
// Address:  0x00569320  (autoassault.exe, image base 0x400000)
// Body:     0x00569320–0x005693d8 (184 bytes; ret 8)
// Stable:   aa_00569320
// System:   container / ordered map
// Ghidra:   FUN_00569320
//
// ABI:      __thiscall
//             ECX = MapShell *map   (+4 head, +8 size)
//             stack: outPair*, int *pKey
//             ret 8
//
// Node:     left+0 parent+4 right+8 key+0xC isnil+0x49
//           (color+0x48 used inside insert callee FUN_005690a0)
//
// Exactness: CF mirrors raw + live decompile; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W19-J).
// =============================================================================

#include <cstdint>

// RB insert + rebalance; throws "map/set<T> too long" if size huge
void *__thiscall FUN_005690a0(void *map, void *outIt, char addLeft, void *parent, int *pKey);

// Map predecessor (dual aa_00537770) — Node** in ECX
void FUN_00537770(void);

/* StdMap_InsertOrFindByIntKey_Inferred — plate-faithful CF.

   Parameters:
     map:    this / ECX — shell with head* at +4
     out:    pair out — *out = iterator node*; byte at out+4 = inserted
     pKey:   pointer to int key

   Algorithm:
     1) Walk from head->parent while !isnil(child)
     2) If last compare was left:
          if node == *head → insert left of head; inserted=1
          else predecessor(node)
     3) If node->key < *pKey → insert; inserted=1
     4) Else equal → inserted=0; it=node

   Sole caller: FUN_00569560 (hinted insert fallback). */

void __thiscall StdMap_InsertOrFindByIntKey_Inferred(
    int map,
    uint32_t *outPair,
    int *pKey)
{
    uint32_t uVar1;
    bool bVar2;
    int *piVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;

    piVar3 = pKey;
    puVar5 = *(uint32_t **)(map + 4);
    bVar2 = true;
    if (*(char *)((int)puVar5[1] + 0x49) == '\0') {
        puVar4 = (uint32_t *)puVar5[1];
        do {
            puVar5 = puVar4;
            bVar2 = *pKey < (int)puVar5[3];
            if (bVar2) {
                puVar4 = (uint32_t *)*puVar5;
            } else {
                puVar4 = (uint32_t *)puVar5[2];
            }
        } while (*(char *)((int)puVar4 + 0x49) == '\0');
    }
    pKey = (int *)puVar5;
    if (bVar2) {
        if (puVar5 == (uint32_t *)**(int **)(map + 4)) {
            puVar5 = (uint32_t *)FUN_005690a0(
                (void *)map, &pKey, 1, puVar5, piVar3);
            uVar1 = *puVar5;
            *(uint8_t *)(outPair + 1) = 1;
            *outPair = uVar1;
            return;
        }
        FUN_00537770();
    }
    if (pKey[3] < *piVar3) {
        puVar5 = (uint32_t *)FUN_005690a0(
            (void *)map, &pKey, (char)bVar2, puVar5, piVar3);
        *outPair = *puVar5;
        *(uint8_t *)(outPair + 1) = 1;
        return;
    }
    *(uint8_t *)(outPair + 1) = 0;
    *outPair = (uint32_t)pKey;
    return;
}
