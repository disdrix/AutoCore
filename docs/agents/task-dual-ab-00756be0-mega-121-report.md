# Dual A/B report — MEGA-121 OWN-ONLY (`0x00756be0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-121**  
**Scope:** VA `0x00756be0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-121 residual dual seal — callee of dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`) / **CNDUIDialog_TeardownChildHash_Inferred** (`0x007917c0`): **child-list detach**.  
**Terminal:** **false** (no runtime Confirmed).  
**Note:** Prior agent hung; this run completed all deliverables from live Ghidra.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00756be0` gfxUIWindow_DetachParent_Inferred | **accept-with-gaps** — CF/ABI/RET4/offsets/memmove/dualed call sites sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): child-only-thiscall / bare-RET / free-or-walk-all / scaffold product-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00756be0` — sealed facts

1. **Body:** `0x00756be0`–`0x00756c44` inclusive (**101 B** / `0x65`); pad `CC` before peer `FUN_00756c50` @ `0x00756c50`.
2. **ABI:** **ECX** = parent window/dialog; stack child*; **EAX** = `0` / `0xffffffff`; **`RET 4`** ×2 exits.
3. **Semantics:** parent child-vector erase + clear child parent link:
   - begin `@parent+0x94`, end `@parent+0x98` (pointer elements).
   - linear find `child*`; on hit `memmove` compact, `end -= 4`, `child+0x88 = 0`, return 0.
   - on miss return `0xffffffff`.
4. **Callees:** `memmove` only (IAT `0x009c652c`).
5. **Callers:** **24** UNCONDITIONAL_CALL.
6. **Dualed parents (assembly authority):**
   - `gfxUIWindow_CompleteDtor` `0x00759de0` @ `0x00759f3a`: `ECX=[self+0x88]`; `PUSH self`.
   - `CNDUIDialog_TeardownChildHash_Inferred` `0x007917c0` @ `0x007918a5`: `ECX=dialog`; `PUSH child`.
7. **Name:** `gfxUIWindow_DetachParent_Inferred` (Ghidra `FUN_00756be0`). Product demangle open → `_Inferred`. Scaffold `Named_CalleeOf_*` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + dualed call-site context.

### Gaps

- Exact product method demangle (no RTTI/string on leaf).  
- Dual residual of attach peer `FUN_00756c50` and other non-dualed callers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00756be0_gfxUIWindow_DetachParent_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00756be0_FUN_00756be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_DetachParent_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00756be0.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00756be0.cpp` |
| Function | `docs/reconstruction/functions/aa_00756be0_FUN_00756be0.md` |
| Function named | `docs/reconstruction/functions/aa_00756be0_gfxUIWindow_DetachParent_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F / prior]
  └─ if self+0x88: FUN_00756be0(parent=[self+0x88], child=self)  [OWN MEGA-121]
  └─ assert residual children @ +0x94 / clear each child+0x88

FUN_007917c0  CNDUIDialog_TeardownChildHash_Inferred  [dualed WQ9L-I]
  └─ per hash child: release; clear +0x2b0; FUN_00756be0(dialog, child)  [OWN MEGA-121]

FUN_00756c50  attach/reparent peer  [residual]
  └─ FUN_00756be0(old_parent=[child+0x88], child) then write new +0x88
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00756be0-mega-121-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00756be0` | Port as **parent child-list detach leaf**. **thiscall RET 4**. ECX=parent, stack=child*. Vector begin/end `@+0x94`/`+0x98`; clear `child+0x88`. Return `0`/`0xffffffff`. **Do not** free objects or walk remaining children. Keep distinct from attach peer `00756c50`. |
| Pair with | dualed CompleteDtor `00759de0`; dualed TeardownChildHash `007917c0`; residual attach `00756c50`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when parent wave merges residuals  
- Do **not** mark runtime Confirmed without Launcher golden  

---

## Terminal

**false**
