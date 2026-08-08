# Review A (reconstruction fidelity): `aa_0078c3d0` CNDUIWndBuffered_TeardownBufferedOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078c3d0` |
| **VA** | `0x0078c3d0`–`0x0078c47e` inclusive (**175 B** / `0xAF`) |
| **Canonical name** | `CNDUIWndBuffered_TeardownBufferedOwned_Inferred` |
| **Ghidra name** | `FUN_0078c3d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-D2) |
| **Counterpart** | `reviews/B_aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |
| **System** | UI / CNDUIWndBuffered complete-dtor helper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full 175 B) + callers/xrefs + call-site context. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tear down **buffered owned children** of `CNDUIWndBuffered` when primary slot `+0x2A4` is live: unregister + scalar-delete `+0x2AC` / optional `+0x49C`, scalar-delete `+0x2A4`, and refcount-release HostBase-aux slot `+0x3C`. Does **not** free HostBase at `+0x2A8`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-D2 append) | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0078c3d0_FUN_0078c3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_TeardownBufferedOwned_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0078c3d0.cpp` |
| Function records | `aa_0078c3d0_FUN_0078c3d0.md`, `aa_0078c3d0_CNDUIWndBuffered_TeardownBufferedOwned_Inferred.md` |
| Parent dual | `CNDUIWndBuffered_CompleteDtor` `aa_0078ca80` (WQ9K-F) |
| Live | decompile ≡ raw CF ≡ full-body hex; ABI sealed via disasm; RTTI class via parent |

---

## 3. Signature (sealed)

```c
// ECX = CNDUIWndBuffered* this; bare C3; void
void __fastcall CNDUIWndBuffered_TeardownBufferedOwned_Inferred(void *self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void | **High** |
| cleanup | `5F 5E C3` | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (bytes authority)

```
ESI=this; EDI=0
if *(this+0x2A4)==0 → RET
FUN_0074e260(*(HostBase+4), *(*(this+0x2AC)+0x8C))
if *(this+0x2AC): vcall [*(child)](1)
*(this+0x2AC)=0   // interleaved after CMP +0x49C
if *(this+0x49C):
  FUN_0074e260 same pattern
  if child: vcall(1); *(this+0x49C)=0
if *(this+0x2A4): vcall(1)
*(this+0x2A4)=0
host_aux = *(*(this+0x2A8)+4)
if *(host_aux+0x3C): refcount--; if 0: vcall[+8]
*(host_aux+0x3C)=0
RET
```

| Stage | Match | Conf |
|---|---|---|
| Gate `+0x2A4` | `39 BE A4 02 00 00` + JZ | **High** |
| Unregister thiscall ECX=`HostBase+4` | `8B 4A 04` before CALL `0074e260` | **High** |
| Scalar flag 1 | `6A 01 FF 10` / `FF 12` | **High** |
| Refcount `ADD [ECX+4],-1` | `83 41 04 FF` | **High** |
| Release `CALL [EDX+8]` | `FF 52 08` | **High** |
| Bare RET | `C3` | **High** |
| Decompile ≡ raw 2026-07-23 | identical body | **High** |
| Owner class CNDUIWndBuffered | parent RTTI + call site | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 175 B hex — see raw WQ9L-D2 append.  
Entry: `56 57 8B F1 33 FF …`  
Epilogue: `… 5F 5E C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (nested teardown helper) |
| Code callers | `CNDUIWndBuffered_CompleteDtor` @ `0x0078cab2` |
| DATA xrefs | 4 vtable slots (`00a9a32c`, `00a6ff84`, `00a6755c`, `00a66d24`) |
| Derived path | `CWndVehicle_CompleteDtor` → parent complete → this |

---

## 7. Gaps

1. Product English / RTTI for owned types at `+0x2A4` / `+0x2AC` / `+0x49C`.  
2. Dual of `FUN_0074e260` (unregister helper; scaffold only).  
3. Product meaning of HostBase-aux `+0x3C` COM-like object.  
4. Exact vtable method indices for 4 DATA slots.  
5. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, body size, gate/offsets, unregister thiscall, scalar-delete pattern, HostBase-aux release, and owner class (via parent RTTI) sealed. Product demangle for owned child types open → **accept-with-gaps**.
