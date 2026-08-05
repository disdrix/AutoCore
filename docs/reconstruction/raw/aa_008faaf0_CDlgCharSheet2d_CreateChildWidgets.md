# Raw capture: CDlgCharSheet2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008faaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008faaf0` |
| **Canonical name** | `CDlgCharSheet2d_CreateChildWidgets` |
| **System** | client-ui / character sheet |
| **Capture timestamp** | `2026-07-29` (refresh; original structural 2026-07-23) |
| **Tool** | Ghidra MCP `get_function_signature` + `analyze_function_complete` + `read_memory` (decompile failed) |
| **Integrity** | Structural + image prolog; replace body when full decompile succeeds |

---

## Decompiler status

```
decompile_function / force_decompile / get_function_pcode @ 0x008faaf0:
  Low-level Error: Overlapping input varnodes
```

## Metrics (`get_function_signature`)

| Metric | Value |
|---|---|
| Instructions | 671 |
| Basic blocks | 69 |
| Edges | 99 |
| Calls | 30 |
| String refs | 30 |
| Cyclomatic | 32 |
| Params | 1 (`this` ECX) |

## Callees (unique)

`FUN_00792600`, `operator_new`, `FUN_0040ddd0`, `FUN_007b5dd0`, `FUN_008a05a0`, `Client_MaybeShowFirstTimeTip`

## Xrefs

| From | Type |
|---|---|
| `0x00a35b30` | DATA (vtable slot; dword = `0x008faaf0`) |

## Image prolog (hex @ `0x008faaf0`, 128 bytes)

```
6aff68bea99b0064a100000000506489250000000083ec08568bf1e8f07ae9ff
6888040000e878edb8ff83c40489442408c74424140000000085c0740a6a0050
e89bb2ebffeb0233c0535583cbff57895c24208b16508bce898678140000ff92
a80000008b8e781400008b0168f061a300ff50288b165368cc61a3008d442418
```

Decoded skeleton:

```c
/* SEH … */
/* this in ESI = ECX */
FUN_00792600();
child = operator_new(0x488);
if (child) FUN_0040ddd0(child, 0); else child = NULL;
*(this + 0x1478) = child;
this->vtbl[0xA8/4](this, child);           /* attach */
(*(child->vtbl + 0x28))(child, "i_d_tabs_c_2d_wnd_icon.xml");
/* … more new/ctor/attach/XML; this+0x1464; Client_MaybeShowFirstTimeTip … */
```

## String constants (function refs)

```
i_d_tabs_c_2d_wnd_icon.xml
i_d_tabs_c_2d_wnd_icon_cover.xml
i_d_c_2d_wnd_bg_character.xml
i_d_c_2d_wnd_bg_attribs.xml
i_d_c_2d_wnd_bg_level_race_class.xml
i_d_c_2d_wnd_bg_experience.xml
i_d_c_2d_wnd_title.xml
i_d_c_2d_wnd_name.xml
i_d_c_2d_wnd_level_race_class.xml
i_d_c_2d_wnd_clan.xml
i_d_c_2d_wnd_label_experience.xml
i_d_c_2d_wnd_experience.xml
i_d_c_2d_wnd_experience_wide.xml
i_d_c_2d_wnd_label_credits.xml
i_d_c_2d_wnd_credits.xml
i_d_c_2d_wnd_credits_wide.xml
i_d_c_2d_wnd_attribute_points.xml
i_d_c_2d_wnd_attrib_combat.xml
i_d_c_2d_wnd_attrib_theory.xml
i_d_c_2d_wnd_attrib_tech.xml
i_d_c_2d_wnd_attrib_perception.xml
i_d_c_2d_btn_attrib_combat_add.xml
i_d_c_2d_btn_attrib_theory_add.xml
i_d_c_2d_btn_attrib_tech_add.xml
i_d_c_2d_btn_attrib_perception_add.xml
i_d_c_2d_wnd_tooltip_attrib_combat.xml
i_d_c_2d_wnd_tooltip_attrib_theory.xml
i_d_c_2d_wnd_tooltip_attrib_tech.xml
i_d_c_2d_wnd_tooltip_attrib_perception.xml
i_d_c_2d_btn_close.xml
```

## Immediates (signature sample)

`-1, 40000, 32, 64, 1, 40001, 2, 40002, 3, 40003, 4, 40004, 5..12, 1160 (=0x488), 200, 20, 27`

## Structural pseudocode

```c
/* CDlgCharSheet2d_CreateChildWidgets @ 0x008faaf0
 *
 * DECOMPILER BLOCKED: Overlapping input varnodes (Ghidra).
 * Recovery: signature + string xrefs + read_memory prolog (2026-07-29).
 */
void __fastcall CDlgCharSheet2d_CreateChildWidgets(void *this)
{
    /* FUN_00792600();
     * for each child chrome:
     *   new(0x488) / ctor; store this+host; vtbl+0xA8 attach; vtbl+0x28 XML
     * known hosts: +0x1478 (tab icon path), +0x1464
     * assets: i_d_c_2d_* experience/credits/attribs/tooltips/close + tab icons
     * Client_MaybeShowFirstTimeTip(tipId?) — id residual
     */
    (void)this;
}
```
