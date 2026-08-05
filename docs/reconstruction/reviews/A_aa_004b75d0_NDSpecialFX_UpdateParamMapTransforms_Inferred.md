# Review A (reconstruction fidelity): `aa_004b75d0` NDSpecialFX_UpdateParamMapTransforms_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b75d0` |
| **VA** | `0x004b75d0` |
| **Canonical name (Ghidra)** | `FUN_004b75d0` |
| **Proposed name** | `NDSpecialFX_UpdateParamMapTransforms_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b75d0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b75d0_NDSpecialFX_UpdateParamMapTransforms_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX param map |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**In-order walk** of the FX param map (`this+0x228` header; nodes via tree successor with red-black-ish `+0x15` color byte) and **resolve each entry’s float3** from host/target geometry.

Per entry (`payload = node[4]`):

### Gate (skip → successor only)

Skip compute if **any**:

- `entry+0x20 == 0` (just-set raw from `004b7550`, not ready), **OR**
- `this+0x2c == 0`, **OR**
- `this+0x10 == 0` (no host), **OR**
- (`Object_ResolveFromTFID(this+0x68)` fails **AND** mode ∉ `{0,1,4,5,6}`), **OR**
- host vtbl **`+0x1cc`** returns null / null at `+8` (no transform provider)

### Source frame

- Bone/hardpoint: if `entry+0x24 == -1` → host transform provider `vtbl+0xc` → `FUN_004e9530(…, base+0x90)` (position-ish float4).
- Else `FUN_0096d460(entry+0x24)` lookup → same extract.

### Target delta

- If target TFID resolves: vtbl `+0x144` refresh; read floats at target `+0x80..+0x8c` (indices `[0x20..0x23]`); optional height adjust via target `+0x1cc` → provider `+0x48` Y; **subtract** source frame → delta.
- Else delta = **0**.

### Mode switch (`entry+0x4`)

| Mode | Behavior (summary) |
|---|---|
| **0** | If ‖delta_xyz‖≠0: write world aim `this+0x80 = delta+source`, state=`2`. If zero and state==`2`: reload delta from cached `this+0x80` then subtract source |
| **1** | Direction: on nonzero store aim; on zero with state==`1` use `FUN_004e96e0` orient + `Math_QuatTransformPoint` (`004e8bf0`) on cached aim; **normalize** xyz (and scale w) via `g_flOne/SQRT` |
| **4** | Same zero/nonzero split as 1 for aim cache; then replace vector with **length** `SQRT(x²+y²+z²)` in x (magnitude mode) |
| **5** | Nonzero → same as mode0 store; zero+state1 → transform via **host object** quat at `host+0x90` through `004e8bf0`; write aim; state=`2` |
| **6** | Like 5 but orient from hardpoint `FUN_004e96e0(…, +0x80)` |

After switch: `FUN_004e88e0` (likely normalize/copy helper) → write float3 to `entry+0x14`; **re-scale** by `entry+0x8/+c/+10` (same scales as setter).

Tree successor walk uses standard MSVC map `+0x15` nil-color tests (not gameplay logic).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004b75d0` (full body) |
| Raw / clean | `raw/aa_004b75d0_*`, `reconstructed-exact/FUN_004b75d0.cpp` |
| Callees | `Object_ResolveFromTFID`, `FUN_004e9530`, `FUN_004e96e0`, `FUN_004e8bf0` (QuatTransformPoint), `FUN_004e88e0`, `FUN_0096d460`, `SQRT` |
| Callers | `Weapon_FireHelper` `0056d160`, `FUN_004b8ed0`, `FUN_00518590` |
| Peer duals | `A/B_aa_004e8bf0_Math_QuatTransformPoint_Inferred` (4 call sites from this body) |

**Not performed:** Launcher, runtime, ledgers, full hardpoint-id dictionary.

---

## 3. Signature

```c
void __fastcall NDSpecialFX_UpdateParamMapTransforms_Inferred(void *fx /*ECX*/);
// decompiler also shows __fastcall; no stack args
```

---

## 4. Field map (this / entry)

| Slot | Role | Conf |
|---|---|---|
| `this+0x10` | Host object | High |
| `this+0x2c` | Gate / context ptr | High (null skips) |
| `this+0x68` | Target TFID_16 | High |
| `this+0x80` | Aim / world vector cache float4 | High |
| `this+0x228` | Map end/header | High |
| `entry+0x4` | Mode | High |
| `entry+0x8..+10` | Scales | High |
| `entry+0x14` | Out float3 | High |
| `entry+0x20` | State 0/1/2 | High |
| `entry+0x24` | Bone/hardpoint id (−1 default) | High |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Map inorder walk from `*end` | Yes |
| Multi-clause skip gate | Yes |
| Source frame (−1 vs hardpoint id) | Yes |
| Target resolve + optional Y fix | Yes |
| switch modes 0/1/4/5/6 | Yes (no 2/3 cases) |
| Post scale write to entry | Yes |
| RB-tree successor | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Param-map transform resolver (not physics step) | **High** | FX callers only |
| Mode set {0,1,4,5,6} only | **High** | switch cases |
| Uses target TFID @ `+0x68` + aim cache @ `+0x80` | **High** | pairs with `004b68c0` |
| Depends on host @ `+0x10` | **High** | pairs with `004b73c0` |
| `004e8bf0` = quat×vec+pos | **High** | dual sealed peer |
| English of every mode / bone provider | **Probable** | residual labels |
| Product name | **Tentative** | `_Inferred` |
| `FUN_004e88e0` exact (norm vs copy) | **Probable** | post-process before scale |

---

## 7. Gaps / open

1. Mode 2/3 unused — script schema may reserve them.
2. Full vtbl `+0x1cc` / `+0xc` / `+0x48` / `+0x144` product names.
3. Whether server ever runs this path (all known callers client FX).

**Verdict:** **accept-with-gaps** — CF sealed High for AutoCore client FX port; mode English residual.
