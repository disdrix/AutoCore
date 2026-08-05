# Review A (reconstruction fidelity): `aa_0091b1c0` Client_Camera_Modes257_ChaseUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091b1c0` |
| **VA** | `0x0091b1c0` |
| **Body span** | `0091b1c0` – `0091b8c6` (**1798** bytes; `ret 0x14` @ epilog) |
| **Canonical name (Ghidra)** | `FUN_0091b1c0` |
| **Proposed name** | `Client_Camera_Modes257_ChaseUpdate_Inferred` (**High** role; product string absent) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W25-B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| **System** | client camera / modes 2·5·7 chase update |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client camera updater for dispatcher modes **2, 5, 7**: cache focus, derive horiz forward from quat, optional look-yaw, place eye with yaw×ranges, **one** vertical map distance probe, normalize look, commit render camera.

```
eye = place(focus, cos/sin(yaw), ranges, basis)
eye = verticalPull(eye, MapRaySegmentHitDistance)
look = normalize(...); renderCommit
```

**Calling convention:** MSVC **stdcall** five stack floats + **EDI = cam***, **`ret 0x14`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0091b1c0_FUN_0091b1c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0091b1c0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_Modes257_ChaseUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091b1c0_Client_Camera_Modes257_ChaseUpdate_Inferred.md` |
| Collision helper | `Client_Map_RaySegmentHitDistance_Inferred` @ `0x00916090` (W23-O) |
| Dispatcher | `Client_Camera_ModeDispatchUpdate_Inferred` @ `0x0091ce80` (W25-B twin) |

**This pass (live):** `decompile_function` @ `0x0091b1c0` + caller `0x0091ce80`; `analyze_function_complete`; `get_function_by_address`; `read_memory` entry/epilog/constants + call-site `0x0091d020`. **Not performed:** Launcher, runtime, bit-exact, ledgers. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 1798 B + `ret 0x14` | **Confirmed** | epilog `C2 14 00` |
| 5 stack floats | **Confirmed** | `ret 0x14` + decompile |
| EDI = cam* | **Confirmed** | caller `mov edi,esi` @ `0x0091d040` |
| Sole caller mode arms 2/5/7 | **High** | xref + switch |
| Single vertical `00916090` probe | **Confirmed** | callees + decompile |
| Eye writes `DAT_00d17944+0x228..` | **High** | decompile |
| Quat scale 2.0 @ `0xa10e74` | **Confirmed** | `read_memory` |
| Reject VOG_DEBUG_STOP name | **Confirmed** | string only on null path |
| Product method name | **Tentative** | `_Inferred` |
| Head wheel-scan purpose | Open | unused result |
| Runtime / bit-exact | Open | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Entry stack align + alloc | **Yes** |
| Focus cache to cam+0xd0x | **Yes** |
| Quat forward client vs vehicle | **Yes** |
| Normalize + look_dot | **Yes** |
| Optional look-yaw integrate | **Yes** |
| Debug sprintf/OutputDebugString | **Yes** |
| Eye place cos/sin + basis | **Yes** |
| Vertical probe + pull | **Yes** |
| Normalize + render commit | **Yes** |

### 4.1 Sealed contract

```
// stdcall RET 0x14; EDI = cam*
void Client_Camera_Modes257_ChaseUpdate_Inferred(
    float focus_x, float focus_y, float focus_z,
    float range_a, float range_b);
```

### 4.2 Caller context

`FUN_0091ce80` switch: cases **2, 5, 7** → this VA; EDI preset to cam.

---

## 5. Gaps (non-blocking)

- Product / PDB method name  
- Mode id English for 2/5/7  
- Wheel/slot scan semantics (dead in CF)  
- Nested helper duals (`00917cd0`, `00915da0`, `0090e1b0`, `0099b8b0`)  
- Runtime / bit-exact / diff  

---

## 6. Verdict

**accept-with-gaps** — ABI, mode role, eye path, and dualed collision helper sealed; product naming and residual nested helpers open.
