# Review B (skeptical / adversarial): `aa_007181c0` `_com_raise_error`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007181c0` |
| **VA** | `0x007181c0` |
| **Canonical name** | `_com_raise_error` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007181c0__com_raise_error.md` |
| **System** | `crt-com` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function can return normally to callers | Body ends in `_CxxThrowException`; decompiler “does not return” | **Attack fails** — pure throw |
| 2 | `fAddRef = true` (owns AddRef on info) | Imm `push 0` before ctor | **Falsified** — **false** |
| 3 | Custom AutoAssault exception type | Uses `_com_error` ctor @ `007181f0` + CRT ThrowInfo | **Falsified** as game type |
| 4 | Same as `Cxx_ThrowException_Param` @ `004048e0` | Different VA/ThrowInfo; this builds `_com_error` first | **Falsified** as identical |
| 5 | Same as `_com_issue_error` | Issue_error only invokes PTR; raise body is here | **Agree distinct** |
| 6 | `__cdecl` / no stack cleanup | `ret 8` | **Falsified** cdecl |
| 7 | Scaffold invents CF | Live ≡ raw ≡ clean (2 steps) | **Attack fails** |
| 8 | Must reimplement for AutoCore server | Client COM / MSVC support only | **Reject port priority** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor then throw CF | **Confirmed** | Mis-model exception flow |
| fAddRef false | **Confirmed** | Wrong IErrorInfo lifetime at raise |
| Raise PTR identity | **Confirmed** | Miss issue_error linkage |
| Exact catchable type_info name | **Medium** | Cosmetic RTTI only |
| Domain = CRT not game | **Confirmed** | Waste port effort |

---

## 3. Cross-check against raw / live / bytes

```
push 0                  ; fAddRef
push [ebp+0xC]          ; IErrorInfo*
push [ebp+8]            ; hr
lea  ecx, [ebp-0x10]
call 0x007181f0         ; _com_error ctor
push 0x00acc2c0         ; ThrowInfo
lea  edx, [ebp-0x10]
push edx
call 0x006a3d60         ; _CxxThrowException
ret  8
```

- ThrowInfo @ `00acc2c0`: `pmfnUnwind = 0x007182e0` matches dualed `_com_error` dtor.
- `PTR_FUN_00af8b20` dword = `0x007181c0` — issue wrappers are not the raise body.

### Double-raise trap

Call sites that catch `_com_error` and re-issue must not assume this unit AddRefs — **fAddRef false**. Ownership is caller's / GetErrorInfo's responsibility.

### ABI trap

Not thiscall; not a single-arg HRESULT throw (`004048e0`). Two stack args, stdcall cleanup `ret 8`.

---

## 4. Surviving contract for AutoCore

```
_com_raise_error(hr, perrinfo):
  never returns
  construct _com_error(hr, perrinfo, fAddRef=false) on stack
  _CxxThrowException(&obj, &DAT_00acc2c0)

AutoCore must NOT:
  - treat this as skill/mission/game exception policy
  - assume AddRef on perrinfo in this leaf
  - port as server error path — map COM failures to return codes instead
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Ctor + throw | **Agree Confirmed** |
| fAddRef false | **Agree Confirmed** |
| `_com_raise_error` identity High | **Agree** (PTR + wrappers; plate name residual only) |
| accept | **Agree** |

---

## 6. Open questions

1. CatchableType string English (optional RTTI polish).
2. None on control flow.

**Verdict:** **accept** — agree with A; block fAddRef-true and game-exception misreads.
