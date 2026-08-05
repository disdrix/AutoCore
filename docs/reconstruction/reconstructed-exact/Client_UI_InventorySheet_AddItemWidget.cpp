// =============================================================================
// Client_UI_InventorySheet_AddItemWidget
// -----------------------------------------------------------------------------
// Stable ID: aa_008605b0
// Address:   0x008605b0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-07-29 dual A/B (accept-with-gaps)
// Exactness: Behavior-preserving rewrite of decompiler control flow + asm ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate an inventory-item sheet widget (template XML via FUN_0085e590),
//   hash-insert by item COID, attach to inventory UI window, stamp type +
//   page-local cell coords, pixel-place, refresh.
//
// ABI (register, sealed by callers + entry bytes):
//   EDI = InventoryUiWindow*
//   EBX = ItemObject*
//   no stack args for window/item; ret (not ret N)
//
// NOT: C2S packet builder; NOT grid PlaceItemFootprint.
//
// DECOMPILER ARTIFACT:
//   Do not port "ExceptionList = (void*)pageIdx" on success — SEH restore is
//   normal fs:[0] from stack (read_memory epilogue).
// =============================================================================

// External / callee names kept as Ghidra symbols where not dual-named here.
extern void* operator_new(unsigned int size);
extern int* FUN_0085e590(void* mem);                 // inventory item widget ctor
extern int FUN_00413920(void* hash, unsigned coidLo, unsigned coidHi,
                        void* value, char noOverwriteFlag);
extern void FUN_0085f150(/* ECX=widget, EAX=window */);

// Register convention: EDI=window, EBX=item (not expressible portably in C).
void Client_UI_InventorySheet_AddItemWidget(void)
{
  // Pseudocode with sealed offsets (byte form).
  // int* window = EDI;  int* item = EBX;

  /*
  void* typeHost = *(void**)((char*)window + 0x56c);
  if (typeHost == 0 || item == 0) {
    return;
  }

  void* mem = operator_new(0x514);
  int* widget = (mem == 0) ? 0 : FUN_0085e590(mem);

  void* hash = *(void**)((char*)window + 0x570);
  unsigned coidLo = *(unsigned*)((char*)item + 0x160);
  unsigned coidHi = *(unsigned*)((char*)item + 0x164);
  int hr = FUN_00413920(hash, coidLo, coidHi, widget, 0);

  if (hr < 0) {
    if (widget != 0) {
      // scalar deleting destructor
      (*(void(__thiscall**)(int*, int))*widget)(widget, 1);
    }
    return;
  }

  // type stamp
  widget[0x125] = *(int*)((char*)typeHost + 4);           // +0x494

  // attach child
  (*(void(__thiscall**)(int*, int*))(*(int*)window + 0xa8))(window, widget);

  unsigned char pageIdx = *(unsigned char*)((char*)window + 0x564);
  (*(int*)((char*)window + 0x500))++;

  int pageH = 0;
  // re-read typeHost (matches body)
  typeHost = *(void**)((char*)window + 0x56c);
  if (typeHost != 0) {
    pageH = *(int*)((char*)typeHost + 0x1c);
  }

  // item cell getters: Y then X (vtbl +0x254, +0x250)
  unsigned yAbs = (*(unsigned(__thiscall**)(int*))(*(int*)item + 0x254))(item) & 0xff;
  unsigned x    = (*(unsigned(__thiscall**)(int*))(*(int*)item + 0x250))(item) & 0xff;
  int yLocal    = (int)yAbs - pageH * (int)pageIdx;

  widget[0x126] = (int)x;        // +0x498
  widget[0x127] = yLocal;        // +0x49c

  // bind from item
  (*(void(__thiscall**)(int*, int*))(*(int*)widget + 0x3b0))(widget, item);

  // pixel place: ECX=widget, EAX=window
  FUN_0085f150();

  // refresh
  (*(void(__thiscall**)(int*))(*(int*)widget + 0x34c))(widget);
  */
}
