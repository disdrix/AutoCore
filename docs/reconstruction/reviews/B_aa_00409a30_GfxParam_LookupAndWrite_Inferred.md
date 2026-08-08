# Review B (skeptical / adversarial): `aa_00409a30` GfxParam_LookupAndWrite_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9J-J) |
| **Counterpart** | `reviews/A_aa_00409a30_GfxParam_LookupAndWrite_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze + disassemble_function + call-site context (no disassemble_bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Standard thiscall (ECX=this) | **Falsified** — host arrives in **EAX** (`MOV ESI,EAX`); ECX not entry this |
| 2 | Hardcoded only `"gWorldFogCenter"` inside body | **Falsified** — name is **EDX** argument; string only at call sites |
| 3 | Float3-specific typed writer | **Falsified** — opaque data pointer; no float ops in body |
| 4 | Plain RET / no stack cleanup | **Falsified** — **`RET 4`** |
| 5 | Null service is fully safe | **Falsified** — write path reloads service without second null test |
| 6 | Same as `FUN_00442d50` (float4 helper) | **Related but distinct** — same lookup slot; write is vtbl+0x50 here vs `FUN_00969a50` there |
| 7 | Physics / CVOG impulse vtbl+0x50 family | **Falsified** — graphics param service path + fog string |
| 8 | Multi-module public API with many callers | **Narrow** — **1** function / **2** xrefs only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/EDX/RET4 ABI | **High** | wrong call-site port |
| Lookup+write vtbl slots | **High** | wrong service binding |
| Fog-center call-site usage | **High** | naming only if generalized wrong |
| Product host type | Medium | docs English |

---

## 3. Cross-check

```
FUN_00942840 call site:
  MOV EAX, [DAT_00d1f05c]
  MOV EDX, "gWorldFogCenter"   ; 0x00a2cf30
  PUSH float3*
  CALL 00409a30                ; RET 4

Inline twin in same function:
  service = DAT_00d1f05c[+4]+0xc
  h = service.vtbl+0x24(service, 0, "gWorldFogCenter")
  service.vtbl+0x50(service, h, dest, -1)
```

Do **not** merge with NDSpecialFX SetParamFloat3 keys, EffEffect FindParamIndex, or physics body vtbl+0x50 impulse.

---

## 4. Surviving contract for AutoCore

```csharp
// EAX=host, EDX=name, stack=data; ret 4
void LookupAndWrite(Host* host, const char* name, void* data)
{
    var svc = host->mid->service; // +4 then +0xc
    uint handle = 0;
    if (svc != null)
        handle = svc.vtbl.Lookup(svc, 0, name); // +0x24
    svc = host->mid->service;     // re-load; may be null → fault
    svc.vtbl.Write(svc, handle, data, 0xFFFFFFFFu); // +0x50
}
```

---

## 5. Open questions

1. Product name of host / parameter service.  
2. Write flag `-1` semantics.  
3. Runtime golden (optional).
