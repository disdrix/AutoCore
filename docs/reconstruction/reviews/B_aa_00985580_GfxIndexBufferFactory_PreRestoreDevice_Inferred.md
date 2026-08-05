# Review B (skeptical / adversarial): `aa_00985580` GfxIndexBufferFactory_PreRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985580` |
| **VA** | `0x00985580` |
| **Canonical name** | `GfxIndexBufferFactory_PreRestoreDevice_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W38-AC) |
| **Counterpart** | `reviews/A_aa_00985580_GfxIndexBufferFactory_PreRestoreDevice_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this PostRestore / recreate? | **No** — only calls release leaf `FUN_00743c50`; no CreateIndexBuffer; lives in Reset **shutdown** cascade |
| Is this VB factory pre-release (`FUN_009864e0`)? | **No** — different VA; IB leaf `00743c50` vs VB leaf; caller passes `[EBP+0x750]` (IB factory slot) not `+0x74c` |
| Is this ECX-thiscall? | **No** — entry `MOV ECX,[EAX+0x14]`; caller loads **EAX** only |
| Is decompiler void wrong (returns HRESULT)? | **No** — parent does not TEST EAX after call; epilogue preserves no intentional return value for consumer |
| Is `FUN_00743c50` argless leaf with no object? | **No** — bytes `MOV ESI,[EBP]; CALL`; callee uses `unaff_ESI` as device-IB* |
| Is scaffold `Named_CalleeOf_Named_gfxDevice` product name? | **Reject** — ownership is IB factory map, not device methods |
| Could flag `0x28` mean something else (e.g. free list)? | Possible nuance — sealed only as **skip release when set**; bit semantics residual |
| Is method name proven PostRestore? | **No** — PreRestore is **Inferred** from cascade position + PostRestore twin |

---

## Residual risks

1. Product English plate for method.  
2. Flag-bit product meaning.  
3. Nested `FUN_00743c50` ownership (not OWN) — port must match retail unlock/Release/stats.  
4. No runtime / bit-exact.

---

## Minimal sealed model

```
GfxIndexBufferFactory_PreRestoreDevice(factory@EAX):
  for each tree node at factory+0x14 (is_nil@+0x21):
    if (node.flags@+0x0C & 0x28) == 0:
      for slot in [node+0x14, node+0x18) step 0x20:
        release_device_ib(*slot)  // FUN_00743c50 / ESI
```

---

## Verdict

Do not unify with PostRestore, VB pre-release, or device-level Reset. **accept-with-gaps**.
