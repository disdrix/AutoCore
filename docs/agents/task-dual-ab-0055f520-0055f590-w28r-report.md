# Dual A/B report — W28-R OWN `aa_0055f520` + `aa_0055f590`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-R  
**Scope:** VAs `0x0055f520`, `0x0055f590` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md` → W28-R  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0055f520` LocalWorklist16_Init_Inferred | **accept** — stride-16 worklist init CF/ABI + high-bit stamp sealed |
| `aa_0055f590` LocalWorklist16_Release_Inferred | **accept** — stride-16 worklist release CF/ABI + align/mask sealed |

---

## VA `0x0055f520` — sealed facts

1. **Body:** `0x0055f520`–`0x0055f588` (**105 B**); pad `CC` after `ret 4`.
2. **ABI:** **thiscall**; ECX = worklist desc; stack = element count; returns desc; **`ret 4`**.
3. **Size:** machine `align16(count*0x10)`; decompiler bare `count*0x10` (equivalent when already 16-aligned).
4. **Alloc:** if `arena[3] < size` → vcall `DAT_00b05060` **vtbl+0x24**; else bump `arena[2]+=size`, `arena[3]-=size`.
5. **Desc stamp:** `[0]=[3]=slab`, `[1]=0`, `[4]=count`, `[2]=count|0x80000000` (high bit → release skips tag free).
6. **Callers (2):** `FUN_006297e0` (`Phys_CommitPairListStorage_Inferred`), `FUN_00560750`.
7. **Name:** `LocalWorklist16_Init_Inferred` (Ghidra `FUN_0055f520`).
8. **Decompile ≡ bytes** for CF; clean adds machine align16.

### Gaps

- Product English for `DAT_00b05060` allocator.  
- Product descriptor type name.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055f520_LocalWorklist16_Init_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055f520_LocalWorklist16_Init_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.md` |
| Annotated | `docs/reconstruction/raw/aa_0055f520_FUN_0055f520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist16_Init_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f520.cpp` |
| Function | `docs/reconstruction/functions/aa_0055f520_FUN_0055f520.md` |
| Function named | `docs/reconstruction/functions/aa_0055f520_LocalWorklist16_Init_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055f520.md` |

---

## VA `0x0055f590` — sealed facts

1. **Body:** `0x0055f590`–`0x0055f5e7` (**88 B**); pad `CC` after `RET`.
2. **ABI:** **__fastcall/thiscall**; ECX = local worklist desc; **plain `ret`**; void.
3. **CF:** aligned size `(desc[+0x10]*0x10 + 0xf) & ~0xf`; bump `DAT_00b05060` counters **or** vcall `vtbl+0x28`; if `desc[+0x8]>=0` tagged free `vtbl+0x14` with tag **`0x12`** and nbytes **`(count & 0x7fffffff) << 4`**.
4. **Callers (1 / 1 xref):** `FUN_006297e0` only — always after init on pair-list commit.
5. **Role:** teardown twin of `LocalWorklist16_Init_Inferred`; stride-16 sibling of `LocalWorklist_Release_Inferred` (`0x0055f4c0`, *8).
6. **Name:** `LocalWorklist16_Release_Inferred` (Ghidra `FUN_0055f590`).
7. **Decompile ≡ bytes** for CF; clean adds machine align16 + `0x7fffffff` mask omitted by decompiler.

### Gaps

- Product English for `DAT_00b05060` allocator.  
- Full stack descriptor map beyond sealed offsets.  
- Whether any path clears high bit for tag free on this flavor (init always sets it).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055f590_LocalWorklist16_Release_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055f590_LocalWorklist16_Release_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.md` |
| Annotated | `docs/reconstruction/raw/aa_0055f590_FUN_0055f590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LocalWorklist16_Release_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055f590.cpp` |
| Function | `docs/reconstruction/functions/aa_0055f590_FUN_0055f590.md` |
| Function named | `docs/reconstruction/functions/aa_0055f590_LocalWorklist16_Release_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055f590.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055f520` | Pair-list / stride-16 worklist prep must use this init (not the *8 bind worklist). Preserve arena bump vs `vtbl+0x24`, **high-bit stamp** on `desc[+8]`, and **`ret 4`**. |
| `0055f590` | Always release after `Phys_CommitPairListStorage` worklist use. Preserve **align16(count*16)**, bump vs `vtbl+0x28`, and tagged free with **`0x7fffffff` mask + `<<4`** + tag `0x12`. **Do not** substitute `LocalWorklist_Release` (`0055f4c0`, *8) — wrong element size. Closes nested residual left open by W27-M CommitPairListStorage dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.
