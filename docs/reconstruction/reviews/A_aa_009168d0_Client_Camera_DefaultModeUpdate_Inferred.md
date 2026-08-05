# Review A (reconstruction fidelity): `aa_009168d0` Client_Camera_DefaultModeUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009168d0` |
| **VA** | `0x009168d0` |
| **Body span** | `009168d0` – `00917603` (**3379** bytes; `ret 0x14` @ `00917601`) |
| **Canonical name (Ghidra)** | `FUN_009168d0` |
| **Proposed name** | `Client_Camera_DefaultModeUpdate_Inferred` (**High** role; product string absent) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W24-D) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |
| **System** | client camera / default mode update |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **default camera mode** updater: compute orbit/chase eye from focus + yaw + ranges, optional look-yaw, build look basis, **collision-pull** via eight map segment distance probes, commit eye to the camera bus, write look direction.

```
eye = collisionPull(orbitAim(focus, yaw, ranges))
DAT_00d17944.eye = integrate_or_snap(eye)
lookSlot = gamepadLook || basisFallback || globals
```

**Calling convention:** MSVC **stdcall**, five stack dwords, **`ret 0x14`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.md` |
| Annotated | `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_009168d0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_DefaultModeUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |
| Collision helper | `Client_Map_RaySegmentHitDistance_Inferred` @ `0x00916090` (W23-O dual) |

**This pass (live):** `decompile_function` @ `0x009168d0` + caller `0x0091ce80` + callees `0x00915ad0`/`0x00916090`; `get_function_by_address` / callers / callees; `read_memory` entry, epilogue region, float constants. **Not performed:** Launcher, runtime, bit-exact, ledgers. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 3379 B + `ret 0x14` | **Confirmed** | epilogue `C2 14 00` |
| stdcall 5 stack args | **Confirmed** | `ret 0x14` + decompile signature |
| Sole caller `FUN_0091ce80` default arm | **High** | callers list + switch decompile |
| Orbit aim uses yaw `+0xcc8` + basis `+0x5ac/+0x5b4` | **High** | decompile CF |
| 8-probe inner loop + multi-pass pull | **High** | `iStack_7c < 8` + outer while |
| Collision via dualed `00916090` | **Confirmed** | callees + W23-O |
| Eye writes `DAT_00d17944+0x228/22c/230` | **High** | decompile |
| Look write `*(client+0x250)+0x170..` | **High** | decompile tail |
| Product method name | **Tentative** | `_Inferred` |
| Mode enum English at `+0xcc4` | Open | |
| Gate-byte English | Open | |
| `param_5` = pure dt | Tentative | caller passes its `param_1` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame + stack alloc | **Yes** (entry bytes) |
| Aim from cos/sin yaw | **Yes** |
| Optional yaw nudge block | **Yes** |
| Basis normalize/cross | **Yes** |
| 8× probe + distance | **Yes** |
| Multi-pass pull break conditions | **Yes** |
| Eye commit integrate/snap | **Yes** |
| Gamepad vs basis vs globals look | **Yes** |
| Early returns if look object null | **Yes** |

### 4.1 Sealed contract

```
// stdcall RET 0x14
void Client_Camera_DefaultModeUpdate_Inferred(
    int *cam,
    float *focus_xyz,
    float range_a,
    float range_b,
    float dt_or_scale);

// default mode only (caller switch); uses map DAT_00d1b644 via 00916090
// writes camera eye DAT_00d17944+0x228.. and look slot
```

### 4.2 Caller context

`FUN_0091ce80` switch on `cam[0x331]`:

| Case | Callee |
|---|---|
| 1 | `FUN_00914930` |
| 2, 5, 7 | `FUN_0091b1c0` |
| 3 | `FUN_00914980` |
| **default** | **`FUN_009168d0`** (this VA) |
| 8 | `FUN_0091c220` |

---

## 5. Callers / callees (live)

**Callers (1):**

| VA | Function | Role |
|---|---|---|
| `0x0091ce80` | `FUN_0091ce80` | camera mode dispatcher |

**Callees:**

| VA | Role |
|---|---|
| `0x00916090` | map segment hit distance (dualed) |
| `0x00915ad0` | probe offset builder |
| `0x0076f5f0` | normalize |
| `0x004e8a40` / `0x004e8ad0` / `0x004e88e0` | quat/basis math |

---

## 6. Gaps

1. Product / PDB camera method name.  
2. Full mode-id table English.  
3. Gate flag dictionary (`+0x493`, `+0xa83`, `+0xa86`, map `+0xf5`, …).  
4. Precise `param_5` unit (dt vs scale).  
5. Runtime / bit-exact / diff.

**Verdict:** **accept-with-gaps** — CF/ABI/role sealed; product naming and flag English open.
