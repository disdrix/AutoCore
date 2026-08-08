// =============================================================================
// UI_Window_OnCommand_Class8_Inferred
// -----------------------------------------------------------------------------
// Purpose:  UI window OnCommand specialization for command class 8: dispatch
//           subcommand ids 1..0xd (dialog toggles + hardcoded skill cast
//           0xED5), with dead-vehicle early divert to base FUN_0082c780.
//
// Address:  0x0082f510  (autoassault.exe, image base 0x400000)
// Stable:   aa_0082f510
// System:   UI command dispatch (skills side-path case 1)
// Ghidra:   FUN_0082f510
//
// Convention: __thiscall ECX=this; stack (cmdClass, cmdId); RET 8.
// Entry: DATA vtable @ 0x00a72514 (no direct CALL sites).
//
// Case map (cmdClass==8):
//   1  → Client_CastSkillFromQuickBarSlot(0xED5)  // ESI=&DAT_00d1a840
//   2,3 → return 1
//   4  → DAT_00d1b874 dialog family (vtbl+0x3d8 / FUN_007fca10 / FUN_007fef20(1,…) / FUN_00889410)
//   5  → DAT_00d1b870 family (FUN_007fef20(0,…), FUN_00888b00)
//   6  → FUN_007fef20(2,0,0)
//   7  → FUN_007fef20(0x12,0,0)
//   8  → FUN_007fef20(0x13,0,0)
//   9  → FUN_007fef20(0x11,0,0)
//   10 → FUN_007fef20(0x29,0,0)
//   11 → DAT_00d1b880 family (FUN_007fef20(4,…), FUN_00889fb0)
//   12 → FUN_007fef20(3,0,0)
//   13 → FUN_007fef20(5,0,0)
//   else / class≠8 → if cmdId!=70000: FUN_0082c780; else return 1
//
// Dead-vehicle gate (cmdId!=10): vehicle@player+0x250 MI vtbl+0x194 non-zero →
//   this.vtbl+0x47c(); return FUN_0082c780(class,id).
//
// Exactness: Behavior-preserving CF. Dual WQ8R-F 2026-08-04.
// Dual reviews:
//   reviews/A_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md
//   reviews/B_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md
// Scaffold: reconstructed-exact/FUN_0082f510.cpp
// =============================================================================

#include <cstdint>

extern "C" int   DAT_00d1b6d8;
extern "C" int*  DAT_00d1b870;
extern "C" int*  DAT_00d1b874;
extern "C" int*  DAT_00d1b880;
extern "C" void  Client_CastSkillFromQuickBarSlot(void* client, int skillId);
extern "C" void  FUN_007fca10(void);
extern "C" void  FUN_007fef20(int dialogIndex, int a, int b); // client often via ECX/global
extern "C" uint32_t __thiscall FUN_0082c780(int* self, int cmdClass, int cmdId);
extern "C" void  FUN_00888b00(int* dlg, int);
extern "C" void  FUN_00889410(int* dlg, int);
extern "C" void  FUN_00889fb0(int* dlg, int);

static char VcallByte(int* obj, int slot)
{
    return (*(char(/**/)(int*, ...))(*(int*)obj + slot))(obj);
}

/// UI OnCommand class-8 dispatcher (INFERRED product class name).
uint32_t __thiscall UI_Window_OnCommand_Class8_Inferred(
    int* self, int cmdClass, int cmdId)
{
    if (cmdId != 10 && DAT_00d1b6d8 != 0) {
        int vehicle = *(int*)(DAT_00d1b6d8 + 0x250);
        if (vehicle != 0) {
            // MI entity at vehicle: *( *(vehicle+4)+4 ) + 4 + vehicle
            int mid = *(int*)(*(int*)(vehicle + 4) + 4);
            int* entity = (int*)(mid + 4 + vehicle);
            char dead = (*(char(/**/)(int*, ...))(*entity + 0x194))(entity);
            if (dead != '\0') {
                (*(void(/**/)(int*, ...))(*self + 0x47c))(self);
                return FUN_0082c780(self, cmdClass, cmdId);
            }
        }
    }

    int* dlg880 = DAT_00d1b880;
    int* dlg874 = DAT_00d1b874;
    int* dlg870 = DAT_00d1b870;

    if (cmdClass == 8) {
        switch (cmdId) {
        case 1:
            Client_CastSkillFromQuickBarSlot((void*)0x00d1a840, 0xED5);
            return 1;
        case 2:
        case 3:
            break;
        case 4:
            if (VcallByte(DAT_00d1b874, 0x3d8) != '\0' && dlg874[0x14c] == 0) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(1, 1, 0);
            if (VcallByte(dlg874, 0x3d8) != '\0') {
                FUN_00889410(dlg874, 1);
                return 1;
            }
            break;
        case 5:
            if (VcallByte(DAT_00d1b870, 0x3d8) != '\0' && dlg870[0x14d] == 0) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(0, 1, 0);
            if (VcallByte(dlg870, 0x3d8) != '\0') {
                FUN_00888b00(dlg870, 1);
                return 1;
            }
            break;
        case 6:
            FUN_007fef20(2, 0, 0);
            break;
        case 7:
            FUN_007fef20(0x12, 0, 0);
            return 1;
        case 8:
            FUN_007fef20(0x13, 0, 0);
            return 1;
        case 9:
            FUN_007fef20(0x11, 0, 0);
            return 1;
        case 10:
            FUN_007fef20(0x29, 0, 0);
            return 1;
        case 11:
            if (VcallByte(DAT_00d1b880, 0x3d8) != '\0' && dlg880[0x14a] == 0) {
                FUN_007fca10();
                return 1;
            }
            FUN_007fef20(4, 1, 0);
            if (VcallByte(dlg880, 0x3d8) != '\0') {
                FUN_00889fb0(dlg880, 1);
                return 1;
            }
            break;
        case 12:
            FUN_007fef20(3, 0, 0);
            return 1;
        case 13:
            FUN_007fef20(5, 0, 0);
            return 1;
        default:
            goto fallback;
        }
        return 1;
    }

fallback:
    if (cmdId != 70000) {
        return FUN_0082c780(self, cmdClass, cmdId);
    }
    return 1;
}
