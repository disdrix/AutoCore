# Review A (reconstruction fidelity): `aa_0075d8e0` NDResourceCache_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d8e0` |
| **VA** | `0x0075d8e0`–`0x0075d9BF` exclusive (**223 B**) |
| **Canonical name** | `NDResourceCache_CompleteDtor` |
| **Ghidra name** | `FUN_0075d8e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-I) |
| **Counterpart** | `reviews/B_aa_0075d8e0_NDResourceCache_CompleteDtor.md` |
| **System** | assets / NDResourceCache + AssManager host complete destructor |
| **Evidence pass** | Live Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `read_memory` **past** Ghidra body end + related decompiles (`FUN_0075d470`, `FUN_00971050`, `FUN_0040d9c0`, `FUN_00415e90`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC complete destructor for the NDResourceCache / AssManager-shaped host embedded at `Palantir+0x30` and published as `DAT_00d1f050`. Tears down NestedHash entries, AssPreloader, std tree, critical section, OwnedPtrTable, and list shell; clears `DAT_00d1f050`. Does **not** free `self`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-I append) | `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResourceCache_CompleteDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0075d8e0.cpp` |
| Function records | `functions/aa_0075d8e0_FUN_0075d8e0.md`, `functions/aa_0075d8e0_NDResourceCache_CompleteDtor.md` |
| Pair ctor | `FUN_0075d470` (unowned) |
| Parent | `Palantir_CompleteDtor` stage `FUN_0075d8e0(self+0x30)` |
| Live | full 223 B hex; 3 xrefs |

---

## 3. Signature (sealed)

```c
// stack self*; RET 4; void; no operator_delete(self)
void NDResourceCache_CompleteDtor(NDResourceCache* self /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | Stack → EBP (`8B 6C 24 1C`) | **High** |
| cleanup | `ADD ESP,0x10; RET 4` | **High** |
| free self | not in body | **High** |
| ECX-thiscall | **No** | **High** |

---

## 4. Control flow (bytes authority)

```
FUN_0075d6f0()                         // ESI=self NestedHash entry teardown
if (self+0x6c) {
  FUN_00971050()                       // ECX=AssPreloader*
  FUN_00971180(pre); operator_delete(pre)
  self+0x6c = 0
}
FUN_0043c220(erase tree at +0x58)      // EDI=self+0x58
operator_delete(tree head); null head/size
DeleteCriticalSection(self+0x3c)
*(self+0x54)=0
FUN_0040d9c0()                         // ESI=self+0x28 OwnedPtrTable_Clear
if (self+0x14) operator_delete; null +0x14..+0x1C
FUN_00415e90()                         // ESI=self+0x04 list tidy
operator_delete(list head); null +0x08
DAT_00d1f050 = 0
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Preloader @ `+0x6c` | matches ctor EnsureAssPreloader | **High** |
| Tree @ `+0x58` | matches ctor `FUN_005ae2b0` head | **High** |
| CS @ `+0x3c` | matches ctor `InitializeCriticalSection` | **High** |
| Global clear | `C7/MOV DAT_00d1f050,0` via `89 1D 50 F0 D1 00` | **High** |
| Ghidra end `0x0075d955` | **Reject** — mid-body after first `operator_delete` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (223 B) — see raw W35-I append.

Entry: `6A FF 68 86 DB 9A 00 64 A1 … 8B 6C 24 1C`  
Epilogue: `89 1D 50 F0 D1 00 … 83 C4 10 C2 04 00`  
Pad: `CC`; next function @ `0x0075d9c0`.

**Decompile ≢ bytes:** false noreturn cuts CF after AssPreloader free and after tree free. **Bytes win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00754320` Palantir_CompleteDtor; Unwind `@009afd03`, `@009afd3f` |
| Callees | `FUN_0075d6f0`, `FUN_00971050`, `FUN_00971180`, `operator_delete`, `FUN_0043c220`, `DeleteCriticalSection`, `FUN_0040d9c0`, `FUN_00415e90` |
| Global | clears `DAT_00d1f050` |

---

## 7. Gaps

1. Nested duals for `FUN_0075d6f0` / `FUN_00971180` / tree host plate.  
2. Exact product type name (NDResourceCache vs AssManager English).  
3. Pair ctor `FUN_0075d470` dual still open.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

Full teardown order, ABI, and `DAT_00d1f050` clear sealed by 223 B hex + ctor symmetry; nested callee plates open; Ghidra body truncated → **accept-with-gaps**.
