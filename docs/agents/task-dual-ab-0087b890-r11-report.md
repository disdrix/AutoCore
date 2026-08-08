# Dual A/B report — R11-030 OWN-ONLY (`0x0087b890`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-030**  
**Scope:** VA `0x0087b890` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x008ac3f0` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_signature` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — undualed callee of dualed mission dialog host; partition system missions-progression; parent dual `0x008ac3f0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0087b890` CVOGDialog_Ctor | **accept-with-gaps** — CF/ABI/RTTI-vtbl/base-callee/multi-caller sealed; param_2 English + mode-dword names + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-return / ECX-thiscall / RET-4 / mission-only body / scaffold-product / subclass-final-vtbl / terminal claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0087b890` — sealed facts

1. **Body:** `0x0087b890`–`0x0087b905` inclusive (**118 B** / `0x76`); pad `CC` @ `0x0087b906+`.
2. **ABI:** stack **`this*`** + **`param_2`**; **`RET 8`**; returns **`this` in EAX**. SEH `LAB_009b531d`. **Not** ECX-thiscall.
3. **Semantics:** **CVOGDialog constructor**
   - Call base `FUN_00792d20` (CNDUIDialog ctor peer; intermediate vtbl `0x00a98f44`).
   - Zero dwords `+0x4FC/+0x500/+0x504/+0x508`; bytes `+0xBF`, `+0x490` (clears base default 1 at `+0x490`).
   - Install primary vtbl **`0x00a58c6c`**.
   - Store `param_2` at **`+0x2A4`**.
4. **RTTI:** COL `0x00ab4984` → type_info `0x00af8e50` → **`.?AVCVOGDialog@@`**.
5. **Callees:** **1** — `FUN_00792d20`.
6. **Callers:** **78** xrefs — shared dialog base (mission host `FUN_008ac3f0`, `CDlgFirstTime_ctor`, CreateNDUIDialogs installers, …). Subclasses overwrite vtbl after return.
7. **Name:** `CVOGDialog_Ctor` (Ghidra `FUN_0087b890`). Scaffold `Named_CalleeOf_Mission_i_d_npc_xml_0087b890` **retired as product**.
8. **Decompile ≡ raw CF**; ABI + epilogue + RTTI sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product English for ctor arg `param_2` / field `+0x2A4`.  
- Official names for mode dwords at `+0x4FC..+0x508`.  
- Full CVOGDialog layout / base size (subclass sizes differ).  
- Runtime / bit-exact / differential.  
- Base `FUN_00792d20` plate naming tension (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0087b890_CVOGDialog_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0087b890_CVOGDialog_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R11-030 append) | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.md` |
| Annotated | `docs/reconstruction/raw/aa_0087b890_FUN_0087b890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGDialog_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0087b890.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_i_d_npc_xml_0087b890.cpp` |
| Function | `docs/reconstruction/functions/aa_0087b890_FUN_0087b890.md` |
| Function named | `docs/reconstruction/functions/aa_0087b890_CVOGDialog_Ctor.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_NpcMissionDialogHost_Ctor_Inferred  0x008ac3f0  [dualed parent]
  CALL 0x0087b890  CVOGDialog_Ctor(this, 0)   [OWN R11-030]
    CALL 0x00792d20  CNDUIDialog base ctor     [prior dual / residual naming]
  *this = 0x00a4a51c  (subclass vtbl overwrite)
  … zeros / FUN_008ab0a0 / NDUIWindow_ReloadInterface("i_d_npc.xml") / …

CDlgFirstTime_ctor  0x008dd590
  CALL 0x0087b890(this, 0)
  *this = 0x00a3d8b4

[~76 other dialog subclass ctors — CreateNDUIDialogs fan-out]
  same base pattern
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0087b890-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0087b890` | Port as **CVOGDialog constructor**. Stack **`this*` + `param_2`**, **`RET 8`**, return **this**. Call CNDUIDialog base first, zero pack, install vtbl `0x00a58c6c`, store arg at `+0x2A4`. Preserve **`+0x490=0`** override of base default 1. Do **not** treat as ECX-thiscall, void, mission-only, or final subclass ctor. Subclasses reinstall their own vtbl after return. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire Mission_i_d_npc_xml scaffold → `CVOGDialog_Ctor`)  
- `systems/missions-progression.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
