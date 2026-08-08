# Dual A/B report — R11-037 OWN-ONLY (`0x00914c60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-037**  
**Scope:** VA `0x00914c60` (`aa_00914c60`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual partition — input-drive-control residual **mode latch +0x493 with drive park on clear**.  
**Parent (evidence only):** `0x00914c20` `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00914c60` Client_SetModeLatch493_ParkDriveOnClear_Inferred | **accept-with-gaps** — CF/ABI/RET/xref/callees/byte seals closed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Stop-leaf-identity / enable-park / EAX-host / mission-hash-`+0x538` / multi-caller claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00914c60` — sealed facts

1. **Body:** `0x00914c60`–`0x00914ce5` inclusive (**134 B** / `0x86`); pad `CC` from `0x00914ce6`.
2. **ABI:** **thiscall** ECX = client host; stack `enable` (low byte); void; **`RET 4`** (`C2 04 00`).
3. **Semantics:**
   - **Clear** (`enable==0`) if `*(u8*)(this+0x493) != 0`:
     - `FUN_007fb990` with ESI = `&DAT_00d1a840`
     - `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` with EAX = this (`MOV EAX,EDI` @ `00914ca5`)
     - If `DAT_00d1b9a8` and vtbl`+0xd0` true → vtbl`+4(0)`
   - **Enable** (`enable!=0`) if latch clear and host non-null:
     - If vtbl`+0xd0` false → vtbl`+4(1)`
   - **Always:** f32 zero at `this+0x538` (`XORPS`/`MOVSS`); `FUN_007902a0(this, enable)`.
4. **Callees:** `FUN_007fb990`, `FUN_00914c20`, `FUN_007902a0` + indirect host vtbl.
5. **Callers:** **0** direct; **1** DATA xref vtable slot `@0x00a2f468`.
6. **Name:** `Client_SetModeLatch493_ParkDriveOnClear_Inferred` (Ghidra `FUN_00914c60`). Product map open → `_Inferred`.
7. **Decompile ≡ raw CF**; `+0x538` store form sealed via disasm as **f32** (decompiler dword-0).
8. **Polarity:** drive park **only on clear**; query polarity inverted enable vs clear.

### Gaps

- Product English for latch `+0x493`, float `+0x538`, host vtbl slots.  
- Owning class of vtable `@00a2f468`.  
- Residual callees `007fb990` / `007902a0` (not dualled; OWN-ONLY).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SetModeLatch493_ParkDriveOnClear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c60.cpp` |
| Function | `docs/reconstruction/functions/aa_00914c60_FUN_00914c60.md` |
| Function named | `docs/reconstruction/functions/aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
vtable @ 00a2f468  →  FUN_00914c60  [OWN R11-037]
  ├─ clear: FUN_007fb990 (ESI=&DAT_00d1a840)     [residual]
  ├─ clear: FUN_00914c20 StopHb+ZeroLong         [dualed MEGA-098]
  │     ├─ CVOGHBBase_Stop                       0x005081d0
  │     └─ VehicleEntity_SetLongitudinalInput    0x004f5650
  ├─ optional: DAT_00d1b9a8 vtbl +0xd0 / +4      [cursor host]
  └─ always: FUN_007902a0 (apply +0x493)         [residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00914c60-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00914c60` | Port as **virtual client mode-latch setter**. thiscall ECX + stack enable + RET 4. |
| Clear path | UI cleanup + StopHb+ZeroLong + optional host notify(0). |
| Enable path | Optional host notify(1) only — **no** drive park. |
| Always | Zero f32 `+0x538`; apply latch via `007902a0`. |
| Do not merge with | `00914c20` park leaf (EAX host; no latch). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- progress / WORK_QUEUE residual clear for R11-037  

**Terminal:** **false**.
