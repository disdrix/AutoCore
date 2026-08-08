# Review A (reconstruction fidelity): `aa_0078ca80` CNDUIWndBuffered_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078ca80` |
| **VA** | `0x0078ca80`–`0x0078caef` (**112 B**) |
| **Canonical name** | `CNDUIWndBuffered_CompleteDtor` |
| **Ghidra name** | `FUN_0078ca80` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-F) |
| **Counterpart** | `reviews/B_aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |
| **System** | UI / CNDUIWndBuffered complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for **CNDUIWndBuffered**: re-stamp primary vtbl `PTR_FUN_00a99f74`, run shared helpers, scalar-delete nested HostBase at `+0x2A8`, chain base `FUN_007b5be0` (`CNDUIWindow_CompleteDtor`). Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-F append) | `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.md` |
| Annotated | `docs/reconstruction/raw/aa_0078ca80_FUN_0078ca80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0078ca80.cpp` |
| Function records | `aa_0078ca80_FUN_0078ca80.md`, `aa_0078ca80_CNDUIWndBuffered_CompleteDtor.md` |
| Ctor twin | `aa_0078caf0` CNDUIWndBuffered_Ctor_Inferred (W34-T) |
| Live | decompile ≡ bytes; RTTI type_info string; scalar peer `0x004293f0` |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b3fee; ADD ESP,0x10; C3; void
void __fastcall CNDUIWndBuffered_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 10 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH prolog; ESI=this
*this = PTR_FUN_00a99f74
EH=0
FUN_007a8580
FUN_0078c3d0 (ECX=ESI)
if *(this+0x2A8): vcall [*(nested)](1)
*(this+0x2A8) = 0
EH=-1
FUN_007b5be0 (ECX=ESI)
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `00a99f74` | `C7 06 74 9F A9 00` | **High** |
| Nested load `+0x2A8` | `8B 8E A8 02 00 00` | **High** |
| Nested scalar flag 1 | `6A 01 FF 10` | **High** |
| Always-null `+0x2A8` | store after if | **High** |
| Base `007b5be0` then RET | disasm end | **High** |
| RTTI CNDUIWndBuffered | COL→type_info `.?AVCNDUIWndBuffered@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (112 B) — see raw WQ9K-F append.  
Entry SEH: `6A FF 68 EE 3F 9B 00 64 A1 …`.  
Epilogue: `… 83 C4 10 C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `CWndVehicle_CompleteDtor` (`0x00834520`), scalar `0x004293f0`, `FUN_00856380`, EH unwinds |
| Pattern | scalar: `complete(this); if (flags&1) delete this;` |

---

## 7. Gaps

1. Product English for `FUN_007a8580` / `FUN_0078c3d0`.  
2. Nested HostBase type details at `+0x2A8` (ctor path known; dtor vtbl[0] product name open).  
3. Full dual of base `FUN_007b5be0` is OWN pair — sealed separately.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, vtbl+RTTI, nested free-null, and base chain sealed. Residual helper English → **accept-with-gaps**.
