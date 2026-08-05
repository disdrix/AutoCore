# Review A (reconstruction fidelity): `aa_00490070` Client_Interact_SelectBestPickTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_00490070` |
| **VA** | `0x00490070` |
| **Canonical name** | `Client_Interact_SelectBestPickTarget` |
| **Prior names** | `FUN_00490070`, `Named_CalleeOf_Client_InteractClickPickTarget_00490070` |
| **Review date** | `2026-07-29` (dual A/B seal; supersedes 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00490070_Client_Interact_SelectBestPickTarget.md` |
| **Residual scratch** | `reviews/a_00490070.md` |
| **System** | `interaction-activation` |
| **Dual status** | **Present** (A + B + residual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Primary pick resolver** used by `Client_InteractClickPickTarget` when resolving the world object under the click/ray path:

1. Require client gfx views `+0xC0` and `+0xBC` non-null.
2. Unproject `param_2` screen coords via `FUN_0075c340` into stack ray buffers.
3. Enumerate objects **twice** (`FUN_004bae00`, flag low-byte **0 then 1**).
4. Gate each object (flag bit6 @ dword index `0x5F`, interact blob `vtbl+0x1CC`, distance probe `vtbl+0x78(5,…)`).
5. Assign **priority byte** from def flags `@+0x3F2` and **clone type** at `*(obj[0x2A]+0x38)`.
6. Keep candidate with **higher priority**; on equal priority keep **smaller distance** (`fStack_3c`).
7. Return best `object*` (may be retargeted to parent `obj[0x2B]` for type 10-family) or `NULL`.

**Does not** call SendUseObject / IfInteractable — parent hub does.

**Calling convention:** `__thiscall` — Client* in `ECX` (entry `mov edi,ecx`).

| Slot | Role | Evidence |
|------|------|----------|
| `this` | Client* | `mov edi,ecx`; loads `+0xC0/+0xBC/+0xB8` |
| stack0 | screen XY* | → `FUN_0075c340` |
| stack1 | unused | **no body use** (raw/live) |
| stack2 | `char filterSelfOwned` | types 0xE/0x12/0x14 ownership skip when 0 |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00490070_FUN_00490070.md` |
| Annotated | `docs/reconstruction/raw/aa_00490070_FUN_00490070.annotated.md` |
| Clean refined | `docs/reconstruction/reconstructed-exact/Client_Interact_SelectBestPickTarget.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00490070.cpp` |
| Function record | `docs/reconstruction/functions/aa_00490070_Client_Interact_SelectBestPickTarget.md` |
| Residual | `docs/reconstruction/reviews/a_00490070.md` |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x00490070` (2026-07-29) ≡ raw CF |
| Memory | `read_memory` entry 48 B; `DAT_00aaa630` → `FF FF 7F 7F` FLT_MAX |
| Parent dual | `aa_009247b0` Client_InteractClickPickTarget |
| Callee duals | `aa_0075c340` unproject; `aa_00524520` / `aa_005245d0` objective ids; `aa_0040b1b0` |

**Not performed:** `disassemble_bytes`, Launcher, live click capture, bit-exact diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Views null → NULL | **Yes** (entry bytes) |
| Unproject call | **Yes** |
| Init bestDist/cand = DAT_00aaa630 | **Yes** / **Confirmed** FLT_MAX |
| `local_5c = 2` two passes | **Yes** |
| Flag toggle `0↔1` after pass | **Yes** |
| Gate bit6 / blob / dist vfunc | **Yes** |
| Flag pri 0x50 / 0x46 | **Yes** |
| Switch clone type full cases | **Yes** |
| Types 1/3 mission 00524520 then 005245d0 | **Yes** (live names ForInteract / ForPick) |
| Type 10-family parent retarget | **Yes** |
| Self-owned filter on 0xE/12/14 | **Yes** |
| Type 0x12 creature cast + vtbl+0x198 / 0040b1b0 | **Yes** |
| Skip 0x1E/0x36/0x38 | **Yes** |
| Max pri then min dist | **Yes** |
| Return best / NULL | **Yes** |
| No UseObject send | **Yes** |

### 3.1 Selection rule (SEALED)

```
if newPri > bestPri: best = obj; bestPri = newPri; bestDist = dist
else if newPri == bestPri && dist < bestDist: best = obj; bestDist = dist
// after each candidate restore running bestPri into local for next compare
```

### 3.2 Constants (SEALED)

| Symbol | Value | Role |
|--------|------:|------|
| `DAT_00aaa630` | **FLT_MAX** (`7F7FFFFF`) | initial / reset distance |
| pri bytes | 0x14,0x28,0x32,0x3C,0x46,0x50,0x5A,0x64 | score ladder |

---

## 4. Offsets (body-backed)

| Offset | Role | Confidence |
|--------|------|------------|
| client `+0xC0`, `+0xBC` | gfx views (null gate) | **High** |
| client `+0xB8` | world / session → `+0xE8A0` local character | **High** |
| obj dword `0x5F` bit6 | candidate eligible flag | **High** |
| obj `vtbl+0x1CC` | interact/query blob | **High** |
| blob `+8`, `+0xE` | probe object / enable | **High** |
| blob→obj `vtbl+0x78(5,…)` | distance fill → `fStack_3c` | **High** |
| `obj[0x2A]+0x38` | clone type | **High** |
| `obj[0x2A]+0x3C` → `+0x3F2` | def flags short | **High** |
| `obj[0x2B]` | parent retarget (type 10 family) | **High** |
| obj dwords 10..0xF | owner TFID-like pairs | **Probable** |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Primary pick for InteractClickPickTarget | **High** (caller dual) |
| Canonical `Client_Interact_SelectBestPickTarget` | **Probable** |
| Priority as “click priority” product term | **Tentative** |
| Clone type numbers = product enums | **Probable** (shared with parent switch) |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / Client this | **High** |
| Control flow / switch | **High** (live ≡ raw) |
| Score rule + pri constants | **High / Sealed** |
| FLT_MAX init | **Confirmed** |
| Two-pass enum | **High** |
| Mission callees 524520/5245d0 | **High** (named duals) |
| Enumerator host ECX for 004bae00 | **Tentative** |
| Unproject which view pointer | **Probable** |
| Runtime pick capture | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

1. Exact `FUN_004bae00` host object / list semantics (flag 0 vs 1).
2. Unproject `this` binding (which of `+0xC0`/`+0xBC`).
3. Product English for every clone type and flag bit.
4. ECX into `00524520`/`005245d0` at this site (parent dual seals global character elsewhere).
5. Runtime: which object wins multi-overlap clicks.

**Verdict:** accept-with-gaps. Score ladder, two-pass walk, and FLT_MAX selection sealed; enumerator host residual.
