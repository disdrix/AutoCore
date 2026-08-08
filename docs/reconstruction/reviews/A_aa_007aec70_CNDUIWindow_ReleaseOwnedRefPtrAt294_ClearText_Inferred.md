# Review A (reconstruction fidelity): `aa_007aec70` CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **VA** | `0x007aec70`–`0x007aecc3` (**84 B**) |
| **Canonical name** | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` |
| **Ghidra name** | `FUN_007aec70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-G) |
| **Counterpart** | `reviews/B_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md` |
| **System** | UI / CNDUIWindow complete-dtor helper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Partial teardown helper on `CNDUIWindow`: optionally destroy/delete owned refcounted shell at `+0x294`, clear text via `vtbl[+0x2B4]("")`, zero related dwords. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-G append) | `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.md` |
| Annotated | `docs/reconstruction/raw/aa_007aec70_FUN_007aec70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007aec70.cpp` |
| Function records | `aa_007aec70_FUN_007aec70.md`, named record |
| Parent | `CNDUIWindow_CompleteDtor` (`0x007b5be0`) calls at `0x007b5c83` |
| Peer dtor | `RefCountedPtr_Dtor_Inferred` (`0x0096efd0`) |

---

## 3. Signature (sealed)

```c
// ECX = this; bare RET (C3); void
void __fastcall CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void; does not free this | **High** |
| cleanup | `C3` @ `0x007aecc3` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI=this; EDI=[ESI+0x294]
if EDI != 0:
  if [ESI+0xBB] != 0:
    ECX=EDI; CALL RefCountedPtr_Dtor
    PUSH EDI; operator_delete; ADD ESP,4
  PUSH ""; ECX=ESI; null +0x294/+0xBB; CALL [vtbl+0x2B4]
zero +0x29C; zero +0x2A0; RET
```

| Stage | Match | Conf |
|---|---|---|
| ECX this | `8B F1` | **High** |
| Owned shell load `+0x294` | `8B BE 94 02 00 00` | **High** |
| Flag gate `+0xBB` | `38 9E BB 00 00 00` | **High** |
| RefCountedPtr dtor + delete | call pair + `83 C4 04` | **High** |
| Empty-string vcall `+0x2B4` | `68 9B 41 A1 00` + `FF 90 B4 02 00 00` | **High** |
| Always-zero pair | `89 9E 9C/A0 02 00 00` | **High** |
| Bare RET | `C3` | **High** |
| Parent chain membership | `007b5c81 MOV ECX,ESI; CALL 007aec70` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 84 B hex in raw WQ9L-G append. Entry: `53 56 8B F1 57 …`. Epilogue: `5E 5B C3` then `CC` pad.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete-dtor helper) |
| Code caller | `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` |
| DATA xrefs | many subclass vtbl slots sharing this method |
| Callees | `FUN_0096efd0`, `operator_delete` |

---

## 7. Gaps

1. Product English for `vtbl[+0x2B4]` (clear-text style; empty arg sealed only).  
2. Exact product type of heap shell at `+0x294` beyond RefCountedPtr entry dtor.  
3. Semantic names for `+0x29C` / `+0x2A0`.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, body size, owned-release gate, empty-string vcall, always-zero fields, and parent call site sealed. Residual product English → **accept-with-gaps**.
