# Review B (skeptical / adversarial): `aa_0045cd30` StdVector_InsertN_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cd30` |
| **VA** | `0x0045cd30` |
| **Canonical name** | `StdVector_InsertN_Pod28` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W34-P) |
| **Counterpart** | `reviews/A_aa_0045cd30_StdVector_InsertN_Pod28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this `vector<string>::insert`? | **No** — no string IAT; SSE float POD copy; helpers are 7-dword memmoves |
| Is ABI ECX=this like BasicString insert? | **No** — bytes: **ECX=count**, **EDX=vec**, **RET 8** (sibling `004306b0` is ECX=vec RET C) |
| Is value by-value on stack (0x1c blob)? | **No** — stack holds **pointer**; prologue SSE-loads into local |
| Is grow path noreturn after delete? | **False** — decompiler warning; bytes publish triad and RET |
| Could stride be 0x20/other? | **No** — magic `0x92492493` and `lea`/`imul` style `*0x1c` throughout |
| Ghidra body end `0045d01b` | Off-by-one vs full `C2 08 00`; exclusive end **`0045d01c`**, size **748** |

---

## Residual risks

1. Product typename / domain (scaffold anmTrackMaster is **not** a sealed plate).  
2. Exact float vs dword interpretation of 7 lanes (POD either way for port).  
3. In-place mid arm register formals of helpers not dual-owned — port must match register ABI of `FUN_0045f*`.  
4. No runtime trace.

---

## Minimal sealed model

```
StdVector_InsertN_Pod28(count@ECX, vec@EDX, where, value*):
  local = *value          // 0x1c SSE
  if count==0: ret 8
  if size+count > 0x9249249: throw
  if cap < size+count: 1.5× realloc + trivial relocate/fill
  else: in-place hole or mid shift
  ret 8
```

---

## Verdict

Structural insert-n sealed; do not merge with BasicString or RcElem variants. **accept-with-gaps**.
