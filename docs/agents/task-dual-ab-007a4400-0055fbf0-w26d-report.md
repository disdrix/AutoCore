# Dual A/B report — W26-D OWN `aa_007a4400` + `aa_0055fbf0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-D  
**Scope:** VAs `0x007a4400`, `0x0055fbf0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md` → W26-D  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007a4400` Perf_QpcBeginNamed_Inferred | **accept** — once-init QPF + label@+8 + QPC@+0 CF/ABI sealed |
| `aa_0055fbf0` WorldObj_UnbindLinks_Inferred | **accept** — manager unbind CF/ABI + caller role sealed |

---

## VA `0x007a4400` — sealed facts

1. **Body:** `0x007a4400`–`0x007a445c` (**92 B**; pad `CC` after `RET 4`).
2. **ABI:** **thiscall**; ECX = timer slot; stack `char* label`; **`ret 4`**; **EAX** = this.
3. **Semantics:** Once-init `DAT_00b00a74` → `QueryPerformanceFrequency` → `DAT_00afa254 = g_flOne/(float)freq`; strcpy label to `slot+8`; `QueryPerformanceCounter(slot)`; return slot.
4. **Classification:** worker; callees Win32 QPF/QPC only.
5. **Callers:** 13 unique / **39** xrefs (high-mention nested) — init stages, sector map IO, UI paths. Labels include `"@@new CVOGSectorMap"`, `"Client InitInstance"`, `"ReadMusicRegions"`, …
6. **Not** logger `FUN_007a4480` (NDError / `vog_LogMessage`).
7. **Name:** `Perf_QpcBeginNamed_Inferred` (Ghidra `FUN_007a4400`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for timer class.  
- End/stop consumer of `DAT_00afa254` (not OWN).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007a4400_Perf_QpcBeginNamed_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_007a4400_Perf_QpcBeginNamed_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007a4400_FUN_007a4400.md` |
| Annotated | `docs/reconstruction/raw/aa_007a4400_FUN_007a4400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Perf_QpcBeginNamed_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007a4400.cpp` |
| Function | `docs/reconstruction/functions/aa_007a4400_FUN_007a4400.md` |
| Function named | `docs/reconstruction/functions/aa_007a4400_Perf_QpcBeginNamed_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_007a4400.md` |

---

## VA `0x0055fbf0` — sealed facts

1. **Body:** `0x0055fbf0`–`0x0055fd72` (**386 B** exclusive end; frame `SUB/ADD ESP,0x38`).
2. **ABI:** **thiscall**; ECX = manager; stack `Object* obj`; **`ret 4`**; void.
3. **CF:** `FUN_0062d960(*(mgr+0x234))` → gate `*(obj+0xc)` + vcall `*(**(mgr+0xc4))+0xc` with count>0 → branch `*(obj+0x40)` simple `FUN_006297e0` vs complex `FUN_006caaa0`+loop → always `FUN_0055f4c0`.
4. **Callers (4 / 5 xrefs):** `FUN_00560e90` (RebindActivate unbind→bind), `FUN_00561450` (RemoveOrDefer), `FUN_005614f0`, `FUN_00561370`.
5. **Role:** manager **unbind / remove spatial-query links** (pair of bind `FUN_0055fa40`, W26-E).
6. **Name:** `WorldObj_UnbindLinks_Inferred` (Ghidra `FUN_0055fbf0`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23; unreachable-block warning retained).

### Gaps

- Product English for manager / query iface.  
- Nested callee contracts (`0062d960`, `006297e0`, `006caaa0`, `0055f4c0`) — not OWN.  
- Bind twin `0055fa40` — W26-E.  
- Unreachable growth residual (`0x0055fcee` / possible `FUN_005b3300`).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0055fbf0_FUN_0055fbf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindLinks_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055fbf0.cpp` |
| Function | `docs/reconstruction/functions/aa_0055fbf0_FUN_0055fbf0.md` |
| Function named | `docs/reconstruction/functions/aa_0055fbf0_WorldObj_UnbindLinks_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055fbf0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007a4400` | Stage timing markers need identical slot layout (+0 QPC, +8 label) and once-init `DAT_00afa254=1/freq`. Do not treat as logger (`007a4480`). Useful for client init/sector stage budgets only if end helper is also ported. |
| `0055fbf0` | Rebind/remove paths require this unbind before bind/destroy. Port must preserve simple vs complex branch on `obj+0x40` and always run `FUN_0055f4c0` cleanup. Closes residual left open by W24-B rebind dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.
