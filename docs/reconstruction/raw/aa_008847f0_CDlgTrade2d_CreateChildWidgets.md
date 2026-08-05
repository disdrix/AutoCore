# Raw capture: CDlgTrade2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008847f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008847f0` |
| **Canonical name** | `CDlgTrade2d_CreateChildWidgets` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-29` |
| **Tool** | Ghidra MCP `disassemble_function` + `get_function_signature` + `audit_globals_in_function` + `read_memory` + callee decompiles |
| **Integrity** | Asm-structural (decompiler blocked: Overlapping input varnodes) |

---

## Stats

| Metric | Value |
|---|---|
| Instructions | 1213 |
| Basic blocks | 123 |
| Cyclomatic complexity | 46 |
| Calls | 68 |
| String refs | 41 |
| Params | 1 (`this` / ECX) |
| Xrefs | DATA `@ 0x00a56ad8` only |

---

## Signature

```c
void __fastcall CDlgTrade2d_CreateChildWidgets(void *this);
```

---

## Raw structural pseudocode (from disassembly)

```c
/* CDlgTrade2d_CreateChildWidgets @ 0x008847f0
 * DECOMPILER BLOCKED: Overlapping input varnodes.
 * Body recovered from disassemble_function (2026-07-29).
 */
void __fastcall CDlgTrade2d_CreateChildWidgets(void *this)
{
    /* SEH: LAB_009b5699 */
    void *host = this; /* EDI */

    FUN_00792600(host); /* rebuild/clear child tree */

    /* Chrome: operator_new + ctor + host.vtbl[+0xa8] attach + child.vtbl[+0x28](xml)
       + optional child.vtbl[+0xfc](1, 0.5f) + store host slot + bump +0x68/+0x74 */

    host[+0x514] = Wnd(0x488, FUN_007b5dd0, "i_d_t_2d_wnd_bg_fill.xml");
    host[+0x518] = Wnd(0x4bc, FUN_00864f20, "i_d_t_2d_wnd_fx.xml");
    host[+0x520] = Wnd(0x488, FUN_007b5dd0, "i_d_t_2d_wnd_bg_texture.xml");
    host[+0x51c] = Wnd(0x488, FUN_007b5dd0, "i_d_t_2d_wnd_icon.xml");
    host.vtbl[+0x404](-1, "i_d_t_2d_wnd_icon_cover.xml", &tmp);
    host[+0x530] = Wnd(..., "i_d_t_2d_wnd_frame_1.xml");
    host[+0x534] = Wnd(..., "i_d_t_2d_wnd_frame_2.xml");
    host[+0x538] = Wnd(..., "i_d_t_2d_wnd_frame_3.xml");
    host[+0x53c] = Wnd(..., "i_d_t_2d_wnd_frame_credits_you.xml");
    host[+0x540] = Wnd(..., "i_d_t_2d_wnd_frame_credits_them.xml");

    host[+0x580] = Btn(0x4cc, FUN_0079c860, "i_d_t_2d_btn_ready_you.xml");  /* +0x3b4(1) */
    host[+0x584] = Btn(0x4cc, FUN_0079c860, "i_d_t_2d_btn_ready_them.xml");

    /* inv_you @ +0x588 */
    g = Grid(0x578, FUN_008609b0);
    g[+0x56c] = *(DAT_00d1b6d8 + 0xce0);
    /* scale g[+0x50c]/[+0x510] from screen DATs if inv non-null */
    g.vtbl[+0x444]("i_d_t_2d_wnd_inv_you.xml");
    g.vtbl[+0x74](0x9c42);
    FUN_00860700(g);
    host[+0x588] = g;

    /* inv_them @ +0x58c */
    g = Grid(0x578, FUN_008609b0);
    root = host[+0x510];
    g[+0x56c] = root ? *(root + 0xce0) : 0;
    /* scale dims if inv non-null */
    FUN_00860700(g);
    g.vtbl[+0x444]("i_d_t_2d_wnd_inv_them.xml");
    g.vtbl[+0x74](0x9c43);
    if (g[+0x56c]) InventoryGrid_SetOwnerFlag_Inferred(g[+0x56c], 6);
    g.vtbl[+0x300](0);
    host[+0x58c] = g;

    host[+0x550] = Wnd(..., "i_d_t_2d_wnd_credits_bg_you.xml");
    host[+0x554] = Wnd(..., "i_d_t_2d_wnd_credits_bg_them.xml");
    /* icon_credits_you_1..4 via +0x404 */
    host[+0x558] = Edt(FUN_00795f20, "i_d_t_2d_edt_credits_you_1.xml", digit=0, id=0x9c41);
    host[+0x55c] = Edt(..., "_2.xml", digit=1, id=0x9c41);
    host[+0x560] = Edt(..., "_3.xml", digit=2, id=0x9c41);
    host[+0x564] = Edt(..., "_4.xml", digit=3, id=0x9c41);
    /* icon_credits_them_1..4 via +0x404 */
    host[+0x568..+0x574] = Wnd credits_them_1..4;

    host[+0x544] = Wnd(..., "i_d_t_2d_wnd_offer_you.xml");
    /* +0x548 written thrice: offer_them, balance_title, balance (last wins) */
    host[+0x590] = Gauge(0x4f8, FUN_0097ffa0, "i_d_t_2d_gauge_balance.xml");
    host[+0x52c] = Wnd(..., "i_d_t_2d_wnd_title.xml");

    host[+0x578] = Btn(..., "i_d_t_2d_btn_accept.xml", id=0x9c44);
    host[+0x57c] = Btn(..., "i_d_t_2d_btn_cancel.xml", id=0x9c45);
    host[+0x504] = Btn(..., "i_d_t_2d_btn_close.xml", id=0x9c40);

    host[+0x49c] = 0x9c40;
    host[+0x50c] = 0; host[+0x50d] = 0;
    host.vtbl[+0x448]();
    host.vtbl[+0x34c]();
}
```

---

## String constants (41)

All under `i_d_t_2d_*`: bg_fill, fx, bg_texture, icon, icon_cover, frame_1/2/3, frame_credits_you/them, btn_ready_you/them, inv_you/them, credits_bg_you/them, icon_credits_you_1..4, edt_credits_you_1..4, icon_credits_them_1..4, credits_them_1..4, offer_you/them, balance_title, balance, gauge_balance, title, btn_accept/cancel/close.
