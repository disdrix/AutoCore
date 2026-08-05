# Review A (reconstruction fidelity): `aa_008847f0` CDlgTrade2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008847f0` |
| **VA** | `0x008847f0` |
| **Canonical name** | `CDlgTrade2d_CreateChildWidgets` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CreateChildWidgets** body for the client **2D trade dialog** host (`CDlgTrade2d`). Clears/rebuilds the child tree via `FUN_00792600`, then **allocates, constructs, skins (XML), attaches, and stores** dual inventory grids, credit digit editors/icons, offer panes, balance gauge, ready/accept/cancel/close buttons, and chrome frames.

**Not** a network send, **not** trade approve/complete handler, **not** inventory grab/drop C2S — pure UI host construction. Invoked via **vtable DATA slot** `@ 0x00a56ad8` (no direct CALL xrefs).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008847f0_CDlgTrade2d_CreateChildWidgets.md` |
| Annotated | `docs/reconstruction/raw/aa_008847f0_CDlgTrade2d_CreateChildWidgets.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CDlgTrade2d_CreateChildWidgets.cpp` |
| Function record | `docs/reconstruction/functions/aa_008847f0_CDlgTrade2d_CreateChildWidgets.md` |
| Live Ghidra | `force_decompile` / `decompile_function` → **blocked** (`Overlapping input varnodes`); recovery via `disassemble_function` + `get_function_signature` + `audit_globals_in_function` + `read_memory` + callee decompiles |
| Vtable entry | DATA `@ 0x00a56ad8` → `0x008847f0` |
| Related (not this unit) | `InventoryGrid_SetOwnerFlag_Inferred` `0x00570600`; grid ctor `FUN_008609b0`; grid refresh `FUN_00860700` |

---

## 3. Signature / ABI

```c
// thiscall: ECX = trade dialog host
// void return; no stack formals
void __fastcall CDlgTrade2d_CreateChildWidgets(void *this);
```

| Claim | Confidence | Notes |
|---|---|---|
| `this` in ECX → EDI for body | **High** | Prologue `MOV EDI,ECX`; all host stores via EDI |
| Void return | **High** | Terminal `RET` after SEH pop; no EAX setup as return object |
| MSVC SEH (`LAB_009b5699`) | **High** | Prologue/epilogue FS:[0] chain; SEH state counter on stack |
| No direct callers | **High** | `get_function_callers` empty; sole xref DATA `@ 0x00a56ad8` |
| Size ~1213 insn / 123 BB / CC ~46 / 68 calls / 41 strings | **High** | `get_function_signature` |

---

## 4. Control flow (sealed from asm)

```
SEH push (LAB_009b5699)
EDI = this
FUN_00792600(this)                    // clear/rebuild existing child tree

// --- chrome / fill / fx / frames ---
// Pattern per child (repeated ~30×):
//   p = operator_new(size)
//   if (p) p = specialized_ctor(p[, arg])
//   this->vtbl[+0xa8](p)             // attach child to host
//   p->vtbl[+0x28](xml_string)       // ReloadInterface / load skin
//   optional: alpha 0.5f via vtbl[+0xfc](1, 0x3f000000)
//   this+slot = p
//   bump this+0x68 child-count / depth float at +0x74; maybe extend +0x70
//   this->vtbl[+0x3f4](1)

+0x514  bg_fill          new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_bg_fill.xml"
+0x518  fx               new(0x4bc) FUN_00864f20  "i_d_t_2d_wnd_fx.xml"
+0x520  bg_texture       new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_bg_texture.xml"
+0x51c  icon             new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_icon.xml"
        icon_cover       via this->vtbl[+0x404](-1, "i_d_t_2d_wnd_icon_cover.xml", &tmp)  // no durable host slot
+0x530  frame_1          new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_frame_1.xml"
+0x534  frame_2          new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_frame_2.xml"
+0x538  frame_3          new(0x488) FUN_007b5dd0  "i_d_t_2d_wnd_frame_3.xml"
+0x53c  frame_credits_you  "i_d_t_2d_wnd_frame_credits_you.xml"
+0x540  frame_credits_them "i_d_t_2d_wnd_frame_credits_them.xml"

// --- ready buttons (button class FUN_0079c860, size 0x4cc) ---
+0x580  ready_you   "i_d_t_2d_btn_ready_you.xml"   + vtbl[+0x3b4](1) + alpha 0.5
+0x584  ready_them  "i_d_t_2d_btn_ready_them.xml"  + vtbl[+0x3b4](1) + alpha 0.5

// --- inventory grids (FUN_008609b0, size 0x578) ---
+0x588  inv_you
  grid+0x56c = *(DAT_00d1b6d8 + 0xce0)     // local trade inventory object*
  if non-null: scale dims into grid+0x50c / +0x510 from screen metrics
  grid->vtbl[+0x444]("i_d_t_2d_wnd_inv_you.xml")
  grid->vtbl[+0x74](0x9c42)                 // widget id 40002
  alpha 0.5; FUN_00860700(grid)             // ESI = grid refresh

+0x58c  inv_them
  partner_root = this+0x510                 // must be set by caller/open path
  grid+0x56c = partner_root ? partner_root+0xce0 : 0
  same dim scale if grid+0x56c non-null
  FUN_00860700(grid)
  grid->vtbl[+0x444]("i_d_t_2d_wnd_inv_them.xml")
  grid->vtbl[+0x74](0x9c43)                 // widget id 40003
  if (grid+0x56c) InventoryGrid_SetOwnerFlag_Inferred(grid+0x56c, 6)
  alpha 0.5; grid->vtbl[+0x300](0)

// --- credits chrome ---
+0x550  credits_bg_you   "i_d_t_2d_wnd_credits_bg_you.xml"
+0x554  credits_bg_them  "i_d_t_2d_wnd_credits_bg_them.xml"
// four you credit icons via vtbl[+0x404] (icon_credits_you_1..4) — no durable slots
// four edit boxes (FUN_00795f20, size 0x4a4):
+0x558  edt_credits_you_1  id 0x9c41, xml …_1, digit index vtbl[+0x98](0)
+0x55c  edt_credits_you_2  id 0x9c41, xml …_2, digit index 1
+0x560  edt_credits_you_3  id 0x9c41, xml …_3, digit index 2
+0x564  edt_credits_you_4  id 0x9c41, xml …_4, digit index 3
// each: vtbl[+0x1d0](0x10); byte +0x48b = 1; vtbl[+0x3ac](DAT_00a32460)
// four them credit icons via vtbl[+0x404] (icon_credits_them_1..4)
+0x568..+0x574  credits_them_1..4 windows  (wnd_credits_them_*.xml)

// --- offer / balance ---
+0x544  offer_you     "i_d_t_2d_wnd_offer_you.xml"   + alpha 0.5
// sequential stores to +0x548 (last write wins for host slot):
//   offer_them, balance_title, balance_wnd → final +0x548 = balance window
// children still attached via +0xa8 regardless of host-slot overwrite
+0x590  gauge_balance  new(0x4f8) FUN_0097ffa0  "i_d_t_2d_gauge_balance.xml"
+0x52c  title          "i_d_t_2d_wnd_title.xml" + alpha 0.5

// --- action buttons (FUN_0079c860) ---
+0x578  accept  "i_d_t_2d_btn_accept.xml"  id 0x9c44  + vtbl[+0x3b4](1)
+0x57c  cancel  "i_d_t_2d_btn_cancel.xml"  id 0x9c45
+0x504  close   "i_d_t_2d_btn_close.xml"   id 0x9c40

// --- host finish flags ---
this+0x49c = 0x9c40                         // default/focus widget id (close)
this+0x50c = 0; this+0x50d = 0              // two flag bytes cleared
this->vtbl[+0x448]()
this->vtbl[+0x34c]()                        // layout/finalize
SEH pop; RET
```

---

## 5. Constants (`read_memory` / immediates)

| Symbol / immediate | Value | Role |
|---|---|---|
| `0x3f000000` | **0.5f** | Alpha/opacity arg to child vtbl `+0xfc` |
| Widget id `0x9c40` | **40000** | Close button; also stored `this+0x49c` |
| `0x9c41` | **40001** | All four local credit edit boxes |
| `0x9c42` | **40002** | `inv_you` grid |
| `0x9c43` | **40003** | `inv_them` grid |
| `0x9c44` | **40004** | Accept |
| `0x9c45` | **40005** | Cancel |
| Owner flag **6** | trade-side inventory type (peer grid) | `InventoryGrid_SetOwnerFlag_Inferred` on them inventory object |
| `DAT_00d1b6d8` | client/session root | `+0xce0` → local trade inventory* |
| `DAT_00d1e50c` / `DAT_00d1e818` / `DAT_00aaa67c` | screen/scale ints × float | drive grid `+0x50c` width-ish |
| `DAT_00d1e81c` / `DAT_00d1e510` / `DAT_00aaa678` | screen/scale | drive grid `+0x510` height-ish |
| `DAT_00aaa678` LE | `9a 99 59 3f` ≈ **0.85f** | height scale |
| `DAT_00aaa67c` LE | `0a d7 23 3a` ≈ **6.25e-4** | width scale (tiny; product of two int→float) |
| Alloc `0x488` | base NDUI window | `FUN_007b5dd0` |
| Alloc `0x4bc` | fx/control subclass | `FUN_00864f20` |
| Alloc `0x4cc` | button | `FUN_0079c860` |
| Alloc `0x578` | inventory grid widget | `FUN_008609b0` |
| Alloc `0x4a4` | edit box | `FUN_00795f20` |
| Alloc `0x4f8` | gauge | `FUN_0097ffa0` |

---

## 6. Host field map (this unit)

| Host off | Widget / value | XML / notes |
|---:|---|---|
| `+0x49c` | dword **0x9c40** | default control id (close) |
| `+0x504` | close button* | `i_d_t_2d_btn_close.xml` |
| `+0x50c` / `+0x50d` | bytes **0** | ready/state flags cleared at end |
| `+0x510` | **input** partner root* | read-only here; supplies them `+0xce0` |
| `+0x514` | bg_fill* | `i_d_t_2d_wnd_bg_fill.xml` |
| `+0x518` | fx* | `i_d_t_2d_wnd_fx.xml` |
| `+0x51c` | icon* | `i_d_t_2d_wnd_icon.xml` |
| `+0x520` | bg_texture* | `i_d_t_2d_wnd_bg_texture.xml` |
| `+0x52c` | title* | `i_d_t_2d_wnd_title.xml` |
| `+0x530..+0x538` | frame_1..3* | frame xmls |
| `+0x53c` / `+0x540` | credit frames you/them* | |
| `+0x544` | offer_you* | |
| `+0x548` | **last** of offer_them / balance_title / balance | **overwrite chain** — final = `wnd_balance` |
| `+0x550` / `+0x554` | credits_bg you/them* | |
| `+0x558..+0x564` | edt_credits_you 1..4* | digit indices 0..3 |
| `+0x568..+0x574` | credits_them digit windows* | |
| `+0x578` | accept* | id 40004 |
| `+0x57c` | cancel* | id 40005 |
| `+0x580` / `+0x584` | ready_you / ready_them* | |
| `+0x588` / `+0x58c` | inv_you / inv_them grids* | ids 40002 / 40003 |
| `+0x590` | balance gauge* | `FUN_0097ffa0` |
| `+0x68` / `+0x70` / `+0x74` | child-count / max / float depth | updated after many attaches |

Grid child fields written by this unit:

| Grid off | Value | Role |
|---:|---|---|
| `+0x56c` | inventory object* | local from `DAT_00d1b6d8+0xce0`; them from `host+0x510+0xce0` |
| `+0x50c` / `+0x510` | scaled pixel dims | from global screen metrics when inv non-null |
| inv object `+0x4` | **6** (them only) | `InventoryGrid_SetOwnerFlag_Inferred` |

---

## 7. Callers / callees

### Callers

| Site | Role |
|---|---|
| Vtable DATA `@ 0x00a56ad8` | Sole xref; virtual CreateChildWidgets dispatch |

### Callees (named / inferred)

| Callee | Role in this unit |
|---|---|
| `FUN_00792600` | Host child-tree rebuild / clear before recreate |
| `operator_new` | All child allocations |
| `FUN_007b5dd0` | Base NDUI window ctor (size `0x488`) |
| `FUN_00864f20` | FX/control subclass ctor |
| `FUN_0079c860` | Button subclass ctor (size `0x4cc`) |
| `FUN_008609b0` | Inventory-grid widget ctor (size `0x578`, vtbl `PTR_FUN_00a6476c`) |
| `FUN_00860700` | Grid content refresh after bind |
| `FUN_00795f20` | Edit-box ctor (size `0x4a4`) |
| `FUN_0097ffa0` | Gauge ctor (size `0x4f8`) |
| `InventoryGrid_SetOwnerFlag_Inferred` | `*(inv+4) = 6` on them side |
| Host/child vtbl slots | `+0xa8` attach, `+0x28` load XML, `+0xfc` alpha, `+0x3f4` notify, `+0x404` spawn-by-xml, `+0x444` grid skin, `+0x74` set id, `+0x3b4` button flag, `+0x448`/`+0x34c` finalize |

---

## 8. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Decompiler body | **N/A** — Ghidra blocked; body is **asm-structural** |
| XML string set (41) | **Yes** — signature + globals audit |
| Dual grids + owner flag 6 | **Yes** |
| Widget ids 40000–40005 | **Yes** |
| Host slot map from `MOV [EDI+…]` | **Yes** |
| No invented C2S/S2C | **Yes** |

Clean plate is a **structural rewrite** from disassembly (not bit-identical C). Must not invent packet sends.

---

## 9. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = trade dialog CreateChildWidgets | **High** | 41 `i_d_t_2d_*` strings + vtable slot |
| Client-only UI (no wire) | **High** | No send callees; pure new/ctor/attach |
| `inv_you` / `inv_them` host slots `+0x588`/`+0x58c` | **High** | Direct stores + XML + ids |
| Local inv from `DAT_00d1b6d8+0xce0` | **High** | Matches DropResponse type-5 path (`client+…+0xce0`) |
| Partner inv via `this+0x510 → +0xce0` | **High** | Asm `MOV EAX,[EDI+0x510]` |
| Owner flag **6** on them inv | **High** | `PUSH 6; CALL 0x00570600` |
| Widget id block 40000–40005 | **High** | Immediates + button/grid id sets |
| `+0x548` triple overwrite | **High** | Three sequential stores; last = balance |
| English class `CDlgTrade2d` | **Inferred** | Registry/name; no RTTI sealed here |
| Full vtbl method English names | **Open** | Slot offsets sealed; product names not |
| Full SEH state-machine unwind table | **Open** | Not required for construction contract |

---

## 10. Gaps / open

1. Ghidra decompiler still blocked — full C body requires varnode fix or continued asm.
2. Product names for `FUN_007b5dd0` / `FUN_0079c860` / `FUN_008609b0` / host vtbl slots.
3. Why `+0x548` overwrites offer_them and balance_title (dead host slots vs intentional “last wins”).
4. Who sets `this+0x510` (partner character/root) before this method runs.
5. Click handlers for ready/accept/cancel/close live in other units (not this VA).
6. Bit-for-bit / runtime / differential open.

**Verdict:** Construction contract, host field map, dual-grid bind, XML inventory, and widget ids sealed from asm despite decompiler failure. Residual: product naming, `+0x548` overwrite intent, partner pointer producer. **accept-with-gaps.**
