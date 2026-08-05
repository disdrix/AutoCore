# Review A (reconstruction fidelity): `aa_00717f20` `_com_issue_errorex`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f20` |
| **VA** | `0x00717f20` |
| **Canonical name** | `_com_issue_errorex` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00717f20__com_issue_errorex.md` |
| **System** | `crt-com` / MSVC COM support (library) |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers |
| **Verdict** | **accept** (library CF + ISupportErrorInfo path sealed) |

---

## 1. Purpose

MSVC COM helper: raise HRESULT with optional rich error info. Given `(hr, IUnknown* punk, GUID const& iid)`:

1. Start with `IErrorInfo* = NULL`.
2. If `punk != NULL`, `QueryInterface` for **`IID_ISupportErrorInfo`** (global `DAT_00a14020`).
3. On success, call **`InterfaceSupportsErrorInfo(iid)`** (vtbl +0x0C), then **Release** (vtbl +0x08).
4. If supports (`iVar2 == 0` success HRESULT path in decomp) and `GetErrorInfo(0, &pei)` succeeds, keep pei; else force NULL.
5. Call same raise entry as `_com_issue_error`: `(*PTR_FUN_00af8b20)(hr, pei)`.

Ghidra library match: **Visual Studio 2003 Debug** `void __stdcall _com_issue_errorex(long, IUnknown*, _GUID const&)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00717f20__com_issue_errorex.md` |
| Annotated | `docs/reconstruction/raw/aa_00717f20__com_issue_errorex.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/_com_issue_errorex.cpp` |
| Function record | `docs/reconstruction/functions/aa_00717f20__com_issue_errorex.md` |
| Twin simple | `_com_issue_error` @ `0x00717f00` |
| IID blob | `read_memory` `0x00a14020` |

---

## 3. Seal: body bytes + convention

`read_memory` @ `0x00717f20` (through `ret 0x0c`):

```
00717f20  55                 push ebp
00717f21  8B EC              mov  ebp, esp
00717f23  83 EC 0C           sub  esp, 0x0C
00717f26  C7 45 F8 00 00 00 00  mov [ebp-8], 0   ; local_c IErrorInfo*
00717f2d  83 7D 0C 00        cmp  dword [ebp+0xC], 0  ; punk
...
; QI(punk, &DAT_00a14020, &local_8)
; vtbl[3] InterfaceSupportsErrorInfo(iid)  ; +0x0C
; vtbl[2] Release                           ; +0x08
; GetErrorInfo(0, &local_c) via IAT 009c66f0
; (*PTR_FUN_00af8b20)(hr, local_c)
00717fxx  C2 0C 00           ret  0x0C            ; __stdcall 3 args
```

Entry hex: `558bec83ec0cc745f800000000837d0c007502eb58…`  
Tail: `…ff15208baf008be55dc20c`

| Claim | Evidence | Conf |
|---|---|---|
| `__stdcall` three formals; `ret 0xC` | `C2 0C 00` + stack layout | **High** |
| Args: hr @`+8`, punk @`+C`, iid @`+10` | `[ebp+…]` uses | **High** |
| IID at `DAT_00a14020` = `{DF0B3D60-548F-101B-8E65-08002BBBD119}` | bytes `60 3d 0b df 8f 54 1b 10 8e 65 08 00 2b 2b d1 19` | **Confirmed** (`IID_ISupportErrorInfo`) |
| Shared raise with simple twin | same `[00af8b20]` call | **High** |
| Callees: QI path + `GetErrorInfo` + raise | Ghidra callees list | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| pei = NULL init | **Yes** |
| punk == NULL → skip QI, raise(hr, NULL) | **Yes** |
| QI fails (HRESULT &lt; 0) → skip support path | **Yes** |
| SupportsErrorInfo + GetErrorInfo gate | **Yes** |
| GetErrorInfo fail → pei forced NULL | **Yes** |
| Always ends in raise(hr, pei) | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Library name / signature | **Confirmed** | Ghidra single-match |
| IID_ISupportErrorInfo GUID | **Confirmed** | byte seal |
| Not game logic | **Confirmed** | CRT COM |
| Exact MSVC `iVar2 == 0` polarity = S_OK | **High** | standard COM |
| Raise callee full semantics | **Probable** | `FUN_007181c0` out of unit |

---

## 6. Callers

Same class of COM/DirectX/DB wrappers as twin (`FUN_00419e90` family, `0x007b*`/`0x007c*` clusters). Used when a COM interface pointer is available for richer errors.

---

## 7. Gaps

1. Dual of raise implementation `FUN_007181c0`.
2. Whether any caller passes non-null punk with intentional SupportsErrorInfo.
3. Runtime deferred.

**Verdict:** **accept** — library CF sealed including ISupportErrorInfo GUID and `ret 0xC`.
