# Dual A/B report — MEGA-019 OWN-ONLY (`0x007f74a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-019**  
**Scope:** VA `0x007f74a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-019 / input-drive-control residual under `Client_InitDefaultKeybinds` (`0x007f8720`).  
**Hint consumed:** `ActionMap slot-field clear / prologue` → sealed as **`ActionMap_ClearAllSlotBindFields_Inferred`**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007f74a0` ActionMap_ClearAllSlotBindFields_Inferred | **accept-with-gaps** — CF/ABI/ESI/RET/4 banks/stride 0x34/7 fields/sole caller sealed; product mode English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / default-writer / full-map-zero / multi-caller / RET4 / non-leaf claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x007f74a0` — sealed facts

1. **Body:** `0x007f74a0`–`0x007f7560` inclusive (**193 B** / `0xC1`); pad `CC` after final `RET`.
2. **ABI:** **ESI** = ActionMap*; no stack args; void; bare **`RET`** (`C3`). Not ECX-thiscall (ECX = loop cursor).
3. **Semantics:** leaf **slot-field clear / prologue**:
   - Four banks: cursor `@+0x32/+0x136/+0x26E/+0x1ACE`, counts `5 / 6 / 0x78 / 0x14`.
   - Per slot (stride `0x34`): zero key0/key1/mod0/mod1 (u16) + flag/clA/clB (u8).
   - Offsets ≡ dualed sibling `ActionMap_TrySetSlotBind` (`0x007f72e0`) tables.
   - Total slots: **151**. Does not write defaults.
4. **Callees:** **none** (leaf).
5. **Callers (1):** `Client_InitDefaultKeybinds` @ `0x007f8725` (`MOV ESI,EDI` then `CALL`).
6. **Xrefs:** 1 `UNCONDITIONAL_CALL`.
7. **Name:** `ActionMap_ClearAllSlotBindFields_Inferred` (Ghidra `FUN_007f74a0`).  
   Retired: `Named_CalleeOf_Client_InitDefaultKeybinds_007f74a0`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + caller context.

### Gaps

- Product English for four mode groups.  
- Exact product symbol (no demangle).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_007f74a0_FUN_007f74a0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f74a0_FUN_007f74a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_ClearAllSlotBindFields_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f74a0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_InitDefaultKeybinds_007f74a0.cpp` |
| Function | `docs/reconstruction/functions/aa_007f74a0_FUN_007f74a0.md` |
| Function named | `docs/reconstruction/functions/aa_007f74a0_ActionMap_ClearAllSlotBindFields_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InitDefaultKeybinds  0x007f8720  [parent; not OWN]
  ├─ FUN_007f74a0  ActionMap_ClearAllSlotBindFields_Inferred  [OWN MEGA-019]
  │     ESI=EDI ActionMap*; zero all slot bind fields
  ├─ flag-gated default DIK stores (inline)
  └─ ActionMap_TrySetSlotBind  0x007f72e0  [dualed W21-P]  × many (modes 2/3)

Client_ActionMap_Init  0x007f9110  [related; not OWN]
  └─ (init path may reach InitDefaultKeybinds; out of scope)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-007f74a0-mega-019-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `007f74a0` | Port as **ActionMap clear-all-slot-bind-fields** leaf. **ESI = map**, void, **no stack cleanup**. Zero 7 fields × 151 slots (4 banks, stride `0x34`). Call **before** default DIK writes in `InitDefaultKeybinds` so customized flags are clear. Keep distinct from `ActionMap_TrySetSlotBind` (gated write) and from full-struct zero. |
| Pair with | dualed `ActionMap_TrySetSlotBind` `007f72e0`; parent `Client_InitDefaultKeybinds` `007f8720`; residual keymap.ini loader `0092f710`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (input-drive-control / ActionMap)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x007f74a0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; retired `Named_CalleeOf_*` scaffold.  
- Odd behavior preserved: ESI-register ABI (not thiscall); zeros flag so parent can re-default; does not itself write DIK values.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
