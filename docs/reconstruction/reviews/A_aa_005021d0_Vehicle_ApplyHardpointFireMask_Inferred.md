# Review A (reconstruction fidelity): `aa_005021d0` Vehicle_ApplyHardpointFireMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005021d0` |
| **VA** | `0x005021d0` |
| **Canonical name** | `Vehicle_ApplyHardpointFireMask_Inferred` |
| **Ghidra symbol** | `FUN_005021d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005021d0_Vehicle_ApplyHardpointFireMask_Inferred.md` |
| **System** | `combat` / vehicle hardpoint weapons |
| **Verdict** | **accept-with-gaps** — 3-slot CF + gates + callees + callers sealed; opcode English / FireHelper this residual |

**Tools:** Ghidra `decompile_function` + `read_memory` (entry + mid/epilogue) + `analyze_function_complete` / `get_xrefs_to`. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**Vehicle thiscall** that applies a **3-bit fire mask** to hardpoint weapons under **`vehicle+0x260`**:

| Bit | Slot index | Typical source (AI FireWeapons) |
|---:|---:|---|
| 0 | front / primary | geometry + range gates → `local_3c \|= 1` |
| 1 | secondary | range gate → `\|= 2` |
| 2 | rear | angle gate → `\|= 4` |

Per non-null weapon:

1. **Fire path** if `want && weapon+0xCB==0 && world+0x7E!=0`:
   - `canFire = weapon.vtbl+0x4C(0)`
   - `Weapon_SetFireFlagPair(canFire)`
   - if `canFire`: `Weapon_FireHelper`, optional **LogicUi 0x31** (local player), `new(0x24)` **CVOGHBWeaponFire**, enqueue `world+0xE4EC`, **Start**
2. **Else**: `Weapon_SetFireFlagPair(want)` only (clear when bit off; latch when gated off fire path).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005021d0_FUN_005021d0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_005021d0_FUN_005021d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_ApplyHardpointFireMask_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_005021d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005021d0_Vehicle_ApplyHardpointFireMask_Inferred.md` |
| Live decompile | Ghidra `0x005021d0` — **≡ raw** |
| Live bytes | entry SEH + loop; epilogue **`ret 4`** |
| Parent (context) | `CVOGHBAIFollowVehicle_FireWeapons` builds mask then calls |
| Sibling duals | `Weapon_SetFireFlagPair`, `Weapon_FireHelper`, `CVOGHBWeaponFire_ctor` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: vehicle in **ECX** (saved ESI) |
| Stack args | **1** byte-sized mask (promoted dword): **fireMask** |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | void |
| SEH | `LAB_009a2edf` frame; ExceptionList restore |

### 3.2 Control flow — **SEALED** (clean ≡ raw ≡ live)

| Stage | Match |
|---|---|
| Loop `i = 0..2` | Yes |
| `weapon = *( *(veh+0x260) + i*4 )` | Yes |
| Null weapon → continue | Yes |
| `want = mask & (1<<i)` | Yes |
| Fire triple: want + +0xCB==0 + world+0x7E | Yes |
| vtbl+0x4C → SetFireFlagPair(canFire) | Yes |
| canFire → FireHelper + UI 0x31? + new HB + enqueue + Start | Yes |
| Else → SetFireFlagPair(want) | Yes |
| No invented 4th slot | Yes |

### 3.3 Callees — **SEALED as list**

| Symbol | Role |
|---|---|
| `FUN_0056a260` | fire flag pair +0xC7/+0xC8 |
| `FUN_0056d160` | fire/muzzle helper |
| `FUN_005fe6a0` | weapon-fire HB ctor (type 9; size 0x24) |
| `operator_new(0x24)` | HB allocation |
| `CVOGHBList_Enqueue` | world list +0xE4EC |
| `CVOGHBBase_Start` | start action |
| `Client_SendLogicUiPacket` | opcode field **0x31**, payload slot index |

### 3.4 Callers — **SEALED**

| Function | Sites |
|---|---|
| `CVOGHBAIFollowVehicle_FireWeapons` | `0x005d736b` (always; mask 0 if !param_2) |
| `VehicleNet_ReconcilePrediction` | `0x005fa59e`, `0x005fa5be` |

### 3.5 Three-rep — **SEALED**

Raw 2026-07-23 ≡ live decompile 2026-07-29; epilogue bytes confirm RET 4; loop bound 3 sealed in decomp + parent mask bits 1|2|4.

---

## 4. Gaps (acceptable)

1. Product English for LogicUi **0x31**.
2. Decompiler `FUN_0056d160(&DAT_00b041b0,0)` vs weapon-as-this thiscall (bytes favor weapon ECX; residual).
3. Exact formal map of `FUN_005fe6a0(..., 1000)` period imm (ctor dual notes mangling).
4. Full net-reconcile mask provenance (caller-owned).
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — dual seals AI/net fire-mask applicator on the shared hardpoint table.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| Raw + annotated + clean + record | **Pass** |
| Dual A/B present | **Pass** |
| No disassemble_bytes | **Pass** |
| Own VA only | **Pass** |
