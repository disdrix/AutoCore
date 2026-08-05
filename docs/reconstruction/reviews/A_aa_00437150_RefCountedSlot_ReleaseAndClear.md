# Review A (reconstruction fidelity): `aa_00437150` RefCountedSlot_ReleaseAndClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437150` |
| **VA** | `0x00437150` |
| **Body** | `0x00437150`–`0x004371b3` |
| **Canonical name** | `RefCountedSlot_ReleaseAndClear` |
| **Prior scaffold** | `FUN_00437150` |
| **Review date** | `2026-07-29` (W23-A dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00437150_RefCountedSlot_ReleaseAndClear.md` |
| **System** | shared intrusive-refcount smart slot / SEH cleanup |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ complete analysis, assembly context). No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Release-and-clear** helper for a pointer slot holding an intrusive-refcount object:

1. Load `obj = *slot`.  
2. If non-null: `--*(obj+4)`; if zero call `obj->vtbl[+8]`; then `*slot = 0`.  
3. Residual second path re-reads `*slot` (null after clear) and would release without clearing.

Also installed on **SEH unwind** paths so slots free correctly on exception.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00437150_FUN_00437150.md` (+ residual) |
| Annotated | `docs/reconstruction/raw/aa_00437150_FUN_00437150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RefCountedSlot_ReleaseAndClear.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00437150.cpp` |
| Function record | `docs/reconstruction/functions/aa_00437150_RefCountedSlot_ReleaseAndClear.md` |
| Live decompile | `decompile_function` `0x00437150` |
| Live bytes | `read_memory` length 128 |
| Meta | body `00437150`–`004371b3` |
| Xrefs | 11 sites incl. Unwind@* and `FUN_0044adc0` |
| Nested | `FUN_00439f00` thin wrapper; CP pair release dual context |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__stdcall`**, one pointer arg |
| Arg | `MOV ESI,[ESP+0x14]` after SEH+`push esi` → original `[ESP+4]` |
| Epilogue | restore FS:[0], `POP ESI`, `ADD ESP,0xC`, **`RET 4`** |
| Return | void |

```c
void __stdcall RefCountedSlot_ReleaseAndClear(void **slot);
```

### 3.2 Algorithm — **SEALED**

```
SEH install (state 0)
obj = *slot
if obj:
  if (--*(int32*)(obj+4) == 0):
    call (*(void***)obj)[+8]   // thiscall, this=obj
  *slot = 0
state = -1
obj = *slot
if obj:                        // residual after clear
  if (--*(int32*)(obj+4) == 0):
    call vtbl[+8]
SEH teardown
ret 4
```

### 3.3 Layout — **SEALED**

| Off | Role |
|---|---|
| slot `+0` | `T*` |
| T `+0` | vtbl |
| T `+4` | intrusive `int32` refcount |
| vtbl `+8` | destroy/Release |

### 3.4 Phase2 residual — **SEALED as residual**

After successful phase1, `*slot` is null → phase2 never runs. If phase1 skipped (already null), phase2 also null. **At most one effective release+clear** under normal CF. Phase2 retained in clean for fidelity to bytes/decompile.

### 3.5 Name — **structural accept**

`RefCountedSlot_ReleaseAndClear` — no RTTI/string on VA; role from refcount math + clear + SEH/CP consumers. Not limited to phy CP definitions.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install / teardown | Yes (bytes) |
| Phase1 release + clear | Yes |
| Phase2 re-read residual | Yes |
| Indirect vtbl+8 only | Yes |
| `RET 4` | Yes |

---

## 5. Gaps / open

1. Product type(s) stored in slots (shared base vs multiple).  
2. Whether vtbl+8 is COM `Release`, `operator delete`, or custom.  
3. Why MSVC left phase2 (template/EH expansion).  
4. Full size of T.  
5. Runtime / differential verification.

**Verdict:** **accept**
