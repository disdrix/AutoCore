# Review B (skeptical / adversarial): `aa_0055c310` StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c310` |
| **VA** | `0x0055c310` |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-AF) |
| **Counterpart** | `reviews/A_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Multi-insert / insert-n public API? | **No** — hardcodes `push 1`; thin wrapper |
| EDI is vec (like `004612d0` / `00469e20`)? | **No** — **ECX** thiscall; `8B F9` copies this into EDI only as callee-save work reg |
| Returns outIt* in EAX (RC twin)? | **No** — void; only `*outIt` store; no `mov eax,outIt` |
| Index after insert (stale begin)? | **No** — index computed **before** call; rebind uses **new** begin |
| Empty-size branch forces index=0 wrongly when where!=begin? | Only when size==0; correct for empty vector insert-at-begin/end |
| Non-POD / string dtor path? | **No** — routes to POD InsertN (`0055be00`), not BasicString insert-n |
| Same as resize `0055c250`? | **No** — resize is exclusive other-agent; different CF (grow/shrink) |
| VOG_DEBUG / Named_CalleeOf scaffold name? | **Reject** — pure container helper |
| Hidden second callee? | **No** — `get_function_callees` → only `FUN_0055be00` |
| Multiple callers? | Listed sole direct caller `FUN_0055c710`; no other xrefs |

---

## Residual risks

1. Product demangle / T identity for Elem28.  
2. Push_back parent spare-cap path formal residual (`FUN_0055c710` / `FUN_0055b7a0`).  
3. No runtime / bit-exact proof.  
4. Capacity field unused in this body — correct for insert-one wrapper (InsertN owns grow).

---

## Minimal sealed model

```
StdVector_InsertOne_RebindIt_Elem28(vec@ECX, outIt, where, value*):
  index = empty ? 0 : (where-begin)/0x1c
  StdVector_InsertN_Elem28(vec, where, 1, value*)   // thiscall RET 0x0C
  *outIt = begin' + index*0x1c
  ret 0x0C   // void
```

---

## Optional extra dual (W37-AF)

Task allowed dualing **one** undualed callee not on the exclusive list. Sole callee `0x0055be00` is **already dual-sealed** (W34-R). **No extra dual filed.**

---

## Verdict

Do not unify ABI with EDI/RC insert-one twins or dword stride-4 thiscall without a port shim. **accept-with-gaps**.
