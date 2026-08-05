# Dual A/B report — W24-R OWN `aa_0056ff00` + `aa_0074ed90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W24-R  
**Scope:** VAs `0x0056ff00`, `0x0074ed90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0056ff00` WeaponHitResultVec_PushBack | **accept-with-gaps** — push_back CF + ABI + stride 0x20 + shell +4/+8/+0xc sealed; element English + nested helpers residual |
| `aa_0074ed90` AnimSlot_Ctor | **accept** — leaf 0x78 ctor CF + ABI + rate/mode/sentinel defaults + unwritten gaps sealed |

---

## VA `0x0056ff00` — sealed facts

1. **Body:** `0x0056ff00`–`0x0056ff60` (97 B; exclusive end `0x0056ff61`; `RET 4` ×2).
2. **ABI:** **ECX**=vector shell*; stack `const Elem20* value`; void return.
3. **Semantics:** MSVC-style **push_back** of one **0x20**-byte POD: fast path fill-at-end, else grow.
4. **Shell:** `+4` begin, `+8` end, `+0xc` capacity end (`+0` unused by this unit).
5. **Stride:** `0x20` (`sar 5`; end bump `+0x20`).
6. **Fast callee:** `FUN_0056f1e0(end, 1, value)` — 8×DWORD POD copy.
7. **Slow callee:** `FUN_0056fab0(this, end, 1, value)` — grow/insert family.
8. **Callers (1):** `Weapon_ApplyDamageToTargets_Inferred` / `FUN_0056e000` (sites `0056e250`, `0056e382`).
9. **Name:** `WeaponHitResultVec_PushBack` (Ghidra `FUN_0056ff00`; **Inferred**).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product English for 0x20 hit-record layout.  
- Nested helper duals (`0056f1e0`, `0056fab0`) not re-sealed in this pass.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0056ff00_WeaponHitResultVec_PushBack.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0056ff00_WeaponHitResultVec_PushBack.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0056ff00_FUN_0056ff00.md` |
| Annotated | `docs/reconstruction/raw/aa_0056ff00_FUN_0056ff00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WeaponHitResultVec_PushBack.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0056ff00.cpp` |
| Function | `docs/reconstruction/functions/aa_0056ff00_FUN_0056ff00.md` |
| Function named | `docs/reconstruction/functions/aa_0056ff00_WeaponHitResultVec_PushBack.md` |
| Scratch | `docs/reconstruction/tmp/a_0056ff00.md` |

---

## VA `0x0074ed90` — sealed facts

1. **Body:** `0x0074ed90`–`0x0074ee31` (162 B; exclusive end `0x0074ee32`; SEH + bare `RET`).
2. **ABI:** **ECX**=slot*; no stack args; void return.
3. **Semantics:** Leaf **default ctor** for **0x78**-byte anim slot (callers `operator_new(0x78)`).
4. **Rate:** `+0x3c = g_flOne` (`0x00a0f2a0` = `1.0f`).
5. **Mode:** `+0x4c = 1` (wrap; matches `AnimSlot_SetTime` nonzero→fmod).
6. **Sentinels:** `+0x50/+0x60/+0x68 = 0xFFFFFFFF`; `+0x54 = 1`; `+0x55/+0x56 = 0`.
7. **Unwritten:** `+0x00`, `+0x14`, `+0x24` (must not invent zeros).
8. **Callers (10):** includes `Object_LoadOrReplaceAnimSlot` (`0x005828b0`), `CVOGGraphicsBase_LoadNextChildAsset` type `0x41` (`0x00581e20`), `FUN_00504d40`, +7.
9. **Name:** `AnimSlot_Ctor` (Ghidra `FUN_0074ed90`; **Inferred**; sibling duals W18-C / W21-J).
10. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB class spelling.  
- Semantic English for unwritten fields and `-1` sentinels.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0074ed90_AnimSlot_Ctor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0074ed90_AnimSlot_Ctor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074ed90_FUN_0074ed90.md` |
| Annotated | `docs/reconstruction/raw/aa_0074ed90_FUN_0074ed90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0074ed90.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074ed90.cpp` |
| Function | `docs/reconstruction/functions/aa_0074ed90_FUN_0074ed90.md` |
| Function named | `docs/reconstruction/functions/aa_0074ed90_AnimSlot_Ctor.md` |
| Scratch | `docs/reconstruction/tmp/a_0074ed90.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0056ff00` | Weapon multi-hit staging vector push_back — preserve stride **0x20**, shell offsets **+4/+8/+0xc**, POD memcpy-8-dwords fast path, and grow via `FUN_0056fab0` semantics. |
| `0074ed90` | Anim slot default ctor after `new(0x78)` — preserve rate **1.0**, mode **1**, sentinels **-1**, and **do not** zero unwritten `+0/+0x14/+0x24`. Pair with `AnimSlot_SetTime` / load paths. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-0056ff00-0074ed90-w24r-report.md`
