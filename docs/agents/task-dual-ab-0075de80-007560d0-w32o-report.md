# Dual A/B report — W32-O OWN `aa_0075de80` + `aa_007560d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-O  
**Scope:** VAs `0x0075de80`, `0x007560d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-O).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0075de80` AssManager_SweepTrackedAssets_Inferred | **accept-with-gaps** — ABI RET8 + mode 1/2/other CF + list/secondary layout + assManager.cpp:0x1BB sealed; product method/mode enums open |
| `aa_007560d0` HostBase_DefaultCtor_Inferred | **accept-with-gaps** — full 175 B field map + vtbl/constants sealed; product class English + nested `0076c5xx` free |

---

## VA `0x0075de80` — sealed facts

1. **Body:** `0x0075de80`–`0x0075e2ce` exclusive (**1358 B** / `0x54E`; pad `CC`).
2. **ABI:** **`__thiscall`**; ECX=`assManager*` (`8B F1`); stack **mode** (`int`) + **ageThreshold** (`float`); **`RET 8`** (`C2 08 00`).
3. **Semantics:** Tracked-asset list sweep at **`this+0x08`**:
   - **mode 1:** optional secondary push (`this+0x6c` CS → `FUN_0043e9e0`); unlink; collect key + asset* into stack vectors; post-pass remap (`FUN_0044e8c0`…).
   - **mode 2:** age path — if asset idle (`+0x10==0`) and `(now - stamp) >= ageThreshold` → optional secondary erase, log **assManager.cpp:0x1BB**, release via vtbl[0], null slot; **single outer pass**.
   - **other (e.g. 0):** hard unload idle assets; **rescan while destroyed≥1**. Observed teardown caller `FUN_007544f0`: mode **0**, age **10.0f**.
4. **Layout:** list sentinel `+0x08`; secondary host `+0x6c` (CS @ host+`0xC0`, flag +`0xD8`). Node: `[2]` key, `[3]` asset*, `[4]` keep. Asset: `+0x10` idle, `+0x1C` stamp, CS `+0x20`, flag `+0x38`.
5. **Classification:** worker.
6. **Callers (7):** `FUN_007544f0`, `FUN_007b7000`, `FUN_004e09e0`, `FUN_008d4690`, `FUN_00937560`, `FUN_009521c0`, `FUN_009523d0`. **Xrefs:** 13.
7. **Name:** `AssManager_SweepTrackedAssets_Inferred` (Ghidra `FUN_0075de80`; **Inferred**). **Reject** scaffold `Named_assManager*`.
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); **bytes win** on ABI/prologue/epilogue. Nested PushBack site matches W31-J (`EAX` container).

### Gaps

- Product/PDB method name and mode enum English.  
- Asset static type / vtbl[0] product role.  
- `node[4]` / `FUN_00971a20` product meaning.  
- Runtime / bit-exact under CS.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075de80_FUN_0075de80.md` |
| Annotated | `docs/reconstruction/raw/aa_0075de80_FUN_0075de80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_SweepTrackedAssets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075de80.cpp` |
| Function | `docs/reconstruction/functions/aa_0075de80_FUN_0075de80.md` |
| Function named | `docs/reconstruction/functions/aa_0075de80_AssManager_SweepTrackedAssets_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0075de80.md` |

---

## VA `0x007560d0` — sealed facts

1. **Body:** `0x007560d0`–`0x0075617f` exclusive (**175 B** / `0xAF`; final `C3`; pad `CC`).
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`self*` (`8B F1`); **no stack formals**; returns **this**; plain **`RET`** after SEH `ADD ESP,0x10`.
3. **Semantics:** Shared **first-stage default ctor**:
   - vtbl **`PTR_FUN_00a9f534`**; zero `+0x04/+0x08`.
   - Subobject **`this+0x10`**: `FUN_0076c500(1000)` → `+0x40/+0x44=1000` → `FUN_0076c4d0`.
   - Zero mid; copy float4 **ones** from `DAT_00afdf40`; `+0x70=0`; `+0x74=g_flHardKillInterpolate` (**0.005f** @ `0x00AAA6A4`); byte `+0x78=1`.
   - Written span **≥ 0x79**; known peer alloc **`new(0x80)`** (UI host). Derived ctors often **replace vtbl**.
4. **Classification:** worker (default ctor).
5. **Callers (6):** `FUN_00492dd0` (PalantirEnv), `FUN_004c0640`, `FUN_0055c8c0`, `FUN_005b35a0`, `FUN_0078caf0`, `FUN_00792600`. **Xrefs:** 6.
6. **Callees:** `FUN_0076c500`, `FUN_0076c4d0` only.
7. **Name:** `HostBase_DefaultCtor_Inferred` (Ghidra `FUN_007560d0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007560d0`.
8. **Decompile ≡ raw CF**; **full body hex** sealed in raw W32-O append.

### Gaps

- Product/PDB class for base vtbl.  
- Nested `FUN_0076c500` / `FUN_0076c4d0` product roles.  
- Exact sizeof per most-derived beyond 0x80 peer.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007560d0_HostBase_DefaultCtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007560d0_HostBase_DefaultCtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007560d0_FUN_007560d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007560d0_FUN_007560d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostBase_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007560d0.cpp` |
| Function | `docs/reconstruction/functions/aa_007560d0_FUN_007560d0.md` |
| Function named | `docs/reconstruction/functions/aa_007560d0_HostBase_DefaultCtor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_007560d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0075de80` | Asset lifetime sweep: **ECX=assManager**, stack `(mode, ageThreshold)`, **RET 8**. Mode 1 = collect/rebind; mode 2 = single-pass age purge; other = hard unload with rescan. Idle test is **asset+0x10==0**. Do not trust decompiler `void(void)` or noreturn-on-delete. Nested push is **EAX-container** stride-2 U32U8 (W31-J). |
| `007560d0` | Shared host base ctor: **ECX=self**, return this, plain RET. Installs provisional vtbl then fog/hardkill defaults; **derived overwrites vtbl**. Subobject init at **+0x10** with arg **1000**. Hardkill float is **0.005f**, not 1.0f. Closes W31-P residual “role of FUN_007560d0” at the field-map level. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structural types).  
- Rejected weak scaffold aliases (`Named_assManager*`, `Named_CalleeOf_Named_VOG_DEBUG_STOP_*`).
