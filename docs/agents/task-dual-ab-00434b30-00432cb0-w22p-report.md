# Dual A/B report — W22-P OWN `0x00434b30` + `0x00432cb0`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00434b30`, `0x00432cb0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees / assembly_context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00434b30` `NDAssetImage_DecodeTgaRleRow_Inferred` | **accept-with-gaps** — 617 B RLE row, `RET 0x18`, AL state carry, bpp tables sealed; product name open |
| `aa_00432cb0` `NDAssetImage_DecodeByFormat_Inferred` | **accept-with-gaps** — 1039 B dispatch, EAX mode 0..4, auto TGA→PNG→BMP→other + string sealed; mode-4 English open |

---

## `0x00434b30` — NDAssetImage_DecodeTgaRleRow_Inferred

### Sealed facts

1. **Body** `0x00434b30`–`0x00434d99` (**617 / `0x269` bytes**).
2. **ABI:** thiscall **ECX = stream\***; stack **6 formals**; **`RET 0x18`**; return **AL = RLE carry state** (`0xFF` = read new packet next row).
3. **RLE math:** high bit → run = `pkt − 0x7F` (= `(pkt&0x7F)+1`); raw → run = `pkt+1`.
4. **bpp switch** via tables `@0x00434d9c` / `@0x00434db0`: **8 / 15 / 16 / 24 / 32**.
5. **Cross-row:** overflow encodes leftover into state; RLE path `vtbl+0x14` then `vtbl+0x10(pos,0)` rewind.
6. **Pitch:** if `*(short*)(row_ctx+0x16)==0x18` advance dest by `run×3`, else `run`.
7. **32bpp:** write 3 B RGB + `FUN_00433280` alpha helper; raw packets → `FUN_00434dd0`.
8. **Sole caller:** `NDAssetImage_LoadTGA` `@0x00434a34` (stores AL into row state).

### Gaps

1. Product helper name.  
2. Stream method English for `vtbl+0x10(pos,0)`.  
3. Dual of `FUN_00434dd0` / full `FUN_00433280` reg ABI.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00434b30_NDAssetImage_DecodeTgaRleRow_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00434b30_FUN_00434b30.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeTgaRleRow_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00434b30.cpp` |
| Raw (authoritative + re-verify append) | `docs/reconstruction/raw/aa_00434b30_FUN_00434b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00434b30_FUN_00434b30.annotated.md` |
| Scratch | `tmp/a_00434b30.md` |

---

## `0x00432cb0` — NDAssetImage_DecodeByFormat_Inferred

### Sealed facts

1. **Body** `0x00432cb0`–`0x004330bf` (**1039 / `0x40F` bytes**).
2. **ABI:** **EAX = format mode** `0..4`; **ECX = stream\***; stack **context\***; **`RET 4`**; return **1|0**.
3. **Modes:**
   - **0 auto:** save pos → **TGA** → rewind → **PNG (`FUN_00435410`)** → rewind → **BMP (`FUN_00433dc0`)** → rewind → **`FUN_0098b5b0`**.
   - **1** BMP only; **2** PNG only; **3** TGA (`FUN_00432af0` + LoadTGA); **4** residual prep + `FUN_0098b5b0`.
   - **else / total fail:** copy **`"Decode: Unknown or wrong format"`** (32 B) to `context+0x44`; return **0**.
4. **Success:** `FUN_00432580(context)`; dtor stack image (`PTR_FUN_00a9bcac` family); return **1**.
5. **Stack image seed:** optional `rep movsd` **0x5F** dwords from `context+0x30`.
6. **Callers:** `FUN_00432be0` `@0x00432c16`, `FUN_00432c50` `@0x00432c72` (both set EAX then call).

### Gaps

1. Product dispatcher name.  
2. Mode-4 / `FUN_0098b5b0` format English.  
3. Dual of ctor/dtor/commit helpers; full context layout.  
4. BMP stream formal (decomp image-only).  
5. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00432cb0_FUN_00432cb0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeByFormat_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00432cb0.cpp` |
| Raw (authoritative + re-verify append) | `docs/reconstruction/raw/aa_00432cb0_FUN_00432cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00432cb0_FUN_00432cb0.annotated.md` |
| Scratch | `tmp/a_00432cb0.md` |

---

## AutoCore impact

- **Client assets / terrain maps:** `DecodeByFormat` is the multi-format entry that auto-tries TGA (incl. RLE via `DecodeTgaRleRow` inside sealed `NDAssetImage_LoadTGA`), PNG, BMP, then residual. Server does not need these decoders for authoritative state; client-fidelity tooling or offline asset pipelines that reimplement loaders should honor:
  - TGA RLE packet math + cross-row state carry
  - auto order TGA→PNG→BMP→other with stream rewinds
  - error string sink at context `+0x44`
- No Launcher / live server work required for these units.

---

## This report

`docs/agents/task-dual-ab-00434b30-00432cb0-w22p-report.md`
