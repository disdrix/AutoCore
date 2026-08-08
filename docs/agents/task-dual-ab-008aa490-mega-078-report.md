# Dual A/B report — MEGA-078 OWN-ONLY (`0x008aa490`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-078**  
**Scope:** VA `0x008aa490` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-078**.  
**Work item:** residual dual seal — **Dialog pre-present setup** (turn-in ready flag store + optional child notify).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008aa490` MissionDialog_SetTurnInReadyFlag_Inferred | **accept-with-gaps** — CF/ABI/EAX-host/DL-flag/+0x580/+0x6e8/vtbl+4/sole-caller pre-present role sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): present / PrepareResponseOpcode / ECX-thiscall / always-vcall / slot-clear / multi-caller / scaffold-product / mode-param3-as-flag claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008aa490` — sealed facts

1. **Body:** `0x008aa490`–`0x008aa4a6` inclusive (**23 B** / `0x17`); pad `CC` then sibling `FUN_008aa4b0` @ `0x008aa4b0`.
2. **ABI:** **EAX** = mission dialog host; **DL** = turn-in ready flag; void; bare **`RET`** (`C3`). Not ECX-thiscall.
3. **Semantics:** pre-present flag apply:
   - Load child from `dialog+0x6e8`.
   - Always `*(char*)(dialog+0x580) = DL`.
   - If child ≠ 0: `PUSH EDX`; `CALL [child.vtbl+4]` (ECX=child).
4. **Static callees:** none (virtual only). Analyze "leaf" = no static FUN_* edges.
5. **Callers (1):** `Client_ShowNpcMissionDialogUI` @ `0x00943a57` UNCONDITIONAL_CALL — after `FUN_0052b420` turn-in probe; before `Client_NpcDialog_PrepareResponseOpcode` (`0x008abd70`) and panel/chrome fill.
6. **Xrefs:** 1× UNCONDITIONAL_CALL.
7. **Name:** `MissionDialog_SetTurnInReadyFlag_Inferred` (Ghidra `FUN_008aa490`). Scaffold `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **System:** `missions-progression` (partition + parent ShowNpc path).

### Gaps

- Product English for dialog host class and fields `+0x580` / `+0x6e8`.  
- Product name for child `vtbl[+4]`.  
- EDX upper-byte contract at child vcall (caller only writes DL).  
- Sibling residuals `FUN_008aa4b0` / `FUN_008aa510` / `FUN_008ab550` (other MEGA units).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa490_FUN_008aa490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_SetTurnInReadyFlag_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aa490.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa490.cpp` |
| Function | `docs/reconstruction/functions/aa_008aa490_FUN_008aa490.md` |
| Function named | `docs/reconstruction/functions/aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowNpcMissionDialogUI  [0x009438f0]  [dualed parent elsewhere]
  ├─ guards: dialog stack + char +0xe98 + mission UI +0x1058
  ├─ mission def lookup / "NPC dialog already active!" early-out
  ├─ FUN_0052b420  turn-in readiness probe  [evidence]
  ├─ FUN_008aa490  MissionDialog_SetTurnInReadyFlag_Inferred  [OWN MEGA-078]
  │     └─ dialog+0x580 = flag; optional child@+0x6e8 vtbl[+4]
  ├─ Client_NpcDialog_PrepareResponseOpcode  [0x008abd70]  dialog+0x650=0x206E
  ├─ FUN_008ab550  multi-mission panel fill  [MEGA-051 residual]
  ├─ FUN_008aa4b0  dialog helper before thr/steer park  [MEGA-058 residual]
  ├─ FUN_008aaf60 / FUN_008ac110 / FUN_008aa510 / FUN_008aa760  chrome/reward
  └─ FUN_0092f090  axis park finalize
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008aa490-mega-078-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008aa490` | Port as **mission dialog pre-present flag apply**: store turn-in ready **char** at **`dialog+0x580`**, then optional child notify **`*(dialog+0x6e8)->vtbl[+4](flag)`**. ABI: **EAX=host**, **DL=flag**, bare RET, no stack args. Call after turn-in probe, before response opcode / panel fill. Do **not** treat as present, PrepareResponseOpcode, slot clear, or ECX-thiscall. |
| Pair with | dualed parent `Client_ShowNpcMissionDialogUI` `009438f0`; residual `FUN_008aa4b0` / `FUN_008aa510` / `FUN_008ab550`; dualed slot clear `MissionDialog_ClearResponseButtonSlots_Inferred` `008aa560` (keep distinct). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / inventory / NAMING_REGISTRY as applicable  
- Do **not** claim runtime Confirmed without Launcher evidence.

**Terminal:** **false**

---

## Process

- OWN VA only (`0x008aa490`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (EAX-host, DL-flag, bare RET).  
- Odd behavior preserved: flag store happens even when child is null; vcall pushes full EDX after only DL was assigned at call site.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
