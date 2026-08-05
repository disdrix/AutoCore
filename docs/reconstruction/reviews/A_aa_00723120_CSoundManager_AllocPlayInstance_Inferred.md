# Review A (reconstruction fidelity): `aa_00723120` CSoundManager_AllocPlayInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723120` |
| **VA** | `0x00723120` |
| **Canonical name** | `CSoundManager_AllocPlayInstance_Inferred` |
| **Ghidra symbol** | `FUN_00723120` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00723120_CSoundManager_AllocPlayInstance_Inferred.md` |
| **System** | client audio / `CSoundManager` / SpecialFX play |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate a 0x150-byte play instance**, construct it from FX-entry / attach parameters, and **push it into a pending list**.

Authoritative behavior (live decompile ≡ raw):

1. `pv = operator_new(0x150)`.
2. If `pv != null`: call **`FUN_0071e570(...)`** with subset of stack args (name + TFID/pos/type fields). Decompiler shows ctor consuming **`EAX = new object`** (`in_EAX` in `FUN_0071e570`) — classic MSVC `new`→ctor handoff; clean plate omits explicit `this` pass.
3. **`FUN_004406e0()`** — vector push of the new pointer (grows/pushes into list; decompiler uses `in_EAX` list + `unaff_ESI` element).
4. Return void.

**Caller context:** `FUN_004b7e50` (SpecialFX host play walk) invokes this on the **`entry+0x10C != 0`** alternate path after minting attach TFID / params from the FX entry (`pbVar16`) and position. Paired in that unit with proximity path `FUN_007258a0` and UI path `Client_PlayNamedInterfaceSound`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00723120_FUN_00723120.md` | ≡ live CF |
| Annotated | `docs/reconstruction/raw/aa_00723120_FUN_00723120.annotated.md` | ≡ raw |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00723120.cpp` | CF ≡ raw (this-pointer elision) |
| Function record | `docs/reconstruction/functions/aa_00723120_FUN_00723120.md` | scaffold |
| Live decompile | Ghidra `0x00723120`, `0x0071e570`, `0x004406e0` | sealed roles |
| Parent dual | `A_aa_004b7e50` | alternate play helper |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Alloc size **0x150** | **High** | `operator_new(0x150)` |
| Null new → still calls push helper | **High** | if only wraps ctor; push always runs |
| Ctor = `FUN_0071e570` fills name at +0x20-ish, TFID block, type floats | **High** | ctor body stores `param_2..` into `in_EAX[4..7]`, `0x4a..0x4e`, copies C-string |
| Push = `FUN_004406e0` vector insert | **High** | grow-or-append dword |
| Called as alternate play from FX host | **High** | `004b7e50` when `entry+0x10C` |
| Exact arg order / which stack slots map to TFID vs pos | **Medium** | parent decompile has many stack remaps |
| Product English name | **Probable** | inferred |
| Whether push target is manager queue vs global | **Medium** | reg-recovered; not dual-sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `new(0x150)` | Yes |
| if non-null → ctor `FUN_0071e570` | Yes |
| always `FUN_004406e0` push | Yes |
| void return | Yes |

```text
AllocPlayInstance(name, tfid..., pos..., type...):
  inst = new (0x150)
  if inst: FUN_0071e570(inst, ...)   // EAX this
  VectorPush(pending, inst)          // FUN_004406e0
```

---

## 5. Callers / callees

**Callees:** `operator_new`, `FUN_0071e570` (ctor), `FUN_004406e0` (vector push).

**Callers:** `FUN_004b7e50` (primary SpecialFX play path).

---

## 6. Gaps / open

1. Exact stack ABI matrix vs `004b7e50` call site (10 `undefined4` params in Ghidra — likely packing TFID + vec + type).
2. Dual for `FUN_0071e570` / `FUN_004406e0` residual.
3. What drains the pending vector (tick / mixer).
4. Null-new still pushing null — crash surface vs retail filter.
5. Runtime not run.

**Verdict:** **accept-with-gaps** — alloc size, ctor, push, and FX-host role sealed; full arg semantics residual.
