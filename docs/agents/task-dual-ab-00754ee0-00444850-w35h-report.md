# Dual A/B report — W35-H OWN `aa_00754ee0` + `aa_00444850`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-H  
**Scope:** VAs `0x00754ee0`, `0x00444850` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00754ee0` GlyphCache_PlacementCtor | **accept-with-gaps** — stack this*/RET4/0xB8 layout/vtbl product + NestedHashBag nest sealed; default-global meaning + unwritten slots + dtor residual open |
| `aa_00444850` FourCCFnPtrMap_TryInsert_DAT_00d21958 | **accept-with-gaps** — EAX tag/ECX handler/map `DAT_00d21958` + discard-out sealed; `FUN_00458510` tree dual open |

---

## VA `0x00754ee0` — sealed facts

1. **Body:** `0x00754ee0`–`0x00754FAB` exclusive (**203 B** / `0xCB`; pad `CC` then next @ `0x00754FB0`).
2. **ABI:** stack **`this*`** placement ctor; **`RET 0x4`**; returns **`this` in EAX**. Not ECX-thiscall.
3. **Semantics:**
   - SEH `LAB_009b0971`.
   - `self+0x04 = 0` (refcount; sole caller later increments).
   - `*self = PTR_FUN_00a9f584` (GlyphCache vtbl).
   - Zero `+0x0c/+0x10/+0x14`.
   - `basic_string` default ctor at **`self+0x18`** (IAT).
   - Copy **`DAT_00d1f01c`/`DAT_00d1f020`** → `+0x38/+0x3c`; zero `+0x40`.
   - **`FUN_004438c0(self+0x44)`** — NestedHashBag_Ctor_Sentinel0x30 (W34-G sealed).
   - Zero `+0x70..+0x80` and `+0x94..+0xac`; re-copy defaults to `+0xb0/+0xb4`.
4. **Size:** host **`operator_new(0xB8)`** (sole caller). Unwritten here: **`+0x08`**, **`+0x84..+0x93`**.
5. **Product:** vtbl-adjacent string `"Failed to create texture for glyph cache"` → **GlyphCache** sealed. Vtbl[0] scalar dtor `0x00443460` → complete `FUN_00755970` (GDI DeleteObject/DeleteDC on late slots).
6. **Classification:** worker.
7. **Callers (1):** `FUN_0073bc50` @ `0x0073bd02` (font name path; `"Arial"` fallback; fail path vtbl delete).
8. **Callees:** IAT `basic_string` ctor; `FUN_004438c0`.
9. **Name:** `GlyphCache_PlacementCtor` (Ghidra `FUN_00754ee0`; **Inferred** role + product class evidence). **Reject** scaffold `Named_CalleeOf_*_gfxFont_*`.
10. **Decompile ≡ CF stores**; **bytes win** on ABI (`RET 4`, unwritten gaps). Full hex: raw W35-H append.

### Gaps

- Product meaning of `DAT_00d1f01c` / `DAT_00d1f020`.  
- Unwritten head/gap dwords; complete dtor / vtbl[2] duals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00754ee0_GlyphCache_PlacementCtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00754ee0_GlyphCache_PlacementCtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.md` |
| Annotated | `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GlyphCache_PlacementCtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754ee0.cpp` |
| Function | `docs/reconstruction/functions/aa_00754ee0_FUN_00754ee0.md` |
| Function named | `docs/reconstruction/functions/aa_00754ee0_GlyphCache_PlacementCtor.md` |
| Scratch | `docs/reconstruction/tmp/a_00754ee0.md` |

---

## VA `0x00444850` — sealed facts

1. **Body:** `0x00444850`–`0x00444874` exclusive (**36 B** / `0x24`; pad `CC` then `FUN_00444880`).
2. **ABI:** **EAX = FourCC `uint32` tag**; **ECX = handler function pointer**; bare **`RET`** (`C3`); void (out-pair discarded). No stack formals for the unit itself.
3. **Semantics:**
   - Build stack key `{tag, handler}`.
   - `EAX = &DAT_00d21958` (global tree-map object).
   - `FUN_00458510(out_pair)` — map lower_bound / insert-if-absent (unowned full dual).
   - Discard `{iterator, inserted?}`.
4. **Call sites (2, same parent):** `FUN_00754680` (Palantir device start, `Palantir.cpp` path):
   - `'EFCT'` `0x45464354` → handler `0x00990540`
   - `'MRPH'` `0x4d525048` → handler `0x009906e0`
5. **Sibling:** `FUN_00444880` identical pattern for map **`DAT_00d21964`** (e.g. `'SKEL'`).
6. **Classification:** wrapper.
7. **Callees:** `FUN_00458510`.
8. **Name:** `FourCCFnPtrMap_TryInsert_DAT_00d21958` (Ghidra `FUN_00444850`; **Inferred** structural). Not a Palantir member despite sole caller domain.
9. **Decompile ≢ bytes** on formals (void/no-arg); **bytes + call sites win**. Full hex: raw W35-H append.

### Gaps

- Full `FUN_00458510` / node layout dual; hit-update policy.  
- Product English for map and handlers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00444850_FUN_00444850.md` |
| Annotated | `docs/reconstruction/raw/aa_00444850_FUN_00444850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FourCCFnPtrMap_TryInsert_DAT_00d21958.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00444850.cpp` |
| Function | `docs/reconstruction/functions/aa_00444850_FUN_00444850.md` |
| Function named | `docs/reconstruction/functions/aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` |
| Scratch | `docs/reconstruction/tmp/a_00444850.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00754ee0` | Port as **placement ctor** (stack this, RET 4), host size **0xB8**. Set GlyphCache vtbl family; refcount0; string @`+0x18`; NestedHashBag @`+0x44` via W34-G helper; copy `DAT_00d1f01c/020` pairs. **Do not** assume ECX-thiscall or full-buffer zero. Free is **only** via scalar deleting dtor path. |
| `00444850` | Port as **register-ABI** map ensure: `tag` in **EAX**, `handler*` in **ECX**, map **`DAT_00d21958`**. Side-effect only. **Do not** merge with sibling map `DAT_00d21964`. Treat hit policy as find-or-insert until `FUN_00458510` sealed. |

Shared / related context:

| Symbol | Role |
|--------|------|
| `PTR_FUN_00a9f584` | GlyphCache vtbl (product string adjacent) |
| `FUN_004438c0` | NestedHashBag @ GlyphCache+0x44 (W34-G) |
| `DAT_00d1f01c` / `DAT_00d1f020` | default pair copied into GlyphCache (meaning open) |
| `DAT_00d21958` | FourCC→fn* map for this wrapper |
| `DAT_00d21964` | sibling map (`FUN_00444880`) |
| `FUN_0073bc50` | GlyphCache factory / font lookup |
| `FUN_00754680` | Palantir device start (registers EFCT/MRPH) |

Closes W35-H partition pair: GlyphCache placement ctor (closes host English gap left by W34-G NestedHashBag) + Palantir FourCC handler registration wrapper.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ caller bytes). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Product name GlyphCache from vtbl-adjacent string; map unit kept structural (FourCC + global address).  
- Avoided inventing handler product English beyond FourCC tags from immediates.
