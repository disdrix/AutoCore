# Dual A/B report — W23-N OWN `aa_00851630` + `aa_00859bc0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-N  
**Scope:** VAs `0x00851630`, `0x00859bc0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ `get_function_by_address` / `get_xrefs_to`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00851630` Client_UI_MapView_DrawMarkersFovOverlay | **accept-with-gaps** — thiscall/C3 + gates + phase map + FOV/cone constants sealed; nested draw leaves + product name open |
| `aa_00859bc0` Client_UI_MapView_DrawEntitiesFovOverlay | **accept-with-gaps** — thiscall/C3 + world list A/B + phase map + FOV scale chain sealed; list English + nested filters + product name open |

---

## VA `0x00851630` — sealed facts

1. **Body:** `0x00851630`–`0x00852428` (**3576 B** / `0xDF8`).
2. **ABI:** **`__thiscall`** (ECX = this*); `and esp,0xFFFFFFF0`; `sub esp,0x164`; plain **`ret` / `C3`**.
3. **Config host:** `this+0x488` (`param_1[0x122]`).
4. **Gate:** config* && `DAT_00d1b644` && `*(+0xe4e8)` && `DAT_00d1b6d8` && **`config+0x4fc != 0`**.
5. **Phases:** markers (`DAT_00d1d964`) → layer bump → auto-patrol → mission tree (`0x65`) → special (`100`) → squad (`1`) → FOV quad + optional sin-cone.
6. **Layer counters:** `this+0x68` ++, `+0x74 = (float)-layer`, max `+0x70`.
7. **Icon half-size:** `config+0x538/0x53c`; marker tex `+0x600+type*4` type 0..8.
8. **FOV:** half = `(1/viewportDim) * 300.0f` (`DAT_00aaa8a8`); cone if `sin(cfg+0x514 * 2.5f) > 0` (`DAT_00aaa6c4=2.5`, size scale `30.0`).
9. **Dispatch:** DATA vtbl only `@0x00a68204`.
10. **Name:** `Client_UI_MapView_DrawMarkersFovOverlay` (Ghidra `FUN_00851630`) — **INFERRED**.

### Gaps

- Product / PDB class+method English.  
- Nested dual of `FUN_008513d0` / `FUN_00757890` / project leaves.  
- Icon-type enum English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00851630_FUN_00851630.md` |
| Annotated | `docs/reconstruction/raw/aa_00851630_FUN_00851630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawMarkersFovOverlay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00851630.cpp` |
| Function | `docs/reconstruction/functions/aa_00851630_FUN_00851630.md` |
| Function named | `docs/reconstruction/functions/aa_00851630_Client_UI_MapView_DrawMarkersFovOverlay.md` |
| Scratch | `docs/reconstruction/tmp/a_00851630.md` |

---

## VA `0x00859bc0` — sealed facts

1. **Body:** `0x00859bc0`–`0x0085a9ef` (**3631 B** / `0xE2F`).
2. **ABI:** **`__thiscall`** (ECX = this*); align 16; `sub esp,0x104`; plain **`ret` / `C3`**.
3. **Config host:** `this+0x488`.
4. **Gate:** config* && local && world && listHost; list heads at world+`0x28` and +`0x48` required. **No** `+0x4fc` enable flag (unlike sibling).
5. **Phases:** world list A → bump → world list B → bump → markers → patrol → mission → special → squad → FOV quad.
6. **Draw path:** `FUN_00859260` (entity/marker), `FUN_00859a90` (icon-type dispatch).
7. **Textures:** entity `+0x5d0`; marker `+0x624+type*4`; FOV `+0x5cc`.
8. **FOV radius:** `cfg+0x514` optionally `* min(1,1)/cfg+0x500` when `+0x5b9==0`, then `* cfg+0x50c * 0.5` (`DAT_00a0f298`).
9. **Dispatch:** DATA vtbl only `@0x00a65a54`.
10. **Name:** `Client_UI_MapView_DrawEntitiesFovOverlay` (Ghidra `FUN_00859bc0`) — **INFERRED**.

### Gaps

- Product / PDB class+method English.  
- Semantic labels for world list A vs B.  
- Full entity filter flag dictionary.  
- Nested dual of `FUN_00859260` / `FUN_00859a90`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00859bc0_FUN_00859bc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_MapView_DrawEntitiesFovOverlay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00859bc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00859bc0_FUN_00859bc0.md` |
| Function named | `docs/reconstruction/functions/aa_00859bc0_Client_UI_MapView_DrawEntitiesFovOverlay.md` |
| Scratch | `docs/reconstruction/tmp/a_00859bc0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00851630` | **Client-only** map UI overlay. Do not port as sector sim authority. Honor `+0x4fc` gate; preserve layer bumps and FOV constants 300/2.5/30. |
| `00859bc0` | **Client-only** entity-rich map overlay. Preserve world list A/B filters; FOV ends with `* 0.5`. Not interchangeable with markers twin. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; W23-N live seal **appended**.
