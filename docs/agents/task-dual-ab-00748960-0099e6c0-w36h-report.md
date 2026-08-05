# Dual A/B report — W36-H OWN `aa_00748960` + `aa_0099e6c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-H  
**Scope:** VAs `0x00748960`, `0x0099e6c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + neighbor decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00748960` MeshHost0xC4_BaseCtor_Inferred | **accept** — ECX placement ctor of 0xC4 multi-vtbl mesh host; ±FLT_MAX triples + flag `0x81` @ +0xBC + return this sealed (336 B); product English residual only |
| `aa_0099e6c0` PalVisibleBoundingShape_EffectMaterialInit_Inferred | **accept** — ECX post-ctor FX/material init; product strings + sole HostPtrTable12 slot-0 caller + status OR sealed (469 B); unowned helper contracts open |

---

## VA `0x00748960` — sealed facts

1. **Body:** `0x00748960`–`0x00748aaf` (**336 B** / `0x150`; next `FUN_00748ab0`).
2. **ABI:** **ECX = self**; returns **self in EAX**; plain **`RET`** after `ADD ESP,0x10`.
3. **Semantics:**
   - Multi-vtbl: `+0x00 = PTR_FUN_00a9db64`, `+0x04 = PTR_LAB_00a9db58` (after interim `00a9db0c`), `+0x08 = PTR_FUN_00a9da80`.
   - Vector-construct **2×8 B** at `+0x10` (`FUN_00437440` / `FUN_00437450`).
   - Zero mid-fields; seed **`DAT_00aaa630` (+FLT_MAX)** ×3 @ `+0x3C` and **`DAT_00aaa63c` (−FLT_MAX)** ×3 @ `+0x48`.
   - Subobject `FUN_00437680(this+0x78)`; `+0xAC = −1`; **`*(byte*)(this+0xBC) |= 0x81`**.
4. **Object span:** **0xC4** (matches all `operator_new(0xC4)` callers).
5. **Classification:** **worker** / placement ctor.
6. **Callers:** **25** functions, **45** xrefs (incl. `FUN_0073c810`×7, `CVOGTacArc_InitializeMesh`, `FUN_004c1cb0`, …).
7. **Callees:** `_eh_vector_constructor_iterator_`, `FUN_00437680`.
8. **Name:** `MeshHost0xC4_BaseCtor_Inferred` (Ghidra `FUN_00748960`; **Inferred** structural).
9. **Family:** base shell for HostPtrTable12 dual-vtbl subclasses; often followed by vtbl[0]/[1] override.
10. **Decompile ≡ bytes** for vtbl / FLT_MAX / flag / return. Full 336 B hex in raw W36-H append.

### Gaps

- Product/PDB English for 0xC4 class and base vtbls.  
- Flag bit semantics beyond neighbor clear-bit0.  
- Unowned subobject contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00748960_FUN_00748960.md` |
| Annotated | `docs/reconstruction/raw/aa_00748960_FUN_00748960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshHost0xC4_BaseCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00748960.cpp` |
| Function | `docs/reconstruction/functions/aa_00748960_FUN_00748960.md` |
| Function named | `docs/reconstruction/functions/aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` |

---

## VA `0x0099e6c0` — sealed facts

1. **Body:** `0x0099e6c0`–`0x0099e894` (**469 B** / `0x1D5`; pad `CC` then next @ `0x0099e8a0`).
2. **ABI:** **ECX = self** (mesh host); returns **status OR** in EAX; plain **`RET`** after `ADD ESP,0x68`.
3. **Semantics:**
   - Load effect **`PalVisibleBoundingShape.fx`** (`0x00a244b0`) via `FUN_00989e00` / `FUN_009701d0` into `self+0x20`.
   - Temp material/desc: `FUN_0098ef00` + color `DAT_00d1a6c0..c8` + `g_flOne` + `FUN_0098f2b0(200)` + `FUN_00749d10`.
   - Bind four params: **`SolidMatDiffuse`**, **`SolidMatEmissive`**, **`WireMatDiffuse`**, **`WireMatEmissive`** (`FUN_00752370` + `FUN_0096fff0`).
   - Refcount swap via `FUN_0073d940` (AddRef first-use vfunc+4 / Release old vfunc+8).
   - Destroy temp `FUN_00457a00`; return `s_fx | s_mat | s0 | s1 | s2 | s3`.
4. **Classification:** **worker** (typed post-ctor init).
5. **Callers:** **1** — `FUN_0073c810` @ `0x0073c869` (HostPtrTable12 slot **0** after base ctor + dual vtbl).
6. **Callees:** `FUN_00989e00`, `FUN_009701d0`, `FUN_0098ef00`, `FUN_0098f2b0`, `FUN_00749d10`, `FUN_00752370`, `FUN_0096fff0`, `FUN_0073d940`, `FUN_00457a00`.
7. **Name:** `PalVisibleBoundingShape_EffectMaterialInit_Inferred` (Ghidra `FUN_0099e6c0`; **Inferred**; FX path is product evidence).
8. **Closes residual:** W35-E HostPtrTable12 slot-0 init callee named only as `FUN_0099e6c0`.
9. **Decompile ≡ bytes** for strings / OR return / sole xref. Full 469 B hex in raw W36-H append.

### Gaps

- Dual-vtbl subclass English (`00aa37b4` / `00aa37a8`).  
- Unowned FX/material helper contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0099e6c0_FUN_0099e6c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalVisibleBoundingShape_EffectMaterialInit_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0099e6c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0099e6c0_FUN_0099e6c0.md` |
| Function named | `docs/reconstruction/functions/aa_0099e6c0_PalVisibleBoundingShape_EffectMaterialInit_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00748960` | Port as **ECX placement ctor** of fixed **0xC4** multi-vtbl mesh host; return `self`. Init ±FLT_MAX float triples and flag `\|0x81` @ `+0xBC`. Expect callers to **override** vtbl[0]/[1] for subclasses. Pair with HostPtrTable12 and any `new(0xC4)+this` mesh paths. |
| `0099e6c0` | Port as **ECX post-ctor** FX/material init for **PalVisibleBoundingShape** only. Bind the four material names; return status OR (0 = clean). Sole caller HostPtrTable12 slot 0 — do not reuse for sibling slot FX without their own plates. |

Shared: W35-E HostPtrTable12 slot 0 pipeline = `new(0xC4)` → **`00748960`** → dual vtbl → **`0099e6c0`**. Co-owned by W36-H partition; ctor is widely reused, init is slot-specific.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + neighbor decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- No invented product class names without evidence; `_Inferred` structural names; FX filename used as product evidence for effect identity only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).
