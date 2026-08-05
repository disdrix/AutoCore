# Dual A/B report — W25-I OWN `aa_0051f510` + `aa_009c3de0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W25-I  
**Scope:** VAs `0x0051f510`, `0x009c3de0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051f510` Mission_ComputeObjectiveXpAsFloat | **accept** — float wrap CF + ABI + ST0 + g_flZero + sole toast caller sealed |
| `aa_009c3de0` atexit_NetClassRep_rpcMsgGuaranteedOrdered | **accept** — mov ecx + jmp dtor thunk + ClassRep identity + atexit reg sealed |

---

## VA `0x0051f510` — sealed facts

1. **Body:** `0x0051f510`–`0x0051f539` (42 B; dual `RET 4`).
2. **ABI:** stack `pObjective`; **`ret 4`**; return **x87 ST0**. Body moves `[esp+4]` → **ECX** for `__fastcall` callee.
3. **Semantics:** if null obj or null mission def at `+0x14c` → `0.0f`; else `(float)Mission_ComputeObjectiveXp(obj)` via `fild`.
4. **Callee:** `Mission_ComputeObjectiveXp` @ `0x0059dde0` (rel32 from `0x0051f521`).
5. **Fail global:** `g_flZero` @ `0x00a0f518` = `00 00 00 00` (0.0f).
6. **Caller (1):** `Client_ShowMissionRewardChatToast` @ `0x008ac61b` — presentation only.
7. **Not grant path:** no `g_flMissionXpRoundBias` (`0x00aaa6d0`); no AddExperience.
8. **Name:** `Mission_ComputeObjectiveXpAsFloat` (Ghidra `FUN_0051f510`; **Inferred**).
9. **Classification:** wrapper.
10. **Decompile ≡ bytes** for CF (FPU return explicit in bytes).

### Gaps

- Product/PDB symbol string (Inferred only).  
- Runtime / bit-exact.  
- Nested calculator map payloads owned by `aa_0059dde0`.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f510_Mission_ComputeObjectiveXpAsFloat.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0051f510_Mission_ComputeObjectiveXpAsFloat.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051f510_FUN_0051f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f510_FUN_0051f510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ComputeObjectiveXpAsFloat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f510.cpp` |
| Parent-seed twin | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowMissionRewardChatToast_0051f510.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f510_FUN_0051f510.md` |
| Function named | `docs/reconstruction/functions/aa_0051f510_Mission_ComputeObjectiveXpAsFloat.md` |
| Scratch | `docs/reconstruction/tmp/a_0051f510.md` |

---

## VA `0x009c3de0` — sealed facts

1. **Body:** `0x009c3de0`–`0x009c3de9` (10 B; leaf thunk).
2. **Bytes:** `mov ecx, 0x00b04f40` ; `jmp FUN_005a2470` (tail; not call+ret).
3. **ABI:** atexit callback — no args; dtor returns to atexit.
4. **Semantics:** CRT exit destructor for static `NetClassRepInstance<RPC_TNLConnection_rpcMsgGuaranteedOrdered>` at `DAT_00b04f40`.
5. **Callee:** `FUN_005a2470` — ClassRep dtor (free name at `this[8]`, restore base vtbl).
6. **Registration:** CRT static init @ `0x009c0eb0` constructs via `FUN_005a2410`, then `atexit(this unit)` (push @ `0x009c0ec5`).
7. **ClassRep identity:** same storage returned by getClassRep Method1 `0x0059e1c0`; name string `RPC_TNLConnection_rpcMsgGuaranteedOrdered` @ `0x009d80cc` (sibling dual High).
8. **Xrefs:** 1 DATA from CRT init; no code CALL sites.
9. **Name:** `atexit_NetClassRep_rpcMsgGuaranteedOrdered` (Ghidra `FUN_009c3de0`; **Inferred**).
10. **Decompile CF ≡ bytes**; bytes refine **mov+jmp** over decompiler call/return.

### Gaps

- Compiler-generated atexit symbol English.  
- Live process-exit observation (optional).  
- Full dual of dtor `FUN_005a2470` residual elsewhere.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.md` |
| Annotated | `docs/reconstruction/raw/aa_009c3de0_FUN_009c3de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/atexit_NetClassRep_rpcMsgGuaranteedOrdered.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009c3de0.cpp` |
| Function | `docs/reconstruction/functions/aa_009c3de0_FUN_009c3de0.md` |
| Function named | `docs/reconstruction/functions/aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md` |
| Scratch | `docs/reconstruction/tmp/a_009c3de0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051f510` | Toast/UI float XP: call int calculator or wrap to float; **do not** apply grant bias here. Grant path stays int calc + `±0.5001f` + AddExperience. |
| `009c3de0` | CRT ClassRep atexit only. Server may omit if ClassRep lifecycle differs; keep ClassRep name/storage identity for GuaranteedOrdered RPC parity. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Prior raw bodies preserved; W25-I live seal sections appended.  
- This report: `docs/agents/task-dual-ab-0051f510-009c3de0-w25i-report.md`
