# Dual A/B report — W32-M OWN `aa_0043ece0` + `aa_0043ea50`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-M  
**Scope:** VAs `0x0043ece0`, `0x0043ea50` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-M).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043ece0` Pod8_CopyIfNonNull | **accept** — null-safe EAX/ECX two-dword store sealed (15 B) |
| `aa_0043ea50` PodU32U8_StoreSplit | **accept** — split pU32*/pU8* store, no null gate, RET 4 sealed (16 B) |

---

## VA `0x0043ece0` — sealed facts

1. **Body:** `0x0043ece0`–`0x0043ecee` (**15 B** / `0xF`; pad `CC` then `FUN_0043ecf0` W32-N).
2. **ABI:** **EAX=dest** (nullable), **ECX=`const PodU32x2* src`**, bare **`RET`**. Fastcall-style dual-register; not stack cdecl.
3. **Semantics:** If dest non-null, copy **two dwords** (`[0]` / `[+4]`); else no-op. Leaf.
4. **Classification:** worker leaf — store helper for stride-2 U32x2 push_back.
5. **Callers (1):** `FUN_0043e970` / `GuardedVector_PushBack_Stride2_U32x2` @ `0x0043e9cf` (EAX=slot, ECX=value*).
6. **Name:** `Pod8_CopyIfNonNull` (Ghidra `FUN_0043ece0`; **Inferred** structural; family W31-J PushBack store).
7. **Decompile ≡ raw CF**; **bytes win** on null gate + width. Full hex: raw W32-M append.

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.  
- Twin `0043ecf0` free (W32-N).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ece0_Pod8_CopyIfNonNull.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ece0_Pod8_CopyIfNonNull.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ece0_FUN_0043ece0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Pod8_CopyIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ece0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ece0_FUN_0043ece0.md` |
| Function named | `docs/reconstruction/functions/aa_0043ece0_Pod8_CopyIfNonNull.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ece0.md` |

---

## VA `0x0043ea50` — sealed facts

1. **Body:** `0x0043ea50`–`0x0043ea5f` (**16 B** / `0x10`; next is `FUN_0043ea60` GrowBlockMap_Stride2).
2. **ABI:** **EAX=dest** (not null-checked), **ECX=`const uint32_t* pU32`**, stack **`const uint8_t* pU8`**, **`RET 0x4`**. Decompiler `__thiscall` plate is incomplete — **bytes win**.
3. **Semantics:** `*(u32*)dest = *pU32`; `*((u8*)dest+4) = *pU8`. Write width **5**; trailing 3 bytes of an 8-byte slot untouched. Leaf.
4. **Classification:** worker leaf — split-source store for adapter `0043e8f0`.
5. **Callers (1):** `FUN_0043e8f0` @ `0x0043e8fb` (ESI→EAX dest; LEA/PUSH stack values as split pointers). Upstream parents of the adapter include `NDResourceCache_LookupOrCreate`, `FUN_0075de80`, ass/preloader rings (not owned).
6. **Name:** `PodU32U8_StoreSplit` (Ghidra `FUN_0043ea50`; **Inferred** structural).
7. **Decompile ≡ raw CF** for stores; **bytes win** on ABI (EAX dest, stack pU8, RET 4, no null gate). Full hex: raw W32-M append.

### Gaps

- Product/PDB English; element field names.  
- Parent adapter `0043e8f0` dual free.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ea50_PodU32U8_StoreSplit.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ea50_PodU32U8_StoreSplit.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ea50_FUN_0043ea50.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ea50_FUN_0043ea50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_StoreSplit.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ea50.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ea50_FUN_0043ea50.md` |
| Function named | `docs/reconstruction/functions/aa_0043ea50_PodU32U8_StoreSplit.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ea50.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043ece0` | Null-safe **8-byte** store: **EAX=dest**, **ECX=src** `{u32,u32}*`, bare **RET**. Use when slot base may be null (stride-2 push path). |
| `0043ea50` | **Split** u32* + u8* store: **EAX=dest**, **ECX=pU32**, stack **pU8**, **RET 4**. **No** null gate. Do **not** unify with contiguous `0043ecf0` / `0043ece0`. |

Shared contrast (do not collapse helpers):

| Unit | Null? | Sources | Width | RET |
|------|-------|---------|-------|-----|
| `0043ece0` | yes | contiguous u32×2 | 8 | bare |
| `0043ecf0` (W32-N) | yes | contiguous u32+u8 | 5 | bare |
| `0043ea50` | no | split u32* + u8* | 5 | 4 |

Closes W31-J residual on store helper `0043ece0`; seals nested store used by adapter `0043e8f0` family.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`Pod8_*` / `PodU32U8_*` family from W31-J store language).  
- Avoided bare `undefined4` in clean (used `uint32_t` / `uint8_t` / explicit POD structs).
