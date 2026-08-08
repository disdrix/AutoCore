# Review A (reconstruction fidelity): `aa_00759de0` gfxUIWindow_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00759de0` |
| **VA** | `0x00759de0`–`0x0075a143` (**868 B**) |
| **Canonical name** | `gfxUIWindow_CompleteDtor` |
| **Ghidra name** | `FUN_00759de0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-F) |
| **Counterpart** | `reviews/B_aa_00759de0_gfxUIWindow_CompleteDtor.md` |
| **System** | UI / gfxUIWindow complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + multi-span `read_memory` + xrefs + RTTI COL. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for **gfxUIWindow**: re-stamp primary vtbl `PTR_FUN_00a9f304`, tear tree shells / vectors / refcounted slots, assert if children remain attached, finish nested subobject at `+0x30`. Does not free `this`. Super-base of `CNDUIWindow_CompleteDtor`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-F append) | `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00759de0_FUN_00759de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxUIWindow_CompleteDtor.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00759de0.cpp` |
| Function records | `aa_00759de0_FUN_00759de0.md`, `aa_00759de0_gfxUIWindow_CompleteDtor.md` |
| Scalar peer | `FUN_004401b0` (`vtbl[0]`) |
| Live | decompile ≉ full body (false-noreturn truncate); disasm + epilogue hex seal complete CF; RTTI type_info string |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009b3156; ADD ESP,0x20; C3; void
void __fastcall gfxUIWindow_CompleteDtor(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void (no free this) | **High** |
| cleanup | `83 C4 20 C3` @ `0x0075a0f2`–`0x0075a0f4` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH; ESI=this; EBX=0
*this = PTR_FUN_00a9f304
clear shells @+0x10 / +0x04 / +0xA4; free vectors; release +0x34
optional FUN_00756be0 if +0x88
children @+0x94: assert + zero child+0x88 + free
EH residual: delete shell heads; nested vtbl @+0x30; shells again
SEH restore; RET
// side: EH_Abort → VOGCRASH / ExitProcess(3)
```

| Stage | Match | Conf |
|---|---|---|
| Vtbl install `00a9f304` | `C7 06 04 F3 A9 00` | **High** |
| Children assert strings | push imm + `FUN_0076d1b0` | **High** |
| False-noreturn correction | disasm continues past deletes to `RET` | **High** |
| Reaches bare RET | epilogue hex @ `0x0075a0f4` | **High** |
| RTTI gfxUIWindow | COL→type_info `.?AVgfxUIWindow@@` | **High** |

---

## 5. Machine bytes (`read_memory`)

| Span | Result |
|---|---|
| Entry 64 B @ `0x00759de0` | SEH + `MOV ESI,ECX` + vtbl store sealed |
| Epilogue @ `0x0075a0e0` | pops + `ADD ESP,0x20` + `C3` sealed |
| COL/type_info | `.?AVgfxUIWindow@@` sealed |

---

## 6. Gaps (accepted)

- Product English for tree-shell / vector element types.
- Exact second residual erase helper VA for shell `+0x04` (CF sealed as erase-all + delete head).
- Helper duals (`FUN_00756be0`, erase family, `FUN_00988710`).
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Fidelity path accepts complete-dtor ABI, RTTI product name, children-assert semantics, and full-body correction of Ghidra false-noreturn truncation. Gaps are naming/helper residual only — not control-flow blockers.
