# Review B (skeptical / adversarial): `aa_007999c0` NDXml_OpenTaggedDocument

| Field | Value |
|---|---|
| **Stable ID** | `aa_007999c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007999c0_NDXml_OpenTaggedDocument.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Signature is 3 stack args (`path, unused, tag`) as decompiler shows | Epilogue **`RET 8`**; call sites push **exactly two** dwords then `lea ecx` | **Falsified** — **`__thiscall(this, path, tag)`** only |
| 2 | First call arg is “this” when Ghidra prints `Open(local_120,"NDSpecialFX")` | Call bytes: push tag, push path, **`lea ecx, [esp+…]`** separate stack object | **Falsified** — `local_120` region is **path buffer**, not always `this` |
| 3 | Function is stdcall / no ECX this | Entry `MOV ESI, ECX`; field ops via ESI | **Falsified** — **thiscall** |
| 4 | `param_3` is a real ignored API parameter | No load of a third stack arg in sealed CF; only `[esp+…]` path + tag used after frame | **Falsified** — **SEH/decompiler phantom** |
| 5 | Tag BSTR is the file path | Path already copied to `this+0x10` and passed to `LoadDocumentFromPath`; BSTR from **tag arg** only | **Falsified** — plate wording “load BSTR path” is **misleading** |
| 6 | Failure always returns COM HRESULT | Load false → **forced 1**; count `< 1` → **forced 1** | **Partially** — success wants **0**; failures **1** or passthrough hr before empty check |
| 7 | Always requires non-null tag | `if (param_4==0) bstr=0` then still calls doc method with NULL BSTR | **Falsified exclusive require** — **NULL tag allowed** |
| 8 | OOM on tag convert is soft-fail | `FUN_004048e0(0x8007000E)` marked noreturn | **Falsified soft-fail** — **throws** |
| 9 | Clean scaffold “system: unknown” only | Callers: UI window init + SpecialFX scripts | **Partially** — system is **NDXml shared open**, multi-consumer |
| 10 | `vtbl+0xdc` is definitely `load` / `loadXML` | No IDL in image; BSTR is **tag** after file already loaded | **Not sealed as named method** — offset only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + path + tag + RET 8 | **High** | Wrong wrappers smash stack / wrong ECX |
| Path owned at `+0x10` (new[]/delete[]) | **High** | Leaks / double-free in ports |
| Doc at `+0x04`, node at `+0x08`, count at `+0x0c` | **High** | Callers reading count (`local_12c` / `local_14`) break |
| Load fail / empty → return 1 | **High** | Invert success checks (`iVar==0`) |
| NULL tag → NULL BSTR still dispatch | **High** | Over-strict port rejects valid calls |
| Tag convert OOM throws | **High** | Missing exception path |
| COM slot English names | **Low–Medium** | Documentation only; behavior uses offsets |
| Singleton `FUN_007b6a20` identity | **Medium** (body owned elsewhere) | Wrong global if reimplemented |

---

## 3. Cross-check against raw + bytes

```
raw/live decompile:
  delete[] path@+10; copy pszPath; LoadDocumentFromPath(singleton, doc@+4, path);
  optional BSTR(tag); doc[+0xdc]→node@+8; if S_OK node[+0x20]→count@+c;
  if count<1 → 1; SysFreeString; return

bytes:
  entry: 64A1… 6AFF 68… SEH; 8BF1; 8B4610 …
  tail:  RET 8 (C20800) both paths; fail MOV EAX,1

callers (read_memory pre-call):
  UI:    push "XML"; push path; lea ecx, this; call
  FX:    push "NDSpecialFX"; push path; lea ecx, this; call
```

**No conflict** between raw, live decompile, and call-site/epilogue bytes on sealed CF.

---

## 4. Surviving contract for AutoCore

```csharp
// Client NDXml open — behavior port (not bit-identical COM)
// Return 0 = success, non-zero = failure (callers test == 0).
int NdXmlOpenTaggedDocument(NdXml self, string path, string? tag)
{
    // replace owned path copy at +0x10
    self.Path = path ?? throw /* retail would AV on strlen */;

    if (!NdXmlLoadDocumentFromPath(GetNdXmlLoaderSingleton(), self.Document, self.Path))
        return 1;

    // tag may be null → null BSTR; non-null fails hard on OOM (throw E_OUTOFMEMORY)
    self.BoundNode = DocumentInvokeTagBind(self.Document, tag); // vtbl+0xDC → +0x08
    if (/* HRESULT S_OK */)
        self.ChildCount = BoundNodeGetCount(self.BoundNode);    // vtbl+0x20 → +0x0C

    if (self.ChildCount < 1)
        return 1;
    return /* HRESULT or 0 */;
}
```

Port notes:

- Server rarely needs MSXML parity; if replaying client UI/FX load, preserve **`== 0` success** and **empty-count failure**.
- Do **not** invent a third stack parameter from Ghidra’s `param_3`.
- Do **not** treat tag as filesystem path.

---

## 5. Open questions

1. Exact MSXML / custom vtable method at doc `+0xdc` (getElementsByTagName vs documentElement vs custom).
2. Exact method at bound iface `+0x20` (get_length vs other).
3. Whether any caller depends on returning raw HRESULT ≠ {0,1}.
4. Full size of NDXml and any fields beyond `+0x00..+0x10`.
5. Runtime confirmation on live `autoassault.exe`.

**Verdict:** **accept-with-gaps**
