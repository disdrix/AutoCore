# Review A (reconstruction fidelity): `aa_00988710` UiOwnedBlock_CompleteBeforeDelete_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988710` |
| **VA** | `0x00988710`–`0x0098879e` (**143 B** / `0x8F`) |
| **Canonical name** | `UiOwnedBlock_CompleteBeforeDelete_Inferred` |
| **Ghidra name** | `FUN_00988710` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-123) |
| **Counterpart** | `reviews/B_aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` |
| **System** | UI owned-block complete destructor (skills-abilities partition bucket; gfxUIWindow teardown helper) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + multi-span `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for a **heap-owned UI block** embedding a tree/map shell and a refcounted iface. Tears members, frees the tree **sentinel head**, nulls head/size. Does **not** free the host — every caller pairs with `operator_delete(block)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-123 append) | `docs/reconstruction/raw/aa_00988710_FUN_00988710.md` |
| Annotated | `docs/reconstruction/raw/aa_00988710_FUN_00988710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiOwnedBlock_CompleteBeforeDelete_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00988710.cpp` |
| Function records | `aa_00988710_FUN_00988710.md`, `aa_00988710_UiOwnedBlock_CompleteBeforeDelete_Inferred.md` |
| Parent dual | `gfxUIWindow_CompleteDtor` `0x00759de0` (WQ9L-F) |
| Live | decompile ≉ full body (false-noreturn); disasm+epilogue hex seal complete CF |

---

## 3. Signature (sealed)

```c
// ECX = this; SEH LAB_009ad7cd; bare RET (C3); void
void __fastcall UiOwnedBlock_CompleteBeforeDelete_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`MOV EDI,ECX` @ `0x00988728`) | **High** |
| return | void (no free this) | **High** |
| cleanup | bare `C3` @ `0x0098879e` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH install; EDI=this; EBX=0; EH=1
release iface @+0x0C (refcount-- / vtbl[+8]); null +0x0C
EH=0; residual release of +0x0C
EH=-1
FUN_0044f3c0(&it, *head, head)   // EDI=container
operator_delete(head)
head=0; size=0
SEH restore; RET
```

| Stage | Match | Conf |
|---|---|---|
| ECX→EDI this | `8B F9` | **High** |
| iface release + null | `MOV ECX,[EDI+0xC]` … `MOV [EDI+0xC],EBX` | **High** |
| Tree erase + head free | `CALL 0044f3c0` then `CALL 00489822` | **High** |
| Null head/size after free | `MOV [EDI+4],EBX; MOV [EDI+8],EBX` | **High** |
| False-noreturn correction | epilogue after delete reaches `C3` | **High** |
| No host free | callers delete host after return | **High** |

---

## 5. Machine bytes (`read_memory`)

| Span | Result |
|---|---|
| Entry 64 B @ `0x00988710` | SEH + `MOV EDI,ECX` + EH=1 + iface load sealed |
| Mid @ `0x00988763`–`0x00988784` | EH=-1 + erase + `operator_delete` sealed |
| Epilogue @ `0x00988785` | `ADD ESP,4` + null head/size + FS restore + `C3` sealed |
| Pad | `CC` @ `0x0098879f` |

---

## 6. Callers / callees

| Kind | Detail |
|---|---|
| Callees | `FUN_0044f3c0`, `operator_delete` @ `0x00489822` |
| Callers | 5 functions / **18** UNCONDITIONAL_CALL — all complete-then-delete |
| Key parent | `gfxUIWindow_CompleteDtor` slots `+0xB0` / `+0xB4` |
| Ctor twin | `FUN_009886d0` (empty tree + isnil@+0x25 + null iface) |

---

## 7. Gaps (accepted)

- Product demangle / exact class English (hence `_Inferred`).
- Tree key/value element type for isnil@+0x25 nodes.
- Exact iface type at `+0x0C`.
- Runtime / bit-exact / differential.

---

## 8. Verdict rationale

Fidelity path accepts complete-dtor ABI, offset map, false-noreturn full-body correction, and universal caller pairing with host `operator_delete`. Gaps are naming/type English only — not control-flow blockers.
