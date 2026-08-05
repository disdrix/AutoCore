# Review B (skeptical / adversarial): `aa_006874b0` IdvFileError_Ctor_MsgBracketErrno

| Field | Value |
|---|---|
| **Stable ID** | `aa_006874b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-B) |
| **Counterpart** | `reviews/A_aa_006874b0_IdvFileError_Ctor_MsgBracketErrno.md` |
| **Scratch** | `tmp/a_006874b0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `std::runtime_error` ctor itself | **Falsified** — most-derived catchable is **IdvFileError**; final vtbl is `009ead64` not pure runtime_error |
| 2 | This throws inside the function | **Falsified** — no `_CxxThrowException` in body; callers throw after |
| 3 | cdecl / no this | **Falsified** — `mov edi,ecx`; `RET 8` thiscall |
| 4 | Always includes strerror | **Falsified** — flag 0 → empty string in brackets (`FUN_00687e40` passes 0) |
| 5 | Never includes strerror | **Falsified** — non-zero flag calls `_errno`/`strerror` |
| 6 | Message is just `msg` | **Falsified** — always wraps with `" ["` … `"]"` |
| 7 | Scaffold Named_CalleeOf plate is product name | **Falsified** — RTTI IdvFileError wins |
| 8 | Object size matches bare exception (0x0c) | **Falsified** — CatchableType size **0x28** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| IdvFileError type identity | **High** | Wrong catch type / port hierarchy |
| Message bracket formula | **High** | Mismatched throw strings |
| RET 8 / two stack args | **High** | Stack corruption on throw path |
| include_errno flag polarity | **High** | Wrong strerror inclusion |
| Base `FUN_00685b40` internals | **Med** | Nested unit not owned here |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + RTTI

```
// FUN_006874b0 epilogue:
mov  dword ptr [edi], 0x009ead64   ; IdvFileError vtbl
mov  eax, edi
pop  edi/esi/ebx
mov  fs:[0], ecx
add  esp, 0xA0
ret  8
```

Throw path sample (`FUN_00687e40`):
```
string("malformed lod info")
FUN_006874b0(msg, 0)
_CxxThrowException(obj, DAT_00ac9e00)
```

CatchableTypeArray @ `0x00ac9df0`: IdvFileError → runtime_error → exception.

---

## 4. Surviving contract for AutoCore

```
// Port as IdvFileError ctor only (not throw):
IdvFileError* IdvFileError_Ctor_MsgBracketErrno(
    IdvFileError* self, const std::string* msg, bool include_errno) {
  std::string part = include_errno ? strerror(*errno()) : "";
  std::string built = *msg + " [" + part + "]";
  BaseExceptionString_Ctor(self, &built);  // FUN_00685b40
  self->vtbl = &IdvFileError_vtbl;         // PTR_FUN_009ead64
  return self;
}
// __thiscall ret 8; callers _CxxThrowException(..., ThrowInfo_IdvFileError)
```

---

## 5. Verdict

**accept** — adversarial probes fail to unseat RTTI, CF, ABI, or message formula.
