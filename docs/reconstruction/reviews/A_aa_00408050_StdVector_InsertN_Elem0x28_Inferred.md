# Review A (reconstruction fidelity): `aa_00408050` StdVector_InsertN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408050` |
| **VA** | `0x00408050` |
| **Body** | `0x00408050`–`0x004082ed` exclusive (**669 B** / `0x29D`) |
| **Canonical name** | `StdVector_InsertN_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00408050` |
| **Prior scaffold** | `FUN_00408050` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9H-A**) |
| **Counterpart** | `reviews/B_aa_00408050_StdVector_InsertN_Elem0x28_Inferred.md` |
| **System** | util / container (`std::vector` InsertN, POD **elem 0x28**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **vector insert-n** for **0x28-byte POD** elements. Inserts `count` copies of `*value` at iterator `where`, growing with **1.5×** policy when capacity is insufficient. Generic infrastructure used by InsertOne rebind `FUN_00406de0` (count forced to 1) on the push_back slow path of `FUN_00406220`. **Not** domain logic.

Twin of InsertN dword (`004073a0`) and InsertN elem0xC (`004082f0`) with stride/ABI differences.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `VecPod28*` this (+4 begin, +8 end, +0xC capEnd); entry `mov ebx,ecx` |
| **EDX** | `const Pod28*` value (10 dwords snapped) |
| stack0 | `Pod28*` where |
| stack1 | `uint` count |
| return | void; **`ret 0x8`** |

```c
void __fastcall StdVector_InsertN_Elem0x28(
    VecPod28 *this, const Pod28 *value, Pod28 *where, uint count);
```

Parent `00406de0` bytes: `mov edx,value; push 1; push where; mov ecx,edi; call 00408050`.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00408050` (2026-08-04) ≡ raw scaffold CF |
| Bytes | `read_memory` — SEH, `mov ebx,ecx`, `B9 0A`/`F3 A5` snap 10 dwords, magic `0x66666667`, max `0x06666666`, grow, **`C2 08 00`** |
| Bounds | body through ret 8; pad `CC`; next twin InsertN12 `004082f0` |
| Callers | `get_function_callers` → `FUN_00406de0` only (1 xref @ `00406e30`) |
| Callees | Ufill `00406e50` / uninit_copy `00409ae0` / relocate `0040a520` / `00409b00`/`00409b20` / size `00437d80` / overflow `00418130` / new/delete |
| Wrapper dual | WQ9G-H sealed `aa_00406de0` InsertOne |
| Ufill dual | WQ9G-H sealed `aa_00406e50` |
| Twin reviews | WQ9H-B `aa_004082f0` InsertN 0xC |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Snap 10 dwords of `*value` | **Yes** |
| cap = (capEnd-begin)/0x28; size = (end-begin)/0x28 | **Yes** |
| count==0 early return | **Yes** |
| max-size check → `FUN_00418130` | **Yes** (`0x06666666`) |
| Grow if cap < size+count: 1.5× then size+count | **Yes** |
| Realloc: new → prefix uninit_copy → Ufill → suffix → delete → triad | **Yes** |
| In-place: tail<count vs else | **Yes** |
| Shared assign-fill `FUN_00409b00` | **Yes** |
| `ret 0x8` | **Yes** |
| No domain / packet logic | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live | **Confirmed** | CF spine identical |
| ECX/EDX + ret 0x8 | **Confirmed** | bytes + parent |
| Triad + stride **0x28** | **Confirmed** | `/0x28`, magic `0x66666667` |
| Growth 1.5× + exact floor | **Confirmed** | decompile + bytes |
| Three-way relocate on grow | **Confirmed** | callees dualed/roles sealed |
| In-place dual sub-cases | **Confirmed** (CF) | helper formal packing High not Confirmed runtime |
| Sole caller InsertOne | **Confirmed** | 1 xref |
| Product English | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Exact MSVC demangled name / 0x28-byte element English type.
2. Full dual of uninit_copy / mid-insert assign-fill leaves (roles sealed).
3. Bit-exact / runtime / image diff.
4. Decompiler warning on `operator_delete` "does not return" is a decomp artifact — triad rebind after free is load-bearing.

**Verdict:** **accept-with-gaps**
