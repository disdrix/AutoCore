# Review B (skeptical / adversarial): `aa_00752370` EffEffect_FindParamIndexByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00752370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-Q) |
| **Counterpart** | `reviews/A_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + function metadata (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | cdecl / returns index in EAX | **Falsified** — ECX this; out-param store; **`ret 8`** |
| 2 | Binary search / hash map | **Falsified** — linear `cmp [table+i*8]` loop |
| 3 | String compare against table names | **Falsified** — iface handle then handle-equality |
| 4 | Stride 4 / pointer table | **Falsified** — `ecx*8` addressing |
| 5 | Miss leaves out-param untouched | **Falsified** — always writes (`-1` or index) |
| 6 | Scaffold `Named_CalleeOf_gfxDeviceVB` is dual-ready | **Falsified** — wrong ownership plate; reject alias |
| 7 | Same as `FUN_0096fff0` set-param | **Falsified** — index lookup only; set is peer |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 8` / thiscall | **High** | stack smash on port |
| −1 miss / always write | **High** | callers treat index ≥0 as hit before set-param |
| Stride-8 handle key | **High** | wrong table layout → silent miss |
| Product English | Medium | naming only |
| Handle == 0 means missing | **High** | zero handle short-circuits to −1 |

---

## 3. Cross-check against raw + bytes

```
inner = effect+8
idx = -1
if inner && iface:
  handle = iface.vtbl+0x24(iface, 0, name)
  if handle:
    scan table[i].handle (stride 8) for match
*out = idx  // or -1 on exhausted scan
ret 8
```

Clean must **not** return the index in EAX, use string strcmp on table, or change miss to leave `*out` undefined.

---

## 4. Surviving contract for AutoCore

```csharp
// Find effect param table index by name/token; -1 if absent.
int FindParamIndex(Effect effect, string name)
{
    var inner = effect.Inner;
    if (inner?.ParamIface is null) return -1;
    var handle = inner.ParamIface.GetByName(0, name);
    if (handle == 0) return -1;
    for (int i = 0; i < inner.ParamCount; i++)
        if (inner.ParamTable[i].Handle == handle) return i;
    return -1;
}
```

Ports that strcmp parameter names against the dense table, or treat EAX as the index, diverge from retail material bind paths.
