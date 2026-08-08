# Dual A/B report — MEGA-074 OWN-ONLY (`0x0082f8d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-074**  
**Scope:** VA `0x0082f8d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/callee decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition `WAVE_2026-08-05_mega_residual_partition_map.md` row MEGA-074.  
**Hint:** `UI_InteractionMenu_AddIgnoreToggle`.  
**System (partition):** skills-abilities (nested under dualed interaction-menu parent).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082f8d0` UI_InteractionMenu_AddIgnoreToggle | **accept-with-gaps** |

Path A (fidelity): CF/ABI/EAX-target/EDI-host/strings/ids/slots/callers/`FUN_00573af0` sealed; product host class + `+0x6B4` English open → **accept-with-gaps**.  
Path B (adversarial): skill-cast / thiscall-ECX / dual-button / friends-merge / plate-as-canonical / phantom-reg claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre-MEGA-074)

| Artifact | Pre | MEGA-074 action |
|---|---|---|
| Raw capture | present (2026-07-23) | **Appended** live re-verify (body preserved) |
| Annotated | scaffold only | **Refreshed** full annotated |
| Clean named cpp | plate `UI_int_btn_generic_*` | **Replaced** with role name |
| FUN twin | scaffold | **Updated** to include named clean |
| FUN function record | partial scaffold | **Updated** |
| Named function record | missing | **Created** |
| Review A | missing | **Created** |
| Review B | missing | **Created** |
| Report | missing | **This file** |

---

## VA `0x0082f8d0` — sealed facts

1. **Body:** `0x0082f8d0`–`0x0082f988` inclusive (**185 B** / `0xB9`); pad `CC` after exclusive end `0x0082f989`.
2. **ABI:** **EAX** = target object*; **EDI** = menu host*; void; bare **`RET`** (`C3`) / **ret 0**. Not MSVC thiscall.
3. **Semantics:**
   - Gate on object `+0x6B4`: enter if `target.field < 1` **or** `local.field >= 1` (`DAT_00d1b6d8`).
   - If social host `DAT_00d1da2c` non-null: get target name via MSVC adjustor `vtbl+0x160`; lookup `FUN_00573af0(host, name)`.
   - Hit → create **Remove from Ignore** (`id 0x1117c`), store host `+0x56c`, return.
   - Miss / no host → create **Add to Ignore** (`id 0x11179`), store host `+0x560`.
   - Widget plate: `i_m_int_2d_btn_generic.xml`; caption via btn `vtbl+0x1d8`.
4. **Callers (code):** only dualed parent `FUN_0082fe20` @ `0x0082feea` (order-flag ≠ 0, last pack) and `0x0082fef6` (order-flag == 0, first pack).
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Callees:** direct `FUN_00573af0` only; indirect target `+0x160`, menu `+0x444`, btn `+0x1d8`.
7. **Name:** `UI_InteractionMenu_AddIgnoreToggle` (Ghidra `FUN_0082f8d0`). Role sealed by product UI English; plate alias `UI_int_btn_generic_0082f8d0` **retired**.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + parent call-site context (`MOV EAX,EBP` / `MOV EDI,ESI`).
9. **Twin shape:** dualed Friends pack `UI_InteractionMenu_AddFriendsToggle` (`0x0082f9a0`, same 185 B / EAX-EDI / gate) — distinct ids, slots, lookup, strings.

### Gaps

- Product / MSVC class for menu host and `DAT_00d1da2c`.  
- English for `+0x6B4`.  
- Dual of `FUN_00573af0` / name-getter vtbl (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ MEGA-074 re-verify) | `docs/reconstruction/raw/aa_0082f8d0_FUN_0082f8d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f8d0_FUN_0082f8d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddIgnoreToggle.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082f8d0.cpp` |
| Scaffold alias (retired) | `docs/reconstruction/reconstructed-exact/UI_int_btn_generic_0082f8d0.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0082f8d0_FUN_0082f8d0.md` |
| Function named | `docs/reconstruction/functions/aa_0082f8d0_UI_InteractionMenu_AddIgnoreToggle.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed]
  ├─ gate host+0x4C0; rebuild shell FUN_0082d2b0
  ├─ resolve TFID @ host+0x578; affinity / self gates
  ├─ EBP = target.vtbl+0x210(0)   // social-action target
  ├─ EDI = ESI = menu host
  ├─ order A (vtbl+0x478 == 0):
  │     FUN_0082f8d0  UI_InteractionMenu_AddIgnoreToggle  [OWN MEGA-074]
  │     FUN_0082f9a0  UI_InteractionMenu_AddFriendsToggle  [dualed MEGA-075]
  │     FUN_0082f810  Tell
  │     FUN_0082fc40  Trade
  │     FUN_0082fa60  Clan
  │     FUN_0082fb30  Convoy  [dualed]
  │     FUN_0082fd50  Name
  └─ order B (vtbl+0x478 != 0): reverse of above
        └─ FUN_0082f8d0 last

FUN_0082f8d0  [OWN]
  └─ FUN_00573af0  ignore-list name lookup on DAT_00d1da2c  [undualed]
       walk [+0x38,+0x3c); _stricmp(entry+0x10, name)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082f8d0-mega-074-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082f8d0` | Port as **interaction-menu Ignore Add/Remove toggle**. **EAX=target, EDI=host**, void, bare RET. Membership via `FUN_00573af0(DAT_00d1da2c, name)`. Slots **+0x560** Add / **+0x56c** Remove. Ids **0x11179** / **0x1117c**. |
| Do not | Treat as skill-cast residual; merge with Friends twin `0082f9a0`; invent product menu class; use plate name as canonical; assume thiscall ECX=menu. |
| Pair with | dualed parent `0082fe20`; dualed Friends `0082f9a0`; dualed Convoy `0082fb30`; undualed lookup `00573af0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/*` residual tables (UI / interaction menu — not cast manager)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0082f8d0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + parent/callee decompiles. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful role name; plate scaffold retired via include redirect.  
- Register ABI (EAX/EDI) restored beyond decompiler phantoms via parent sites.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
