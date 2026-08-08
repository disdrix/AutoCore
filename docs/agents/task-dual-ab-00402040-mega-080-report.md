# Dual A/B report — MEGA-080 OWN-ONLY (`0x00402040`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-080**  
**Scope:** VA `0x00402040` (`aa_00402040`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Mission null dialog nested residual → **generic StringFlag copy-ctor**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402040` BasicStringFlag_CopyCtor_EdiSrc_Inferred | **accept-with-gaps** — CF/ABI/RET4/EDI-src/layout sealed; product flag + map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-dialog / plain-string-only / thiscall-ECX-aggregate / cdecl / swap-ESI-EDI / merge-with-00401d30 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402040` — sealed facts

1. **Body:** `0x00402040`–`0x0040208c` inclusive (**77 B** / `0x4D`); pad `CC` before `FUN_00402090` @ `0x00402090`.
2. **ABI:** stack **dest***; **EDI** = source*; **EAX** = dest*; **`RET 4`**.
3. **Semantics:** copy-ctor for `{ basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }`:
   - SEH frame (`LAB_009bbfb9` / FS:[0]).
   - IAT `[0x009c62ec]` → `basic_string::basic_string(const basic_string&)` (demangle `...QAE@ABV01@@Z`).
   - `dest.flag = src.flag` at `+0x1c`.
4. **Callees:** string copy-ctor only.
5. **Callers:** **2** UNCONDITIONAL_CALL:
   - `FUN_00401fe0` @ `0x0040200a` — dest `node+0xc`.
   - `FUN_00980160` @ `0x009801c0` — `MOV EDI,EAX` after `FUN_00401d30`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL (same).
7. **Name:** `BasicStringFlag_CopyCtor_EdiSrc_Inferred` (Ghidra `FUN_00402040`). Product flag English open → `_Inferred`.
8. **Retired scaffold:** `Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00402040`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for flag byte.  
- Parent map/node value_type product name (`FUN_00401fe0`).  
- Twin construct-from-parts `00401d30` residual (context only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402040_FUN_00402040.md` |
| Annotated | `docs/reconstruction/raw/aa_00402040_FUN_00402040.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_CopyCtor_EdiSrc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402040.cpp` |
| Function | `docs/reconstruction/functions/aa_00402040_FUN_00402040.md` |
| Function named | `docs/reconstruction/functions/aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00980160  (mission-chain residual parent; string parse with ")")
  ├─ basic_string::find / substr
  ├─ FUN_00401d30  construct StringFlag from (string*, char*)  [residual]
  ├─ FUN_00402040  BasicStringFlag_CopyCtor_EdiSrc_Inferred  [OWN MEGA-080]
  └─ FUN_00401c50  map insert/find peer  [residual]

FUN_00401fe0  tree/map node ctor  [residual]
  └─ FUN_00402040  embeds StringFlag at node+0xc  [OWN MEGA-080]
```

Partition hint "Mission null dialog nested" explains **why** this VA was queued (depth under mission null-dialog chain), not the unit's semantics.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402040-mega-080-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402040` | Port as **copy of `{string, byte}` aggregate**. Native sites use **EDI=src**, stack=dest, **RET 4**. Managed code can use ordinary copy. Do **not** implement as mission-dialog open. Keep distinct from construct-from-parts `00401d30` and string dtor `004020f0`. |
| Pair with | residual `00401d30` (from parts); residual `00401fe0` (node ctor); residual `004020f0` (string dtor); residual `00980160` (parse/insert parent). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage / naming registry when the merge agent runs.
- Retire Named_CalleeOf scaffold references in any index not touched here.
