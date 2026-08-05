# Review A (reconstruction fidelity): `aa_00513b00` Object_CopyReactionOrLocalTransform4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513b00` |
| **VA** | `0x00513b00` |
| **Canonical name (Ghidra)** | `FUN_00513b00` |
| **Proposed name** | `Object_CopyReactionOrLocalTransform4_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | (none) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_00513b00_Object_CopyReactionOrLocalTransform4_Inferred.md` |
| **System** | `combat` / reaction transform pack |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Copy four dwords of transform/orientation into a caller-supplied out buffer**, preferring reaction-linked sources over local `obj+0x160`.

Priority (High CF):

1. If `obj->vtbl+0x210(0) != 0`: treat result as COM-adjusted object; copy **four dwords at `result+0x164`** (after `*(result+4)+4` base adjust).
2. Else if `obj->vtbl+0x214() != 0`: same pattern — four dwords at adjusted `+0x164`.
3. Else: copy `obj[0x58..0x5b]` i.e. **local transform at `+0x160`**.

### Combat nested use

Sole non-ctor live combat caller: `Client_Combat_ApplyHit_Inferred` (`0x004d78e0`) reaction branch (`vtbl+0x214` list + `vtbl+0x88` notify) packs reaction args via this helper. Also referenced from `CVOGHBSkillBase_ctor` (`0x005788d0`) — likely template/default init path (**Probable**).

**Decompiler noise (High):** `unaff_ESI` / `unaff_retaddr` are the **out pointer** (ABI not fully recovered); both branches write four dwords to that destination.

**Not** phys impulse (`0058c3b0`), not hit apply, not multi-target walk.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00513b00` |
| Callers | `get_function_callers` → `004d78e0`, `005788d0` |
| Parent dual | `A_aa_004d78e0_Client_Combat_ApplyHit_Inferred` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00513b00` |
| Function record | `docs/reconstruction/functions/aa_00513b00_FUN_00513b00.md` |

**This pass:** live decompile; callers; parent dual. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall/fastcall — ECX = object*; out* not fully typed in decompiler
void __fastcall Object_CopyReactionOrLocalTransform4_Inferred(
    int *obj /*, float out[4] via hidden/stack ABI */);
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `vtbl+0x210(0)` | Preferred reaction/component source |
| `vtbl+0x214()` | Secondary reaction source |
| (none other) | Local `+0x160` fallback is inline |

| Caller | Role |
|---|---|
| `0x004d78e0` | Hit reaction notify pack |
| `0x005788d0` | `CVOGHBSkillBase_ctor` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `+0x210` then `+0x214` then local | Yes |
| Four-dword copy each arm | Yes |
| COM base adjust `*(+4)+4` | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Transform4 prefer reaction then local | **High** | three-arm CF |
| Local source `+0x160` | **High** | indices 0x58–0x5b |
| Nested of apply-hit reaction path | **High** | sole combat caller |
| Exact out ABI (ESI vs stack) | **Tentative** | decompiler unaff |
| Product name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Formal calling convention for out pointer.
2. Product names of `vtbl+0x210` / `+0x214`.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — priority CF High; out ABI noisy.
