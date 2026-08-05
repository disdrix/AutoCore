# Annotated low-level: CDlgCharSheet2d_CreateChildWidgets

| Field | Value |
|---|---|
| Stable ID | `aa_008faaf0` |
| VA | `0x008faaf0` |
| System | client-ui / character sheet |
| Date | 2026-07-29 |

## Recovery notes

- Ghidra decompiler fails: **Overlapping input varnodes** (`decompile` / `force_decompile` / `pcode`).
- Recovered from `get_function_signature`, `analyze_function_complete`, `read_memory`, string search.
- Size: **671** instructions, **69** blocks, cyclomatic **~32**, **~30** calls, **30** string refs.
- UI CreateChildWidgets for 2D character sheet: XP/credits, four attributes + add + tooltips, identity chrome, tab icon, close; optional first-time tip.
- Virtual: sole xref DATA `0x00a35b30`.

## Image-sealed construct pattern

1. SEH prologue; `ESI = this` (ECX).
2. `FUN_00792600()` base init.
3. `operator_new(0x488)` + `FUN_0040ddd0` child ctor.
4. Store at **`this+0x1478`**; parent **`vtbl+0xA8`** attach.
5. Child **`vtbl+0x28`** load `i_d_tabs_c_2d_wnd_icon.xml` (`0x00a361f0`).
6. Further loads: icon cover (`vtbl+0x404` path), `i_d_c_2d_wnd_bg_character.xml`, more `new`/`attach`/XML.
7. Additional host slot **`this+0x1464`** observed mid-body.
8. Callees also include `FUN_007b5dd0`, `FUN_008a05a0`, `Client_MaybeShowFirstTimeTip`.

## XML / string anchors (complete body set)

- Tabs: `i_d_tabs_c_2d_wnd_icon.xml`, `i_d_tabs_c_2d_wnd_icon_cover.xml`
- Identity: title, name, level_race_class, clan, bg_character, bg_level_race_class
- XP: label_experience, bg_experience, experience, experience_wide
- Credits: label_credits, credits, credits_wide
- Attribs: bg_attribs, attribute_points, attrib_{combat,theory,tech,perception}
- Add buttons: btn_attrib_*_add
- Tooltips: tooltip_attrib_*
- Close: `i_d_c_2d_btn_close.xml`

## Pseudocode (structural)

```c
/* CDlgCharSheet2d_CreateChildWidgets @ 0x008faaf0
 *
 * DECOMPILER BLOCKED. Image prolog + signature recovery 2026-07-29.
 *
 * Role: construct character-sheet 2D dialog children from i_d_c_2d_* /
 * i_d_tabs_c_2d_* XML — tab icon, identity chrome, experience/credits,
 * attribute values + add buttons + tooltips, close; optional first-time tip.
 */
void __fastcall CDlgCharSheet2d_CreateChildWidgets(void *this)
{
    /* See raw capture for image hex + skeleton.
     * Full CF deferred until decompiler or complete asm walk.
     */
    (void)this;
}
```

## Open questions

- Full decompile after Ghidra varnode fix or manual asm reconstruction.
- Map all widget host offsets (beyond `+0x1478` / `+0x1464`).
- Exact `Client_MaybeShowFirstTimeTip` tip id and conditions.
- Vtable base + method slot English index.
