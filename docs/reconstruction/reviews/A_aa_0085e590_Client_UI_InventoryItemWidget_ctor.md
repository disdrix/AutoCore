# Review A (reconstruction fidelity): `aa_0085e590` Client_UI_InventoryItemWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e590` |
| **VA** | `0x0085e590` |
| **Canonical name** | `Client_UI_InventoryItemWidget_ctor` |
| **Prior names** | `FUN_0085e590`, `Inv_i_g_2d_wnd_inventory_item_template_xml_0085e590` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0085e590_Client_UI_InventoryItemWidget_ctor.md` |
| **System** | `inventory-transfer` (UI sheet / item icon widget) |
| **Dual status** | **Present** (first dual seal) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-place constructor** for the inventory-sheet **item icon widget** (object size `0x514` from sole parent `FUN_008605b0`).

```text
// thiscall / placement-new style: ECX = raw memory from operator_new(0x514)
// returns this (param_1)
1. FUN_007b5dd0(this, 0)          // NDUI base init
2. *this = &PTR_FUN_00a65354      // inventory-item widget vtable
3. FUN_0085cd40()                 // secondary base / sheet-widget init
4. Zero/stamp inventory-specific fields (+0x492, +0xC7, +0x490, +0x491,
   +0x48C, +0x50C, +0x510, +0x494, +0x488=1, +0x4A8, +0x4AC)
5. NDUIWindow_LoadInterfaceFile("i_g_2d_wnd_inventory_item_template.xml")
6. FUN_0085dc30()                 // post-XML wire children
7. Load overlay texture slots:
   this[+0x50C] = broken-item overlay  ("i_g_2d_overlay_broken.dds")
   this[+0x510] = highlight overlay    ("i_g_2d_highlight.dds")
   (each: new(4) stub → string path → FUN_0096f3e0; fail → delete + null)
return this;
```

**Not** a packet builder. **Not** grid place / sell / grab. Pure UI widget materialize.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085e590_FUN_0085e590.md` |
| Annotated | `docs/reconstruction/raw/aa_0085e590_FUN_0085e590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085e590.cpp` (+ named stub) |
| Function record | `docs/reconstruction/functions/aa_0085e590_FUN_0085e590.md` |
| Live decompile | Ghidra `batch_decompile` / `decompile_function` `0x0085e590` ≡ raw |
| Parent dual | `A/B_aa_008605b0_Client_UI_InventorySheet_AddItemWidget` |
| Callers | `get_function_callers`: `FUN_008605b0`, `FUN_0085e730`, `FUN_00863380`, `FUN_0093e7e0` |

**Not performed:** `disassemble_bytes`, Launcher, live UI capture, Ghidra rename.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog / ExceptionList | **Yes** |
| Base `FUN_007b5dd0(this,0)` then vtbl `PTR_FUN_00a65354` | **Yes** |
| Field zero/stamp block | **Yes** |
| Load `i_g_2d_wnd_inventory_item_template.xml` | **Yes** |
| Broken DDS → `param_1[0x143]` (`+0x50C`) | **Yes** |
| Highlight DDS → `param_1[0x144]` (`+0x510`) | **Yes** |
| Fail path: `FUN_0096efd0` + `operator_delete` + null slot | **Yes** |
| Return `this` | **Yes** |

---

## 4. ABI / layout (SEALED where noted)

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX / param_1) | raw `0x514` bytes | parent `operator_new(0x514)` then call |
| return | `this` | decompiler `return param_1` |
| vtbl | `PTR_FUN_00a65354` | `*param_1 = &PTR_FUN_…` |

### Widget fields stamped at construct

| Offset | Decomp index | Init | Role (inferred) | Conf |
|-------:|-------------:|------|-----------------|------|
| `+0x0` | `[0]` | vtbl | inventory item widget | **High** |
| `+0x488` | `[0x122]` | `1` | enable/visible-ish default | **Probable** |
| `+0x48C` | `[0x123]` | `0` | — | **Open** |
| `+0x490` | `[0x124]` byte | `0` | — | **Open** |
| `+0x491` | byte | `0` | — | **Open** |
| `+0x492` | byte | `0` | — | **Open** |
| `+0xC7` (199) | byte | `0` | — | **Open** |
| `+0x494` | `[0x125]` | `0` | inventory type (parent later stamps) | **High** (parent dual) |
| `+0x498`/`+0x49c` | `[0x126]`/`[0x127]` | (not here) | cell X/Y (parent stamps) | **High** |
| `+0x4A8` | `[0x12a]` | `0` | — | **Open** |
| `+0x4AC` | `[299]` | `0` | — | **Open** |
| `+0x50C` | `[0x143]` | broken overlay handle* | **High** (string) |
| `+0x510` | `[0x144]` | highlight overlay handle* | **High** (string) |

\*Each is a heap `uint32` stub (`new(4); *p=0`) then texture-load path fills/replaces via `FUN_0096f3e0`.

---

## 5. Callers

| Enclosing | Role |
|-----------|------|
| `Client_UI_InventorySheet_AddItemWidget` `0x008605b0` | primary: sheet add after `new(0x514)` |
| `FUN_0085e730` | sibling ctor path (out of deep dual) |
| `FUN_00863380` / `FUN_0093e7e0` | other UI materialize sites |

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| Inventory item widget ctor (template XML) | **Confirmed** (string) |
| Broken / highlight overlay strings | **Confirmed** |
| Size `0x514` from parent alloc | **High** |
| Field English beyond overlays / type / cell | **Open / Probable** |
| Product class symbol | **Open** (`_ctor` is role name) |
| Runtime / bit-exact | **Open** |

---

## 7. Gaps

1. Full meaning of zeroed bytes `+0xC7`, `+0x491`, `+0x492`.
2. Exact type of overlay handle at `+0x50C`/`+0x510` (texture wrapper vs raw id).
3. Sibling callers `0085e730` / `00863380` full dual (out of unit).

**Verdict:** **accept-with-gaps**
