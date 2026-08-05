# Review B (skeptical / adversarial): `aa_007647c0` Host_RegisterObjectAndAccumulateBounds

| Field | Value |
|---|---|
| **Stable ID** | `aa_007647c0` |
| **VA** | `0x007647c0` |
| **Canonical name** | `Host_RegisterObjectAndAccumulateBounds` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-L) |
| **Counterpart** | `reviews/A_aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this TacArc-only mesh init? | **No** — ~37 xrefs across host/mesh/bootstrap; reject Named_CalleeOf_CVOGTacArc_* |
| Is decompiler `__thiscall(int*,int*)` missing RET 4? | **Bytes win** — `C2 04 00` seals one stack arg |
| Is host+0xbc a BoundsVolume? | **No** — `FUN_004406e0` is ptr-vector push (EAX=vec, ESI=&value); Bounds dest is host+4 |
| Does it skip Bounds when gate set? | **No early-out in this unit** — gate is inside `0074c9c0` on local+0x2c |
| Is object+0x28 a matrix not bounds? | **No** — passed as stack1 to sealed Bounds_AccumulateTransformedLocal local param |
| Could FUN_004406e0 be something else? | **No** — decompile is capacity check + store dword + end++ / grow helper |
| Is this a dtor / unlink? | **No** — append-only vector push + accumulate; no free |

---

## Residual risks

1. Product type plates for host/object.  
2. Virtual slot English (offsets sealed, meaning open).  
3. Host virt+0x0c callee-clean vs stack reuse into Bounds — entry stack image sealed; mechanism residual.  
4. No runtime register trace at call sites.

---

## Minimal sealed model

```
Host_RegisterObjectAndAccumulateBounds(host@ECX, obj@stack0):
  push_back obj* into vector at host+0xbc
  obj.virt+0x20(host)
  if linkage_gate: obj.virt+0x80()
  scale = obj+0x64
  if flags_bc bit0: obj.virt+0x5c()
  xform = host.virt+0x0c(obj+0x28, scale)
  Bounds_AccumulateTransformedLocal(host+4, xform, obj+0x28, scale)
  ret 4
```

---

## Verdict

Structural host-register + bounds-accumulate worker sealed. Do not invent product class names. **accept-with-gaps**.
