# Review A (reconstruction fidelity): `aa_0056d160` Weapon_FireHelper_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056d160` |
| **VA** | `0x0056d160` |
| **Canonical name** | `Weapon_FireHelper_Inferred` (was `FUN_0056d160`) |
| **Ghidra symbol** | `FUN_0056d160` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056d160_Weapon_FireHelper_Inferred.md` |
| **System** | combat / vehicle weapon |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — dual fire/muzzle CF sealed; full wire opcodes residual |

---

## 1. Purpose

**Weapon fire / muzzle-state helper** on a weapon-like `this` object. Two major branches on flag byte **`this+0xc4 & 0x80`**:

### Path A — bit7 clear (primary fire packet path)

1. One-shot init: if `+0xb2==0`, set it, alloc session via `FUN_004ec010(8)` into `+0xbc`, wire host object, `FUN_004b8dc0(0,0)`.
2. Compute fire-allowed `uVar7` from `+0xc7` / `+0xcb` gates.
3. Burst/cooldown counter at `+0xb4` with active flag `+0xb1` (5-tick off sequence).
4. If `param_3 != 0` early return (suppress fire).
5. On fire: set `+0xb1=1`, `FUN_004b8dc0(1,0)`; alloc type-4 message `FUN_004ec010(4)`; pack fields via `FUN_004b7550`:
   - field1: zero
   - field2: `this+0xe8`
   - field3: `(1 - this+0xdc) * 0.5` (`DAT_00a0f298`)
   - field4: `this+0xe0`
6. Dispatch via host vtbl+0xf8; `FUN_004b7e50`; resolve owner TFID via vtbl+0x210 → +0xa4 chain; `FUN_004b68c0` + `FUN_004b75d0`.

### Path B — bit7 set (heat / alternate state)

1. `Weapon_CanFireHeatCheck(this)`.
2. Muzzle/active transition on `+0xc7` vs heat; counter uses threshold **2** (not 5).
3. Edge on `cVar8` vs stored `+0xca`: start/stop effects (`FUN_004ec010(7)`, `FUN_00569cb0`).
4. Walk attachment list `+0x128..+0x12c` (offsets via base); type **4** nodes get `FUN_004b8dc0`.
5. Store `+0xca = cVar8`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0056d160` |
| Raw | `raw/aa_0056d160_FUN_0056d160.md` |
| Callers | `VehicleNet_UnpackGhostVehicle`, `FUN_004f9030`, `FUN_005021d0`, `FUN_0056d520`, `FUN_00814400` |
| Constant | `DAT_00a0f298` = **0.5** |

---

## 3. Signature

```c
uint __thiscall Weapon_FireHelper(void* weapon, undefined4 param_2, char suppressFire /*param_3*/);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Dual path on +0xc4 bit7 | **High** |
| Message build + dispatch on path A | **High** |
| Heat gate + state edge on path B | **High** |
| Exact opcode English for 004ec010(4/7/8) | **Medium** residual |
| Product weapon class name | Open `_Inferred` |

**Verdict:** **accept-with-gaps**
