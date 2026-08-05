# Review B (skeptical / adversarial): `aa_00985610` GfxIndexBufferFactory_PostRestoreDevice

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985610` |
| **VA** | `0x00985610` |
| **Canonical name** | `GfxIndexBufferFactory_PostRestoreDevice` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W38-AC) |
| **Counterpart** | `reviews/A_aa_00985610_GfxIndexBufferFactory_PostRestoreDevice.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Is this PreRestore / release-only? | **No** — calls create leaf `FUN_00743cd0`; product **PostResoreDevice** string; post-Reset parent site |
| Is this VB PostRestore (`FUN_00986570`)? | **No** — IB path string `gfxIndexBufferFactory.cpp`; caller uses IB factory slot `[EBP+0x750]` then VB at `+0x74c` |
| Is return always 0/−1 only? | **Bytes**: soft-fail returns ESI (create result); create leaf returns `0xffffffff` on fail path observed — still **passthrough** required |
| Is callback failure fatal? | **No** — logs and continues; only create failure aborts/returns |
| Is EH_Abort always taken? | **No** — only when `FUN_0076d1b0` returns **3**; else return hr |
| Decompiler `void`/wrong arg count? | Ignore Ghidra `undefined`/void; sealed int + EAX factory |
| Scaffold `Named_gfxIndexBufferFactory` as full type? | Partial — path proves **file/module**; method is PostRestoreDevice specifically |
| Is `is32` really `*(+0x10)==4`? | **Yes** in bytes (`CMP dword [EDI+0x10],4` → bool on stack); product stride 2 vs 4 for 16/32-bit indices |

---

## Residual risks

1. Secondary-tree / RestoreSurfaceCallback host English.  
2. Full `FUN_00743cd0` usage/pool bit mapping (owned elsewhere).  
3. No runtime / bit-exact.

---

## Minimal sealed model

```
GfxIndexBufferFactory_PostRestoreDevice(factory@EAX) -> 0 | hr:
  for each eligible IB slot in factory map:
    hr = recreate_device_ib(slot.ib)   // FUN_00743cd0
    if hr < 0:
      if errReport(PostResoreDevice) != 3: return hr
      else crash_abort()
    for each restore callback on slot: try invoke; log on fail
  return 0
```

---

## Verdict

Do not unify with PreRestore, VB PostRestore, or full factory create API. **accept-with-gaps**.
