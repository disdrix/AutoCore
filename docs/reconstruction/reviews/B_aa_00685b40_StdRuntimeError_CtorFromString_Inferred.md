# Review B (skeptical / adversarial): `aa_00685b40` StdRuntimeError_CtorFromString_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00685b40` |
| **VA** | `0x00685b40` |
| **Canonical name** | `StdRuntimeError_CtorFromString_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-B) |
| **Counterpart** | `reviews/A_aa_00685b40_StdRuntimeError_CtorFromString_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| This is IdvFileError ctor itself? | **Falsified** — sole caller `006874b0` installs **final** vtbl `009ead64` after this; this only installs `009ea778` |
| cdecl / no this? | **Falsified** — `mov esi,ecx`; **`RET 4`** one stack arg |
| RET 8 (two stack args)? | **Falsified** — epilogue `C2 04 00` |
| String at +0x10 not +0x0c? | **Falsified** — `lea ecx,[esi+0xc]` before copy-ctor |
| Throws inside? | **Falsified** — no `_CxxThrowException`; pure ctor |
| Scaffold Named_CalleeOf is product name? | **Reject** |
| Bare `exception` only (no string)? | **Falsified** — always copy-ctors string member |
| Confirmed product `runtime_error` without caveat? | **Not Confirmed** — catchable + layout **Inferred**; keep `_Inferred` |

---

## Residual risks

1. COL/RTTI on `PTR_FUN_009ea778` not memory-walked — type plate could be a sibling intermediate (still runtime_error-layout).  
2. Exact exception subobject field layout between +4 and +0xb.  
3. Runtime / bit-exact.

---

## Minimal sealed model

```
StdRuntimeError_CtorFromString(self@ECX, msg@stack):
  exception::exception(self)
  *self = &vtbl_009ea778          // {scalar_dtor_00685c00, what_004018e0}
  basic_string::basic_string(self+0x0c, msg)
  return self                     // ret 4
```

Caller `IdvFileError_Ctor_MsgBracketErrno` then overwrites vtbl with `009ead64`.

---

## Verdict

Base ctor sealed; do not merge with IdvFileError final ctor. Product English residual → **accept-with-gaps**.
