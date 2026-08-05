# Review A (reconstruction fidelity): `aa_004363b0` BitVec_EnsureOneAndLocateRef_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004363b0` |
| **VA** | `0x004363b0`–`0x0043640f` exclusive (**95 B**) |
| **Canonical name** | `BitVec_EnsureOneAndLocateRef_Inferred` |
| **Ghidra name** | `FUN_004363b0` |
| **Prior scaffold** | `FUN_004363b0` / `Named_CalleeOf_Named_gfxBody_004363b0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual W38-C) |
| **Counterpart** | `reviews/B_aa_004363b0_BitVec_EnsureOneAndLocateRef_Inferred.md` |
| **System** | dword-packed bit vector ensure + bit-ref locate |
| **Evidence pass** | Live decompile + `read_memory` + sole-caller `get_assembly_context` + parent `FUN_00765740`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Grow/ensure one bit of packed storage, then produce a rebased bit-reference for callers that will set/test that bit. Used from gfxBody chunk unserialize when establishing a bit cursor into host bit storage.

**Not** a full insert-N API (sibling `00436410`), not dword-vector resize, not domain geometry logic despite gfxBody caller plate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` @ `0x004363b0` ≡ scaffold |
| Bytes | full **95 B** body; `mov eax,1`; `call +0xd2` → `004364b0`; `C2 0C 00` |
| Callee | `decompile_function` `FUN_004364b0` |
| Sibling | `FUN_00436410` @ `0x00436410` (not OWN) |
| Parent | `FUN_00765740` @ call `0x00765c31` |
| Family | bitset path notes vs `004365e0` / dword erase |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// EAX = host*; EDI = BitRef* out; stack (bitAdd, dwordPos*, param3);
// returns out*; RET 0x0C
BitRef* BitVec_EnsureOneAndLocateRef_Inferred(...);
```

| Formal | Source | Conf |
|---|---|---|
| host* | EAX (`mov ebx,eax`) | **Confirmed** |
| out* | EDI (`mov [edi],…; mov eax,edi`) | **Confirmed** |
| bitAdd | stack0 | **Confirmed** |
| dwordPos* | stack1 | **Confirmed** |
| param3 | stack2 → forwarded | **Confirmed** presence; meaning open |
| ensure count | EAX=1 pre-call | **Confirmed** |
| RET 0xC | `C2 0C 00` | **Confirmed** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Snapshot begin@+8 | **Yes** | **Confirmed** |
| call ensure with count 1 | **Yes** | **Confirmed** |
| Re-read begin@+8 | **Yes** | **Confirmed** |
| bitIndex = words*32 + bitAdd | **Yes** | **Confirmed** |
| out = {&31, begin+(>>5)} | **Yes** | **Confirmed** |
| return out* | **Yes** | **Confirmed** |
| Invented branches | **None** | — |

Decompiler omits explicit count=1 and register ABI — **bytes win**.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Custom register+stack ABI | **Confirmed** | sole caller matches |
| begin @ host+8 | **Confirmed** | |
| Bit packing 32/dword | **Confirmed** | |
| Ensure-then-locate order | **Confirmed** | realloc-safe |
| param3 semantics | **Open** | only forwarded |
| Product class name | **Open** | |
| Runtime | **Open** | |

---

## 6. Gaps

1. Product / MSVC demangle (`vector<bool>`-like?).  
2. Full dual of ensure engine `004364b0`.  
3. param3 role.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/bit math sealed; product English + ensure internals open.
