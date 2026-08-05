# Review A (reconstruction fidelity): `aa_004be2a0` ListTrackedObj_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004be2a0` |
| **VA** | `0x004be2a0`–`0x004be43c` (**412 B**) |
| **Canonical name** | `ListTrackedObj_CompleteDtor` |
| **Ghidra name** | `FUN_004be2a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-P) |
| **Counterpart** | `reviews/B_aa_004be2a0_ListTrackedObj_CompleteDtor.md` |
| **System** | large owned object complete dtor (list-tracked + globals) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for list-tracked owned objects: flag-gated nested cleanup, global count--, intrusive unlink, optional global instance teardown, free two buffer triples, member dtors, install base vtbl `PTR_LAB_009cb5cc` at `+0x10` and `+0x20`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-P append) | `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004be2a0_FUN_004be2a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ListTrackedObj_CompleteDtor.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004be2a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004be2a0_ListTrackedObj_CompleteDtor.md` |
| Consumer | `aa_005b8000` Elem0x28_CompleteDtor (W29-F) |
| Live | decompile stage order ≡ bytes; epilogue hex seals fall-through past false noreturn |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009a1833; ADD ESP,0x10; C3; void
void __fastcall ListTrackedObj_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 10 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prolog; EH=9; ESI=this
if flag@+0x5D0:
  cleanup list region (+0x10..) ; FUN_004bf740(this+0x10)
DAT_00b03734--
unlink DLL (this+0 / this+4)
DAT_00b0373c--
if count==0: complete-dtor+delete DAT_00b03730; null it
elif count<0: count=0
delete buffer@+0x58C; zero triple
delete buffer@+0x57C; zero triple
FUN_0074b580(+0x474); (+0x444); (+0x414)   // empty stubs
FUN_00763f60(+0x2C8); (+0x17C); (+0x30)
*(this+0x20) = *(this+0x10) = &PTR_LAB_009cb5cc
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Flag@+0x5D0 gate | decompile ≡ `38 9E D0 05 00 00` | **High** |
| Global counts + DLL unlink | decompile ≡ bytes | **High** |
| Buffer triples | decompile ≡ lea/mov offsets | **High** |
| Member dtor order 6→1 | EH state bytes + lea offsets | **High** |
| Base vtbl dual install | epilogue `B8 CC B5 9C 00; 89 46 20; 89 46 10` | **High** |
| Reaches RET | full 412 B hex | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (412 B) — see raw W30-P append.  
Entry SEH: `6A FF 68 33 18 9A 00 64 A1 …`.  
Epilogue: `… 83 C4 10 C3` then `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `FUN_00494700`, `FUN_00494530`, `FUN_00497a30`, `FUN_005b8000`, self |
| Pattern | callers: `FUN_004be2a0(p); operator_delete(p);` |

---

## 7. Gaps

1. Product/MSVC demangle for class (base vtbl install ≠ product plate).  
2. Flag path nested blob type / vtbl[+8] semantics.  
3. Nested `FUN_00763f60` / `FUN_004bf740` product English (OWN residual).  
4. Dual global counter product meaning.  
5. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, unlink/globals, buffer offsets, member order, and base vtbl install sealed. Residual product class + nested members → **accept-with-gaps**.
