// =============================================================================
// UI_InventoryPanel_MessageHandler_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008be900
// Address:   0x008be900–0x008beb13  (autoassault.exe, image base 0x400000)
// Size:      531 bytes (0x213)
// System:    inventory-transfer / UI message dispatch
// Generated: 2026-07-29 W20-F OWN dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Ghidra:    FUN_008be900
// =============================================================================
//
// PURPOSE:
//   Inventory / item panel UI message handler (thiscall, ret 8).
//   Slot controls 0x9c43..0x9c46; close 0x9c40; specials 0x9c41/0x9c42.
//   msg 0xe → Client_UseInventoryItem_Inferred(1); fail → Client_SendUseObject_IfInteractable.
//   Unknown → UI_DefaultMessageHandler.
//
// ABI:
//   uint32_t __thiscall (void *this, int msg, int controlId);
//   ECX=this; stack msg, controlId; ret 8.
//

#include <cstdint>
#include <cmath>

// External symbols (image / dual-named)
extern "C" {
uint32_t __thiscall UI_DefaultMessageHandler(void *self, int msg, int controlId); // FUN_0087b500
char __cdecl Client_UseInventoryItem_Inferred(int mode); // FUN_00941d50 — item in EDI, client ESI
void Client_SendUseObject_IfInteractable(void); // 0x00930d70
void FUN_007fd420(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3);
void FUN_007fca10(void);
int FUN_004024b0(void); // StdVector_DwordSize (context-dependent this)
void FUN_008bda60(void);
}

extern int *DAT_00d1d8dc;
extern uint8_t DAT_00d1d8f4;
extern uint8_t DAT_00d1d8f5;
extern float _DAT_00aaa5dc; // 4294967296.0f @ 0x00aaa5dc

uint32_t __thiscall UI_InventoryPanel_MessageHandler_Inferred(void *self, int msg, int controlId)
{
  float fVar1;
  char cVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  int iVar5;
  uint32_t uVar6;
  long double fVar7;
  uint8_t local_10[16];
  int *const this_i = reinterpret_cast<int *>(self);

  // ---- Slot band: control ids 0x9c43..0x9c46 ----
  if ((0x9c42 < controlId) && (controlId < 0x9c47)) {
    iVar5 = controlId + -0x9c43; // slot 0..3
    if (msg == 5) {
      if (*(int *)((char *)self + 0x55c + iVar5 * 4) != 0) {
        int **slot = *(int ***)((char *)self + 0x55c + iVar5 * 4);
        puVar3 = (uint32_t *)((**(code **)(*slot + 0x140))(local_10, 1));
        puVar4 = (uint32_t *)((**(code **)(*slot + 0x120))(local_10, 1, 1));
        FUN_007fd420(*puVar4, puVar4[1], *puVar3, puVar3[1]);
      }
      return 1;
    }
    if (msg == 6) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (DAT_00d1d8dc != (int *)0x0) {
        (**(code **)(*DAT_00d1d8dc + 4))(0);
      }
      return 1;
    }
    if (msg == 0xe) {
      // Prefer inventory-item use; fall back to world UseObject-if-interactable.
      cVar2 = Client_UseInventoryItem_Inferred(1);
      if (cVar2 == '\0') {
        Client_SendUseObject_IfInteractable();
      }
      return 1;
    }
  }

  // ---- Close / specials ----
  if (controlId == 40000) { // 0x9c40
    if (msg == 8) {
      FUN_007fca10(); // leave dialog host
    }
    // falls through to default
  }
  else if (controlId == 0x9c41) {
    if (msg == 8) {
      return 1; // swallow activate
    }
  }
  else if ((controlId == 0x9c42) && (msg == 0x1a)) {
    // Scroll-sync when list has more than 4 visible entries
    if (((*(int **)((char *)self + 0x544) != (int *)0x0) &&
         (*(int *)((char *)self + 0x550) != 0)) &&
        (4 < (uint32_t)(*(int *)((char *)self + 0x554) - *(int *)((char *)self + 0x550) >> 2))) {
      fVar7 = (long double)((**(code **)(**(int **)((char *)self + 0x544) + 0x458))());
      iVar5 = FUN_004024b0();
      fVar1 = (float)(iVar5 + -4);
      if (iVar5 + -4 < 0) {
        fVar1 = fVar1 + _DAT_00aaa5dc; // u32→float bias 2^32
      }
      if (*(int *)((char *)self + 0x548) != (int)std::lround(fVar1 * (float)fVar7)) {
        *(int *)((char *)self + 0x548) = (int)std::lround(fVar1 * (float)fVar7);
        FUN_008bda60();
      }
    }
    return 1;
  }

  uVar6 = UI_DefaultMessageHandler(self, msg, controlId); // FUN_0087b500
  return uVar6;
}

// Alias for Ghidra name
uint32_t __thiscall FUN_008be900(void *self, int msg, int controlId)
{
  return UI_InventoryPanel_MessageHandler_Inferred(self, msg, controlId);
}
