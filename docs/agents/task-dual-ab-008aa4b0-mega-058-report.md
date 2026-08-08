# Dual A/B report — MEGA-058 OWN-ONLY (`0x008aa4b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-058**  
**Scope:** VA `0x008aa4b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `disassemble_function` + `read_memory` + callers/xrefs + caller disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — missions-progression dialog helper before thr/steer park (`FUN_009373e0` / ShowNpc parent `0x009438f0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008aa4b0` MissionDialog_SetNpcObjectAndNameCaption_Inferred | **accept-with-gaps** — ESI/EAX ABI, `+0x644` stamp, `+0x6d8` caption bind/clear, SetText arity split, tail JMP `+0x34c`, 3 call sites sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-ECX / stack-RET4 / header-merge / thr-park-merge / ShowNpc-only / single-arity SetText claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008aa4b0` — sealed facts

1. **Body:** `0x008aa4b0`–`0x008aa50e` inclusive (**95 B** / `0x5F`); pad `CC` before sibling `0x008aa510`.
2. **ABI:** **ESI** = mission dialog host*; **EAX** = NPC object* (0 = clear); void; plain **`RET`** (`C3`). Not entry thiscall.
3. **Semantics:**
   - Always `dialog+0x644 ← EAX` (NPC object stamp; dualed ShowNpc already-active compare).
   - Widget `dialog+0x6d8`: null → return after stamp.
   - NPC 0: widget **vtbl+0x1d8**(`&DAT_00a1419b`, 1, 1) — empty C-string.
   - NPC non-0: secondary-vtbl **+0x160**(1,1) display name; widget **vtbl+0x1d8**(name) **one** stack arg.
   - Common tail: **JMP** widget **vtbl+0x34c** (refresh). Decompiler "jumptable" warning is the tail-jump.
4. **Callees:** none direct FUN_*; virtual only. analyze classification **leaf**.
5. **Callers (3 UNCONDITIONAL_CALL):**
   - `Client_ShowNpcMissionDialogUI` @ `0x0094397d` (multi-active journal early): `EAX=[ESP+0x18]`, `ESI=EBX`.
   - `Client_ShowNpcMissionDialogUI` @ `0x00943a75` (main present): `EAX=[ESP+0x18]`, `ESI=EBX`.
   - `FUN_009373e0` @ `0x00937411` (dialog thr/steer/HB park gate): `EAX=[ESP+8]`, `ESI=[EDI+0x1058]`.
6. **Xrefs:** 3 UNCONDITIONAL_CALL (same sites).
7. **Sibling chrome:** dualed `Client_MissionDialog_SetHeaderCaption_Inferred` (`0x008aaf60`) uses **`+0x6e0`** with same paint pair — this unit is **name caption `+0x6d8`** + **object stamp `+0x644`**.
8. **Name:** `MissionDialog_SetNpcObjectAndNameCaption_Inferred` (Ghidra `FUN_008aa4b0`). Product map open → `_Inferred`.  
   **Retired:** `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` (misses `FUN_009373e0`).
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site framing.

### Full body hex (95 B)

```
8b8ed806000085c9898644060000744e85c0742b8b50048b5204578b398d4402048b106a016a018bc8ff92600100008b8ed806000050ff97d80100005feb118b016a016a01689b41a100ff90d80100008b8ed80600008b11ffa24c030000c3
```

### Gaps

- Product/PDB English; vtbl `+0x160`/`+0x1d8`/`+0x34c` product names.  
- GetName return type; SetText arity asymmetry rationale.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa4b0_FUN_008aa4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionDialog_SetNpcObjectAndNameCaption_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aa4b0.cpp` |
| Function | `docs/reconstruction/functions/aa_008aa4b0_FUN_008aa4b0.md` |
| Function named | `docs/reconstruction/functions/aa_008aa4b0_MissionDialog_SetNpcObjectAndNameCaption_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowNpcMissionDialogUI  0x009438f0  [dualed]
  ├─ … Prepare / multi-active journal path …
  ├─ FUN_008aa4b0  MissionDialog_SetNpcObjectAndNameCaption_Inferred  [OWN MEGA-058]
  ├─ Client_UpdateMissionJournal / FUN_0092f090 finalize …
  └─ main present: FUN_008aa4b0 then reward chrome / thr-adjacent finalize

FUN_009373e0  dialog gate thr0+steer0+HB  [residual MEGA-024]
  ├─ FUN_007fef20(10,0,0)
  ├─ FUN_008aa4b0  [OWN MEGA-058]  ← "dialog helper before thr/steer park"
  └─ VehicleEntity_SetLongitudinal(0) / SetSteer(0) / SetHandbrake

Client_MissionDialog_SetHeaderCaption_Inferred  0x008aaf60  [dualed]
  └─ sibling paint on +0x6e0 (not this VA)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008aa4b0-mega-058-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008aa4b0` | Port as **register-ABI** dialog helper: **ESI=dialog**, **EAX=npc**. Always write **NpcObject** at `+0x644`. Bind/clear **name caption** widget `+0x6d8` via SetText family; preserve **3-arg clear** vs **1-arg bind** and **tail refresh**. |
| Distinct from | header caption `008aaf60` (`+0x6e0`); thr/steer park body in parent `009373e0`; response-slot `008aa510`. |
| Pair with | dualed ShowNpc `009438f0`; residual park gate `009373e0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` / system map `missions-progression.md` (if desired)
- Retire scaffold alias `Named_CalleeOf_Client_ShowNpcMissionDialogUI_008aa4b0` in any remaining indexes
