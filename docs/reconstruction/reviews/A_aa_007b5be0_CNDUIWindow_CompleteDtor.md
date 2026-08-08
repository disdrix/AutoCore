# Review A (reconstruction fidelity): `aa_007b5be0` CNDUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b5be0` |
| **VA** | `0x007b5be0`–`0x007b5dcc` (**493 B**) |
| **Canonical name** | `CNDUIWindow_CompleteDtor` |
| **Ghidra name** | `FUN_007b5be0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-F) |
| **Counterpart** | `reviews/B_aa_007b5be0_CNDUIWindow_CompleteDtor.md` |
| **System** | UI / CNDUIWindow complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + multi-span `read_memory` + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for **CNDUIWindow**: re-stamp primary vtbl `PTR_FUN_00a960ac`, owner-debug log, decrement live window counter, release owned child/strings/buffers/nested CS object, chain super-base `FUN_00759de0`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9K-F append) | `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b5be0_FUN_007b5be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007b5be0.cpp` |
| Function records | `aa_007b5be0_FUN_007b5be0.md`, `aa_007b5be0_CNDUIWindow_CompleteDtor.md` |
| Ctor twin | `aa_007b5dd0` NDUIWindow_BaseCtor_Inferred (same vtbl) |
| Live | decompile ≡ disasm CF; false-noreturn corrected; RTTI type_info string |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b325c; ADD ESP,0x10; C3; void
void __fastcall CNDUIWindow_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 10 C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH; ESI=this; EDI=1; EBX=0
*this = PTR_FUN_00a960ac
if +0x2B0: VOG_DEBUG_STOP + owner filename warn
_DAT_00d17954--
if +0x2B4 && +0xBD: vcall[+0xC](1); null both
FUN_007a8580; FUN_007aec70; FUN_007aff00
free +0x28C (+ helper), +0x2B8, string slots, 11× +0x45C
nested +0x1E8 dual FUN_00424060 + DeleteCriticalSection(+0x1EC)
FUN_00759de0
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `00a960ac` | `C7 06 AC 60 A9 00` | **High** |
| Owner debug strings | decompile ≡ push imm strings | **High** |
| Live count decrement | `SUB [00d17954],EDI` | **High** |
| Free chain + always-null | disasm after each free | **High** |
| Nested CS tear + base | end of disasm | **High** |
| Reaches RET | epilogue hex | **High** |
| RTTI CNDUIWindow | COL→type_info `.?AVCNDUIWindow@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry/mid/epilogue samples in raw WQ9K-F append. Full listing via `disassemble_function` (493 B).  
Entry SEH: `6A FF 68 5C 32 9B 00 …`.  
Epilogue: `… CALL 00759de0; SEH restore; 83 C4 10 C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete dtor body) |
| Callers | `CNDUIWndBuffered_CompleteDtor`, `CWndWaypointIcon_CompleteDtor`, scalar `0x00423e50`, many UI complete paths + EH |
| Pattern | scalar: `complete(this); if (flags&1) delete this;` |

---

## 7. Gaps

1. Product English for free helpers and super-base `FUN_00759de0`.  
2. Exact semantic names for string slots / 11-element array.  
3. Nested object class at `+0x1E8` (vtbls `00a964b8`/`00a964ac`).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

Complete-dtor role, ABI/SEH, vtbl+RTTI, owner-debug, free-null order, nested CS tear, and base chain sealed. Residual helper/layout English → **accept-with-gaps**.
