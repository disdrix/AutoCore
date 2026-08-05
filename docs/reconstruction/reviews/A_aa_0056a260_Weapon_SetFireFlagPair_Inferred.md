# Review A (reconstruction fidelity): `aa_0056a260` Weapon_SetFireFlagPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a260` |
| **VA** | `0x0056a260`–`0x0056a27a` |
| **Canonical name** | `Weapon_SetFireFlagPair_Inferred` |
| **Ghidra symbol** | `FUN_0056a260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| **System** | `combat` / vehicle hardpoint weapons |
| **Verdict** | **accept-with-gaps** — ABI + dual-byte CF + hardpoint `this` sealed; product English for +0xC7/+0xC8 pair and non-0/1 domain open |

**Tools:** Ghidra `decompile_function` ×2 + `force_decompile` + `read_memory` body + `analyze_function_complete` / callers / xrefs. No `disassemble_bytes`. Own VA only. No ledgers.

---

## 1. Purpose

Leaf **thiscall** dual-byte setter on a **weapon / hardpoint** object (the three pointers under `vehicle+0x260`):

1. Always write stack `u8` value to **`this+0xC7`**.
2. If **`this+0xC8` ≠ value**, also write the same value to **`+0xC8`**.
3. Return (`RET 4`).

Used to **clear** fire state (`push 0`) on recovery / deactivate paths, and to **push desired fire/active** (`0`/`1` and vfunc-derived bool) from enable and input paths. Sibling `FUN_0056d520` (start-fire) **inlines** the same +0xC7/+0xC8 pattern with value `1` (and also sets `+0xC9`).

**Do not confuse** offset `+0xC7` with the drive-axis **mask constant** `0xC7` on lockobj `+0xb4` (SetSteerInput / SetLongitudinalInput). Same numeric byte, different field family.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056a260_FUN_0056a260.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0056a260_FUN_0056a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_SetFireFlagPair_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0056a260.cpp` (redirect plate) |
| Function record | `docs/reconstruction/functions/aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| Live decompile | Ghidra `0x0056a260` — **≡** raw body |
| Live bytes | `read_memory` len 32 @ entry |
| Callers | DriveControlTick, airStabilization, ActivateEnterWorld, UnpackGhostVehicle, FUN_005021d0, FUN_004f4eb0/f00, FUN_004f9030, FUN_00814400, … |
| Sibling context (not owned) | `FUN_0056d520` start-fire inlines same pair; `FUN_0056b400` sets `+0xCB`; vehicle fire-all `0x004f50d0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__thiscall`**: weapon\* in **ECX** |
| Stack args | **1** byte-sized value (promoted dword on stack): **`u8 value`** |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | void (no EAX product use) |
| Body | `0x0056a260`–`0x0056a27a` (27 bytes); `CC` pad after |
| Callees | **none** (leaf) |

```c
// Canonical sealed signature
void __thiscall Weapon_SetFireFlagPair_Inferred(
    WeaponHardpoint* weapon,   /* ECX */
    unsigned char value);      /* [esp+4], cleaned by RET 4 */
```

### 3.2 Machine body — **SEALED**

`read_memory` @ `0x0056a260` length 32:

```
8a 44 24 04           mov  al, [esp+4]          ; value
38 81 c8 00 00 00     cmp  [ecx+0xc8], al       ; compare latched twin (old)
88 81 c7 00 00 00     mov  [ecx+0xc7], al       ; ALWAYS store desired
74 06                 jz   +6                   ; skip if +0xC8 already == value
88 81 c8 00 00 00     mov  [ecx+0xc8], al       ; store twin only on change
c2 04 00              ret  4
cc cc cc cc cc        int3 pad
```

Decompiler reorders always-store before the compare in pseudocode; **semantics match** because the compare uses the pre-call value of `+0xC8` (store to `+0xC7` does not affect it). Instruction order is: **CMP +0xC8 → MOV +0xC7 → JZ → MOV +0xC8**.

### 3.3 Dual-byte contract — **SEALED**

| Off | Width | Write rule |
|---:|---|---|
| `+0xC7` (199) | u8 | **Always** written = `value` |
| `+0xC8` (200) | u8 | Written = `value` **iff** previous `+0xC8 ≠ value` |

Post-condition when call returns: both bytes equal `value` (if they differed, both updated; if already equal at `+0xC8`, only `+0xC7` is rewritten).

### 3.4 Object identity (`this`) — **SEALED High (family)**

| Evidence | Detail |
|---|---|
| Slot table | Callers load `*(vehicle+0x260)` then `[table + i]` for `i ∈ {0,4,8}` (3 slots) |
| Same table as fire-all | `Vehicle_FireAllPrimaryWeapons_Inferred` `0x004f50d0` uses identical 3-slot walk |
| Start-fire twin | `FUN_0056d520` on same object writes `+0xC7/+0xC8 = 1` and `+0xC9 = 1` |
| Clear twin | Many clear paths: `FUN_0056a260(slot, 0)` then often `slot+0xC9 = 0` (e.g. `FUN_004f9030`, site @ `0x005ff9f5`) |
| airStab recovery | `VehicleAction_airStabilization` zeros all 3 slots via this helper |

**Physics docs** that label `entity+0x260` as “stabilizer slots” are **same table** as primary hardpoint weapons — the clear-on-recovery path is weapon-fire-flag clear, not a separate stabilizer type.

### 3.5 Call graph (live xrefs) — **SEALED as list**

| Caller | VA | Typical arg |
|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` @ `0x009231c8` | `0` (loop clear) |
| `VehicleAction_airStabilization` | `0x00598320` @ `0x00598512` | `0` (post-collision recovery) |
| `Vehicle_ActivateEnterWorld` | `0x00503f30` @ `0x005042d4` | `0` |
| `VehicleNet_UnpackGhostVehicle` | `0x005f7720` @ `0x005f9a01` | value from net bit → `setnz` |
| `FUN_005021d0` | `0x005021d0` @ `0x00502268` / `0x0050234d` | vfunc result **or** bitmask bool |
| `FUN_004f4eb0` / `FUN_004f4f00` | `0x004f4eb0` / `0x004f4f00` | `0` |
| `FUN_004f9030` | `0x004f9030` @ `0x004f9076` | `0` (+ then `+0xC9=0`) |
| `FUN_00814400` | `0x00814400` @ `0x00814452` | `0` |
| (additional sites) | `0x004fb8c4`, `0x005ff9f5` | `1` then `0` / clear pair |

**12** xrefs from `analyze_function_complete` / `get_xrefs_to`.

### 3.6 Three-rep — **SEALED**

| Rep | Status |
|---|---|
| Raw 2026-07-23 | ≡ live decompile CF |
| force_decompile 2026-07-29 | ≡ raw |
| Machine bytes | ≡ dual-store CF; decompiler store order cosmetic only |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| load value from stack | Yes |
| always `+0xC7 = value` | Yes |
| if `+0xC8 != value` then `+0xC8 = value` | Yes |
| no other stores / no callees | Yes |
| `ret 4` | Yes |

```
Weapon_SetFireFlagPair_Inferred(weapon, value):
  // machine: cmp [weapon+0xC8], value first
  weapon[+0xC7] = value           // always
  if weapon[+0xC8] != value:
    weapon[+0xC8] = value
  return
```

---

## 5. Gaps / open

1. Product / PDB name (kept `_Inferred`).
2. English roles of **+0xC7 vs +0xC8** beyond “always vs change-gated twin” (dirty/edge vs pure redundant-store skip).
3. Whether any caller stores values **other than 0/1** (enable path uses bool-like; net path uses setnz).
4. Full consumer map of readers of `+0xC7` / `+0xC8` (IsAnyWeaponFiring / tick / net pack — sibling units).
5. Runtime / bit-exact package policy.

**Verdict:** **accept-with-gaps** — leaf dual-flag setter ABI/CF/offsets/`this` family sealed; product English + consumer inventory open.
