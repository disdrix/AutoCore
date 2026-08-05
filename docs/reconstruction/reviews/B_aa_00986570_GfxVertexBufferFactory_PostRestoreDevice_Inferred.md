# Review B (skeptical / adversarial): `aa_00986570` GfxVertexBufferFactory_PostRestoreDevice_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986570` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-AE) |
| **Counterpart** | `reviews/A_aa_00986570_GfxVertexBufferFactory_PostRestoreDevice_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata + caller decompile (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | ECX-thiscall factory method | **Falsified** — entry uses **EAX** (`MOV EDX,[EAX+0x14]`); no `MOV REG,ECX` this capture |
| 2 | PreRestore / release-only | **Falsified** — calls `FUN_00746640` recreate; PreRestore twin is `FUN_009864e0` |
| 3 | Surface callback fail aborts PostRestore | **Falsified** — callback hr&lt;0 only logs (line 0x1a4); loop continues |
| 4 | Always walks all pools | **Falsified** — skips when `(flags@+0xE & 0x28) != 0` |
| 5 | Scaffold void/no-return is dual-ready | **Falsified** — returns HRESULT; success `XOR EAX,EAX` |
| 6 | Named_gfxVertexBufferFactory is precise plate | **Falsified** as sole name — need PostRestoreDevice role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX-this + plain RET | **High** | stack smash / wrong factory |
| HRESULT fail propagation | **High** | device Reset continues after VB fail |
| DEFAULT-pool flag mask 0x28 | **High** | managed pools recreated incorrectly |
| Product English exact demangle | Medium | naming only |
| FUN_00746640 arg field map | High (call site) | wrong recreate params |

---

## 3. Cross-check against raw + bytes

```
map = *(EAX+0x14)
for node in map:
  if (node+0xE & 0x28)==0:
    for slot in [node[5],node[6]) step 0x20:
      hr = RecreateVB(slot[0], count@+C, stride@+8, usage@+4, fvf=0)
      if hr<0: errReport; maybe return hr or EH_Abort
      fire surface callbacks (log-only fail)
return 0
```

Clean must **not** use ECX-thiscall, treat as PreRestore, or promote callback log fail to hard fail.

---

## 4. Surviving contract for AutoCore

```csharp
// After device Reset: recreate DEFAULT-pool VBs; log callback failures.
int PostRestoreVertexBuffers(VbFactory factory)
{
    foreach (var pool in factory.Pools)
    {
        if ((pool.Flags & 0x28) != 0) continue;
        foreach (var slot in pool.Slots)
        {
            int hr = RecreateVertexBuffer(slot.Vb);
            if (hr < 0) return hr; // or EH_Abort path in retail
            FireSurfaceRestoreCallbacks(slot); // log-only
        }
    }
    return 0;
}
```

Server-side ports are N/A (client graphics). Client ports that use ECX-this or skip the 0x28 gate will diverge from retail Reset recovery.

---

## 5. Verdict

Adversarial checks reinforce A: ABI and CF sealed; product demangle residual only → **accept-with-gaps**.
