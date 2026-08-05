# Dual A/B report — W35-A OWN `aa_0043e630` + `aa_004ed310`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-A  
**Scope:** VAs `0x0043e630`, `0x004ed310` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-A).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043e630` GuardedVector_EraseFirstEqual_ThiscallRange | **accept-with-gaps** — ESI/RET4 + CS + first-equal erase via EraseRange_Thiscall sealed; product residual only |
| `aa_004ed310` AssPreloader_ProcessKeyRingStep_Inferred | **accept-with-gaps** — cdecl 3-arg + AL yield/done + gate + tracked-erase/enqueue/wait CF sealed; nested product residual |

---

## VA `0x0043e630` — sealed facts

1. **Body:** `0x0043e630`–`0x0043e6c1` (**146 B** / `0x92`; pad `CC`).
2. **ABI:** **ESI=container** (caller-established); stdcall **1** stack formal (`const int* key`); frame `SUB/ADD ESP,0x0C`; **`RET 0x4`**; return **AL** (0/1). Decompiler `unaff_ESI` + void surface — **bytes win**.
3. **Semantics:** Optional-CS first-equal erase:  
   - Gate `char +0x2c` → `Enter/LeaveCriticalSection(+0x14)`.  
   - Scan half-open `[begin, begin+size)` with family ring page map (`page=idx>>2`, wrap by capacity).  
   - On first `elem == *key` → `GuardedVector_EraseRange_Thiscall` (`0x0043df90`, **ECX=ESI**) with `[idx, idx+1)`; found=1; exit.  
   - Return found.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size, `+0x14` CS, `+0x2c` lock-enable (family).
5. **Classification:** **worker** — callees CS IAT + `FUN_0043df90`.
6. **Callers (2):** `FUN_00971030` @ `0x00971044` (`ADD ESI,0x1C` on AssPreloader this → pending ring); `NDResourceCache_LookupOrCreate` @ `0x0075ddb2` (`LEA ESI,[EBP+0x1C]`).
7. **Name:** `GuardedVector_EraseFirstEqual_ThiscallRange` (Ghidra `FUN_0043e630`; **Inferred** structural). Twin of W28-C `GuardedVector_EraseFirstEqual` (`0x0043c550`, same 146 B / ESI / RET4) which routes through EAX `FUN_0043c8c0`. **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043e630`.
8. **Decompile ≡ bytes** for linear CF; **bytes win** on ESI + RET 4 + nested thiscall.  
   Full hex: `83ec0c807e2c005355578d7e14897c240c740757ff15bc619c008b4e0c8b6e1032db03e93bcd74528bc1c1e8028d1485000000008bfa8bd12bd78b7e083bf877022bc78b7e048b04878b14908b44241c3b1074098b7c240c83c101ebc78bc183c001508bd65251568d4c2420518bcee8ecf8ffff8b7c240cb301807f1800740757ff15b8619c005f5d8ac35b83c40cc20400`

### Gaps

- Product/PDB class English.  
- Element type beyond dword POD equality.  
- Nested EraseRange free remains on W34-L.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e630_FUN_0043e630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_EraseFirstEqual_ThiscallRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e630.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e630_FUN_0043e630.md` |
| Function named | `docs/reconstruction/functions/aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` |

---

## VA `0x004ed310` — sealed facts

1. **Body:** `0x004ed310`–`0x004ed46b` (**348 B** / `0x15C`; pad `CC`).
2. **ABI:** **cdecl** 3 stack formals (`GuardedVector* ring`, `char* progress_flag`, `uint* cursor`); plain **`RET`**; return **AL** (1=done / 0=yield). Callers `ADD ESP,0xC`.
3. **Semantics:** Cooperative preload key-ring step under global AssPreloader:  
   - Gate: if `*(DAT_00d1f050+0x6c)==0` → return **1**.  
   - Clamp `*cursor` into `[0, ring->size)`.  
   - Walk absolute indices `begin+cursor`…`begin+size` with family page map.  
   - **Tracked** (`FUN_00971900` recurse=0, ECX=preloader): if flag set → `FUN_00971030` (pending remove); erase one via `FUN_0043df90`; resume out-iterator (no cursor++).  
   - **Untracked, flag==0:** if not cache-present (`FUN_0075d610`) and not tree-ready (`FUN_00971a20` recurse=0) → `FUN_009717a0` EnqueueKeyAndDeps; flag=1; return **0**.  
   - **Untracked, flag!=0:** if not cache-present → if not tree-ready return **0** else advance; if cache-present advance.  
   - Exhaust: cursor=0, flag=0, return **1**.
4. **Layout (ring):** same GuardedVector family `+0x04/+0x08/+0x0c/+0x10`.
5. **Classification:** **worker**.
6. **Callers (4 fns / 8 xrefs):** `FUN_00542790` (FxCache_ApplyWithNfxEnsure), `FUN_00542e20`, `FUN_005575c0`, `FUN_005c6ad0`.
7. **Name:** `AssPreloader_ProcessKeyRingStep_Inferred` (Ghidra `FUN_004ed310`; **Inferred** structural from AssPreloader nested duals + FxCache callers). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ed310`.
8. **Decompile ≡ bytes** for full CF; **bytes win** on cdecl + AL + gate.  
   Full hex: `a150f0d10083ec0883786c007506b00183c408c38b4c24148b0185c0558b6c24107c053b45107206c7010000000056578b7d0c03398bf5538b451003450c3bf575083bf80f84f70000008bc7c1e8028d0c85000000008bd18bcf2bca8b56083bd077022bc28b56048b04828d1c888b0d50f0d1008b496c6a0053e87145480084c08b5424207435803a00740ea150f0d1008b486c53e8863c48008bc783c001505657568d4c2420518bcde8d10bf5ff8b7424108b7c2414e97cffffff803a008b0d50f0d10053742ce83302270084c07541a150f0d1008b486c6a0053e82f46480084c074528b44242483000183c701e944ffffffe80702270084c075158b0d50f0d1008b496c6a0053e80246480084c0740f8b44242483000183c701e917ffffff8b1550f0d1008b4a6c53e8604348008b442420c600015b5f5e32c05d83c408c38b4c24248b5424205b5f5ec70100000000c60200b0015d83c408c3`

### Gaps

- Product/PDB method English.  
- Nested `FUN_0075d610` / `FUN_00971a20` / `FUN_00971030` product dual free (not owned).  
- Progress-flag product label.  
- Runtime / bit-exact / concurrent ring mutation.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.md` |
| Annotated | `docs/reconstruction/raw/aa_004ed310_FUN_004ed310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_ProcessKeyRingStep_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ed310.cpp` |
| Function | `docs/reconstruction/functions/aa_004ed310_FUN_004ed310.md` |
| Function named | `docs/reconstruction/functions/aa_004ed310_AssPreloader_ProcessKeyRingStep_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043e630` | First-equal erase with **ESI=container**, stack `key*`, **RET 4**, **AL** found; optional CS when `+0x2c`. Nested erase is **thiscall** `EraseRange_Thiscall` (W34-L) — do **not** call W28-C `0043c550` / EAX `0043c8c0` interchangeably without matching nested ABI. Used for AssPreloader pending ring at **+0x1c** via `00971030`. |
| `004ed310` | Port as **cdecl** cooperative step: `(ring*, flag*, cursor*) → AL`. Gate on global AssPreloader. Do **not** invent blocking full drain or AssPreloader thiscall method. Tracked keys erase in-place; first unready enqueues and yields; flag!=0 waits. Closes primary external residual of W31-K is-tracked + W32-J enqueue-key duals. |

Shared: both consume **EraseRange_Thiscall** (`0043df90`). `004ed310` may call `00971030` which in turn calls `0043e630` for pending-ring erase — co-owned only by partition; chain is AssPreloader preload progression.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0043c550` | W28-C EraseFirstEqual (ESI + EAX EraseRange twin) |
| `0x0043e5b0` | W30-B ContainsFirstEqual (no mutate) |
| `0x0043df90` | W34-L EraseRange_Thiscall |
| `0x00971900` | W31-K IsKeyTrackedRecursive |
| `0x009717a0` | W32-J EnqueueKeyAndDeps |
| `0x00971030` | AssPreloader pending-side remove (calls `0043e630`) |
| `0x00971a20` | AssPreloader tree-ready check |
| `0x0075d610` | NDResourceCache key-present |
| `0x00542790` | FxCache_ApplyWithNfxEnsure (primary caller of `004ed310`) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + get_function_by_address + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` family; `AssPreloader_*` from sealed nested duals + `assPreloader` family context).  
- Rejected scaffold VOG_DEBUG / Named_CalleeOf plates.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs / `uint8_t`).
