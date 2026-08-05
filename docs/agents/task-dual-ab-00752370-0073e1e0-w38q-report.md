# Dual A/B report — W38-Q OWN `aa_00752370` + `aa_0073e1e0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-Q  
**Scope:** VAs `0x00752370`, `0x0073e1e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + callee decompile context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00752370` EffEffect_FindParamIndexByName_Inferred | **accept** — thiscall + `ret 8` + handle→stride-8 index scan + miss −1 sealed |
| `aa_0073e1e0` EffEffect_CreateAndLoad_Inferred | **accept** — stdcall 3-arg + `ret 0xc` + freelist/init/load/fail-dtor/register sealed |

---

## VA `0x00752370` — sealed facts

1. **Body:** `0x00752370`–`0x007523cb` exclusive (**91 B** / `0x5b`; pad `CC` then next).
2. **ABI:** **`__thiscall`**; ECX = **effect shell***; stack **`(int* outIndex, nameOrToken)`**; epilogue **`RET 0x08`**. Out-param only (no meaningful EAX).
3. **Semantics:**
   - `inner = effect[+8]`; default index **−1**.
   - If `inner` and `inner[+0xc]` iface: `handle = iface.vtbl[+0x24](iface, 0, name)`.
   - If handle ≠ 0: linear scan `table=inner[+0x10]`, `count=inner[+0x18]`, **stride 8**, match dword0 → index; exhausted scan → **−1**.
   - Always writes `*outIndex`.
4. **Classification:** worker (indirect vtbl only; no direct FUN_* callees).
5. **Callers (35 fn / 86 xrefs):** material/FX bind helpers — `FUN_0075bf40` (`"DiffuseTexture"`), `FUN_0098fd80`, `FUN_0099f450`, `FUN_00731130`, `FUN_0098df00`, `FUN_004246a0`, `FUN_00442640`, `FUN_0043ed30`, `FUN_0043eea0`, `effEffect_Unserialize`, …
6. **Callees:** none direct; **indirect** param-iface `vtbl+0x24`.
7. **Name:** `EffEffect_FindParamIndexByName_Inferred` (Ghidra `FUN_00752370`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxDeviceVB_00752370`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on **`ret 8`**.  
   Full hex: raw W38-Q append (91 B).

### Gaps

- Product/PDB English for iface method / table payload dword1.  
- Name vs interned-token domain at call sites.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00752370_FUN_00752370.md` |
| Annotated | `docs/reconstruction/raw/aa_00752370_FUN_00752370.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffect_FindParamIndexByName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00752370.cpp` |
| Function | `docs/reconstruction/functions/aa_00752370_FUN_00752370.md` |
| Function named | `docs/reconstruction/functions/aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` |

---

## VA `0x0073e1e0` — sealed facts

1. **Body:** `0x0073e1e0`–`0x0073e257` exclusive (**119 B** / `0x77`; pad `CC` then next).
2. **ABI:** **stdcall** 3 stack args **`(manager*, pathOrToken, int* outStatus)`**; epilogue **`RET 0x0C`**; returns **effect*** or **null**.
3. **Semantics:**
   - Freelist alloc: `EDI=&DAT_00d21970`; `FUN_00457040` → block **0x30**.
   - Init: vtbl `PTR_FUN_00a9f9c4`; zero `+4..+0x18`/`+0x20`; `+0x1c/+0x1e = 0xFFFF`.
   - Load: **thiscall** `FUN_007533e0(ECX=path, obj, flag=0)`; `*outStatus = status`.
   - Fail (`status < 0`): if obj, **`vtbl[0](1)`** (`FUN_00445020`); return null.
   - Success: **thiscall** `FUN_0073d830(ECX=manager, obj)`; return obj.
4. **Classification:** worker.
5. **Callers (2):** `FUN_009701d0` EffEffectSlot_BindByPath @ `0x009701e7` (`DAT_00d1f61c`); `FUN_0072a660` gfxSubPhaseMap Phase*.fx @ `0x0072a92a`.
6. **Callees:** `FUN_00457040`, `FUN_007533e0`, `FUN_0073d830`, indirect `vtbl[0]` (`FUN_00445020`).
7. **Name:** `EffEffect_CreateAndLoad_Inferred` (Ghidra `FUN_0073e1e0`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxSubPhaseMap_0073e1e0`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on path/manager **ECX** into callees and **`ret 0xc`**.  
   Full hex: raw W38-Q append (119 B).

### Gaps

- Unowned load/register callee duals / full status domain.  
- Product class English for effect / manager.  
- Null freelist + successful load theoretical edge.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073e1e0_FUN_0073e1e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0073e1e0_FUN_0073e1e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffect_CreateAndLoad_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073e1e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0073e1e0_FUN_0073e1e0.md` |
| Function named | `docs/reconstruction/functions/aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00752370` | Port as **effect param index by name**: ECX=effect, stack out-index + name, **`ret 8`**, always write index or **−1**. Do **not** return index in EAX or strcmp against the dense table — resolve handle via iface `vtbl+0x24`, then stride-8 scan. Pairs with `FUN_0096fff0` set-param on hit (`index ≥ 0`). |
| `0073e1e0` | Port as **effect factory**: stdcall manager + path + out-status, **`ret 0xc`**, freelist shell, load, fail→dtor(1)+null, success→manager register + object*. Primary consumer is `EffEffectSlot_BindByPath` (W37-Q) which AddRefs and swaps into a slot. Do **not** model as the slot bind itself. |
| Shared | Same effect-shell type family (`+0` vtbl / `+4` refcount / `+8` inner). Loader produces shells; finder indexes params after load. Co-owned as W38-Q partition pair (create/load + param resolve). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x009701d0` | EffEffectSlot_BindByPath_Inferred (W37-Q) — primary loader caller |
| `0x007533e0` | Path/resource load into effect+8 (unowned) |
| `0x0073d830` | Manager list register (unowned) |
| `0x00457040` | Freelist pop for `DAT_00d21970` (unowned) |
| `0x00445020` | Scalar deleting dtor @ effect vtbl[0] |
| `0x00a9f9c4` | Effect vtbl (`PTR_FUN_00a9f9c4`) |
| `0x00d21970` | Effect freelist pool head |
| `0x00d1f61c` | Process effect manager* |
| `0x0096fff0` | Set-param by index (peer of finder) |
| `0x0075bf40` | GfxView diffuse clear — finder + `"DiffuseTexture"` |
| `0x0072a660` | gfxSubPhaseMap Phase*.fx secondary loader caller |

Closes W38-Q OWN pair: nested **effect create/load** left open under BindByPath + high-traffic **param index** helper used across material/FX bind paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (full file rewrite kept original decompile section).  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / `void*` / explicit layouts).  
- Distinguished finder (index out-param) from set-param peer and from slot-bind wrapper.  
- Distinguished decompiler callee signatures from **byte-sealed** ECX routing.  
- Terminal coverage: **false** always.
