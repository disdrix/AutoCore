# Review A (reconstruction fidelity): `aa_004f9030` Vehicle_UpdateWeaponHardpoints3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f9030` |
| **VA** | `0x004f9030` |
| **Body** | `0x004f9030`–`0x004f9563` (`ret` inclusive) |
| **Canonical name** | `Vehicle_UpdateWeaponHardpoints3_Inferred` |
| **Prior / alias** | `FUN_004f9030` |
| **Review date** | `2026-07-29` (W19-A OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004f9030_Vehicle_UpdateWeaponHardpoints3_Inferred.md` |
| **System** | vehicle / combat weapon hardpoints |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Vehicle **primary hardpoint trio** update on each relevant tick:

1. **Optional fire clear** — if lock/control object at MI `+0xb0` has `(byte+0xb4 & 0x13) != 0`, zero fire flags on all three slots under `this+0x260` via `Weapon_SetFireFlagPair(0)` and `slot+0xC9 = 0`.
2. **Per-slot aim / orient / fire** — for `slotIdx = 0..2`: load plant aim vec3, world-transform, build **+Y** yaw quat (angle from `this+0x158` unless mode ∈ {0,1}), compose with vehicle orientation, push to hardpoint iface, call `Weapon_FireHelper`, optional 4×4 gfx path.

Called from vehicle update `FUN_00500560` (just before `CVOGPlayerVehicle_UpdateTurretAiming`) and `FUN_008d7e40`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f9030_FUN_004f9030.md` (+ W19-A re-seal) |
| Annotated | `docs/reconstruction/raw/aa_004f9030_FUN_004f9030.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_UpdateWeaponHardpoints3_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004f9030.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f9030_Vehicle_UpdateWeaponHardpoints3_Inferred.md` |
| Live decompile | ≡ frozen raw CF |
| Live bytes | entry @ `0x004f9030` len 256; epilogue @ `0x004f9560`; `DAT_00af18b0` |
| Meta | body `004f9030`–`004f9563`; **2** xrefs; **11** callees |
| Related duals | `Weapon_SetFireFlagPair`, `Quat_FromAxisAngle`, `Weapon_FireHelper`, `Math_Matrix4x4_Set16` |

---

## 3. Byte seal (summary)

### Entry / ABI

```
55 8B EC 83 E4 F0 81 EC E4 00 00 00 53 56 8B F1
; frame + 16-align + sub 0xe4 + ebx/esi; ESI = ECX (this)
```

| Claim | Evidence | Conf |
|---|---|---|
| ECX this | `8B F1` | **High** |
| Near RET 0 args | `8B E5 5D C3` @ `004f9560` | **High** |
| Slot table +0x260 | `8B 96 60 02 00 00` | **High** |
| Clear fire +0xC9 | `C6 87 C9 00 00 00 00` after call | **High** |
| Call SetFireFlagPair | `6A 00 8B CF E8 …` → `0x0056a260` | **High** |

### +Y axis global

`DAT_00af18b0` bytes: `00 00 00 00 | 00 00 80 3f | 00 00 00 00 | 00 00 00 00` → `(0, 1.0f, 0, 0)`.

### Loop strides (decompile ≡ structure)

| Counter | Step | Meaning |
|---|---|---|
| `local_c4` | start 3, `--` | 3 iterations |
| `local_e4` | `+0xc` | aim vec3 stride |
| `local_e8` | `+4` | slot pointer stride |
| `bVar9` | `+3` | mode field bit shift |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Phase1 gated clear of 3 slots | **Yes** |
| Phase2 3× aim load + transform | **Yes** |
| Mode 3-bit pack + yaw gate | **Yes** |
| Quat +Y × vehicle orient | **Yes** |
| FireHelper + optional matrix path | **Yes** |
| No invent product English | **Yes** (`_Inferred`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 3 primary hardpoints @ +0x260 | **Confirmed** | matches SetFireFlagPair dual |
| ECX vehicle ABI | **Confirmed** | |
| Fire clear pair + +0xC9 | **Confirmed** | |
| Yaw about +Y from mode/angle | **Confirmed** | axis bytes + Quat dual |
| Product method name | **Inferred** | structural only |
| Mode enum English | **Low–Med** | CF values 0/1/2 only |
| Nested `this+8` host class | **Medium** | dual sources sealed; type open |
| Full gfx attach semantics | **Medium** | helpers residual |

---

## 6. Gaps / open

1. Product / PDB / RTTI name.
2. Exact plant mode enum (`+0x50c` 3-bit fields).
3. `FUN_004e9370` / `FUN_004e8830` / `FUN_004e88a0` product names (not OWN).
4. Runtime verification of fire + matrix path.
5. Bit-exact image diff.

**Verdict:** **accept-with-gaps**
