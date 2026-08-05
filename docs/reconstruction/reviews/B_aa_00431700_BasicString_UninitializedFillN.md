# Review B (skeptical / adversarial): `aa_00431700` BasicString_UninitializedFillN

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-H) |
| **Counterpart** | `reviews/A_aa_00431700_BasicString_UninitializedFillN.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | stdcall / RET n | **Falsified** — bare `C3`; callers `ADD ESP,0x14` |
| 2 | Decompiler 3-arg is full call-site ABI | **Partial** — body uses 3; **callers push 5** (alloc + value echo) |
| 3 | Returns dest-end in EAX | **Falsified** — void; wrapper `FUN_00430390` computes `dest+count*0x1c` |
| 4 | Stride is 4 or sizeof(void*) | **Falsified** — `ADD ESI,0x1C` |
| 5 | Frees / owns vector buffer | **Falsified** — placement construct only |
| 6 | Scaffold `Named_CalleeOf_*VOG_DEBUG*` is product | **Rejected** |
| 7 | No EH residual (decompiler happy path only) | **Falsified** — dtor loop + `_CxxThrowException(0,0)` in bytes |
| 8 | Product demangle sealed | **Careful** — structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + 0x1c fill | **High** | Wrong string layout / stack |
| IAT copy-ctor / dtor | **High** | Wrong string ops |
| Caller set (2) | **High** | Missed sites only if new xrefs |
| 5-vs-3 formal story | **High** | Port may drop unused args OK |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// StringVec_PushBack @ 0x00430249:
//   push value; push this; push 1; push end; push value  (or equivalent order)
//   call FUN_00431700; add esp, 0x14; end += 0x1c
// StdUninitFillN_BasicString @ 0x004303a7:
//   five pushes (dest,count,value,alloc,value); call; add esp,0x14
//   return dest + count*0x1c
// Body epilog: ... 5B 8B E5 5D C3
// EH: FF 15 F4 62 9C 00 (dtor); E8 → 006a3d60 _CxxThrowException
```

Live decompile ≡ happy-path CF; **bytes win** on EH residual and bare RET.

---

## 4. Surviving contract for AutoCore

```
// Port as cdecl uninit fill-n (stride 0x1c):
void BasicString_UninitializedFillN(BasicString* dest, int n, const BasicString* v) {
  for (; n > 0; --n, ++dest) {
    if (dest) copy_ctor(dest, v);
  }
}
// Call sites may pass two extra unused args; preserve stack cleanup (cdecl).
// Pair with StdUninitFillN_BasicString (wrapper return) and StringVec_PushBack.
// Do not free the vector buffer here.
```

---

## 5. Verdict

Adversarial pass confirms A on cdecl, stride, IAT ops, EH residual, and caller linkage. Product demangle residual → **accept-with-gaps**.
