# Dual A/B report — W19-P OWN `0x0063a700` + `0x0071bdd0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W19-P  
**Scope:** OWN VAs only: `0x0063a700`, `0x0071bdd0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).  
**Module:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0063a700` CVOGHBAIBase_SetFloat0x2c | **accept-with-gaps** — float SSE store / ABI / callers **sealed**; product field name open |
| `aa_0071bdd0` DES_BuildSBoxLookupTables | **accept-with-gaps** — S-box LUT builder CF / banks / sole caller **sealed**; golden vectors open |

---

## VA `0x0063a700` — sealed facts

1. **Role:** Leaf HBAI **float field setter** at `this+0x2c`.  
2. **ABI:** `__thiscall`; stack float; `ret 4`.  
3. **Bytes (not int mov):**  
   `movss xmm0,[esp+4]` / `movss [ecx+0x2c],xmm0` / `ret 4`.  
4. **Callers:**  
   - `CVOGHBAIWalkingCreatureTurreted_ctor` @ `0x00639860` — `push 0` (0.0f)  
   - `CVOGHBAIBase_Default_ctor` @ `0x0063c966` — `push 0` (0.0f)  
5. **Vtbl:** method pointer at Turreted/Default **+0x20** (`0x009e3ce0`, `0x009e3d60`) + three sibling DATA slots.  
6. **Distinct from** ctor seed `this+0x7c` (`[0x1f]=1.0f`).  
7. **Gaps:** product name of `+0x2c`; dynamic vtbl callers; runtime.

---

## VA `0x0071bdd0` — sealed facts

1. **Role:** One-shot **DES S-box lookup-table builder** (not P-perm, not key schedule).  
2. **Source:** `DAT_00afcb48` / `DAT_00afcb88` (= +0x40) — FIPS DES S1..S8 nibble tables (512 bytes; S1/S2 prefixes match classic).  
3. **Output:** four banks × `0x1000` at `DAT_00d12e90` .. `DAT_00d15e90` (end check `0x00d16e91`); BSS zero until init.  
4. **Packing:** each output byte = `(S_hi<<4) | S_lo` from dual index formulas (decompile preserved).  
5. **Loop:** outer `iVar3 = 0,8,16,24`; inner fills 0x1000 indices in steps of 4.  
6. **Sole caller:** `DES_InitializeCipher` @ `0x0071c06b` (after `DES_KeySchedule`, before `FUN_0071b5a0` / W19-Q).  
7. **Consumer:** `DES_CalculateSBoxSubstitution` (`aa_0071ba90`) indexes the four banks.  
8. **Gaps:** golden-vector fill proof; S-pair pedagogy; sibling builder body (not OWN).

---

## Files

### `0x0063a700`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| Function record | `docs/reconstruction/functions/aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| Alias record | `docs/reconstruction/functions/aa_0063a700_FUN_0063a700.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_SetFloat0x2c.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0063a700.cpp` |
| Raw (+ live) | `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.md` |
| Annotated | `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.annotated.md` |

### `0x0071bdd0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| Function record | `docs/reconstruction/functions/aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| Alias record | `docs/reconstruction/functions/aa_0071bdd0_FUN_0071bdd0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_BuildSBoxLookupTables.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0071bdd0.cpp` |
| Raw (+ live) | `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.md` |
| Annotated | `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0063a700-0071bdd0-w19p-report.md` |

---

## AutoCore impact

- **HBAI:** Turreted/Default (and vtbl[+0x20]) zero a **float at +0x2c** via this leaf; layout ports should reserve that float separately from `+0x7c` (1.0f seed).  
- **Auth DES:** client cipher init must expand S-boxes into four 0x1000 banks (or ship equivalent precomputed tables) before `DES_CalculateSBoxSubstitution`; do not attribute P-table build to this VA.
