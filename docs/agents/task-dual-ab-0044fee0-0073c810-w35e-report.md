# Dual A/B report — W35-E OWN `aa_0044fee0` + `aa_0073c810`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-E  
**Scope:** VAs `0x0044fee0`, `0x0073c810` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs/bulk xrefs + neighbor decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0044fee0` NestedHash0x10_StaticOnceGet_d1fcc0_Inferred | **accept** — once-flag + NestedHash0x10 static + atexit + RET sealed (90 B); product plate residual only |
| `aa_0073c810` HostPtrTable12_Bootstrap_EDI_Inferred | **accept-with-gaps** — EDI 12-slot ladder + sizes/vtbls/NestedHash wiring + return 0 sealed (862 B); 0 xrefs + product English open |

---

## VA `0x0044fee0` — sealed facts

1. **Body:** `0x0044fee0`–`0x0044ff39` (**90 B** / `0x5A`; pad `CC` then next).
2. **ABI:** no stack formals; plain **`RET`**; returns **`&DAT_00d1fcc0` in EAX**.
3. **Semantics:**
   - If **`DAT_00d1fce8` bit 0** clear → set bit; **`FUN_00457ac0(&DAT_00d1fcc0)`** (W34-E NestedHash_Ctor_Sentinel0x10); **`atexit(LAB_009c34b0)`**.
   - Always return address of static NestedHash shell.
4. **Layout:** static NestedHash span **0x28** at `DAT_00d1fcc0` (node size **0x10**).
5. **Classification:** **wrapper** / once-get factory.
6. **Callers (1 fn, 2 sites):** `FUN_0044fe10` @ `0x0044fe1f`, `0x0044fe33` (uses `*(get()+8)` sentinel).
7. **Callees:** `FUN_00457ac0`, `_atexit`.
8. **Name:** `NestedHash0x10_StaticOnceGet_d1fcc0_Inferred` (Ghidra `FUN_0044fee0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_*anmTrackEvents*`.
9. **Family:** twin static once-gets `FUN_00438c40` / `FUN_00438ca0` (other NestedHash0x10 statics).
10. **Decompile ≡ bytes** for flag/ctor/atexit/return.  
    Full hex: `64a1000000006aff681dca9b0050b8010000008405e8fcd1006489250000000075250905e8fcd10068c0fcd100c744240c00000000e8a67b000068b0349c00e8b299030083c4048b0c24b8c0fcd10064890d0000000083c40cc3`

### Gaps

- Product/PDB English for this specific static instance.  
- Unowned atexit dtor body.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044fee0_FUN_0044fee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044fee0.cpp` |
| Function | `docs/reconstruction/functions/aa_0044fee0_FUN_0044fee0.md` |
| Function named | `docs/reconstruction/functions/aa_0044fee0_NestedHash0x10_StaticOnceGet_d1fcc0_Inferred.md` |

---

## VA `0x0073c810` — sealed facts

1. **Body:** `0x0073c810`–`0x0073cb6d` (**862 B** / `0x35E`; pad `CC` then `FUN_0073cb70`).
2. **ABI:** **EDI = void\*\* host table** (register formal; prologue does not save EDI); no stack args; returns **0**; plain **`RET`** after `ADD ESP,0x10`.
3. **Semantics:** bootstrap **12** subsystem hosts into `EDI[0..11]` (+0x00..+0x2C):
   - **0–4,7–8:** `new(0xC4)` + `FUN_00748960` + dual vtbl pairs + typed init (`FUN_0099e6c0` … `FUN_0099f450(..., 10.0f)`).
   - **5:** `new(0x44)` + `FUN_00457720` + `FUN_00731130`.
   - **6:** `new(0x34)` inline multi-vtbl + `FUN_007300c0`.
   - **9:** `new(0x30)` + NestedHash0x10 + tail zeros + `FUN_0098fd80`.
   - **10:** `new(0x40)` + NestedHashBag0x18 + tail zeros + `FUN_0098df00`.
   - **11:** `new(0x14C)` + `FUN_00764030` + `FUN_007647c0(EDI[8])`.
4. **Host table span:** ≥ **0x30** (12 pointers).
5. **Classification:** **worker** (bootstrap).
6. **Callers:** **none recovered** (0 Ghidra xrefs) — gap.
7. **Callees:** `operator_new`, `FUN_00748960`, `FUN_00457720`, `FUN_00457ac0`, `FUN_00457b30`, `FUN_00764030`, plus per-slot inits listed in raw append.
8. **Name:** `HostPtrTable12_Bootstrap_EDI_Inferred` (Ghidra `FUN_0073c810`; **Inferred** structural). Neighbor `gfxToolFactory.cpp` is context only — not product plate for this body.
9. **Closes residuals:** W34-E NestedHash0x10 heap host caller; W34-G NestedHashBag0x18 sole caller.
10. **Decompile ≡ bytes** for EDI stores / sizes / RET 0. Full 862 B hex in raw W35-E append.

### Gaps

- Call site recovery (0 xrefs).  
- Product English for host class and each dual-vtbl subclass.  
- Unowned init callees' full contracts.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.md` |
| Annotated | `docs/reconstruction/raw/aa_0073c810_FUN_0073c810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostPtrTable12_Bootstrap_EDI_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073c810.cpp` |
| Function | `docs/reconstruction/functions/aa_0073c810_FUN_0073c810.md` |
| Function named | `docs/reconstruction/functions/aa_0073c810_HostPtrTable12_Bootstrap_EDI_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0044fee0` | Port as **process-static once-get**: no formals, returns `&g_nestedHash0x10_d1fcc0`. First call: flag bit0 + placement NestedHash0x10 ctor + atexit. Do **not** re-ctor each call. Do **not** hard-wire anmTrackEvents scaffold. Pair with W34-E `NestedHash_Ctor_Sentinel0x10`. |
| `0073c810` | Port as **EDI host-table bootstrap** of **12** pointers (span ≥ 0x30), return **0**. Not ECX-thiscall. Include NestedHash0x10 host@+0x24 and NestedHashBag0x18 host@+0x28 with tail zeros as sealed. Expect possible **indirect** call site (no static xrefs). Do not invent product "GfxToolFactory" plate without further evidence. |

Shared: both touch NestedHash0x10 family (static once-get vs heap slot in 12-table). Co-owned only by W35-E partition assignment; not the same runtime object.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + neighbor decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Rejected scaffold anmTrackEvents name for `0044fee0`.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit pointers).
