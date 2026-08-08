# Dual A/B report — MEGA-046 OWN-ONLY (`0x008aa510`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-046**  
**Scope:** VA `0x008aa510` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + `read_memory` + parent decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-046 / missions-progression — mission dialog response-slot TFID stamp.  
**Hint consumed:** Mission dialog response-slot clear / TFID stamp → **clear** is peer `0x008aa560` (already dualed); **this VA stamps** one slot.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008aa510` MissionDialog_StampResponseSlot_Inferred | **accept-with-gaps** — CF/ABI/RET8/EDI·ESI·EDX/offsets/+0x518 TFID stamp/caption vtbl path/6 xrefs sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): clear-all / reward-chrome / thiscall-ECX / plain-RET / sole-Show-caller / EDX=TFID / create-destroy / packet claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008aa510` — sealed facts

1. **Body:** `0x008aa510`–`0x008aa55b` exclusive (**75 B** / `0x4B`); pad `CC` before dualed clear peer `FUN_008aa560` @ `0x008aa560`.
2. **ABI:** **EDI** = dialog host\*; **ESI** = slot index; **EDX** = caption C-string\*; stack `tfidLo`, `tfidHi`; void; **`RET 8`**.
3. **Semantics:** single-slot response stamp:
   - Bounds: `ESI >= 0 && ESI < dialog+0x510`.
   - If widget `dialog+0x708+ESI*4` non-null: `vtbl+0x1d8(caption,1,1)` then `vtbl+0x34c()`.
   - Store TFID pair at `dialog+0x518+ESI*8` / `+0x51c`.
4. **Callees:** none direct (indirect widget vtbl only).
5. **Callers (2 parents / 6 sites):**
   - `Client_ShowNpcMissionDialogUI` @ `0x00943abe`, `0x00943b12`, `0x00943b48`, `0x00943b5b` — Complete / OK / Accept+Decline with TFID (−1,−1).
   - `FUN_0093e450` @ `0x0093e6c7`, `0x0093e72e` — "Work in progress" or dynamic choice loop.
6. **Xrefs:** 6 `UNCONDITIONAL_CALL`.
7. **Caption seals:** `"Complete"@a2d33c`, `"OK"@a2d338`, `"Accept"@a2d330`, `"Decline"@a2d328`, `"Work in progress"@a2d364`.
8. **Name:** `MissionDialog_StampResponseSlot_Inferred` (Ghidra `FUN_008aa510`).  
   **Retired:** `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510`.
9. **Peer:** dualed `MissionDialog_ClearResponseButtonSlots_Inferred` (`0x008aa560`) — 8-slot wipe inverse family.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB symbol English.  
- Product names for vtbl+0x1d8 / +0x34c.  
- Dynamic TFID domain (`FUN_0057a250` residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa510_FUN_008aa510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_StampResponseSlot_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aa510.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa510.cpp` |
| Function | `docs/reconstruction/functions/aa_008aa510_FUN_008aa510.md` |
| Function named | `docs/reconstruction/functions/aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowNpcMissionDialogUI  [0x009438f0]
  ├─ FUN_008aaf60          header caption
  ├─ set dialog+0x510 = 1 or 2
  ├─ FUN_008ac110          rebuild response XML widgets
  ├─ FUN_008aa510          MissionDialog_StampResponseSlot_Inferred  [OWN MEGA-046]
  │     captions: Complete | OK | Accept/Decline; TFID (−1,−1)
  └─ FUN_008aa760          reward chrome  [dualed residual family]

FUN_0093e450  (choice / "Dialog has no choices from %I64d")
  ├─ FUN_008ac110
  ├─ FUN_008aa510  "Work in progress" (−1,−1) when no choices  [OWN MEGA-046]
  └─ loop FUN_0057a250 → FUN_008aa510  dynamic slots  [OWN MEGA-046]

FUN_008aa560  MissionDialog_ClearResponseButtonSlots_Inferred  [dualed WQ7R-C]
  └─ pre-rebuild wipe of +0x518 TFID bank + +0x708 widgets (peer inverse)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008aa510-mega-046-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008aa510` | Port as **single response-slot stamp**: set button caption + write TFID pair. **EDI=dialog, ESI=slot, EDX=caption, stack lo/hi, RET 8**. Do **not** implement as clear-all (that is `008aa560`). Do **not** confuse with reward banks `+0x558`/`+0x698`. Call after response-chrome rebuild when count at `+0x510` is set. |
| Pair with | dualed clear `008aa560`; rebuild `008ac110`; ShowNpcMissionDialogUI; choice path `0093e450`; residual `FUN_0057a250` for dynamic TFID. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
**Not written by this agent.**
