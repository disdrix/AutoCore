# Review B (skeptical / adversarial): `aa_009847c0` AssPackManager_PrepReplaceExistingEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009847c0` |
| **VA** | `0x009847c0` |
| **Canonical name** | `AssPackManager_PrepReplaceExistingEntry_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-Y) |
| **Counterpart** | `reviews/A_aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this full remove/delete of pack entry? | **No** — no free of node; only clears `+0x1C` and pushes; parent continues open/compress/insert |
| Is this the add path itself? | **No** — returns before open-read; parent owns compress/insert |
| Is ECX the host (thiscall)? | **No** — EDI/EDX is host (CS fields); ECX is path buffer from caller LEA |
| Decompiler `__fastcall` 2-arg only? | **Incomplete** — bytes `RET 4` + stack load of name/cookie; **bytes win** |
| Is miss path success? | **No** — `OR EAX,-1` / return `0xFFFFFFFF` when `it == host+8` |
| Is `DAT_00d1eac0` a live resource? | Empty shared sentinel (family-wide); used as clear value |
| Could this be extract? | **No** — no file I/O; sole caller is replace branch of AddOrReplace |

---

## Residual risks

1. `nameOrCookie` product meaning (pack key vs path fragment).  
2. Push-container ownership / when drained.  
3. Nested HashMap node layout beyond used offsets.  
4. No runtime.

---

## Minimal sealed model

```
PrepReplace(pathBuf@ECX, host@EDX, name@stack) -> 0|-1:
  maybe EnterCS(host+0x38)
  normalize path; cache lookup name; map find
  if miss: LeaveCS; return -1
  entry+0x1C = empty_shared; push into *(entry+0x24)+0x30
  LeaveCS; return 0
```

---

## Verdict

Do not treat as full erase, add, or extract. Replace-prep only. **accept-with-gaps**.
