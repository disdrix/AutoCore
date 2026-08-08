# Review A (reconstruction fidelity): `aa_004082f0` StdVector_InsertN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004082f0` |
| **VA** | `0x004082f0` |
| **Body** | `0x004082f0`–`0x00408587` (**663 B** / `0x297`) |
| **Canonical name** | `StdVector_InsertN_Elem12_Inferred` |
| **Ghidra name** | `FUN_004082f0` |
| **Prior scaffold** | `FUN_004082f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9H-B**) |
| **Counterpart** | `reviews/B_aa_004082f0_StdVector_InsertN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` InsertN, POD **elem 0xC**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **vector insert-n** for **12-byte POD** elements. Inserts `count` copies of `*value` at iterator `where`, growing with **1.5×** policy when capacity is insufficient. Generic infrastructure used by InsertOne rebind `FUN_00406e70` (count forced to 1) on the push_back slow path of `FUN_004062a0`. **Not** domain logic.

Twin of InsertN dword (`004073a0`) and InsertN elem0x28 (`00408050`) with stride/ABI differences.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `VecPod12*` this (+4 begin, +8 end, +0xC capEnd) |
| stack0 | `Pod12*` where |
| stack1 | `uint` count |
| stack2 | `const Pod12*` value (3 dwords snapped to stack locals) |
| return | void; **`ret 0xC`** |

```c
void __thiscall StdVector_InsertN_Elem12(
    VecPod12 *this, Pod12 *where, uint count, const Pod12 *value);
```

Parent `00406e70` bytes: `mov ecx,edi; push value; push 1; push where; call 004082f0`.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x004082f0` (2026-08-04) ≡ raw scaffold CF |
| Bytes | `read_memory` 256+ B — SEH, `mov ebx,ecx`, magic `/12`, `0x15555555`, grow, **`C2 0C 00`** |
| Bounds | `get_function_by_address` body `004082f0`–`00408587` |
| Callers | `get_function_callers` → `FUN_00406e70` only (1 xref) |
| Callees | uninit_copy / Ufill `00406ee0` / copy_backward / assign-fill / size / overflow / new/delete |
| Wrapper dual | WQ9G-I sealed `aa_00406e70` InsertOne |
| Ufill dual | WQ9G-I sealed `aa_00406ee0` |
| Twin reviews | `A_aa_004073a0_StdVector_InsertN_Dword_Inferred` pattern |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Snap 3 dwords of `*value` | **Yes** |
| cap = (capEnd-begin)/12; size = (end-begin)/12 | **Yes** |
| count==0 early return | **Yes** |
| max-size check → `FUN_00418130` | **Yes** (`0x15555555`) |
| Grow if cap < size+count: 1.5× then size+count | **Yes** |
| Realloc: new → prefix uninit_copy → Ufill → suffix → delete → triad | **Yes** |
| In-place: tail<count vs else (copy_backward) | **Yes** |
| assign-fill `FUN_0042ac90` on in-place | **Yes** |
| `ret 0xC` | **Yes** |
| No domain / packet logic | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live | **Confirmed** | CF spine identical |
| thiscall + ret 0xC | **Confirmed** | bytes + parent |
| Triad + stride **0xC** | **Confirmed** | `/0xc`, magic `0x2AAAAAAB` |
| Growth 1.5× + exact floor | **Confirmed** | decompile + bytes |
| Three-way relocate on grow | **Confirmed** | callees dualed/roles sealed |
| In-place dual sub-cases | **Confirmed** (CF) | helper formal packing High not Confirmed runtime |
| Sole caller InsertOne | **Confirmed** | 1 xref |
| Product English | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Exact MSVC demangled name / 12-byte element English type.
2. Full dual of uninit_copy / copy_backward / assign-fill leaves (roles sealed).
3. Bit-exact / runtime / image diff.
4. Decompiler warning on `operator_delete` "does not return" is a decomp artifact — normal free path continues to triad write in raw.

**Verdict:** **accept-with-gaps**
