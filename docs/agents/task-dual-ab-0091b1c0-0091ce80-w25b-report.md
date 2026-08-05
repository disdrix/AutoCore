# Dual A/B report — W25-B OWN VAs `0x0091b1c0` + `0x0091ce80`

**Date:** 2026-07-29  
**Agent:** W25-B (OWN-ONLY dual A/B)  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module / base:** `autoassault.exe` @ `0x400000`  
**Owned VAs only:** `0x0091b1c0`, `0x0091ce80`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ function meta / xrefs / callees / call-site reads). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_0091b1c0` @ `0x0091b1c0` | `Client_Camera_Modes257_ChaseUpdate_Inferred` | **accept-with-gaps** |
| `aa_0091ce80` @ `0x0091ce80` | `Client_Camera_ModeDispatchUpdate_Inferred` | **accept-with-gaps** |

Both A and B reviews agree per VA.

---

## VA1 — `0x0091b1c0` Client_Camera_Modes257_ChaseUpdate_Inferred

### Sealed facts

1. **Body:** `0091b1c0`–`0091b8c6` (**1798** B / `0x706`). Epilogue **`ret 0x14`** (`C2 14 00`).
2. **ABI:** MSVC **stdcall** 5 stack floats (focus xyz + range_a + range_b) + **EDI = cam*** (caller `mov edi,esi` @ `0x0091d040`).
3. **Role:** Camera modes **2 / 5 / 7** chase update — sole caller `FUN_0091ce80` switch arms.
4. **Focus cache:** `cam+0xd04/0xd08/0xd0c`; dirty `cam+0xd00 = 0`.
5. **Forward:** quat→horiz axis with factor **2.0** (`0x00a10e74`); client vs vehicle branch.
6. **Look-yaw:** optional integrate `|look_dot| * 12.0 * 3.5` into `cam+0x538` when flags `+0x493` && `+0xa83`.
7. **Eye place:** `cos/sin(cam+0xcc8)` × ranges × basis `+0x5ac/+0x5b4` + focus → `DAT_00d17944+0x228/22c/230`.
8. **Collision:** **single** vertical probe via dualed `Client_Map_RaySegmentHitDistance_Inferred` (`0x00916090`); pad Y+**5.0**; gate **0.2**.
9. **Reject alias:** `Named_VOG_DEBUG_STOP_0091b1c0` — string is null-client abort only.
10. **Decompile ≡ bytes** for CF; ABI refined from call-site.

### Gaps

- Product / PDB method name  
- Mode 2/5/7 English labels  
- Head wheel-scan purpose (unused CF)  
- Nested helper duals  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0091b1c0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_Modes257_ChaseUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_0091b1c0_FUN_0091b1c0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0091b1c0.md` |

---

## VA2 — `0x0091ce80` Client_Camera_ModeDispatchUpdate_Inferred

### Sealed facts

1. **Body:** `0091ce80`–`0091d433` (**1459** B / `0x5B3`). Epilogue **`ret 4`** (`C2 04 00`).
2. **ABI:** **EAX = cam*** on entry (`mov esi,eax`); one stack float `dt_or_scale`; void.
3. **Role:** Client **camera mode dispatcher** tick — focus resolve, gate, ranges, **switch(`cam[0x331]` / +0xCC4)**, post look + FOV band + optional velocity FOV.
4. **Mode table:** 1→`00914930`; **2/5/7→`0091b1c0`**; 3→`00914980`; **default→`009168d0` (W24-D dual)**; 8→`0091c220`.
5. **Focus:** `FUN_00917cd0`; pose fallback Y+**4.0**; map flag Y+**1.5**.
6. **Post:** look = focus−eye (skip mode 8 path); modes 4/5 special Y blend (0.05/0.4); FOV band clamp ~**1.5** to child `+0xf0`.
7. **Caller:** sole xref site `0x00924283` (`push ebx; mov eax,edi; call`) — containing function undefined in Ghidra (~`0x00923db0` region).
8. **Decompile ≡ bytes** for CF; ABI refined from entry/epilog.

### Gaps

- Product / PDB method name  
- Mode enum English  
- Duals for mode helpers 1/3/8  
- Containing caller function identity  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.md` |
| Annotated | `docs/reconstruction/raw/aa_0091ce80_FUN_0091ce80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0091ce80.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_ModeDispatchUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_0091ce80_FUN_0091ce80.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0091ce80_Client_Camera_ModeDispatchUpdate_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0091ce80.md` |

---

## AutoCore impact

- **`0091ce80`:** client-only camera mode dispatcher. Server ports do not need this switch; if camera collision parity is required, reuse dualed map segment distance (`00916090`) contracts rather than inventing server camera modes.
- **`0091b1c0`:** client-only chase path for modes 2/5/7. Do not conflate with default multipass (`009168d0`) — this is a **single vertical** probe. Preserve EDI=cam* + five float stack ABI when hooking/reimplementing.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`0091b1c0`, `0091ce80`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |
