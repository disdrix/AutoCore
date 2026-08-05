# Dual A/B report — W22-F OWN `aa_007fd970` + `aa_00792490`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-F  
**Scope:** VAs `0x007fd970`, `0x00792490` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007fd970` Ui_WriteFormatColorD3d | **accept** — leaf color LUT, CL/EAX ABI, JT+idx tables, all case constants sealed |
| `aa_00792490` UiWidget_TeardownIfActive | **accept-with-gaps** — gate/CF/offsets/hash walk sealed; vtbl product English + owned type residual |

---

## VA `0x007fd970` — sealed facts

1. **Body:** `0x007fd970`–`0x007fda16` (167 B; leaf; multi-`RET`).
2. **ABI:** **EAX** = `uint8_t out[4]` / `D3DCOLOR*`; **CL** = format index; return EAX.
3. **Semantics:** write little-endian D3DCOLOR `AARRGGBB` as bytes `[B,G,R,A]`.
4. **Dispatch:** index table `@0x007fda3c` + jump table `@0x007fda18` (9 targets).
5. **Cases:** 0..4 palette; 100/0x65/0x66 pure R/G/B; else white (`0xFFFFFFFF`).
6. **Callees:** none.
7. **Callers (5 / 8 xrefs):** `FUN_00870e80`, `FUN_00871150`, `FUN_00814d80`, `FUN_00946c00`, `FUN_00871030`.
8. **Name:** `Ui_WriteFormatColorD3d` (Ghidra `FUN_007fd970`).
9. **Decompile ≡ bytes** for CF and constants; call-site CL often under-reported (bytes/callers fill).

### Gaps

- Product English for palette indices 0..4.  
- Full meaning of `node+0x1c` before `−0x0f` at map-marker caller.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007fd970_Ui_WriteFormatColorD3d.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_007fd970_Ui_WriteFormatColorD3d.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007fd970_FUN_007fd970.md` |
| Annotated | `docs/reconstruction/raw/aa_007fd970_FUN_007fd970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Ui_WriteFormatColorD3d.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fd970.cpp` |
| Function | `docs/reconstruction/functions/aa_007fd970_FUN_007fd970.md` |
| Function named | `docs/reconstruction/functions/aa_007fd970_Ui_WriteFormatColorD3d.md` |
| Scratch | `docs/reconstruction/tmp/a_007fd970.md` |

---

## VA `0x00792490` — sealed facts

1. **Body:** `0x00792490`–`0x007925ff` (368 B; worker; `POP EBX; POP ESI; RET`).
2. **ABI:** **ECX** = UI widget `this`; no stack args; void.
3. **Gate:** `vtbl+0x3d8()` nonzero required; else full early return.
4. **Teardown:** `vtbl+0x330(8)`; clear `+0x8c/+0xc8/+0x492`; release `+0x2ac`/`+0x2a8` (+ `FUN_0074e260`); `vtbl+0x58`; hash-walk children at `+0x4d8` via `vtbl+0xb0`; `vtbl+0x3b4`; optional `+0x2a8` dtor on `vtbl+0x1c0`; clear `+0x4c0/+0x4b8/+0x4bc/+0x4b4`.
5. **Hash:** lock byte `+0x1d`; chain `+0x14`; value `+0x8`; misuse logs `HashError:*` / `VOG_DEBUG_STOP`.
6. **Callees:** `FUN_0074e260`, `FUN_007a4480` + vtbl slots.
7. **Callers:** 100+; pattern `vtbl+0x3ac(); FUN_00792490();` (e.g. mission dialog flush).
8. **Name:** `UiWidget_TeardownIfActive` (Ghidra `FUN_00792490`).
9. **Decompile ≡ bytes** for CF/offsets; prior `Named_VOG_DEBUG_STOP_*` superseded.

### Gaps

- Product English for vtbl `+0x330/+0x3ac/+0xb0/+0x1c0`.  
- Concrete type of `+0x2ac` owned object.  
- Live teardown differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00792490_UiWidget_TeardownIfActive.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00792490_UiWidget_TeardownIfActive.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00792490_FUN_00792490.md` |
| Annotated | `docs/reconstruction/raw/aa_00792490_FUN_00792490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiWidget_TeardownIfActive.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00792490.cpp` |
| Function | `docs/reconstruction/functions/aa_00792490_FUN_00792490.md` |
| Function named | `docs/reconstruction/functions/aa_00792490_UiWidget_TeardownIfActive.md` |
| Scratch | `docs/reconstruction/tmp/a_00792490.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007fd970` | Client UI color LUT only — D3DCOLOR LE; do not invent server-side palette from this; preserve pure R/G/B indices 100/101/102. |
| `00792490` | Client widget close teardown — preserve `vtbl+0x3d8` gate or inactive widgets get force-cleared; typically after `vtbl+0x3ac`; not a server object lifecycle. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.
