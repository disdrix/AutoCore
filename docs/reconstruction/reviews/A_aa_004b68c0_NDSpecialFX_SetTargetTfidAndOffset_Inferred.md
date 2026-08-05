# Review A (reconstruction fidelity): `aa_004b68c0` NDSpecialFX_SetTargetTfidAndOffset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b68c0` |
| **VA** | `0x004b68c0` |
| **Canonical name (Ghidra)** | `FUN_004b68c0` |
| **Proposed name** | `NDSpecialFX_SetTargetTfidAndOffset_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_004b68c0` — chain-of-callers only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b68c0_NDSpecialFX_SetTargetTfidAndOffset_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX param host |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf thiscall store** on an NDSpecialFX-sized host object (~`0x240`): write a **16-byte TFID** into `this+0x68..+0x74` and a **float4** (world/aim offset or base vector) into `this+0x80..+0x8c`.

```
this+0x68 = tfid.d0..d3   // 4×u32 TFID_16
this+0x80 = offset.xyzw   // 4×f32 from *param_6
```

No branches, no callees. Companion of `FUN_004b75d0` (param-map transform update) which **reads** the same slots as target TFID and cached aim vector.

**Not** a network send, physics impulse, or map insert — pure field pack.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004b68c0` |
| Raw | `docs/reconstruction/raw/aa_004b68c0_FUN_004b68c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b68c0_FUN_004b68c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b68c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b68c0_FUN_004b68c0.md` |
| Constants | `read_memory` `DAT_00b047c0` @ `0x00b047c0` → **16 zero bytes** (caller default offset) |

**This pass:** live decompile; xrefs; FireHelper / weapon-pack call-site decompiles. **Not performed:** Launcher, runtime, bit-exact image diff, ledger updates.

---

## 3. Signature

```c
// thiscall; leaf; ret (no ret N)
void __thiscall NDSpecialFX_SetTargetTfidAndOffset_Inferred(
    void *fx,          // ECX — NDSpecialFX-like host
    uint32_t tfid0,    // Stack[0x4]
    uint32_t tfid1,    // Stack[0x8]
    uint32_t tfid2,    // Stack[0xc]
    uint32_t tfid3,    // Stack[0x10]
    float *offset4);   // Stack[0x14] — 4 floats copied
```

Storage from `analyze_function_complete`: `param_1` = ECX; stack layout matches four dwords + pointer.

---

## 4. Callers (3)

| Caller | VA | Role |
|---|---|---|
| `Weapon_FireHelper_Inferred` | `0x0056d160` / call @ `0056d503` | After type-4 FX alloc + param pack; TFID from owner entity `+0x160..+0x16c`; offset `&DAT_00b047c0` (zeros) |
| `FUN_0056a9e0` | `0x0056a9e0` / call @ `0056aabc` | Weapon/FX packet path; TFID from `param_4+0x160` or sentinel `DAT_009d2f68`; offset local zeros |
| `FUN_00512d10` | `0x00512d10` / call @ `00512e12` | Additional consumer (same field pack) |

Immediately after FireHelper: `FUN_004b75d0()` recomputes param-map vectors using the TFID/offset just written.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Store 4 dwords → `+0x68..+0x74` | Yes |
| Store 4 floats from `*param_6` → `+0x80..+0x8c` | Yes |
| Return | Yes |

Leaf; no SEH; no branches.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf thiscall field pack | **High** | decompile + zero callees |
| `+0x68` = TFID_16 (4 dwords) | **High** | FireHelper copies entity `+0x160` TFID block; `Object_ResolveFromTFID((TFID_16*)(this+0x68))` in `004b75d0` |
| `+0x80` = float4 aim/base offset | **High** | written as 4 floats; consumed as position/delta base in `004b75d0` cases 0/1/4/5/6 |
| Default offset often zero (`DAT_00b047c0`) | **Confirmed** | `read_memory` all zeros |
| Class is NDSpecialFX-like (`+0x224` map sibling methods) | **High** | sibling `004b7550` map @ `+0x224`; object size peer `0x240` from FX parse |
| Product / mangled name | **Tentative** | no body string → keep `_Inferred` |
| Exact semantic of float4 (world pos vs local offset) | **Probable** | callers pass zeros; `004b75d0` treats `+0x80` as writable aim cache |

---

## 7. Gaps / open

1. Product C++ symbol (plate/RTTI absent on body).
2. Whether any caller passes a non-zero float4 as a deliberate world aim point vs pure zero baseline.
3. Full English of `FUN_00512d10` caller path (not required for CF seal).

**Verdict:** **accept-with-gaps** — CF and field layout sealed High; naming remains `_Inferred`.
