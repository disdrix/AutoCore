# Review B (skeptical / adversarial): `aa_0076c130` Debug_OutputDebugStringFmt_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c130` |
| **VA** | `0x0076c130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0076c130_Debug_OutputDebugStringFmt_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` 59 B + 78 xrefs + call-site stack cleanup |
| **Agent** | W38-Y OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | thiscall / ECX format | Entry loads `[ESP+4]`; no ECX use | **Falsified thiscall** |
| 2 | Fixed single string arg only | Callers push 1–7+ args; `_vsnprintf` gets va_list | **Falsified fixed-arity** |
| 3 | Returns HRESULT / bool | No EAX set; void return sites | **Falsified non-void** |
| 4 | Writes file / vog log | Only `OutputDebugStringA` | **Falsified file/vog** |
| 5 | Product name `Client_RecvLoginFail_*` | 78 multi-domain xrefs | **Rejected scaffold** |
| 6 | Buffer is heap | `SUB ESP,0x800` only | **Falsified heap** |
| 7 | stdcall RET N | bare `C3`; callers `ADD ESP` | **Falsified stdcall** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ODS fmt wrapper role | **Confirmed** | Mis-port logging |
| cdecl varargs; void | **Confirmed** | Stack smash / wrong cleanup |
| 2048 buffer | **Confirmed** | Truncation mismatch |
| Null format no-op | **Confirmed** | Crash vs silent |
| Product English | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

| Caller | Pattern |
|---|---|
| `GfxDevice_Reset` / `FUN_0075e710` | Multi-arg D3D present dumps; `ADD ESP,0x20` across two prints |
| Voice `FUN_00671aa0` | Single format `"Couldnt get capture interface\n"`; `ADD ESP,4` |
| `Client_RecvLoginFail` | format + 1 arg; `ADD ESP,8` |
| Pack `FUN_0096b470` | format + 2 args; `ADD ESP,0xC` |

All consistent with cdecl varargs and plain `RET`.

---

## 4. Byte anchors

```text
0x0076c130: 8B 44 24 04              ; EAX = format
            81 EC 00 08 00 00        ; SUB ESP,0x800
            85 C0 74 26              ; TEST/JZ null
            … PUSH va; PUSH fmt; PUSH 0x800; PUSH buf
            FF 15 B4 64 9C 00        ; CALL [_vsnprintf]
            83 C4 10
            8D 04 24 50
            FF 15 A4 61 9C 00        ; CALL [OutputDebugStringA]
            81 C4 00 08 00 00 C3     ; ADD ESP,0x800; RET
```

---

## 5. What would reverse the seal?

- Proof of fixed arity / stdcall — contradicted by variable `ADD ESP` and bare `C3`.
- Proof of file I/O — no such callee.
- Proof of non-void return — no EAX construction.

None observed. **accept**.
