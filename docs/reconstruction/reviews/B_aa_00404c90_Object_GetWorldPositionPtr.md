# Review B (skeptical / adversarial): `Object_GetWorldPositionPtr` / `FUN_00404c90` @ `0x00404c90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404c90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404c90_Object_GetWorldPositionPtr.md` |
| **Verdict** | **accept** on CF/offsets/CC/leaf purity; **needs-more-evidence** only on sealed product symbol and typed `this+4` layout |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function writes pose / mutates entity | **Falsified** — pure loads + `add`/`lea` + `ret`; no stores, no calls |
| 2 | Returns position **by value** (3 floats in regs/stack) | **Falsified** — returns **address**; callers dereference (`*(ret+0/4/8)`) |
| 3 | Always uses rigid body (`rb+0xb0`) | **Falsified if absolute** — only when `this+8 != 0`; else entity `+0x84` path |
| 4 | Fallback is plain `this+0x84` with no adjust | **Falsified** — `lea eax,[edx+ecx+0x84]` where `edx=**(this+4)+4` |
| 5 | `__cdecl` / stack `this` | **Falsified** — ECX-based loads; no `[esp+…]` formals |
| 6 | Decompiler CF wrong vs bytes | **Falsified** — decomp ≡ `read_memory` path |
| 7 | Same as quat getter `00404a20` | **Falsified as identity** — twin CF, different addends (`0xb0`/`0x84` vs `0x30`/`0x94`) |
| 8 | Name must be retail `Object_GetWorldPositionPtr` | **Hold inferred** — no in-body string; role High from RB map + consumers |
| 9 | `this+8` is always Havok chassis | **Overstated if sealed** — pointer at `entity+8` then `+0x3c` → RB is **High** from physics verified chain; this leaf only proves the load chain |
| 10 | Runtime / bit-exact EXE verified | **Open** — static body only |
| 11 | Scaffold alias `Named_CalleeOf_Client_RecvBroadcast_*` is exclusive owner | **Falsified as exclusive** — 60+ callers; RecvBroadcast is one parent seed only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Physics path offsets `*(phys+0x3c)+0xb0` | **Confirmed** | Wrong pose slot → aim/airStab/drive range all shift |
| Fallback `adj+this+0x84` | **Confirmed** | Unattached entities read wrong memory |
| ECX `this` convention | **Confirmed** | Wrong CC → garbage returns / crash |
| Leaf purity | **Confirmed** | Low |
| Return = **pointer to position** | **High** | Treating as float value breaks all consumers |
| Semantic label “world position” | **High** | Twin quat at `0x30`; RB map `+0xb0` XYZ; airStab/DCT usage |
| Product C++ name | **Medium / Open** | Docs should keep `FUN_00404c90` or `_Inferred` until symbol |
| `*( *(this+4)+4 )` type recovery | **Medium** | Porting without adjust breaks non-zero base classes |
| Full caller semantic audit | **N/A here** | Own-VA only; callers listed for context |

---

## 3. Surviving contract for AutoCore

```
// ECX = entity / object
ptr = Object_GetWorldPositionPtr(entity):
  if entity.physicsObj != null:          // entity+0x08
      rb = physicsObj.rigidBody          // *(physicsObj + 0x3c)
      return &rb.worldPos                // rb + 0xB0
  else:
      adj = *( *(entity+4) + 4 )         // type/clonebase adjust
      return (byte*)entity + adj + 0x84  // embedded pose

// NOT a by-value vec3. NOT the quat getter (00404a20).
// Twin: FUN_00404a20 → rb+0x30 / entity+0x94 (orientation).
```

Port rule: any system needing chassis/entity world XYZ should call this helper (or equivalent dual-path), never hardcode only `rb+0xb0` without the `entity+8` gate and fallback.

---

## 4. Assembly contract (from `read_memory`)

```
00404c90  8b4108          mov  eax, [ecx+8]
00404c93  85c0            test eax, eax
00404c95  7409            jz   fallback
00404c97  8b403c          mov  eax, [eax+0x3c]
00404c9a  05b0000000      add  eax, 0xb0
00404c9f  c3              ret
fallback:
00404ca0  8b4104          mov  eax, [ecx+4]
00404ca3  8b5004          mov  edx, [eax+4]
00404ca6  8d840a84000000  lea  eax, [edx+ecx+0x84]
00404cad  c3              ret
```

Hex: `8b410885c074098b403c05b0000000c38b41048b50048d840a84000000c3`

Range matches Ghidra function body `00404c90`–`00404cad`.

---

## 5. Falsification notes on over-claims

### 5.1 “Always rb+0xb0”

Physics notes sometimes shorthand “returns `rb+0xb0`.” Accurate **only** on the attached path. Fallback path never touches `+0x3c`. Ports that omit the gate will fault or read stale RB when `entity+8==0`.

### 5.2 RecvBroadcast-only naming

Scaffold human name `Named_CalleeOf_Client_RecvBroadcast_00404c90` is a **parent-seed alias**, not ownership. DriveControlTick, airStab, AI pursue, cast aim, respawn pack, etc. all call this leaf. Prefer role name + VA.

### 5.3 Confusing with `FUN_00404cb0`

Sibling VA `0x00404cb0` is a **different** function (thiscall with vtbl dispatch / side effects). Do not merge plates.

---

## 6. Open questions

1. Retail / PDB name for `0x00404c90`.
2. Exact C++ type of object at `this+4` and meaning of dword at `+4` (adjustor magnitude units: bytes — confirmed by `lea` usage).
3. Guaranteed width of returned pose (3 vs 4 floats) for every consumer — RB documents 4-float slot; some callers only read XYZ.
4. Whether any caller assumes return non-null without null-checking `this` (leaf does not null-check `this` itself).

**Verdict:** **accept** on sealed CF, offsets, ECX convention, leaf purity, and position-pointer role. Reject exclusive RecvBroadcast ownership and by-value / always-RB overclaims. Product symbol remains open.
