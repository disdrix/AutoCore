# Review B (skeptical / adversarial): `aa_00460d70` RcElem28_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00460d70` |
| **VA** | `0x00460d70` |
| **Canonical name** | `RcElem28_Release` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-O) |
| **Counterpart** | `reviews/A_aa_00460d70_RcElem28_Release.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this AddRef not Release? | **No** — `ADD [+4],-1`; AddRef twin is ++ and often `vtbl+4` |
| Is `FF 62 08` a CALL? | **No** — opcode is **JMP dword [EDX+8]**; decompiler "call" is wrong — **bytes win** |
| Does it free the element buffer? | **No** — only touches shared at `+0x10`; parents free storage |
| thiscall ECX=elem? | **No** — callers set **EAX**=cur; body reads `[EAX+0x10]` into ECX |
| Interlocked / atomic refcount? | **No** — plain `ADD DWORD`, not `LOCK` |
| Full object dtor (all fields)? | **No** — sole non-POD member released is shared*; POD dwords left alone |
| Scaffold long Named_CalleeOf name? | **Reject** — structural `RcElem28_Release` only |
| Body size wrong? | Exclusive end **`0x00460d83`**, **19 B** — bytes win |

---

## Residual risks

1. Product shared class / vtbl plate.  
2. Whether `vtbl+8` is scalar deleting dtor vs Release — not dual-owned.  
3. No runtime.

---

## Minimal sealed model

```
RcElem28_Release(elem@EAX):
  shared = *(elem+0x10)
  if !shared: ret
  if --shared.refcount != 0: ret
  jmp shared.vtbl[+8]   // this@ECX = shared
```

---

## Verdict

Tiny, fully byte-sealed Release leaf. Do not treat as full element dtor, buffer free, or AddRef. **accept-with-gaps**.
