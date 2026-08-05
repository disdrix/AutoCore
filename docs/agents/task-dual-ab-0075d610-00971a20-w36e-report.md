# Dual A/B report — W36-E OWN `aa_0075d610` + `aa_00971a20`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W36-E  
**Scope:** VAs `0x0075d610`, `0x00971a20` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + neighbor callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave36_partition_map.md` (W36-E).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0075d610` NDResourceCache_IsKeyPresent_Inferred | **accept-with-gaps** — thiscall/RET4/end+value gates/48 B sealed; product English open |
| `aa_00971a20` AssPreloader_IsKeyTreeReady_Inferred | **accept-with-gaps** — thiscall/RET8/tree/dep/present-OR/drain/341 B sealed; product + nested free open |

---

## VA `0x0075d610` — sealed facts

1. **Body:** `0x0075d610`–`0x0075d63f` (**48 B** / `0x30`; next body `0x0075d640`).
2. **ABI:** **ECX = NestedHash map / NDResourceCache head**; stack **`const void* key`**; **`RET 4`**; return **EAX 0/1**. Decompiler bare `undefined FUN(void)` is wrong.
3. **Semantics:**
   - Establish **EDI=cache**, **EBX=key\***; call **`HashMap_FindIterator_Inferred`** (`0x0044e8c0`) with `out_it` = &key stack slot (overwritten with node\*).
   - If **it == map.end(+0x08)** → **0**.
   - If **\*(void\*\*)(it + 0x0C) == NULL** → **0**.
   - Else → **1**.
4. **Classification:** **worker** / predicate wrapper — sole callee find.
5. **Callers (3 fn / 6 sites):**  
   - `FUN_004ed310` @ `0x004ed3d8`, `0x004ed404` — AssPreloader_ProcessKeyRingStep (W35-A)  
   - `FUN_00583fa0` @ `0x00583ff0`, `0x005841b9`, `0x005841cd` — LoadNextChildAsset  
   - `FUN_004b6ab0` @ `0x004b6b3b` — FX name preload gate
6. **Callees:** `FUN_0044e8c0` only.
7. **Name:** `NDResourceCache_IsKeyPresent_Inferred` (Ghidra `FUN_0075d610`; **Inferred** from NestedHash host + FindIterator + ProcessKeyRingStep “cache-present”). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`.
8. **Family:** present-check twin of inlined gates inside `00971a20` dep walk; consumer of W21-N find.
9. **Decompile ≡ bytes** for find/gates/RET4.  
   Full hex: `538b5c2408578d44240c8bf950e89e12cfff8b44240c3b47085f5b740e83780c007408b801000000c2040033c0c20400`

### Gaps

- Product/PDB method English.  
- Key object domain residual (shared with FindIterator).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075d610_FUN_0075d610.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d610_FUN_0075d610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResourceCache_IsKeyPresent_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d610.cpp` |
| Function | `docs/reconstruction/functions/aa_0075d610_FUN_0075d610.md` |
| Function named | `docs/reconstruction/functions/aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` |

---

## VA `0x00971a20` — sealed facts

1. **Body:** `0x00971a20`–`0x00971b74` (**341 B** / `0x155`; pad `CC`). SEH `LAB_009b09e1`.
2. **ABI:** **ECX = AssPreloader\***; stack **`(const void* key, char recurse)`**; **`RET 8`**; return **AL 0/1**.
3. **Semantics:**
   - Always **`FUN_00971480(this)`** (pending drain / already-loaded handling; plate `assPreloader.cpp`).
   - **Tree exact-find** on map@**+0x10** via **`FUN_0043d5e0`** (ECX=map, EBX=key\*, EAX=out); miss when node == **\*(this+0x14)** → return **0**.
   - If **recurse==0** OR **`*( *(this+0x110) + 0x64 ) == 0`** → return **1**.
   - Else: **`FUN_00744360(key, &local_vec)`** fill deps; for each dep (GuardedVector page map):
     - recurse **`IsKeyTreeReady(dep, 0)`**;
     - if dep not tree-ready **and** cache-miss/null-value (inlined `0044e8c0` on **cache@+0x110**, same end/+0x0C gates as peer) → dtor (`FUN_005b2ba0`), return **0**;
   - Dtor vec; return **1**.
4. **Layout:** tree map@+0x10 / end@+0x14; **`NDResourceCache*` @ +0x110**.
5. **Classification:** **worker** / readiness probe (side-effectful enter).
6. **Callers (6):** `FUN_004ed310`, `FUN_0075de80`, `FUN_0075e2d0`, `FUN_007b6f90`, `FUN_00952090`, self.
7. **Callees:** `FUN_00971480`, `FUN_0043d5e0`, `FUN_00744360`, self, `FUN_0044e8c0`, `FUN_005b2ba0`.
8. **Name:** `AssPreloader_IsKeyTreeReady_Inferred` (Ghidra `FUN_00971a20`; **Inferred** from AssPreloader plate + tree@+0x10 + W35-A “tree-ready”). **Reject** scaffold `Named_CalleeOf_Named_assManager_*`.
9. **Decompile ≡ bytes** for CF; **bytes win** on RET8, find register formals, key-slot reuse. Full 341 B hex in raw W36-E append.

### Gaps

- Product/PDB method English.  
- Unowned full contracts: `00971480` drain, `0043d5e0` map find, `00744360` dep fill.  
- Meaning/writers of **`cache+0x64`** gate.  
- Runtime / bit-exact / concurrent tree mutation.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00971a20_FUN_00971a20.md` |
| Annotated | `docs/reconstruction/raw/aa_00971a20_FUN_00971a20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_IsKeyTreeReady_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971a20.cpp` |
| Function | `docs/reconstruction/functions/aa_00971a20_FUN_00971a20.md` |
| Function named | `docs/reconstruction/functions/aa_00971a20_AssPreloader_IsKeyTreeReady_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0075d610` | Port as **thiscall** present predicate: ECX=cache (NestedHash head), stack key\*, **RET 4**, **EAX** 0/1. Present = find hit **and** value@node+0x0C non-null. Do **not** insert on miss. Pair with W21-N `HashMap_FindIterator` register ABI (EDI/EBX). |
| `00971a20` | Port as **thiscall** tree-ready probe: ECX=AssPreloader, `(key*, recurse)`, **RET 8**, **AL** 0/1. **Always drain** (`00971480`) first. recurse=0 → membership only. recurse!=0 + cache+0x64 → deps must be shallow-tree **or** cache-present. Do **not** deep-recurse deps. |

Shared: complementary gates used by **AssPreloader_ProcessKeyRingStep** (W35-A): enqueue/wait when **not present and not tree-ready**. Co-owned only by W36-E partition assignment; same preload progression chain.

### Lifecycle (relative)

```
AssPreloader_ProcessKeyRingStep (004ed310)
  cache = DAT_00d1f050
  preloader = *(cache + 0x6c)
  if !NDResourceCache_IsKeyPresent(cache, key)        // this dual 0075d610
     && !AssPreloader_IsKeyTreeReady(preloader, key, 0) // this dual 00971a20
    → EnqueueKeyAndDeps / yield
```

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0044e8c0` | W21-N HashMap_FindIterator |
| `0x004ed310` | W35-A ProcessKeyRingStep (primary consumer) |
| `0x0075d470` | W35-B NDResourceCache_Ctor |
| `0x00971480` | AssPreloader drain/pending (plate assPreloader.cpp) |
| `0x0043d5e0` | Map lower_bound exact write-out |
| `0x00744360` | W32-L family dep / preload list fill |
| `0x009717a0` | W32-J EnqueueKeyAndDeps |
| `0x00971900` | W31-K IsKeyTrackedRecursive |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + get_function_by_address + xrefs + neighbor callee decompile. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`NDResourceCache_IsKeyPresent`; `AssPreloader_IsKeyTreeReady` from plate + dual family).  
- Rejected scaffold VOG_DEBUG / Named_CalleeOf_assManager plates.  
- Avoided bare `undefined4` in clean (`uint32_t` / `uint8_t` / explicit structs).
