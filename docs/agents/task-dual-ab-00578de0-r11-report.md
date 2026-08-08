# Dual A/B report — R11-006 OWN-ONLY (`0x00578de0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-006**  
**Scope:** VA `0x00578de0` (`aa_00578de0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-006**.  
**Work item:** Residual dual seal — skills-abilities; MSVC scalar deleting dtor for `CVOGHBSkillBase`.  
**Partition parent:** `0x00578ce0` (`Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred`) — image adjacency only.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00578de0` CVOGHBSkillBase_ScalarDeletingDtor | **accept** — vtbl[0] + complete-body call + flags&1 free + ret4 + RTTI class sealed; product mangled open |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-dtor-collapse / always-free / array-delete / OnEnd-caller / bare-ret claims **falsified**; product mangled **open**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00578de0` — sealed facts

1. **Body:** `0x00578de0`–`0x00578dfe` exclusive (**30 B** / `0x1E`); terminal **`C2 04 00`**; pad `CC CC` before next code @ `0x00578e00`.
2. **ABI:** MSVC **`__thiscall`** — **ECX=this**, stack **`uint8_t flags`**, **`ret 4`**, **EAX=this**.
3. **Semantics:** MSVC **scalar deleting destructor**:
   - Always `FUN_00578a60(this)` — complete dtor (restores `PTR_FUN_009d3fdc`, frees skill-owned fields, tails base dtor).
   - If `(flags & 1)` → `operator_delete(this)` @ `0x00489822` (+ `add esp,4`).
   - Return `this`.
4. **Xrefs:** 1 **DATA** from `0x009d3fdc` (vtbl[0] of `PTR_FUN_009d3fdc`). **0** CODE callers.
5. **Callees:** `FUN_00578a60`; `operator_delete`.
6. **Family:** dualed `CVOGHBSkillBase_ctor` @ `0x005788d0` (same vtbl / RTTI `".?AVCVOGHBSkillBase@@"`); base twin `CVOGHBBase_ScalarDeletingDtor` @ `0x00508630` (do **not** merge). Complete body `FUN_00578a60` residual (not OWN).
7. **Name:** `CVOGHBSkillBase_ScalarDeletingDtor` (Ghidra `FUN_00578de0`). No `_Inferred` — class RTTI Confirmed + role sealed.
8. **Decompile ≡ raw CF ≡ bytes**; decompiler "delete does not return" is noise.
9. **Partition parent** `0x00578ce0` is wave score parent (OnEnd ends exclusive here); **live entry** is virtual delete via vtbl[0].

### Byte seal

```
00578de0  56                 push esi
00578de1  8B F1              mov  esi, ecx
00578de3  E8 78 FC FF FF     call 0x00578a60
00578de8  F6 44 24 08 01     test byte [esp+8], 1
00578ded  74 09              jz   no_free
00578def  56                 push esi
00578df0  E8 2D 0A F1 FF     call operator_delete
00578df5  83 C4 04           add  esp, 4
00578df8  8B C6              mov  eax, esi
00578dfa  5E                 pop  esi
00578dfb  C2 04 00           ret  4
```

Hex: `568bf1e878fcfffff644240801740956e82d0af1ff83c4048bc65ec20400`

### Gaps

- Product / PDB mangled `??_GCVOGHBSkillBase@@…`.  
- Complete dtor `FUN_00578a60` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578de0.cpp` |
| Function | `docs/reconstruction/functions/aa_00578de0_FUN_00578de0.md` |
| Function named | `docs/reconstruction/functions/aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_009d3fdc  [CVOGHBSkillBase vtbl]
  [0]  FUN_00578de0  CVOGHBSkillBase_ScalarDeletingDtor  [OWN R11-006]
         └─ FUN_00578a60  complete dtor  [residual; restores same vtbl]
              └─ FUN_00508390  CVOGHBBase_dtor  [dualed family]

CVOGHBSkillBase_ctor (0x005788d0)  [dualed]
  └─ installs PTR_FUN_009d3fdc

CVOGHBBase_ScalarDeletingDtor (0x00508630)  [dualed]
  └─ base vtbl 0x009cdab0 — do not merge

Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred (0x00578ce0)  [dualed parent]
  └─ body ends exclusive at 0x00578de0 — adjacency only, not a caller
```

Partition host "skills-abilities" matches product class role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00578de0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00578de0` | Port as **`CVOGHBSkillBase` vtbl[0] scalar deleting dtor**: complete body then optional heap free. **`__thiscall`**, flags stack, **`ret 4`**, return this. |
| Distinct from | complete `FUN_00578a60`; base scalar `0x00508630`; OnEnd `0x00578ce0`. |
| Pair with | dualed ctor `0x005788d0`; residual complete dtor `0x00578a60`; dualed base dtor family `0x00508390` / `0x00508630`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0` / `aa_00578de0`.
- Verdict: **accept**; Terminal **false**.

---

## Process

- OWN VA only (`0x00578de0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall ret 4; flags bit0 only).
- Odd behavior preserved: decompiler non-return warning ignored; no array-delete path.
- No `_Inferred` (RTTI class Confirmed). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
