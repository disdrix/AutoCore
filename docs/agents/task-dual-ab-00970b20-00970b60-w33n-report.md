# Dual A/B report — W33-N OWN `aa_00970b20` + `aa_00970b60`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-N  
**Scope:** VAs `0x00970b20`, `0x00970b60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00970b20` SideHost_PushKeyFlag0_Inferred | **accept-with-gaps** — thiscall/ret4 + key+flag0 + host+0xAC locked push sealed; product English open |
| `aa_00970b60` SideHost_PushKeyFlag1_Inferred | **accept-with-gaps** — bit-twin of flag0 with imm8=1; sole NDResource miss path sealed |

---

## VA `0x00970b20` — sealed facts

1. **Body:** `0x00970b20`–`0x00970b55` (**54 B** / `0x36`; pad `CC`).
2. **ABI:** **ECX=`keyHolder*`** (`*ecx` → u32 key); stack **1** formal **`host*`**; epilogue **`RET 0x4`** (`C2 04 00`). Not bare void thiscall.
3. **Semantics:** Build stack `PodU32U8{key=*ecx, flag=0}` via adapter `FUN_0043e8f0` → `PodU32U8_StoreSplit` (`0043ea50`); then **`GuardedVector_PushBackLocked_Stride2_U32U8`** (`FUN_0043e7f0`) with **EDI = host+0xAC**, stack = pod*.
4. **Classification:** worker (2 callees).
5. **Callers (2 xrefs / 2 fns):** `FUN_0075e2d0` @ `0x0075e333` (`push [esi+0x6c]; mov ecx, local; call`); `FUN_00971030` @ `0x0097103b` (`push this; mov ecx, arg; call`).
6. **Callees:** `FUN_0043e8f0` (split-store adapter), `FUN_0043e7f0` (locked U32U8 push — W32-N sealed).
7. **Name:** `SideHost_PushKeyFlag0_Inferred` (Ghidra `FUN_00970b20`; **Inferred** structural).
8. **Decompile incomplete:** live decompile shows bare `FUN_0043e8f0(); FUN_0043e7f0();` with void signature — **bytes win** on ECX key, stack host, flag imm `6A 00`, `ADD EDI,0xAC`, `RET 4`. Full hex in raw W33-N append.

### Gaps

- Product/PDB English for host class / event flag meaning.  
- Nested adapter `0043e8f0` dual free (only leaf store sealed W32-M).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970b20_FUN_00970b20.md` |
| Annotated | `docs/reconstruction/raw/aa_00970b20_FUN_00970b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SideHost_PushKeyFlag0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970b20.cpp` |
| Function | `docs/reconstruction/functions/aa_00970b20_FUN_00970b20.md` |
| Function named | `docs/reconstruction/functions/aa_00970b20_SideHost_PushKeyFlag0_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00970b20.md` |

---

## VA `0x00970b60` — sealed facts

1. **Body:** `0x00970b60`–`0x00970b95` (**54 B** / `0x36`; pad `CC`).
2. **ABI:** identical to `00970b20` — **ECX=keyHolder***, stack **host***, **`RET 0x4`**.
3. **Semantics:** bit-twin of `00970b20` except **flag imm8 = 1** (`6A 01` vs `6A 00`). Same callees; same `host+0xAC` locked push.
4. **Classification:** worker.
5. **Callers (1 xref / 1 fn):** `NDResourceCache_LookupOrCreate` (`FUN_0075dba0`) @ `0x0075dceb` — after alternate provider miss when `cache+0x6c != 0` (`push [esi+0x6c]; mov ecx, ebp; call`).
6. **Callees:** `FUN_0043e8f0`, `FUN_0043e7f0`.
7. **Name:** `SideHost_PushKeyFlag1_Inferred` (Ghidra `FUN_00970b60`; **Inferred**).
8. **Twin delta:** only `PUSH imm8` and `E8` rel32 (same targets `0043e8f0` / `0043e7f0`). Full hex in raw W33-N append.

### Gaps

- Product meaning of flag=1 vs flag=0 (miss vs remove/evict sites suggest event kind).  
- Runtime / bit-exact.  
- Nested adapter free.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970b60_FUN_00970b60.md` |
| Annotated | `docs/reconstruction/raw/aa_00970b60_FUN_00970b60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SideHost_PushKeyFlag1_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970b60.cpp` |
| Function | `docs/reconstruction/functions/aa_00970b60_FUN_00970b60.md` |
| Function named | `docs/reconstruction/functions/aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00970b60.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00970b20` | Port as **thiscall** ECX=key holder, stack host, **RET 4**. Form `{*ecx, flag:0}` then locked push to **`host+0xAC`**. Do **not** trust decompiler void/no-args surface. |
| `00970b60` | Same ABI; **flag=1** only delta. Sole miss-path notifier from `NDResourceCache_LookupOrCreate` when `cache+0x6c` set. |
| Pair with | Nested locked push `0043e7f0` (W32-N), store split `0043ea50` (W32-M), adapter `0043e8f0` (free), cache `0075dba0` / remove `0075e2d0` (not owned). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes residual callers of W32-N locked U32U8 push (`FUN_00970b20` / `FUN_00970b60`) named in wave32/33 partitions.
