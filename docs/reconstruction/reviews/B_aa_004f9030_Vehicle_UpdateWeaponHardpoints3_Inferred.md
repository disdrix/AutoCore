# Review B (skeptical / adversarial): `aa_004f9030` Vehicle_UpdateWeaponHardpoints3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f9030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-A OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_004f9030_Vehicle_UpdateWeaponHardpoints3_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | cdecl with stack `this` | Entry `MOV ESI,ECX`; epilogue near `RET` | **Falsified** — **ECX this** |
| 2 | Updates turret only | No call to `CVOGPlayerVehicle_UpdateTurretAiming` (sibling in caller); walks **+0x260** hardpoints | **Falsified** — **hardpoints ×3** |
| 3 | Slot count ≠ 3 | `local_c4=3` / phase1 `local_e8=3`; strides 4 / 0xC / bit+3 | **Confirmed 3** |
| 4 | Always clears fire | Clear gated on lock obj + `(+0xb4 & 0x13)` | **Confirmed gated** |
| 5 | Clears only +0xC7 | Explicit `slot+0xC9=0` after SetFireFlagPair(0) | **Confirmed third byte** |
| 6 | Axis is +Z / vehicle forward | `DAT_00af18b0` = `(0,1,0,0)` | **Falsified** — **+Y** |
| 7 | Always applies vehicle yaw | mode ∈ {0,1} forces angle **0** | **Confirmed gated** |
| 8 | FireHelper always | Requires non-null slot **and** `slot+8` iface | **Confirmed gated** |
| 9 | Is matrix-only / pure math | Has fire helper + vtbl side effects | **Falsified** — combat update |
| 10 | Scaffold “unknown system” | Hardpoint table + sealed weapon callees + vehicle tick caller | **System is vehicle combat hardpoints** |
| 11 | Product name proven | No string/RTTI on unit | **Still `_Inferred`** |
| 12 | Self-recursive (scaffold note) | callees list has no self; bulk scaffold lied | **No self-call** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-slot hardpoint identity | **High** | Wrong weapon system on server |
| Fire clear gate | **High** | Stuck fire state / false clear |
| Mode packing (3×3 bits @ +0x50c) | **High** | Wrong yaw / mode branch |
| +Y yaw axis | **High** | Aim tilts wrong axis |
| Product English | **Medium** | Naming only |
| Nested host `this+8` type | **Medium** | Wrong pos/orient source in ports |
| Gfx attach full contract | **Medium** | Cosmetic only if unused path |

---

## 3. Cross-check against raw + bytes

```
raw phase1:
  lock = MI(+0xb0); if lock && (lock+0xb4 & 0x13):
    for 3: SetFireFlagPair(slot,0); slot+0xc9=0

raw phase2:
  for 3:
    aim = plant+0x4e8+i*12
    FUN_004e9370(pos, orient, aim, out)
    mode = (plant+0x50c >> i*3) & 7
    angle = mode in {0,1} ? 0 : this+0x158
    FUN_00567ce0(+Y, angle); quat mul; FUN_004e8830
    if mode==2 && this+0x3a0: vtbl
    if slot && slot+8: vtbl set; FireHelper; optional matrix

bytes:
  8BF1 … 8B9660020000 … 6A00 8BCF E8… c687c900000000
  epilogue 8BE55DC3
  DAT_00af18b0 = 0,1,0,0

caller FUN_00500560 @ 00500612:
  FUN_004f9030(); FUN_004fc010(); FUN_004fa0f0(); UpdateTurretAiming();
  ≡ hardpoint pass distinct from turret aiming sibling
```

---

## 4. Surviving contract for AutoCore

```csharp
// Per-tick primary hardpoint update (client vehicle).
void VehicleUpdateWeaponHardpoints3(Vehicle v)
{
    // Optional clear when control flags & 0x13
    if (v.LockObj != null && (v.LockObj.FlagsB4 & 0x13) != 0)
        for (int i = 0; i < 3; i++)
            ClearFireFlags(v.Hardpoints[i]); // +0xC7/+0xC8 via SetFireFlagPair; +0xC9=0

    for (int i = 0; i < 3; i++)
    {
        var aim = v.Plant.AimOffset[i];           // +0x4E8 + i*12
        int mode = (v.Plant.ModePack >> (i * 3)) & 7; // +0x50C
        float yaw = (mode == 0 || mode == 1) ? 0f : v.YawAt158;
        // world aim + QuatFromAxisAngle(+Y, yaw) * vehicleOrient
        // push hardpoint iface; WeaponFireHelper(...); optional gfx matrix
    }
}
```

- Server ports for ghost fire must align hardpoint clear / mode / yaw sources — do **not** fold turret aiming into this unit.
- Reuse sealed helpers: SetFireFlagPair, FireHelper, Quat_FromAxisAngle, Matrix4x4_Set16.

---

## 5. Gaps surviving review

1. Product / PDB name (`_Inferred` retained).
2. Mode enum English beyond CF branches 0/1/2.
3. Helper product names (`004e9370` / `004e8830` / …) residual.
4. Runtime / differential verification.
5. Bit-exact image diff.
6. Clean C++ is documentation CF (not compile-linked against retail).

**Verdict:** **accept-with-gaps** — ABI, 3-slot CF, fire clear, mode/yaw/+Y, callees **sealed**; product English + helper names open.
