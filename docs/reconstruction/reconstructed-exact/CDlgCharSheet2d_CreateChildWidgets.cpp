// =============================================================================
// CDlgCharSheet2d_CreateChildWidgets
// -----------------------------------------------------------------------------
// Stable ID: aa_008faaf0
// Address:   0x008faaf0  (autoassault.exe, image base 0x400000)
// System:    client-ui / character sheet
// Generated: 2026-07-29 STRUCTURAL recovery (Ghidra decompile blocked)
// Exactness: NOT control-flow complete - image prolog + signature/strings.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/* CDlgCharSheet2d_CreateChildWidgets @ 0x008faaf0
 *
 * DECOMPILER BLOCKED: Overlapping input varnodes (Ghidra).
 * Recovery: get_function_signature + read_memory prolog (2026-07-29).
 *
 * Role: construct character-sheet 2D dialog children from i_d_c_2d_* /
 * i_d_tabs_c_2d_* XML — tab icon, identity chrome, experience/credits,
 * attribute panes + add buttons + tooltips, close button; optional
 * Client_MaybeShowFirstTimeTip.
 *
 * Virtual method: DATA xref only @ 0x00a35b30.
 *
 * Image-sealed construct pattern:
 *   FUN_00792600();
 *   operator_new(0x488) + FUN_0040ddd0;
 *   *(this+0x1478) = child; this->vtbl+0xA8 attach;
 *   child->vtbl+0x28 load "i_d_tabs_c_2d_wnd_icon.xml";
 *   further new/ctor/attach/XML (host +0x1464 observed);
 *   callees also FUN_007b5dd0, FUN_008a05a0, Client_MaybeShowFirstTimeTip.
 *
 * Full control-flow rewrite deferred until decompiler or manual asm walk.
 */
void __fastcall CDlgCharSheet2d_CreateChildWidgets(void *this)
{
    (void)this;
    /* Construction order (partial, image + string family):
     *  tab icon + icon cover
     *  bg_character / identity (title, name, level_race_class, clan)
     *  experience + credits labels/windows (wide variants)
     *  bg_attribs + four attrib panes (combat/theory/tech/perception)
     *  attrib add buttons + tooltip windows
     *  Client_MaybeShowFirstTimeTip on first-open path (tip id residual)
     *  close button
     */
    return;
}
