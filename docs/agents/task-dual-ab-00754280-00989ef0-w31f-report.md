# Dual A/B report — W31-F OWN `aa_00754280` + `aa_00989ef0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-F  
**Scope:** VAs `0x00754280`, `0x00989ef0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave31.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00754280` Palantir_StartPreloadThread_Inferred | **accept-with-gaps** — EDI host + AL once-gate + thrThread create (ESI/EDX/AL) sealed; start-routine/product residual |
| `aa_00989ef0` ResourceCache_SetField10AndConfigure_Inferred | **accept-with-gaps** — EDI/ECX/RET4 + CS gate + subobject configure sealed; field/configure product residual |

---

## VA `0x00754280` — sealed facts

1. **Body:** `0x00754280`–`0x007542e8` (**105 B** / `0x69`; pad `CC` after last RET).
2. **ABI:** **EDI=host**; **0** stack formals; plain **`RET`**; return **AL** (0 already-running / 1 start-attempted).
3. **Semantics:**  
   - If `host+0xd4 != 0` → log Palantir.cpp:0x1fd level 2 `"Preload thread already runnning."` → AL=0.  
   - Else `operator_new(0x10)` thrThread: vftable `PTR_FUN_00a9e9bc`, zero id/handle, `+0x0c = *(DAT_00d1f050+0x6c)`; store at `host+0xd4` (null on OOM).  
   - `FUN_0071aef0` with **ESI=thread**, **EDX=0x40000**, **AL=0** (CreateThread stack reservation, not suspended; start `LAB_0071aed0`).  
   - AL=1 (even if new failed — retail CF).
4. **Layout:** host `+0xd4` thrThread*; thr `+0x00` vftable, `+0x04` id, `+0x08` HANDLE, `+0x0c` context.
5. **Classification:** worker — callees `vog_LogMessage`, `operator_new`, `FUN_0071aef0`.
6. **Callers (2):** `FUN_007b75b0` @ `0x007b7724` (`MOV EDI,[DAT_00d1f058]`), `FUN_00934420` @ `0x00934453` (same EDI load; "Preloading enabled").
7. **Name:** `Palantir_StartPreloadThread_Inferred` (Ghidra `FUN_00754280`; **Inferred** structural/plates).
8. **Decompile ≡ bytes** for CF; create-arg regs **from bytes** (decompiler incomplete).  
   Full hex: `5633f639b7d4000000741d68d8f7a9006a0268fd0100006810f9a900e81f2b240083c41032c05ec36a10e8e355d3ff83c4043bc6741d89700c897004897008c700bce9a9008b0d50f0d1008b516c89500c8bf0ba0000040032c089b7d4000000e80b6cfcffb0015ec3`

### Gaps

- Product/PDB method English.  
- thrThread start routine body (`LAB_0071aed0`) not OWN.  
- OOM still invokes create with null ESI (retail).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00754280_Palantir_StartPreloadThread_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00754280_Palantir_StartPreloadThread_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00754280_FUN_00754280.md` |
| Annotated | `docs/reconstruction/raw/aa_00754280_FUN_00754280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_StartPreloadThread_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00754280.cpp` |
| Function | `docs/reconstruction/functions/aa_00754280_FUN_00754280.md` |
| Function named | `docs/reconstruction/functions/aa_00754280_Palantir_StartPreloadThread_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00754280.md` |

---

## VA `0x00989ef0` — sealed facts

1. **Body:** `0x00989ef0`–`0x00989f58` (**105 B** / `0x69`; pad `CC` after `RET 4`).
2. **ABI:** **EDI=object**; **ECX=field10**; stdcall **1** stack formal (configure flag); **`RET 0x4`**; void. (Decompiler `__thiscall` label is **wrong** for this — this is EDI, not ECX.)
3. **Semantics:** SEH (`LAB_009adcf3`); if `+0x80` → Enter CS `+0x68`; `*(+0x10)=ECX`; `FUN_00996d70(stack)` with **EAX=`obj+0x14`**; if `+0x80` → Leave; unlink SEH.
4. **Layout:** `+0x10` dword, `+0x14` configure subobject, `+0x68` CS, `+0x80` flag — same lock family as `ResourceCache_LookupByName` (`0x00989e00`).
5. **Classification:** worker — callees Enter/LeaveCriticalSection, `FUN_00996d70`.
6. **Callers (2):** `FUN_007b75b0` @ `0x007b7745` (`MOV EDI,0x00d1eac8`; ECX `0x10000`/`0x40000` by mode bit2; push 0), `FUN_0099c1c0` @ `0x0099c22a` (local object; ECX `0x4000`; push 1).
7. **Name:** `ResourceCache_SetField10AndConfigure_Inferred` (Ghidra `FUN_00989ef0`; **Inferred** structural).
8. **Decompile ≡ bytes** for CF; EDI-this + EAX subobject + RET 4 sealed from bytes.  
   Full hex: `6aff68f3dc9a0064a10000000050648925000000005180bf800000000053568d77688bd989742408740756ff15bc619c008b44241c50c7442418000000008d4714895f10e837ce0000807e1800740756ff15b8619c008b4c240c5e5b64890d0000000083c410c20400`

### Gaps

- Product English for `+0x10` / configure flag.  
- Nested CF of `FUN_00996d70` (not OWN).  
- SEH unwind Leave guarantees.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ResourceCache_SetField10AndConfigure_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00989ef0.cpp` |
| Function | `docs/reconstruction/functions/aa_00989ef0_FUN_00989ef0.md` |
| Function named | `docs/reconstruction/functions/aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00989ef0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00754280` | Preload start must use **EDI=Palantir host** (`*DAT_00d1f058`), plain RET, **AL** already/started. Gate on `host+0xd4`; thrThread **0x10** with vftable `PTR_FUN_00a9e9bc` + context from `DAT_00d1f050+0x6c`; create via thrThread helper with **stack 0x40000**, not suspended. Do not invent ECX-thiscall. Do not treat OOM as AL=0 — retail returns 1. Closes AssManager / Preloading-enabled residual from W30-D. |
| `00989ef0` | ResourceCache-family configure: **EDI=object**, **ECX→+0x10**, stack flag, **RET 4**. Optional CS `+0x68` when `+0x80`. Configure callee must receive **EAX=obj+0x14**, not whole host. AssManager wires global `0x00d1eac8` with size-like ECX (`0x10000`/`0x40000`) and flag 0. Do not merge with LookupByName CF; share lock layout only. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`Palantir_*` from plates; `ResourceCache_*` from CS-layout pair with sealed `00989e00`).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
