# Dual A/B report — R12-007 OWN-ONLY (`0x007fb990`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-007**  
**Scope:** VA `0x007fb990` (`aa_007fb990`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-007**.  
**Work item:** R12 residual dual seal — input-drive-control residual **host+0x1144 query/fade cleanup leaf**.  
**Parent dual (evidence only):** `0x00914c60` `Client_SetModeLatch493_ParkDriveOnClear_Inferred`.  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007fb990` Client_UI_Host1144_QueryAndFade_Inferred | **accept-with-gaps** — CF/ABI/RET/xref/byte/ESI seals closed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): OnKeyDown-only / ECX-host / RET4 / unconditional-fade / cursor-host / drive-side-effect claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007fb990` — sealed facts

1. **Body:** `0x007fb990`–`0x007fb9d3` inclusive (**68 B** / `0x44`); pad `CC` from `0x007fb9d4`.
2. **ABI:** **ESI** = client UI host (callers: majority `MOV ESI, 0x00d1a840`); **plain RET** (`C3`); **zero** stack args. **Not** ECX thiscall on host.
3. **Semantics (triple-gated fade):**
   - If `*(host+0x1144) == 0` → return.
   - Else `AL = obj->vtbl[+0xd0]()`; if AL==0 → return.
   - Else `EAX = obj->vtbl[+0xe8]()`; if EAX==-1 → return.
   - Else `obj->vtbl[+0xfc](0, 0.1f)` with PUSH order `0x3dcccccd`, then `0`.
4. **Slot install (evidence):** CreateNDUIDialogs host install writes `+0x1144` via `operator_new(0x488)` + `FUN_007b5dd0` + `vtbl+0x28` / `+0xcc`.
5. **Callees:** none by name (indirect vtbl only).
6. **Callers:** **15** UNCONDITIONAL_CALL (parent mode-latch clear, OnKeyDown skill cancel, interact cancel, UI/packet teardown, etc.).
7. **Name:** `Client_UI_Host1144_QueryAndFade_Inferred` (Ghidra `FUN_007fb990`). Product map open → `_Inferred`. Supersedes Named_CalleeOf OnKeyDown-only scaffold.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site ESI context.

### Gaps

- Product English for dialog class at `+0x1144` and vtbl `+0xd0` / `+0xe8` / `+0xfc`.  
- Semantic of fade arg0=`0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.md` |
| Annotated | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_Host1144_QueryAndFade_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fb990.cpp` |
| Function | `docs/reconstruction/functions/aa_007fb990_FUN_007fb990.md` |
| Function named | `docs/reconstruction/functions/aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00914c60  Client_SetModeLatch493_ParkDriveOnClear_Inferred  [parent dual R11-037]
  clear path:
    MOV ESI, &DAT_00d1a840
    CALL FUN_007fb990  Client_UI_Host1144_QueryAndFade_Inferred  [OWN R12-007]
    CALL FUN_00914c20  StopHbAndZeroLongitudinal
    optional DAT_00d1b9a8 notify(0)

Client_Input_OnKeyDown_MatchAction
  PromptSkillTargetSelect(EAX=-1, show=0)
  MOV ESI, &DAT_00d1a840
  CALL FUN_007fb990  [OWN R12-007]

CreateNDUIDialogs install (0x0093e7e0)  [dualed MEGA-133]
  host+0x1144 = new(0x488) + FUN_007b5dd0 + vtbl+0x28/+0xcc
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007fb990-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007fb990` | Port as **ESI-host free-function** (custom convention). Plain RET. |
| Gates | null `+0x1144` → query `+0xd0` → state `+0xe8 != -1` → fade `+0xfc(0, 0.1f)`. |
| Pair with | CreateNDUIDialogs install of `+0x1144`; parent mode-latch clear path. |
| Do not | Treat as ECX thiscall host; OnKeyDown-only; unconditional fade; drive/latch writer. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- progress / WORK_QUEUE residual clear for R12-007  

**Terminal:** **false**.
