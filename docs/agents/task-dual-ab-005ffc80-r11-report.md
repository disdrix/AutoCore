# Dual A/B report — R11-009 OWN-ONLY (`0x005ffc80`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-009**  
**Scope:** VA `0x005ffc80` (`aa_005ffc80`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-009**.  
**Work item:** Residual dual seal — shared empty stub (`ret 4`) used as multi-domain vtbl default + nop CALL.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ffc80` EmptyStub_Ret4 | **accept** — 3 B `c2 04 00` / RET 0x4 / zero side effects / mass DATA + sole CALL nop sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): skills-product / bare-ret-EmptyRet-merge / dest-init / real-work / pure-void-ABI claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005ffc80` — sealed facts

1. **Body:** `0x005ffc80`–`0x005ffc82` inclusive (**3 B** / `0x3`); terminal **`C2 04 00`**; pad `CC` before `FUN_005ffc90` @ `0x005ffc90`.
2. **ABI:** callee cleans **4** stack bytes (`RET 0x4`). Ignores ECX/this and stack arg. **Not** bare `c3` / not pure void-no-cleanup.
3. **Semantics:** shared **empty leaf** — no stores, no callees, no return value set.
4. **Code caller (1):** `FUN_0064d9f0` @ `0x0064d9f9` — `push dest; call` then 8× dword copy `this+0x30..+0x4c` → dest (stub is nop).
5. **Xrefs:** 100+ DATA (Ghidra list capped); sample Class vtbl `0x00a9bbe8+8`, VehicleAction primary +0x10, secondary empties, physics component tables.
6. **Callees:** none. Classification **stub**.
7. **Family:** contrast bare-`c3` `EmptyRet` `0x0056f570`, `CVOGHBBase_EmptyVFunc` `0x005081f0`; do **not** merge ABIs. Neighbor `0x005ffc90` is non-empty — do not merge.
8. **Name:** `EmptyStub_Ret4` (Ghidra `FUN_005ffc80`). Product demangle open — descriptive, not RTTI invent.
9. **Decompile CF ≡ raw** (empty return); **ABI correction** via `disassemble_function` + `read_memory` (decompiler void incomplete, not CF conflict).
10. **Partition parent** `0x00416110` is residual score parent (Class_00a9bbe8 complete dtor / vtbl host); **not** sole live structural owner — mass multi-domain DATA.

### Gaps

- Product / PDB symbol for shared empty.  
- Exhaustive DATA-slot census.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ffc80_EmptyStub_Ret4.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005ffc80_EmptyStub_Ret4.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.md` |
| Annotated | `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyStub_Ret4.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ffc80.cpp` |
| Function | `docs/reconstruction/functions/aa_005ffc80_FUN_005ffc80.md` |
| Function named | `docs/reconstruction/functions/aa_005ffc80_EmptyStub_Ret4.md` |

---

## Chain context (not dualled; evidence only)

```text
Class_00a9bbe8_CompleteDtor_Inferred (0x00416110)  [dualed; residual parent]
  vtbl 0x00a9bbe8
    +0  set +8
    +4  get +8
    +8  EmptyStub_Ret4 (0x005ffc80)  [OWN R11-009]
    +C  scalar-deleting style

FUN_0064d9f0  [not OWN]
  └─ CALL EmptyStub_Ret4 (nop)
  └─ copy this+0x30..+0x4c → dest* (8 dwords)

VehicleAction primary vtbl  [physics verified]
  +0x10 EmptyStub_Ret4

EmptyRet (0x0056f570)  [dualed] — bare c3; different VA/ABI — do not merge
```

Partition host "skills-abilities" names residual score parentage, not this leaf's product role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005ffc80-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ffc80` | Port as **shared empty vfunc / nop** with **`ret 4`** (one ignored stack dword). No domain work. |
| Distinct from | bare-`c3` `EmptyRet` `0056f570`; HB empty `005081f0`; neighbor `005ffc90`. |
| Pair with | residual parent vtbl `00a9bbe8`; optional omit of CALL in ports of `0064d9f0` copy path. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `EmptyStub_Ret4` @ `0x005ffc80` / `aa_005ffc80`.
- Verdict: **accept**; Terminal **false**.

---

## Process

- OWN VA only (`0x005ffc80`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI correction (`ret 4`).
- Odd behavior preserved: mass multi-domain reuse; sole CALL is nop before copy.
- Descriptive name without unproven product English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
