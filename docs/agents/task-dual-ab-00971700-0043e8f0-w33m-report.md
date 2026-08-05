# Dual A/B report — W33-M OWN `aa_00971700` + `aa_0043e8f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-M  
**Scope:** VAs `0x00971700`, `0x0043e8f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs + `disassemble_function` listing). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00971700` AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred | **accept** — ECX host + cache-ctx span snapshot + InsertRange→EnqueueEligible→dtor sealed (150 B; 0 static xrefs) |
| `aa_0043e8f0` PodU32U8_StoreByValue | **accept** — ESI dest + by-value stack u32/u8 → StoreSplit adapter sealed (19 B; cdecl) |

---

## VA `0x00971700` — sealed facts

1. **Body:** `0x00971700`–`0x00971795` (**150 B** / `0x96`; pad `CC` then `FUN_009717a0`).
2. **ABI:** **ECX=`AssPreloader* host`** (`MOV ESI,ECX`); bare **`RET`**; **returns 0**.
3. **Semantics:** Zero local GuardedVector; load `ctx = *(*(host+0x110)+0x64)`; take linear span **`first=*(ctx+0x50)`**, **`last=*(ctx+0x54)`**; `FUN_0043df90` erase/init; `GuardedVector_InsertRange` copy span into local; `AssPreloader_EnqueueEligibleFromRing` (ESI=local, stack=host); `FUN_005b2ba0` destroy local.
4. **Classification:** AssPreloader worker — **no** per-key dep expand (contrast `009717a0` / `00971820`).
5. **Callers (0):** Ghidra xref_count=0 (orphan static; body still sealable via family callees).
6. **Name:** `AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred` (Ghidra `FUN_00971700`; **Inferred** structural; family W31-K enqueue + W32-G InsertRange).
7. **Decompile ≡ raw CF**; **bytes win** on ESI/host preserve and InsertRange push count. Full hex: raw W33-M append.

### Gaps

- Product/PDB English for cache-ctx `+0x50`/`+0x54`.  
- Why zero static xrefs.  
- Nested `0043df90` / `005b2ba0` dual free.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00971700_FUN_00971700.md` |
| Annotated | `docs/reconstruction/raw/aa_00971700_FUN_00971700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971700.cpp` |
| Function | `docs/reconstruction/functions/aa_00971700_FUN_00971700.md` |
| Function named | `docs/reconstruction/functions/aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00971700.md` |

---

## VA `0x0043e8f0` — sealed facts

1. **Body:** `0x0043e8f0`–`0x0043e902` (**19 B** / `0x13`; pad `CC`).
2. **ABI:** **ESI=dest**; stack **by-value** `u32` + `u8` (dword slot); bare **`RET`** (**cdecl** — callers `ADD ESP,8`); **returns dest in EAX**. Decompiler `void()` plate is incomplete — **bytes win**.
3. **Semantics:** `LEA` addresses of stack values → `PodU32U8_StoreSplit` (W32-M); write width **5** at dest; return ESI.
4. **Classification:** wrapper leaf-adapter — sole callee `0043ea50`.
5. **Callers (9 xrefs / 6 fns):** `NDResourceCache_LookupOrCreate` @ `0075dd96`; `FUN_00970b20` @ `00970b36`; `FUN_00970b60` @ `00970b76`; `FUN_0075de80` (×4); `FUN_0075d3c0` @ `0075d437`; `FUN_00970e50` @ `00970f30`.
6. **Name:** `PodU32U8_StoreByValue` (Ghidra `FUN_0043e8f0`; **Inferred** structural; closes W32-M parent-adapter residual).
7. **Decompile ≡ partial**; **bytes win** on ESI/dual LEA/return. Full hex: `8D442408508D4C24088BC6E8500100008BC6C3`.

### Gaps

- Product/PDB element field English.  
- Parent wrappers `00970b20`/`00970b60` dual free (W33-N).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e8f0_PodU32U8_StoreByValue.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e8f0_PodU32U8_StoreByValue.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e8f0_FUN_0043e8f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e8f0_FUN_0043e8f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_StoreByValue.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e8f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e8f0_FUN_0043e8f0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e8f0_PodU32U8_StoreByValue.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e8f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00971700` | **ECX=host**, bare **RET**, return **0**. Snapshot `*(*(host+0x110)+0x64)` span `+0x50..+0x54` into local GuardedVector, then `EnqueueEligibleFromRing`. Do **not** collapse with ExpandDeps siblings. No static callers found — do not invent entry without evidence. |
| `0043e8f0` | **ESI=dest**, stack **by-value** u32+u8, bare **RET** (caller cleans 8), returns dest. Adapts to `PodU32U8_StoreSplit`. Do **not** use null-safe contiguous `0043ecf0` / `0043ece0` ABIs. |

Shared family context (not re-owned):

| Unit | Role |
|------|------|
| `0043ea50` | Split-pointer store (nested of `0043e8f0`) |
| `0043e7f0` | Locked stride-2 U32U8 push (typical post-materialize) |
| `00971640` | Enqueue eligible from ring (nested of `00971700`) |
| `0044e1c0` | InsertRange (nested of `00971700`; sole known caller) |

Closes W32-M residual on parent adapter `0043e8f0`; seals AssPreloader span-snapshot worker `00971700` (InsertRange sole-caller context).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + disassemble_function listing. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`AssPreloader_*` / `PodU32U8_*` family).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit POD + header structs).
