# Dual A/B report — WQ9R-E OWN-ONLY (`0x005190c0`, `0x00519280`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9R-E**  
**Scope:** VAs `0x005190c0`, `0x00519280` only. Dual A/B + trio + clean.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-E**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005190c0` Object_EnsureIntKeyMapAt0x15c_Inferred | **accept-with-gaps** — lazy map ensure CF/ABI/`+0x15C`/0xC host/sentinel/`ret` sealed; product English open |
| `aa_00519280` MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred | **accept-with-gaps** — Mat* string seed CF/float4 bank/caller colors sealed; `FUN_0051def0` this residual |

---

## VA `0x005190c0` — sealed facts

1. **Body:** `0x005190c0`–`0x00519146` exclusive (**134 B** / `0x86`). Final **`C3`** after `ADD ESP,0x10`; pad `CC`.
2. **ABI:** **`__fastcall`/`__thiscall`**; ECX=`host*`; no stack formals; returns **map*** in EAX.
3. **Semantics:** MSVC-like **lazy int-key map ensure** at `host+0x15C`:
   - If slot non-null → return it.
   - Else `operator_new(0xC)` map host; `FUN_0040f400()` → `new(0x18)` sentinel; force is_nil `@+0x15=1`; self-link left/parent/right; `map+8=size 0`; store (null on OOM).
4. **Prologue (`read_memory`):** `6A FF 68 3C369A00` SEH; `8B D9`; `83 BB 5C010000 00` = `CMP [EBX+0x15C],0`; `75 4E` skip; `6A 0C` push size for `new`.
5. **Classification:** worker (ensure getter).
6. **Callers (2 fn / 12 xrefs):** `FUN_0052d450` (req aggregate — clear/find/insert via `Map_LowerBoundFindByIntKey` + `FUN_0040ed60`, keys from skill/item `+0x34`); `FUN_0089a260` case 7 membership probe.
7. **Related:** teardown frees `+0x15C` in `Object_SharedBase_Dtor` `0x00518ec0` (W29-G). Sentinel factory `FUN_0040f400` undualed here.
8. **Name:** `Object_EnsureIntKeyMapAt0x15c_Inferred` (Ghidra `FUN_005190c0`). Scaffold caller-chain alias **narrow — do not promote**.
9. **Decompile ≡ raw CF**; ABI/alloc sizes sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for host + map value type.  
- `map+0` field meaning (unwritten by ensure).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005190c0_Object_EnsureIntKeyMapAt0x15c_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005190c0_Object_EnsureIntKeyMapAt0x15c_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005190c0_FUN_005190c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005190c0_FUN_005190c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EnsureIntKeyMapAt0x15c_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005190c0.cpp` |
| Function | `docs/reconstruction/functions/aa_005190c0_FUN_005190c0.md` |
| Function named | `docs/reconstruction/functions/aa_005190c0_Object_EnsureIntKeyMapAt0x15c_Inferred.md` |

---

## VA `0x00519280` — sealed facts

1. **Body:** `0x00519280`–`0x005194f0` exclusive (**624 B** / `0x270`). Epilogue `5F 5E 5D 5B 83 C4 14 C3`; next fn `0x005194f0`.
2. **ABI:** stack — `src*`, `dstVecHost*`, plus **float4** (`r,g,b,a`) for `FUN_009700f0` @ stack `+0x0C`. Void. Ghidra 2-formal sig is **incomplete** vs callers.
3. **Semantics:** **material color bank seed**:
   - Count materials: `(src+0xC4 - src+0xC0) >> 2` (0 if begin null).
   - Local default float4 **`{0,0,0,1}`** (`g_flOne` @ `0x00A0F2A0` = `00 00 80 3F`).
   - Per index: for `"MatDiffuse"`, `"MatAmbient"`, `"MatEmissive"`: `FUN_0096f840(name, &default)` then push float4 into dst vector (`+4` begin / `+8` end / `+0xC` cap, stride **0x10**) via grow `FUN_0051d4a0` or copy `FUN_00608720` + `end+=0x10`.
   - Then `FUN_009700f0` applies **caller float4** to all three Mat* names.
4. **Head `FUN_0051def0`:** vector resize helper (0x10 stride); decompiler drops this/target — **residual**.
5. **Classification:** worker (FX/material seed).
6. **Callers (2):** `FUN_0051b2a0` (WQ9R-H — empty-bank gate; `src=*(vtbl+0x1CC()+8)`, `dst=host+0x51` → begin @ **0x148**); `FUN_004c5480` (wrapper + secondary bank).
7. **Name:** `MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred` (string evidence). **Not** a skill cast helper despite WQ-009 residual partition nesting.
8. **Decompile ≡ raw CF**; strings/float sealed by `read_memory`.

### Gaps

- `FUN_0051def0` exact this/vector at entry.  
- Whether loop loads `src_vec[i]` (decomp is count-only).  
- Product types for src material owner / host bank.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00519280_MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00519280_MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00519280_FUN_00519280.md` |
| Annotated | `docs/reconstruction/raw/aa_00519280_FUN_00519280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00519280.cpp` |
| Function | `docs/reconstruction/functions/aa_00519280_FUN_00519280.md` |
| Function named | `docs/reconstruction/functions/aa_00519280_MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005190c0` | Port as lazy map ensure: **never** double-create when `+0x15C` set; header **0xC**, sentinel **0x18** is_nil; pair free with SharedBase dtor. Callers must clear/rebuild before insert. |
| `00519280` | Port Mat* default seed only when bank empty (caller gate). Preserve 3× push per material + caller tint apply. Float4 stride **0x10**. |
| Pair with | `Map_LowerBoundFindByIntKey`, `FUN_0040ed60`, `FUN_0040f400`, `Object_SharedBase_Dtor` (`0x00518ec0`), `FUN_0051b2a0` (WQ9R-H). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names use structural + string evidence + `_Inferred`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
