# Review B (skeptical / adversarial): `aa_008605b0` Client_UI_InventorySheet_AddItemWidget

| Field | Value |
|---|---|
| **Stable ID** | `aa_008605b0` |
| **VA** | `0x008605b0` |
| **Review type** | Skeptical / adversarial dual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008605b0_Client_UI_InventorySheet_AddItemWidget.md` |
| **Evidence** | Independent re-read of live decompile + `read_memory` entry/callers/epilogue; callee ctor string; hash insert body |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---:|---|---|---|
| 1 | This builds/sends a C2S inventory packet | **Falsified** | No `Client_SendSectorPacket`; only UI new/hash/vtbl |
| 2 | Pure thiscall (`ECX=this`) | **Falsified** | Body is `[edi+…]` / `[ebx+…]`; callers load EDI/EBX explicitly |
| 3 | `unaff_EDI`/`unaff_EBX` are decompiler noise (unused) | **Falsified** | Entry `mov eax,[edi+0x56c]`; `cmp ebx,0`; call sites set both |
| 4 | Widget is a generic NDUIWindow with no inventory role | **Falsified as product** | Ctor loads `i_g_2d_wnd_inventory_item_template.xml` + inventory overlays |
| 5 | Keys are sequential slot indices | **Falsified** | Hash keys = `item+0x160/+0x164` (COID family) |
| 6 | Y stored is absolute grid Y | **Falsified** | `pageH * pageIdx` subtracted from item Y before store (`imul`/`sub`) |
| 7 | Fail path leaks the `0x514` widget | **Falsified** | Negative insert → `vtbl+0(1)` scalar delete when non-null |
| 8 | Success path sets `ExceptionList = pageIdx` | **Falsified (decomp bug)** | Epilogue restores `fs:[0]` from stack; pageIdx only used in Y math |
| 9 | Always succeeds when item non-null | **Falsified** | Duplicate COID insert returns `0x80004005` → destroy path |
| 10 | Same as DropToGrid (`0x00860a50`) | **Falsified** | DropToGrid hit-tests + sends `0x2036`/`0x2027`; this only materializes icons |
| 11 | `FUN_008c3120` is the only caller | **Falsified** | Also `FUN_00860700` bulk rebuild (many UI open/refresh parents) |
| 12 | typeHost **is** InventoryGrid class | **Not required / not sealed** | Offsets `+4` type, `+0x1c` pageH sealed; object English remains **Probable** |

---

## 2. Surviving contract

```text
Client_UI_InventorySheet_AddItemWidget(window@EDI, item@EBX):
  if !*(window+0x56c) || !item: return
  widget = new(0x514); FUN_0085e590(widget)   // inventory item template
  hr = HashInsert(*(window+0x570), item.COID, widget, noOverwrite=0)
  if hr < 0:
    if widget: widget->dtor(1)
    return
  widget.invType = *(*(window+0x56c)+4)
  window->attach(widget)                      // vtbl+0xa8
  *(window+0x500)++
  cellX = item.vgetX() & 0xff                 // vtbl+0x250
  cellY = (item.vgetY() & 0xff)
          - pageH(window) * pageIdx(window)   // page-local
  widget.cellX/Y = cellX/cellY
  widget->bind(item); place(widget,window); widget->refresh()
```

Risk if wrong:

| Wrong assumption | Risk |
|---|---|
| Skip page-local Y | Multi-page cargo/locker icons on wrong row |
| Wrong COID offsets | Hash collisions / missing icons after equip |
| Treat as packet path | Ghost server traffic; wrong layer in AutoCore port |
| Ignore fail dtor | UI object leak on duplicate add |

---

## 3. Cross-check spine

```text
RecvInventoryEquip
  → FUN_008c3120(parent@EAX, item@ECX)
       edi=*(parent+0x580); ebx=item; call 0x008605b0

FUN_00860700(window@ESI)   // bulk sheet rebuild
  → for each resolved item: ebx=item; edi=esi; call 0x008605b0
  → window->vtbl+0x34c()

FUN_0085e590: string "i_g_2d_wnd_inventory_item_template.xml"  (Confirmed)
FUN_0085f150: pixel = origin + pitch * cell                    (High)
FUN_00413920: COID hash insert; dup → 0x80004005               (High)
pageH×pageIdx family: DropToGrid / HitTest / FindFree          (High)
```

---

## 4. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EDI/EBX | **High** | Mis-bind in ports / hooks |
| Template widget identity | **Confirmed** | Wrong UI factory |
| COID hash key | **High** | Icon map desync |
| Page-local Y | **High** | Multi-page layout |
| typeHost offsets | **High** | Wrong type stamp / pageH |
| Not a packet builder | **High** | Architecture mistake |
| Item vfunc names | **Probable** | Docs only |
| Window product class name | **Probable** | Naming only |
| Runtime multi-page | **Open** | Edge visual |

---

## 5. Open (do not invent)

1. Live capture: equip → single add path stamps correct cell vs bulk rebuild.
2. Whether `*(parent+0x580)` in equip wrapper is always same type as bulk `ESI` window.
3. Formal names for item `+0x250/+0x254` and window attach `+0xa8`.
4. Bit-exact / differential vs retail (deferred).

**Verdict:** residual challenges on **packet role**, **ABI**, **absolute-Y**, and **decomp ExceptionList** **defeated**. **accept-with-gaps.**
