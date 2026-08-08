# Dual A/B report — R10-018 OWN-ONLY (`0x004020f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-018**  
**Scope:** VA `0x004020f0` (`aa_004020f0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — undualed callee of dualed HP manager `0x00401d30` → **generic StringFlag dtor (string only)**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004020f0` BasicStringFlag_Dtor_Inferred | **accept-with-gaps** — CF/ABI/RET4/string-dtor-only sealed; product type English + Unwind frame IDs open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-dialog / flag-freeing full dtor / thiscall-at-entry / cdecl / merge-with-00402040-or-00401d30 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004020f0` — sealed facts

1. **Body:** `0x004020f0`–`0x00402126` inclusive (**55 B** / `0x37`); pad `CC` before `FUN_00402130` @ `0x00402130`.
2. **ABI:** stack **object***; nested **thiscall** `ECX=object` into CRT dtor; void; **`RET 4`**.
3. **Semantics:** destroy `{ basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }` by string dtor only:
   - SEH frame (`LAB_009bbfb9` / FS:[0]).
   - IAT `[0x009c62f4]` → `basic_string::~basic_string()`.
   - Flag byte **not touched** (POD).
4. **Callees:** string dtor only.
5. **Callers:** **7** UNCONDITIONAL_CALL — all `Unwind@*`:
   - `009ac6a1`, `009ac6ae`, `009ac6e3`, `009ac6ed`, `009bc647`, `009bc7e7`, `009bd0d0`.
6. **Xrefs:** 7 UNCONDITIONAL_CALL (same).
7. **Name:** `BasicStringFlag_Dtor_Inferred` (Ghidra `FUN_004020f0`). Family membership Probable (shared SEH + dualed twins) → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product English for flag byte.  
- Per-Unwind owning frame product type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004020f0_FUN_004020f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004020f0_FUN_004020f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004020f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004020f0_FUN_004020f0.md` |
| Function named | `docs/reconstruction/functions/aa_004020f0_BasicStringFlag_Dtor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
BasicStringFlag family (shared SEH LAB_009bbfb9):
  00401d30  BasicStringFlag_CtorFromStringAndChar_Inferred  [dualed MEGA-065]
  00402040  BasicStringFlag_CopyCtor_EdiSrc_Inferred        [dualed MEGA-080]
  004020f0  BasicStringFlag_Dtor_Inferred                   [OWN R10-018]
            └─ 7× Unwind@* exception cleanup sites

Parent dual hint 0x00401d30 explains queue depth (undualed callee of dualed HP manager),
not mission-dialog semantics of this unit.
```

Partition system **missions-progression** is inheritance from the parent dual chain; unit itself is shared MSVC aggregate cleanup.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004020f0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004020f0` | Port as **dispose of `{string, byte}` string field only**. Native sites use **stack object*** + **RET 4** (Unwind). Managed: drop string; no flag cleanup. Do **not** implement as mission-dialog. Keep distinct from ctor `00401d30` and copy `00402040`. |
| Pair with | dualed `00401d30` (from parts); dualed `00402040` (copy); residual `00401fe0` (node ctor). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Record first dual seal for `aa_004020f0`.
