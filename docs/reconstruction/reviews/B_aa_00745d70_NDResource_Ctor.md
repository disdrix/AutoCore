# Review B (skeptical / adversarial): `aa_00745d70` NDResource_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00745d70_NDResource_Ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `operator new` | Body never allocates; returns stack `this` | **Falsified** |
| 2 | Final vtbl is always `00a9e850` | Body stores `00aa1d40`; patch is **caller-side** | **Falsified** as body property |
| 3 | `__stdcall` only / no register args | EDX written to `this+0xc`; sites load EDX | **Falsified** pure stdcall |
| 4 | ECX is this (normal thiscall) | this loaded from **stack** into ESI; ECX unused for fields | **Falsified** standard thiscall |
| 5 | optionalSrc always required | `cmp ebp, ebx` / `jz` skip | **Falsified** |
| 6 | Same as dtor `FUN_00745ff0` | Dtor deletes CS / releases `+0x14`; opposite lifecycle | **Falsified** merge |
| 7 | Object size unknown | Cache path `operator_new(0x3c)` + CS to `+0x38` fits | **Survives** as 0x3c |
| 8 | Name is heap string deep-copy | Body stores **one dword** `*nameKey` | **Falsified** as deep copy |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches raw 2026-07-23 body and `read_memory` hex through `RET 0xC`. Callers list matches `get_function_callers` (7). LookupOrCreate site seals push order + post-vtbl patch.

---

## 3. Surviving contract

```
// EDX = typeToken
// (this, nameKey*, optionalSrc*)  RET 0xC
// *this = PTR_FUN_00aa1d40
// this+4 = *nameKey; +0xc = type; +0x18 = -1
// InitializeCriticalSection(this+0x20); *(u8*)(this+0x38)=1
// if optionalSrc: this+0x14 = optionalSrc->vtbl[+4]()
// return this
```

**Gaps kept:** product class spelling; optionalSrc virtual meaning; runtime/bit-exact.

**Verdict:** **accept-with-gaps**.
