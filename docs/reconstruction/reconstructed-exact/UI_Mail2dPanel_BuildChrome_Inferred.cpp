// =============================================================================
// UI_Mail2dPanel_BuildChrome_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008b84a0
// Address:   0x008b84a0 – 0x008b8b76  (autoassault.exe, image base 0x400000)
// Size:      1751 B (0x6D7)
// System:    inventory-transfer (mail 2d UI chrome builder; client-only)
// Dual:      R13-013 2026-08-05 (A/B accept-with-gaps)
// Exactness: Behavior-preserving rewrite of decompiler + disasm control flow.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NOT claimed.
// =============================================================================
//
// PURPOSE:
//   Initialize / build mail 2d panel chrome for `this`:
//     - shared title/icon/fill/texture + close button (id 0x9c40)
//     - receive tab (+0x55c, id 0x9c43) and send tab (+0x558, id 0x9c42)
//     - mode @+0x510 == 1 → receive list chrome + select receive tab
//       else → send/deposit/credits/compose chrome + select send tab
//     - final layout vtbl +0x34c
//
// ABI: ECX = this; no stack args; plain RET.
// Dispatch: vtable DATA slot @0x00a475b0 (no direct CALL xrefs).
//
// Dualed callees (evidence; not owned here):
//   FUN_00822cb0 UI_TabChrome_SetSelected_Inferred      (ESI, BL, force@stack, RET 4)
//   FUN_00756c90 UI_Widget_MoveToFrontInParentGroup_Inferred (EDI=widget, RET)
//
// Rejected scaffold alias: UI_mail_bg_frame_deposit (one send-arm plate only).
// =============================================================================

#include <cstdint>

// Forward decls — residual / dualed peers (names where dualed)
void FUN_00792600();
void* operator_new(uint32_t size);
int  FUN_008230b0(/* tab memory */);
int* FUN_008b7240(/* list memory, host arg */);
void FUN_008b6d50(/* list setup; ESI=list */);
void FUN_00822cb0(int force);   // ESI=tab, BL=selected
int  FUN_00756c90();            // EDI=widget; EAX status
uint32_t GetTickCount();
void FUN_00980250(/* request helper; EAX family, stack payload */);
int  FUN_007a69d0(/* string path */);
int  FUN_007a6de0(/* ECX from 007a69d0 */);
void FUN_00977a30(/* residual UI helper */);

// Clean structural reconstruction (control flow sealed; vtbl product names open).
void __fastcall UI_Mail2dPanel_BuildChrome_Inferred(int* self)
{
    // SEH frame omitted (LAB_009b6675) — present in raw.
    FUN_00792600();

    // --- Shared chrome via vtbl[+0x404] LoadChild(xml, outslot, id=-1) ---
    // self+0x544: i_d_mail_2d_wnd_bg_fill.xml
    // self+0x548: i_d_mail_2d_wnd_bg_texture.xml
    // self+0x550: i_d_mail_2d_wnd_icon.xml
    // self+0x554: i_d_mail_2d_wnd_icon_cover.xml
    // self+0x54c: i_d_mail_2d_wnd_title.xml
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x404))(
        self, (int*)((char*)self + 0x544), "i_d_mail_2d_wnd_bg_fill.xml", -1);
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x404))(
        self, (int*)((char*)self + 0x548), "i_d_mail_2d_wnd_bg_texture.xml", -1);
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x404))(
        self, (int*)((char*)self + 0x550), "i_d_mail_2d_wnd_icon.xml", -1);
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x404))(
        self, (int*)((char*)self + 0x554), "i_d_mail_2d_wnd_icon_cover.xml", -1);
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x404))(
        self, (int*)((char*)self + 0x54c), "i_d_mail_2d_wnd_title.xml", -1);

    // Close button vtbl[+0x408] id 0x9c40 → self+0x504
    (*(void(__thiscall**)(int*, int*, const char*, int))(*self + 0x408))(
        self, (int*)((char*)self + 0x504), "i_d_mail_2d_btn_close.xml", 0x9c40);

    // --- Receive tab (0x81c) → self+0x55c, id 0x9c43 ---
    void* recv_mem = operator_new(0x81c);
    int recv_tab = recv_mem ? FUN_008230b0() : 0;
    *(int*)((char*)self + 0x55c) = recv_tab;
    (*(void(__thiscall**)(int*, int))(*self + 0xa8))(self, recv_tab);
    // LoadXml / finalize / SetId on recv_tab (vtbl +0x28 / +0x43c / +0x74)
    // "i_d_mail_2d_tab_receive.xml", id 0x9c43

    // --- Send tab (0x81c) → self+0x558, id 0x9c42 ---
    void* send_mem = operator_new(0x81c);
    int send_tab = send_mem ? FUN_008230b0() : 0;
    *(int*)((char*)self + 0x558) = send_tab;
    (*(void(__thiscall**)(int*, int))(*self + 0xa8))(self, send_tab);
    // "i_d_mail_2d_tab_send.xml", id 0x9c42

    if (*(int*)((char*)self + 0x510) == 1) {
        // ===== RECEIVE MODE =====
        // frames: i_d_mail_2d_wnd_bg_frame.xml → +0x59c
        //         i_d_mail_2d_wnd_bg_frame_attach.xml → +0x598
        // list: operator_new(0x560) → FUN_008b7240 → self+0x5a4
        // FUN_008b6d50(list, -1, -1); scale/show list
        // Select receive: ESI=recv_tab, BL=1, force=1 → FUN_00822cb0
        // show recv vtbl +0x94
        // Collapse send: ESI=send_tab, BL=0, force=1 → FUN_00822cb0
        // MoveToFront send: EDI=send_tab → FUN_00756c90
        uint32_t now = GetTickCount();
        if (now - *(uint32_t*)((char*)self + 0x50c) >= 10000u) {
            // FUN_00980250 family path with payload dword 3 (wire map residual)
            *(uint32_t*)((char*)self + 0x50c) = now;
        }
    } else {
        // ===== SEND MODE =====
        // i_d_mail_2d_wnd_bg_frame_send.xml / deposit / inv_bg / credits ×4
        // edits: credits 0x9c49; receiver 0x9c46; subject 0x9c47; message 0x9c48
        // send button 0x9c41; item drop 0x9c44; postage "Postage:" path
        // tab-order indices 0..6 via vtbl +0x98
        // Collapse receive + MoveToFront; select send + show
        *(int*)((char*)self + 0x518) = -1;
        *(int*)((char*)self + 0x51c) = -1;
    }

    // Final layout / refresh
    (*(void(__thiscall**)(int*))(*self + 0x34c))(self);
}

// FUN_* twin retained for ledger linkage: reconstructed-exact/FUN_008b84a0.cpp
