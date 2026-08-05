# Review B (skeptical / adversarial): `Object_GetWorldOrientQuatPtr` / `FUN_00404a20` @ `0x00404a20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404a20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404a20_Object_GetWorldOrientQuatPtr.md` |
| **Verdict** | **accept** on CF/offsets/CC/leaf purity; **needs-more-evidence** only on sealed product symbol and typed `this+4` layout |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function writes pose / mutates entity | **Falsified** — pure loads + `add`/`lea` + `ret`; no stores, no calls |
| 2 | Returns quaternion **by value** (4 floats in regs/stack) | **Falsified** — returns **address**; callers dereference or pass pointer to extractors |
| 3 | Always uses rigid body (`rb+0x30`) | **Falsified if absolute** — only when `this+8 != 0`; else entity `+0x94` path |
| 4 | Fallback is plain `this+0x94` with no adjust | **Falsified** — `lea eax,[edx+ecx+0x94]` where `edx=**(this+4)+4` |
| 5 | `__cdecl` / stack `this` | **Falsified** — ECX-based loads; no `[esp+…]` formals |
| 6 | Decompiler CF wrong vs bytes | **Falsified** — decomp ≡ `read_memory` path |
| 7 | Same as position getter `00404c90` | **Falsified as identity** — twin CF, different addends (`0x30`/`0x94` vs `0xb0`/`0x84`) |
| 8 | Returned slot is world **position** | **Falsified** — RB map + consumers treat `+0x30` as quat; position is twin `+0xb0` |
| 9 | Name must be retail `Object_GetWorldOrientQuatPtr` | **Hold inferred** — no in-body string; role High from RB map + consumers |
| 10 | `this+8` is always Havok chassis | **Overstated if sealed** — pointer at `entity+8` then `+0x3c` → RB is **High** from physics verified chain; this leaf only proves the load chain |
| 11 | Runtime / bit-exact EXE verified | **Open** — static body only |
| 12 | Scaffold alias `Named_CalleeOf_Client_SendRespawnInSector_*` is exclusive owner | **Falsified as exclusive** — many callers (airStab, PushDriveAxes, turret aim, collision, …) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Physics path offsets `*(phys+0x3c)+0x30` | **Confirmed** | Wrong orient slot → basis/airStab/drive axes all rotate wrong |
| Fallback `adj+this+0x94` | **Confirmed** | Unattached entities read wrong memory |
| ECX `this` convention | **Confirmed** | Wrong CC → garbage returns / crash |
| Leaf purity | **Confirmed** | Low |
| Return = **pointer to quaternion** | **High** | Treating as float value breaks all consumers |
| Semantic label “world orientation quat” | **High** | Twin pos at `0xb0`; RB map `+0x30` xyzw; airStab/PushDriveAxes/calcWheelTorque |
| Product C++ name | **Medium / Open** | Docs should keep `FUN_00404a20` or `_Inferred` until symbol |
| `*( *(this+4)+4 )` type recovery | **Medium** | Porting without adjust breaks non-zero base classes |
| Full caller semantic audit | **N/A here** | Own-VA only; callers listed for context |

---

## 3. Surviving contract for AutoCore

```
// ECX = entity / object
ptr = Object_GetWorldOrientQuatPtr(entity):
  if entity.physicsObj != null:          // entity+0x08
      rb = physicsObj.rigidBody          // *(physicsObj + 0x3c)
      return &rb.orientQuat              // rb + 0x30  (4×f32 xyzw)
  else:
      adj = *( *(entity+4) + 4 )         // type/clonebase adjust
      return (byte*)entity + adj + 0x94  // embedded orientation

// NOT a by-value quat. NOT the position getter (00404c90).
// Twin: FUN_00404c90 → rb+0xb0 / entity+0x84 (world position).
```

Port rule: any system needing chassis/entity world orientation should call this helper (or equivalent dual-path), never hardcode only `rb+0x30` without the `entity+8` gate and fallback.

---

## 4. Assembly contract (from `read_memory`)

```
00404a20  8b4108          mov  eax, [ecx+8]
00404a23  85c0            test eax, eax
00404a25  7407            jz   fallback
00404a27  8b403c          mov  eax, [eax+0x3c]
00404a2a  83c030          add  eax, 0x30
00404a2d  c3              ret
fallback:
00404a2e  8b4104          mov  eax, [ecx+4]
00404a31  8b5004          mov  edx, [eax+4]
00404a34  8d840a94000000  lea  eax, [edx+ecx+0x94]
00404a3b  c3              ret
```

Hex: `8b410885c074078b403c83c030c38b41048b50048d840a94000000c3`

Range matches Ghidra function body `00404a20`–`00404a3b`.

---

## 5. Falsification notes on over-claims

### 5.1 “Always rb+0x30”

Physics notes sometimes shorthand “returns `rb+0x30`.” Accurate **only** on the attached path. Fallback path never touches `+0x3c`. Ports that omit the gate will fault or read stale RB when `entity+8==0`.

### 5.2 Confusing with position twin

`FUN_00404c90` is the **position** pointer (`rb+0xb0` / `+0x84`). Same structure, different constants. Do not merge plates or swap addends in ports.

### 5.3 Respawn-only naming

Scaffold human name `Named_CalleeOf_Client_SendRespawnInSector_00404a20` is a **parent-seed alias**, not ownership. Prefer role name + VA.

### 5.4 “Basis matrix” vs “quaternion”

`rb+0x30` is the **quaternion** slot; the 3×3 world matrix lives at `rb+0x80..` (separate). Consumers often convert quat → basis via `FUN_004e8b60` / `FUN_004e8a40`. This leaf does not return the matrix.

### 5.5 Encoding vs twin not “different algorithm”

`add eax,0x30` (`83 c0 30`) vs twin `add eax,0xb0` (`05 b0 00 00 00`) is only an imm8 vs imm32 encoding choice for the constant; control flow is isomorphic.

---

## 6. Open questions

1. Retail / PDB name for `0x00404a20`.
2. Exact C++ type of object at `this+4` and meaning of dword at `+4` (adjustor magnitude units: bytes — confirmed by `lea` usage).
3. Whether any caller assumes return non-null without null-checking `this` (leaf does not null-check `this` itself).
4. Whether fallback `+0x94` is always a full 4-float quat vs a different orient packing on non-physics objects (consumers treat as quat; product type open).

**Verdict:** **accept** on sealed CF, offsets, ECX convention, leaf purity, and orientation-pointer role. Reject exclusive Respawn ownership, by-value / always-RB overclaims, and identity with the position twin. Product symbol remains open.
