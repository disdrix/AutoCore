# Review A (reconstruction fidelity): `aa_0055fa40` WorldObj_BindLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fa40` |
| **VA** | `0x0055fa40`–`0x0055fbeb` |
| **Body** | **428 bytes** |
| **Canonical name** | `WorldObj_BindLinks_Inferred` |
| **Prior scaffold** | `FUN_0055fa40` |
| **Review date** | `2026-07-29` (W26-E dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0055fa40_WorldObj_BindLinks_Inferred.md` |
| **System** | world-object / phys bind |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Manager **bind/link** path for a world object:

| Step | Action |
|---|---|
| Gate | `*(obj+0xc) != 0` |
| Prep | `FUN_0062d960` with manager `+0x234` |
| Scale | `*(float*)(*(manager+0xcc)+8) * 0.5f` |
| Pose | `*(obj+0x14)+0x20`; component vtbl+0x18; manager vtbl+4 |
| Attach | simple `FUN_006297e0` if `obj+0x40==0`; else multi-entry `FUN_006caaa0` walk |
| Teardown | `FUN_0055f4c0` |

Used after unbind by `WorldObj_RebindActivate` and by enroll/activate helpers.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x0055fa40` |
| Bytes | `read_memory` prologue 64 B + epilogue `ret 4` |
| Bounds | body `0055fa40`–`0055fbeb` (428 B) |
| Constant | `DAT_00a0f298` = `0x3F000000` = **0.5f** |
| Callers | 5 manager helpers (6 xrefs) |
| Pair context | `A_aa_00560e90_WorldObj_RebindActivate_Inferred` |
| Raw / clean | `aa_0055fa40_*`, `WorldObj_BindLinks_Inferred.cpp` |

**Not performed:** Launcher, runtime, duals of nested attach helpers (`006297e0`/`006caaa0`/`0062d960`).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = manager; stack = object | **Confirmed** | `mov esi,ecx`; `mov ebx,[ebp+8]` |
| `ret 4` | **Confirmed** | `C2 04 00` |
| Gate `obj+0xc` | **Confirmed** | `cmp [ebx+0xc],0` |
| Scale × 0.5f | **Confirmed** | `read_memory` @ `0x00a0f298` |
| Simple vs complex by `obj+0x40` | **Confirmed** | decompile CF |
| Product class English | **Inferred** | structural WorldObj bind |
| Nested attach exact layouts | **Out of scope** | OWN VA only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early gate | Yes |
| Prep + scale + vfuncs | Yes |
| Simple / complex branch | Yes |
| Multi-entry walk + free | Yes |
| FUN_0055f4c0 teardown | Yes |
| ret 4 | Yes |

---

## 5. Gaps / open

1. Product/PDB name.
2. Semantics of `obj+0x40` and manager `+0xcc/+0xd0/+0x138` blocks.
3. Bit-exact geometry of `FUN_006297e0` / `FUN_006caaa0` (not OWN).
4. Runtime differential.

**Verdict:** **accept**
