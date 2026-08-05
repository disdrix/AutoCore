# Review A (reconstruction fidelity): `aa_0096efd0` RefCountedPtr_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096efd0` |
| **VA** | `0x0096efd0`–`0x0096f03a` (**107 B** / `0x6B`); pad `CC`×5; next @ `0x0096f040` |
| **Canonical name** | `RefCountedPtr_Dtor_Inferred` (**Inferred**); Ghidra `FUN_0096efd0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md` |
| **System** | shared util — refcounted handle destructor |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context`, peer `0096ef70` (no `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/payload layout sealed; product RTTI open only |
| **Dual status** | **Present (W38-P)** |

---

## 1. Purpose

Destroy a **4-byte refcounted handle**:

```
// ECX = handle*; ret
if (payload = *handle) {
  if (--payload->refcount@+8 == 0)
    call (payload+4)->vtbl[2]();   // release; this = payload+4
  *handle = 0;
}
// SEH cleanup twin: release without null (no-op after successful try)
```

Peer default ctor: `RefCountedPtr_DefaultCtor_Inferred` @ `0x0096ef70` (W25-N) zeros the same 4-byte slot.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x0096efd0` |
| Complete analysis | leaf; 100 xrefs; no FUN callees |
| Machine | `read_memory` 128 B → body **107 B** then `CC` |
| Peer ctor | `0x0096ef70` dual + clean (W25-N) |
| Thunk | `thunk_FUN_0096efd0` @ `0x004434c0` (identical shape; not OWN) |
| Scaffold | `raw/aa_0096efd0_*`, `reconstructed-exact/FUN_0096efd0.cpp` |

**Not performed:** Launcher, runtime golden, parent ledger edits, `disassemble_bytes`.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| SEH prolog `push -1; push LAB_009ac21a; fs:[0]` | `6a ff 68 1a c2 9a 00 64 a1 …` | **Confirmed** |
| `mov esi, ecx` this | `8b f1` | **Confirmed** |
| EH state 0 then -1 | `c7 44 24 10 00…` / `ffffffff` | **Confirmed** |
| refcount `--` at `+8` | `83 40 08 ff` / `83 46 08 ff` | **Confirmed** |
| `lea ecx, [payload+4]` before call | `8d 48 04` / `8d 4e 04` | **Confirmed** |
| `call [vtbl+8]` | `ff 50 08` / `ff 52 08` | **Confirmed** |
| try path nulls `*handle` | `c7 06 00 00 00 00` | **Confirmed** |
| cleanup path does **not** null | second block ends at call only | **Confirmed** |
| `ret` not `ret N` | `83 c4 10 c3` | **Confirmed** |
| Body 107 B | end @ `0x0096f03a`; pad then `0x0096f040` | **Confirmed** |

Full hex (107 B):

```
6aff681ac29a0064a100000000506489250000000051568bf189742404c7442410000000008b0685c07414834008ff8d480475058b01ff5008c70600000000c7442410ffffffff8b3685f6740e834608ff8d4e0475058b11ff52088b4c24085e64890d0000000083c410c3
```

---

## 4. Layout contract

| Offset | Role |
|---|---|
| handle+0 | `payload*` |
| payload+4 | iface / subobject (release this-ptr) |
| payload+8 | `int32` refcount |
| iface vtbl+8 | release / destroy method |

---

## 5. Dual-release decompiler note

Ghidra shows two nearly identical release blocks. Bytes prove MSVC **SEH state machine** (try + cleanup), not two live releases on the happy path: after `*handle = 0`, the cleanup reload is zero.

---

## 6. Residual gaps

1. Product / RTTI name of payload type.  
2. Exact identity of release method (free vs recycle).  
3. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept** — full body sealed; only product English open.
