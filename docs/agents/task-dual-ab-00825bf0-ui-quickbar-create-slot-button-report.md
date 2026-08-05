# Dual A/B report — `aa_00825bf0` UI_QuickBar_CreateSlotButton

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00825bf0`. Dual A/B + artifacts. Seal QB slot-button **ctor** + XML skin + field defaults.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` + callers/xrefs. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00825bf0` UI_QuickBar_CreateSlotButton | **accept-with-gaps** — **ctor / size / XML / key fields sealed** |

---

## Sealed facts

1. **Role:** In-place **constructor** for a QuickBar slot-button NDUI widget. Returns `this`. **No** packet, **no** skill cast, **no** page select.

2. **Object size `0x554`:** sole caller `FUN_008a16b0` allocates `operator_new(0x554)` at both sites before CALL.

3. **ABI:** `this` in object pointer (`param_1`); body is field init + callees; returns `this`.

4. **Sequence:**
   - SEH (`LAB_009b42b0`)
   - Base ctor **`FUN_00792d20(this)`** (base vtbl `PTR_FUN_00a98f44`)
   - Derived field defaults (below)
   - Vtable → **`PTR_FUN_00a75004`**
   - **`NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml")`**
   - return `this`

5. **Constants (`read_memory`):**
   | VA / name | Value | Written to |
   |---|---|---|
   | `DAT_00aaabc4` | **0.88f** (`ae47613f`) | `this+0x508` |
   | `g_flMultiKillCountBlend` @ `0x00a0f730` | **0.1f** (`cdcccc3d`) | `this+0x514` (shared float pool — **not** multi-kill semantics) |

6. **Key field defaults:**

   | Off | Init | Notes |
   |----:|------|-------|
   | `+0x00` | `PTR_FUN_00a75004` | Derived vtable |
   | `+0x4fc` | `0` | Selected/active flag |
   | `+0x4fd`, `+0x4fe` | `0` | Flags |
   | `+0x500` | **`0xFFFFFFFF`** | Slot/column index sentinel |
   | `+0x508` | **0.88f** | Default `DOWN_SIZE_RATIO` (sibling `FUN_00825cd0` also writes `+0x504`) |
   | `+0x50c`, `+0x510` | `0` | |
   | `+0x514` | **0.1f** | |
   | `+0x540..+0x550` | `0` (5 dwords) | `+0x548` later label child* after XML |
   | `+0xbf`, `+0xc7`, `+0x490` | `0` | Flag bytes |

7. **Callers (exactly 2 xrefs, one parent):**
   - `FUN_008a16b0` @ `0x008a19d2` → store `host[0x19b]` (`+0x66c`); stamp `+0x500=0`; label `"1"` via `+0x548`
   - `FUN_008a16b0` @ `0x008a1b1c` → store `host[0x19c]` (`+0x670`); stamp `+0x500=1`; label `"2"`

8. **Related (not this unit):** dtor `FUN_00825bb0` (same vtbl); XML attr parser `FUN_00825cd0` (`DOWN_SIZE_RATIO`).

9. **Not** QuickBarUpdate `0x2062`, **not** `Client_QuickBar_ActivateSlot`, **not** `QuickBar_SelectPage`.

---

## Gaps

1. Product/RTTI class name for `PTR_FUN_00a75004`.  
2. English meaning of residual floats/dwords (`+0x50c/+0x510/+0x514`, non-label `+0x54x`).  
3. Whether the 10 page-column widgets share this class / this ctor VA (only two xrefs known).  
4. Base ctor `FUN_00792d20` full layout (out of unit).  
5. Runtime / bit-for-bit / differential open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| Function record | `docs/reconstruction/functions/aa_00825bf0_UI_QuickBar_CreateSlotButton.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBar_CreateSlotButton.cpp` |
| Raw (authoritative + live append) | `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.md` |
| Annotated | `docs/reconstruction/raw/aa_00825bf0_FUN_00825bf0.annotated.md` |
| Scratch | `tmp/a_00825bf0.md` |
| This report | `docs/agents/task-dual-ab-00825bf0-ui-quickbar-create-slot-button-report.md` |

Legacy scaffolds retained:  
`functions/aa_00825bf0_FUN_00825bf0.md`,  
`reconstructed-exact/FUN_00825bf0.cpp`,  
`reconstructed-exact/Skill_i_d_qb_2d_btn_quickbar_xml_00825bf0.cpp`.

Registry: `NAMING_REGISTRY.md` → `UI_QuickBar_CreateSlotButton` (quickbar.xml).

---

## AutoCore impact

- **Client UI only** — no server packet, no skill persistence change.  
- Do not map this VA to QuickBarUpdate `0x2062` or cast paths.  
- If emulating client chrome: object **`0x554`**, skin **`i_d_qb_2d_btn_quickbar.xml`**, default scale **0.88** at `+0x508`, index sentinel **−1** at `+0x500` until host stamps column.  
- Known host wiring places **two** instances (labels 1/2) under `FUN_008a16b0`; full 10-slot page rebind is other code (`FUN_008a0e10` / SelectPage family).
