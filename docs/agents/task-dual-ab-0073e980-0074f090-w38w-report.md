# Dual A/B report — W38-W OWN `aa_0073e980` + `aa_0074f090`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-W  
**Scope:** VAs `0x0073e980`, `0x0074f090` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + callee/sibling decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-W).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0073e980` Gfx_EffectMap_ReleaseAllEntries_Inferred | **accept** — void/global tree walk / payload@`+0xC` release / iterator++ sealed (47 B) |
| `aa_0074f090` Gfx_GlobalEffect_OnDeviceReset_Inferred | **accept** — EAX holder / `+0xC` / vtbl`+0x118` / 0\|−1 / Global Effect plate sealed (46 B) |

---

## VA `0x0073e980` — sealed facts

1. **Body:** `0x0073e980`–`0x0073e9af` exclusive (**47 B** / `0x2F`; pad `CC` then next).
2. **ABI:** no formals; plain **`RET`** (`C3`). Frame: `PUSH ECX; PUSH ESI` / `POP ESI; POP ECX`.
3. **Semantics:** MSVC-style **tree for-each release** on global head **`DAT_00d1ee68`**:
   - `head = DAT_00d1ee68`; `cur = *head` (begin); end when `cur == head`.
   - Loop: `FUN_0073e780(cur[+0xC])` then **`FUN_004425f0`** with **`EDX=&cur`** (iterator++, isnil@`+0x11`).
   - Releases entry resources only — **does not erase** nodes.
4. **Classification:** worker.
5. **Callers (1):** `FUN_0075eff0` **`GfxDevice_Reset`** @ `0x0075f145` (shutdown, immediately before `FUN_0074f0c0`).
6. **Callees:** `FUN_0073e780` (payload release), `FUN_004425f0` (tree iterator++).
7. **Name:** `Gfx_EffectMap_ReleaseAllEntries_Inferred` (Ghidra `FUN_0073e980`; **Inferred**). **Reject** sole `Named_CalleeOf_Named_gfxDevice_0073e980`.
8. **Family:** map at `DAT_00d1ee64` / head `DAT_00d1ee68`; single-entry teardown neighbor `FUN_0073e800` (unowned).
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on stack `cur`, `LEA EDX,[ESP+4]`, payload `@+0xC`.  
   Full hex: raw W38-W append (47 B).

### Gaps

- Product map / value_type English.  
- Unowned `FUN_0073e780` / erase duals.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073e980_FUN_0073e980.md` |
| Annotated | `docs/reconstruction/raw/aa_0073e980_FUN_0073e980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_EffectMap_ReleaseAllEntries_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073e980.cpp` |
| Function | `docs/reconstruction/functions/aa_0073e980_FUN_0073e980.md` |
| Function named | `docs/reconstruction/functions/aa_0073e980_Gfx_EffectMap_ReleaseAllEntries_Inferred.md` |

---

## VA `0x0074f090` — sealed facts

1. **Body:** `0x0074f090`–`0x0074f0be` exclusive (**46 B** / `0x2E`; pad `CC`).
2. **ABI:** **EAX=`holder*`**; bare **`RET`**; return **0** | **`0xFFFFFFFF`**. Decompiler phantom `in_EAX` is real formal — **bytes win**.
3. **Semantics:** Global Effect **device-reset** step:
   - If `holder[+0xC] == 0` → return **0**.
   - Else `PUSH` inner; **`CALL [vtbl+0x118]`**; **`SETGE`/`SUB 1`** → **0** if status ≥ 0 else **−1**.
4. **Classification:** leaf (virtual call only; no static callees).
5. **Callers (1):** `FUN_0075eff0` **`GfxDevice_Reset`** @ `0x0075f333` — `EAX=*(*(EBP+0x760)+4)`; `JGE` success; fail log **`"Failed to Reset() device on Global Effect"`**.
6. **Callees:** virtual only (`vtbl[+0x118]`). Sibling shutdown: **`FUN_0074f0c0`** (vtbl `+0x10c` / `+0x114`).
7. **Name:** `Gfx_GlobalEffect_OnDeviceReset_Inferred` (Ghidra `FUN_0074f090`; **Inferred**, product plate-backed). **Reject** sole `Named_CalleeOf_Named_gfxDevice_0074f090`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX formal + SETGE map + null path form.  
   Full hex: raw W38-W append (46 B).

### Gaps

- Product holder / iface C++ type.  
- Exact vtbl[+0x118] English.  
- Reset-frame identity of `[EBP+0x760]+4`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074f090_FUN_0074f090.md` |
| Annotated | `docs/reconstruction/raw/aa_0074f090_FUN_0074f090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_GlobalEffect_OnDeviceReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074f090.cpp` |
| Function | `docs/reconstruction/functions/aa_0074f090_FUN_0074f090.md` |
| Function named | `docs/reconstruction/functions/aa_0074f090_Gfx_GlobalEffect_OnDeviceReset_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0073e980` | Port as **global effect-tree resource release**: no args; walk `DAT_00d1ee68` begin→end; `release(node[+0xC])` then tree iterator++. **Do not** erase nodes here. Call from device-reset **shutdown** before lost-device Global Effect pass. |
| `0074f090` | Port as **Global Effect OnReset wrapper**: **EAX=holder**, bare RET, return **0/−1**. Null `+0xC` → 0; else `vtbl[+0x118]` + status map. Wire into `GfxDevice_Reset` factory chain with product fail plate. |
| Shared | Both are **sole-callee leaves under `GfxDevice_Reset`** (W37-N): shutdown release-all vs rebuild Global Effect. Co-owned as W38-W partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `GfxDevice_Reset` (W37-N) — sole caller of both |
| `0x00754480` | `Palantir_ResetDevice` (W35-K) — outer wrapper |
| `0x0073e780` | Per-entry effect payload resource release |
| `0x004425f0` | MSVC tree iterator++ (isnil@`+0x11`) |
| `0x0074f0c0` | Sibling Global Effect lost-device / shutdown vcalls |
| `0x0073e800` | Single-entry teardown + map erase neighbor |
| `0x00d1ee68` | Global effect tree head/sentinel |
| `0x00d1ee64` | Map object family (erase path) |

Closes W38-W OWN pair: **effect-map release-all** (Reset shutdown) + **Global Effect OnReset** (Reset rebuild) left open as nested callees under sealed `GfxDevice_Reset`.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product PDB names; `_Inferred` structural names; Global Effect plate used only as role evidence.  
- Rejected long Named_CalleeOf scaffold aliases as sole names.  
- Avoided bare `undefined4` in clean (`void*` / explicit casts).  
- Distinguished release-all walk from erase (`0073e800`) and OnReset (`+0x118`) from lost-device sibling (`0074f0c0`).  
- Terminal coverage: **false** always.  
- Trio (raw / annotated / clean) + dual A/B filed per VA.
