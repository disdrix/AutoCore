# Review A (reconstruction fidelity): `aa_005f5de0` VehicleNet_PackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5de0` |
| **VA** | `0x005f5de0` |
| **Canonical name** | `VehicleNet_PackUpdate` |
| **Ghidra name** | `VehicleNet_PackUpdate` (string-backed; was `FUN_005f5de0` scaffold) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_005f5de0_VehicleNet_PackUpdate.md` |
| **System** | `input-drive-control` (TNL GhostVehicle pack / wire producer) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Retail **client** TNL `packUpdate` for GhostVehicle: serializes mask-gated vehicle state into a `BitStream`.

1. **Null parent gate:** `ghost+0x50 == 0` → log `"Can't save ghost data for vehicle!"` and return **0**.
2. **Resolve vehicle entity:** `entity = vfunc(**(ghost+0x50), +0x1d4)()`.
3. **Initial vs delta (`DAT_00d1798c`):**
   - **Initial (`!= 0`):** optional debug `"Packing initial update for vehicle %I64"`; full create body (template floats, path/skills seeds, owner block with character vs creature branch, hardpoint seeds); then set local dirty accumulator `local_38 = 0x80` (SkillsMask keep-dirty).
   - **Delta (`== 0`):** skip create body; only `SkillsMask` (`param_3 & 0x80`) owner-skills path via `FUN_005b2830` when set.
4. **Hardpoints / equipment (always after initial/skills split):**
   - Wheel: `param_4 & 1` (`WheelSetMask` high dword bit0) → single-flag hardpoint at `entity+600` (`+0x258`).
   - Front/Turret/Rear: table `DAT_009dd198` → masks high `4/8/0x10` against `entity+0x260` slot array (3× pointer stride 4).
   - Melee `param_4 & 0x20` → `entity+0x264`; Ornament `param_4 & 0x40` → `entity+0x26c`.
   - Armor `param_3 & 0x40000000` → `entity+0x254` + six 16-bit resists via vfunc `+0x38`.
5. **Owner-gated GM / clan / pet / murderer / health / AI state.**
6. **PositionMask (`param_3 & 2`):** pos×3 + rot×4 + linVel×3 + angVel×3 (phys host or zero/`DAT_00d02830` fallback) → firing heat-prep on 3 weapons → 8-bit firing set → 8-bit driving flags (`+0x61c` / corpse bit via vfunc) → **quantized thr `+0x614` (6b) + steer `+0x618` (6b)** → turret `+0x158` float32.
7. **Combat tail:** Target / Attribute / Heat `+0x150` / ShieldMax `+0x148` / Shield `+0x144` / Power (owner vfunc) / Token.

**Not** `VehicleNet_UnpackGhostVehicle` (`0x005f7720`) — that is the **client unpack** sibling. This is the **pack** (producer). Server AutoCore mirrors wire order in `GhostVehicle.cs::PackUpdate`.

**Calling convention (decompiler):** `__thiscall` / stack ghost context as first arg; `param_3`/`param_4` = low/high **32-bit halves** of 64-bit TNL update mask; `param_5` connection/stream handle for skill/hardpoint helpers.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005f5de0_FUN_005f5de0.md` | Prior capture; live re-decompile **≡ CF** |
| Annotated | `docs/reconstruction/raw/aa_005f5de0_FUN_005f5de0.annotated.md` | Scaffold + dual plate append |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005f5de0.cpp` (+ Drive_Packing_* aliases) | Scaffold CF present |
| Function record | `docs/reconstruction/functions/aa_005f5de0_FUN_005f5de0.md` | Updated dual seal |
| Live decompile | Ghidra MCP `decompile_function` @ `0x005f5de0` | Full body (~765 lines) |
| Live constants | `read_memory` @ `0x009dd198` (weapon mask table), `0x00d1798c`, `0x00d02830` | Sealed table values |
| Callees | `get_function_callees` | BitStream write*, `FUN_005b1290`, `FUN_005b2830`, `Weapon_CanFireHeatCheck`, log |
| Xrefs | `get_xrefs_to` @ entry | **DATA** `0x009dd1e0` (vtable slot — virtual pack) |
| Server mirror | `src/AutoCore.Game/TNL/Ghost/GhostVehicle.cs` | Mask constants + pack order |
| Pose notes | `physics/verified/server_ghost_pack_notes.md` | PositionMask field order |
| Sibling unpack dual | `reviews/A_aa_005f7720_VehicleNet_UnpackGhostVehicle.md` | Consumer contract |
| System map | `systems/input-drive-control.md` | drive axes on wire |

**Not performed:** Launcher, runtime golden capture, bit-exact package diff, full owner-block English names for every FUN_ leaf, OWN-ONLY other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Canonical role = GhostVehicle **packUpdate** (not unpack) | **High** | Strings + write* BitStream callees + mirror C# |
| Null `ghost+0x50` → fail log + return 0 | **High** | Live first branch |
| Entity via vfunc `+0x1d4` on parent | **High CF** | Live |
| `DAT_00d1798c != 0` = **initial** full body | **High** | String "Packing initial update"; delta skips to skills/`LAB_005f65ca` |
| Initial end sets dirty `0x80` (SkillsMask) | **High** | `local_38 = 0x80` only on initial path |
| `param_3` low-32 / `param_4` high-32 of 64b mask | **High** | Matches GhostObject/GhostVehicle mask constants |
| `PositionMask = 0x2` → pose + thr/steer quant | **High** | `param_3 & 2`; thr/steer `+0x614`/`+0x618` 6-bit |
| Firing byte **before** driving-flags byte | **High** | Heat-prep loop then 8b then 8b (`+0x61c` bit0 path) |
| Wheel `param_4 & 1` / weapons table `4,8,0x10` / melee `0x20` / ornament `0x40` | **High** | `read_memory` DAT_009dd198 + live ifs |
| Hardpoint pack shape: CBID 20b + TFID 64b + global flag | **High CF** | Repeated pattern for each slot |
| Armor `0x40000000` + six 16b resists | **High** | Matches C# ChangeArmor |
| Heat `0x20000000` → `entity+0x150`; ShieldMax `0x2000000` → `+0x148`; Shield `0x4000000` → `+0x144` | **High** | Live combat tail ≡ unpack dual map |
| Power `0x8000000` via owner vfunc `+0x214` short clamp | **High CF** | Live |
| GM `0x10000000` 4-bit when owner present | **High** | Live |
| Health 18b cur + corpse flag; HealthMax 18b | **High** | `param_3 & 8` / `& 0x40` |
| Skills path `0x80` dual: initial FUN_005b1290 body vs delta FUN_005b2830 | **High CF** | Live split |
| 7× "float == 1.0 skip else write 32" on initial | **High structure** | Live; **7th offset may be decomp alias `+0x210` twice** (see gaps) |
| Virtual method (DATA xref only) | **High** | No code callers; vtable `0x009dd1e0` |
| Every leaf product English name | **Low–Medium** | FUN leaves residual |
| Bit-exact / runtime golden | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Null parent early out | **Yes** |
| Initial vs delta split on `DAT_00d1798c` | **Yes** |
| Initial create body (template + owner + skills seed) | **Yes** (large residual detail) |
| Skills delta `0x80` only path | **Yes** |
| Wheel / 3 weapons / melee / ornament / armor | **Yes** |
| GM / clan false-slot / pet / murderer / HP / AI | **Yes** |
| PositionMask pose + thr/steer + turret | **Yes** |
| Target / attributes / heat / shields / power / token | **Yes** |
| No invent unpack/equip side effects in pack | **Yes** |

### 4.1 Mask → gate map (sealed static)

| Wire mask (ulong) | Test in pack | Section |
|---|---|---|
| SkillsMask `0x80` | `param_3 & 0x80` | Owner skills (delta) / initial includes create skills path |
| WheelSetMask `0x1_0000_0000` | `param_4 & 1` | Wheel hardpoint |
| Front/Turret/Rear `0x4/8/10_0000_0000` | DAT_009dd198 pairs | Weapon slots `entity+0x260[i]` |
| Melee `0x20_0000_0000` | `param_4 & 0x20` | `entity+0x264` |
| Ornament `0x40_0000_0000` | `param_4 & 0x40` | `entity+0x26c` |
| ChangeArmor `0x4000_0000` | `param_3 & 0x40000000` | Armor + resists |
| GMMask `0x1000_0000` | `param_3 & 0x10000000` | 4-bit GM |
| ClanMask `0x40_0000` | `param_3 & 0x400000` | Clan payload |
| PetCBIDMask `0x100_0000` | `param_3 & 0x1000000` | Pet CBID |
| MurdererMask `0x20` | `param_3 & 0x20` | Murderer TFID 64b |
| HealthMask `0x8` | `param_3 & 8` | HP 18b + corpse |
| HealthMaxMask `0x40` | `param_3 & 0x40` | Max HP 18b |
| StateMask `0x8000_0000` | high bit path | AI state 8b (owner gated) |
| PositionMask `0x2` | `param_3 & 2` | Pose + thr/steer |
| TargetMask `0x4` | `param_3 & 4` | Target TFID |
| AttributeMask `0x20_0000` | `param_3 & 0x200000` | 4×32 attrib |
| HeatMask `0x2000_0000` | `param_3 & 0x20000000` | Heat f32 bits @ `+0x150` |
| ShieldMaxMask `0x200_0000` | `param_3 & 0x2000000` | `+0x148` |
| ShieldMask `0x400_0000` | `param_3 & 0x4000000` | `+0x144` |
| PowerMask `0x800_0000` | `param_3 & 0x8000000` | Power via owner |
| TokenMask `0x100` | `param_3 & 0x100` | Token flag |

### 4.2 PositionMask wire order (pack)

```
flag(PositionMask)
  pos.xyz f32×3
  rot.xyzw f32×4
  linVel.xyz f32×3
  angVel.xyz f32×3          // zeros via DAT_00d02830 when no phys host
  Weapon_CanFireHeatCheck ×3 (side-effect prep; not separate wire words)
  firingFlags u8            // FIRST flag byte
  driveFlags u8             // SECOND — bit0 handbrake (+0x61c path), bit2 corpse via vfunc
  thr  WriteQuantizedFloat(entity+0x614, 6)
  steer WriteQuantizedFloat(entity+0x618, 6)
  wantedTurret f32 @ entity+0x158
```

### 4.3 Weapon mask table (`DAT_009dd198`)

`read_memory` 2026-07-29 (3 pairs, loop `< 0x009dd1b0`):

| Index | lo (`param_3`) | hi (`param_4`) | Slot |
|---|---|---|---|
| 0 | `0` | `4` | Front @ `*(entity+0x260+0)` |
| 1 | `0` | `8` | Turret @ `+4` |
| 2 | `0` | `0x10` | Rear @ `+8` |

Gate: `writeFlag((table.lo & param_3) | (table.hi & param_4) != 0)` then present-flag then hardpoint triple.

---

## 5. Gaps / open

1. **Decompiler alias residual:** initial 7th optional float shows `entity+0x210` twice; likely `+0x214` for last slot — not machine-proved this pass (OWN-ONLY decompile preferred; no `disassemble_bytes`).
2. **Owner-block leaf English:** character vs creature branches call many vfuncs / `FUN_0042bb40` bit packs — CF sealed, product names Low.
3. **Return value:** decompiler returns `puStack_48` (stack garbage / last pointer); true TNL dirty mask may be `local_38` — **ABI residual** (vtable contract).
4. **Runtime / bit-exact:** not run; server C# is the production mirror, not this client pack path on AutoCore sector.
5. Full initial template float field English (0x1a8/0x1ac/0x1fc…).

**Verdict:** **accept-with-gaps**
