# Review A (reconstruction fidelity): `aa_004bb070` Object_ResolveTfIdGetIdentity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb070` |
| **VA** | `0x004bb070` |
| **Canonical name (Ghidra)** | `FUN_004bb070` |
| **Proposed name** | `Object_ResolveTfIdGetIdentity_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Client_RecvNpcMissionDialog_004bb070` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004bb070_Object_ResolveTfIdGetIdentity_Inferred.md` |
| **System** | `combat` / object resolve (type-0x12 transform climb) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a compact TFID/target blob to an object, then return the result of `vtbl+0x1d8()` (identity / parent interface — Probable).**

Body (entire function):

1. `obj = CVOGReaction_ResolveObjectTarget(blob[2] byte, blob[0], blob[1])`.
2. If null → return 0.
3. Else → return `obj->vtbl[+0x1d8]()`.

### Combat nested use

In `Client_Combat_ApplyMultiTargetHits_Inferred` (`0x004da2e0`) and sibling single-hit `0x004d7e30`, type-**0x12** attacker climb:

* Call current `vtbl+0x1d8`, read TFID dwords at result `+0x228..+0x234`.
* Pass that stack blob here.
* Adjust returned COM-style object: `*(obj+4)+4 + obj` → next parent in climb.
* Stop when type is no longer 0x12; type **0x14** uses `+0x160` transform, else fallback.

Also called from mission dialog / other resolve sites (`00815070`, `004ca910`, …).

**Not** full multi-hit apply, not `Object_ResolveFromTFID` alone (that is `0x004bb950`), not vtbl gate `+0x198`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004bb070` |
| Callers | `get_function_callers` → `004da2e0`, `004d7e30`, `00815070`, `004ca910`, `005c67b0`, `006508d0` |
| Parent duals | `A_aa_004da2e0_*`, `A_aa_004d78e0_*` (climb context) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004bb070` |
| Function record | `docs/reconstruction/functions/aa_004bb070_FUN_004bb070.md` |

**This pass:** live decompile; callers; multi-hit climb cross-check. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// cdecl/stdcall as decompiled — blob points at TFID-like triple
void *Object_ResolveTfIdGetIdentity_Inferred(
    undefined4 *blob);  // [0],[1] ids; byte at +8 (param_1+2 as byte*)
// returns: vtbl+0x1d8() result, or 0 if ResolveObjectTarget fails
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `CVOGReaction_ResolveObjectTarget` | Resolve object from blob |
| `vtbl+0x1d8` | Identity / interface getter on resolved object |

| Caller | Role |
|---|---|
| `0x004da2e0` | Multi-target deferred transform climb (type 0x12) |
| `0x004d7e30` | Single-hit deferred transform climb |
| `0x00815070` | `Client_RecvNpcMissionDialog` |
| others | Non-combat resolve |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ResolveObjectTarget three-arg | Yes |
| Null → 0 | Yes |
| Else vtbl+0x1d8 return | Yes |
| No other branches | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin resolve + virtual get | **High** | 3-line body |
| Used in type-0x12 combat transform climb | **High** | parent duals + live callers |
| `vtbl+0x1d8` = identity/parent interface | **Probable** | callers adjust COM + read TFID @+0x228 |
| Product function name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Retail name of `vtbl+0x1d8` and exact blob layout vs full `TFID_16`.
2. Full RTTI of returned object without caller adjust.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF High; identity vtbl product name open.
