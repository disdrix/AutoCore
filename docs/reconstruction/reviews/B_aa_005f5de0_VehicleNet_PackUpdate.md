# Review B (skeptical / adversarial): `aa_005f5de0` VehicleNet_PackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A narrative polish) |
| **Counterpart** | `reviews/A_aa_005f5de0_VehicleNet_PackUpdate.md` |
| **System** | `input-drive-control` (TNL GhostVehicle pack) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on initial/delta split, mask→section map, PositionMask thr/steer order, hardpoint table; **reject** overclaims that this is unpack, that it is server C#, that return is proven dirty-mask, or that every owner-leaf is product-named |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `VehicleNet_UnpackGhostVehicle` | Would invert producer/consumer | **Falsified** — only `BitStream_write*`; no readFlag/readInt |
| 2 | This is AutoCore server `GhostVehicle.PackUpdate` | Wrong binary / port target | **Falsified** — client VA `0x005f5de0` in `autoassault.exe`; C# is a **mirror** |
| 3 | `DAT_00d1798c == 0` means initial | Invert create vs delta | **Falsified** — initial string + full body under `!= 0`; delta goto skills label |
| 4 | Wheel uses `param_3` low bit | Wrong mask half | **Falsified** — `param_4 & 1` (high dword of WheelSetMask) |
| 5 | Weapons are a single combined flag | Drop slot independence | **Falsified** — 3-entry table + separate melee/ornament |
| 6 | thr/steer are full f32 on wire | Bandwidth / unpack mismatch | **Falsified** — `BitStream_writeQuantizedFloat(..., 6)` |
| 7 | Driving flags byte is packed **before** firing | Handbrake/Firing swap (known NPC bug class) | **Falsified** — heat-prep → 8b firing → 8b flags with `+0x61c` |
| 8 | Heat writes `+0x614` | Confuse thr slot | **Falsified** — Heat uses `entity+0x150` under `0x20000000` |
| 9 | Static code callers exist for pack | Missed call graph | **Falsified** — DATA-only xref at `0x009dd1e0` (vtable) |
| 10 | Null parent still packs pose | Crash / empty ghost | **Falsified** — early return 0 after log |
| 11 | Armor has no resist array | Incomplete ChangeArmor | **Falsified** — six 16-bit writes after TFID |
| 12 | Package bit-exact / runtime sealed | Premature complete | **Fail** — static dual only |

---

## 2. Decisive dataflow (raw ≡ live)

```
// GhostVehicle::packUpdate (virtual) — client image
// mask64 = (param_4 << 32) | param_3   // halves as used below

if (*(ghost + 0x50) == 0) {
  log("Can't save ghost data for vehicle!");
  return 0;
}
entity = vfunc(parent, 0x1d4)();

if (DAT_00d1798c != 0) {                 // INITIAL
  maybe log("Packing initial update for vehicle %I64", tfid);
  FUN_005b1290(conn);                    // initial skills/create seed
  write 32+32 template ids (entity+0x1a8, +0x1ac);
  write flags / byte / up to 7 optional floats (==1.0 omit);
  optional path block; optional IDs; 8× skill short table @ +0x28c;
  owner present? → character OR creature owner wire;
  local_dirty = 0x80;                    // SkillsMask keep
} else {
  // DELTA skills only:
  if writeFlag(mask & 0x80): pack owner skills via FUN_005b2830
}

// hardpoints (initial + delta)
if writeFlag(mask_hi & 1):     pack hardpoint entity+0x258   // Wheel
for i in 0..2:                 // DAT_009dd198 → hi 4,8,0x10
  if writeFlag(table[i] & mask) && present(entity+0x260[i]): pack hardpoint
if writeFlag(mask_hi & 0x20) && present(+0x264): melee
if writeFlag(mask_hi & 0x40) && present(+0x26c): ornament
if writeFlag(mask_lo & 0x40000000) && present(+0x254): armor + 6×u16

// owner-gated + combat + pose + tail (mask bits as dual A table)
if writeFlag(PositionMask=0x2):
  pos, rot, linVel, angVel
  heatcheck weapons[0..2]
  writeBits8(firing); writeBits8(driveFlags);   // ORDER sealed
  writeQuantizedFloat(entity+0x614, 6);          // thr
  writeQuantizedFloat(entity+0x618, 6);          // steer
  writeBits32(entity+0x158);                    // turret

// Heat/ShieldMax/Shield/Power/Token ...
return /* decomp: stack residue; dirty ABI residual */;
```

Live re-decompile 2026-07-29 ≡ frozen raw CF for all mask gates listed in dual A §4.1.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pack not unpack | **High** | Invert wire port |
| Initial vs delta on `DAT_00d1798c` | **High** | Missing create body / double-pack |
| 64-bit mask halves | **High** | Wrong hardpoint/pose dirty |
| Wheel/weapon/ornament mask bits | **High** | Null wheels / missing guns |
| DAT_009dd198 = Front/Turret/Rear | **High** | Slot swap |
| PositionMask thr/steer 6-bit + order | **High** | Handbrake/NPC drive bugs |
| Combat offset map Heat/Shield/Power | **High** | Pool desync |
| Vtable-only entry | **High** (static) | Missed direct calls if any |
| Owner branch product names | **Low** | Misnamed port helpers |
| Return dirty mask ABI | **Medium residual** | TNL clear/dirty wrong |
| Initial 7th float offset | **Medium residual** | One omitted pool scale |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `ghost+0x50` parent | Soft optional? | **No** — hard null check + log |
| Initial flag `DAT_00d1798c` | Global always 0? | Image default 0 (delta); set by TNL initial path elsewhere |
| `entity+0x614` thr | Heat alias? | **No** — only under PositionMask quant path |
| `entity+0x618` steer | thr twin wrong width? | **No** — same 6-bit quant |
| `entity+0x150` heat | pose field? | **No** — HeatMask only |
| Firing before flags | Swap safe? | **No** — unpack dual + server notes require this order |
| Wheel `+0x258` / 600 decimal | Wrong slot? | **Same** — decomp `600` == `0x258` |
| Weapon base `+0x260` | One pointer? | **No** — stride-4 array ×3 |
| Armor `+0x254` + vfunc `+0x38` | CBID only? | **No** — six extra 16b |
| `DAT_009dd198` contents | Guessed masks? | **No** — `read_memory` 4/8/0x10 |
| Return `puStack_48` | True dirty? | **Untrusted decomp** — residual |

---

## 5. Surviving contract for AutoCore

```
// Client retail GhostVehicle pack (reference for server C# mirror)

VehicleNet_PackUpdate(ghost, /*stream ctx*/, maskLo, maskHi, conn):
  if ghost.parent == null: log; return 0
  entity = parent.GetVehicleEntity()          // vfunc +0x1d4

  if isInitial:                               // DAT_00d1798c
    packInitialCreateBody(entity, conn)       // template, owner, skills seed
    keepDirty |= SkillsMask                   // 0x80
  else if mask & SkillsMask:
    packOwnerSkillsDelta(conn)

  packHardpoint(mask & WheelSetMask, entity.wheel)
  packHardpoints3(mask & Front/Turret/Rear, entity.weapons[0..2])
  packHardpoint(mask & Melee, entity.melee)
  packHardpoint(mask & Ornament, entity.ornament)
  packArmorIf(mask & ChangeArmor)

  packGM / clan-slot / pet / murderer / health / healthMax / AI state
  if mask & PositionMask:
    packPose(entity)            // pos rot linVel angVel
    packFiringByte then DriveFlagsByte
    packQuant thr(+0x614), steer(+0x618) @ 6 bits
    pack turret(+0x158)
  packTarget / attributes / heat / shieldMax / shield / power / token

// Server AutoCore must match field order + mask gates for client unpack 0x005f7720.
// This client pack is the RE ground truth for producer order when server diverges.
```

---

## 6. Open questions

1. Confirm return ABI (dirty mask vs void) via call-site / TNL base — decomp return is untrusted.
2. Machine-confirm 7th initial float offset (`+0x210` vs `+0x214`) if bit-exact initial create needed.
3. Runtime one initial + one PositionMask delta capture against server C# for thr/steer bytes.
4. English names for `FUN_005b1290` / `FUN_005b2830` / `FUN_0042bb40` (OWN-ONLY leave for their VAs).

**Verdict:** **accept-with-gaps**
