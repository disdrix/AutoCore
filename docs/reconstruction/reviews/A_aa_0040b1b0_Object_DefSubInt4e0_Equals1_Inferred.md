# Review A (reconstruction fidelity): `aa_0040b1b0` Object_DefSubInt4e0_Equals1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b1b0` |
| **VA** | `0x0040b1b0`–`0x0040b1ca` |
| **Canonical name** | `Object_DefSubInt4e0_Equals1_Inferred` (Ghidra `FUN_0040b1b0`) |
| **Ghidra name** | `FUN_0040b1b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0040b1b0_Object_DefSubInt4e0_Equals1_Inferred.md` |
| **System** | `interaction-activation` / object definition predicate (shared) |
| **Verdict** | **accept-with-gaps** — CF + offsets + bool ABI sealed; product English for `+0x4e0` open |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Leaf **boolean predicate** on an object’s dual-base definition subrecord:

```c
// __fastcall — ECX = object*
// returns AL/EAX low byte: 1 if *(int*)(*(obj_field + 0x3c) + 0x4e0) == 1, else 0
uint8_t __fastcall Object_DefSubInt4e0_Equals1_Inferred(Object *obj);
```

High-level walk (live decompile ≡ entry bytes):

1. `adj = *(*(obj + 4) + 4)` — secondary-table / vb-style adjustor dword.
2. `holder = *(obj + adj + 0xac)` — pointer at dual-base-relative **`+0xac`**.
3. `sub = *(holder + 0x3c)` — definition subrecord pointer.
4. Return `*(int32*)(sub + 0x4e0) == 1` as boolean (`SETE AL`).

No callees, no stores, no globals.

**Role in parents (context only, not owned):**

* `Client_SelectTargetObject_Inferred` (`0x0093e120`): when select target valid and this returns **false**, show first-time tips **4** / maybe **9**.
* `Client_InteractClickPickTarget` (`0x009247b0`): type-`0x12` soft-gather arm gates on this (positive filter with other checks).
* Many other callers (`FUN_00490070`, `FUN_0056c0a0`, …) — shared object/def predicate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_0040b1b0_*`, `FUN_0040b1b0.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x0040b1b0` (2026-07-29) |
| Entry bytes | `read_memory` 32 B @ `0x0040b1b0` |
| Callers | `get_function_callers`: `Client_InteractClickPickTarget`, `FUN_00490070`, `FUN_0056c0a0`, `FUN_005cd3b0`, `FUN_005da0a0`, `FUN_00836410`, `FUN_0090f250`, `FUN_00930fc0`, `FUN_0093e120`, `FUN_00946c00` |
| Callees | none (leaf) |
| Parent dual | `A_aa_0093e120_Client_SelectTargetObject_Inferred` (tip gate); interact dual references type-0x12 arm |

**Not performed:** product name for `+0x4e0`; dual of every caller; runtime; bit-exact; Launcher.

---

## 3. Machine bytes (`read_memory` @ `0x0040b1b0`)

```
8B 41 04             mov  eax, [ecx+4]
8B 50 04             mov  edx, [eax+4]          ; adjustor
8B 84 0A AC 00 00 00 mov  eax, [edx+ecx+0xAC] ; holder*
8B 48 3C             mov  ecx, [eax+0x3C]       ; sub*
83 B9 E0 04 00 00 01 cmp  dword ptr [ecx+0x4E0], 1
0F 94 C0             sete al
C3                   ret
CC…                  int3 pad
```

`CONCAT31` in decompiler is the usual high-garbage + `SETE` bool packing — **effective return is AL 0/1**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` ECX = object | **Confirmed** | `mov eax,[ecx+4]` entry |
| Dual-base walk `*(obj+4)+4` then `+0xac` | **Confirmed** | bytes + decompile |
| Subrecord via `holder+0x3c` | **Confirmed** | `mov ecx,[eax+0x3c]` |
| Compare **int @ +0x4e0 == 1** | **Confirmed** | `cmp dword [ecx+0x4e0],1` / `sete` |
| Leaf (no calls) | **Confirmed** | callees empty; `ret` only |
| Clean ≡ raw ≡ live CF | **Confirmed** | single path |
| Role = shared def/category predicate | **High** | tip gate + type-0x12 + multi-caller |
| Product English for field `+0x4e0` | **Open** | residual |
| Whether `holder` is race-item / clonebase / other | **Probable** | same `+0xac→+0x3c` family as combat-pool getters; not dual-owned |

---

## 5. Control flow checklist

| Stage | Match |
|---|---|
| Load adjustor from `obj+4` chain | **Yes** |
| Load holder at `+0xac` | **Yes** |
| Load sub at `+0x3c` | **Yes** |
| Bool `*(sub+0x4e0)==1` | **Yes** |
| No stores / no side effects | **Yes** |

---

## 6. Gaps

1. Product / PDB name and English meaning of dword `+0x4e0` (category, faction class, “player vehicle”, etc.).
2. Full taxonomy of `holder` at dual-base `+0xac` vs race-item slot patterns.
3. Runtime confirmation on live objects; bit-exact N/A for pure predicate beyond CF.
4. Per-caller semantic tables (OWN-ONLY — residual).

**Verdict:** **accept-with-gaps** — leaf CF, offsets, and bool ABI sealed for ports; field English open.
