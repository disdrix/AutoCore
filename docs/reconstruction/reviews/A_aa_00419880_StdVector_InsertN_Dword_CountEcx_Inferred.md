# Review A (reconstruction fidelity): `aa_00419880` StdVector_InsertN_Dword_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419880` |
| **VA** | `0x00419880` |
| **Body** | `0x00419880`–`0x00419ac4` (0x245 bytes) |
| **Canonical name** | `StdVector_InsertN_Dword_CountEcx_Inferred` |
| **Prior scaffold** | `FUN_00419880` |
| **Review date** | `2026-07-29` (W23-D dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00419880_StdVector_InsertN_Dword_CountEcx_Inferred.md` |
| **System** | util / container (generic) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Generic MSVC-style **vector insert-n** for **4-byte** elements: insert `count` copies of `*value` at `where`, growing with 1.5× policy when capacity is insufficient. Twin of sealed `StdVector_InsertN_Dword_Inferred` (`0x004073a0`) with a **different ABI** (count in ECX).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00419880` |
| Bytes | `read_memory` SEH prolog, max-size `0x3fffffff`, ThrowTooLong call, `ret 0x0C` |
| Bounds | body `00419880`–`00419ac4` |
| Callees | `0040c7c0`, `00418130`, `004651d0`, memmove, new/delete |
| Callers | `00418690` resize + mission/UI multi-site list |
| Twin | sealed review `A_aa_004073a0_StdVector_InsertN_Dword_Inferred` |
| Raw / clean | `aa_00419880_*` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live | **High** | CF identical |
| ECX = count | **Confirmed** | `mov esi,ecx` |
| Stack vec/where/value | **Confirmed** | `[ebp+8/0xC/0x10]`; `ret 0x0C` |
| Triad +4/+8/+0xC stride 4 | **Confirmed** | `>>2` / `*4` |
| Max elems 0x3fffffff | **Confirmed** | `bb ff ff ff 3f` |
| ThrowTooLong | **Confirmed** | rel32 → `00418130` |
| 1.5× growth | **Confirmed** | `cap + (cap>>1)` |
| Twin ABI ≠ `004073a0` | **Confirmed** | thiscall-on-vector vs count-in-ECX |
| Product demangle | **Inferred** | keep `_Inferred` |
| Domain-specific | **Falsified** | multi-caller generic |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| count==0 early-out | Yes |
| overflow throw | Yes |
| grow 1.5× / exact floor | Yes |
| in-place arms | Yes |
| no domain logic | Yes |

---

## 5. Gaps / open

1. Exact MSVC demangled name / template args.
2. Full caller taxonomy.
3. Precise helper ABI of `FUN_0040c7c0` / `FUN_004651d0` (out of owned scope detail).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
