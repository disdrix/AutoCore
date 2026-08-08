# Review B (skeptical / adversarial): `aa_00416f00` Class_00a733ec_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416f00` |
| **VA** | `0x00416f00` |
| **Canonical name** | `Class_00a733ec_ScalarDeletingDtor_Inferred` |
| **Review date** | `2026-08-05` (WQ9J-E dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00416f00_Class_00a733ec_ScalarDeletingDtor_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + `disassemble_function` + xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Complete dtor only (no free path) | **Falsified** — `TEST flags,1` then `operator_delete` |
| 2 | Always frees host | **Falsified** — free only if bit0 set |
| 3 | `__fastcall` / no stack cleanup | **Falsified** — thiscall **`RET 4`** |
| 4 | `operator_delete` is noreturn | **Falsified** — bytes fall through to `MOV EAX,ESI; POP ESI; RET 4` |
| 5 | Array deleting dtor (`flags&2`) | **Falsified** — only bit0 tested |
| 6 | Separate complete dtor call (like `0097a8a0` pattern) | **Falsified** — teardown **inline** (vtbl + callback only) |
| 7 | Direct CALL graph callers | **Falsified** — DATA vtbl only |
| 8 | Class is literally `"UNI_BUTTONS"` | **Fails** — adjacent .rdata string after single-slot vtbl; no RTTI seal |
| 9 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
PUSH ESI
MOV ESI, ECX                    // self
MOV EAX, [ESI+0x10]             // free_cb
TEST EAX, EAX
MOV dword [ESI], 0x00a733ec     // reinstall vtbl (order: TEST then store before JZ)
JZ skip_cb
MOV ECX, [ESI+0x4]
PUSH ECX
CALL EAX                        // cdecl free
ADD ESP, 4
skip_cb:
TEST byte [ESP+8], 1
JZ skip_free
PUSH ESI
CALL operator_delete            // 0x00489822
ADD ESP, 4
skip_free:
MOV EAX, ESI
POP ESI
RET 4
```

Vtbl proof:

```text
*(uint32*)0x00a733ec == 0x00416f00   // slot 0 = this function
```

A ≡ B on live decompile + body hex + DATA xref.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar CF + flags&1 | **High** | Leaks or double-free |
| RET 4 thiscall | **High** | Stack imbalance |
| vtbl[0] binding | **High** | Wrong delete dispatch |
| cdecl free callback +0x10 | **High** | Wrong teardown |
| Product English | **Open** | Naming only |

---

## 4. Surviving contract

```text
Class_00a733ec_ScalarDeletingDtor_Inferred:
  ECX = this; stack flags; RET 4
  *this = PTR_FUN_00a733ec
  if (+0x10): cdecl(+0x10)(+0x04)
  if flags&1: operator_delete(this)
  return this
```
