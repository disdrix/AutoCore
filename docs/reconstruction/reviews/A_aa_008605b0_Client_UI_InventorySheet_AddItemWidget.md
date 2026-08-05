# Review A (reconstruction fidelity): `aa_008605b0` Client_UI_InventorySheet_AddItemWidget

| Field | Value |
|---|---|
| **Stable ID** | `aa_008605b0` |
| **VA** | `0x008605b0` |
| **Canonical name** | `Client_UI_InventorySheet_AddItemWidget` |
| **Aliases** | `FUN_008605b0`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008605b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (raw ≡ live decompile ≡ call-site asm) |
| **Counterpart** | `reviews/B_aa_008605b0_Client_UI_InventorySheet_AddItemWidget.md` |
| **System** | `inventory-transfer` (UI sheet / item icon) |
| **Live re-decompile** | Ghidra MCP `decompile_function` `0x008605b0`; callees `0x0085e590` / `0x0085f150` / `0x00413920`; callers `0x00860700` / `0x008c3120` |
| **Evidence** | `read_memory` entry `0x008605b0`, call site `0x008607a0`, thin wrapper `0x008c3120`, body through epilogue `0x00860680+` |
| **Verdict** | **accept-with-gaps** — ABI, COID hash insert, page-local Y, template ctor **sealed**; item vfunc English + full window type **Probable** |

---

## 1. Purpose

**Inventory sheet single-item UI add helper.**

Given:

- **EDI** = inventory UI window / sheet host
- **EBX** = world/inventory **item object** (must be non-null)

Does:

1. Gate: `*(window+0x56c) != 0` (type host / grid binder) **and** `item != 0`.
2. `operator_new(0x514)` → construct via `FUN_0085e590` (**inventory item widget** ctor: loads `i_g_2d_wnd_inventory_item_template.xml`, broken/highlight overlays).
3. Insert widget into window hash table at `window+0x570` keyed by item COID `item+0x160` / `item+0x164` (`FUN_00413920`, no-overwrite flag `0`).
4. On insert **HRESULT ≥ 0** (success `0`):
   - Stamp widget inventory-type from `*(typeHost+4)` → `widget+0x494`.
   - Attach: `window->vtbl+0xa8(widget)`.
   - `*(window+0x500)++` (sheet item/widget counter).
   - Read page index `*(u8*)(window+0x564)`, page height `typeHost ? *(typeHost+0x1c) : 0`.
   - Query item cell via `item->vtbl+0x254` (Y) then `item->vtbl+0x250` (X).
   - Store `widget+0x498 = X & 0xff`, `widget+0x49c = (Y & 0xff) - pageH * pageIdx` (**absolute → page-local Y**).
   - `widget->vtbl+0x3b0(item)` (bind/refresh from item).
   - `FUN_0085f150(widget@ECX, window@EAX)` — pixel place from cell × pitch + origin.
   - `widget->vtbl+0x34c()` UI refresh.
5. On insert fail (negative HRESULT, e.g. duplicate `0x80004005`): scalar-deleting dtor `widget->vtbl+0(1)` if non-null.

**Not** a C2S packet builder. **Not** grid footprint stamp (`PlaceItemFootprint`). UI-only sheet icon materialize.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008605b0_FUN_008605b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008605b0_FUN_008605b0.annotated.md` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_008605b0.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_UI_InventorySheet_AddItemWidget.cpp` |
| Function record | `docs/reconstruction/functions/aa_008605b0_Client_UI_InventorySheet_AddItemWidget.md` |
| Live body | Ghidra decompile `0x008605b0` (matches raw CF) |
| Ctor string | `FUN_0085e590` → `NDUIWindow_LoadInterfaceFile("i_g_2d_wnd_inventory_item_template.xml")` |
| Position helper | `FUN_0085f150`: `px = originX + pitchX*cellX`, `py = originY + pitchY*cellY` |
| Hash insert | `FUN_00413920` TFID/COID hash (duplicate → `0x80004005`) |
| Callers | `FUN_00860700` (bulk rebuild), `FUN_008c3120` (equip single-add) |
| Sibling page math | DropToGrid residual `aa_00860a50` / HitTest `aa_0085f220` (`pageH×pageIdx`) |
| System map | `systems/inventory-transfer.md` |

**Not performed:** `disassemble_bytes` (project RE rule), Launcher, live UI capture, bit-exact EXE diff.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **EDI** | Inventory UI window / sheet | Entry `mov eax,[edi+0x56c]`; caller `008607b2`: `mov edi,esi` |
| **EBX** | Item object* | Entry `cmp ebx,0`; caller: `mov ebx,eax` after `ResolveObjectTarget`; thin wrapper: `mov ebx,ecx` |
| stack | *(none for this/item)* | No stack args for window/item |
| return | void (no meaningful EAX contract) | Epilogue `ret` after SEH pop |
| cleanup | **`ret`** (not `ret N`) | Bytes `c3` after `add esp,0x14` |

```c
// Custom dual-register (not pure thiscall / stdcall)
void Client_UI_InventorySheet_AddItemWidget(void);
// EDI = InventoryUiWindow*, EBX = ItemObject*  (caller-owned)
```

Null / host gate (entry bytes):

```text
typeHost = *(window + 0x56c)
if (typeHost == 0 || item == 0) return;
```

Thin equip wrapper `FUN_008c3120` (`read_memory` `0x008c3120`):

```text
push ebx; push edi
edi = *(eax + 0x580)     // sheet/window ptr from parent
ebx = ecx                // item (fastcall arg)
if (edi && ebx) call 0x008605b0
pop edi; pop ebx; ret
```

Bulk rebuild caller `FUN_00860700` @ `0x008607b2`:

```text
// after ResolveObjectTarget → EAX item
mov ebx, eax
mov edi, esi             // ESI = window this
call FUN_008605b0
```

---

## 4. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| SEH prolog / `ExceptionList` | **Yes** |
| Gate typeHost + item | **Yes** |
| `new(0x514)` + `FUN_0085e590` | **Yes** |
| Hash insert `FUN_00413920(window+0x570, coidLo, coidHi, widget, 0)` | **Yes** |
| Success: type stamp, attach `+0xa8`, count++, cell query, place, refresh | **Yes** |
| Fail: dtor `(1)` if widget non-null | **Yes** |
| Early return when gate fails | **Yes** |

### Decompiler artifact (do not port)

Raw/decompiler success path shows `ExceptionList = (void*)(uint)bVar1`. **False.**

Success epilogue (`read_memory` ~`0x008606b8+`):

```text
pop esi
pop ebp
mov ecx, [esp+8]     // prior SEH frame
mov fs:[0], ecx
add esp, 0x14
ret
```

`bVar1` is the **page-index byte** used in Y math only; SEH restore is normal stack/fs path.

---

## 5. Sealed formulas / offsets

### 5.1 Window (EDI)

| Offset | Decomp index | Role | Confidence |
|-------:|-------------:|------|---|
| `+0x56c` | `[0x15b]` | Type host / grid binder | **High** (same as DropToGrid/HitTest) |
| `+0x570` | `[0x15c]` | Widget hash table (`FUN_00413920` param0) | **High** |
| `+0x564` | byte at dword `0x159` | Page index | **High** |
| `+0x500` | `[0x140]` | Widget/item counter (`++` on success) | **High** |
| vtbl `+0xa8` | — | Attach/add child widget | **High** CF; English **Probable** |
| vtbl `+0x34c` | — | UI dirty/refresh (also bulk end) | **High** CF |

### 5.2 Item (EBX)

| Offset / slot | Role | Confidence |
|---|---|---|
| `+0x160` / `+0x164` | COID lo/hi (hash key; same family as Grab/Drop packets) | **High** |
| vtbl `+0x254` | Returns cell **Y** (byte used) | **High** order; English **Probable** |
| vtbl `+0x250` | Returns cell **X** (byte used) | **High** order; English **Probable** |

### 5.3 Widget (ESI after construct)

| Offset | Decomp index | Role | Confidence |
|-------:|-------------:|------|---|
| size `0x514` | — | Allocation | **Confirmed** (`push 0x514`) |
| `+0x494` | `[0x125]` | `*(typeHost+4)` inventory type | **High** |
| `+0x498` | `[0x126]` | Cell X (`& 0xff`) | **High** |
| `+0x49c` | `[0x127]` | Page-local cell Y | **High** |
| vtbl `+0x3b0` | — | Bind/setup from item (`push ebx; call`) | **High** CF |
| vtbl `+0x34c` | — | Refresh after place | **High** CF |
| vtbl `+0` | — | Scalar deleting dtor on insert fail | **High** |

### 5.4 Page-local Y (SEALED; inverse of DropToGrid wire Y)

```text
typeHost = *(window + 0x56c)
pageH    = typeHost ? *(i32*)(typeHost + 0x1c) : 0
pageIdx  = *(u8*)(window + 0x564)
absY     = (u8) item->vtbl+0x254()
cellX    = (u8) item->vtbl+0x250()
cellY    = absY - pageH * pageIdx
widget[+0x498] = cellX
widget[+0x49c] = cellY
```

Matches DropToGrid residual product shape (`wireY = pageH*pageIdx + cellY`) as **inverse** transform for sheet display.

### 5.5 Position helper `FUN_0085f150` (called with ECX=widget, EAX=window)

```text
cellX = widget[0x126]
cellY = widget[0x127]
px = *(window+0x50c)*cellX + *(window+0x504)
py = *(window+0x510)*cellY + *(window+0x508)
widget->vtbl+0x118(&px)   // set screen/local position
```

---

## 6. Callers

| Call site | Enclosing | Role |
|----------:|-----------|------|
| `0x008607b2` | `FUN_00860700` | Bulk: iterate resolved grid items → add each widget; then window `+0x34c` |
| `0x008c3132` | `FUN_008c3120` | Thin: if `*(parent+0x580)` and item → add one |
| (via thin) `0x008140c5` | `Client_RecvInventoryEquip` | Equip S2C path adds sheet icon |

Bulk parent also reached from trade UI, mission UI refresh, cargo/locker open helpers — sheet rebuild family (out of unit scope beyond call-graph note).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary / CF | **High** | live ≡ raw |
| EDI window + EBX item ABI | **High** | entry + both callers |
| Widget = inventory item template | **Confirmed** | ctor string in `FUN_0085e590` |
| COID key `+0x160/+0x164` | **High** | hash args + inventory family |
| typeHost `+0x56c`, pageH `+0x1c`, pageIdx `+0x564` | **High** | asm + sibling seal |
| Page-local Y formula | **High** | `imul`/`sub` at body |
| Hash insert + fail dtor | **High** | `FUN_00413920` + vtbl0(1) |
| Naming `…Sheet_AddItemWidget` | **High** | role; not a product symbol |
| Item vfunc `+0x250/+0x254` English | **Probable** | order sealed; names open |
| Window object product type | **Probable** | offsets shared with DropToGrid host |
| Runtime / bit-exact | **Open** | project deferred |

---

## 8. Gaps / open

1. Exact product class name of window at EDI (cargo vs locker vs trade pane share offsets).
2. Item vfunc `+0x250/+0x254` formal names (GetGridX/Y vs InvPos).
3. Full layout of widget beyond stamped fields.
4. Whether insert success path should treat HRESULT `1` specially (`FUN_00413920` can return `1` only when `param_5≠0`; here `param_5=0`, so practical success is `0`).
5. Runtime multi-page sheet (pageIdx≠0) visual check.

**Verdict:** **accept-with-gaps**
